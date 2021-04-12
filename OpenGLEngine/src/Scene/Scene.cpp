#include "pch.h"
#include "Scene.h"

#include "Renderer/Renderer.h"
#include "Components.h"
#include "Entity.h"
#include "Scene.h"

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
		// Render 2D
		PerspectiveCamera* mainCamera = nullptr;
		glm::mat4 cameraTransform { 1.0f };

		{
			auto view = m_Registry.view<TransformComponent, CameraComponent>();
			for (auto entity : view)
			{
				auto [transform, camera] = view.get<TransformComponent, CameraComponent>(entity);

				mainCamera = &camera.m_Camera;
				cameraTransform = transform.m_Transform;
				break;
			}
		}

        if (mainCamera)
        {
            mainCamera->OnUpdate(ts);
            Renderer::BeginScene(*mainCamera);
        }


        
    }

}