#pragma once
#include "Core/Core.h"
#include "entt/entt.hpp"

namespace OGLE
{
    class Scene
    {
    public:
        Scene();
        ~Scene() = default;

        void OnUpdate(float ts);
        
        class Entity CreateEntity(const std::string& name = "Entity");
        void DestroyEntity(Entity entity);

        // TEMP
        entt::registry& Reg() { return m_Registry; }

    private:
        entt::registry m_Registry;

        friend class Entity;

        void PreUpdate(float ts);
        void Update(float ts);
        void PostUpdate(float ts);
    };
}