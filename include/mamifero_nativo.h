/**
 * @file mamifero_nativo.h
 * @brief Declaração da classe MamiferoNativo e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef MAMIFERO_NATIVO_H
#define MAMIFERO_NATIVO_H

#include "mamifero.h"
#include "nativo.h"

namespace PetFera{
    
    class MamiferoNativo : public Mamifero, public Nativo {
        public:
            /**
             * @brief   Construtor da classe MamiferoNativo.
             */
            MamiferoNativo(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                shared_ptr<Funcionario> tratador_, string batismo_, string cor_,
                string ibama_, string uf_origem_, string autorizacao_);
            
            /**
		     * @brief      Destrutor da classe MamiferoNativo.
		     */
            ~MamiferoNativo();
    };
    
}

#endif
