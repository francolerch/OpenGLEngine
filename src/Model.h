#pragma once
#include "pch.h"
#include "Renderer/Shader.h"
#include "Mesh.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

class Model 
{
    public:
        /*  Functions   */
        Model(const std::string& path) : path(path) { loadModel(); };
        void Draw(Shader shader);	
    private:
        /*  Model Data  */
        std::vector<Mesh> meshes;
        std::string directory;
        std::vector<Tex> textures_loaded; 
        std::string path;
        /*  Functions   */
        void loadModel();
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Tex> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
        unsigned int TextureFromFile(const char *path, const std::string &directory);
};