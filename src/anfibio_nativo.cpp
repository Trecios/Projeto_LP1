/**
 * @file anfibio_nativo.cpp
 * @brief Implementação da classe AnfibioNativo e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "anfibio_nativo.h"

namespace PetFera{
    
    /**
     * @brief   Construtor da classe AnfibioNativo.
     * @detail  O construtor chama primeiro o construtor da classe Ave com os parâmetros
     * id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_, 
     * total_mudas_ é ultima_muda_ e então chama o construtor da classe Nativa
     * com os parâmetros ibama_, uf_origem_ e autorização_.
     */
    AnfibioNativo::AnfibioNativo(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                        float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                        shared_ptr<Funcionario> tratador_, string batismo_, int total_mudas_,
                        string ultima_muda_, string ibama_, string uf_origem_, string autorizacao_):
                        Anfibio(id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, veterinario_, 
                        tratador_, batismo_, total_mudas_, ultima_muda_), Nativo(ibama_, uf_origem_,
                        autorizacao_){}
    
    /**
    * @brief      Destrutor da classe AnfibioNativo.
    */
    AnfibioNativo::~AnfibioNativo(){}
}
