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
#include <string>

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
		map<int, Anfibio> m_lista_anfibio;
		map<int, Ave> m_lista_ave;
		map<int, Mamifero> m_lista_mamifero;
		map<int, Reptil> m_lista_reptil;
		map<int, Funcionario*> m_lista_funcionario;

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
		void buscar_funcionario(int id);
		
		/**
		* @brief	Método que remove um funcionário pelo seu ID
		* @params	Int id referente ao id de um funcionário cadastrado 
		*/
		void remover_funcionario(int id);
	};
}


#endif