#include <iostream>
#include "canvas.hpp"

int main(){
    Canvas tela;
    
    CriarCanvas(tela, 40, 30);
    ImprimirCanvas(tela);
    DestruirCanvas(tela);
    return 0;
}