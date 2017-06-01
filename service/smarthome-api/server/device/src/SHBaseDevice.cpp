/* ****************************************************************
 *
 * Copyright 2017 Samsung Electronics All Rights Reserved.
 *
 *
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************/
#include <SHBaseDevice.h>
#include <SHPlatform_Impl.h>
#include <SHBaseDevice_Impl.h>

namespace OIC
{
    namespace Service
    {
        namespace SH
        {
            SHBaseDevice::SHBaseDevice()
            {
                SH_Impl::start();
                m_deviceImpl = new SHBaseDevice_Impl;
            }

            SHBaseDevice::~SHBaseDevice()
            {
                SH_Impl::stop();
                delete m_deviceImpl;
            }

            std::string SHBaseDevice::getType() const
            {
                return m_deviceImpl->getType();
            }

            void SHBaseDevice::setType(const std::string& type)
            {
                m_deviceImpl->setType(type);
            }

            std::string SHBaseDevice::getName() const
            {
                return m_deviceImpl->getName();
            }

            void SHBaseDevice::setName(const std::string& name)
            {
                m_deviceImpl->setName(name);
            }
        }
    }
}
