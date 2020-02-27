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

ROS2SB::ROS2SB(HardwareSerial USB):Node("StackBridge"){
    ROS2SB::thisPtr = this;
    this->USB = &USB;
    this->USB->begin(115200);
    while(!this->USB);
    ros2::init(this->USB);
}

ROS2SB::ROS2SB(String ssid, String pw, String agip, uint16_t agport):Node("StackBridge"){
    ROS2SB::thisPtr = this;
    this->udp = new WiFiUDP();
    WiFi.begin(ssid.c_str(), pw.c_str());
    while (WiFi.status != WL_CONNECTED);
    ros2::init(this->udp, agip.c_str(), agport);
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

template <typename MT> void ROS2SB::sendUART(MT msg){

}

template <typename MT> void ROS2SB::begin(String subTpName, String pubTpName){
    this->createSubscriber<MT>(subTpName.c_str(), (ros2::CallbackFunc)this->cbSub, nullptr);
    this->_publisher = this->createPublisher<MT>(pubTpName.c_str());
    xTaskCreatePinnedToCore(this->cbPub, "Pub", 1024*8, NULL, 1, this->Pub, CONFIG_ARDUINO_RUN_CORE1);
    xTaskCreatePinnedToCore(this->watchUART, "Uartrx", 1024*8, NULL, 1, this->Uartrx, CONFIG_ARDUINO_RUN_CORE1);
}

template <typename MT> void ROS2SB::stop(String subTpName, String pubTpName){
    this->deleteSubscriber(subTpName.c_str());
    this->deletePublisher(pubTpName.c_str());
    vTaskDelete(this->Pub);
    vTaskDelete(this->Uartrx);
}