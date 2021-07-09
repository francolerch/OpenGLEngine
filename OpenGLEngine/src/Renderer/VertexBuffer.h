#pragma once
#include "Renderer/Buffer.h"

namespace OGLE {
    class VertexBuffer : public Buffer
    {
    public:
        VertexBuffer() = default;
        VertexBuffer(const void* data, unsigned int size) : Buffer(data, size, GL_ARRAY_BUFFER) {};
        ~VertexBuffer() = default;

        virtual unsigned int GetCount() const override { return m_Size / sizeof(float); };
    };
}