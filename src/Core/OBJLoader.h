#pragma once
#include "pch.h"

namespace OGLE {
    class OBJLoader
    {
    private:
        std::vector<float> m_Vertices;
        std::vector<unsigned int> m_Indices;
    public:
        OBJLoader(const std::string& path);
        ~OBJLoader() = default;

        const std::vector<float>& GetVertices() const;
        const std::vector<unsigned int>& GetIndices() const;
        const unsigned int GetVerticesSize() const { return m_Vertices.size() * sizeof(float); };
        const unsigned int GetIndicesSize() const { return m_Indices.size() * sizeof(unsigned int); };
    };
}