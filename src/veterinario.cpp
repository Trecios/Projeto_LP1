/**
 * @file veterinario.cpp
 * @brief Implementação da classe Veterinario e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "veterinario.h"

namespace PetFera{

	/**
     * @brief Construtor da classe Veterinário.
     * @details O construtor chama o construtor da classe Funcionário com os parâmetros
     * id_, nome_, cpf_, idade_, tipo_sanguineo_, fator_rh_, especialidade_, 
     */
    Veterinario::Veterinario(int id_, string funcao_, string nome_, string cpf_, short idade_, string tipo_sanguineo_,
                            char fator_rh_, string especialidade_): Funcionario(id_, funcao_, nome_, cpf_, idade_,
                            tipo_sanguineo_, fator_rh_, especialidade_) {}

    /**
     * @brief Destrutor da classe Veterinário.
     */
    Veterinario::~Veterinario() {}
}
