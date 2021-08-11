
#pragma once

#include <AzCore/Component/Component.h>

#include <RenderJoyDemoProject/RenderJoyDemoProjectBus.h>

namespace RenderJoyDemoProject
{
    class RenderJoyDemoProjectSystemComponent
        : public AZ::Component
        , protected RenderJoyDemoProjectRequestBus::Handler
    {
    public:
        AZ_COMPONENT(RenderJoyDemoProjectSystemComponent, "{9428fb4f-d791-4388-b67b-7877dc75b486}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        RenderJoyDemoProjectSystemComponent();
        ~RenderJoyDemoProjectSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // RenderJoyDemoProjectRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
