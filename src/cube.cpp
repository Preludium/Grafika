#include "cube.h"

cube::cube(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void cube::drawme(ShaderProgram *sp, GLuint tex0)
{
    // tworzymy klocek w punkcie "0x0x0" i przesuwamy w zaleznosci od wspolrzednych w tablicy

    float fx = float(x), fy = float(y), fz = float(z);
    glm::mat4 M=glm::mat4(1.0f);
    
    std::vector<float> verts;
    std::vector<float> normals;
    std::vector<float> texCoords;
    unsigned int vertexCount = 36;

    // Tylna ściana
    verts.push_back(-5.0f);
    verts.push_back(0.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(2.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(0.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(0.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(2.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(2.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    // Przednia ściana
    verts.push_back(-7.0f);
    verts.push_back(0.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(2.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(0.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(0.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(2.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(2.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    // Dolna ściana
    verts.push_back(-7.0f);
    verts.push_back(0.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(0.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(0.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(0.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(0.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(0.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    // Górna ściana
    verts.push_back(-7.0f);
    verts.push_back(2.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(2.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(2.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(2.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(2.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(2.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    // PRAWA ściana
    verts.push_back(-5.0f);
    verts.push_back(0.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(2.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(0.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(0.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(2.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-5.0f);
    verts.push_back(2.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    // tfu lewa ściana
    verts.push_back(-7.0f);
    verts.push_back(0.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(2.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(0.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(0.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(2.0f);
    verts.push_back(-5.0f);
    verts.push_back(1.0f);

    verts.push_back(-7.0f);
    verts.push_back(2.0f);
    verts.push_back(-7.0f);
    verts.push_back(1.0f);

    // :::NORMALNE:::

    for(int i = 0; i < 6; ++i)
    {
        for(int i = 0; i < 12; ++i) // tylna/przednia
        {
            if(i < 6)
                i = -i;
            normals.push_back(0.0f);
            normals.push_back(0.0f);
            normals.push_back(float(i));
            normals.push_back(0.0f);
        }

        for(int i = 0; i < 12; ++i) // dolna/gorna
        {
            if(i < 6)
                i = -i;
            normals.push_back(0.0f);
            normals.push_back(float(i));
            normals.push_back(0.0f);
            normals.push_back(0.0f);
        }

        for(int i = 0; i < 12; ++i) // prawa/lewa
        {
            if(i > 5)
                i = -i;
            normals.push_back(float(i));
            normals.push_back(0.0f);
            normals.push_back(0.0f);
            normals.push_back(0.0f);
        }
    }

    // :::TEXCOORDS:::

    for(int i = 0; i < 6; ++i)
    {
        texCoords.push_back(1.0f);
        texCoords.push_back(0.0f);
        texCoords.push_back(0.0f);
        texCoords.push_back(1.0f);
        texCoords.push_back(0.0f);
        texCoords.push_back(0.0f);

        texCoords.push_back(1.0f);
        texCoords.push_back(0.0f);
        texCoords.push_back(1.0f);
        texCoords.push_back(1.0f);
        texCoords.push_back(0.0f);
        texCoords.push_back(1.0f);
    }

    M = glm::translate(M, glm::vec3(2 * fx, 2 * fy, 2 * fz));


    sp->use();
    glUniformMatrix4fv(sp->u("M"),1,false,glm::value_ptr(M));   

    glUniform1i(sp->u("textureMap0"),0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,tex0);

    glEnableVertexAttribArray(sp->a("vertex"));  //Włącz przesyłanie danych do atrybutu vertex
    glVertexAttribPointer(sp->a("vertex"),4,GL_FLOAT,false,0,(void*)&verts[0]); //Wskaż tablicę z danymi dla atrybutu vertex

    glEnableVertexAttribArray(sp->a("normal"));  //Włącz przesyłanie danych do atrybutu normal
    glVertexAttribPointer(sp->a("normal"),4,GL_FLOAT,false,0,(void*)&normals[0]); //Wskaż tablicę z danymi dla atrybutu normal

    glEnableVertexAttribArray(sp->a("texCoord0"));  //Włącz przesyłanie danych do atrybutu texCoord0
    glVertexAttribPointer(sp->a("texCoord0"),2,GL_FLOAT,false,0,(void*)&texCoords[0]); //Wskaż tablicę z danymi dla atrybutu texCoord0

    glDrawArrays(GL_TRIANGLES,0,vertexCount); //Narysuj obiekt

    glDisableVertexAttribArray(sp->a("vertex"));  //Wyłącz przesyłanie danych do atrybutu vertex
    glDisableVertexAttribArray(sp->a("normal"));  //Wyłącz przesyłanie danych do atrybutu normal
    glDisableVertexAttribArray(sp->a("texCoord0"));  //Wyłącz przesyłanie danych do atrybutu texCoord0
}
