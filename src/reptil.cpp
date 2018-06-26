/**
 * @file reptil.cpp
 * @brief Implementação da classe Réptil e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "reptil.h"

using namespace std;

namespace PetFera{

    /**
     * @brief Construtor da classe Réptil.
     * @details O construtor chama primeiro o construtor da classe Animal com os parâmetros
     * id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_
     * e depois armazena os valores dos parâmetros veneno_ no atributo m_veneno e tipo_veneno_ em
     * m_tipo_veneno.
     */
    Reptil::Reptil(int id_, string classe_, string nome_, string cientifico_, char sexo_,
                    float tamanho_, string dieta_, shared_ptr<Veterinario> veterinario_,
                    shared_ptr<Tratador> tratador_, string batismo_, bool veneno_,
                    string tipo_veneno_): Animal(id_, classe_, nome_, cientifico_, sexo_,
                    tamanho_, dieta_, veterinario_, tratador_, batismo_), m_veneno(veneno_),
                    m_tipo_veneno(tipo_veneno_) {}

    /**
     * @brief Destrutor da classe Réptil.
     */
    Reptil::~Reptil() {}

    /**
     * @brief Método get do atributo m_veneno.
     * @return Valor do atributo m_veneno.
     */
    bool Reptil::getVeneno(){
        return m_veneno;
    }
    /**
     * @brief Método get do atributo m_tipo_veneno.
     * @return Valor do atributo m_tipo_veneno.
     */
    string Reptil::getTipoVeneno(){
        return m_tipo_veneno;
    }

}
