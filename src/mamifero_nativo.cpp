/**
 * @file mamifero_nativo.cpp
 * @brief Implementação da classe MamiferoNativo e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "mamifero_nativo.h"

namespace PetFera{
    
    /**
     * @brief   Construtor da classe MamiferoNativo.
     * @detail  O construtor chama primeiro o construtor da classe Ave com os parâmetros
     * id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_ é
     * cor_ e então chama o construtor da classe Nativa
     * com os parâmetros ibama_, uf_origem_ e autorização_.
     */
    MamiferoNativo::MamiferoNativo(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                shared_ptr<Funcionario> tratador_, string batismo_, string cor_, string ibama_, 
                string uf_origem_, string autorizacao_) : Mamifero(id_, classe_, nome_, cientifico_, sexo_, 
                tamanho_,dieta_, veterinario_, tratador_, batismo_, cor_), Nativo(ibama_, uf_origem_, 
                autorizacao_){}
    
    /**
    * @brief      Destrutor da classe MamiferoNativo.
    */
    MamiferoNativo::~MamiferoNativo(){}
}
