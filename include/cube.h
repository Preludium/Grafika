#ifndef CUBE_H
#define CUBE_H

// #include <GL/glew.h>
#include <GLFW/glfw3.h>

class cube
{
    public:
        int x, y, z;
        bool exists;
        GLuint texture;
        cube();
        cube(int x, int y, int z, GLuint tex);
        void decreaseY();
};

#endif //CUBE_H