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

#include <ros2sb.hpp>

template <typename MT>
class C2M : public ROS2SB{
private:
    QueueHandle_t SemPubMsg;
    static void cbPub(void*);
    static void watchUART(void*);
public:
    C2M(HardwareSerial*);
    C2M(String, String, String, uint16_t);
    void setPublishMsg(MT);
    void beginBridge(String);
    void stopBridge();
};

template <typename MT>
C2M<MT>::C2M(HardwareSerial *mUSB):ROS2SB(mUSB){

}

template <typename MT>
C2M<MT>::C2M(String ssid, String pw, String agip, uint16_t agport):ROS2SB(ssid, pw, agip, agport){

}

template <typename MT>
void
C2M<MT>::cbPub(void *arg){

}

template <typename MT>
void
C2M<MT>::watchUART(void *arg){

}

template <typename MT>
void
C2M<MT>::setPublishMsg(MT msg){

}

template <typename MT>
void
C2M<MT>::beginBridge(String tName){
    this->tName = tName;
    
}

template <typename MT>
void
C2M<MT>::stopBridge(){
    
}

#endif