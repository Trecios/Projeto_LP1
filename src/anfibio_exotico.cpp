/**
 * @file anfibio_exotico.cpp
 * @brief Implementação da classe AnfibioExotico e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "anfibio_exotico.h"

namespace PetFera{
    
    /**
     * @brief   Construtor da classe AnfibioExotico.
     * @detail  O construtor chama primeiro o construtor da classe Ave com os parâmetros
     * id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_, 
     * total_mudas_ é ultima_muda_ e então chama o construtor da classe Exotico
     * com os parâmetros ibama_, uf_origem_ e autorização_.
     */
    AnfibioExotico::AnfibioExotico(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                        float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                        shared_ptr<Funcionario> tratador_, string batismo_, int total_mudas_,
                        string ultima_muda_, string ibama_, string pais_origem_):
                        Anfibio(id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, veterinario_, 
                        tratador_, batismo_, total_mudas_, ultima_muda_), Exotico(ibama_, pais_origem_){}
    
    /**
    * @brief      Destrutor da classe AnfibioExotico.
    */
    AnfibioExotico::~AnfibioExotico(){}
}
