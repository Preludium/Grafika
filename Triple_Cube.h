#ifndef TRIPLE_CUBE_H_INCLUDED
#define TRIPLE_CUBE_H_INCLUDED

//myCubeVertices - homogeniczne wspó³rzêdne wierzcho³ków w przestrzeni modelu
//myCubeNormals - homogeniczne wektory normalne œcian (per wierzcho³ek) w przestrzeni modelu
//myCubeVertexNormals - homogeniczne wektory normalne wierzcho³ków w przestrzeni modelu
//myCubeTexCoords - wspó³rzêdne teksturowania
//myCubeColors - kolory wierzcho³ków
//myCubeC1 - kolumna macierzy TBN^-1
//myCubeC2 - kolumna macierzy TBN^-1
//myCubeC3 - kolumna macierzy TBN^-1

int tripleCubeVertexCount= 84;

float tripleCubeVertices[]={
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

				//Ściana 4 (górna)
				1.0f, 1.0f, 1.0f,1.0f,
				3.0f, 1.0f,-1.0f,1.0f,
				3.0f, 1.0f, 1.0f,1.0f,

				1.0f, 1.0f, 1.0f,1.0f,
				1.0f, 1.0f,-1.0f,1.0f,
				3.0f, 1.0f,-1.0f,1.0f,

                //Ściana 5 (boczna prawa)
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
			};


	float tripleCubeNormals[]={
			    // prawy kwadrat

				//Œciana 1 tylna
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				//Œciana 2 przednia
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				//Œciana 3 dolna
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				//Œciana 4 gorna
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				//Œciana 5 boczna prawa
				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,

				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,
				1.0f, 0.0f, 0.0f,0.0f,

				// srodkowy kwadrat

				//Œciana 1 tylna
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				//Œciana 2 przednia
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				//Œciana 3 dolna
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				//Œciana 4 gorna
				0.0f,1.0f, 0.0f,0.0f,
				0.0f,1.0f, 0.0f,0.0f,
				0.0f,1.0f, 0.0f,0.0f,

				0.0f,1.0f, 0.0f,0.0f,
				0.0f,1.0f, 0.0f,0.0f,
				0.0f,1.0f, 0.0f,0.0f,

				//kwadrat lewy

                //Œciana 1 tylna
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,
				0.0f, 0.0f,-1.0f,0.0f,

				//Œciana 2 przednia
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,
				0.0f, 0.0f, 1.0f,0.0f,

				//Œciana 3 dolna
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,
				0.0f,-1.0f, 0.0f,0.0f,

				//Œciana 4 gorna
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,
				0.0f, 1.0f, 0.0f,0.0f,

				//Œciana 5 boczna lewa
				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,

				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,
				-1.0f, 0.0f, 0.0f,0.0f,
			};

	float tripleCubeTexCoords[]={
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

                //lewy kloc

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

                //Œciana 14
				1.0f, 0.0f,   //A
                0.0f, 1.0f,    //B
                0.0f, 0.0f,    //C

                1.0f, 0.0f,    //A
                1.0f, 1.0f,    //D
                0.0f, 1.0f,    //B

				};


#endif // TRIPLE_CUBE_H_INCLUDED
