/*
gcc -c cg2d.c
gcc atividade3.c -o atividade3 cg2d.o -lm -lX11
./atividade3
*/


#include "cg2d.h"

object * Cisalhamento(object * ob, float escalar) {
  object * oob;
  int i;

  oob = CreateObject(ob->numbers_of_points);
  for(i=0;i<ob->numbers_of_points;i++) {
    SetObject(SetPoint(ob->points[i].x + ((escalar) * (ob->points[i].y) * -1),ob->points[i].y,ob->points[i].color),oob);
    }

  return oob;
  }

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
	paleta = CreatePalette(3);		// paleta tera 2 cores?
	SetColor(0.0, 0.0, 0.0, paleta);	// preto
	SetColor(220.0, 20.0, 60.0, paleta);	// vermelho
	SetColor(30.0, 144.0, 255.0, paleta);	// azul


	// criando pontos
	//point * SetPoint(float x, float y, int color)

	// pontos do quadrado
	point * p1;
	p1 = SetPoint(-1.0, -2.0, 1);
	point * p2;
	p2 = SetPoint(-6.0, -2.0, 1);
	point * p3;
	p3 = SetPoint(-1.0, -6.0, 1);
	point * p4;
	p4 = SetPoint(-6.0, -6.0, 1);


	// criando objetos
	object * quadrado;
	quadrado = CreateObject(4);


	// setando os pontos dos objetos
	SetObject(p1, quadrado);
	SetObject(p3, quadrado);
	SetObject(p4, quadrado);
	SetObject(p2, quadrado);


	// utilizando nossa funcao de cisalhamento
	object * novoquadrado;
	novoquadrado = Cisalhamento(quadrado, 0.5f);


	// desenhando objetos no buffer
	DrawObject(novoquadrado, w, buffer);


	// jogando o buffer na tela
 	Dump2X(buffer, paleta);



}
