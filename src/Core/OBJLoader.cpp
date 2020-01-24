#include "OBJLoader.h"

namespace OGLE {

    OBJLoader::OBJLoader(const std::string& path)
    {
        std::vector<float> vec = {
            -0.5f, -0.5f, 0.0f,  // bottom left near
            -0.5f,  0.5f, 0.0f,   // top left near
            0.5f,  0.5f, 0.0f,  // top right near
            0.5f, -0.5f, 0.0f,  // bottom right near
            -0.5f, -0.5f, -0.5f,  // bottom left far
            -0.5f,  0.5f, -0.5f,   // top left far
            0.5f,  0.5f, -0.5f,  // top right far
            0.5f, -0.5f, -0.5f
        };

        std::vector<unsigned int> vec2 = {
            0, 2, 1,
            0, 3, 2,

            0, 1, 4,
            1, 5, 4,

            4, 7, 5,
            5, 6, 7,

            7, 6, 2,
            2, 3, 7,

            1, 2, 5,
            5, 2, 6,

            0, 4, 3,
            3, 4, 7
        };

        m_Vertices = vec;
        m_Indices = vec2;
    }

    const std::vector<float>& OBJLoader::GetVertices() const
    {
        return m_Vertices;
        
    }
    
    const std::vector<unsigned int>& OBJLoader::GetIndices() const
    {
        return m_Indices;
    }
}