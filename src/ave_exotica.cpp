/**
 * @file ave_exotica.cpp
 * @brief Implementação da classe AveExotica e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "ave_exotica.h"

namespace PetFera{
    
    
    /**
     * @brief   Construtor da classe AveExotica.
     * @detail  O construtor chama primeiro o construtor da classe Ave com os parâmetros
     * id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_, 
     * m_tamanho_bico e envergadura_ em m_envergadura e então chama o construtor da classe Exotico
     * com os parâmetros ibama_, pais_origem_.
     */
    AveExotica::AveExotica(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Veterinario> veterinario_,
                shared_ptr<Tratador> tratador_, string batismo_, int tamanho_bico_,
                int envergadura_, string ibama_, string pais_origem_) : 
                Ave(id_, classe_, nome_, cientifico_, sexo_, tamanho_,dieta_, veterinario_, tratador_,
                batismo_, tamanho_bico_, envergadura_), Exotico(ibama_, pais_origem_){}
                
    /**
     * @brief      Destrutor da classe AveExotica.
     */            
    AveExotica::~AveExotica(){}
}
