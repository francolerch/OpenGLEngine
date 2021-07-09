#pragma once


#include "Core/Core.h"
#include <glad/glad.h> // holds all OpenGL type declarations

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <Renderer/Shader.h>

#include "Renderer/VertexArray.h"
#include "Renderer/Renderer.h"
#include "Renderer/VertexBufferLayout.h"
#include "Renderer/IndexBuffer.h"
#include "Renderer/Texture.h"
#include "Renderer/VertexBuffer.h"

using namespace std;

namespace OGLE {
	struct Vertex {
		// position
		glm::vec3 Position;
		// normal
		glm::vec3 Normal;
		// texCoords
		glm::vec2 TexCoords;
		// tangent
		glm::vec3 Tangent;
		// bitangent
		glm::vec3 Bitangent;
	};

	struct MeshTexture {
		unsigned int id;
		std::string type;
		std::string path;
	};

	class Mesh {
	public:
		// mesh Data
		std::vector<Vertex>       vertices;
		std::vector<unsigned int> indices;
		std::vector<MeshTexture>      textures;
		Ref<VertexArray> vertexArray;

		// constructor
		Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::vector<MeshTexture>& textures);

		// render the mesh
		void Draw(const Ref<Shader>& shader, const glm::mat4& transform);

	private:
		// render data 
		Ref<VertexBuffer> m_VertexBuffer;
		Ref<IndexBuffer> m_IndexBuffer;
		Ref<VertexBufferLayout> m_Layout;

		// initializes all the buffer objects/arrays
		void setupMesh();
	};
}