/**
 * @file cadastro.h
 * @brief Declaração da classe Cadastro e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef GERENCIA_H
#define GERENCIA_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <memory>
#include <string>

#include "animal.h"
#include "anfibio_exotico.h"
#include "anfibio_nativo.h"
#include "ave_exotica.h"
#include "ave_nativa.h"
#include "mamifero_exotico.h"
#include "mamifero_nativo.h"
#include "reptil_exotico.h"
#include "reptil_nativo.h"
#include "funcionario.h"
#include "tratador.h"
#include "veterinario.h"

using namespace std;

namespace PetFera{
	class Gerencia
	{
        protected:
	        map<int, shared_ptr<Animal>> m_lista_animal;
			map<int, shared_ptr<Funcionario>> m_lista_funcionario;

		public:
			/**
			 * @brief Construtor padrão da classe Cadastrar
			 */
			Gerencia();

			/**
			 * @brief Destrutor padrão da classe Cadastrar
			 */
			~Gerencia();
			
			/**
			* @brief 	Método que cadastra funcionário pela sua função
			* @params	String funcao referente a função do funcionário
			*/
			void cadastrar_funcionario(string funcao_);

			/**
			* @brief	Método que exibe um funcionário pelo seu ID
			* @params	Int id referente ao id de um funcionário cadastrado 
			*/
			void exibir_funcionario(int id_);
			
			/**
			* @brief	Método que remove um funcionário pelo seu ID
			* @params	Int id referente ao id de um funcionário cadastrado 
			*/
			void remover_funcionario(int id_);
			
			/**
			* @brief	Método que le dados de funcionários de um aquivo .csv 
			*/
			void ler_funcionarios();

			/**
		    * @brief	Método que le dados de funcionários de um aquivo .csv 
		    */
			void ler_animais();

			/**
			* @brief	Método que cadastra um animal pela sua classe
			* @params	String classe referente a classe de um animal
			*/
			void cadastrar_animal(string classe_);

			/**
			* @brief	Método auxiliar que cadastra um animal do tipo anfíbio.
			* @params	Int id referente a id de um animal.
			* @params	String nome referente a nome de um animal.
			* @params	String nome_cintifico referente a nome_cintifico de um animal.
			* @params	char sexo referente a sexo de um animal.
			* @params	float tamanho referente a tamanho de um animal.
			* @params	String dieta referente a dieta de um animal.
			* @params	shared_ptr<Funcionario> veterinario referente a veterinário de um animal.
			* @params	shared_ptr<Funcionario> tratador referente a tratador de um animal.
			* @params	String batismo referente a batismo de um animal.
            * @params   String classe_ refente a classe de um animal.
			*/
			void cadastrar_anfibio(int id_, string nome_, string nome_cientifico_, char sexo_, float tamanho_,
                    string dieta_, shared_ptr<Funcionario> veterinario_, shared_ptr<Funcionario> tratador_,
                    string batismo_, string classe_);

			/**
			* @brief	Método auxiliar que cadastra um animal do tipo ave
			* @params	Int id referente a id de um animal
			* @params	String nome referente a nome de um animal
			* @params	String nome_cintifico referente a nome_cintifico de um animal
			* @params	char sexo referente a sexo de um animal
			* @params	float tamanho referente a tamanho de um animal
			* @params	String dieta referente a dieta de um animal
			* @params	shared_ptr<Funcionario> veterinario referente a veterinario de um animal
			* @params	shared_ptr<Funcionario> tratador referente a tratador de um animal
			* @params	String batismo referente a batismo de um animal
			* @params   String classe_ refente a classe de um animal.
            */
			void cadastrar_ave(int id_, string nome_, string nome_cientifico_, char sexo_, float tamanho_,
                    string dieta_, shared_ptr<Funcionario> veterinario_, shared_ptr<Funcionario> tratador_,
                    string batismo_, string classe_);

			/**
			* @brief	Método auxiliar que cadastra um animal do tipo mamifero
			* @params	Int id referente a id de um animal
			* @params	String nome referente a nome de um animal
			* @params	String nome_cintifico referente a nome_cintifico de um animal
			* @params	char sexo referente a sexo de um animal
			* @params	float tamanho referente a tamanho de um animal
			* @params	String dieta referente a dieta de um animal
			* @params	shared_ptr<Funcionario> veterinario referente a veterinario de um animal
			* @params	shared_ptr<Funcionario> tratador referente a tratador de um animal
			* @params	String batismo referente a batismo de um animal
            * @params   String classe_ refente a classe de um animal.
			*/
			void cadastrar_mamifero(int id_, string nome_, string nome_cientifico_, char sexo_, float tamanho_,
                    string dieta_, shared_ptr<Funcionario> veterinario_, shared_ptr<Funcionario> tratador_,
                    string batismo_, string classe_);

			/**
			* @brief	Método auxiliar que cadastra um animal do tipo reptil
			* @params	Int id referente a id de um animal
			* @params	String nome referente a nome de um animal
			* @params	String nome_cintifico referente a nome_cintifico de um animal
			* @params	char sexo referente a sexo de um animal
			* @params	float tamanho referente a tamanho de um animal
			* @params	String dieta referente a dieta de um animal
			* @params	shared_ptr<Funcionario> veterinario referente a veterinario de um animal
			* @params	shared_ptr<Funcionario> tratador referente a tratador de um animal
			* @params	String batismo referente a batismo de um animal
            * @params   String classe_ refente a classe de um animal.
			*/
			void cadastrar_reptil(int id_, string nome_, string nome_cientifico_, char sexo_, float tamanho_,
                    string dieta_, shared_ptr<Funcionario> veterinario_, shared_ptr<Funcionario> tratador_,
                    string batismo_, string classe_);

			/**
			* @brief	Método que exibe um animal pelo seu ID
			* @params	Int id referente ao id de um animal cadastrado 
			*/
			void exibir_animal(int id_);

			/**
			* @brief	Método que remove um animal pelo seu ID
			* @params	Int id referente ao id de um animal cadastrado 
			*/
			void remover_animal(int id_);

			/**
			* @brief	Método que exibe todos os funcionários cadastrados.
			*/
			void listar_funcionarios();

			/**
			* @brief	Método que consulta todos os animais de uma determinada classe
			* @params	String classe referente a classe dos animais. 
			*/
			map<int, shared_ptr<Animal>> consultar_animaisClasse(string classe);

			/**
			* @brief	Método que consulta todos os animais sob responsabilidade de 
			* determinado funcionário, a consulta é pelo ID do funcionário.
			* @params	Int id referente ao id do funcionário. 
			*/
			map<int, shared_ptr<Animal>> consultar_animaisResp(int id);

			template <typename T, typename U>
			void imprimir(map<T, shared_ptr<U>> lista)
			{
				for(auto i = lista.begin(); i != lista.end(); i++)
				{
					cout << *(i->second);
				}
			}

            /**
             * @brief   Método menu petfera.
             */
            void menu();
	};
}

#endif
