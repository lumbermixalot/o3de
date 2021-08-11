/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

// Created by : Galib Arrieta (aka "lumbermixalot@github", "galibzon@github")

#pragma once

#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

namespace RenderJoy
{
    class RenderJoyEditorModule
        : public  AZ::Module
    {
    public:
        AZ_RTTI(RenderJoyEditorModule, "{DEDA1262-3060-436C-A264-DEC26835DB06}", AZ::Module);
        AZ_CLASS_ALLOCATOR(RenderJoyEditorModule, AZ::SystemAllocator, 0);

        RenderJoyEditorModule();

        AZ::ComponentTypeList GetRequiredSystemComponents() const override;
    };
}
