#include "pch.h"
#include "Scene.h"

#include "Renderer/Renderer.h"
#include "Components.h"
#include "Entity.h"

namespace OGLE {

    Scene::Scene()
    {
    }

    Entity Scene::CreateEntity(const std::string& name)
    {
        Entity entity = { m_Registry.create(), this };
        entity.AddComponent<TransformComponent>();
        auto& tag = entity.AddComponent<TagComponent>();
        tag.m_Tag = (name.empty()) ? "Entity" : name;
 
        return entity;
    }

    void Scene::DestroyEntity(Entity entity)
	    {
		    m_Registry.destroy(entity);
	    }

    void Scene::OnUpdate(float ts)
    {
        PreUpdate(ts);
        Update(ts);
        PostUpdate(ts);
    }

    void Scene::PreUpdate(float ts)
    {
   
    }

    void Scene::Update(float ts)
    {
    }

    void Scene::PostUpdate(float ts)
    {
    }
}