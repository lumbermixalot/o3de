/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

// Created by : Galib Arrieta (aka "lumbermixalot@github", "galibzon@github")

#include <AzCore/RTTI/BehaviorContext.h>
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include <AzToolsFramework/API/ViewPaneOptions.h>
#include <LyViewPaneNames.h>

// RenderJoy
#include "RenderJoySystemComponent.h"
#include "MainWindow.h"
#include <RenderJoy/RenderJoySettingsBus.h>

namespace RenderJoy
{
    RenderJoySystemComponent::RenderJoySystemComponent()
    {

    }

    RenderJoySystemComponent::~RenderJoySystemComponent()
    {
        AzToolsFramework::CloseViewPane(RenderJoyName);
        AzToolsFramework::UnregisterViewPane(RenderJoyName);
    }

    void RenderJoySystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<RenderJoySystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<RenderJoySystemComponent>("RenderJoy", "A sandbox to play with Atom Shaders")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System", 0xc94d118b))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void RenderJoySystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("RenderJoyService"));
    }

    void RenderJoySystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("RenderJoyService"));
    }

    void RenderJoySystemComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        AZ_UNUSED(required);
    }

    void RenderJoySystemComponent::GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        AZ_UNUSED(dependent);
    }

    void RenderJoySystemComponent::Init()
    {

    }

    void RenderJoySystemComponent::Activate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void RenderJoySystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
    }


    ////////////////////////////////////////////////////////////////////////
    // AztoolsFramework::EditorEvents::Bus::Handler overrides
    void RenderJoySystemComponent::NotifyRegisterViews()
    {
        AZ::Vector2 size(1280, 720);
        RenderJoySettingsRequestBus::BroadcastResult(size, &RenderJoySettingsRequests::GetRenderTargetSize);
        uint32_t width = aznumeric_cast<uint32_t>(AZStd::ceilf(size.GetX()));
        uint32_t height = aznumeric_cast<uint32_t>(AZStd::ceilf(size.GetY()));

        AzToolsFramework::ViewPaneOptions options;
        options.paneRect = QRect(0, 0, width, height);
        options.isDockable = false;
        AzToolsFramework::RegisterViewPane<RenderJoy::MainWindow>(RenderJoyName, LyViewPane::CategoryOther, options);
    }
    ////////////////////////////////////////////////////////////////////////
}
