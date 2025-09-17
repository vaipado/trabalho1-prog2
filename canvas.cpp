#include "canvas.hpp"
#include <iostream>

void CriarCanvas(Canvas &tela, int largura, int altura)
{
    if (largura <= 0 || altura <= 0)
    {
        std::cerr << "Largura ou altura inválida" << std::endl; // Aqui eu valido as medidas passadas
        tela.largura = 0;
        tela.altura = 0;
        tela.pixels = nullptr;
        tela.cores = nullptr;
        return;
    }

    tela.largura = largura;
    tela.altura = altura;

    tela.pixels = new char *[altura];
    tela.cores = new char *[altura];

    for (int i = 0; i < altura; i++)
    {
        tela.pixels[i] = new char[largura];
        tela.cores[i] = new char[largura];

        for (int j = 0; j < largura; j++)
        {
            tela.pixels[i][j] = ' ';
            tela.cores[i][j] = 'W';
        }
    }
}

void DestruirCanvas(Canvas &tela)
{
    if (tela.pixels != nullptr)
    {
        for (int i = 0; i < tela.altura; i++)
        {
            delete[] tela.pixels[i];
        }
        delete[] tela.pixels;
        tela.pixels = nullptr;
    }

    if (tela.cores != nullptr)
    {
        for (int i = 0; i < tela.altura; i++)
        {
            delete[] tela.cores[i];
        }
        delete[] tela.cores;
        tela.cores = nullptr;
    }

    tela.altura = 0;
    tela.largura = 0;
}

void ImprimirCanvas(const Canvas &tela)
{

    for (int i = 0; i < tela.largura + 2; i++)
        std::cout << '-'; // Isso vai criar o topo da borda do canvas
    std::cout << std::endl;

    for (int i = 0; i < tela.altura; i++)
    {
        std::cout << '|'; // Isso vai criar a borda lateral esquerda

        for (int j = 0; j < tela.largura; j++)
        {
            std::cout << tela.pixels[i][j];
        }
        std::cout << '|' << std::endl; // E isso vai criar a borda lateral direita
    }

    for (int i = 0; i < tela.largura + 2; i++) 
        std::cout << '-'; // Isso vai criar o topo da borda do canvas
    std::cout << std::endl;
}

void DesenharPonto(Canvas &tela, int x, int y, char simbolo, char cor)
{
    // Código da lógica será implementado aqui
}
void DesenharLinha(Canvas &tela, int x1, int y1, int x2, int y2, char simbolo, char cor)
{
    // Código da lógica será implementado aqui
}
void DesenharRetangulo(Canvas &tela, int x, int y, int largura, int altura, char simbolo, char cor)
{
    // Código da lógica será implementado aqui
}
void DesenharRetanguloPreenchido(Canvas &tela, int x, int y, int largura, int altura, char simbolo, char cor)
{
    // Código da lógica será implementado aqui
}
void RedimensionarCanvas(Canvas &tela, int novaLargura, int novaAltura)
{
    // Código da lógica será implementado aqui
}
void SobreporCanvas(Canvas &telaDestino, const Canvas &telaOrigem1, const Canvas &telaOrigem2)
{
    // Código da lógica será implementado aqui
}
bool CompararCanvas(const Canvas &tela1, const Canvas &tela2)
{
    // Código da lógica será implementado aqui
    return true;
}