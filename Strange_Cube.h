#ifndef STRANGE_CUBE_H_INCLUDED
#define STRANGE_CUBE_H_INCLUDED

//myCubeVertices - homogeniczne współrzędne wierzchołków w przestrzeni modelu
//myCubeNormals - homogeniczne wektory normalne ścian (per wierzchołek) w przestrzeni modelu
//myCubeVertexNormals - homogeniczne wektory normalne wierzchołków w przestrzeni modelu
//myCubeTexCoords - współrzędne teksturowania
//myCubeColors - kolory wierzchołków
//myCubeC1 - kolumna macierzy TBN^-1
//myCubeC2 - kolumna macierzy TBN^-1
//myCubeC3 - kolumna macierzy TBN^-1

int strangeCubeVertexCount=108;

float strangeCubeVertices[]={
                //prawy kwadrat

                //Ściana 1 (tylna)
				3.0f,-1.0f,-1.0f,1.0f,
				1.0f, 1.0f,-1.0f,1.0f,
				1.0f,-1.0f,-1.0f,1.0f,

				3.0f,-1.0f,-1.0f,1.0f,
				3.0f, 1.0f,-1.0f,1.0f,
				1.0f, 1.0f,-1.0f,1.0f,

                //Ściana 2 (przednia)
				1.0f,-1.0f, 1.0f,1.0f,
				3.0f, 1.0f, 1.0f,1.0f,
				3.0f,-1.0f, 1.0f,1.0f,

				1.0f,-1.0f, 1.0f,1.0f,
				1.0f, 1.0f, 1.0f,1.0f,
				3.0f, 1.0f, 1.0f,1.0f,


				//Ściana 3 (dolna)
				1.0f,-1.0f,-1.0f,1.0f,
				3.0f,-1.0f, 1.0f,1.0f,
				3.0f,-1.0f,-1.0f,1.0f,

				1.0f,-1.0f,-1.0f,1.0f,
				1.0f,-1.0f, 1.0f,1.0f,
				3.0f,-1.0f, 1.0f,1.0f,


                //Ściana 4 (boczna prawa)
				3.0f,-1.0f, 1.0f,1.0f,
				3.0f, 1.0f,-1.0f,1.0f,
				3.0f,-1.0f,-1.0f,1.0f,

				3.0f,-1.0f, 1.0f,1.0f,
				3.0f, 1.0f, 1.0f,1.0f,
				3.0f, 1.0f,-1.0f,1.0f,

				//kwadrat srodkowy

				//Ściana 1 (tylna)
				1.0f,-1.0f,-1.0f,1.0f,
				-1.0f, 1.0f,-1.0f,1.0f,
				-1.0f,-1.0f,-1.0f,1.0f,

				1.0f,-1.0f,-1.0f,1.0f,
				1.0f, 1.0f,-1.0f,1.0f,
				-1.0f, 1.0f,-1.0f,1.0f,

                //Ściana 2 (przednia)
				-1.0f,-1.0f, 1.0f,1.0f,
				1.0f, 1.0f, 1.0f,1.0f,
				1.0f,-1.0f, 1.0f,1.0f,

				-1.0f,-1.0f, 1.0f,1.0f,
				-1.0f, 1.0f, 1.0f,1.0f,
				1.0f, 1.0f, 1.0f,1.0f,


				//Ściana 3 (dolna)
				-1.0f,-1.0f,-1.0f,1.0f,
				1.0f,-1.0f, 1.0f,1.0f,
				1.0f,-1.0f,-1.0f,1.0f,

				-1.0f,-1.0f,-1.0f,1.0f,
				-1.0f,-1.0f, 1.0f,1.0f,
				1.0f,-1.0f, 1.0f,1.0f,

				//Ściana 4 (górna)
				-1.0f, 1.0f, 1.0f,1.0f,
				1.0f, 1.0f,-1.0f,1.0f,
				1.0f, 1.0f, 1.0f,1.0f,

				-1.0f, 1.0f, 1.0f,1.0f,
				-1.0f, 1.0f,-1.0f,1.0f,
				1.0f, 1.0f,-1.0f,1.0f,

				//kwadrat lewy

				//Ściana 1 (tylna)
				-1.0f,-1.0f,-1.0f,1.0f,
				-3.0f, 1.0f,-1.0f,1.0f,
				-3.0f,-1.0f,-1.0f,1.0f,

				-1.0f,-1.0f,-1.0f,1.0f,
				-1.0f, 1.0f,-1.0f,1.0f,
				-3.0f, 1.0f,-1.0f,1.0f,

                //Ściana 2 (przednia)
				-3.0f,-1.0f, 1.0f,1.0f,
				-1.0f, 1.0f, 1.0f,1.0f,
				-1.0f,-1.0f, 1.0f,1.0f,

				-3.0f,-1.0f, 1.0f,1.0f,
				-3.0f, 1.0f, 1.0f,1.0f,
				-1.0f, 1.0f, 1.0f,1.0f,


				//Ściana 3 (dolna)
				-3.0f,-1.0f,-1.0f,1.0f,
				-1.0f,-1.0f, 1.0f,1.0f,
				-1.0f,-1.0f,-1.0f,1.0f,

				-3.0f,-1.0f,-1.0f,1.0f,
				-3.0f,-1.0f, 1.0f,1.0f,
				-1.0f,-1.0f, 1.0f,1.0f,

				//Ściana 4 (górna)
				-3.0f, 1.0f, 1.0f,1.0f,
				-1.0f, 1.0f,-1.0f,1.0f,
				-1.0f, 1.0f, 1.0f,1.0f,

				-3.0f, 1.0f, 1.0f,1.0f,
				-3.0f, 1.0f,-1.0f,1.0f,
				-1.0f, 1.0f,-1.0f,1.0f,

				//Ściana 5 (boczna lewa)
				-3.0f,-1.0f,-1.0f,1.0f,
				-3.0f, 1.0f, 1.0f,1.0f,
				-3.0f,-1.0f, 1.0f,1.0f,

				-3.0f,-1.0f,-1.0f,1.0f,
				-3.0f, 1.0f,-1.0f,1.0f,
				-3.0f, 1.0f, 1.0f,1.0f,

				//kwadrat gorny

				//Ściana 1 (tylna)
				3.0f, 1.0f,-1.0f,1.0f,
				1.0f, 3.0f,-1.0f,1.0f,
				1.0f, 1.0f,-1.0f,1.0f,

				3.0f, 1.0f,-1.0f,1.0f,
				3.0f, 3.0f,-1.0f,1.0f,
				1.0f, 3.0f,-1.0f,1.0f,

                //Ściana 2 (przednia)
				1.0f, 1.0f, 1.0f,1.0f,
				3.0f, 3.0f, 1.0f,1.0f,
				3.0f, 1.0f, 1.0f,1.0f,

				1.0f, 1.0f, 1.0f,1.0f,
				1.0f, 3.0f, 1.0f,1.0f,
				3.0f, 3.0f, 1.0f,1.0f,

				//Ściana 3 (górna)
				1.0f, 3.0f, 1.0f,1.0f,
				3.0f, 3.0f,-1.0f,1.0f,
				3.0f, 3.0f, 1.0f,1.0f,

				1.0f, 3.0f, 1.0f,1.0f,
				1.0f, 3.0f,-1.0f,1.0f,
				3.0f, 3.0f,-1.0f,1.0f,

				//Ściana 4 (boczna lewa)
				1.0f, 1.0f,-1.0f,1.0f,
				1.0f, 3.0f, 1.0f,1.0f,
				1.0f, 1.0f, 1.0f,1.0f,

				1.0f, 1.0f,-1.0f,1.0f,
				1.0f, 3.0f,-1.0f,1.0f,
				1.0f, 3.0f, 1.0f,1.0f,

				//Ściana 5 (boczna prawa)
				3.0f, 1.0f, 1.0f,1.0f,
				3.0f, 3.0f,-1.0f,1.0f,
				3.0f, 1.0f,-1.0f,1.0f,

				3.0f, 1.0f, 1.0f,1.0f,
				3.0f, 3.0f, 1.0f,1.0f,
				3.0f, 3.0f,-1.0f,1.0f,
		};


float strangeCubeColors[]={
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

				//Ściana 6
				1.0f,1.0f,1.0f,1.0f,
				1.0f,1.0f,1.0f,1.0f,
				1.0f,1.0f,1.0f,1.0f,

				1.0f,1.0f,1.0f,1.0f,
				1.0f,1.0f,1.0f,1.0f,
				1.0f,1.0f,1.0f,1.0f,
			};

			float strangeCubeNormals[]={ // single nie zmieniany
				//Ściana 1
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				//Ściana 2
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				//Ściana 3
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				//Ściana 4
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				//Ściana 5
				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,

				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,

				//Ściana 6
				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,

				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,


			};

			float strangeCubeVertexNormals[]={ // single nie zmieniany
				//Ściana 1
				1.0f,-1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				-1.0f,-1.0f,-1.0f,0.0f,

				1.0f,-1.0f,-1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,

				//Ściana 2
				-1.0f,-1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,

				-1.0f,-1.0f, 1.0f,0.0f,
				-1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,


				//Ściana 3
				-1.0f,-1.0f,-1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,
				1.0f,-1.0f,-1.0f,0.0f,

				-1.0f,-1.0f,-1.0f,0.0f,
				-1.0f,-1.0f, 1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,

				//Ściana 4
				-1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,

				-1.0f, 1.0f, 1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,

				//Ściana 5
				-1.0f,-1.0f,-1.0f,0.0f,
				-1.0f, 1.0f, 1.0f,0.0f,
				-1.0f,-1.0f, 1.0f,0.0f,

				-1.0f,-1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				-1.0f, 1.0f, 1.0f,0.0f,

				//Ściana 6
				1.0f,-1.0f, 1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				1.0f,-1.0f,-1.0f,0.0f,

				1.0f,-1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
			};

			float strangeCubeTexCoords[]={
				//Ściana 1
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 2
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 3
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 4
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 5
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 6
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 7
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 8
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 9
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 10
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 11
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 12
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 13
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 14
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 15
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 16
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 17
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,

				//Ściana 18
				1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
				1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f,
			};

#endif // STRANGE_CUBE_H_INCLUDED
