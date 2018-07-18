#pragma once

#include "Shader.h"
#include <GL\glew.h>
#include <SDL_opengl.h>

class OpenGLShader :public IShader
{
	friend class OpenGLRender;
private:
	OpenGLShader();
	~OpenGLShader();
public:
	// Inherited via IShader
	bool Create(ShaderType type) override;
	bool LoadFromMemory(const char * data) override;
	bool LoadFromString(std::string & filename) override;
	bool Compile() override;
	void Destroy() override;

	static GLenum ShaderTypeToGLShaderType(ShaderType type);
	GLuint GetShaderID()
	{
		return ShaderID;
	};

private:
	GLuint ShaderID;

};