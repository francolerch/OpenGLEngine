#include "GameLayer.h"
#include <imgui/imgui.h>
#include "Scene/Components.h"

namespace SANDBOX
{
	GameLayer::GameLayer()
		: Layer("EditorLayer")
	{

	}

	void GameLayer::OnAttach()
	{
		OGLE::FrameBufferSpecification fbSpec;
		fbSpec.Width = 1280;
		fbSpec.Height = 720;
		m_FrameBuffer = OGLE::FrameBuffer::Create(fbSpec);
		
		m_ActiveScene = CreateScope<Scene>();

		Entity m_ActiveCamera = m_ActiveScene->CreateEntity("Camera");
		m_ActiveCamera.AddComponent<CameraComponent>();

		Entity Cube = m_ActiveScene->CreateEntity("Cube");
		Cube.AddComponent<RenderComponent>("res/models/me/cube.obj");

	}

	void GameLayer::OnDetach()
	{
	}

	void GameLayer::OnUpdate(float ts)
	{
		// updates

		if (OGLE::FrameBufferSpecification spec = m_FrameBuffer->GetSpecification();
			m_ViewportSize.x > 0.0f && m_ViewportSize.y > 0.0f && // zero sized framebuffer is invalid
			(spec.Width != m_ViewportSize.x || spec.Height != m_ViewportSize.y))
		{
			m_FrameBuffer->Resize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);
			//m_CameraController.OnResize(m_ViewportSize.x, m_ViewportSize.y);
			//m_EditorCamera.SetViewportSize(m_ViewportSize.x, m_ViewportSize.y);
			//m_ActiveScene->OnViewportResize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);
		}

		m_ActiveScene->OnUpdate(ts);



		// render Scene
		m_FrameBuffer->Bind();
		OGLE::Renderer::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		OGLE::Renderer::Clear();
		m_ActiveScene->OnDraw();
		m_FrameBuffer->Unbind();
	}

	void GameLayer::OnImGuiRender()
	{
		static bool p_open = true;
		
		static bool opt_fullscreen = true;
		static bool opt_padding = false;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

		// Viewport

		// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
		// because it would be confusing to have two docking targets within each others.
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		if (opt_fullscreen)
		{
			const ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->WorkPos);
			ImGui::SetNextWindowSize(viewport->WorkSize);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}
		else
		{
			dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
		}

		// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
		// and handle the pass-thru hole, so we ask Begin() to not render a background.
		if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;

		// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
		// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
		// all active windows docked into it will lose their parent and become undocked.
		// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
		// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
		if (!opt_padding)
			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("DockSpace Demo", &p_open, window_flags);
		if (!opt_padding)
			ImGui::PopStyleVar();

		if (opt_fullscreen)
			ImGui::PopStyleVar(2);

		// DockSpace
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("Options"))
			{
				// Disabling fullscreen would allow the window to be moved to the front of other windows,
				// which we can't undo at the moment without finer window depth/z control.
				ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen);
				ImGui::MenuItem("Padding", NULL, &opt_padding);
				ImGui::Separator();

				if (ImGui::MenuItem("Flag: NoSplit", "", (dockspace_flags & ImGuiDockNodeFlags_NoSplit) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoSplit; }
				if (ImGui::MenuItem("Flag: NoResize", "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoResize; }
				if (ImGui::MenuItem("Flag: NoDockingInCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingInCentralNode) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_NoDockingInCentralNode; }
				if (ImGui::MenuItem("Flag: AutoHideTabBar", "", (dockspace_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0)) { dockspace_flags ^= ImGuiDockNodeFlags_AutoHideTabBar; }
				if (ImGui::MenuItem("Flag: PassthruCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) != 0, opt_fullscreen)) { dockspace_flags ^= ImGuiDockNodeFlags_PassthruCentralNode; }
				ImGui::Separator();

				if (ImGui::MenuItem("Close", NULL, false, p_open != NULL))
					p_open = false;
				ImGui::EndMenu();
			}
			

			ImGui::EndMenuBar();
		}

		ImGui::End();

		// Editor view
		ImGui::Begin("Editor", &p_open);

		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
		m_ViewportSize = { viewportPanelSize.x, viewportPanelSize.y };

		uint32_t textureID = m_FrameBuffer->GetColorAttachmentRendererID();
		ImGui::Image(reinterpret_cast<void*>(textureID), ImVec2{ viewportPanelSize.x, viewportPanelSize.y }, ImVec2{ 0, 1 }, ImVec2{ 1, 0 });
		ImGui::End();

		// Inspector

		ImGui::ShowDemoWindow(&p_open);

		ImGui::Begin("Scene Hierarchy", &p_open);

		m_ActiveScene->Reg().each([&](auto entityID)
			{
				Entity entity{ entityID , m_ActiveScene.get() };
				

				auto& tag = entity.GetComponent<TagComponent>().m_Tag;

				ImGuiTreeNodeFlags flags = ((m_SelectionContext == entity) ? ImGuiTreeNodeFlags_Selected : 0) | ImGuiTreeNodeFlags_OpenOnArrow;
				flags |= ImGuiTreeNodeFlags_SpanAvailWidth;
				bool opened = ImGui::TreeNodeEx((void*)(uint64_t)(uint32_t)entity, flags, tag.c_str());
				if (ImGui::IsItemClicked())
				{
					m_SelectionContext = entity;
				}

				bool entityDeleted = false;
				if (ImGui::BeginPopupContextItem())
				{
					if (ImGui::MenuItem("Delete Entity"))
						entityDeleted = true;

					ImGui::EndPopup();
				}

				if (opened)
				{
					/*ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_SpanAvailWidth;
					bool opened = ImGui::TreeNodeEx((void*)9817239, flags, tag.c_str());
					if (opened)
						ImGui::TreePop();
					*/
					ImGui::TreePop();
				}

				if (entityDeleted)
				{
					m_ActiveScene->DestroyEntity(entity);
					if (m_SelectionContext == entity)
						m_SelectionContext = {};
				}

			});
		
		if (ImGui::IsMouseDown(0) && ImGui::IsWindowHovered())
			m_SelectionContext = {};

		// Right-click on blank space
		if (ImGui::BeginPopupContextWindow(0, 1, false))
		{
			if (ImGui::MenuItem("Create Empty Entity"))
				m_ActiveScene->CreateEntity("Empty Entity");

			ImGui::EndPopup();
		}
		ImGui::End();

		ImGui::Begin("Properties");
		if (m_SelectionContext)
		{
			const ImGuiTreeNodeFlags treeNodeFlags = ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_SpanAvailWidth | ImGuiTreeNodeFlags_AllowItemOverlap | ImGuiTreeNodeFlags_FramePadding;
			if (m_SelectionContext.HasComponent<TransformComponent>())
			{
				std::string name = "Transform";
				TransformComponent& component = m_SelectionContext.GetComponent<TransformComponent>();
				ImVec2 contentRegionAvailable = ImGui::GetContentRegionAvail();

				ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2{ 4, 4 });
				float lineHeight = 1.f;//GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;
				ImGui::Separator();
				bool open = ImGui::TreeNodeEx((void*)typeid(TransformComponent).hash_code(), treeNodeFlags, name.c_str());
				ImGui::PopStyleVar(
				);
				ImGui::SameLine(contentRegionAvailable.x - lineHeight * 0.5f);
				if (ImGui::Button("+", ImVec2{ lineHeight, lineHeight }))
				{
					ImGui::OpenPopup("ComponentSettings");
				}

				bool removeComponent = false;
				if (ImGui::BeginPopup("ComponentSettings"))
				{
					if (ImGui::MenuItem("Remove component"))
						removeComponent = true;

					ImGui::EndPopup();
				}

				if (open)
				{
					std::string label = "Translation";
					glm::vec3& values = component.Translation;
					float columnWidth = 100.0f;
					float resetValue = 0.0f;

					ImGuiIO & io = ImGui::GetIO();
					auto boldFont = io.Fonts->Fonts[0];

					ImGui::PushID(label.c_str());

					ImGui::Columns(2);
					ImGui::SetColumnWidth(0, columnWidth);
					ImGui::Text(label.c_str());
					ImGui::NextColumn();

					//ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
					//ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0, 0 });
					ImGui::PushItemWidth(80);

					ImGui::DragFloat("X", &values.x, 0.1f);
					ImGui::SameLine();
					ImGui::DragFloat("Y", &values.y, 0.1f);
					ImGui::SameLine();
					ImGui::DragFloat("Z", &values.z, 0.1f);
					ImGui::PopItemWidth();

					ImGui::Columns(1);

					ImGui::PopID();

					label = "Rotation";
					glm::vec3& values2 = component.Rotation;
					ImGui::PushID(label.c_str());

					ImGui::Columns(2);
					ImGui::SetColumnWidth(0, columnWidth);
					ImGui::Text(label.c_str());
					ImGui::NextColumn();

					//ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
					//ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0, 0 });
					ImGui::PushItemWidth(80);

					ImGui::DragFloat("X", &values2.x, 0.1f);
					ImGui::SameLine();
					ImGui::DragFloat("Y", &values2.y, 0.1f);
					ImGui::SameLine();
					ImGui::DragFloat("Z", &values2.z, 0.1f);
					ImGui::PopItemWidth();

					ImGui::Columns(1);

					ImGui::PopID();

					label = "Scale";
					glm::vec3& values3 = component.Scale;
					ImGui::PushID(label.c_str());

					ImGui::Columns(2);
					ImGui::SetColumnWidth(0, columnWidth);
					ImGui::Text(label.c_str());
					ImGui::NextColumn();

					//ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
					//ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0, 0 });
					ImGui::PushItemWidth(80);

					ImGui::DragFloat("X", &values3.x, 0.1f, 0.f, 1000.f);
					ImGui::SameLine();
					ImGui::DragFloat("Y", &values3.y, 0.1f, 0.f, 1000.f);
					ImGui::SameLine();
					ImGui::DragFloat("Z", &values3.z, 0.1f, 0.f, 1000.f);
					ImGui::PopItemWidth();

					ImGui::Columns(1);

					ImGui::PopID();

					ImGui::TreePop();
				}

				if (removeComponent)
					m_SelectionContext.RemoveComponent<TransformComponent>();
			}
			
		}	

		ImGui::End();
	}
}
