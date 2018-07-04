/**
 * @file reptil_nativo.cpp
 * @brief Implementação da classe ReptilNativo e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "reptil_nativo.h"

namespace PetFera{
    
    /**
     * @brief   Construtor da classe ReptilNativo.
     * @detail  O construtor chama primeiro o construtor da classe Ave com os parâmetros
     * id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_,
     * veneno_ é tipo_veneno_ e então chama o construtor da classe Nativa com os parâmetros ibama_, 
     * uf_origem_ e autorização_.
     */
    ReptilNativo::ReptilNativo(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                shared_ptr<Funcionario> tratador_, string batismo_, bool veneno_, string tipo_veneno_, string ibama_, 
                string uf_origem_, string autorizacao_) : Reptil(id_, classe_, nome_, cientifico_, sexo_, 
                tamanho_,dieta_, veterinario_, tratador_, batismo_, veneno_, tipo_veneno_), Nativo(ibama_, uf_origem_, 
                autorizacao_) {}
    
    /**
    * @brief      Destrutor da classe ReptilNativo.
    */
    ReptilNativo::~ReptilNativo(){}
}
