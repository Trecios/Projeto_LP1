#include <iostream>
#include "gerencia.h"

using namespace PetFera;

int main(int argc, char const *argv[])
{
	/* code */
    cout << "OK" << endl;

    Gerencia c;
    
    c.cadastrar_funcionario("Veterinario");

    c.buscar_funcionario(3);

	return 0;
}