#pragma once
#include "glad/glad.h"
#include "Renderer/Buffer.h"

namespace OGLE {
	class IndexBuffer : public Buffer
	{
	private:
		unsigned int m_RendererID;

	public:
		IndexBuffer() = default;
		IndexBuffer(const unsigned int* data, unsigned int count) : Buffer(data, count, GL_ELEMENT_ARRAY_BUFFER) {};
		~IndexBuffer() = default;
	};
}