#ifndef REPARATIE_H
#define REPARATIE_H

#include "masina.h"
#include "angajat.h"
#include <string>

class Reparatie
{
private:
    Masina m_masina;
    Angajat m_angajat;
    std::string m_tipReparatie;
    float m_cost;

public:
    Reparatie();
    Reparatie(const Masina& m_masina,
                const Angajat& m_angajat,
                const std::string& m_tipReparatie,
                float m_cost);
    ~Reparatie();

    Reparatie(const Reparatie& m_reparatie);
    Reparatie& operator=(const Reparatie& m_reparatie);

    Masina getMasina() const;
    Angajat getAngajat() const;
    std::string getTipReparatie() const;
    float getCost() const;

    void setMasina(const Masina& m_masina);
    void setAngajat(const Angajat& m_angajat);
    void setTipReparatie(const std::string& m_tipReparatie);
    void setCost(float m_cost);
    void setAngajatStatieLucru(int statieLucru);

    friend std::ostream& operator<<(std::ostream& os, const Reparatie& reparatie);
    friend std::istream& operator>>(std::istream& is, Reparatie& m_reparatie);

    static void interschimbareStatieLucru(Reparatie& m_reparatie1,  Reparatie& m_reparatie2);
};

#endif //REPARATIE_H