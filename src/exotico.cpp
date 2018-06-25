/**
 * @file exotico.cpp
 * @brief Implementação da classe Exótico e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "exotico.h"


namespace PetFera{

    /**
     * @brief Construtor da classe Exótico.
     * @details O construtor chama primeiro o construtor da classe AnimalSilvestre com o parâmetro
     * ibama_, e depois armazena o valor do parâmetro pais_origem_ no atributo m_pais_origem.
     */
    Exotico::Exotico(string ibama_, string pais_origem_): AnimalSilvestre(ibama_), 
    m_pais_origem(pais_origem_){}

    /**
     * @brief Destrutor da classe Exótico.
     */
    Exotico::~Exotico(){}

    /**
     * @brief Método get do atributo m_pais_origem.
     * @return Valor do atributo m_pais_origem.
     */
    string Exotico::getPais(){
        return m_pais_origem;
    }
}
