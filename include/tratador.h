/**
 * @file tratador.h
 * @brief Declaração da classe Tratador.
 * @author Bryan Brito
 * @author Leonardo Matos
 */
#ifndef TRATADOR_H
#define TRATADOR_H


#include "funcionario.h"

namespace PetFera{

    /**
     * @brief Classe Tratador.
     */
    class Tratador: public Funcionario{
        public:

            /**
             * @brief Construtor da classe Tratador.
             */
            Tratador(int id_, string nome_, string cpf_, short idade_, short tipo_sanguineo_, char fator_rh_, 
                    sting especialidade_);

            /**
             * @brief Destrutor da classe Tratador.
             */
            ~Tratador();
    }

}

#endif
