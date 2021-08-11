
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "RenderJoyDemoProjectSystemComponent.h"

namespace RenderJoyDemoProject
{
    class RenderJoyDemoProjectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(RenderJoyDemoProjectModule, "{374cb4a1-6e65-4d39-a233-cc094e8a3c9d}", AZ::Module);
        AZ_CLASS_ALLOCATOR(RenderJoyDemoProjectModule, AZ::SystemAllocator, 0);

        RenderJoyDemoProjectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                RenderJoyDemoProjectSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<RenderJoyDemoProjectSystemComponent>(),
            };
        }
    };
}// namespace RenderJoyDemoProject

AZ_DECLARE_MODULE_CLASS(Gem_RenderJoyDemoProject, RenderJoyDemoProject::RenderJoyDemoProjectModule)
