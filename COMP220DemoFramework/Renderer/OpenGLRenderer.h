#pragma once

#include "Renderer.h"
#include "OpenGLVertexBuffer.h"
#include <iostream>

//Structure to Hold OGL versions
struct OpenGLVersion
{
	int MajorVersion;
	int MinorVersion;

	//Array of all supported OGL versions
	const static OpenGLVersion SupportedOpenGLVersions[];
};

//OpenGL Renderer which implements the IRenderer Interface
class OpenGLRender :public IRenderer
{
public:
	OpenGLRender();
	~OpenGLRender();

	//Create the Renderer
	bool Create(RendererDesc &desc, SDL_Window * window) override;
	void Destory() override;
	//Clear the current buffer
	void Clear(float r, float g, float b) override;
	//Begin Renderering
	void Begin() override;
	//End Endererering
	void End() override;

	IVertexBuffer * CreateAndFillVertexBuffer(void ** data, int size) override;
	IVertexBuffer * CreateVertexBuffer(int size) override;
	IVertexLayout * CreateVertexLayout(VertexDesc * desc, int numberOfElements) override;
	IShader * CreateShader(ShaderType type) override;
	IShaderProgram * CreateShaderProgram() override;
private:
	SDL_GLContext Context;
	SDL_Window * Window;


};