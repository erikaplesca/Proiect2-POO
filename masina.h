#ifndef MASINA_H
#define MASINA_H

#include "client.h"
#include <string>

class Masina
{
private:
    std::string m_nrInm;
    std::string m_marca;
    std::string m_model;
    Client m_proprietar;

public:
    Masina();
    Masina(const std::string& m_nrInm,
        const std::string& m_marca,
        const std::string& m_model,
        const Client& m_proprietar);
    ~Masina();

    Masina(const Masina& masina);
    Masina& operator=(const Masina& masina);

    std::string getNrInm() const;
    std::string getMarca() const;
    std::string getModel() const;
    Client getProprietar() const;

    void setNrInm(const std::string& m_nrInm);
    void setMarca(const std::string& m_marca);
    void setModel(const std::string& m_model);
    void setProprietar(const Client& m_proprietar);

    friend std::istream& operator>>(std::istream& is, Masina& m_masina);
    friend std::ostream& operator<<(std::ostream& os, const Masina& m_masina);
};

#endif //MASINA_H