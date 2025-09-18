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

// <-- funções para evitar repetição de código -->

bool validade(const Canvas &tela, int x, int y) // Uma função que valida coordenadas
{
    if (x < 0 || x > tela.largura || y < 0 || y > tela.altura) // Verifica se as coordenadas são menores que 0 ou se são maiores que as medidas do canvas
        return true;
    return false;
}

void modificaCanvas(Canvas &tela, int x, int y, char simbolo, char cor) // Uma função que modifica o valor de um pixel ou cor nas matrizes do canvas
{
    tela.pixels[y][x] = simbolo;
    tela.cores[y][x] = cor;
}

bool igualdade(int c1, int c2) // Função simples que verifica igualdade
{
    return c1 == c2;
}

void itera(int inicio, int fim, int inicio2, int fim2, Canvas &tela, char simbolo, char cor) // Função que itera em dois for's e modifica o canvas chamando a função modificaCanvas() passando seus devidos parâmetros
{
    for (int i = inicio; i < fim; i++)
        for (int j = inicio2; j < fim2; j++)
            modificaCanvas(tela, j, i, simbolo, cor);
}

// <-- funções cobradas no trabalho -->

void CriarCanvas(Canvas &tela, int largura, int altura)
{
    // Valido as dimensões da tela
    if (largura <= 0 || altura <= 0)
    {
        std::cout << GetColorCode('R') << "Largura ou altura inválida" << RESET << std::endl;
        tela.largura = 0;
        tela.altura = 0;
        tela.pixels = nullptr;
        tela.cores = nullptr;
        return; // A função é encerrada aqui
    }

    // Armazeno as dimensões válidas
    tela.largura = largura;
    tela.altura = altura;

    // Alocação de memória para as matrizes
    tela.pixels = new char *[altura];
    tela.cores = new char *[altura];

    for (int i = 0; i < altura; i++)
    {
        tela.pixels[i] = new char[largura];
        tela.cores[i] = new char[largura];

        for (int j = 0; j < largura; j++) // Aqui eu preencho as matrizes do canvas
        {
            modificaCanvas(tela, j, i, ' ', ' ');
        }
    }
}

void DestruirCanvas(Canvas &tela)
{
    if (tela.pixels != nullptr) // Impede que o programa tente liberar memória que não foi alocada ou que já foi liberada
    {
        for (int i = 0; i < tela.altura; i++)
        {
            delete[] tela.pixels[i];
        }
        delete[] tela.pixels;
        tela.pixels = nullptr;
    }

    if (tela.cores != nullptr) // Mesma coisa que a de cima
    {
        for (int i = 0; i < tela.altura; i++)
        {
            delete[] tela.cores[i];
        }
        delete[] tela.cores;
        tela.cores = nullptr;
    }

    tela.altura = 0; // Anulo as medidas do canvas
    tela.largura = 0;
}

void ImprimirCanvas(const Canvas &tela)
{
    for (int i = 0; i < tela.largura + 2; i++)
        std::cout << '-'; // topo da borda do canvas
    std::cout << std::endl;

    for (int i = 0; i < tela.altura; i++)
    {
        std::cout << '|'; // borda lateral esquerda
        for (int j = 0; j < tela.largura; j++)
            std::cout << GetColorCode(tela.cores[i][j]) << tela.pixels[i][j] << RESET;
        std::cout << '|' << std::endl; // borda lateral direita
    }

    for (int i = 0; i < tela.largura + 2; i++)
        std::cout << '-'; // pé da borda do canvas
    std::cout << std::endl;
}

void DesenharPonto(Canvas &tela, int x, int y, char simbolo, char cor)
{
    if (validade(tela, x, y)) // Validação para as coordenadas
    {
        std::cout << GetColorCode('R') << "Coordenadas Inválidas!" << RESET << std::endl;
        return;
    }
    modificaCanvas(tela, x, y, simbolo, cor); // Após a validação, eu modifico o simbolo e a cor
}

void DesenharLinha(Canvas &tela, int x1, int y1, int x2, int y2, char simbolo, char cor)
{
    if (validade(tela, x1, y1) || validade(tela, x2, y2)) // Validação para as coordenadas
    {
        std::cout << GetColorCode('R') << "Coordenadas Inválidas!" << RESET << std::endl;
        return;
    }
    if (igualdade(x1, x2) || igualdade(y1, y2)) // Garante que a linha seja absolutamente horizontal ou vertical
    {
        itera(y1 - 1, y2, x1 - 1, x2, tela, simbolo, cor); // Desenho a linha
        return;
    }
    // Se chegou aqui, quer dizer que a linha não é absolutamente horizontal ou vertical e, portanto, nem preciso de um 'else'
    std::cout << GetColorCode('R') << "A linha não é perfeitamente horizontal ou vertical!" << RESET << std::endl;
    return;
}

void DesenharRetangulo(Canvas &tela, int x, int y, int largura, int altura, char simbolo, char cor)
{
    int x2, y2;
    x2 = x + largura; // Aqui, eu obtenho as segundas coordenadas
    y2 = y + altura;

    if (validade(tela, x, y) || validade(tela, x2, y2))
    {
        std::cout << GetColorCode('R') << "Coordenadas Inválidas!" << RESET << std::endl;
        return;
    }

    for (int i = x - 1; i < x2; i++) // Aqui eu "desenho" as duas bases do retângulo
    {
        modificaCanvas(tela, i, y - 1, simbolo, cor);  // A de cima
        modificaCanvas(tela, i, y2 - 1, simbolo, cor); // A de baixo
    }
    for (int i = y - 1; i < y2; i++) // Aqui eu "desenho" as duas laterais
    {
        modificaCanvas(tela, x - 1, i, simbolo, cor);  // A da esquerda
        modificaCanvas(tela, x2 - 1, i, simbolo, cor); // A da direita
    }
}
void DesenharRetanguloPreenchido(Canvas &tela, int x, int y, int largura, int altura, char simbolo, char cor)
{
    int x2, y2;
    x2 = x + largura; // Aqui, eu obtenho as segundas coordenadas
    y2 = y + altura;

    if (validade(tela, x, y) || validade(tela, x2, y2)) // Valido as coordenadas
    {
        std::cout << GetColorCode('R') << "Coordenadas Inválidas!" << RESET << std::endl;
        return;
    }
    // Preencho todo o retângulo formado pelas 4 coordenadas (é como se eu tivesse preenchendo uma matriz)
    itera(y - 1, y2, x - 1, x2, tela, simbolo, cor);
}
void RedimensionarCanvas(Canvas &tela, int novaLargura, int novaAltura)
{
    Canvas tela2;
    CriarCanvas(tela2, tela.largura, tela.altura); // Crio um "canvas auxiliar" que vai guardar o conteúdo do canvas que estamos trabalhando
    for (int i = 0; i < tela.altura; i++)
        for (int j = 0; j < tela.largura; j++)
            modificaCanvas(tela2, j, i, tela.pixels[i][j], tela.cores[i][j]);

    CriarCanvas(tela, novaLargura, novaAltura); // Redimensiono o canvas que estamos trabalhando
    int altura, largura;
    (tela2.altura > novaAltura ? altura = novaAltura : altura = tela2.altura); // Determino as medidas para serem usadas no for que iterará sob as matrizes de pixels e cores do novo canvas
    (tela2.largura > novaLargura ? largura = novaLargura : largura = tela2.largura);

    for (int i = 0; i < altura; i++)
        for (int j = 0; j < largura; j++)
            modificaCanvas(tela, j, i, tela2.pixels[i][j], tela2.cores[i][j]); // "Preencho" o novo canvas com o conteúdo do antigo canvas
}

void SobreporCanvas(Canvas &telaDestino, const Canvas &telaOrigem1, const Canvas &telaOrigem2)
{
    if (igualdade(telaOrigem1.altura, telaOrigem2.altura) && igualdade(telaOrigem1.largura, telaOrigem2.largura)) // Verifico se as medidas são iguais
        for (int i = 0; i < telaOrigem1.altura; i++)
            for (int j = 0; j < telaOrigem1.largura; j++)
                (telaOrigem2.pixels[i][j] != ' ' ? modificaCanvas(telaDestino, j, i, telaOrigem2.pixels[i][j], telaOrigem2.cores[i][j]) : modificaCanvas(telaDestino, j, i, telaOrigem1.pixels[i][j], telaOrigem1.cores[i][j]));
    // Se o pixel do canvas B for difente de ' ', priorizar o valor desse pixel, "subscrevendo" o pixel do canvas A
}

bool CompararCanvas(const Canvas &tela1, const Canvas &tela2)
{
    if (igualdade(tela1.altura, tela2.altura) && igualdade(tela1.largura, tela2.largura)) // Verifico se as medidas são iguais
    {
        for (int i = 0; i < tela1.altura; i++)
            for (int j = 0; j < tela1.largura; j++)
                if (tela1.pixels[i][j] != tela2.pixels[i][j] || tela1.cores[i][j] != tela2.cores[i][j]) // Itero a matriz procurando valores diferentes
                    return false;
        return true; // Se chegar até aqui, quer dizer que as medidas são iguais e não há valores difentes, os canvas são idênticos
    }
    return false;
}
