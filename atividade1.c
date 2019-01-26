/*
gcc -c cg2d.c
gcc atividade1.c -o atividade1 cg2d.o -lm -lX11
./atividade1
*/


#include "cg2d.h"

void main(){

	// criando nosso plano cartesiano
	// (float xmin, float xmax, float ymin, float ymax)
	window * w;
	w = CreateWindow(-8.0, 5.0, -7.0, 5.0);


	// criando um buffer
	bufferdevice * buffer;
	buffer = CreateBuffer(640, 480);


	// criando cores numa paleta de cores
	palette * paleta;
	paleta = CreatePalette(3);		//  paleta tera 2 cores?
	SetColor(0.0, 0.0, 0.0, paleta);	//  preto
	SetColor(220.0, 20.0, 60.0, paleta);	//  vermelho
	SetColor(30.0, 144.0, 255.0, paleta);	//  azul


	// criando pontos
	// point * SetPoint(float x, float y, int color)

	// pontos do quadrado
	point * p1;
	p1 = SetPoint(-1.0, -2.0, 1);
	point * p2;
	p2 = SetPoint(-6.0, -2.0, 1);
	point * p3;
	p3 = SetPoint(-1.0, -6.0, 1);
	point * p4;
	p4 = SetPoint(-6.0, -6.0, 1);

	// pontos do pentagono
	point * pp1;
	pp1 = SetPoint(-3.0 , -6.0, 2);
	point * pp2;
	pp2 = SetPoint(-4.0 , -4.0, 2);
	point * pp3;
	pp3 = SetPoint(-7.0 , -3.0, 2);
	point * pp4;
	pp4 = SetPoint(-6.0 , -9.0, 2);
	point * pp5;
	pp5 = SetPoint(-9.0 , -8.0, 2);


	// criando objetos
	object * quadrado;
	quadrado = CreateObject(4);

	object * poligono;
	poligono = CreateObject(5);


	// setando os pontos dos objetos
	SetObject(p1, quadrado);
	SetObject(p3, quadrado);
	SetObject(p4, quadrado);
	SetObject(p2, quadrado);

	SetObject(pp1, poligono);
	SetObject(pp2, poligono);
	SetObject(pp3, poligono);
	SetObject(pp5, poligono);
	SetObject(pp4, poligono);


	// desenhando objetos no buffer
	DrawObject(quadrado, w, buffer);
	DrawObject(poligono, w, buffer);


	// jogando o buffer na tela
 	Dump2X(buffer, paleta);



}
