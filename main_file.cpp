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
#include "constants.h"
#include "lodepng.h"
#include "shaderprogram.h"

#include "Triangle_Cube.h"
#include "Single_Cube.h"
#include "Double_Cube.h"
#include "Triple_Cube.h"
#include "Quadruple_Cube.h"
#include "Strange_Cube.h"

const int modelSize = 6;

float speed_x=0;
float speed_y=0;
float cam_z=0;
float aspectRatio=1;
float angle_x=0; //Aktualny kąt obrotu obiektu
float angle_y=0;
float angle_z=0; //Aktualny kąt obrotu obiektu

float gd = 0;
float pl = 0;

ShaderProgram *sp;

//Uchwyty na tekstury
GLuint tex0;
GLuint tex1;
GLuint tex2;
GLuint tex3;

int map[12][8][8];


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

        if (key==GLFW_KEY_Q) cam_z += -PI/2;
        if (key==GLFW_KEY_E) cam_z += PI/2;
    }

    if (action==GLFW_RELEASE) {
        if (key==GLFW_KEY_Q) cam_z=0;
        if (key==GLFW_KEY_E) cam_z=0;
    }
}

void windowResizeCallback(GLFWwindow* window,int width,int height) {
    if (height==0) return;
    aspectRatio=(float)width/(float)height;
    glViewport(0,0,width,height);
}



//Funkcja wczytująca teksturę
GLuint readTexture(const char* filename) {
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

//Procedura inicjująca
void initOpenGLProgram(GLFWwindow* window) {
	glClearColor(0,0,0,1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSetWindowSizeCallback(window,windowResizeCallback);
	glfwSetKeyCallback(window,keyCallback);

	sp=new ShaderProgram("vertex.glsl",NULL,"fragment.glsl");

    tex0=readTexture("block.png");
    tex1=readTexture("sky.png");
    tex2=readTexture("mapa.png");
    tex3=readTexture("mapa.png");
}


//Zwolnienie zasobów zajętych przez program
void freeOpenGLProgram(GLFWwindow* window) {
    //************Tutaj umieszczaj kod, który należy wykonać po zakończeniu pętli głównej************
    glDeleteTextures(1,&tex0);
    glDeleteTextures(1,&tex1);
    glDeleteTextures(1,&tex2);
    glDeleteTextures(1,&tex3);

    delete sp;
}


//Procedura rysująca zawartość sceny
void drawScene(GLFWwindow* window,float angle_x,float angle_y, float velo, float cam_angle_z, float falling) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 V=glm::lookAt(
         glm::vec3(0, 45, -20),
         glm::vec3(0,0,0),
         glm::vec3(0.0f,1.0f,0.0f));

    glm::mat4 P=glm::perspective(50.0f*PI/180.0f, aspectRatio, 0.01f, 100.0f);
    glm::mat4 M=glm::mat4(1.0f);


	M=glm::translate(M,glm::vec3(0.0f,falling,0.0f)); //opadanie
    M=glm::translate(M,glm::vec3(pl,gd,velo)); //przemieszczenie            -- swiruje dla strzalek gora dol
    M=glm::rotate(M,PI/2,glm::vec3(1.0f, 0.0f,0.0f));

    M=glm::translate(M,glm::vec3(1.0f,1.0f,-23.0f)); // na X i Y tylko dla niektorych klockow
    //M=glm::translate(M,glm::vec3(0.0f,1.0f,-23.0f));

	M=glm::rotate(M,angle_y,glm::vec3(1.0f,0.0f,0.0f));
	M=glm::rotate(M,angle_x,glm::vec3(0.0f,1.0f,0.0f));
	M=glm::rotate(M,angle_z,glm::vec3(0.0f,0.0f,1.0f));


	V=glm::rotate(V,cam_angle_z,glm::vec3(0.0f,1.0f,0.0f)); //kamera


	float *verts=strangeCubeVertices;
	float *normals=strangeCubeNormals;
	float *texCoords=strangeCubeTexCoords;
	unsigned int vertexCount=strangeCubeVertexCount;



    sp->use();
    glUniformMatrix4fv(sp->u("P"),1,false,glm::value_ptr(P));
    glUniformMatrix4fv(sp->u("V"),1,false,glm::value_ptr(V));
    glUniformMatrix4fv(sp->u("M"),1,false,glm::value_ptr(M));
    glUniform4f(sp->u("lp"),0,40,-15,1); //Współrzędne źródła światła

    glUniform1i(sp->u("textureMap0"),0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,tex0);

    glUniform1i(sp->u("textureMap1"),1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D,tex1);


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
    glm::mat4 M=glm::mat4(1.0f);

	std::vector<float> verts;
	for(int i=-8; i<7; i+=2)//wiersze
    {
        for(int j=-8; j<7; j+=2)//kolumny
        {
            verts.push_back(float(i));
            verts.push_back(0.0f);
            verts.push_back(float(j+2));
            verts.push_back(1.0f);

            verts.push_back(float(i+2));
            verts.push_back(0.0f);
            verts.push_back(float(j));
            verts.push_back(1.0f);

            verts.push_back(float(i+2));
            verts.push_back(0.0f);
            verts.push_back(float(j+2));
            verts.push_back(1.0f);

            verts.push_back(float(i));
            verts.push_back(0.0f);
            verts.push_back(float(j+2));
            verts.push_back(1.0f);

            verts.push_back(float(i+2));
            verts.push_back(0.0f);
            verts.push_back(float(j));
            verts.push_back(1.0f);

            verts.push_back(float(i));
            verts.push_back(0.0f);
            verts.push_back(float(j));
            verts.push_back(1.0f);
        }
    }
	/*
        -8.0f,0.0f,8.0f,1.0f,
		8.0f,0.0f,8.0f,1.0f,
		8.0f,0.0f,-8.0f,1.0f,

		-8.0f,0.0f,8.0f,1.0f,
		-8.0f,0.0f,-8.0f,1.0f,
		8.0f,0.0f,-8.0f,1.0f,
		};
*/
    //std::vector<float> colors[]=

    /*{
        0.0f,0.0f,0.0f,1.0f,
        0.0f,0.0f,0.0f,1.0f,
		0.0f,0.0f,0.0f,1.0f,

		0.0f,0.0f,0.0f,1.0f,
		0.0f,0.0f,0.0f,1.0f,
		0.0f,0.0f,0.0f,1.0f,
		};*/

    std::vector<float> texCoords;//[]=
    for(int i=0; i<64; i++)
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
    /*{
        1.0f, 0.0f,   //A
        0.0f, 1.0f,    //B
        0.0f, 0.0f,    //C

        1.0f, 0.0f,    //A
        1.0f, 1.0f,    //D
        0.0f, 1.0f,    //B
    };*/

    std::vector<float> normals;
        for(int i=0;i<64*6;i++)
        {
            normals.push_back(0.0f);
            normals.push_back(1.0f);
            normals.push_back(0.0f);
            normals.push_back(0.0f);
        }
        /*{
        0.0f,1.0f, 0.0f,0.0f,
		0.0f,1.0f, 0.0f,0.0f,
		0.0f,1.0f, 0.0f,0.0f,

		0.0f,1.0f, 0.0f,0.0f,
		0.0f,1.0f, 0.0f,0.0f,
		0.0f,1.0f, 0.0f,0.0f,
        };*/

    unsigned int vertexCount = 6*64;

    sp->use();
    glUniformMatrix4fv(sp->u("M"),1,false,glm::value_ptr(M));

    glUniform1i(sp->u("textureMap1"),1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D,tex2);

    glUniform1i(sp->u("textureMap0"),0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,tex3);


    glEnableVertexAttribArray(sp->a("vertex"));  //Włącz przesyłanie danych do atrybutu vertex
    glVertexAttribPointer(sp->a("vertex"),4,GL_FLOAT,false,0,(void*)&verts[0]); //Wskaż tablicę z danymi dla atrybutu vertex

    glEnableVertexAttribArray(sp->a("normal"));  //Włącz przesyłanie danych do atrybutu normal
    glVertexAttribPointer(sp->a("normal"),4,GL_FLOAT,false,0,(void*)&normals[0]); //Wskaż tablicę z danymi dla atrybutu normal

    //glEnableVertexAttribArray(sp->a("color"));  //Włącz przesyłanie danych do atrybutu color
    //glVertexAttribPointer(sp->a("color"),4,GL_FLOAT,false,0,colors);

    glEnableVertexAttribArray(sp->a("texCoord0"));  //Włącz przesyłanie danych do atrybutu texCoord0
    glVertexAttribPointer(sp->a("texCoord0"),2,GL_FLOAT,false,0,(void*)&texCoords[0]); //Wskaż tablicę z danymi dla atrybutu texCoord0

    glDrawArrays(GL_TRIANGLES,0,vertexCount); //Narysuj obiekt

    glDisableVertexAttribArray(sp->a("vertex"));  //Wyłącz przesyłanie danych do atrybutu vertex
    glDisableVertexAttribArray(sp->a("normal"));  //Wyłącz przesyłanie danych do atrybutu normal
    //glDisableVertexAttribArray(sp->a("color"));  //Wyłącz przesyłanie danych do atrybutu normal
    glDisableVertexAttribArray(sp->a("texCoord0"));  //Wyłącz przesyłanie danych do atrybutu texCoord0
}

void chooseModel(int);

int main(void)
{
    srand(time(NULL));
	GLFWwindow* window; //Wskaźnik na obiekt reprezentujący okno

	glfwSetErrorCallback(error_callback);//Zarejestruj procedurę obsługi błędów

	if (!glfwInit()) { //Zainicjuj bibliotekę GLFW
		fprintf(stderr, "Nie można zainicjować GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(500, 500, "OpenGL", NULL, NULL);  //Utwórz okno 500x500 o tytule "OpenGL" i kontekst OpenGL.

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
        for (int j = 0; j < 8; ++j) //szerokosc "kolumny"
        {
            for(int k = 0; k < 8; ++k)  //dlugosc "wiersze"
            {
                map[i][j][k] = 0;
            }
        }
    }

    //trzeba machnac jakiegos switcha w petli ktory bedzie losowal figury i kazda figure trzeba na inny sposob wpisac do tablicy "map"

	//Główna pętla
	float velo=0;
	float cam_angle_z=0;
	float falling=0;
	glfwSetTime(0); //Zeruj timer
	while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostać zamknięte
	{
       // angle_x+=speed_x; //Zwiększ/zmniejsz kąt obrotu na podstawie prędkości i czasu jaki upłynał od poprzedniej klatki
        //angle_y+=speed_y*glfwGetTime(); //Zwiększ/zmniejsz kąt obrotu na podstawie prędkości i czasu jaki upłynał od poprzedniej klatki
        velo+=speed_y*glfwGetTime();
        cam_angle_z=cam_z;//*glfwGetTime();
        //chooseModel(rand()%modelSize+1);
        if (round(glfwGetTime()*10)/10==1.5 and falling > -22)
        {
            falling+=-2;
            glfwSetTime(0);
        }
		drawScene(window,angle_x,angle_y,velo,cam_angle_z,falling); //Wykonaj procedurę rysującą
        drawMap();
		glfwSwapBuffers(window);
		glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.
	}

	freeOpenGLProgram(window);

	glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW
	exit(EXIT_SUCCESS);
}


void chooseModel(int chosen) //mozna tu podac wszystkie tabele i ilosc wierzcholkow modelu po referencji i przypisac w switchu
{
    switch(chosen)
    {
        case 1:     //SingleCube - wymaga przesuniecia X na poczatku
        //[11][3][3]
        map[11][3][3] = 1;
        break;

        case 2:     //DoubleCube - rotacja "N-M" musi byc wedlug innego punktu niz srodka
        //[11][3,4][3]
        map[11][3][3] = 1;
        map[11][4][3] = 1;

        break;

        case 3:     //TripleCube - wymaga przesuniecia X na poczatku
        //[11][2,3,4][3]
        map[11][2][3] = 1;
        map[11][3][3] = 1;
        map[11][4][3] = 1;
        break;

        case 4:     //QuadrupleCube - rotacja "N-M" musi byc wedlug innego punktu niz srodka
        //[11][2,3,4,5][3]
        map[11][2][3] = 1;
        map[11][3][3] = 1;
        map[11][4][3] = 1;
        map[11][5][3] = 1;
        break;

        case 5:     //TriangleCube - wymaga przesunieci X na poczatku
        //[11][3][2,3], [11][2][3], [11][4][3]
        map[11][3][2] = 1;
        map[11][3][3] = 1;
        map[11][2][3] = 1;
        map[11][4][3] = 1;
        break;

        case 6:     //StrangeCube - wymaga przesunieci X na poczatku
        //[11][2,3,4][3], [11][2][2]
        map[11][2][3] = 1;
        map[11][3][3] = 1;
        map[11][4][3] = 1;
        map[11][2][2] = 1;
        break;
    }
}
