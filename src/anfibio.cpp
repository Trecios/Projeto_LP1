/**
 * @file anfibio.cpp
 * @brief Implementação da classe Anfíbio e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "anfibio.h"


namespace PetFera{

    /**
     * @brief Construtor da classe Anfíbio.
     * @details O construtor chama primeiro o construtor da classe Animal com os parâmetros
     * id_, classe_, nome_, cientifico_, sexo_, tamanho_, dieta_, veterinario_, tratador_, batismo_
     * e depois armazena os valores dos parâmetros total_mudas_ no atributo m_total_mudas e
     * ultima_muda_ em m_ultima_muda.
     */
    Anfibio::Anfibio(int id_, string classe_, string nome_, string cientifico_, char sexo_,
                    float tamanho_, string dieta_, shared_ptr<Veterinario> veterinario_,
                    shared_ptr<Tratador> tratador_, string batismo_, int total_mudas_,
                    string ultima_muda_): Animal(id_, classe_, nome_, cientifico_, sexo_, tamanho_,
                    dieta_, veterinario_, tratador_, batismo_), m_total_mudas(total_mudas_),
                    m_ultima_muda(ultima_muda_) {}

    /**
     * @brief Destrutor da classe Anfíbio.
     */
    Anfibio::~Anfibio() {}

    /**
     * @brief Método get do atributo m_total_mudas.
     * @return Valor do atributo m_total_mudas.
     */
    int Anfibio::getTotalMudas(){
        return m_total_mudas;
    }

    /**
     * @brief Método get do atributo m_ultima_muda.
     * @return Valor do atributo m_ultima_muda.
     */
    string Anfibio::getUltimaMuda(){
        return m_ultima_muda;
    }

    /**
     * @brief Método set do atributo m_total_mudas.
     * @return Altera o valor do atributo m_total_mudas.
     */
    void Anfibio::setTotalMuda(int total_mudas_){
        m_total_mudas = total_mudas_;
    }

    /**
     * @brief Método set do atributo m_ultima_muda.
     * @return Altera o valor do atributo m_ultima_muda.
     */
    void Anfibio::setUltimaMuda(string ultima_muda_){
        m_ultima_muda = ultima_muda_;
    }
}
