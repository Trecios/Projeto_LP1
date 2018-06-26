/**
 * @file exotico.h
 * @brief Declaração da classe Exótico e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef EXOTICO_H
#define EXOTICO_H

#include "animal_silvestre.h"

using namespace std;

namespace PetFera{

    /**
     * @brief Classe Exótico.
     */
    class Exotico: public AnimalSilvestre{
        protected:
            string m_pais_origem;

        public:

            /**
             * @brief Construtor da classe Exótico.
             */
            Exotico(string ibama_, string pais_origem_); 

            /**
             * @brief Destrutor da classe Exótico.
             */
            ~Exotico();

            /**
             * @brief Método get do atributo m_pais_origem.
             * @return m_pais_origem.
             */
            string getPais();
    };
}

#endif
