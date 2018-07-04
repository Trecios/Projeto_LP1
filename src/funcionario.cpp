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

	Funcionario::Funcionario(int id_, string funcao_, string nome_, string cpf_, short idade_,
                            string tipo_sanguineo_, char fator_rh_, string especialidade_):
                            m_id(id_), m_funcao(funcao_), m_nome(nome_), m_cpf(cpf_), m_idade(idade_), 
                            m_tipo_sanguineo(tipo_sanguineo_), m_fator_rh(fator_rh_),
                            m_especialidade(especialidade_){}

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
     * @brief Método get do atributo m_funcao.
     * @return Valor do atributo m_funcao.
     */
    string Funcionario::getFuncao(){
        return m_funcao;
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

    /**
     * @brief Método set do atributo m_funcao.
     * @details Altera o valor do atributo m_funcao.
     */
    void Funcionario::setFuncao(string funcao_){
        m_funcao = funcao_;
    }

    /**
     * @brief Método set do atributo m_idade.
     * @details Altera o valor do atributo m_idade.
     */
    void Funcionario::setIdade(short idade_){
        m_idade = idade_;
    }

    /**
     * @brief Método set do atributo m_especialidade.
     * @details Altera o valor do atributo m_especialidade.
     */
    void Funcionario::setEspecialidade(string especialidade_){
        m_especialidade = especialidade_;
    }

    /**
     * @brief Método operator<< sobrecarregado.
     * @return ostream o.
     */
    ostream& operator<<(ostream &o, Funcionario const f)
    {
        o << endl;
        o << ">>>>> Ficha do Funcionario <<<<<" << endl;
        o << "ID" << setfill ('.') << setw (20) << "> " << f.m_id << endl;
        o << "Funcao" << setfill ('.') << setw (16) << "> " << f.m_funcao << endl;
        o << "Nome" << setfill ('.') << setw (18) << "> " << f.m_nome << endl;
        o << "CPF" << setfill ('.') << setw (19) << "> " << f.m_cpf << endl;
        o << "Idade" << setfill ('.') << setw (17) << "> " << f.m_idade << endl;
        o << "Tipo Sanguineo" << setfill ('.') << setw (8) << "> " << f.m_tipo_sanguineo << endl;
        o << "Fator RH" << setfill ('.') << setw (14) << "> " << f.m_fator_rh << endl;
        o << "Especialidade" << setfill ('.') << setw (9) << "> " << f.m_especialidade << endl;
        o << endl;

        return o;
    }

}
