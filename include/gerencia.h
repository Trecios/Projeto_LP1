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
#include "anfibio.h"
#include "ave.h"
#include "mamifero.h"
#include "reptil.h"
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
			void cadastrar_funcionario(string funcao);

			/**
			* @brief	Método que busca um funcionário pelo seu ID
			* @params	Int id referente ao id de um funcionário cadastrado 
			*/
			void exibir_funcionario(int id);
			
			/**
			* @brief	Método que remove um funcionário pelo seu ID
			* @params	Int id referente ao id de um funcionário cadastrado 
			*/
			void remover_funcionario(int id);
			
			/**
			* @brief	Método que le dados de funcionários de um aquivo .csv 
			*/
			void ler_funcionarios();

			/**
			* @brief	Método que cadastra um animal pela sua classe
			* @params	String classe referente a classe de um animal
			*/
			void cadastrar_animal(string classe);


			void cadastrar_anfibio(int id, string nome, string nome_cientifico, char sexo, float tamanho, string dieta, 
								shared_ptr<Funcionario> veterinario, shared_ptr<Funcionario> tratador, string batismo);


			void cadastrar_ave(int id, string nome, string nome_cientifico, char sexo, float tamanho, string dieta, 
								shared_ptr<Funcionario> veterinario, shared_ptr<Funcionario> tratador, string batismo);


			void cadastrar_mamifero(int id, string nome, string nome_cientifico, char sexo, float tamanho, string dieta, 
								shared_ptr<Funcionario> veterinario, shared_ptr<Funcionario> tratador, string batismo);


			void cadastrar_reptil(int id, string nome, string nome_cientifico, char sexo, float tamanho, string dieta, 
								shared_ptr<Funcionario> veterinario, shared_ptr<Funcionario> tratador, string batismo);

			void exibir_animal(int id);
	};
}


#endif