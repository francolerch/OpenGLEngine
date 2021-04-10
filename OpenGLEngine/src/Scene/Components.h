#pragma once
#include "Core/Core.h"
#include "glm/glm.hpp"

namespace OGLE
{
    struct TagComponent
    {
        std::string m_Tag;

        TagComponent() = default;
        TagComponent(const TagComponent&) = default;
        TagComponent(const std::string& tag)
            : m_Tag(tag) {};

        operator std::string& () { return m_Tag; };
        operator const std::string& () const { return m_Tag; };
    };
    
    struct TransformComponent
    {
        glm::vec4 m_Transform { 1.0f };

        TransformComponent() = default;
        TransformComponent(const TransformComponent&) = default;
        TransformComponent(const glm::vec4& transform)
            : m_Transform(transform) {};

        operator glm::vec4& () { return m_Transform; };
        operator const glm::vec4& () const { return m_Transform; };
    };
}