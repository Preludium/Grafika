#include "texture.h"

Texture *tex;

void initTextures()
{
    tex = new Texture[7];
    tex[0].readTexture("block1.png");
    tex[1].readTexture("block2.png");
    tex[2].readTexture("block3.png");
    tex[3].readTexture("block4.png");
    tex[4].readTexture("block5.png");
    tex[5].readTexture("block6.png");
    tex[6].readTexture("block7.png");
}

void freeTextures()
{
    tex[0].delTexture();
    tex[1].delTexture();
    tex[2].delTexture();
    tex[3].delTexture();
    tex[4].delTexture();
    tex[5].delTexture();
    tex[6].delTexture();
}

Texture::Texture()
{

}

Texture::~Texture()
{

}


GLuint Texture::readTexture(const char* filename)
{
    GLuint tex;
    glActiveTexture(GL_TEXTURE0);

    //Wczytanie do pamięci komputera
    std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
    unsigned width, height;   //Zmienne do których wczytamy wymiary obrazka
    //Wczytaj obrazek
    unsigned error = lodepng::decode(image, width, height, filename);

    //Import do pamięci karty graficznej
    glGenTextures(1,&tex); //Zainicjuj jeden uchwyt
    glBindTexture(GL_TEXTURE_2D, tex); //Uaktywnij uchwyt
    //Wczytaj obrazek do pamięci KG skojarzonej z uchwytem
    glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
      GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*) image.data());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return tex;
}

void Texture::delTexture()
{
    glDeleteTextures(1,&texture);
}

GLuint Texture::retTexture()
{
    return texture;
}
