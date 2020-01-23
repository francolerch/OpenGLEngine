#pragma once
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace OGLE {

    class Entity
    {
    protected:
        glm::vec3 m_Position;
    protected:
        Entity(const glm::vec3& position) : m_Position(position) {};
        virtual ~Entity() = default;

    public:
        inline glm::vec3 GetPos() const { return m_Position; };
        virtual void OnUpdate(float dt) = 0;
    };
}