/**
 * @file funcionario.cpp
 * @brief Implementação da classe Funcionario e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */


#include "funcionario.h"

namespace PetFera{

	/**
     * @brief Construtor da classe Funcionario.
     * @details O construtor armazena o valor dos parâmetros id_ no atributo m_id, nome_ em m_nome
     * cpf_ em m_cpf, idade_ em m_idade, tipo_sanguineo_ em m_tipo_sanguineo, fator_rh_ em m_fator_rh e 
     * especialidade_ em m_especialidade.
     */

	Funcionario::Funcionario(int id_, string funcao, string nome_, string cpf_, short idade_,
                            string tipo_sanguineo_, char fator_rh_, string especialidade_):
                            m_id(id_), m_nome(nome_), m_cpf(cpf_), m_tipo_sanguineo(tipo_sanguineo_), 
                            m_fator_rh(fator_rh_), m_especialidade(especialidade_){}

    /**
     * @brief Destrutor da classe Funcionario.
     */    
    Funcionario::~Funcionario(){}

    /**
     * @brief Método get do atributo m_id.
     * @return Valor do atributo m_id.
     */
    int Funcionario::getId(){
    	return m_id;
    }

    /**
     * @brief Método get do atributo m_nome.
     * @return Valor do atributo m_nome.
     */
    string Funcionario::getNome(){
    	return m_nome;
    }

    /**
     * @brief Método get do atributo m_cpf.
     * @return Valor do atributo m_cpf.
     */
    string Funcionario::getCpf(){
    	return m_cpf;
    }

    /**
     * @brief Método get do atributo m_idade.
     * @return Valor do atributo m_idade.
     */
    short Funcionario::getIdade(){
    	return m_idade;
    }

    /**
     * @brief Método get do atributo m_tipo_sanguineo.
     * @return Valor do atributo m_tipo_sanguineo.
     */
    string Funcionario::getTipoSanguineo(){
    	return m_tipo_sanguineo;
    }

    /**
     * @brief Método get do atributo m_fator_rh.
     * @return Valor do atributo m_fator_rh.
     */
    char Funcionario::getFatorRH(){
    	return m_fator_rh;
    }

    /**
     * @brief Método get do atributo m_especialidade.
     * @return Valor do atributo m_especialidade.
     */
    string Funcionario::getEspecialidade(){
    	return m_especialidade;
    }

}
