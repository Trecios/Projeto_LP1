#include <iostream>
#include "gerencia.h"
#include "excecoes.h"

using namespace PetFera;
using namespace std;

int main(int argc, char const *argv[])
{
	/* code */
    int op;
    Gerencia c;
    
    c.ler_funcionarios();

    do{
        cout << "+=============== Menu de Opções ==============+" << endl
             << "| 1) Busca de Funcionário.                    |" << endl
             << "| 2) Busca de Animal.                         |" << endl
             << "| 3) Cadastro de Funcionário.                 |" << endl
             << "| 4) Cadastro de Animal.                      |" << endl
             << "| 0) Sair.                                    |" << endl
             << "+=============================================+" << endl
             << "\nDigite sua opção: "                            ;

        try{
            cin >> op;

            if(op < 0 || op > 4) throw ErroMenu(); // Se for digitado letra, não acusa erro. Tentar tratar.

            switch(op){
                case 1:
                    // busca funcionário.
                    break;
                case 2:
                    // busca animal.
                    break;
                case 3:
                    // cadastro funcionario.
                    break;
                case 4:
                    // cadastro animal.
                    break;
            }
        }
        catch(ErroMenu &erro){
            cerr << erro.what() << endl;
        }

    }while(op != 0);
    
    // c.cadastrar_funcionario("Veterinario");

    c.exibir_funcionario(3);
    c.remover_funcionario(3);
    c.exibir_funcionario(3);

    c.cadastrar_animal("Mamifero");
    // c.exibir_animal(1);

	return 0;
}
