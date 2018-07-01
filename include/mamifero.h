/**
 * @file mamifero.h
 * @brief Declaração da classe Mamífero e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef MAMIFERO_H
#define MAMIFERO_H

#include "animal.h"

using namespace std;

namespace PetFera{

    /**
     * @brief Classe Anfíbio.
     */
    class Mamifero: public Animal{
        protected:
            string m_cor;

        public:

            /**
             * @brief Construtor da classe Mamífero.
             */
            Mamifero(int id_, string classe_, string nome_, string cientifico_, char sexo_,
                    float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                    shared_ptr<Funcionario> tratador_, string batismo_, string cor_);

            /**
             * @brief Destrutor da classe Mamífero.
             */
            ~Mamifero();

            /**
             * @brief Método get do atributo m_cor.
             * @return m_cor.
             */
            string getCor();
    };
}

#endif
