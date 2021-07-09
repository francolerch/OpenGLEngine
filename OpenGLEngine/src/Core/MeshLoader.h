#pragma once

#include "Mesh.h"
#include "Core.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include "Renderer/Texture.h"

namespace OGLE
{
	class MeshLoader
	{
	public:
		MeshLoader(const std::string& path);
		void Draw(const Ref<Shader>& shader);
	private:
		// model data
		std::vector<Mesh> meshes;
		std::string directory;
		std::vector<Texture> m_textures;

		void loadModel(string path);
		void processNode(aiNode* node, const aiScene* scene);
		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
		vector<MeshTexture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
			string typeName);
	};
}