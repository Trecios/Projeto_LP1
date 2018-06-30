#include <iostream>
#include "gerencia.h"

using namespace PetFera;

int main(int argc, char const *argv[])
{
	/* code */
    Gerencia c;
    
    c.ler_funcionarios();
    
    // c.cadastrar_funcionario("Veterinario");

    c.buscar_funcionario(3);
    c.remover_funcionario(3);
    c.buscar_funcionario(3);
    

	return 0;
}
