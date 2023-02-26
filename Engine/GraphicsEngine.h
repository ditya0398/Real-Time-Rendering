#pragma once
#include<Windows.h>
#include<glew.h>               // This SHOULD be above GL.h header.
#include<gl/GL.h>


class GraphicsEngine
{
private:
	HDC ghdc;
	HGLRC ghglrc;

public:
	int init();
	int init();
	

};

