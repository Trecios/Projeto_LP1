/**
 * @file mamifero_exotico.h
 * @brief Declaração da classe MamiferoExotico e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef MAMIFERO_EXOTICO_H
#define MAMIFERO_EXOTICO_H

#include "mamifero.h"
#include "exotico.h"

namespace PetFera{
    
    class MamiferoExotico : public Mamifero, public Exotico {
        public:
            /**
             * @brief   Construtor da classe MamiferoExotico.
             */
            MamiferoExotico(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                shared_ptr<Funcionario> tratador_, string batismo_, string cor_,
                string ibama_, string pais_origem_);

            /**
	         * @brief      Destrutor da classe MamiferoExotico.
	         */
            ~MamiferoExotico();
    };
    
}

#endif
