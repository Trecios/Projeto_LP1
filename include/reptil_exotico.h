/**
 * @file reptil_exotico.h
 * @brief Declaração da classe ReptilExotico e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef REPTIL_EXOTICO_H
#define REPTIL_EXOTICO_H

#include "reptil.h"
#include "exotico.h"

namespace PetFera{
    
    class ReptilExotico : public Reptil, public Exotico {
        public:
            /**
             * @brief   Construtor da classe ReptilExotico.
             */
            ReptilExotico(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                shared_ptr<Funcionario> tratador_, string batismo_, bool veneno_, string tipo_veneno_,
                string ibama_, string pais_origem_);

            /**
	         * @brief      Destrutor da classe ReptilExotico.
	         */
            ~ReptilExotico();
    };
    
}

#endif
