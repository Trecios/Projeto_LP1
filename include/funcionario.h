/**
 * @file funcionario.h
 * @brief Declaração da classe Funcionário e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

namespace PetFera{

    /**
     * @brief Classe Funcionário.
     */
    class Funcionario{
        protected:
            int m_id;
            string m_funcao;
            string m_nome;
            string m_cpf;
            short m_idade;
            string m_tipo_sanguineo; // A, B, AB, O
            char m_fator_rh; // +, -
            string m_especialidade;

        public:
  
            /**
             * @brief Construtor da classe Funcionário.
             */
            Funcionario(int id_, string funcao_, string nome_, string cpf_, short idade_,
                    string tipo_sanguineo_, char fator_rh_, string especialidade_);

            /**
             * @brief Destrutor da classe Funcionário.
             */
            ~Funcionario();

            /**
             * @brief Método get do atributo m_id.
             * @return m_id.
             */
            int getId();

            /**
             * @brief Método get do atributo m_funcao.
             * @return m_funcao.
             */
            string getFuncao();

            /**
             * @brief Método get do atributo m_nome.
             * @return m_nome.
             */
            string getNome();

            /**
             * @brief Método get do atributo m_cpf.
             * @return m_cpf.
             */
            string getCpf();

            /**
             * @brief Método get do atributo m_idade.
             * @return m_idade.
             */
            short getIdade();

            /**
             * @brief Método get do atributo m_tipo_sanguineo.
             * @return m_tipo_sanguineo.
             */
            string getTipoSanguineo();

            /**
             * @brief Método get do atributo m_fator_rh.
             * @return m_fator_rh.
             */
            char getFatorRH();
 
            /**
             * @brief Método get do atributo m_especialidade.
             * @return m_especialidade.
             */
            string getEspecialidade();

            /**
             * @brief Método set do atributo m_funcao.
             */
            void setFuncao(string funcao_);

            /**
             * @brief Método set do atributo m_idade.
             */
            void setIdade(short idade_);

            /**
             * @brief Método set do atributo m_especialidade.
             */
            void setEspecialidade(string especialidade_);

            /**
             * @brief Método operator<< sobrecarregado.
             */
            friend ostream& operator<<(ostream &o, Funcionario const f);
    };

}

#endif
