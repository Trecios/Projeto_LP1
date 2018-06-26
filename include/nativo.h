/**
 * @file nativo.h
 * @brief Declaração da classe Nativo e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef NATIVO_H
#define NATIVO_H

#include "animal_silvestre.h"

using namespace std;

namespace PetFera{

    /**
     * @brief Classe Nativo.
     */
    class Nativo: public AnimalSilvestre{
        protected:
            string m_uf_origem;
            string m_autorizacao;

        public:

            /**
             * @brief Construtor da classe Nativo.
             */
            Nativo(string ibama_, string uf_origem_, string autorizacao_); 

            /**
             * @brief Destrutor da classe Nativo.
             */
            ~Nativo();

            /**
             * @brief Método get do atributo m_uf_origem.
             * @return m_uf_origem.
             */
            string getOrigem();

            /**
             * @brief Método get do atributo m_autorizacao.
             * @return m_uf_autorizacao.
             */
            string getAutorizacao();
    };
}

#endif
