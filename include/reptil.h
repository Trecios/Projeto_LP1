/**
 * @file reptil.h
 * @brief Declaração da classe Réptil e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef REPTIL_H
#define REPTIL_H

#include "Animal.h"

using namespace std;

namespace PetFera{

    /**
     * @brief Classe Réptil.
     */
    class Reptil: public Animal{
        protected:
            bool m_veneno;
            string m_tipo_veneno;

        public:

            /**
             * @brief Construtor da classe Réptil.
             */
            Reptil(int id_, string classe_, string nome_, string cientifico_, char sexo_,
                    float tamanho_, string dieta_, share_ptr<PetFera::Veterinario> veterinario_,
                    share_ptr<PetFera::Tratador> tratador_, string batismo_, bool veneno_,
                    string tipo_veneno_);

            /**
             * @brief Destrutor da classe Réptil.
             */
            ~Reptil();

            /**
             * @brief Método get do atributo m_veneno.
             * @return m_veneno.
             */
            bool getVeneno();

            /**
             * @brief Método get do atributo m_tipo_veneno.
             * @return m_tipo_veneno.
             */
            string getTipoVeneno();
    }
}

#endif
