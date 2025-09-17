#include <iostream>
#include "canvas.hpp"

int main(){
    Canvas tela;
    
    CriarCanvas(tela, 40, 30);
    DesenharPonto(tela, 30, 28, '&', 'f');
    DesenharRetanguloPreenchido(tela, 3, 4, 10, 20, '*', 'p');
    ImprimirCanvas(tela);
    DestruirCanvas(tela);
    return 0;
}