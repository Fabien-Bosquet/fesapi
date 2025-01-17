/*-----------------------------------------------------------------------
Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the NOTICE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"; you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
-----------------------------------------------------------------------*/
#include "WellboreFeature.h"

#include <stdexcept>

#include "../witsml2_0/Wellbore.h"

using namespace std;
using namespace RESQML2_NS;

const char* WellboreFeature::XML_TAG = "WellboreFeature";

WITSML2_0_NS::Wellbore* WellboreFeature::getWitsmlWellbore() const
{
	const auto& witsmlWellbores = getRepository()->getTargetObjects<WITSML2_0_NS::Wellbore>(this);
	switch (witsmlWellbores.size()) {
	case 0: return nullptr;
	case 1: return witsmlWellbores[0];
	default: throw std::logic_error("There are too much associated WITSML wellbores.");
	}
}
