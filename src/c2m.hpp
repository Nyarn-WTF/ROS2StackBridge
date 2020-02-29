/*
    Copyright © 2020 Nyarn-WTF <s16054@tokyo.kosen-ac.jp>
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
        http://www.apache.org/licenses/LICENSE-2.0
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _C2M_
#define _C2M_

#include <Arduino.h>
#include <ros2sb.hpp>

template <typename MT>
class C2M : public ROS2SB{
private:
    QueueHandle_t QuePubMsg;
    TaskHandle_t pub;
    ros2::Publisher<MT> *_publisher;
    static void cbPub(void*);
    static void watchClient(void*);
public:
    C2M(HardwareSerial*, HardwareSerial*);
    C2M(HardwareSerial*, String, String, String, uint16_t);
    ~C2M();
    void setPublishMsg(MT*);
    void beginBridge(String);
    void stopBridge();
};

template <typename MT>
C2M<MT>::C2M(HardwareSerial *mUART, HardwareSerial *mUSB):ROS2SB(mUART, mUSB){
    this->SemPubMsg = xQueueCreate(1, sizeof(MT));
}

template <typename MT>
C2M<MT>::C2M(HardwareSerial *mUART, String ssid, String pw, String agip, uint16_t agport):ROS2SB(mUART, ssid, pw, agip, agport){
    this->SemPubMsg = xQueueCreate(1, sizeof(MT));
}

template <typename MT>
C2M<MT>::~C2M(){
    this->stopBridge();
}

template <typename MT>
void
C2M<MT>::cbPub(void *arg){
    MT *msg;
    C2M<MT> *_this = C2M::thisPtr;
    delay(DELAYTIME);
    while(1){
        xQueueReceive(_this->QuePubMsg, msg, 0);
        if(msg == NULL){
            delay(DELAYTIME);
            continue;
        }else{
            _this->_publisher->publish(msg);
            delay(DELAYTIME);
        }
    }
}

template <typename MT>
void
C2M<MT>::watchClient(void *conv){
    C2M<MT> *_this = C2M::thisPtr;
    MT *msg;
    char buff[1024];
    while(1){
        if(_this->UART != nullptr){
            //このへんでUARTからのデータを変換
            uint len = _this->UART->readBytesUntil('\0', buff, 1024);
            (void*)(conv)(*buff, msg, len);
            setPublishMsg(msg);
        } 
    }
}

template <typename MT>
void
C2M<MT>::setPublishMsg(MT *msg){
    xQueueOverwrite(this->QuePubMsg, msg);
}

template <typename MT>
void
C2M<MT>::beginBridge(String topicName){
    this->topicName = topicName;
    this->_publisher = this->createPublisher(topicName.c_str());
    xTaskCreatePinnedToCore(this->cbPub, "cbPub", 1024*8, NULL, 1, this->pub, CONFIG_ARDUINO_RUN_CORE1);
}

template <typename MT>
void
C2M<MT>::stopBridge(){
    deletePublisher(this->topicName.c_str());
    vTaskDelete(this->pub);
}

#endif