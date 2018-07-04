/**
 * @file mamifero_exotica.cpp
 * @brief Implementação da classe MamiferoExotica e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "mamifero_exotico.h"

namespace PetFera{
    
    /**
     * @brief   Construtor da classe MamiferoExotica.
     * @detail  O construtor chama primeiro o construtor da classe Ave com os parâmetros
     * id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_ é 
     * cor_ e então chama o construtor da classe Exotico com os parâmetros ibama_, pais_origem_.
     */
    MamiferoExotico::MamiferoExotico(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                shared_ptr<Funcionario> tratador_, string batismo_, string cor_, string ibama_,
                string pais_origem_): Mamifero(id_, classe_, nome_, cientifico_, sexo_, tamanho_,dieta_,
                veterinario_, tratador_, batismo_, cor_), Exotico(ibama_, pais_origem_) {}

    /**
     * @brief Destrutor da classe MamiferoExotica.
     */            
    MamiferoExotico::~MamiferoExotico() {}
}
