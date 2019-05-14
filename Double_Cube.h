#ifndef DOUBLE_CUBE_H_INCLUDED
#define DOUBLE_CUBE_H_INCLUDED


//myCubeVertices - homogeniczne współrzędne wierzchołków w przestrzeni modelu
//myCubeNormals - homogeniczne wektory normalne ścian (per wierzchołek) w przestrzeni modelu
//myCubeVertexNormals - homogeniczne wektory normalne wierzchołków w przestrzeni modelu
//myCubeTexCoords - współrzędne teksturowania
//myCubeColors - kolory wierzchołków
//myCubeC1 - kolumna macierzy TBN^-1
//myCubeC2 - kolumna macierzy TBN^-1
//myCubeC3 - kolumna macierzy TBN^-1

int doubleCubeVertexCount= 60;

float doubleCubeVertices[]={
                //prawy kwadrat

                //Ściana 1 (tylna)
				2.0f,-1.0f,-1.0f,1.0f,
				0.0f, 1.0f,-1.0f,1.0f,
				0.0f,-1.0f,-1.0f,1.0f,

				2.0f,-1.0f,-1.0f,1.0f,
				2.0f, 1.0f,-1.0f,1.0f,
				0.0f, 1.0f,-1.0f,1.0f,

                //Ściana 2 (przednia)
				0.0f,-1.0f, 1.0f,1.0f,
				2.0f, 1.0f, 1.0f,1.0f,
				2.0f,-1.0f, 1.0f,1.0f,

				0.0f,-1.0f, 1.0f,1.0f,
				0.0f, 1.0f, 1.0f,1.0f,
				2.0f, 1.0f, 1.0f,1.0f,


				//Ściana 3 (dolna)
				0.0f,-1.0f,-1.0f,1.0f,
				2.0f,-1.0f, 1.0f,1.0f,
				2.0f,-1.0f,-1.0f,1.0f,

				0.0f,-1.0f,-1.0f,1.0f,
				0.0f,-1.0f, 1.0f,1.0f,
				2.0f,-1.0f, 1.0f,1.0f,

				//Ściana 4 (górna)
				0.0f, 1.0f, 1.0f,1.0f,
				2.0f, 1.0f,-1.0f,1.0f,
				2.0f, 1.0f, 1.0f,1.0f,

				0.0f, 1.0f, 1.0f,1.0f,
				0.0f, 1.0f,-1.0f,1.0f,
				2.0f, 1.0f,-1.0f,1.0f,

                //Ściana 5 (boczna prawa)
				2.0f,-1.0f, 1.0f,1.0f,
				2.0f, 1.0f,-1.0f,1.0f,
				2.0f,-1.0f,-1.0f,1.0f,

				2.0f,-1.0f, 1.0f,1.0f,
				2.0f, 1.0f, 1.0f,1.0f,
				2.0f, 1.0f,-1.0f,1.0f,

				//kwadrat lewy
				//Ściana 1 (tylna)
				0.0f,-1.0f,-1.0f,1.0f,
				-2.0f, 1.0f,-1.0f,1.0f,
				-2.0f,-1.0f,-1.0f,1.0f,

				0.0f,-1.0f,-1.0f,1.0f,
				0.0f, 1.0f,-1.0f,1.0f,
				-2.0f, 1.0f,-1.0f,1.0f,

                //Ściana 2 (przednia)
				-2.0f,-1.0f, 1.0f,1.0f,
				0.0f, 1.0f, 1.0f,1.0f,
				0.0f,-1.0f, 1.0f,1.0f,

				-2.0f,-1.0f, 1.0f,1.0f,
				-2.0f, 1.0f, 1.0f,1.0f,
				0.0f, 1.0f, 1.0f,1.0f,


				//Ściana 3 (dolna)
				-2.0f,-1.0f,-1.0f,1.0f,
				0.0f,-1.0f, 1.0f,1.0f,
				0.0f,-1.0f,-1.0f,1.0f,

				-2.0f,-1.0f,-1.0f,1.0f,
				-2.0f,-1.0f, 1.0f,1.0f,
				0.0f,-1.0f, 1.0f,1.0f,

				//Ściana 4 (górna)
				-2.0f, 1.0f, 1.0f,1.0f,
				0.0f, 1.0f,-1.0f,1.0f,
				0.0f, 1.0f, 1.0f,1.0f,

				-2.0f, 1.0f, 1.0f,1.0f,
				-2.0f, 1.0f,-1.0f,1.0f,
				0.0f, 1.0f,-1.0f,1.0f,

				//Ściana 5 (boczna lewa)
				-2.0f,-1.0f,-1.0f,1.0f,
				-2.0f, 1.0f, 1.0f,1.0f,
				-2.0f,-1.0f, 1.0f,1.0f,

				-2.0f,-1.0f,-1.0f,1.0f,
				-2.0f, 1.0f,-1.0f,1.0f,
				-2.0f, 1.0f, 1.0f,1.0f,
			};


float doubleCubeColors[]={
				//bloczek prawy
                //Ściana 1
				1.0f,0.0f,0.0f,1.0f,
				1.0f,0.0f,0.0f,1.0f,
				1.0f,0.0f,0.0f,1.0f,

				1.0f,0.0f,0.0f,1.0f,
				1.0f,0.0f,0.0f,1.0f,
				1.0f,0.0f,0.0f,1.0f,

				//Ściana 2
				0.0f,1.0f,0.0f,1.0f,
				0.0f,1.0f,0.0f,1.0f,
				0.0f,1.0f,0.0f,1.0f,

				0.0f,1.0f,0.0f,1.0f,
				0.0f,1.0f,0.0f,1.0f,
				0.0f,1.0f,0.0f,1.0f,

				//Ściana 3
				0.0f,0.0f,1.0f,1.0f,
				0.0f,0.0f,1.0f,1.0f,
				0.0f,0.0f,1.0f,1.0f,

				0.0f,0.0f,1.0f,1.0f,
				0.0f,0.0f,1.0f,1.0f,
				0.0f,0.0f,1.0f,1.0f,

				//Ściana 4
				1.0f,1.0f,0.0f,1.0f,
				1.0f,1.0f,0.0f,1.0f,
				1.0f,1.0f,0.0f,1.0f,

				1.0f,1.0f,0.0f,1.0f,
				1.0f,1.0f,0.0f,1.0f,
				1.0f,1.0f,0.0f,1.0f,

				//Ściana 5
				0.0f,1.0f,1.0f,1.0f,
				0.0f,1.0f,1.0f,1.0f,
				0.0f,1.0f,1.0f,1.0f,

				0.0f,1.0f,1.0f,1.0f,
				0.0f,1.0f,1.0f,1.0f,
				0.0f,1.0f,1.0f,1.0f,

				//bloczek lewy
				//Ściana 1
				1.0f,0.0f,0.0f,1.0f,
				1.0f,0.0f,0.0f,1.0f,
				1.0f,0.0f,0.0f,1.0f,

				1.0f,0.0f,0.0f,1.0f,
				1.0f,0.0f,0.0f,1.0f,
				1.0f,0.0f,0.0f,1.0f,

				//Ściana 2
				0.0f,1.0f,0.0f,1.0f,
				0.0f,1.0f,0.0f,1.0f,
				0.0f,1.0f,0.0f,1.0f,

				0.0f,1.0f,0.0f,1.0f,
				0.0f,1.0f,0.0f,1.0f,
				0.0f,1.0f,0.0f,1.0f,

				//Ściana 3
				0.0f,0.0f,1.0f,1.0f,
				0.0f,0.0f,1.0f,1.0f,
				0.0f,0.0f,1.0f,1.0f,

				0.0f,0.0f,1.0f,1.0f,
				0.0f,0.0f,1.0f,1.0f,
				0.0f,0.0f,1.0f,1.0f,

				//Ściana 4
				1.0f,1.0f,0.0f,1.0f,
				1.0f,1.0f,0.0f,1.0f,
				1.0f,1.0f,0.0f,1.0f,

				1.0f,1.0f,0.0f,1.0f,
				1.0f,1.0f,0.0f,1.0f,
				1.0f,1.0f,0.0f,1.0f,

				//Ściana 5
				0.0f,1.0f,1.0f,1.0f,
				0.0f,1.0f,1.0f,1.0f,
				0.0f,1.0f,1.0f,1.0f,

				0.0f,1.0f,1.0f,1.0f,
				0.0f,1.0f,1.0f,1.0f,
				0.0f,1.0f,1.0f,1.0f,
			};

			float doubleCubeNormals[]={
			    //prawy klocek
				//Œciana 1 (tylna)
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				//Œciana 2 (przednia)
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				//Œciana 3 (dolna)
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				//Œciana 4 (gorna)
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				//Œciana 5 (prawa)
				2.0f, 0.0f, 0.0f,0.0f,
				2.0f, 0.0f, 0.0f,0.0f,
				2.0f, 0.0f, 0.0f,0.0f,

				2.0f, 0.0f, 0.0f,0.0f,
				2.0f, 0.0f, 0.0f,0.0f,
				2.0f, 0.0f, 0.0f,0.0f,

				//lewy klocek
				//Œciana 1 (tylna)
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				//Œciana 2 (przednia)
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				//Œciana 3 (dolna)
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				//Œciana 4 (gorna)
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				//Œciana 5 (lewa)
				-2.0f, 0.0f, 0.0f,0.0f,
				-2.0f, 0.0f, 0.0f,0.0f,
				-2.0f, 0.0f, 0.0f,0.0f,

				-2.0f, 0.0f, 0.0f,0.0f,
				-2.0f, 0.0f, 0.0f,0.0f,
				-2.0f, 0.0f, 0.0f,0.0f,
			};

			float doubleCubeVertexNormals[]={
				//Œciana 1
				1.0f,-1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				-1.0f,-1.0f,-1.0f,0.0f,

				1.0f,-1.0f,-1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,

				//Œciana 2
				-1.0f,-1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,

				-1.0f,-1.0f, 1.0f,0.0f,
				-1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,


				//Œciana 3
				-1.0f,-1.0f,-1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,
				1.0f,-1.0f,-1.0f,0.0f,

				-1.0f,-1.0f,-1.0f,0.0f,
				-1.0f,-1.0f, 1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,

				//Œciana 4
				-1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,

				-1.0f, 1.0f, 1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,

				//Œciana 5
				-1.0f,-1.0f,-1.0f,0.0f,
				-1.0f, 1.0f, 1.0f,0.0f,
				-1.0f,-1.0f, 1.0f,0.0f,

				-1.0f,-1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				-1.0f, 1.0f, 1.0f,0.0f,

				//Œciana 6
				1.0f,-1.0f, 1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				1.0f,-1.0f,-1.0f,0.0f,

				1.0f,-1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,

				//Œciana 7
				1.0f,-1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				-1.0f,-1.0f,-1.0f,0.0f,

				1.0f,-1.0f,-1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,

				//Œciana 8
				-1.0f,-1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,

				-1.0f,-1.0f, 1.0f,0.0f,
				-1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,


				//Œciana 9
				-1.0f,-1.0f,-1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,
				1.0f,-1.0f,-1.0f,0.0f,

				-1.0f,-1.0f,-1.0f,0.0f,
				-1.0f,-1.0f, 1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,

				//Œciana 10
				-1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,

				-1.0f, 1.0f, 1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,

			};

			float doubleCubeTexCoords[]={
				//prawy kloc
				//Œciana 1
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				//Œciana 2
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				//Œciana 3
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				//Œciana 4
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				//Œciana 5
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				//lewy kloc

				//Œciana 6
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				//Œciana 7
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				//Œciana 8
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				//Œciana 9
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				//Œciana 10
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				};

#endif // DOUBLE_CUBE_H_INCLUDED
