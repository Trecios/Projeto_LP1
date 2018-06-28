/**
 * @file tratador.cpp
 * @brief Implementação da classe Tratador e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "tratador.h"

namespace PetFera{

	/**
     * @brief Construtor da classe Tratador.
     * @details O construtor chama o construtor da classe Funcionário com os parâmetros
     * id_, nome_, cpf_, idade_, tipo_sanguineo_, fator_rh_, especialidade_, 
     */
    Tratador::Tratador(int id_, string funcao_, string nome_, string cpf_, short idade_, string tipo_sanguineo_,
                        char fator_rh_, string especialidade_): Funcionario(id_, funcao_, nome_, cpf_, 
                        idade_, tipo_sanguineo_, fator_rh_, especialidade_) {}

    /**
     * @brief Destrutor da classe Tratador.
     */
    Tratador::~Tratador() {}
}
