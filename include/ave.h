/**
 * @file ave.h
 * @brief Declaração da classe Ave e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef AVE_H
#define AVE_H

#include "animal.h"

using namespace std;

namespace PetFera{

    /**
     * @brief Classe Ave.
     */
    class Ave: public Animal{
        protected:
            int m_tamanho_bico;
            int m_envergadura;

        public:

            /**
             * @brief Construtor da classe Ave.
             */
            Ave(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                shared_ptr<Funcionario> tratador_, string batismo_, int tamanho_bico_,
                int envergadura_);

            /**
             * @brief Destrutor da classe Ave.
             */
            ~Ave();

            /**
             * @brief Método get do atributo m_tamanho_bico.
             * @return m_tamanho_bico.
             */
            int getTamanhoBico();

            /**
             * @brief Método get do atributo m_envergadura.
             * @return m_envergadura.
             */
            int getEnvergadura();

            /**
             * @brief Método set do atributo m_tamanho_bico.
             */
            void setTamanhoBico(int tamanho_bico_);

            /**
             * @brief Método set do atributo m_envergadura.
             */
            void setEnvergadura(int envergadura_);
    };
}

#endif
