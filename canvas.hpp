#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <iostream>

struct Canvas
{
    int largura;
    int altura;
    char** pixels;
    char** cores;
};

void CriarCanvas(Canvas &tela, int largura, int altura);
void DestruirCanvas(Canvas &tela);
void ImprimirCanvas(const Canvas& tela);
void DesenharPonto(Canvas& tela, int x, int y, char simbolo, char cor);
void DesenharLinha(Canvas& tela, int x1, int y1, int x2, int y2, char simbolo, char cor);
void DesenharRetangulo(Canvas& tela, int x, int y, int largura, int altura, char simbolo, char cor);
void DesenharRetanguloPreenchido(Canvas& tela, int x, int y, int largura, int altura, char simbolo, char cor);
void RedimensionarCanvas(Canvas& tela, int novaLargura, int novaAltura);
void SobreporCanvas(Canvas& telaDestino, const Canvas& telaOrigem1, const Canvas& telaOrigem2);
bool CompararCanvas(const Canvas& tela1, const Canvas& tela2);


#endif