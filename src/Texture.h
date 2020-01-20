#pragma once
#include <string>

class Texture
{
public:
	Texture(const std::string& path);
	~Texture();

	int GetWidth() const { return m_Width; }
	int GetHeight() const { return m_Height; }

	unsigned int Get() const { return m_RendererID; };
	void Bind(unsigned int index) const;
private:
	std::string m_Path;
	int m_Width, m_Height;
	unsigned int m_RendererID;
	int m_NrChannels;
	//GLenum m_InternalFormat, m_DataFormat;
};