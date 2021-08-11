/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

// Created by : Galib Arrieta (aka "lumbermixalot@github", "galibzon@github")

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "RenderJoyEditorModule.h"
#include "RenderJoySystemComponent.h"
#include "Components/RenderJoyTextureEditorComponent.h"
#include "Components/RenderJoyKeyboardEditorComponent.h"
#include "Components/RenderJoyPassEditorComponent.h"
#include "Components/RenderJoySettingsEditorComponent.h"

namespace RenderJoy
{
    RenderJoyEditorModule::RenderJoyEditorModule()
    {
        m_descriptors.insert(m_descriptors.end(), {
            RenderJoySystemComponent::CreateDescriptor(),
            RenderJoyTextureEditorComponent::CreateDescriptor(),
            RenderJoyKeyboardEditorComponent::CreateDescriptor(),
            RenderJoyPassEditorComponent::CreateDescriptor(),
            RenderJoySettingsEditorComponent::CreateDescriptor(),
        });
    }

    AZ::ComponentTypeList RenderJoyEditorModule::GetRequiredSystemComponents() const
    {
        return AZ::ComponentTypeList{
            azrtti_typeid<RenderJoySystemComponent>(),
        };
    }

}

// DO NOT MODIFY THIS LINE UNLESS YOU RENAME THE GEM
// The first parameter should be GemName_GemIdLower
// The second should be the fully qualified name of the class above
AZ_DECLARE_MODULE_CLASS(RenderJoy_deda12623060436ca264dec26835db06, RenderJoy::RenderJoyEditorModule)
