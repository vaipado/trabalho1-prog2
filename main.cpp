#include <iostream>
#include "canvas.hpp"

int main() {
    Canvas tela;
    std::cout << "<<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>>" << std::endl;
    std::cout << "        TESTE DO TAD CANVAS        " << std::endl;
    std::cout << "<<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>>" << std::endl << std::endl;

    // Crio um canvas vazio
    std::cout << "Criando um canvas de 40x30:" << std::endl;
    CriarCanvas(tela, 40, 30);
    ImprimirCanvas(tela);

    // Desenho um ponto em (26, 31)
    std::cout << "Desenhando um ponto (26, 31) com '&' e cor Magenta:" << std::endl;
    DesenharPonto(tela, 26, 31, '&', 'M');
    ImprimirCanvas(tela);

    //Desenho um retângulo preenchido em (3, 4)
    std::cout << "Desenhando um retangulo preenchido em (3,4) com 10x20, '@' e cor Vermelha:" << std::endl;
    DesenharRetanguloPreenchido(tela, 3, 4, 10, 20, '@', 'R');
    ImprimirCanvas(tela);

    // Desenh0 uma linha de (5, 5) a (15, 5)
    std::cout << "Desenhando uma linha horizontal de (5, 5) a (15, 5) com '=' e cor Azul:" << std::endl;
    DesenharLinha(tela, 5, 5, 15, 5, '=', 'B');
    ImprimirCanvas(tela);

    // Desenho um retângulo não preenchido em (25, 2)
    std::cout << "Desenhando a borda de um retangulo em (25, 2) com 12x8, '#' e cor Amarela:" << std::endl;
    DesenharRetangulo(tela, 25, 2, 12, 8, '#', 'Y');
    ImprimirCanvas(tela);

    // Redimensiono o canvas
    std::cout << "Redimensionando o canvas principal para 20x40:" << std::endl;
    RedimensionarCanvas(tela, 20, 40);
    ImprimirCanvas(tela);

    // Testo a sobreposicao e comparacao
    std::cout << "Testando sobreposicao e comparacao entre canvas." << std::endl;
    
    // Crio dois novos canvas para o teste
    Canvas telaA, telaB, telaResultado;
    CriarCanvas(telaA, 15, 10);
    CriarCanvas(telaB, 15, 10);
    CriarCanvas(telaResultado, 15, 10);

    DesenharRetangulo(telaA, 2, 2, 10, 6, 'A', 'M'); // Desenho um retângulo não preenchido no canvas A
    DesenharRetanguloPreenchido(telaB, 5, 4, 8, 4, 'B', 'G'); // Desenho um retângulo preenchido no canvas B
    
    std::cout << "Tela A:" << std::endl;
    ImprimirCanvas(telaA);
    std::cout << "Tela B:" << std::endl;
    ImprimirCanvas(telaB);
    
    // Sobrepoe os canvas
    SobreporCanvas(telaResultado, telaA, telaB);
    std::cout << "Canvas sobrepostos:" << std::endl;
    ImprimirCanvas(telaResultado);
    
    // Compara os canvas
    std::cout << "Comparando Tela A e Tela B:" << std::endl;
    std::cout << "Resultado -> " << (CompararCanvas(telaA, telaB) ? "Iguais" : "Diferentes") << std::endl;
    
    std::cout << "\nComparando Tela A e Tela A:" << std::endl;
    std::cout << "Resultado -> " << (CompararCanvas(telaA, telaA) ? "Iguais" : "Diferentes") << std::endl;

    // Libero toda a memória alocada
    std::cout << "Liberando a memória de todos os canvas..." << std::endl;
    DestruirCanvas(tela);
    DestruirCanvas(telaA);
    DestruirCanvas(telaB);
    DestruirCanvas(telaResultado);
    
    return 0;
}