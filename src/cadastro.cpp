/**
 * @file cadastro.cpp
 * @brief Implementação da classe Cadastro e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "cadastro.h"

using namespace std;

namespace PetFera{
	/**
	* @brief Construtor padrão da classe Cadastrar
	*/
	Cadastro::Cadastro(){}

	/**
	* @brief Destrutor padrão da classe Cadastrar
	*/
	Cadastro::~Cadastro(){}


	void Cadastro::cadastrar_funcionario(string funcao)
	{
		string aux;
		int id;
		string nome, cpf, tipo_sanguineo, especialidade;
		short idade;
		char fator_rh;

		cout << "Numero de identificação (ID): ";
		getline(cin, aux);
		id = stoi(aux);

		cout << "\nNome do funcionário: ";
		getline(cin, nome);

		cout << "\nCPF do funcionário: ";
		getline(cin, cpf);


		cout << "\nIdade do funcionário: ";
		getline(cin, aux);
		idade = stoi(aux);

		cout << "\nTipo sanguíneo do funcionário: ";
		getline(cin, tipo_sanguineo);

		cout << "\nFator RH: ";
		getline(cin, aux);
		fator_rh = aux[0];

		cout << "\nEspecialidade do funcionário: ";
		getline(cin, especialidade);

		Funcionario *novoFuncionario;

		if(funcao.compare("Tratador") == 0)
		{
			novoFuncionario = new Tratador(id, funcao, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade);

		}
		else
		{
			novoFuncionario = new Veterinario(id, funcao, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade);
		}

		m_lista_funcionario.insert(pair<int, Funcionario*>(id, novoFuncionario));

		cout << endl <<"Cadastro feito com sucesso!" << endl;
	}
	
}
