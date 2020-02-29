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

#ifndef _ROS2_SB_
#define _ROS2_SB_

#include <WiFi.h>
#include <WiFiUdp.h>
#include <ros2arduino.h>

class ROS2SB : public ros2::Node{
private:
    WiFiUDP *udp;
    HardwareSerial *UART, *USB;
public:
    static ROS2SB* thisPtr;
    ROS2SB(HardwareSerial*, HardwareSerial*);
    ROS2SB(HardwareSerial*, String, String, String, uint16_t);
};

ROS2SB::ROS2SB(HardwareSerial *USB, HardwareSerial *UART):Node("StackBridge"){
    ROS2SB::thisPtr = this;
    this->USB = USB;
    this->USB->begin(115200);
    if(UART != nullptr){
        this->UART = UART;
        this->UART->begin(115200);
    }
    while(!this->USB);
    ros2::init(this->USB);
}

ROS2SB::ROS2SB(HardwareSerial *UART, String ssid, String pw, String agip, uint16_t agport):Node("StackBridge"){
    ROS2SB::thisPtr = this;
    if(UART != nullptr){
        this->UART = UART;
        this->UART->begin(115200);
    }
    this->udp = new WiFiUDP();
    WiFi.begin(ssid.c_str(), pw.c_str());
    while (WiFi.status() != WL_CONNECTED);
    ros2::init(this->udp, agip.c_str(), agport);
}

#endif