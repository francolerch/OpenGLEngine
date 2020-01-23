#pragma once
#include "pch.h"
#include "Core.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "Shader.h"
#include "Texture.h"

class Renderer
{
private:
    std::vector<VertexArray> m_VAO;
    std::vector<VertexBuffer> m_BVO;
    std::vector<Shader> m_Shaders;
    std::vector<Texture> m_Textures;
public:
    Renderer();
    ~Renderer();
};

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}
