/**
 * @file anfibio.h
 * @brief Declaração da classe Anfíbio e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef ANFIBIO_H
#define ANFIBIO_H


#include "animal.h"


namespace PetFera{

    /**
     * @brief Classe Anfíbio.
     */
    class Anfibio: public Animal{
        protected:
            int m_total_mudas;
            string m_ultima_muda;

        public:

            /**
             * @brief Construtor da classe Anfíbio.
             */
            Anfibio(int id_, string classe_, string nome_, string cientifico_, char sexo_,
                    float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                    shared_ptr<Funcionario> tratador_, string batismo_, int total_mudas_,
                    string ultima_muda_);

            /**
             * @brief Destrutor da classe Anfíbio.
             */
            ~Anfibio();

            /**
             * @brief Método get do atributo m_total_mudas.
             * @return m_total_mudas.
             */
            int getTotalMudas();

            /**
             * @brief Método get do atributo m_ultima_muda.
             * @return m_ultima_muda.
             */
            string getUltimaMuda();

            /**
             * @brief Método set do atributo m_total_mudas.
             */
            void setTotalMuda(int total_mudas_);

            /**
             * @brief Método set do atributo m_ultima_muda.
             */
            void setUltimaMuda(string ultima_muda_);
    };
}
#endif
