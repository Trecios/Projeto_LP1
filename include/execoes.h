#ifndef EXECOES_H
#define EXECOES_H


#include <stdexcept>

using std::invalid_argument;

class ErroEntrada: public invalid_argument{
    public:
        ErroEntrada(): invalid_argument("uso: exportar -c <classe> -v <veterinario> -t <tratador> <arquivo_saida>") {}
};

class ErroLeitura: public invalid_argument{
    public:
        ErroLeitura(): invalid_argument("ERRO! Não foi possível abrir o arquivo. \nVerifique se o arquivo existe.") {}
};

#endif
