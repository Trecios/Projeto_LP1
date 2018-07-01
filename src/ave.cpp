/**
 * @file ave.cpp
 * @brief Implementação da classe Ave e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "ave.h"

using namespace std;

namespace PetFera{

    /**
     * @brief Construtor da classe Ave.
     * @details O construtor chama primeiro o construtor da classe Animal com os parâmetros
     * id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_
     * e depois armazena os valores dos parâmetros tamanho_bico_ no atributo m_tamanho_bico e
     * envergadura_ em m_envergadura.
     */
    Ave::Ave(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
            float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
            shared_ptr<Funcionario> tratador_, string batismo_, int tamanho_bico_,
            int envergadura_): Animal(id_, classe_, nome_, cientifico_, sexo_, 
            tamanho_, dieta_, veterinario_, tratador_, batismo_), m_tamanho_bico(tamanho_bico_),
            m_envergadura(envergadura_) {}

    /**
     * @brief Destrutor da classe Ave.
     */
    Ave::~Ave() {}

    /**
     * @brief Método get do atributo m_tamanho_bico.
     * @return Valor do atributo m_tamanho_bico.
     */
    int Ave::getTamanhoBico(){
        return m_tamanho_bico;
    }

    /**
     * @brief Método get do atributo m_envergadura.
     * @return Valor do atributo m_envergadura.
     */
    int Ave::getEnvergadura(){
        return m_envergadura;
    }
}
