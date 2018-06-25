/**
 * @file exotico.cpp
 * @brief Implementação da classe Exótico e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "exotico.h"


namespace PetFera{
    Exotico::Exotico(string ibama_, string pais_origem_): AnimalSilvestre(ibama_), 
    m_pais_origem(pais_origem_){}

    Exotico::~Exotico(){}

    string Exotico::getPais(){
        return m_pais_origem;
    }
}
