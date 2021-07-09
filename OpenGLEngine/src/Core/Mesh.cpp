#include "pch.h"
#include "Mesh.h"
#include "glfw/glfw3.h"

OGLE::Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, const std::vector<MeshTexture>& textures)
	: vertices(vertices),
	indices(indices),
	textures(textures)
{
	// now that we have all the required data, set the vertex buffers and its attribute pointers.
	setupMesh();
}

void OGLE::Mesh::Draw(const Ref<Shader>& shader, const glm::mat4& transform )
{
	//glm::mat4 transform = glm::mat4(1.0f);
	//transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 1.0f, 0.0f));

	// bind appropriate textures
	unsigned int diffuseNr = 1;
	unsigned int specularNr = 1;
	unsigned int normalNr = 1;
	unsigned int heightNr = 1;
	for (unsigned int i = 0; i < textures.size(); i++)
	{
		glActiveTexture(GL_TEXTURE0 + i); // active proper texture unit before binding
		// retrieve texture number (the N in diffuse_textureN)
		string number;
		string name = textures[i].type;
		if (name == "texture_diffuse")
			number = std::to_string(diffuseNr++);
		else if (name == "texture_specular")
			number = std::to_string(specularNr++); // transfer unsigned int to stream
		else if (name == "texture_normal")
			number = std::to_string(normalNr++); // transfer unsigned int to stream
		else if (name == "texture_height")
			number = std::to_string(heightNr++); // transfer unsigned int to stream

		// now set the sampler to the correct texture unit
		glUniform1i(glGetUniformLocation(shader->GetRendererID(), (name + number).c_str()), i);
		// and finally bind the texture
		glBindTexture(GL_TEXTURE_2D, textures[i].id);
	}


	// draw mesh
	Renderer::Submit(shader, vertexArray, transform);

	// always good practice to set everything back to defaults once configured.
	glActiveTexture(GL_TEXTURE0);
}

void OGLE::Mesh::setupMesh()
{
	// create buffers/arrays
	vertexArray = CreateRef<VertexArray>();
	m_VertexBuffer = CreateRef<VertexBuffer>(&vertices[0], vertices.size() * sizeof(Vertex));
	m_IndexBuffer = CreateRef<IndexBuffer>(&indices[0], indices.size() * sizeof(unsigned int));
	m_Layout = CreateRef<VertexBufferLayout>();
	m_Layout->Push(3);
	m_Layout->Push(3);
	m_Layout->Push(2);
	m_Layout->Push(3);
	m_Layout->Push(3);

	vertexArray->AddBuffer(*m_VertexBuffer, *m_Layout);
	vertexArray->AddBuffer(*m_IndexBuffer);
}

