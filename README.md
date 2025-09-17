# Trabalho Prático 1 - Canvas

## Descrição do Projeto
Este trabalho consiste em implementar um Tipo Abstrato de Dados (TAD) Canvas para representar uma tela retangular de caracteres. A memória para as matrizes de caracteres e cores é alocada dinamicamente, permitindo que as dimensões da tela sejam definidas em tempo de execução. O programa deve ser modularizado com a definição do TAD em um arquivo de cabeçalho (.hpp) e a implementação em um arquivo de código (.cpp).

## Funcionalidades
O TAD Canvas implementa as seguintes funcionalidades:

* CriarCanvas: Aloca e inicializa o canvas.

* DesenharPonto: Altera um ponto específico na tela.

* DesenharLinha: Desenha linhas horizontais e verticais.

* DesenharRetangulo: Desenha as bordas de um retângulo.

* DesenharRetanguloPreenchido: Desenha um retângulo sólido.

* RedimensionarCanvas: Altera as dimensões da tela, preservando o conteúdo original.

* SobreporCanvas: Combina duas telas em uma.

* CompararCanvas: Verifica se duas telas são idênticas.

* DestruirCanvas: Libera toda a memória alocada.

## Como compilar e rodar
Para compilar o programa, use o seguinte comando no terminal:


`g++ main.cpp canvas.cpp -o canvas_executavel`

Para executar, rode:


`./canvas_executavel`
