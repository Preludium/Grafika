#ifndef CUBE_H
#define CUBE_H

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
class cube
{
    public:
        int x, y, z;

        cube(int x, int y, int z);
        void drawme(ShaderProgram*, GLuint);
};

#endif // CUBE_H
