#include "masina.h"
#include <iostream>

// ------- CONSTRUCTOR IMPLICIT PENTRU CLASA "Masina"  -------

Masina::Masina()
{
    m_nrInm = "-";
    m_marca = "-";
    m_model = "-";
    m_proprietar = Client();
}


// ------- CONSTRUCTOR DE INITIALIZARE
// CU PARAMETRI PENTRU CLASA "Masina"  -------

Masina::Masina(const std::string& m_nrInm,
                const std::string& m_marca,
                const std::string& m_model,
                const Client& m_proprietar)
{
    this->m_nrInm = m_nrInm;
    this->m_marca = m_marca;
    this->m_model = m_model;
    this->m_proprietar = m_proprietar;
}


// ------- DESTRUCTORUL PENTRU CLASA "Masina"  -------

Masina::~Masina() {}


// ------- CONSTRUCTOR DE COPIERE PENTRU CLASA "Masina"  -------

Masina::Masina(const Masina& other)
{
    this->m_nrInm = other.m_nrInm;
    this->m_marca = other.m_marca;
    this->m_model = other.m_model;
    this->m_proprietar = other.m_proprietar;
}


// ------- CONSTRUCTORUL DE COPIERE PRIN OPERATORUL "="  -------

Masina& Masina::operator=(const Masina& other)
{
    this->m_nrInm = other.m_nrInm;
    this->m_marca = other.m_marca;
    this->m_model = other.m_model;
    this->m_proprietar = other.m_proprietar;
    return *this;
}

// ------- GETTER-ELE PENTRU CLASA "Client"  -------

std::string Masina::getNrInm() const
{
    return m_nrInm;
}
std::string Masina::getMarca() const
{
    return m_marca;
}
std::string Masina::getModel() const
{
    return m_model;
}
Client Masina::getProprietar() const
{
    return m_proprietar;
}


// ------- SETTER-ELE PENTRU CLASA "Client"  -------

void Masina::setNrInm(const std::string& m_nrInm)
{
    this->m_nrInm = m_nrInm;
}
void Masina::setMarca(const std::string& m_marca)
{
    this->m_marca = m_marca;
}
void Masina::setModel(const std::string& m_model)
{
    this->m_model = m_model;
}

void Masina::setProprietar(const Client& m_proprietar)
{
    this->m_proprietar = m_proprietar;
}


// ------- SUPRAINCARCARE DE OPERATORI ">>" SI "<<"
// (CITIRE SI AFISARE) -------

std::istream& operator>>(std::istream& is, Masina& m_masina)
{
    std::string m_nrInm, m_marca, m_model;
    std::string m_nume_proprietar, m_tipProprietar;
    Client m_proprietar;
    is>>m_nrInm>>m_marca>>m_model>>m_nume_proprietar>>m_tipProprietar;
    m_masina.setNrInm(m_nrInm);
    m_masina.setMarca(m_marca);
    m_masina.setModel(m_model);
    m_proprietar.setNume(m_nume_proprietar);
    m_proprietar.setTipClient(m_tipProprietar);
    m_masina.setProprietar(m_proprietar);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Masina& masina)
{
    os << "Datele masinii clientului "
    << masina.getProprietar().getNume() << ":\n"
    << "-Numar de inmatriculare: "
    << masina.getNrInm() <<'\n'
    << "-Marca: "
    << masina.getMarca() << "\n"
    << "-Model: "
    << masina.getModel() << "\n";
    return os;
}