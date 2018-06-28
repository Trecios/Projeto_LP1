/**
 * @file cadastro.h
 * @brief Declaração da classe Cadastro e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef CADASTRO_H
#define CADASTRO_H


#include <iostream>
#include <map>
#include <fstream>
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
	class Cadastro
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
		Cadastro();

		/**
		 * @brief Destrutor padrão da classe Cadastrar
		 */
		~Cadastro();
		

		void cadastrar_funcionario(string funcao);
	};
}


#endif