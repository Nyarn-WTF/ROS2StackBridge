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

#include <ros2sb.hpp>

ROS2SB::ROS2SB(HardwareSerial UART){
    ROS2SB::thisPtr = this;
}

ROS2SB::ROS2SB(String ssid, String pw, int agip, int agport){
    ROS2SB::thisPtr = this;
}

template <typename MT> static void cbSub(MT msg, void *arg){

}
static void cbPub(void *){

}

static void watchUART(void *){
    
}

template <typename MT> void ROS2SB::setPublishMsg(MT msg){

}

template <typename MT> void ROS2SB::getSubscribeMsg(MT msg){

}

template <typename MT> void sendUART(MT msg){

}

void begin(){

}

void stop(){

}