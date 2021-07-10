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
		// Render
		PerspectiveCamera* mainCamera = nullptr;
		glm::mat4 cameraTransform { 1.0f };

		{
			auto view = m_Registry.view<TransformComponent, CameraComponent>();
			for (auto entity : view)
			{
				auto [transform, camera] = view.get<TransformComponent, CameraComponent>(entity);

				mainCamera = &camera.m_Camera;
				cameraTransform = transform.GetTransform();
				break;
			}
		}

        if (mainCamera)
        {
            mainCamera->OnUpdate(ts);
            //Renderer::BeginScene(*mainCamera);
        }


		{
			auto view = m_Registry.view<TransformComponent, DirectionalLightComponent>();
			for (auto entity : view)
			{
				auto [transform, light] = view.get<TransformComponent, DirectionalLightComponent>(entity);

				m_DirectionalLight = transform.Translation;
				break;
			}
		}
    }

	void Scene::OnDraw()
	{
		{
			auto view = m_Registry.view<TransformComponent, RenderComponent>();
			for (auto entity : view)
			{
				auto [transform, render] = view.get<TransformComponent, RenderComponent>(entity);

				render.m_Model.GetShader()->SetUniformVec3f("lightPos", m_DirectionalLight);
				render.m_Model.Draw(transform.GetTransform());
				break;
			}
		}
	}

}