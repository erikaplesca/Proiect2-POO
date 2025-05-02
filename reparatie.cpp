#include "reparatie.h"
#include <iostream>
int CONT_REPARATII = 0;


// ------- CONSTRUCTOR IMPLICIT PENTRU CLASA "Reparatie"  -------

Reparatie::Reparatie()
{
    m_masina = Masina();
    m_angajat = Angajat();
    m_tipReparatie = "Necunoscut";
    m_cost = 0;
}


// ------- CONSTRUCTOR DE INITIALIZARE
// CU PARAMETRI PENTRU CLASA "Reparatie"  -------

Reparatie::Reparatie(const Masina& m_masina,
                    const Angajat& m_angajat,
                    const std::string& m_tipReparatie,
                    float m_cost)
{
    this->m_masina = m_masina;
    this->m_angajat = m_angajat;
    this->m_tipReparatie = m_tipReparatie;
    this->m_cost = m_cost;
}


// ------- DESTRUCTORUL PENTRU CLASA "Masina"  -------

Reparatie::~Reparatie(){}


// ------- CONSTRUCTOR DE COPIERE PENTRU CLASA "Reparatie"  -------

Reparatie::Reparatie(const Reparatie &m_other)
{
    this->m_masina = m_other.m_masina;
    this->m_angajat = m_other.m_angajat;
    this->m_tipReparatie = m_other.m_tipReparatie;
    this->m_cost =m_other.m_cost;
}


// ------- CONSTRUCTORUL DE COPIERE PRIN OPERATORUL "="  -------

Reparatie& Reparatie::operator=(const Reparatie &m_other)
{
    this->m_masina = m_other.m_masina;
    this->m_angajat = m_other.m_angajat;
    this->m_tipReparatie = m_other.m_tipReparatie;
    this->m_cost = m_other.m_cost;
    return *this;
}

// ------- GETTER-ELE PENTRU CLASA "Reparatie"  -------
Masina Reparatie::getMasina() const
{
    return m_masina;
}
Angajat Reparatie::getAngajat() const
{
    return m_angajat;
}
std::string Reparatie::getTipReparatie() const
{
    return m_tipReparatie;
}
float Reparatie::getCost() const
{
    return m_cost;
}


// ------- SETTER-ELE PENTRU CLASA "Client"  -------

void Reparatie::setMasina(const Masina &m_masina)
{
    this->m_masina = m_masina;
}
void Reparatie::setAngajat(const Angajat &m_angajat)
{
    this->m_angajat = m_angajat;
}
void Reparatie::setTipReparatie(const std::string &m_tipReparatie)
{
    this->m_tipReparatie = m_tipReparatie;
}
void Reparatie::setCost(float m_cost)
{
    this->m_cost = m_cost;
}
// Aceasta metoda ne va ajuta la functia „interschimbareStatieLucru” 
void Reparatie::setAngajatStatieLucru(int statieLucru) {
    Angajat temp = this->m_angajat;
    temp.setStatiaLucru(statieLucru);
    this->m_angajat = temp;
}

// ------- SUPRAINCARCARE DE OPERATORI ">>" SI "<<"
// (CITIRE SI AFISARE)-------

std::istream& operator>>(std::istream& is, Reparatie& m_reparatie)
{
    std::string m_nrInm, m_marca, m_model, m_numeProprietar;
    std::string m_tipProprietar, m_numeAngajat, m_tipReparatie;
    int m_statieLucru;
    float m_costReparatie;
    Client m_proprietar;
    Masina m_masina;
    Angajat m_angajat;
    CONT_REPARATII++;
    is>>m_nrInm>>m_marca>>m_model
    >>m_numeProprietar>>m_tipProprietar
    >>m_numeAngajat>>m_statieLucru
    >>m_tipReparatie>>m_costReparatie;

    m_masina.setNrInm(m_nrInm);
    m_masina.setMarca(m_marca);
    m_masina.setModel(m_model);

    m_proprietar.setNume(m_numeProprietar);
    m_proprietar.setTipClient(m_tipProprietar);
    m_masina.setProprietar(m_proprietar);

    m_angajat.setNume(m_numeAngajat);
    m_angajat.setStatiaLucru(m_statieLucru);

    m_reparatie.setMasina(m_masina);
    m_reparatie.setAngajat(m_angajat);
    m_reparatie.setTipReparatie(m_tipReparatie);
    m_reparatie.setCost(m_costReparatie);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Reparatie& m_reparatie)
{
    os << "Reparatia cu numarul "
    << "--- Datele masinii:"
    << '\n'
    << "- Numar inmatriculare: "
    << m_reparatie.getMasina().getNrInm()<<'\n'
    << "- Marca: "
    << m_reparatie.getMasina().getMarca() << '\n'
    << "- Model: "
    << m_reparatie.getMasina().getModel() << '\n'
    << "--- Date despre client:"
    << '\n'
    << "- Numele clientului: "
    << m_reparatie.getMasina().getProprietar().getNume() << '\n'
    << "- Tip client: "
    << m_reparatie.getMasina().getProprietar().getTipClient() << '\n'
    << "--- Date despre angajatul responsabil de reparatie:"
    << '\n'
    << "- Numele angajatului: "
    << m_reparatie.getAngajat().getNume() << '\n'
    << "- Statia de lucru: "
    << m_reparatie.getAngajat().getStatiaLucru() << '\n'
    << "--- Date despre reparatie:"
    <<'\n'
    << "- Tip reparatie: "
    << m_reparatie.getTipReparatie() << '\n'
    << "- Costul reparatiei: "
    << m_reparatie.getCost() << '\n';
    return os;
}


// ----- FUNCTIE INTERSCHIMBARE STATII LUCRU

void Reparatie::interschimbareStatieLucru(Reparatie& m_reparatie1, Reparatie& m_reparatie2)
{
    int AUX_STATIE = m_reparatie1.getAngajat().getStatiaLucru();
    m_reparatie1.setAngajatStatieLucru(m_reparatie2.getAngajat().getStatiaLucru());
    m_reparatie2.setAngajatStatieLucru(AUX_STATIE);
    std::cout << "Interschimbare realizata cu succes! \n \n";
    std::cout << "Acum, angajatul "<<m_reparatie1.getAngajat().getNume()
                <<" lucreaza la statia "<<m_reparatie1.getAngajat().getStatiaLucru()
                <<" si angajatul "<< m_reparatie2.getAngajat().getNume()
                <<" lucreaza la statia "<<m_reparatie2.getAngajat().getStatiaLucru()
                <<"\n \n";
};