// DESCRIEREA PROBLEMEI
//  |-  Acest program C++ gestionează operațiunile unui service auto,
//		oferind următoarele funcționalități:
	// -- Administrarea clienților și a mașinilor acestora
	// -- Gestiunea angajaților service-ului
	// -- Înregistrarea și urmărirea reparațiilor efectuate
	// -- Generarea de rapoarte și liste pentru toate entitățile gestionate



// STRUCTURA PROGRAMULUI
//	|-	Programul este modularizat în patru clase principale:

	// Client - gestionează informații despre clienții service-ului
	// Masina - stochează date despre vehiculele clienților
	// Angajat - menține informații despre angajații service-ului
	// Reparatie - înregistrează detalii despre intervențiile efectuate



// DESCRIEREA DATELOR DE INTRARE
//  |-  Programul citește datele dintr-un fișier text numit "input.in".

//		Acesta conține, pe rând, un numar care indică opțiunea
//		pe care utlizatorul o alege, urmat de datele acelei operatii.



//	DESCRIEREA OPERATIILOR POSIBILE
//	--- Optiunea 1
//		- Citire de clienti
//		- Format citire: [Numele clientului] [Tip client]

//	--- Optiunea 2
//		- Afisarea tuturor clientilor
//		[Nu mai trebuie citit nimic]

//  --- Optiunea 3
//		- Citirea unei noi masini
//		- Format citire:
//		[Nr.Inm] [Marca] [Model] [Nume proprietar] [Tip proprietar]

//  --- Optiunea 4
//		- Afisarea tuturor masinilor
//		[Nu mai trebuie citit nimic]

//  --- Optiunea 5
//		- Citirea unui nou angajat
//		- Format citire: [Numele angajatului] [Statia de lucru]

//  --- Optiunea 6
//		- Afisarea tuturor angajatilor
//		[Nu mai trebuie citit nimic]

//  --- Optiunea 7
//		- Citirea unei noi reparatii
//		- Format citire:
//		[Nr.Inm] [Marca] [Model] [Nume proprietar] [Tip proprietar]
//		[Nume angajat] [Statia de lucru] [Tip reparatie] [Cost]

//  --- Optiunea 8
//		- Afisarea tuturor reparatiilor
//		[Nu mai trebuie citit nimic]

// --- Optiunea 9
//		- Interschimbarea statiilor de lucru intre doua reparatii
//		[Nr. Reparatiei 1] [Nr. Reparatiei 2]

// --- Optiunea 10
//		- Afisarea sumei totale de plata pentru un anumit client
//		[Numele clientului]


// FLUXUL DE DATE

// Datele sunt citite din fișierul de intrare,
// procesate în funcție de opțiunea selectată,
// iar rezultatele sunt afișate pe ecran.

// Programul oferă o interfață simplă de gestionare
// a tuturor entităților unui service auto.
#include "angajat.h"
#include "client.h"
#include "masina.h"
#include "reparatie.h"
#include "factura.h"
#include "ServiceException.h"
#include "serviciu.h"


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::ifstream fin("input2.in");


	// DECLARAREA VECTORILOR:
std::vector<Masina> listaMasini;
// --------------------
std::vector<Reparatie> listaReparatii;
// --------------------
std::vector<Client> listaClienti;
// --------------------
std::vector<Angajat> listaAngajati;
// --------------------
std::vector<Factura> listaFacturi;



static int OPTIUNE;

int main()
{
	try
	{if (!fin)
	{
		std::cerr << "Eroare la deschiderea fisierului!\n";
		return 1;
	}
	else
	{
		while (fin >> OPTIUNE)
		{
			// MENIU OPTIUNI:
			// Optiunea 1 - Citire de clienti
			// Optiunea 2 - Afisarea tuturor clientilor
			// Optiunea 3 - Citirea unei noi masini
			// Optiunea 4 - Afisarea tuturor masinilor
			// Optiunea 5 - Citirea unui nou angajat
			// Optiunea 6 - Afisarea tuturor angajatilor
			// Optiunea 7 - Citirea unei noi reparatii
			// Optiunea 8 - Afisarea tuturor reparatiilor
			// Optiunea 9 - Interschimmbarea statiilor de lucru intre doua reparatii
			// Optiunea 10 - Afisarea sumei totale de plata pentru un anumit client


			if (OPTIUNE == 1)
			{
				// Citirea unui nou client
				Client client;
				fin >> client;
				listaClienti.push_back(client);
			}
			else if (OPTIUNE == 2)
			{
				// Afisarea tuturor clientilor
				for (const auto& client : listaClienti) {
					std::cout << client << "\n";
				}
			}
			else if (OPTIUNE == 3)
			{
				// Citirea unei noi masini
				Masina masina;
				fin >> masina;
				listaMasini.push_back(masina);
			}
			else if (OPTIUNE == 4)
			{
				// Afisarea tuturor masinilor
				for (const auto& masina : listaMasini) {
					std::cout << masina << "\n";
				}
			}
			else if (OPTIUNE == 5)
			{
				// Citirea unui nou angajat
				Angajat angajat;
				fin >> angajat;
				listaAngajati.push_back(angajat);
			}
			else if (OPTIUNE == 6)
			{
				// Afisarea tuturor angajatilor
				for (const auto& angajat : listaAngajati) {
					std::cout << angajat << "\n";
				}
			}
			else if (OPTIUNE == 7)
			{
				// Citirea unei noi reparatii

				// Pentru serviciul de tip Schimb ulei:
				// [NrInm] [Marca] [Model] [NumeProprietar] [TipProprietar] [NumeAngajat] [StatiaLucru] Schimb_ulei [0 sau 1 pentru transmisie] [cantitate ulei]

				// Pentru serviciul de tip Diagnoza:
				// [NrInm] [Marca] [Model] [NumeProprietar] [TipProprietar] [NumeAngajat] [StatiaLucru] Diagnoza [Nr. Sisteme verificate]

				// Pentru serviciul de tip Geometrie roti:
				// [NrInm] [Marca] [Model] [NumeProprietar] [TipProprietar] [NumeAngajat] [StatiaLucru] Geometrie_roti [Nr. Axe]

				// Pentru serviciul de tip Electrica:
				// [NrInm] [Marca] [Model] [NumeProprietar] [TipProprietar] [NumeAngajat] [StatiaLucru] Electrica [Cost piese]

				// Pentru serviciul de tip Vopsire:
				// [NrInm] [Marca] [Model] [NumeProprietar] [TipProprietar] [NumeAngajat] [StatiaLucru] Vopsire [Suprafata vopsita]

				try {
					Reparatie reparatie;
					fin >> reparatie;
					const auto& masinaReparatie = reparatie.getMasina();
					auto it = std::find_if(listaMasini.begin(), listaMasini.end(),
						[&](const Masina& m) { return m.getNrInm() == masinaReparatie.getNrInm(); });
					
					// Dacă mașina nu există, o adăugăm
					if (it == listaMasini.end()) {
						listaMasini.push_back(masinaReparatie);
						std::cout << "!!! Masina " << masinaReparatie.getNrInm() 
								<< " a fost adaugata in istoric\n";
					}
					
					listaReparatii.push_back(reparatie);
					
				}
				catch (const TipServiciuInvalidException& e) {
					std::cout << "Serviciu invalid ignorat: " << e.what() << "\n";
					continue; 
				}
				catch (const TipProprietarInvalidException& e) {
					std::cout << "Eroare: " << e.what() << '\n';
				}

			}
			else if (OPTIUNE == 8)
			{
				// Afisarea tuturor reparatiilor
				for (const auto& reparatie : listaReparatii) {
					std::cout << reparatie << "\n";
				}
			}
			// Insterschimbarea statiilor de lucru intre doua reparatii
			else if (OPTIUNE == 9)
			{
				size_t i, j;
				fin >> i >> j;
				if (i < listaReparatii.size() && j < listaReparatii.size()) {
					Reparatie::interschimbareStatieLucru(listaReparatii[i], listaReparatii[j]);
				} else {
					std::cout << "Indici invalizi pentru reparatii!\n";
				}
			}
			else if (OPTIUNE == 10) {
				try{
					// Citirea unei noi facturi
									
					// Citim factura cu toate detaliile sale
					Factura factura;
					fin >> factura;

					// Actualizăm factura cu data curentă dacă data este implicită
					if (factura.getDataEmitere() == "01/01/2025") {
						factura.genereazaDataCurenta();
					}
					// Actualizăm totalul factură (în caz că nu s-a făcut automat)
					factura.actualizeazaTotal();
					
					std::string DATA_CURENTA;
					DATA_CURENTA = factura.genereazaDataCurenta2();
						// Verificare data invalida 
					if(factura.getDataEmitere()>DATA_CURENTA)
						throw DataInvalidaException(factura.getDataEmitere());
					
						// Verificare duplicat numar factura
					for (const auto& f : listaFacturi) 
						if (f.getNrFactura() == factura.getNrFactura()) 
							throw NumarFacturaDuplicatException(factura.getNrFactura());


					std::cout << "\n------------ Generare Factura Noua ------------\n";
					// Afișăm factura generată
					std::cout << factura;

					// O adaugam in capatul listei.
					listaFacturi.push_back(factura);
				}
				catch (const DataInvalidaException& e)
				{
					std::cout << "Data"<< e.what() <<" este invalida." << "\n";
					continue; 
				}		
				catch (const NumarFacturaDuplicatException& e) {
					std::cout << "Nr de factura duplicat: " << e.what() << "\n";
					continue; 
				}
					
			}
			else if (OPTIUNE == 11) {
				// Afișarea datelor unei anumite facturi
				int idFactura;
				size_t i=0;
				fin >> idFactura;
				while (i<listaFacturi.size())
				{
					if (idFactura == listaFacturi[i].getNrFactura())
					{
						std::cout << "\n------------ Detalii Factură ------------\n \n";
						std::cout << listaFacturi[idFactura];
					}
					i++;
				}
				if(i==listaFacturi.size())
					std::cout << "Factura inexistenta!\n";
			}
			else if (OPTIUNE == 12)
			{		// Afisarea sumei de plata, adunand toate facturile neplatite ale respectivului client.
					std::string NUME_CLIENT;
					float SUMA = 0.0f;
					fin >> NUME_CLIENT;
					
					bool clientGasit = false;
					
					// Verificăm existența clientului în listă
					for (const auto& factura : listaFacturi)
						if (factura.getClient().getNume() == NUME_CLIENT) {
							clientGasit = true;
							break;
						}
					
					if (!clientGasit) {
						std::cout << "Clientul " << NUME_CLIENT << " nu există în sistem!\n";
					}
					else {
						// Colectăm facturile neplătite ale clientului
						std::vector<Factura*> facturiNeplatite;
						
						for (auto it = listaFacturi.begin(); it != listaFacturi.end(); ++it) 
							if (it->getClient().getNume() == NUME_CLIENT && !it->getPlatita()) 
							{
								SUMA += it->calculeazaTotalCuTVA();
								facturiNeplatite.push_back(&(*it));
							}
						
						// Afișare detaliată
						std::cout << "\n----- Raport neplăți client " << NUME_CLIENT << " -----\n";
						
						if (facturiNeplatite.empty()) {
							std::cout << "Clientul nu are facturi neplătite.\n";
						}
						else {
							for (const auto& factura : facturiNeplatite) {
								std::cout << "Factura #" << factura->getNrFactura() 
										  << " - Total: " << factura->calculeazaTotalCuTVA() 
										  << " RON (Data: " << factura->getDataEmitere() << ")\n";
							}
							std::cout << "\nTotal de plată: " << SUMA << " RON\n";
						}
					}
				
			}
			 

			// - am la factura.h metode pe care nu le-am folosit
		}
	}}
    catch (const ServiceException& e) {
        std::cout << "Eroare de service: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Eroare neprevazuta: " << e.what() << "\n";
    }
	return 0;
}