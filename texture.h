#ifndef TEXTURE_H
#define TEXTURE_H

#include "GL/glew.h"
#include "lodepng.h"
#include "stdio.h"


class Texture {
private:
	GLuint texture;
public:
	Texture();
	~Texture();
    GLuint readTexture(const char*);
    void delTexture();
    GLuint retTexture();
};

extern Texture *tex;
void initTextures();
void freeTextures();


#endif

