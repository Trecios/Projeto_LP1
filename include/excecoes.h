#ifndef EXCECOES_H
#define EXCECOES_H


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

class ErroMenu: public invalid_argument{
    public:
        ErroMenu(): invalid_argument("\nERRO! Entrada invalida. \nVerifique o menu abaixo. \n\n") {}
};

class ErroCadastro: public invalid_argument{
    public:
        ErroCadastro(): invalid_argument("ERRO! Este campo e obrigatório.\nEntre com um valor válido.\n") {}
};

class ErroBuscaClasse: public invalid_argument{
    public:
        ErroBuscaClasse(): invalid_argument("Erro! Classe não encontrada.\nVerifique a classe informada.\n") {}
};

#endif
