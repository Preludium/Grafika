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
<<<<<<< HEAD

        cube& operator=(const cube& other)
        {
            this->exists = other.exists;
            this->texture = other.texture;
            return *this;
        }
=======
        cube(int x, int y, int z);
>>>>>>> a09749a4703c92a567f741e2ec5c27a0bf96e587
};

#endif //CUBE_H
