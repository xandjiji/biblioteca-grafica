/*
gcc -c cg2d.c
gcc atividade2.c -o atividade2 cg2d.o -lm -lX11
./atividade2
*/


#include "cg2d.h"

// funcao para preencher um objeto com cor
void fill(point * p0, int cor){
	if(p0->color == 0){
		p0->color = 1;

		// criando pontos vizinhos (nao-diagonais)
		point * p1;
		p1 = SetPoint(p0->x - 1.0, p0->y, 0);
		point * p2;
		p2 = SetPoint(p0->x + 1.0, p0->y, 0);
		point * p3;
		p3 = SetPoint(p0->x, p0->y - 1.0, 0);
		point * p4;
		p4 = SetPoint(p0->x, p0->y + 1.0, 0);

		// chamando recursivamente a funcao fill para os pontos vizinhos
		fill(p1, cor);
		fill(p2, cor);
		fill(p3, cor);
		fill(p4, cor);

		// nao esta funcionando corretamente! nao consegui bolar uma forma de detectar os limites do nosso objeto
	}
}

void main(){

	// criando nosso plano cartesiano
	// (float xmin, float xmax, float ymin, float ymax)
	window * w;
	w = CreateWindow(-8.0, 5.0, -7.0, 5.0);
//	w = CreateWindow(-20.0, 20.0, -20.0, 20.0);


	// criando um buffer
	bufferdevice * buffer;
	buffer = CreateBuffer(640, 480);


	// criando cores numa paleta de cores
	palette * paleta;
	paleta = CreatePalette(4);		// paleta tera 2 cores?
/*
	SetColor(0.0, 0.0, 0.0, paleta);	// preto
	SetColor(1.0, 0.0, 0.0, paleta);	// vermelho
	SetColor(0.0, 0.0, 1.0, paleta);	// azul
	SetColor(0.0, 1.0, 0.0, paleta);	// verde
*/

	// cores normalizadas
	SetColor(0.0, 0.0, 0.0, paleta);	// preto
	SetColor(0.215, 0.066, 0.501, paleta);	// azul
	SetColor(0.431, 0.047, 0.078, paleta);	// vermelho
	SetColor(0.137, 0.458, 0.188, paleta);	// verde




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

	point * teste;
	teste = SetPoint(-3.1, -5.9, 0);


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

	object * novopoligono;
	novopoligono = Rotate(poligono, 45.0); // o nosso novo objeto sera rotacionado em torno da ORIGEM e nao em torno de si mesmo. Isso causa a impressao de que ele "translada" um pouco
	novopoligono = ChangeColor(novopoligono, 3);
	DrawObject(novopoligono, w, buffer);


	// jogando o buffer na tela
 	Dump2X(buffer, paleta);



}
