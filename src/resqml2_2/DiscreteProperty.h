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
#pragma once

#include "../resqml2/DiscreteProperty.h"

namespace RESQML2_2_NS
{
	/**
	 * Proxy class for a discrete  property. Such property contains discrete integer values;
	 * typically used to store any type of index. So that the value range can be known before
	 * accessing all values, it also optionally stores the minimum and maximum value in the range.
	 */
	class DiscreteProperty final : public RESQML2_NS::DiscreteProperty
	{
	public:

		/**
		 * Only to be used in partial transfer context.
		 *
		 * @param [in]	partialObject	If non-null, the partial object.
		 */
		DLL_IMPORT_OR_EXPORT DiscreteProperty(gsoap_resqml2_0_1::eml20__DataObjectReference* partialObject) : RESQML2_NS::DiscreteProperty(partialObject) {}


		/**
		 * Creates a discrete property which is of a local property kind.
		 *
		 * @exception	std::invalid_argument	If @p or @p localPropKind is null. If @p dimension is zero.
		 *
		 * @param [in]	rep			  	The representation on which this property is attached to. It
		 * 								cannot be null.
		 * @param 	  	guid		  	The guid to set to the property. If empty then a new guid will be
		 * 								generated.
		 * @param 	  	title		  	The title to set to the property. If empty then \"unknown\" title
		 * 								will be set.
		 * @param 	  	dimension	  	The dimension of each value of this property. Dimension is 1 for
		 * 								a scalar property.
		 * @param 	  	attachmentKind	The topological element on which the property values are attached
		 * 								to.
		 * @param [in]	propKind	 	The property kind of these property values. It cannot be null.
		 */
		DiscreteProperty(RESQML2_NS::AbstractRepresentation* rep, const std::string& guid, const std::string& title,
			unsigned int dimension, gsoap_eml2_3::resqml22__IndexableElement attachmentKind, EML2_NS::PropertyKind* propKind);

		/**
		 * Creates an instance of this class by wrapping a gSOAP instance.
		 *
		 * @param [in]	fromGsoap	If non-null, the gSOAP instance.
		 */
		DiscreteProperty(gsoap_eml2_3::_resqml22__DiscreteProperty* fromGsoap): RESQML2_NS::DiscreteProperty(fromGsoap) {}

		/** Destructor does nothing since the memory is managed by the gsoap context. */
		~DiscreteProperty() {}

		DLL_IMPORT_OR_EXPORT std::string pushBackRefToExistingDataset(EML2_NS::AbstractHdfProxy* proxy, const std::string & datasetName, LONG64 nullValue, LONG64 minimumValue, LONG64 maximumValue) final;
		using AbstractDiscreteOrCategoricalProperty::pushBackRefToExistingDataset;

		DLL_IMPORT_OR_EXPORT LONG64 getNullValue(unsigned int patchIndex = (std::numeric_limits<unsigned int>::max)()) const final;

		DLL_IMPORT_OR_EXPORT bool hasMinimumValue(unsigned int index = 0) const final;

		DLL_IMPORT_OR_EXPORT LONG64 getMinimumValue(unsigned int index = 0) const final;

		DLL_IMPORT_OR_EXPORT bool hasMaximumValue(unsigned int index = 0) const final;

		DLL_IMPORT_OR_EXPORT LONG64 getMaximumValue(unsigned int index = 0) const final;

		DLL_IMPORT_OR_EXPORT void setMinimumValue(LONG64 value, unsigned int index = 0) const final;

		DLL_IMPORT_OR_EXPORT void setMaximumValue(LONG64 value, unsigned int index = 0) const final;

		bool validatePropertyKindAssociation(EML2_NS::PropertyKind*) final { return true; }

		bool validatePropertyKindAssociation(gsoap_resqml2_0_1::resqml20__ResqmlPropertyKind) final { return true; }

	private:

		size_t getMinimumValueSize() const;
		size_t getMaximumValueSize() const;
	};
}