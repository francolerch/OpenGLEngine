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
            m_Data.push_back(m_Texcoords[i]);
            m_Data.push_back(m_Texcoords[i+1]);
            m_Data.push_back(m_Texcoords[i+2]);
            m_Data.push_back(m_Normals[i]);
            m_Data.push_back(m_Normals[i+1]);
            m_Data.push_back(m_Normals[i+2]);
        }
    }

    void OBJLoader::Load(const std::string& path)
    {
        std::ifstream source(path);
        OG_ASSERT(source, "Cannot open path: " + path);
        std::string line;

        while (std::getline(source, line))
        {
            if (line.substr(0, 2) == "v ")
            {
                std::istringstream s(line.substr(2));
                float a;
                s >> a;
                m_Vertices.push_back(a);
                s >> a;
                m_Vertices.push_back(a);
                s >> a;
                m_Vertices.push_back(a);
            }

            if (line.substr(0, 3) == "vt ")
            {
                 std::istringstream s(line.substr(3));
                float a;
                s >> a;
                m_Texcoords.push_back(a);
                s >> a;
                m_Texcoords.push_back(a);
                s >> a;
                m_Texcoords.push_back(a);
            }

            if (line.substr(0, 3) == "vn ")
            {
                std::istringstream s(line.substr(3));
                float a;
                s >> a;
                m_Normals.push_back(a);
                s >> a;
                m_Normals.push_back(a);
                s >> a;
                m_Normals.push_back(a);
            }

            if (line.substr(0, 2) == "f ")
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