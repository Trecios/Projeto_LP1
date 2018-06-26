/**
 * @file nativo.cpp
 * @brief Implementação da classe Nativo e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "nativo.h"

using namespace std;

namespace PetFera{

    /**
     * @brief Construtor da classe Nativo.
     * @details O construtor chama primeiro o construtor da classe AnimalSilvestre com o parâmetro
     * ibama_, e depois armazena os valores dos parâmetros uf_origem_ no atributo m_uf_origem e
     * autorizacao_ em m_autorizacao.
     */
    Nativo::Nativo(string ibama_, string uf_origem_, string autorizacao_): AnimalSilvestre(ibama_),
                m_uf_origem(uf_origem_), m_autorizacao(autorizacao_) {}

    /**
     * @brief Destrutor da classe Nativo.
     */
    Nativo::~Nativo() {}

    /**
     * @brief Método get do atributo m_uf_origem.
     * @return Valor do atributo m_uf_origem.
     */
    string Nativo::getOrigem(){
        return m_uf_origem;
    }

    /**
     * @brief Método get do atributo m_autorizacao.
     * @return Valor do atributo m_autorizacao.
     */
    string Nativo::getAutorizacao(){
        return m_autorizacao;
    }
}
