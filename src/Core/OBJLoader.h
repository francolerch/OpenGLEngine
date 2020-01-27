#pragma once
#include "pch.h"

namespace OGLE {
    class OBJLoader
    {
    private:
        std::vector<float> m_Vertices;
        std::vector<float> m_Texcoords;
        std::vector<float> m_Normals;
        std::vector<float> m_Data;
        std::vector<unsigned int> m_VertexIndices;
        std::vector<unsigned int> m_TexCoordsIndices;
        std::vector<unsigned int> m_NormalsIndices;
    public:
        OBJLoader(const std::string& path);
        ~OBJLoader() = default;

        const std::vector<float>& GetVertices() const;
        const std::vector<float>& GetTexCoord() const;
        const std::vector<float>& GetNormals() const;
        const std::vector<unsigned int>& GetVertexIndices() const;
        const std::vector<unsigned int>& GetTexCoordsIndices() const;
        const std::vector<unsigned int>& GetNormalsIndices() const;
        const std::vector<float>& GetData() const;
        const unsigned int GetVerticesSize() const { return m_Vertices.size() * sizeof(float); };
        const unsigned int GetTexCoordsSize() const { return m_Texcoords.size() * sizeof(float); };
        const unsigned int GetNormalsSize() const { return m_Normals.size() * sizeof(float); };
        const unsigned int GetDataSize() const { return m_Data.size() * sizeof(float); };
        const unsigned int GetVertexIndicesSize() const { return m_VertexIndices.size() * sizeof(unsigned int); };
        const unsigned int GetTexCoordsIndicesSize() const { return m_TexCoordsIndices.size() * sizeof(unsigned int); };
        const unsigned int GetNormalsIndicesSize() const { return m_NormalsIndices.size() * sizeof(unsigned int); };

        private:
        void Load(const std::string& path);
    };
}