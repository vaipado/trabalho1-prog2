#include <iostream>
#include "canvas.hpp"

int main(){
    Canvas tela;
    
    CriarCanvas(tela, 40, 30);
    DesenharPonto(tela, 30, 28, '&', 'M');
    DesenharRetanguloPreenchido(tela, 3, 4, 10, 20, '*', 'R');
    ImprimirCanvas(tela);
    DestruirCanvas(tela);
    return 0;
}