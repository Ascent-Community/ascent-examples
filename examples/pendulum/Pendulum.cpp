// Copyright (c) 2015 - 2016 Anyar, Inc.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//      http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Pendulum.h"

Pendulum::Pendulum(size_t sim) : asc::Module(sim)
{
   addIntegrator(theta, theta_d);
   addIntegrator(theta_d, theta_dd);

#define ascNS Pendulum
   ascVar(theta)
}

void Pendulum::update()
{
   theta_dd = -g / length * sin(theta);
}