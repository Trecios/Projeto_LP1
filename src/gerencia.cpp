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

	/**
	* @brief 	Método que cadastra funcionário pela sua função
	* @params	String funcao referente a função do funcionário
	*/
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

		shared_ptr<Funcionario> novoFuncionario;

		if(funcao.compare("Tratador") == 0)
		{
			cout << "entrou no if" << endl;
			cout << "idade: " << idade << endl;
			cout << "funcao: " << funcao << endl;

			novoFuncionario = make_shared<Tratador>(id, funcao, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade);

		}
		else if(funcao.compare("Veterinario") == 0)
		{
			novoFuncionario = make_shared<Veterinario>(id, funcao, nome, cpf, idade, tipo_sanguineo, fator_rh, especialidade);
		}

		m_lista_funcionario.insert(pair<int, shared_ptr<Funcionario>>(id, novoFuncionario));

		cout << endl <<"Cadastro feito com sucesso!" << endl;
	}

	/**
	* @brief	Métodd que busca um funcionário pelo seu ID
	* @params	Int id referente ao id de um funcionário cadastrado 
	*/
	void Gerencia::buscar_funcionario(int id)
	{
		map<int, shared_ptr<Funcionario>>::iterator func = m_lista_funcionario.find(id);
		
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
	
	/**
	* @brief	Método que remove um funcionário pelo seu ID
	* @params	Int id referente ao id de um funcionário cadastrado 
	*/
	void Gerencia::remover_funcionario(int id)
	{
		map<int, shared_ptr<Funcionario>>::iterator func =  m_lista_funcionario.find(id);

		if(func != m_lista_funcionario.end())
		{
	
			m_lista_funcionario.erase(func);
			cout << "Removido com sucesso!" << endl;
	
		}
		else
		{
			cout << "Funcionario não encontrado" << endl;
		}
	}
	
	/**
	* @brief	Método que le dados de funcionários de um aquivo .csv 
	*/
	void Gerencia::ler_funcionarios()
	{
		ifstream func;
	    func.open("data/funcionarios.csv");
	    if(func.bad())
	    {
	        cerr << "ERRO! Nao foi possivel abrir o arquivo" << endl;
	        exit(EXIT_FAILURE);
	    }
	    
	    string cabecalho, linha;
	    getline(func, cabecalho); //Para ler o cabeçalho do arquivo
	    
	    while(getline(func, linha))
	    {
	        stringstream aux(linha);
	        string id, funcao, nome, cpf, idade, tipo_sang, fator_rh, especialidade;
	        
	        getline(aux, id, ';');
	        getline(aux, funcao, ';');
	        getline(aux, nome, ';');
	        getline(aux, cpf, ';');
	        getline(aux, idade,';');
	        getline(aux, tipo_sang, ';');
	        getline(aux, fator_rh, ';');
	        getline(aux, especialidade, ';');
	        
	        if(funcao == "Veterinario")
	        {
	    		m_lista_funcionario.insert(pair<int, shared_ptr<Funcionario>>(stoi(id), make_shared<Veterinario>(stoi(id), funcao, nome, cpf, (short)stoi(idade), tipo_sang, fator_rh[0], especialidade)));
	        }
	        else
	        {
	        	m_lista_funcionario.insert(pair<int, shared_ptr<Funcionario>>(stoi(id), make_shared<Tratador>(stoi(id), funcao, nome, cpf, (short)stoi(idade), tipo_sang, fator_rh[0], especialidade)));
	        }
	    }
	    cout << endl << "Leitura bem sucedida!" << endl;
	}
}
