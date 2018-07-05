#include <iostream>
#include "gerencia.h"
#include "excecoes.h"

using namespace PetFera;
using namespace std;

int main(int argc, char const *argv[])
{
    Gerencia c;
    
    c.ler_funcionarios();
//    c.ler_animal();

    c.menu();

	return 0;
}
    
