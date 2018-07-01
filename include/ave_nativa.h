/**
 * @file ave_nativa.h
 * @brief Declaração da classe AveNativa e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef AVE_NATIVA_H
#define AVE_NATIVA_H

#include "ave.h"
#include "nativo.h"

namespace PetFera{
    
    class AveNativa : public Ave, public Nativo {
        public:
            /**
             * @brief   Construtor da classe AveNativa.
             */
            AveNativa(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                shared_ptr<Funcionario> tratador_, string batismo_, int tamanho_bico_,
                int envergadura_, string ibama_, string uf_origem_, string autorizacao_);
            
            /**
		     * @brief      Destrutor da classe AveNativa.
		     */
            ~AveNativa();
    };
    
}

#endif
