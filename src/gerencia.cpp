/**
 * @file gerencia.cpp
 * @brief Implementação da classe Gerencia e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "gerencia.h"
#include "excecoes.h"

using namespace std;

namespace PetFera{

	/**
	* @brief Construtor padrão da classe Gerencia.
	*/
	Gerencia::Gerencia(){}

	/**
	* @brief Destrutor padrão da classe Gerencia.
	*/
	Gerencia::~Gerencia(){}

	/**
	* @brief 	Método que cadastra funcionário pela sua função.
	* @params	String funcao referente a função do funcionário (Veterinário ou Tratador).
	*/
	void Gerencia::cadastrar_funcionario(string funcao_)
	{
        string aux;
	    int id;
	    string nome, cpf, tipo_sanguineo, especialidade;
	    short idade;
	    char fator_rh;
        bool flag;

        do{
            cout << "\nNumero de identificação do funcionário (ID): ";
            getline(cin, aux);
            try{
                id = stoi(aux);
                flag = true;
            }
            catch(invalid_argument &erro){
                cout << "Entrada invalida. Informe um valor inteiro." << endl << endl;
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nNome do funcionário: ";
            getline(cin, nome);
            try{
                if(nome.size() == 0) throw ErroCadastro();
                flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nCPF do funcionário: ";
            getline(cin, cpf);
            try{
                if(nome.size() == 0) throw ErroCadastro();
                flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nIdade do funcionário: ";
            getline(cin, aux);
            try{
                idade = stoi(aux);
                flag = true;
            }
            catch(invalid_argument &erro){
                cout << "Entrada invalida. Informe um valor inteiro." << endl << endl;
                cin.clear();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nTipo sanguíneo do funcionário: ";
            getline(cin, tipo_sanguineo);
            try{
                if(tipo_sanguineo.size() == 0) throw ErroCadastro();
                flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nFator RH: ";
            getline(cin, aux);
            fator_rh = aux[0];
            try{
                if(sizeof(fator_rh) == 0) throw ErroCadastro();
                flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nEspecialidade do funcionário: ";
            getline(cin, especialidade);
            try{
                if(especialidade.size() == 0) throw ErroCadastro();
                flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

        shared_ptr<Funcionario> novoFuncionario;

        if(funcao_.compare("Tratador") == 0)
        {
            novoFuncionario = make_shared<Tratador>(id, funcao_, nome, cpf, idade, tipo_sanguineo,
                    fator_rh, especialidade);
		}
        else if(funcao_.compare("Veterinario") == 0)
        {
            novoFuncionario = make_shared<Veterinario>(id, funcao_, nome, cpf, idade, tipo_sanguineo, 
                    fator_rh, especialidade);
        }

        m_lista_funcionario.insert(pair<int, shared_ptr<Funcionario>>(id, novoFuncionario));

        exibir_funcionario(id);
	}

	/**
	* @brief	Método que busca um funcionário pelo seu ID.
	* @params	Int id referente ao id de um funcionário cadastrado .
	*/
	void Gerencia::exibir_funcionario(int id_)
	{
        map<int, shared_ptr<Funcionario>>::iterator func = m_lista_funcionario.find(id_);
		
        try{
    	    if(func != m_lista_funcionario.end())
	        {
	            cout << *(func -> second);
	        }
    	    else throw ErroBuscaFuncionario();
	    }
        catch(ErroBuscaFuncionario &erro){
            cout << erro.what();
        }
	}
	
	/**
	* @brief	Método que remove um funcionário pelo seu ID
	* @params	Int id referente ao id de um funcionário cadastrado 
	*/
	void Gerencia::remover_funcionario(int id)
	{
	    map<int, shared_ptr<Funcionario>>::iterator func =  m_lista_funcionario.find(id);

        try{
            if(func != m_lista_funcionario.end())
	        {
	            m_lista_funcionario.erase(func);
	            cout << "Removido com sucesso!" << endl;
            }
    	    else throw ErroBuscaFuncionario();
	    }
        catch(ErroBuscaFuncionario &erro){
            cout << erro.what();
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
        bool flag;

        do{
            cout << "\nNumero de identificação do animal (ID): ";
            getline(cin, aux);
            try{
                id = stoi(aux);
                flag = true;
            }
            catch(invalid_argument &erro){
                cout << "Entrada invalida. Informe um valor inteiro." << endl << endl;
                cin.clear();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nNome do animal: ";
            getline(cin, nome);
            try{
                if(nome.size() == 0) throw ErroCadastro();
                    flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nNome científico do animal: ";
            getline(cin, nome_cientifico);
            try{
                if(nome.size() == 0) throw ErroCadastro();
                flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nSexo do animal: ";
            getline(cin, aux);
            sexo = aux[0];
            try{
                if(aux.size() == 0) throw ErroCadastro();
                flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nTamanho em metros do animal: ";
            getline(cin, aux);
            try{
                tamanho = stof(aux);
                flag = true;
            }
            catch(invalid_argument &erro){
                cout << "Entrada invalida. Informe um valor decimal ou inteiro." << endl;
                cin.clear();
                flag = false;
            }
        }while(!flag);

        cout << "\nDieta predominante do animal: ";
        getline(cin, dieta);

        do{
            cout << "\nVeterinário associado do animal: ";
            getline(cin, aux);
            try{
                veterinario_resp_id = stoi(aux);
                flag = true;
            }
            catch(invalid_argument &erro){
                cout << "Entrada invalida. Informe um valor inteiro." << endl;
                cin.clear();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nTratador associado do animal: ";
            getline(cin, aux);
            try{
                tratador_resp_id = stoi(aux);
                flag = true;
            }
            catch(invalid_argument &erro){
                cout << "Entrada invalida. Informe um valor inteiro." << endl;
                cin.clear();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nNome de batismo do animal: ";
            getline(cin, batismo);
            try{
                if(batismo.size() == 0) throw ErroCadastro();
                flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

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

        if(classe.compare("anfibio_exotico") == 0 || classe.compare("anfibio_nativo") == 0)
	    {
	        cadastrar_anfibio(id, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, 
                    batismo, classe);
	    }
	    else if(classe.compare("ave_exotica") == 0 || classe.compare("ave_nativa") == 0)
	    {
	        cadastrar_ave(id, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, 
                    batismo, classe);
	    }
	    else if(classe.compare("mamifero_exotico") == 0 || classe.compare("mamifero_nativo") == 0)
	    {
	        cadastrar_mamifero(id, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador,
                    batismo, classe);
	    }
	    else if(classe.compare("reptil_exotico") == 0 || classe.compare("reptil_nativo") == 0)
	    {
	        cadastrar_reptil(id, nome, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador,
                        batismo, classe);
	    }

	    cout << "Cadastro realizado com sucesso." << endl;
        exibir_animal(id);
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
	void Gerencia::cadastrar_anfibio(int id_, string nome_, string nome_cientifico_, char sexo_, 
            float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_, 
            shared_ptr<Funcionario> tratador_, string batismo_, string classe_)
	{
	    int total_mudas;
	    string aux, ultima_muda, ibama;
        bool flag;

        do{
            cout << "\nTotal de mudas: ";
            getline(cin, aux);
            try{
                total_mudas = stoi(aux);
                flag = true;
            }
            catch(invalid_argument &erro){
                cout << "Entrada invalida. Informe um valor inteiro." << endl;
                cin.clear();
                flag = false;
            }
        }while(!flag);

	    cout << "\nData da ultima muda (dd/mm/aa): ";
	    getline(cin, ultima_muda);

        do{
            cout << "\nIbama: ";
            getline(cin, ibama);
            try{
                if(ibama.size() == 0) throw ErroCadastro();
                flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

        if(classe_.compare("anfibio_exotico") == 0){
            string pais_origem;

            do{
                cout << "\nPais de Origem: ";
                getline(cin, pais_origem);
                try{
                    if(pais_origem.size() == 0) throw ErroCadastro();
                    flag = true;
                }
                catch(ErroCadastro &erro){
                    cout << erro.what();
                    flag = false;
                }
            }while(!flag);

            shared_ptr<Animal> novoAnimal = make_shared<AnfibioExotico>(id_, "Amphibia", nome_,
                nome_cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_,
                total_mudas, ultima_muda, ibama, pais_origem);

	        m_lista_animal.insert(pair<int, shared_ptr<Animal>>(id_, novoAnimal));
        }

        else if(classe_.compare("anfibio_nativo") == 0){
            string uf_origem, autorizacao;

            do{
                cout << "\nUF de origem: ";
                getline(cin, uf_origem);
                try{
                    if(uf_origem.size() == 0) throw ErroCadastro();
                    flag = true;
                }
                catch(ErroCadastro &erro){
                    cout << erro.what();
                    flag = false;
                }
            }while(!flag);

            do{
                cout << "\nAutorização: ";
                getline(cin, autorizacao);
                try{
                    if(autorizacao.size() == 0) throw ErroCadastro();
                    flag = true;
                }
                catch(ErroCadastro &erro){
                    cout << erro.what();
                    flag = false;
                }
            }while(!flag);

            shared_ptr<Animal> novoAnimal = make_shared<AnfibioNativo>(id_, "Amphibia", nome_,
                nome_cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_,
                total_mudas, ultima_muda, ibama, uf_origem, autorizacao);

	        m_lista_animal.insert(pair<int, shared_ptr<Animal>>(id_, novoAnimal));
        }

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
	void Gerencia::cadastrar_ave(int id_, string nome_, string nome_cientifico_, char sexo_, float tamanho_,
            string dieta_, shared_ptr<Funcionario> veterinario_, shared_ptr<Funcionario> tratador_,
            string batismo_, string classe_)
	{
	    int tamanho_bico, envergadura;
	    string aux, ibama;
        bool flag;

        do{
            cout << "\nTamanho do bico: ";
            getline(cin, aux);
            try{
	            tamanho_bico = stoi(aux);
                flag = true;
            }
            catch(invalid_argument &erro){
                cout << "Entrada invalida. Informe um valor inteiro." << endl;
                cin.clear();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nEnvergadura: ";
            getline(cin, aux);
            try{
    	        envergadura = stoi(aux);
                flag = true;
            }
            catch(invalid_argument &erro){
                cout << "Entrada invalida. Informe um valor inteiro." << endl;
                cin.clear();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nIbama: ";
            getline(cin, ibama);
            try{
                if(ibama.size() == 0) throw ErroCadastro();
                flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

        if(classe_.compare("ave_exotico") == 0){
            string pais_origem;

            do{
                cout << "\nPais de Origem: ";
                getline(cin, pais_origem);
                try{
                    if(pais_origem.size() == 0) throw ErroCadastro();
                    flag = true;
                }
                catch(ErroCadastro &erro){
                    cout << erro.what();
                    flag = false;
                }
            }while(!flag);

            shared_ptr<Animal> novoAnimal = make_shared<AveExotica>(id_, "Ave", nome_,
                nome_cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_,
                tamanho_bico, envergadura, ibama, pais_origem);

	        m_lista_animal.insert(pair<int, shared_ptr<Animal>>(id_, novoAnimal));
        }

        else if(classe_.compare("ave_nativo") == 0){
            string uf_origem, autorizacao;

            do{
                cout << "\nUF de origem: ";
                getline(cin, uf_origem);
                try{
                    if(uf_origem.size() == 0) throw ErroCadastro();
                    flag = true;
                }
                catch(ErroCadastro &erro){
                    cout << erro.what();
                    flag = false;
                }
            }while(!flag);

            do{
                cout << "\nAutorização: ";
                getline(cin, autorizacao);
                try{
                    if(autorizacao.size() == 0) throw ErroCadastro();
                    flag = true;
                }
                catch(ErroCadastro &erro){
                    cout << erro.what();
                    flag = false;
                }
            }while(!flag);

            shared_ptr<Animal> novoAnimal = make_shared<AveNativa>(id_, "Aves", nome_,
                nome_cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_,
                tamanho_bico, envergadura, ibama, uf_origem, autorizacao);

	        m_lista_animal.insert(pair<int, shared_ptr<Animal>>(id_, novoAnimal));
        }

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
	void Gerencia::cadastrar_mamifero(int id_, string nome_, string nome_cientifico_, char sexo_, 
            float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_, 
            shared_ptr<Funcionario> tratador_, string batismo_, string classe_)
	{
	    string aux, cor, ibama;
        bool flag;

        do{
            cout << "\nCor predominante: ";
	        getline(cin, cor);
            try{
                if(cor.size() == 0) throw ErroCadastro();
                flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

        do{
            cout << "\nIbama: ";
            getline(cin, ibama);
            try{
                if(ibama.size() == 0) throw ErroCadastro();
                flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

        if(classe_.compare("mamifero_exotico") == 0){
            string pais_origem;

            do{
                cout << "\nPais de Origem: ";
                getline(cin, pais_origem);
                try{
                    if(pais_origem.size() == 0) throw ErroCadastro();
                    flag = true;
                }
                catch(ErroCadastro &erro){
                    cout << erro.what();
                    flag = false;
                }
            }while(!flag);

            shared_ptr<Animal> novoAnimal = make_shared<MamiferoExotico>(id_, "Mammalia", nome_,
                nome_cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_,
                cor, ibama, pais_origem);

	        m_lista_animal.insert(pair<int, shared_ptr<Animal>>(id_, novoAnimal));
        }

        else if(classe_.compare("mamifero_nativo") == 0){
            string uf_origem, autorizacao;

            do{
                cout << "\nUF de origem: ";
                getline(cin, uf_origem);
                try{
                    if(uf_origem.size() == 0) throw ErroCadastro();
                    flag = true;
                }
                catch(ErroCadastro &erro){
                    cout << erro.what();
                    flag = false;
                }
            }while(!flag);

            do{
                cout << "\nAutorização: ";
                getline(cin, autorizacao);
                try{
                    if(autorizacao.size() == 0) throw ErroCadastro();
                    flag = true;
                }
                catch(ErroCadastro &erro){
                    cout << erro.what();
                    flag = false;
                }
            }while(!flag);

            shared_ptr<Animal> novoAnimal = make_shared<MamiferoNativo>(id_, "Mammalia", nome_,
                nome_cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_,
                cor, ibama, uf_origem, autorizacao);

	        m_lista_animal.insert(pair<int, shared_ptr<Animal>>(id_, novoAnimal));
        }

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
	void Gerencia::cadastrar_reptil(int id_, string nome_, string nome_cientifico_, char sexo_,
            float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
            shared_ptr<Funcionario> tratador_, string batismo_, string classe_)
	{
	    string aux, venenoso, tipo_veneno, ibama;
	    bool eh_venenoso = false, flag;

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

        do{
            cout << "\nIbama: ";
            getline(cin, ibama);
            try{
                if(ibama.size() == 0) throw ErroCadastro();
                flag = true;
            }
            catch(ErroCadastro &erro){
                cout << erro.what();
                flag = false;
            }
        }while(!flag);

        if(classe_.compare("reptil_exotico") == 0){
            string pais_origem;

            do{
                cout << "\nPais de Origem: ";
                getline(cin, pais_origem);
                try{
                    if(pais_origem.size() == 0) throw ErroCadastro();
                    flag = true;
                }
                catch(ErroCadastro &erro){
                    cout << erro.what();
                    flag = false;
                }
            }while(!flag);
    
            shared_ptr<Animal> novoAnimal = make_shared<ReptilExotico>(id_, "Reptilia", nome_,
                nome_cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_,
                eh_venenoso, tipo_veneno, ibama, pais_origem);

	        m_lista_animal.insert(pair<int, shared_ptr<Animal>>(id_, novoAnimal));
        }

        else if(classe_.compare("reptil_nativo") == 0){
            string uf_origem, autorizacao;

            do{
                cout << "\nUF de origem: ";
                getline(cin, uf_origem);
                try{
                    if(uf_origem.size() == 0) throw ErroCadastro();
                    flag = true;
                }
                catch(ErroCadastro &erro){
                    cout << erro.what();
                    flag = false;
                }
            }while(!flag);

            do{
                cout << "\nAutorização: ";
                getline(cin, autorizacao);
                try{
                    if(autorizacao.size() == 0) throw ErroCadastro();
                    flag = true;
                }
                catch(ErroCadastro &erro){
                    cout << erro.what();
                    flag = false;
                }
            }while(!flag);

            shared_ptr<Animal> novoAnimal = make_shared<ReptilNativo>(id_, "Reptilia", nome_,
                nome_cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_,
                eh_venenoso, tipo_veneno, ibama, uf_origem, autorizacao);

	        m_lista_animal.insert(pair<int, shared_ptr<Animal>>(id_, novoAnimal));

        }

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
	        cout << "Animal não encontrado" << endl;
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
	        << "Função: " << (i->second)->getFuncao() << endl
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

        try{
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
            else throw ErroBuscaClasse();
        }
        catch(ErroBuscaClasse &erro){
            cout << erro.what();
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

    void Gerencia::menu(){
        int op, op_aux;
    
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

                    if((op < 0x47 && op > 0x58) || op > 4) throw ErroMenu();

                switch(op){
                    case 1:
                        cout << "Digite o ID do funcionário: ";
                        cin >> op_aux;
                        exibir_funcionario(op_aux);
                        break;
                    case 2:
                        cout << "Digite o ID do animal: ";
                        cin >> op_aux;
                        exibir_animal(op_aux);
                        break;
                    case 3:
                        do{
                            try{
                                cout << "+========== Cadastro de Funcionário ===========+" << endl
                                     << "| 1) Veterinário.                              |" << endl
                                     << "| 2) Tratador.                                 |" << endl
                                     << "| 0) Sair.                                     |" << endl
                                     << "+==============================================+" << endl
                                     << "\nDigite sua opção: "                             ;
                                cin >> op_aux;
                                cin.ignore(1, '\n'); 
                                // Ignora o cach do cin, se não quando chamar o cadastro_funcionario
                                // e assim apresenta erro de tecla invalida.
                                if((op_aux < 0x47 && op_aux > 0x58) || op_aux > 2) throw ErroMenu();
                            }
                            catch(ErroMenu &erro){
                                cout << erro.what();
                            }

                            switch(op_aux){
                                case 1:
                                    cadastrar_funcionario("Veterinario");
                                    break;
                                case 2:
                                    cadastrar_funcionario("Tratador");
                                    break;
                                }
                        }while(op_aux != 0);
                        break;
                    case 4:
                        do{
                            try{
                                cout << "+============ Cadastro de Animal ==============+" << endl
                                     << "| 1) Anfíbio Exótico.                          |" << endl
                                     << "| 2) Anfíbio Nativo.                           |" << endl
                                     << "| 3) Ave Exótica.                              |" << endl
                                     << "| 4) Ave Nativa.                               |" << endl
                                     << "| 5) Mamífero Exótico.                         |" << endl
                                     << "| 6) Mamífero Nativo.                          |" << endl
                                     << "| 7) Réptil Exótico.                           |" << endl
                                     << "| 8) Réptil Nativo.                            |" << endl
                                     << "| 0) Sair.                                     |" << endl
                                     << "+==============================================+" << endl
                                     << "\nDigite sua opção: "                             ;
                                cin >> op_aux;
                                cin.ignore(1, '\n'); 
                                // Ignora o cach do cin, se não quando chamar o cadastro_animal
                                // e assim apresenta erro de tecla invalida.
                                if((op_aux < 0x47 && op_aux > 0x58) || op_aux > 8) throw ErroMenu();
                            }
                            catch(ErroMenu &erro){
                                cout << erro.what();
                            }

                            switch(op_aux){
                                case 1:
                                    cadastrar_animal("anfibio_exotico");
                                    break;
                                case 2:
                                    cadastrar_animal("anfibio_nativo");
                                    break;
                                case 3:
                                    cadastrar_animal("ave_exotica");
                                    break;
                                case 4:
                                    cadastrar_animal("ave_nativa");
                                    break;
                                case 5:
                                    cadastrar_animal("mamifero_exotico");
                                    break;
                                case 6:
                                    cadastrar_animal("mamifero_nativo");
                                    break;
                                case 7:
                                    cadastrar_animal("reptil_exotico");
                                    break;
                                case 8:
                                    cadastrar_animal("reptil_nativo");
                                    break;
                                }
                        }while(op_aux != 0);
                        break;
                }
            }
            catch(ErroMenu &erro){
                cout << erro.what() << endl;
            }

        }while(op != 0);
    }
}
