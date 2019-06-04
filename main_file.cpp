#define GLM_FORCE_RADIANS
#define GLM_FORCE_SWIZZLE

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <vector>
#include "constants.h"
//#include "lodepng.h"
#include "shaderprogram.h"
#include "texture.h"

#include "model.h"
#include "map.h"

#include "modele.h"
#include "single.h"


const int modelSize = 6;

float cam_z=0;
float aspectRatio=1;
float angle_x=0; //Aktualny kąt obrotu obiektu
float angle_y=0;
float angle_z=0; //Aktualny kąt obrotu obiektu

float gd = 0;
float pl = 0;

// modele *model;
// single single;

class cube
{
    public:
        int x, y, z;
        GLuint texture;
        bool exists;
        cube();
        cube(int x, int y, int z, GLuint tex);
        void drawMe();
        void decreaseY();
};

std::vector<cube> mPos;

// ShaderProgram *sp;

// GLuint text[7];

// int map[7][12][7];
cube cubemap[7][12][7];

//Procedura obsługi błędów
void error_callback(int error, const char* description) {
	fputs(description, stderr);
}


void keyCallback(GLFWwindow* window,int key,int scancode,int action,int mods) {
    if (action==GLFW_PRESS) {
        if (key==GLFW_KEY_N) angle_z+=PI/2;
        if (key==GLFW_KEY_M) angle_z+=-PI/2;

        if (key==GLFW_KEY_UP) gd += 2.0f;
        if (key==GLFW_KEY_DOWN) gd += -2.0f;
        if (key==GLFW_KEY_LEFT) pl += 2.0f;
        if (key==GLFW_KEY_RIGHT) pl += -2.0f;

        if (key==GLFW_KEY_Q) cam_z += PI/4;
        if (key==GLFW_KEY_E) cam_z += -PI/4;
    }
}

void windowResizeCallback(GLFWwindow* window,int width,int height) {
    if (height==0) return;
    aspectRatio=(float)width/(float)height;
    glViewport(0,0,width,height);
}

//Funkcja wczytująca teksturę
// GLuint readTexture(const char* filename) {
//     GLuint tex;
//     glActiveTexture(GL_TEXTURE0);

//     //Wczytanie do pamięci komputera
//     std::vector<unsigned char> image;   //Alokuj wektor do wczytania obrazka
//     unsigned width, height;   //Zmienne do których wczytamy wymiary obrazka
//     //Wczytaj obrazek
//     unsigned error = lodepng::decode(image, width, height, filename);

//     //Import do pamięci karty graficznej
//     glGenTextures(1,&tex); //Zainicjuj jeden uchwyt
//     glBindTexture(GL_TEXTURE_2D, tex); //Uaktywnij uchwyt
//     //Wczytaj obrazek do pamięci KG skojarzonej z uchwytem
//     glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
//       GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*) image.data());

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//     return tex;
// }

//Procedura inicjująca
void initOpenGLProgram(GLFWwindow* window) {
	glClearColor(0,0,0,1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSetWindowSizeCallback(window,windowResizeCallback);
	glfwSetKeyCallback(window,keyCallback);

    initShaders();
    initTextures();
	// sp=new ShaderProgram("vertex.glsl",NULL,"fragment.glsl");
    // text[0]=readTexture("block1.png");
    // text[1]=readTexture("block2.png");
    // text[2]=readTexture("block3.png");
    // text[3]=readTexture("block4.png");
    // text[4]=readTexture("block5.png");
    // text[5]=readTexture("block6.png");
    // text[6]=readTexture("block7.png");
}


//Zwolnienie zasobów zajętych przez program
void freeOpenGLProgram(GLFWwindow* window) {
    //************Tutaj umieszczaj kod, który należy wykonać po zakończeniu pętli głównej************
    // glDeleteTextures(1,&text[0]);
    // glDeleteTextures(1,&text[1]);
    // glDeleteTextures(1,&text[2]);
    // glDeleteTextures(1,&text[3]);
    // glDeleteTextures(1,&text[4]);
    // glDeleteTextures(1,&text[5]);
    // glDeleteTextures(1,&text[6]);
    // delete sp;
    freeShaders();
    freeTextures();
}


//Procedura rysująca zawartość sceny
void drawMatrices(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 V=glm::lookAt(
         glm::vec3(0, 55, -20),
         glm::vec3(0,0,0),
         glm::vec3(0.0f,1.0f,0.0f));

    glm::mat4 P=glm::perspective(50.0f*PI/180.0f, aspectRatio, 0.01f, 100.0f);

    glm::mat4 lp=glm::mat4(1.0f);

    lp=glm::translate(lp,glm::vec3(0.0f,55.0f,-20.0f));     //obracac zrodlo swiatla razem z kamera
    lp=glm::rotate(lp,PI/4,glm::vec3(0.0f,1.0f,0.0f));      // jest jeszcze jedno w drawMap

    lp=glm::rotate(lp,cam_z,glm::vec3(0.0f,1.0f,0.0f));

	V=glm::rotate(V,PI/4,glm::vec3(0.0f,1.0f,0.0f)); //kamera
	V=glm::rotate(V,cam_z,glm::vec3(0.0f,1.0f,0.0f)); //kamera

    sp->use();
    glUniformMatrix4fv(sp->u("P"),1,false,glm::value_ptr(P));
    glUniformMatrix4fv(sp->u("V"),1,false,glm::value_ptr(V));
    glUniformMatrix4fv(sp->u("lp"),1,false,glm::value_ptr(lp));
}


void drawMap();
void chooseModel(int);
bool canFall();

int main(void)
{
    srand(time(NULL));
	GLFWwindow* window; //Wskaźnik na obiekt reprezentujący okno

	glfwSetErrorCallback(error_callback);//Zarejestruj procedurę obsługi błędów

	if (!glfwInit()) { //Zainicjuj bibliotekę GLFW
		fprintf(stderr, "Nie można zainicjować GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(1000, 1000, "Tetris", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.

	if (!window) //Jeżeli okna nie udało się utworzyć, to zamknij program
	{
		fprintf(stderr, "Nie można utworzyć okna.\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window); //Od tego momentu kontekst okna staje się aktywny i polecenia OpenGL będą dotyczyć właśnie jego.
	glfwSwapInterval(1); //Czekaj na 1 powrót plamki przed pokazaniem ukrytego bufora

	if (glewInit() != GLEW_OK) { //Zainicjuj bibliotekę GLEW
		fprintf(stderr, "Nie można zainicjować GLEW.\n");
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window); //Operacje inicjujące

    for(int i = 0; i < 12; ++i) //wysokosc
    {
        for (int j = 0; j < 7; ++j) //szerokosc "kolumny"
        {
            for(int k = 0; k < 7; ++k)  //dlugosc "wiersze"
            {
                // map[j][i][k] = 0;
                cubemap[j][i][k].x = j;
                cubemap[j][i][k].y = i;
                cubemap[j][i][k].z = k;
                cubemap[j][i][k].exists = false;
            }
        }
    }

    //próba zabawy z mapą
    /*
    for (int j = 0; j < 7; ++j)
        {
            for(int k = 0; k < 7; ++k)
            {
                cubemap[j][0][k].texture = tex[rand()%7].retTexture();
                cubemap[j][k][0].texture = tex[rand()%7].retTexture();
                cubemap[0][j][k].texture = tex[rand()%7].retTexture();
                cubemap[j][0][k].exists = true;
                cubemap[j][k][0].exists = true;
                cubemap[0][j][k].exists = true;
            }
        }
*/

	//Główna pętla
    bool spada = false;
	glfwSetTime(0); //Zeruj timer
	while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostać zamknięte
	{
        if(!spada){
            chooseModel(1);//rand() % modelSize + 1);
            spada = true;
        }

        if (round(glfwGetTime()*10)/10==1.5){
            if(canFall()){
                glfwSetTime(0);
            }
        }

		drawMatrices(); //Wykonaj procedurę rysującą

        // //DrawBlocks
        /*for(int i = 0; i < 12; ++i) //wysokosc
        {
            for (int j = 0; j < 7; ++j) //szerokosc "kolumny"
            {
                for(int k = 0; k < 7; ++k)  //dlugosc "wiersze"
                {
                    if(cubemap[j][i][k].exists)
                        cubemap[j][i][k].drawMe();
                }
            }
        }
        */
        // DrawModel

        for(int i = 0; i < int(mPos.size()); ++i)
        {
            mPos[i].drawMe();
        }
        drawMap();


		glfwSwapBuffers(window);
		glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.
	}

	freeOpenGLProgram(window);

	glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW
	exit(EXIT_SUCCESS);
}


bool canFall(){
    if(mPos[0].y == 0)
        return false;
    else
    {
        // for(int i = 0; i < int(mPos.size()); ++i)
        //     mPos[i].decreaseY();
        return true;
    }
}


void chooseModel(int chosen)
{
    switch(chosen)
    {
        case 1:     //SingleCube
        //[11][3][3]
        // map[3][11][3] = 1;

        // model = &single;

        mPos.clear();
        mPos.push_back(cube(3,11,3,tex[0].retTexture()));
        break;

        case 2:     //DoubleCube
        //[11][3,4][3]
        // map[3][11][3] = 1;
        // map[4][11][3] = 1;
        mPos.clear();
        mPos.reserve(2);
        mPos.push_back(cube(3,11,3,tex[0].retTexture()));
        mPos.push_back(cube(4,11,3,tex[0].retTexture()));
        break;

        case 3:     //TripleCube
        //[11][2,3,4][3]
        // map[2][11][3] = 1;
        // map[3][11][3] = 1;
        // map[4][11][3] = 1;

        mPos.clear();
        mPos.reserve(3);
        mPos.push_back(cube(2,11,3,tex[0].retTexture()));
        mPos.push_back(cube(3,11,3,tex[0].retTexture()));
        mPos.push_back(cube(4,11,3,tex[0].retTexture()));
        break;

        case 4:     //QuadrupleCube
        //[11][2,3,4,5][3]
        // map[2][11][3] = 1;
        // map[3][11][3] = 1;
        // map[4][11][3] = 1;
        // map[5][11][3] = 1;

        mPos.clear();
        mPos.reserve(4);
        mPos.push_back(cube(2,11,3,tex[0].retTexture()));
        mPos.push_back(cube(3,11,3,tex[0].retTexture()));
        mPos.push_back(cube(4,11,3,tex[0].retTexture()));
        mPos.push_back(cube(5,11,3,tex[0].retTexture()));
        break;

        case 5:     //TriangleCube
        //[11][3][2,3], [11][2][3], [11][4][3]
        // map[3][11][2] = 1;
        // map[3][11][3] = 1;
        // map[2][11][3] = 1;
        // map[4][11][3] = 1;

        mPos.clear();
        mPos.reserve(4);
        mPos.push_back(cube(3,11,2,tex[0].retTexture()));
        mPos.push_back(cube(3,11,3,tex[0].retTexture()));
        mPos.push_back(cube(2,11,3,tex[0].retTexture()));
        mPos.push_back(cube(4,11,3,tex[0].retTexture()));
        break;

        case 6:     //StrangeCube
        //[11][2,3,4][3], [11][2][2]
        // map[2][11][3] = 1;
        // map[3][11][3] = 1;
        // map[4][11][3] = 1;
        // map[2][11][2] = 1;

        mPos.clear();
        mPos.reserve(4);
        mPos.push_back(cube(2,11,3,tex[0].retTexture()));
        mPos.push_back(cube(3,11,3,tex[0].retTexture()));
        mPos.push_back(cube(4,11,3,tex[0].retTexture()));
        mPos.push_back(cube(2,11,2,tex[0].retTexture()));
        break;
    }
}


cube::cube(int x, int y, int z,  GLuint tex)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->texture = tex;
}

cube::cube()
{

}

void cube::decreaseY()
{
    this->y = this->y - 1;
}

// tworzymy klocek w punkcie "0x0x0" i przesuwamy w zaleznosci od wspolrzednych w tablicy
void cube::drawMe()
{

    float fx = float(x), fy = float(y), fz = float(z);
    glm::mat4 M=glm::mat4(1.0f);

    float *verts = modelVerts;
    float *texCoords = modelCubeTexCoords;
    float *normals = modelCubeNormals;
    unsigned int vertexCount = modelVertexCount;


    M = glm::translate(M, glm::vec3(2 * fx, 2 * fy, 2 * fz));


    sp->use();
    glUniformMatrix4fv(sp->u("M"),1,false,glm::value_ptr(M));

    glUniform1i(sp->u("textureMap0"),0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,texture);

    glEnableVertexAttribArray(sp->a("vertex"));  //Włącz przesyłanie danych do atrybutu vertex
    glVertexAttribPointer(sp->a("vertex"),4,GL_FLOAT,false,0,verts); //Wskaż tablicę z danymi dla atrybutu vertex

    glEnableVertexAttribArray(sp->a("normal"));  //Włącz przesyłanie danych do atrybutu normal
    glVertexAttribPointer(sp->a("normal"),4,GL_FLOAT,false,0,normals); //Wskaż tablicę z danymi dla atrybutu normal

    glEnableVertexAttribArray(sp->a("texCoord0"));  //Włącz przesyłanie danych do atrybutu texCoord0
    glVertexAttribPointer(sp->a("texCoord0"),2,GL_FLOAT,false,0,texCoords); //Wskaż tablicę z danymi dla atrybutu texCoord0

    glDrawArrays(GL_TRIANGLES,0,vertexCount); //Narysuj obiekt

    glDisableVertexAttribArray(sp->a("vertex"));  //Wyłącz przesyłanie danych do atrybutu vertex
    glDisableVertexAttribArray(sp->a("normal"));  //Wyłącz przesyłanie danych do atrybutu normal
    glDisableVertexAttribArray(sp->a("texCoord0"));  //Wyłącz przesyłanie danych do atrybutu texCoord0
}



void drawMap(){
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

    glm::mat4 M=glm::mat4(1.0f);

    float *verts = map_verts;
    float *normals = map_normals;
    float *colors = map_colors;
    unsigned int vertexCount = map_vertsCount;

    glm::mat4 lp=glm::mat4(1.0f);
    lp=glm::translate(lp,glm::vec3(0.0f,20.0f,-20.0f));
    lp=glm::rotate(lp,PI/4,glm::vec3(0.0f,1.0f,0.0f));
    lp=glm::rotate(lp,cam_z,glm::vec3(0.0f,1.0f,0.0f));

    sp->use();
    glUniformMatrix4fv(sp->u("M"),1,false,glm::value_ptr(M));
    glUniformMatrix4fv(sp->u("lp"),1,false,glm::value_ptr(lp));

    glEnableVertexAttribArray(sp->a("vertex"));  //Włącz przesyłanie danych do atrybutu vertex
    glVertexAttribPointer(sp->a("vertex"),4,GL_FLOAT,false,0,verts); //Wskaż tablicę z danymi dla atrybutu vertex

    glEnableVertexAttribArray(sp->a("normal"));  //Włącz przesyłanie danych do atrybutu normal
    glVertexAttribPointer(sp->a("normal"),4,GL_FLOAT,false,0,normals); //Wskaż tablicę z danymi dla atrybutu normal

    glEnableVertexAttribArray(sp->a("color"));  //Włącz przesyłanie danych do atrybutu color
    glVertexAttribPointer(sp->a("color"),4,GL_FLOAT,false,0,colors);

    glDrawArrays(GL_QUADS,0,vertexCount); //Narysuj obiekt

    glDisableVertexAttribArray(sp->a("vertex"));  //Wyłącz przesyłanie danych do atrybutu vertex
    glDisableVertexAttribArray(sp->a("normal"));  //Wyłącz przesyłanie danych do atrybutu normal
    glDisableVertexAttribArray(sp->a("color"));  //Wyłącz przesyłanie danych do atrybutu normal

    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

}
