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
#include "lodepng.h"
#include "shaderprogram.h"
#include <algorithm>    // std::sort

#include "model.h"
#include "map.h"

#include "scoreboard.h"
#include "cube.h"
#include "modele.h"
#include "single.h"
#include "bigcube.h"
#include "one.h"
#include "two.h"
#include "three.h"
#include "four.h"
#include "five.h"
#include "six.h"
#include "seven.h"
#include "test.h"


float cam_z=0;
float aspectRatio=1;

bool endGameMode = false;
bool newGame = false;
Model *model;
ShaderProgram *sp;
std::vector<cube> mPos;
GLuint text[7];
cube cubemap[9][15][9];

std::vector<ScoreBoard> topScores;

void drawMap();
void drawMatrices();
void drawCube(cube);
void chooseModel(int);
bool endGame();
void checkSurfaces();
void deleteSurface(int);
void startNewGame();
void updateConsole();
void showTopScores();


//Procedura obsługi błędów
void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}


void keyCallback(GLFWwindow* window,int key,int scancode,int action,int mods)
{
    if (action==GLFW_PRESS) {
        if (key==GLFW_KEY_N && !endGameMode) model->RotL(cubemap);//angle_z+=PI/2;
        if (key==GLFW_KEY_M && !endGameMode) model->RotR(cubemap);//angle_z+=-PI/2;

        if (key==GLFW_KEY_SPACE && !endGameMode) model->toBottom(cubemap);
        if (key==GLFW_KEY_LEFT_CONTROL && !endGameMode) model->falling(cubemap);
        if (key==GLFW_KEY_ESCAPE) startNewGame();

        if (key==GLFW_KEY_UP && !endGameMode) model->MovUD(1, cubemap);//gd += 2.0f;
        if (key==GLFW_KEY_DOWN && !endGameMode) model->MovUD(-1, cubemap);//gd += -2.0f;
        if (key==GLFW_KEY_LEFT && !endGameMode) model->MovLR(1, cubemap);//pl += 2.0f;
        if (key==GLFW_KEY_RIGHT && !endGameMode) model->MovLR(-1, cubemap);//pl += -2.0f;

        if (key==GLFW_KEY_Q) cam_z += PI/4;
        if (key==GLFW_KEY_E) cam_z += -PI/4;
    }
}

void windowResizeCallback(GLFWwindow* window,int width,int height)
{
    if (height==0) return;
    aspectRatio=(float)width/(float)height;
    glViewport(0,0,width,height);
}

//Funkcja wczytująca teksturę
GLuint readTexture(const char* filename)
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

//Procedura inicjująca
void initOpenGLProgram(GLFWwindow* window)
{
	glClearColor(0,0,0,1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSetWindowSizeCallback(window,windowResizeCallback);
	glfwSetKeyCallback(window,keyCallback);

	sp=new ShaderProgram("vertex.glsl",NULL,"fragment.glsl");
    text[0]=readTexture("block1.png");
    text[1]=readTexture("block2.png");
    text[2]=readTexture("block3.png");
    text[3]=readTexture("block4.png");
    text[4]=readTexture("block5.png");
    text[5]=readTexture("block6.png");
    text[6]=readTexture("block7.png");
}


//Zwolnienie zasobów zajętych przez program
void freeOpenGLProgram(GLFWwindow* window) {
    //************Tutaj umieszczaj kod, który należy wykonać po zakończeniu pętli głównej************
    glDeleteTextures(1,&text[0]);
    glDeleteTextures(1,&text[1]);
    glDeleteTextures(1,&text[2]);
    glDeleteTextures(1,&text[3]);
    glDeleteTextures(1,&text[4]);
    glDeleteTextures(1,&text[5]);
    glDeleteTextures(1,&text[6]);
    delete sp;
}


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

    topScores.push_back(ScoreBoard());
    startNewGame();
    newGame = false;


	//Główna pętla
    chooseModel(8);
	glfwSetTime(0); //Zeruj timer
	while (!glfwWindowShouldClose(window)) //Tak długo jak okno nie powinno zostaĠ Ǡzamknięte
	{

        if (round(glfwGetTime()*10)/10==1.5)
        {
            if(model->falling(cubemap))
            {
                glfwSetTime(0);
            }
            else
            {
                // zaktualizuj wynik
                int points = model->getPoints();
                topScores.back().updateScore(points);
                updateConsole();


                for (int i = 0; i < model->parts.size(); ++i)
                {
                    cubemap[model->parts[i].x][model->parts[i].y][model->parts[i].z].exists = true;
                    cubemap[model->parts[i].x][model->parts[i].y][model->parts[i].z].texture = model->mytex;
                }

                delete model;


                if (endGame())
                {
                    std::cout << "Game Over" << std::endl;
                    endGameMode = true;
                    // wyswietl wszystki wyniki
                    topScores.back().updateName();
                    showTopScores();


                    newGame = false;
                    while(!newGame)
                    {
                        drawMatrices(); //Wykonaj procedurę rysującą
                        drawMap();
                        for(int i = 0; i < 15; ++i) //wysokosc
                        {
                            for (int j = 1; j < 8; ++j) //szerokosc "kolumny"
                            {
                                for(int k = 1; k < 8; ++k)  //dlugosc "wiersze"
                                {
                                    if(cubemap[j][i][k].exists)
                                        drawCube(cubemap[j][i][k]);
                                }
                            }
                        }
                        glfwSwapBuffers(window);
		                glfwPollEvents();
                    }
                    topScores.push_back(ScoreBoard());
                    newGame = false;
                    endGameMode = false;
                    glfwSetTime(0);
                    continue;
                }
                else
                {
                    checkSurfaces();
                    chooseModel(8);
                    glfwSetTime(0);
                }
            }

        }

		drawMatrices(); //Wykonaj procedurę rysującą
        drawMap();

        //DrawBlocks
        for(int i = 0; i < 15; ++i) //wysokosc
        {
            for (int j = 1; j < 8; ++j) //szerokosc "kolumny"
            {
                for(int k = 1; k < 8; ++k)  //dlugosc "wiersze"
                {
                    if(cubemap[j][i][k].exists)
                        drawCube(cubemap[j][i][k]);
                }
            }
        }

        for (int i = 0; i < model->parts.size(); ++i)
        {
           drawCube(model->parts[i]);
        }

		glfwSwapBuffers(window);
		glfwPollEvents(); //Wykonaj procedury callback w zalezności od zdarzeń jakie zaszły.
	}
    delete model;
	freeOpenGLProgram(window);

	glfwDestroyWindow(window); //Usuń kontekst OpenGL i okno
	glfwTerminate(); //Zwolnij zasoby zajęte przez GLFW
	exit(EXIT_SUCCESS);
}


void showTopScores()
{
    std::cout << std::endl << ":::  Top 10 Scores  :::" << std::endl;
    std::sort(topScores.rbegin(), topScores.rend());
    if (topScores.size() > 10)
        topScores.pop_back();

    for (int i = 0; i < 10; ++i)
    {
        std::cout << i + 1 << ". ";
        if (topScores.size() >= i + 1)
        {
            topScores[i].showScoreBoard();
        }
        else
        {
            std::cout << std::endl;
        }
    }

    std::cout << "Press ESC to start new game" << std::endl;
}


void updateConsole()
{
    // wyczysc konsole
    system("cls");

    std::cout << "New game" << std::endl;
    std::cout << "Current score: ";
    topScores.back().showScore();
}


bool endGame()
{
    for (int i = 1; i < 8; ++i)
    {
        for (int j = 1; j < 8; ++j)
        {
            if (cubemap[i][11][j].exists)
                return true;
        }
    }
    return false;
}


void startNewGame()
{
    for(int i = 0; i < 15; ++i) //wysokosc
    {
        for (int j = 0; j < 9; ++j) //szerokosc "kolumny"
        {
            for(int k = 0; k < 9; ++k)  //dlugosc "wiersze"
            {
                cubemap[j][i][k].x = j;
                cubemap[j][i][k].y = i;
                cubemap[j][i][k].z = k;
                if (j == 0 || j == 8)
                {
                    if (k == 0 || k == 8)
                        cubemap[j][i][k].exists = true;
                    else
                        cubemap[j][i][k].exists = false;
                }
                else
                    cubemap[j][i][k].exists = false;
            }
        }
    }

    // topScores.push_back(ScoreBoard());
    topScores.back().clearScore();
    updateConsole();

    newGame = true;
    chooseModel(rand() % 9);
}

void deleteSurface(int i)
{
    for (; i < 15; ++i)
    {
        for (int j = 1; j < 8; ++j)
        {
            for (int k = 1; k < 8; ++k)
            {
                if (i == 14)
                {
                    cubemap[j][i][k].exists == false;
                }
                else
                {
                    cubemap[j][i][k].exists = cubemap[j][i + 1][k].exists;
                    cubemap[j][i][k].texture = cubemap[j][i + 1][k].texture;
                }
            }
        }
    }
}

void checkSurfaces()
{
    // jesli cala powierzchnia pusta to nie ma co sprawdzac dalej
    //w sumie wystarczy znalezc jeden pusty i mozna leciec dalej
    bool toClear;

    for (int i = 11; i >= 0; --i)
    {
        toClear = true;

        for (int j = 1; j < 8; ++j)
        {
            if (!toClear)
                break;

            for (int k = 1; k < 8; ++k)
            {
                if (cubemap[j][i][k].exists == false)
                {
                    toClear = false;
                    break;
                }
            }
        }

        if (toClear)
        {
            deleteSurface(i);
            topScores.back().updateScore(100);
            updateConsole();
        }
    }
}


void chooseModel(int chosen)
{
    // std::cout << chosen << std::endl;
    switch(chosen)
    {
        case 0:
        model = new Single;
        break;

        case 1:
        model = new bigcube;
        break;

        case 2:
        model = new one;
        break;

        case 3:
        model = new two;
        break;

        case 4:
        model = new three;
        break;

        case 5:
        model = new four;
        break;

        case 6:
        model = new five;
        break;

        case 7:
        model = new six;
        break;

        case 8:
        model = new seven;
        break;

        default:
        model = new test;
        break;

    }


    model->mytex = rand()%7;
    model->state = 0;
    for (int i = 0; i < model->parts.size(); ++i)
    {
       model->parts[i].texture = model->mytex;
    }
}


// tworzymy klocek w punkcie "0x0x0" i przesuwamy w zaleznosci od wspolrzednych w tablicy
void drawCube(cube klocek)
{

    float fx = float(klocek.x), fy = float(klocek.y), fz = float(klocek.z);
    glm::mat4 M=glm::mat4(1.0f);

    float *verts = modelVerts;
    float *texCoords = modelCubeTexCoords;
    float *normals = modelCubeNormals;
    unsigned int vertexCount = modelVertexCount;


    M = glm::translate(M, glm::vec3(2 * fx - 2, 2 * fy, 2 * fz - 2));


    sp->use();
    glUniformMatrix4fv(sp->u("M"),1,false,glm::value_ptr(M));

    glUniform1i(sp->u("textureMap0"),0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, text[klocek.texture]);

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


//Procedura rysująca zawartość sceny
void drawMatrices()
{
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

	// V=glm::rotate(V,PI/4,glm::vec3(0.0f,1.0f,0.0f)); //kamera
	V=glm::rotate(V,cam_z,glm::vec3(0.0f,1.0f,0.0f)); //kamera

    sp->use();
    glUniformMatrix4fv(sp->u("P"),1,false,glm::value_ptr(P));
    glUniformMatrix4fv(sp->u("V"),1,false,glm::value_ptr(V));
    glUniformMatrix4fv(sp->u("lp"),1,false,glm::value_ptr(lp));
}
