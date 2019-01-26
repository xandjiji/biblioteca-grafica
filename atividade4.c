/*
gcc -c cg2d.c
gcc -c cg3d.c
gcc atividade4.c -o atividade4 ./cg2d.o ./cg3d.o -lm -lX11
rodar ./atividade4
*/


#include "cg3d.h"

int main() {

// setando a janela
	window *janela;
	janela = CreateWindow(-30, 30, -30, 30);

// criando buffer
	bufferdevice *buffer;
	buffer = CreateBuffer(640, 480);

// setando universo
	SetWorld3d(-100, 100, -100, 100, -100, 100);
	SetWorld(-100, 100, -100, 100);

// parametros do observador
	SetObsPlane(0, 0, -1);
	SetProjCenter(0, 0, -45);
	SetProjPlane(0, 0, -5);
	SetViewPlane(0, 1, 0);


// criando paleta de cores
	palette *paleta_cores;
	paleta_cores = CreatePalette(3);

// setando cores na paleta
	SetColor(1, 1, 1, paleta_cores);
	SetColor(0, 0, 0, paleta_cores);
	SetColor(0, 1, 1, paleta_cores);




// criando nosso objeto
	object3 *objeto3d;
	objeto3d = CreateObject3(5);

// criando pontos (1)
	point3 *p11;
	p11 = SetPoint3(10, 10, 0, 1);

	point3 *p12;
	p12 = SetPoint3(10, 0, 15, 1);

	point3 *p13;
	p13 = SetPoint3(10, -10, 0, 1);

// criando face (1) com esses pontos
	face *face1;
	face1 = CreateFace(3);

// setando os pontos da face (1)
	SetFace(p11, face1);
	SetFace(p12, face1);
	SetFace(p13, face1);





// criando pontos (2)
	point3 *p21;
	p21 = SetPoint3(-10, 10, 0, 1);

	point3 *p22;
	p22 = SetPoint3(-10, 0, 15, 1);

	point3 *p23;
	p23 = SetPoint3(-10, -10, 0, 1);

// criando face (2) com esses pontos
	face *face2;
	face2 = CreateFace(3);

// setando os pontos da face (2)
	SetFace(p21, face2);
	SetFace(p22, face2);
	SetFace(p23, face2);





// criando pontos (3)
	point3 *p31;
	p31 = SetPoint3(10, 10, 0, 1);

	point3 *p32;
	p32 = SetPoint3(10, 0, 15, 1);

	point3 *p33;
	p33 = SetPoint3(-10, 0, 15, 1);

	point3 *p34;
	p34 = SetPoint3(-10, 10, 0, 1);

// criando face (3) com esses pontos
	face *face3;
	face3 = CreateFace(4);

// setando os pontos da face (3)
	SetFace(p31, face3);
	SetFace(p32, face3);
	SetFace(p33, face3);
	SetFace(p34, face3);





// criando pontos (4)
	point3 *p41;
	p41 = SetPoint3(10, 0, 15, 1);

	point3 *p42;
	p42 = SetPoint3(10, -10, 0, 1);

	point3 *p43;
	p43 = SetPoint3(-10, -10, 0, 1);

	point3 *p44;
	p44 = SetPoint3(-10, 0, 15, 1);

// criando face (4) com esses pontos
	face *face4;
	face4 = CreateFace(4);

// setando os pontos da face (4)
	SetFace(p41, face4);
	SetFace(p42, face4);
	SetFace(p43, face4);
	SetFace(p44, face4);





// criando pontos (5)
	point3 *p51;
	p51 = SetPoint3(10, 10, 0, 1);

	point3 *p52;
	p52 = SetPoint3(10, -10, 0, 1);

	point3 *p53;
	p53 = SetPoint3(-10, -10, 0, 1);

	point3 *p54;
	p54 = SetPoint3(-10, 10, 0, 1);

// criando face (5) com esses pontos
	face *face5;
	face5 = CreateFace(4);

// setando os pontos da face (5)
	SetFace(p51, face5);
	SetFace(p52, face5);
	SetFace(p53, face5);
	SetFace(p54, face5);





// setando as faces para o nosso objeto3d
	SetObject3(face1, objeto3d);
	SetObject3(face2, objeto3d);
	SetObject3(face3, objeto3d);
	SetObject3(face4, objeto3d);
	SetObject3(face5, objeto3d);

// desenhando
	DrawObject3D(objeto3d, janela, buffer);

// chamando dump2x
	Dump2X(buffer, paleta_cores);

}
