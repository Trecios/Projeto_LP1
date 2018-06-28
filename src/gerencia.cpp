/**
 * @file cadastro.cpp
 * @brief Implementação da classe Cadastro e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "gerencia.h"

using namespace std;

namespace PetFera{
	/**
	* @brief Construtor padrão da classe Cadastrar
	*/
	Gerencia::Gerencia(){}

	/**
	* @brief Destrutor padrão da classe Cadastrar
	*/
	Gerencia::~Gerencia(){}


	void Gerencia::cadastrar_funcionario(string funcao)
	{
		string aux;
		int id;
		string nome, cpf, tipo_sanguineo, especialidade;
		short idade;
		char fator_rh;

		cout << "Numero de identificação do funcionário (ID): ";
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
			cout << "entrou no if" << endl;
			cout << "idade: " << idade << endl;
			cout << "funcao: " << funcao << endl;

			novoFuncionario = new Tratador(id, funcao, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade);

		}
		else if(funcao.compare("Veterinario") == 0)
		{
			novoFuncionario = new Veterinario(id, funcao, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade);
		}

		m_lista_funcionario.insert(pair<int, Funcionario*>(id, novoFuncionario));

		cout << endl <<"Cadastro feito com sucesso!" << endl;
	}

	void Gerencia::buscar_funcionario(int id)
	{
		map<int, Funcionario*>::iterator func = m_lista_funcionario.find(id);
		
		cout << endl << m_lista_funcionario.size() << endl;

		if(func != m_lista_funcionario.end())
		{

			cout << *(func -> second);
		}
		else
		{
			cout << "Funcionario nao encontrado" << endl;
		}
	}
	
}
