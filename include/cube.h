#ifndef CUBE_H
#define CUBE_H

// #include <GL/glew.h>
#include <GLFW/glfw3.h>

class cube
{
    public:
        int x, y, z;
        bool exists;
        unsigned int texture;
        cube();
        cube(int x, int y, int z, unsigned int tex);

        cube& operator=(const cube& other)
        {
            this->exists = other.exists;
            this->texture = other.texture;
            return *this;
        }
};

#endif //CUBE_H
