#include <iostream>
#include "gerencia.h"

using namespace PetFera;

int main(int argc, char const *argv[])
{
	/* code */

    Gerencia c;
    
    c.ler_funcionarios();
    
    // c.cadastrar_funcionario("Veterinario");

    c.exibir_funcionario(3);
    c.remover_funcionario(3);
    c.exibir_funcionario(3);

    c.cadastrar_animal("Mamifero");
    // c.exibir_animal(1);

	return 0;
}