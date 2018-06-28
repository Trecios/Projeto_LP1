#ifndef EXECOES_H
#define EXECOES_H


#include <stdexcept>

using std::invalid_argument;

class erroEntrada: public invalid_argument{
    public:
        erroEntrada(): invalid_argument("uso: exportar -c <classe> -v <veterinario> -t <tratador> <arquivo_saida>") {}
};

#endif
