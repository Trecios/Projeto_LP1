/**
 * @file anfibio_nativo.h
 * @brief Declaração da classe AnfibioNativo e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef ANFIBIO_NATIVA_H
#define ANFIBIO_NATIVA_H

#include "anfibio.h"
#include "nativo.h"

namespace PetFera{
    
    class AnfibioNativo : public Anfibio, public Nativo {
        public:
            /**
             * @brief   Construtor da classe AnfibioNativo.
             */
            AnfibioNativo(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                shared_ptr<Funcionario> tratador_, string batismo_, int total_mudas_,
                string ultima_muda_, string ibama_, string uf_origem_, string autorizacao_);

            /**
	         * @brief     Destrutor da classe AnfibioNativo.
	         */
            ~AnfibioNativo();
    };
    
}

#endif
