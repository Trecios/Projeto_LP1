/**
 * @file cadastro.cpp
 * @brief Implementação da classe Cadastro e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "gerencia.h"
#include "excecoes.h"

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

        try{
            cout << "Numero de identificação do funcionário (ID): ";
            getline(cin, aux);
            if(typeid(aux) != typeid(int)) throw ErroCadastro();
            id = stoi(aux);

            cout << "\nNome do funcionário: ";
            getline(cin, nome);

            cout << "\nCPF do funcionário: ";
            getline(cin, cpf);


            cout << "\nIdade do funcionário: ";
            getline(cin, aux);
            if(typeid(aux) != typeid(int)) throw ErroCadastro();
            idade = stoi(aux);

            cout << "\nTipo sanguíneo do funcionário: ";
            getline(cin, tipo_sanguineo);

            cout << "\nFator RH: ";
            getline(cin, aux);
            fator_rh = aux[0];

            cout << "\nEspecialidade do funcionário: ";
            getline(cin, especialidade);
        }
        catch(ErroCadastro &erro){
            cout << erro.what() << endl;
        }

        shared_ptr<Funcionario> novoFuncionario;

		if(funcao.compare("Tratador") == 0)
		{

			cout << "idade: " << idade << endl;
			cout << "funcao: " << funcao << endl;

			novoFuncionario = make_shared<Tratador>(id, funcao, nome, cpf, idade, tipo_sanguineo,
                    fator_rh, especialidade);
		}
		else if(funcao.compare("Veterinario") == 0)
		{
			novoFuncionario = make_shared<Veterinario>(id, funcao, nome, cpf, idade, tipo_sanguineo, 
                    fator_rh, especialidade);
		}

		m_lista_funcionario.insert(pair<int, shared_ptr<Funcionario>>(id, novoFuncionario));

		cout << endl <<"Cadastro feito com sucesso!" << endl;
	}

	/**
	* @brief	Métodd que busca um funcionário pelo seu ID
	* @params	Int id referente ao id de um funcionário cadastrado 
	*/
	void Gerencia::exibir_funcionario(int id)
	{
		map<int, shared_ptr<Funcionario>>::iterator func = m_lista_funcionario.find(id);
		
		cout << endl << m_lista_funcionario.size() << endl;

		if(func != m_lista_funcionario.end())
		{

			cout << *(func -> second);
		}
		else
		{
			cout << "Funcionário não encontrado" << endl;
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
			cout << "Funcionário não encontrado" << endl;
		}
	}
	
	/**
	* @brief	Método que le dados de funcionários de um aquivo .csv 
	*/
	void Gerencia::ler_funcionarios()
	{
        ifstream func("data/funcionarios.csv");

        try{
    	    if(!func.is_open()) throw ErroLeitura();

            else{
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
                        m_lista_funcionario.insert(pair<int, shared_ptr<Funcionario>>(stoi(id),
                                    make_shared<Veterinario>(stoi(id), funcao, nome, cpf, (short)stoi(idade), 
                                    tipo_sang, fator_rh[0], especialidade)));
                    }
                    else
                    {
                        m_lista_funcionario.insert(pair<int, shared_ptr<Funcionario>>(stoi(id),
                                    make_shared<Tratador>(stoi(id), funcao, nome, cpf, (short)stoi(idade),
                                    tipo_sang, fator_rh[0], especialidade)));
                    }
                }
            }
        }
        catch(ErroLeitura &erro){
            cerr << erro.what() << endl;
            exit(1);
        }
	}


	/**
	* @brief	Método que cadastra um animal pela sua classe
	* @params	String classe referente a classe de um animal
	*/
	void Gerencia::cadastrar_animal(string classe)
	{
		string aux;
		int id, veterinario_resp_id, tratador_resp_id;
		string nome, nome_cientifico, dieta, batismo;
		char sexo;
		double tamanho;

        try{
            cout << "Numero de identificação do animal (ID): ";
            getline(cin, aux);
            // if(typeid(aux) != typeid(int)) throw ErroCadastro();
            id = stoi(aux);

            cout << "\nNome do animal: ";
            getline(cin, nome);

            cout << "\nNome científico do animal: ";
            getline(cin, nome_cientifico);

            cout << "\nSexo do animal: ";
            getline(cin, aux);
            sexo = aux[0];

            cout << "\nTamanho em metros do animal: ";
            getline(cin, aux);
            // if(typeid(aux) != typeid(float)) throw ErroCadastro();
            tamanho = stof(aux);

            cout << "\nDieta predominante do animal: ";
            getline(cin, dieta);

            cout << "\nVeterinário associado do animal: ";
            getline(cin, aux);
            veterinario_resp_id = stoi(aux);

            cout << "\nTratador associado do animal: ";
            getline(cin, aux);
            // if(typeid(aux) != typeid(int)) throw ErroCadastro();
            tratador_resp_id = stoi(aux);

            cout << "\nNome de batismo do animal: ";
            getline(cin, batismo);
        }
        catch(ErroCadastro &erro){
            cout << erro.what() << endl;
        }
	
		shared_ptr<Funcionario> veterinario = nullptr;
		shared_ptr<Funcionario> tratador = nullptr;

		if(m_lista_funcionario.find(veterinario_resp_id) != m_lista_funcionario.end())
		{
			veterinario = m_lista_funcionario[veterinario_resp_id];
		}

		if(m_lista_funcionario.find(tratador_resp_id) != m_lista_funcionario.end())
		{
			tratador = m_lista_funcionario[tratador_resp_id];
		}


		if(classe.compare("Anfibio") == 0)
		{
			cadastrar_anfibio(id, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, batismo);
		}
		else if(classe.compare("Ave") == 0)
		{
			cadastrar_ave(id, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, batismo);
		}
		else if(classe.compare("Mamifero") == 0)
		{
			cadastrar_mamifero(id, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, batismo);
		}
		else if(classe.compare("Reptil") == 0)
		{
			cadastrar_reptil(id, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, batismo);
		}

		cout << "Cadastro realizado com sucesso." << endl;

	}

	/**
	* @brief	Método auxiliar que cadastra um animal do tipo anfíbio
	* @params	Int id referente a id de um animal
	* @params	String nome referente a nome de um animal
	* @params	String nome_cintifico referente a nome_cintifico de um animal
	* @params	char sexo referente a sexo de um animal
	* @params	float tamanho referente a tamanho de um animal
	* @params	String dieta referente a dieta de um animal
	* @params	shared_ptr<Funcionario> veterinário referente a veterinário de um animal
	* @params	shared_ptr<Funcionario> tratador referente a tratador de um animal
	* @params	String batismo referente a batismo de um animal
	*/
	void Gerencia::cadastrar_anfibio(int id, string nome, string nome_cientifico, char sexo, float tamanho,
            string dieta, shared_ptr<Funcionario> veterinario, shared_ptr<Funcionario> tratador, string batismo)
	{
		int total_mudas;
		string aux, ultima_muda;

		cout << "\nTotal de mudas: ";
		getline(cin, aux);
		total_mudas = stoi(aux);

		cout << "\nData da ultima muda (dd/mm/aa): ";
		getline(cin, ultima_muda);

		shared_ptr<Animal> novoAnimal = make_shared<Anfibio>(id, "Amphibia", nome, nome_cientifico, sexo,
                tamanho, dieta, veterinario, tratador, batismo, total_mudas, ultima_muda);

		m_lista_animal.insert(pair<int, shared_ptr<Animal>>(id, novoAnimal));
	}

	/**
	* @brief	Método auxiliar que cadastra um animal do tipo ave
	* @params	Int id referente a id de um animal
	* @params	String nome referente a nome de um animal
	* @params	String nome_cintifico referente a nome_cintifico de um animal
	* @params	char sexo referente a sexo de um animal
	* @params	float tamanho referente a tamanho de um animal
	* @params	String dieta referente a dieta de um animal
	* @params	shared_ptr<Funcionario> veterinário referente a veterinário de um animal
	* @params	shared_ptr<Funcionario> tratador referente a tratador de um animal
	* @params	String batismo referente a batismo de um animal
	*/
	void Gerencia::cadastrar_ave(int id, string nome, string nome_cientifico, char sexo, float tamanho,
            string dieta, shared_ptr<Funcionario> veterinario, shared_ptr<Funcionario> tratador, string batismo)
	{
		int tamanho_dico, envergadura;
		string aux;

		cout << "\nTamanho do bico: ";
		getline(cin, aux);
		tamanho_dico = stoi(aux);

		cout << "\nEnvergadura: ";
		getline(cin, aux);
		envergadura = stoi(aux);

		shared_ptr<Animal> novoAnimal = make_shared<Ave>(id, "Aves", nome, nome_cientifico, sexo, tamanho,
                dieta, veterinario, tratador, batismo, tamanho_dico, envergadura);

		m_lista_animal.insert(pair<int, shared_ptr<Animal>>(id, novoAnimal));

	}

	/**
	* @brief	Método auxiliar que cadastra um animal do tipo mamífero
	* @params	Int id referente a id de um animal
	* @params	String nome referente a nome de um animal
	* @params	String nome_cintifico referente a nome_cintifico de um animal
	* @params	char sexo referente a sexo de um animal
	* @params	float tamanho referente a tamanho de um animal
	* @params	String dieta referente a dieta de um animal
	* @params	shared_ptr<Funcionario> veterinário referente a veterinário de um animal
	* @params	shared_ptr<Funcionario> tratador referente a tratador de um animal
	* @params	String batismo referente a batismo de um animal
	*/
	void Gerencia::cadastrar_mamifero(int id, string nome, string nome_cientifico, char sexo, float tamanho,
            string dieta, shared_ptr<Funcionario> veterinario, shared_ptr<Funcionario> tratador, string batismo)
	{
		string aux, cor;

		cout << "\nCor predominante: ";
		getline(cin, cor);

		shared_ptr<Animal> novoAnimal = make_shared<Mamifero>(id, "Mammalia", nome, nome_cientifico, sexo,
                tamanho, dieta, veterinario, tratador, batismo, cor);

		m_lista_animal.insert(pair<int, shared_ptr<Animal>>(id, novoAnimal));
	}

	/**
	* @brief	Método auxiliar que cadastra um animal do tipo réptil
	* @params	Int id referente a id de um animal
	* @params	String nome referente a nome de um animal
	* @params	String nome_cintifico referente a nome_cintifico de um animal
	* @params	char sexo referente a sexo de um animal
	* @params	float tamanho referente a tamanho de um animal
	* @params	String dieta referente a dieta de um animal
	* @params	shared_ptr<Funcionario> veterinário referente a veterinário de um animal
	* @params	shared_ptr<Funcionario> tratador referente a tratador de um animal
	* @params	String batismo referente a batismo de um animal
	*/
	void Gerencia::cadastrar_reptil(int id, string nome, string nome_cientifico, char sexo, float tamanho,
            string dieta, shared_ptr<Funcionario> veterinario, shared_ptr<Funcionario> tratador, string batismo)
	{
		string aux, venenoso, tipo_veneno;
		bool eh_venenoso = false;

		cout << "\nAnimal venenoso (sim ou não): ";
		getline(cin, venenoso);

		if(venenoso.compare("sim") == 0)
		{
			eh_venenoso = true;
			cout << "\nTipo do veneno: ";
			getline(cin, tipo_veneno);
		}
		else
		{
			tipo_veneno = "Nenhum";
		}

		shared_ptr<Animal> novoAnimal = make_shared<Reptil>(id, "Reptilia", nome, nome_cientifico, sexo,
                tamanho, dieta, veterinario, tratador, batismo, eh_venenoso, tipo_veneno);

		m_lista_animal.insert(pair<int, shared_ptr<Animal>>(id, novoAnimal));
	}

	/**
	* @brief	Método que exibe um animal pelo seu ID
	* @params	Int id referente ao id de um animal cadastrado 
	*/
	void Gerencia::exibir_animal(int id)
	{
		map<int, shared_ptr<Animal>>::iterator animal = m_lista_animal.find(id);
		
		cout << endl << m_lista_animal.size() << endl;

		if(animal != m_lista_animal.end())
		{

			cout << *(animal -> second);
		}
		else
		{
			cout << "Animal nao encontrado" << endl;
		}
	}

	/**
	* @brief	Método que remove um animal pelo seu ID
	* @params	Int id referente ao id de um animal cadastrado 
	*/
	void Gerencia::remover_animal(int id)
	{
		map<int, shared_ptr<Animal>>::iterator animal =  m_lista_animal.find(id);

		if(animal != m_lista_animal.end())
		{
			m_lista_animal.erase(animal);
			cout << "Removido com sucesso!" << endl;
		}
		else
		{
            cout << "Animal não encontrado" << endl;
		}
	}

	/**
	* @brief	Método que exibe todos os funcionários cadastrados.
	*/
	void Gerencia::listar_funcionarios()
	{
		cout << "-----------------------------" << endl;
		for(auto i  = m_lista_funcionario.begin(); i != m_lista_funcionario.end(); i++)
		{
			cout << "ID: " << (i->second)->getId() << endl 
			<< "Nome: " << (i->second)->getNome() << endl
			<< "Funcao: " << (i->second)->getFuncao() << endl
			<< "Especialidade: " << (i->second)->getEspecialidade() << endl
			<< "-----------------------------" << endl;
		}
	}

	/**
	* @brief	Método que consulta todos os animais de uma determinada classe
	* @params	String classe referente a classe dos animais. 
	*/
	void Gerencia::consultar_animaisClasse(string classe)
	{
		string buscada = "";
		bool achou = false;
		if(classe.compare("Anfibio") == 0 || classe.compare("Amphibia") == 0)
		{
			buscada = "Amphibia";
		}
		else if(classe.compare("Ave") == 0 || classe.compare("Aves") == 0)
		{
			buscada = "Aves";
		}
		else if(classe.compare("Mamifero") == 0 || classe.compare("Mammalia") == 0)
		{
			buscada = "Mammalia";
		}
		else if(classe.compare("Reptil") == 0 ||classe.compare("Reptilia") == 0)
		{
			buscada = "Reptilia";
		}
		
		if(!buscada.compare("") == 0)
		{
			achou = true;
		}
		
		if(achou)
		{
			for(auto i  = m_lista_animal.begin(); i != m_lista_animal.end(); i++)
			{
				if((i->second)->getClasse().compare(buscada) == 0)
				{
					cout << *(i->second);
				}
			}
		}
		else
		{
			cout << "Erro! " << classe << " nao eh uma classe valida." << endl;
		}
	}


	/**
	* @brief	Método que consulta todos os animais sob responsabilidade de 
	* determinado funcionário, a consulta é pelo ID do funcionário.
	* @params	Int id referente ao id do funcionário. 
	*/
	void Gerencia::consultar_animaisResp(int id)
	{
		for(auto i  = m_lista_animal.begin(); i != m_lista_animal.end(); i++)
		{
			if((i->second)->getVeterinario()->getId() == id || (i->second)->getTratador()->getId() == id)
			{
				cout << *(i->second);
			}
		}
	}

}
