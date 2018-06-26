/**
 * @file animal_silvestre.cpp
 * @brief Implementação da classe AnimalSilvestre e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "animal_silvestre.h"

using namespace std;

namespace PetFera{

    /**
     * @brief Construtor da classe AnimalSilvestre.
     * @details O construtor armazena o valor do parâmetro ibama_ no atributo m_ibama.
     */
    AnimalSilvestre::AnimalSilvestre(string ibama_): m_ibama(ibama_) {}

    /**
     * @brief Destrutor da classe AnimalSilvestre.
     */
    AnimalSilvestre::~AnimalSilvestre() {}

    /**
     * @brief Método get do atributo m_ibama.
     * @return Valor do atributo m_ibama.
     */
    string AnimalSilvestre::getIbama(){
        return m_ibama;
    }
}
