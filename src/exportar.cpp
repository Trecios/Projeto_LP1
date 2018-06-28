#include <iostream>
#include <string>
#include "execoes.h"

using namespace std;

int main(int argc, char const *argv[]){
    string classe, veterinario, tratador, saida;

    try{
        // Checa se não foi passado parâmetros ou se o único parâmetro foi o "-h"(help).
        if(argc == 1) throw erroEntrada();
        if(argv[1] == string("-h")) throw erroEntrada();

        else{
            // Percorre o array argv é armazena os devidos parâmetros nas variáveis para chamar o
            // método imprimir.
            for(int i = 1; i < argc; i ++){
                if(argv[i] == string("-c")) classe = argv[i + 1];
                else if(argv[i] == string("-v")) veterinario = argv[i + 1];
                else if(argv[i] == string("-t")){
                    tratador = argv[i + 1];
                    // Caso o valor de (i + 3) seja maior que o argc mostra que não foi passado o
                    // ultimo parâmetro, no caso o de arquivo de saída e assim e chamada a exceção.
                    if((i + 3) > argc) throw erroEntrada();
                    else saida = argv[i + 2];
                }
            }
            // Checa se todos os parârametros foram passados.
            if(classe == "" || veterinario == "" || tratador == "" ) throw erroEntrada();
        }
    }
    catch(erroEntrada &ex){
        cerr << ex.what() << endl;
        exit(1);
    }
    
    // Chama imprimir

    return 0;
}
