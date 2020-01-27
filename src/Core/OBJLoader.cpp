#include "OBJLoader.h"
#include <fstream>

namespace OGLE {

    OBJLoader::OBJLoader(const std::string& path)
    {
        Load(path);

        m_Data.reserve(m_Vertices.size() + m_Normals.size());
        for (size_t i = 0; i < m_Vertices.size(); i+=3)
        {
            m_Data.push_back(m_Vertices[i]);
            m_Data.push_back(m_Vertices[i+1]);
            m_Data.push_back(m_Vertices[i+2]);
            m_Data.push_back(m_Normals[i]);
            m_Data.push_back(m_Normals[i+1]);
            m_Data.push_back(m_Normals[i+2]);
        }
        /*std::vector<float> vec = {
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
        m_VertexIndices = vec2;*/
    }

    void OBJLoader::Load(const std::string& path)
    {
        std::ifstream source(path);
        std::string line;

        while (std::getline(source, line))
        {
            std::string::size_type a = line.find("v ");
            if (a != -1)
            {

                line = line.substr(2);
                std::string::size_type beg = 0;
	            for (auto end = 0; (end = line.find(" ", end)) != std::string::npos; ++end)
                {
                    m_Vertices.push_back(std::stof(line.substr(beg, end - beg)));
                    beg = end + 1;
                }
                m_Vertices.push_back(std::stof(line.substr(beg)));
            }

            if (line.find("vt ") != std::string::npos)
            {
                line = line.substr(3);
                std::string::size_type beg = 0;
	            for (auto end = 0; (end = line.find(" ", end)) != std::string::npos; ++end)
                {
                    m_Texcoords.push_back(std::stof(line.substr(beg, end - beg)));
                    beg = end + 1;
                }
                m_Texcoords.push_back(std::stof(line.substr(beg)));
            }

            if (line.find("vn ") != std::string::npos)
            {
                line = line.substr(3);
                std::string::size_type beg = 0;
	            for (auto end = 0; (end = line.find(" ", end)) != std::string::npos; ++end)
                {
                    m_Normals.push_back(std::stof(line.substr(beg, end - beg)));
                    beg = end + 1;
                }
                m_Normals.push_back(std::stof(line.substr(beg)));
            }

            if (line.find("f ") != std::string::npos)
            {
                line = line.substr(2);
                std::string::size_type beg = 0;
                std::vector<std::string> indices;
	            for (auto end = 0; (end = line.find(" ", end)) != std::string::npos; ++end)
                {
                    indices.push_back(line.substr(beg, end - beg));
                    beg = end + 1;
                }
                indices.push_back(line.substr(beg));

                for (auto& i : indices)
                {
                    auto beg = 0;
                    auto end = i.find("/", beg);
                    m_VertexIndices.push_back(std::stof(i.substr(beg, end))-1);
                    beg = end + 1;
                    end = i.find("/", beg);
                    m_TexCoordsIndices.push_back(std::stof(i.substr(beg, end))-1);
                    beg = end + 1;
                    m_NormalsIndices.push_back(std::stof(i.substr(beg))-1);
                    
                }
            }
        }
    }

    const std::vector<float>& OBJLoader::GetVertices() const
    {
        return m_Vertices;
        
    }

    const std::vector<float>& OBJLoader::GetTexCoord() const
    {
        return m_Texcoords;
    }
    
    const std::vector<float>& OBJLoader::GetNormals() const
    {
        return m_Normals;
    }

    const std::vector<float>& OBJLoader::GetData() const 
    {
        return m_Data;
    }
    
    const std::vector<unsigned int>& OBJLoader::GetVertexIndices() const
    {
        return m_VertexIndices;
    }

    const std::vector<unsigned int>& OBJLoader::GetTexCoordsIndices() const
    {
        return m_TexCoordsIndices;
    }

    const std::vector<unsigned int>& OBJLoader::GetNormalsIndices() const
    {
        return m_NormalsIndices;
    }
}