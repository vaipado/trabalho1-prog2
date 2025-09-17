#include <iostream>
#include "canvas.hpp"

int main(){
    Canvas tela;
    
    CriarCanvas(tela, 40, 30);
    DesenharPonto(tela, 30, 28, '&', 'f');
    DesenharLinha(tela, 20, 10, 20, 15, '%', 'h');
    ImprimirCanvas(tela);
    DestruirCanvas(tela);
    return 0;
}