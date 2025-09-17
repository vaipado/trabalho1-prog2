#include "canvas.hpp"
#include <iostream>
#include <string>

std::string GetColorCode(char cor)
{
    switch (cor)
    {
    case 'K':
        return "\033[30m"; // Black
    case 'R':
        return "\033[31m"; // Red
    case 'G':
        return "\033[32m"; // Green
    case 'Y':
        return "\033[33m"; // Yellow
    case 'B':
        return "\033[34m"; // Blue
    case 'M':
        return "\033[35m"; // Magenta
    case 'C':
        return "\033[36m"; // Cyan
    case 'W':
        return "\033[37m"; // White
    default:
        return "\033[0m"; // Código para Resetar/Padrão
    }
}

const std::string RESET = GetColorCode(' ');

bool verificaCoordenada(const Canvas &tela, int x, int y) // Uma função que valida coordenadas, fiz para evitar a repetição de código
{
    if (x < 0 || x > tela.largura || y < 0 || y > tela.altura)
        return true; // Se retornar true, então as coordenada são inválidas
    return false;
}

void modificaPixel(Canvas &tela, int x, int y, char simbolo, char cor)
{
    tela.pixels[y][x] = simbolo;
    tela.cores[y][x] = cor;
}

void CriarCanvas(Canvas &tela, int largura, int altura)
{
    if (largura <= 0 || altura <= 0)
    {
        std::cout << "Largura ou altura inválida" << std::endl; // Aqui eu valido as medidas passadas
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
            modificaPixel(tela, j, i, ' ', ' ');
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
            std::cout << GetColorCode(tela.cores[i][j]) << tela.pixels[i][j];
        }
        std::cout << '|' << std::endl; // E isso vai criar a borda lateral direita
    }

    for (int i = 0; i < tela.largura + 2; i++)
        std::cout << '-'; // Isso vai criar o topo da borda do canvas
    std::cout << std::endl;
}

void DesenharPonto(Canvas &tela, int x, int y, char simbolo, char cor)
{
    if (verificaCoordenada(tela, x, y))
    {
        std::cout << "Coordenadas Inválidas!" << std::endl; // Validação para as coordenadas
        return;
    }
    modificaPixel(tela, x, y, simbolo, cor);
}

void DesenharLinha(Canvas &tela, int x1, int y1, int x2, int y2, char simbolo, char cor)
{
    if (verificaCoordenada(tela, x1, y1) || verificaCoordenada(tela, x2, y2))
    {
        std::cout << "Coordenadas Inválidas!" << std::endl; // Validação para as coordenadas
        return;
    }
    else if (x1 == x2 || y1 == y2)
    {
        for (int i = y1 - 1; i < y2; i++)
            for (int j = x1 - 1; j < x2; j++)
            {
                modificaPixel(tela, j, i, simbolo, cor);
            }
    }
    else
    {
        std::cout << "A linha não é perfeitamente horizontal ou vertical!" << std::endl;
        return;
    }
}
void DesenharRetangulo(Canvas &tela, int x, int y, int largura, int altura, char simbolo, char cor)
{
    int x2, y2;
    x2 = x + largura; // Aqui, eu obtenho as segundas coordenadas
    y2 = y + altura;

    if (verificaCoordenada(tela, x, y) || verificaCoordenada(tela, x2, y2))
    {
        std::cout << "Coordenadas Inválidas!" << std::endl;
        return;
    }

    for (int i = x - 1; i < x2; i++)
    {
        modificaPixel(tela, y - 1, i, simbolo, cor);
        modificaPixel(tela, y2 - 1, i, simbolo, cor);
    }
    for (int i = y - 1; i < y2; i++)
    {
        modificaPixel(tela, i, x - 1, simbolo, cor);
        modificaPixel(tela, i, x2 - 1, simbolo, cor);
    }
}
void DesenharRetanguloPreenchido(Canvas &tela, int x, int y, int largura, int altura, char simbolo, char cor)
{
    int x2, y2;
    x2 = x + largura; // Aqui, eu obtenho as segundas coordenadas
    y2 = y + altura;

    if (verificaCoordenada(tela, x, y) || verificaCoordenada(tela, x2, y2))
    {
        std::cout << "Coordenadas Inválidas!" << std::endl;
        return;
    }
    for (int i = x - 1; i < x2; i++)
        for (int j = y - 1; j < y2; j++)
        {
            modificaPixel(tela, j, i, simbolo, cor);
        }
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
    if (tela1.altura == tela2.altura && tela1.largura == tela2.largura)
    {
        for (int i = 0; i < tela1.altura; i++)
            for (int j = 0; j < tela1.largura; j++)
                if (tela1.pixels[i][j] != tela2.pixels[i][j] || tela1.cores[i][j] != tela2.cores[i][j])
                    return false;
        return true;
    } return false;
}
