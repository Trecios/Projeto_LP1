/**
 * @file reptil_nativo.h
 * @brief Declaração da classe ReptilNativo e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef REPTIL_NATIVO_H
#define REPTIL_NATIVO_H

#include "reptil.h"
#include "nativo.h"

namespace PetFera{
    
    class ReptilNativo : public Reptil, public Nativo {
        public:
            /**
             * @brief   Construtor da classe ReptilNativo.
             */
            ReptilNativo(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                shared_ptr<Funcionario> tratador_, string batismo_, bool veneno_, string tipo_veneno_,
                string ibama_, string uf_origem_, string autorizacao_);
            
            /**
		     * @brief      Destrutor da classe ReptilNativo.
		     */
            ~ReptilNativo();
    };
    
}

#endif
