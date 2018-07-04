/**
 * @file reptil_exotico.cpp
 * @brief Implementação da classe ReptilExotico e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "reptil_exotico.h"

namespace PetFera{
    
    /**
     * @brief   Construtor da classe ReptilExotica.
     * @detail  O construtor chama primeiro o construtor da classe Ave com os parâmetros
     * id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_, 
     * veneno_ é tipo_veneno_ e então chama o construtor da classe Exotico
     * com os parâmetros ibama_, pais_origem_.
     */
    ReptilExotico::ReptilExotico(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                shared_ptr<Funcionario> tratador_, string batismo_, bool veneno_,
                string tipo_veneno_, string ibama_, string pais_origem_): 
                Reptil(id_, classe_, nome_, cientifico_, sexo_, tamanho_,dieta_, veterinario_, tratador_,
                batismo_, veneno_, tipo_veneno_), Exotico(ibama_, pais_origem_){}

    /**
     * @brief Destrutor da classe ReptilExotico.
     */            
    ReptilExotico::~ReptilExotico(){}
}
