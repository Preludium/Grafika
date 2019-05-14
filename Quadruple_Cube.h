#ifndef QUADRUPLE_CUBE_H_INCLUDED
#define QUADRUPLE_CUBE_H_INCLUDED

//myCubeVertices - homogeniczne wsp�rz�dne wierzcho�k�w w przestrzeni modelu
//myCubeNormals - homogeniczne wektory normalne �cian (per wierzcho�ek) w przestrzeni modelu
//myCubeVertexNormals - homogeniczne wektory normalne wierzcho�k�w w przestrzeni modelu
//myCubeTexCoords - wsp�rz�dne teksturowania
//myCubeColors - kolory wierzcho�k�w
//myCubeC1 - kolumna macierzy TBN^-1
//myCubeC2 - kolumna macierzy TBN^-1
//myCubeC3 - kolumna macierzy TBN^-1

int quadrupleCubeVertexCount=108;

					float quadrupleCubeVertices[]={
                //prawy kwadrat

                //Ściana 1 (tylna)
				4.0f,-1.0f,-1.0f,1.0f,
				2.0f, 1.0f,-1.0f,1.0f,
				2.0f,-1.0f,-1.0f,1.0f,

				4.0f,-1.0f,-1.0f,1.0f,
				4.0f, 1.0f,-1.0f,1.0f,
				2.0f, 1.0f,-1.0f,1.0f,

                //Ściana 2 (przednia)
				2.0f,-1.0f, 1.0f,1.0f,
				4.0f, 1.0f, 1.0f,1.0f,
				4.0f,-1.0f, 1.0f,1.0f,

				2.0f,-1.0f, 1.0f,1.0f,
				2.0f, 1.0f, 1.0f,1.0f,
				4.0f, 1.0f, 1.0f,1.0f,


				//Ściana 3 (dolna)
				2.0f,-1.0f,-1.0f,1.0f,
				4.0f,-1.0f, 1.0f,1.0f,
				4.0f,-1.0f,-1.0f,1.0f,

				2.0f,-1.0f,-1.0f,1.0f,
				2.0f,-1.0f, 1.0f,1.0f,
				4.0f,-1.0f, 1.0f,1.0f,

				//Ściana 4 (górna)
				2.0f, 1.0f, 1.0f,1.0f,
				4.0f, 1.0f,-1.0f,1.0f,
				4.0f, 1.0f, 1.0f,1.0f,

				2.0f, 1.0f, 1.0f,1.0f,
				2.0f, 1.0f,-1.0f,1.0f,
				4.0f, 1.0f,-1.0f,1.0f,

                //Ściana 5 (boczna prawa)
				4.0f,-1.0f, 1.0f,1.0f,
				4.0f, 1.0f,-1.0f,1.0f,
				4.0f,-1.0f,-1.0f,1.0f,

				4.0f,-1.0f, 1.0f,1.0f,
				4.0f, 1.0f, 1.0f,1.0f,
				4.0f, 1.0f,-1.0f,1.0f,

				//kwadrat srodkowy 1

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

				//kwadrat srodkowy 2

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

				//kwadrat lewy

				//Ściana 1 (tylna)
				-2.0f,-1.0f,-1.0f,1.0f,
				-4.0f, 1.0f,-1.0f,1.0f,
				-4.0f,-1.0f,-1.0f,1.0f,

				-2.0f,-1.0f,-1.0f,1.0f,
				-2.0f, 1.0f,-1.0f,1.0f,
				-4.0f, 1.0f,-1.0f,1.0f,

                //Ściana 2 (przednia)
				-4.0f,-1.0f, 1.0f,1.0f,
				-2.0f, 1.0f, 1.0f,1.0f,
				-2.0f,-1.0f, 1.0f,1.0f,

				-4.0f,-1.0f, 1.0f,1.0f,
				-4.0f, 1.0f, 1.0f,1.0f,
				-2.0f, 1.0f, 1.0f,1.0f,


				//Ściana 3 (dolna)
				-4.0f,-1.0f,-1.0f,1.0f,
				-2.0f,-1.0f, 1.0f,1.0f,
				-2.0f,-1.0f,-1.0f,1.0f,

				-4.0f,-1.0f,-1.0f,1.0f,
				-4.0f,-1.0f, 1.0f,1.0f,
				-2.0f,-1.0f, 1.0f,1.0f,

				//Ściana 4 (górna)
				-4.0f, 1.0f, 1.0f,1.0f,
				-2.0f, 1.0f,-1.0f,1.0f,
				-2.0f, 1.0f, 1.0f,1.0f,

				-4.0f, 1.0f, 1.0f,1.0f,
				-4.0f, 1.0f,-1.0f,1.0f,
				-2.0f, 1.0f,-1.0f,1.0f,

				//Ściana 5 (boczna lewa)
				-4.0f,-1.0f,-1.0f,1.0f,
				-4.0f, 1.0f, 1.0f,1.0f,
				-4.0f,-1.0f, 1.0f,1.0f,

				-4.0f,-1.0f,-1.0f,1.0f,
				-4.0f, 1.0f,-1.0f,1.0f,
				-4.0f, 1.0f, 1.0f,1.0f,
			};


				float quadrupleCubeColors[]={ // single Cube nie zmieniany
                //�ciana 1
				1.0f,0.0f,0.0f,1.0f,
				1.0f,0.0f,0.0f,1.0f,
				1.0f,0.0f,0.0f,1.0f,

				1.0f,0.0f,0.0f,1.0f,
				1.0f,0.0f,0.0f,1.0f,
				1.0f,0.0f,0.0f,1.0f,

				//�ciana 2
				0.0f,1.0f,0.0f,1.0f,
				0.0f,1.0f,0.0f,1.0f,
				0.0f,1.0f,0.0f,1.0f,

				0.0f,1.0f,0.0f,1.0f,
				0.0f,1.0f,0.0f,1.0f,
				0.0f,1.0f,0.0f,1.0f,

				//�ciana 3
				0.0f,0.0f,1.0f,1.0f,
				0.0f,0.0f,1.0f,1.0f,
				0.0f,0.0f,1.0f,1.0f,

				0.0f,0.0f,1.0f,1.0f,
				0.0f,0.0f,1.0f,1.0f,
				0.0f,0.0f,1.0f,1.0f,

				//�ciana 4
				1.0f,1.0f,0.0f,1.0f,
				1.0f,1.0f,0.0f,1.0f,
				1.0f,1.0f,0.0f,1.0f,

				1.0f,1.0f,0.0f,1.0f,
				1.0f,1.0f,0.0f,1.0f,
				1.0f,1.0f,0.0f,1.0f,

				//�ciana 5
				0.0f,1.0f,1.0f,1.0f,
				0.0f,1.0f,1.0f,1.0f,
				0.0f,1.0f,1.0f,1.0f,

				0.0f,1.0f,1.0f,1.0f,
				0.0f,1.0f,1.0f,1.0f,
				0.0f,1.0f,1.0f,1.0f,

				//�ciana 6
				1.0f,1.0f,1.0f,1.0f,
				1.0f,1.0f,1.0f,1.0f,
				1.0f,1.0f,1.0f,1.0f,

				1.0f,1.0f,1.0f,1.0f,
				1.0f,1.0f,1.0f,1.0f,
				1.0f,1.0f,1.0f,1.0f,
			};

			float quadrupleCubeNormals[]={ // single cube nie zmieniany
				//�ciana 1
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				//�ciana 2
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				//�ciana 3
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				//�ciana 4
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				//�ciana 5
				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,

				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,

				//�ciana 6
				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,

				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,


			};

			float quadrupleCubeVertexNormals[]={ // single Cube nie zmieniany
				//�ciana 1
				1.0f,-1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				-1.0f,-1.0f,-1.0f,0.0f,

				1.0f,-1.0f,-1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,

				//�ciana 2
				-1.0f,-1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,

				-1.0f,-1.0f, 1.0f,0.0f,
				-1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,


				//�ciana 3
				-1.0f,-1.0f,-1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,
				1.0f,-1.0f,-1.0f,0.0f,

				-1.0f,-1.0f,-1.0f,0.0f,
				-1.0f,-1.0f, 1.0f,0.0f,
				1.0f,-1.0f, 1.0f,0.0f,

				//�ciana 4
				-1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,

				-1.0f, 1.0f, 1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,

				//�ciana 5
				-1.0f,-1.0f,-1.0f,0.0f,
				-1.0f, 1.0f, 1.0f,0.0f,
				-1.0f,-1.0f, 1.0f,0.0f,

				-1.0f,-1.0f,-1.0f,0.0f,
				-1.0f, 1.0f,-1.0f,0.0f,
				-1.0f, 1.0f, 1.0f,0.0f,

				//�ciana 6
				1.0f,-1.0f, 1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
				1.0f,-1.0f,-1.0f,0.0f,

				1.0f,-1.0f, 1.0f,0.0f,
				1.0f, 1.0f, 1.0f,0.0f,
				1.0f, 1.0f,-1.0f,0.0f,
			};

			float quadrupleCubeTexCoords[]={
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

				//srodkowy kloc

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

                //srodkowy kloc

				//Œciana 10
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B


                //Œciana 11
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

                //Œciana 12
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

                //Œciana 13
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				// lewy kloc

                //Œciana 14
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				//Œciana 15
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				//Œciana 16
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				//Œciana 17
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				//Œciana 18
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B
			};

#endif // QUADRUPLE_CUBE_H_INCLUDED
