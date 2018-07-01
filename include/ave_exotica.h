/**
 * @file ave_exotica.h
 * @brief Declaração da classe AveExotica e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef AVE_EXOTICA_H
#define AVE_EXOTICA_H

#include "ave.h"
#include "exotico.h"

namespace PetFera{
    
    class AveExotica : public Ave, public Exotico {
        public:
            /**
             * @brief   Construtor da classe AveExotica.
             */
            AveExotica(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                shared_ptr<Funcionario> tratador_, string batismo_, int tamanho_bico_,
                int envergadura_, string ibama_, string pais_origem_);
            
            /**
		     * @brief      Destrutor da classe AveExotica.
		     */
            ~AveExotica();
    };
    
}

#endif
