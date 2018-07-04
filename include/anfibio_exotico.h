/**
 * @file anfibio_exotico.h
 * @brief Declaração da classe AnfibioExotico e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef ANFIBIO_EXOTICO_H
#define ANFIBIO_EXOTICO_H

#include "anfibio.h"
#include "exotico.h"

namespace PetFera{
    
    class AnfibioExotico : public Anfibio, public Exotico {
        public:
            /**
             * @brief   Construtor da classe AnfibioExotico.
             */
            AnfibioExotico(int id_, string classe_, string nome_, string cientifico_, char sexo_, 
                float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                shared_ptr<Funcionario> tratador_, string batismo_, int total_mudas_,
                string ultima_muda_, string ibama_, string pais_origem_);
            
            /**
		     * @brief      Destrutor da classe AnfibioExotico.
		     */
            ~AnfibioExotico();
    };
    
}

#endif
