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

#include <ros2sb.hpp>

template <typename MT, typename ST>
class M2C : public ROS2SB{
private:
    QueueHandle_t SemSubMsg;
    static void cbSub(MT, void *);
public:
    M2C();
    void getSubscribeMsg(MT);
    void sendUART();
    void begin(String);
    void stop();
};

#endif