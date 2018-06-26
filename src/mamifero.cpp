/**
 * @file mamifero.cpp
 * @brief Implementação da classe Mamífero e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "mamifero.h"

using namespace std;

namespace PetFera{

    /**
     * @brief Construtor da classe Mamífero.
     * @details O construtor chama primeiro o construtor da classe Animal com os parâmetros
     * id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_
     * e depois armazena o valor do parâmetro cor_ no atributo m_cor.
     */
    Mamifero::Mamifero(int id_, string classe_, string nome_, string cientifico_, char sexo_,
                        float tamanho_, string dieta_, shared_ptr<Veterinario> veterinario_,
                        shared_ptr<Tratador> tratador_, string batismo_, string cor_):
                        Animal(id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, 
                        veterinario_, tratador_, batismo_), m_cor(cor_) {}

    /**
     * @brief Destrutor da classe Mamífero.
     */
    Mamifero::~Mamifero() {}

    /**
     * @brief Método get do atributo m_cor.
     * @return Valor do atributo m_cor.
     */
    string Mamifero::getCor(){
        return m_cor;
    }


}
