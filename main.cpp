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


// DETALII DE IMPLEMENTARE

// Programul utilizează array-uri statice pentru stocarea datelor
// (maxim 20 de clienți/mașini, 10 angajați/reparații).

// Fiecare clasă are implementate constructori, destructori,
// operatori de citire/afisare și metode get/set.

// Se menține coerența datelor între entități
// (o reparație are legături cu mașina, clientul și angajatul responsabil).




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


#include <iostream>
#include <fstream>
#include <string>

std::ifstream fin("input.in");


	// DECLARAREA VECTORILOR:
Masina listaMasini[20];
int nrMasini=0;
// --------------------
Reparatie listaReparatii[10];
int nrReparatii=0;
// --------------------
Client listaClienti[20];
int nrClienti=0;
// --------------------
Angajat listaAngajati[10];
int nrAngajati=0;
int actualizare = 0;
// --------------------
// Declararea vectorului de facturi
Factura listaFacturi[20];
int nrFacturi = 0;



int OPTIUNE;

int main()
{
	if (!fin)
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
				fin >> listaClienti[nrClienti++];
			}
			else if (OPTIUNE == 2)
			{
				// Afisarea tuturor clientilor
				std::cout <<
					"\n------------  Clientii service-ului  ------------\n \n";
				for(int i=0; i<nrClienti; i++)
					std::cout << listaClienti[i] << '\n';
			}
			else if (OPTIUNE == 3)
			{
				// Citirea unei noi masini
				fin >> listaMasini[nrMasini++];
			}
			else if (OPTIUNE == 4)
			{
				// Afisarea tuturor masinilor
				std::cout <<
					"\n------------  Istoric masini  ------------\n \n";
				for(int i=0; i<nrMasini; i++)
					std::cout << listaMasini[i] << '\n';
			}
			else if (OPTIUNE == 5)
			{
				// Citirea unui nou angajat
				fin >> listaAngajati[nrAngajati++];
			}
			else if (OPTIUNE == 6)
			{
				// Afisarea tuturor angajatilor
				std::cout <<
					"\n------------  Lista angajati  ------------\n \n";
				for(int i=0; i<nrAngajati; i++)
					std::cout << listaAngajati[i] << '\n';
			}
			else if (OPTIUNE == 7)
			{
				// Citirea unei noi reparatii
				fin >> listaReparatii[nrReparatii];

				//  Verificam dacă mașina există in vectorul de masina
				bool masinaExista = false;
				std::string nr_inmatriculare = listaReparatii[nrReparatii-1].getMasina().getNrInm();

				for (int i = 0; i < nrMasini; i++)
					if (listaMasini[i].getNrInm() == nr_inmatriculare)
					{
						masinaExista = true;
						break;
					}

				// Dacă mașina nu există și mai avem spațiu, o adăugăm
				if (!masinaExista && nrMasini < 20)
				{
					listaMasini[nrMasini++] = listaReparatii[nrReparatii-1].getMasina();
					std::cout << "!!! Masina " << listaMasini[nrMasini-1].getNrInm()
							 << " a fost adaugata in istoric\n";
				}

			}
			else if (OPTIUNE == 8)
			{
				// Afisarea tuturor reparatiilor
				std::cout <<
					"\n------------  Istoric reparatii  ------------\n \n";
				for(int i=0; i<nrReparatii; i++)
					std::cout << listaReparatii[i]<<'\n';
			}
			// Insterschimbarea statiilor de lucru intre doua reparatii
			else if (OPTIUNE == 9)
			{
				int i, j;
				fin >> i >> j;
				if (i >= 0 && i < nrReparatii && j >= 0 && j < nrReparatii) 
					Reparatie::interschimbareStatieLucru(listaReparatii[i], listaReparatii[j]);
				else
					std::cout << "Indici invalizi pentru reparatii!\n";
			}
			else if (OPTIUNE == 10)
			{
				std::string NUME_CLIENT;
				float SUMA = 0;
				fin >> NUME_CLIENT;
				for (int i = 0; i < nrReparatii; i++)
					if (listaReparatii[i].getMasina().getProprietar().getNume() == NUME_CLIENT)
						SUMA+=listaReparatii[i].getCost();
				std::cout << "Suma totala de plata pe care o are clientul "<<NUME_CLIENT<<" este de "<<SUMA<<" RON.\n \n";
			}
			else if (OPTIUNE == 11) {
				// Citirea unei noi facturi
				std::cout << "\n------------ Generare Factura Noua ------------\n";
				
				// Citim factura cu toate detaliile sale
				fin >> listaFacturi[nrFacturi];
				
				// Actualizăm factura cu data curentă dacă data este implicită
				if (listaFacturi[nrFacturi].getDataEmitere() == "01/01/2025") {
					listaFacturi[nrFacturi].genereazaDataCurenta();
				}
				
				// Actualizăm totalul factură (în caz că nu s-a făcut automat)
				listaFacturi[nrFacturi].actualizeazaTotal();
				
				// Afișăm factura generată
				std::cout << listaFacturi[nrFacturi];
				
				// Incrementăm contorul de facturi
				nrFacturi++;
			}
			else if (OPTIUNE == 12) {
				// Afișarea datelor unei anumite facturi
				int idFactura;
				fin >> idFactura;
				
				std::cout << "\n------------ Detalii Factură ------------\n \n";
				
				if (idFactura >= 0 && idFactura < nrFacturi) {
					std::cout << listaFacturi[idFactura];
				} else {
					std::cout << "Eroare: Nu există factură cu indexul " << idFactura << "!\n";
				}
			}
			 

			// - am la factura.h metode pe care nu le-am folosit
		}
	}
	return 0;
}