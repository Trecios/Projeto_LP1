/**
 * @file animal.cpp
 * @brief Implementação da classe Animal e seus métodos.
 * @author Bryan Brito
 * @author Leonardo Matos
 */

#include "animal.h"

namespace PetFera{

    /**
     * @brief Construtor da classe Animal.
     * @details O construtor armazena os valores dos parâmetro id_ no atributo m_id, classe_ em
     * m_classe, nome_ em m_nome, cientifico_ em m_cientifico, sexo_ em m_sexo, tamanho_ em
     * m_tamanho, dieta_ em m_dieta, veterinario_ em m_veterinario, tratador_ em m_tratador e
     * batismo_ em m_batismo.
     */
    Animal::Animal(int id_, string classe_, string nome_, string cientifico_, char sexo_,
                    float tamanho_, string dieta_, shared_ptr<Funcionario> veterinario_,
                    shared_ptr<Funcionario> tratador_, string batismo_): m_id(id_), m_classe(classe_),
                    m_nome(nome_), m_cientifico(cientifico_), m_sexo(sexo_), m_tamanho(tamanho_),
                    m_dieta(dieta_), m_veterinario(veterinario_), m_tratador(tratador_), 
                    m_batismo(batismo_) {}

    /**
     * @brief Destrutor da classe Animal.
     */
    Animal::~Animal() {}

    /**
     * @brief Método get do atributo m_id.
     * @return Valor do atributo m_id.
     */
    int Animal::getId(){
        return m_id;
    }

    /**
     * @brief Método get do atributo m_classe.
     * @return Valor do atributo m_classe.
     */
    string Animal::getClasse(){
        return m_classe;
    }

    /**
     * @brief Método get do atributo m_nome.
     * @return Valor do atributo m_nome.
     */
    string Animal::getNome(){
        return m_nome;
    }

    /**
     * @brief Método get do atributo m_cientifico.
     * @return Valor do atributo m_cientifico.
     */
    string Animal::getCientifico(){
        return m_cientifico;
    }

    /**
     * @brief Método get do atributo m_sexo.
     * @return Valor do atributo m_sexo.
     */
    char Animal::getSexo(){
        return m_sexo;
    }

    /**
     * @brief Método get do atributo m_tamanho.
     * @return Valor do atributo m_tamanho.
     */
    float Animal::getTamanho(){
        return m_tamanho;
    }

    /**
     * @brief Método get do atributo m_dieta.
     * @return Valor do atributo m_dieta.
     */
    string Animal::getDieta(){
        return m_dieta;
    }

    /**
     * @brief Método get do atributo m_veterinario.
     * @return Valor do atributo m_veterinario.
     */
    shared_ptr<Funcionario> Animal::getVeterinario(){
        return m_veterinario;
    }

    /**
     * @brief Método get do atributo m_tratador.
     * @return Valor do atributo m_tratador.
     */
    shared_ptr<Funcionario> Animal::getTratador(){
        return m_tratador;
    }

    /**
     * @brief Método get do atributo m_batismo.
     * @return Valor do atributo m_batismo.
     */
    string Animal::getBatismo(){
        return m_batismo;
    }

    /**
     * @brief Método set do atributo m_tamanho.
     * @details Altera o valor do atributo m_tamanho.
     */
    void Animal::setTamanho(float tamanho_){
        m_tamanho = tamanho_;
    }

    /**
     * @brief Método set do atributo m_dieta.
     * @details Altera o valor do atributo m_dieta.
     */
    void Animal::setDieta(string dieta_){
        m_dieta = dieta_;
    }

    /**
     * @brief Método set do atributo m_veterinario.
     * @details Altera o valor do atributo m_veterinario.
     */
    void Animal::setVeterinario(shared_ptr<Funcionario> veterinario_){
        m_veterinario = veterinario_;
    }

    /**
     * @brief Método set do atributo m_tratador.
     * @details Altera o valor do atributo m_tratador.
     */
    void Animal::setTratador(shared_ptr<Funcionario> tratador_){
        m_tratador = tratador_;
    }
    

}
