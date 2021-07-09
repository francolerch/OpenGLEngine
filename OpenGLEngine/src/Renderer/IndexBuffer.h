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
		IndexBuffer(const void* data, unsigned int count) : Buffer(data, count, GL_ELEMENT_ARRAY_BUFFER) {};
		~IndexBuffer() = default;

		virtual unsigned int GetCount() const override { return m_Size / sizeof(unsigned int); };
	};
}