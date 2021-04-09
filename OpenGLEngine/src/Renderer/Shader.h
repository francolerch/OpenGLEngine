#pragma once
#include <string>
#include <unordered_map>
#include "glm/glm.hpp"

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:
	std::string m_Filepath;
	unsigned int m_RendererID;
	mutable std::unordered_map<std::string, int> m_UniformLocationCache;

public:
	Shader(const std::string& filepath);
	~Shader();

	void Bind() const;
	void Unbind() const;

	// Set uniforms
	void SetInt(const std::string& name, int value);
	void SetFloat(const std::string& name, float value);
	void SetFloat3(const std::string& name, float v0, float v1, float v2);
	void SetFloat4(const std::string& name, float v0, float v1, float v2, float v3);
	void SetMat4(const std::string& name, const glm::mat4& matrix);
	void SetUniformVec3f(const std::string& name, const glm::vec3& vec);


private:
	int GetUniformLocation(const std::string& name) const;
	unsigned int CompileShader(unsigned int type, const std::string& source);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
	ShaderProgramSource ParseShader(const std::string& filepath);
};