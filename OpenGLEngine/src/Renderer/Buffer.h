#pragma once
#include "glad/glad.h"

namespace OGLE {

    class Buffer
    {
    protected:
        unsigned int m_RendererId;
        const void* m_Data;
        unsigned int m_Size;
        GLenum m_Type;
    protected:
        Buffer() = default;
        Buffer(const void* data, unsigned int size, GLenum type);

    public:
        virtual ~Buffer();
        inline unsigned int GetId() const { return m_RendererId; };
        inline unsigned int GetSize() const { return m_Size; };
        inline GLenum GetType() const { return m_Type; };
        inline void SetData(const void* data, unsigned int size) { m_Data = data; m_Size = size; };
        void Bind() const;
        void UnBind() const;

        virtual unsigned int GetCount() const = 0;
    };
}