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
    QueueHandle_t SemPubMsg, SemSubMsg;
    WiFiUDP *udp;
    HardwareSerial *UART, *USB;
    TaskHandle_t Pub, Uartrx;
    void *_publisher;
    template <typename MT> static void cbSub(MT, void *);
    static void cbPub(void *);
    static void watchUART(void *);
public:
    static ROS2SB* thisPtr;
    ROS2SB(HardwareSerial);
    ROS2SB(String, String, String, uint16_t);
    template <typename MT> void setPublishMsg(MT);
    template <typename MT> void getSubscribeMsg(MT);
    template <typename MT> void sendUART(MT);
    template <typename MT> void begin(String, String);
    template <typename MT> void stop(String, String);
}
#endif 