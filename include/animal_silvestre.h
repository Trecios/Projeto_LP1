/**
 * @file animal_silvestre.h
 * @brief Declaração da classe AnimalSilvestre e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef ANIMAL_SILVESTRE_H
#define ANIMAL_SILVESTRE_H


using namespace std;

namespace PetFera{

    /**
     * @brief Classe AnimalSilvestre.
     */
    class AnimalSilvestre{
        protected:
            string m_ibama;

        public:

            /**
             * @brief Construtor da classe AnimalSilvestre.
             */
            AnimalSilvestre(string ibama_); 

            /**
             * @brief Destrutor da classe AnimalSilvestre.
             */
            ~AnimalSilvestre();

            /**
             * @brief Método get do atributo m_ibama.
             * @return m_ibama.
             */
            string getIbama();
    }
}

#endif
