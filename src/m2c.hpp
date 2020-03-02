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

#ifndef _M2C_
#define _M2C_
#include <Arduino.h>
#include <ros2sb.hpp>

template <typename MT>
class M2C : public ROS2SB{
private:
    QueueHandle_t QueSubMsg;
    static void cbSub(MT, void *);
public:
    M2C(HardwareSerial*, HardwareSerial*);
    M2C(HardwareSerial*, String, String, String, uint16_t);
    MT getSubscribeMsg();
    void sendClient();
    void beginBridge(String);
    void stopBridge();
};

template <typename MT>
M2C<MT>::M2C(HardwareSerial*mUART, HardwareSerial* mUSB):ROS2SB(mUART, mUSB){

}

template <typename MT>
M2C<MT>::M2C(HardwareSerial *mUART, String ssid, String pw, String agip, uint16_t agport):ROS2SB(mUART, ssid, pw, agip, agport){
    
}

template <typename MT>
MT
M2C<MT>::getSubscribeMsg(){

}

template <typename MT>
void 
M2C<MT>::sendClient(){

}

template <typename MT>
void 
M2C<MT>::beginBridge(String topicName){

}

template <typename MT>
void 
M2C<MT>::stopBridge(){

}

#endif