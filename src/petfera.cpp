#include <iostream>
#include "gerencia.h"

using namespace PetFera;
using namespace std;

int main(int argc, char const *argv[])
{
    Gerencia petfera;
    
    petfera.ler_funcionarios();
    petfera.ler_animais();

    petfera.menu();

	return 0;
}
    
