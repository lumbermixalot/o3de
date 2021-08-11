
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace RenderJoyDemoProject
{
    class RenderJoyDemoProjectRequests
    {
    public:
        AZ_RTTI(RenderJoyDemoProjectRequests, "{9f92cd62-1459-45b8-a7db-e76405b8df9c}");
        virtual ~RenderJoyDemoProjectRequests() = default;
        // Put your public methods here
    };
    
    class RenderJoyDemoProjectBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using RenderJoyDemoProjectRequestBus = AZ::EBus<RenderJoyDemoProjectRequests, RenderJoyDemoProjectBusTraits>;
    using RenderJoyDemoProjectInterface = AZ::Interface<RenderJoyDemoProjectRequests>;

} // namespace RenderJoyDemoProject
