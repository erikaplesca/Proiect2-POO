# Program de gestiune a unui service auto in C++

<h5>Autor: Plesca Maria-Erika, grupa 133</h5>
<h3>Descriere</h3>
Acest proiect implementează un sistem complet de gestiune pentru un service auto folosind principiile programării orientate pe obiecte în C++. Sistemul permite administrarea clienților, vehiculelor, angajaților, reparațiilor și facturilor (cu serviciile aferente), oferind o soluție minimală pentru gestionarea operațiunilor zilnice ale unui service auto.

<h3>Structura proiectului</h3>
Proiectul este organizat într-o arhitectură modulară, cu fiecare entitate implementată ca o clasă separată:<br>
├── angajat.h, angajat.cpp    # Gestionează angajații service-ului <br>
├── client.h, client.cpp      # Administrează datele clienților  <br>
├── masina.h, masina.cpp      # Gestionează informații despre vehicule  <br>
├── reparatie.h, reparatie.cpp # Înregistrează intervențiile efectuate  <br>
├── factura.h, factura.cpp    # Gestionează facturile și plățile  <br>
├── main.cpp                  # Conține bucla principală a aplicației  <br>
├── Makefile                  # Configurație pentru compilare <br>
└── input2.in                  # Fișier cu date de intrare <br>


<h3>Funcționalități principale</h3>
Sistemul oferă următoarele funcționalități: <br>
- Gestionarea  clienților: Adăugarea și afișarea clienților (persoane fizice și juridice). <br>
- Gestiunea vehiculelor: Înregistrarea și afișarea mașinilor cu detalii de identificare. <br>
- Administrarea angajaților: Adăugarea și listarea angajaților și stațiilor de lucru. <br>
- Înregistrarea reparațiilor: Documentarea intervențiilor cu detalii despre mașină, client, angajat și costul reparației. <br>
- Interschimbarea stațiilor de lucru: Modificarea asignărilor pentru reparații. <br>
- Calculul costurilor: Calcularea sumei totale de plată pentru un client specific. <br>
- Generarea facturilor: Crearea și gestionarea facturilor cu calculul TVA și discount-urilor. <br>


<h3>Formatul datelor de intrare (input2.in) </h3>
Sistemul citește date din fișierul input2.in care conține, pe fiecare linie, un număr de opțiune urmat de datele specifice operației:<br><br>

<i>-> Adăugare client <br></i>
1 [Numele clientului] [Tip client]            
<br>
<i>-> Afișare clienți <br></i>
2                                                 
<br>
<i>-> Adăugare mașină<br></i>
3 [Nr.Inm] [Marca] [Model] [Nume proprietar] [Tip proprietar] <br>
<br>
<i>-> Afișare mașini</i><br>
4                                                
<br>
<i>-> Adăugare angajat </i><br>
5 [Numele angajatului] [Statia de lucru]          
<br>
<i>-> Afișare angajați</i><br>
6                                                 
<br>
<i>-> Adaugare reparatie</i><br>
7  <br>              
----> Pentru fiecare reparatie, in functie de tipul reparatiei: <br>
<ul>
   <li> <i>Pentru serviciul de tip Schimb ulei:</i><br>
  [NrInm] [Marca] [Model] [NumeProprietar] [TipProprietar] [NumeAngajat] [StatiaLucru] Schimb_ulei [0 sau 1 pentru transmisie] [cantitate ulei]</li><br>
  <br>
  <li><i>Pentru serviciul de tip Diagnoza:</i><br>
	[NrInm] [Marca] [Model] [NumeProprietar] [TipProprietar] [NumeAngajat] [StatiaLucru] Diagnoza [Nr. Sisteme verificate] </li><br>
<br>
	<li><i>Pentru serviciul de tip Geometrie roti:</i><br>
	[NrInm] [Marca] [Model] [NumeProprietar] [TipProprietar] [NumeAngajat] [StatiaLucru] Geometrie_roti [Nr. Axe] </li><br>
<br>
	<li> <i>Pentru serviciul de tip Electrica:</i><br>
	[NrInm] [Marca] [Model] [NumeProprietar] [TipProprietar] [NumeAngajat] [StatiaLucru] Electrica [Cost piese]</li><br>
<br>
	<li><i>Pentru serviciul de tip Vopsire:</i><br>
	[NrInm] [Marca] [Model] [NumeProprietar] [TipProprietar] [NumeAngajat] [StatiaLucru] Vopsire [Suprafata vopsita]</li><br>
</ul>
  <br>
<i>
-> Afisarea tuturor reparatiilor <br></i>
8            
<br><br>

<i>
-> Insterschimbarea statiilor de lucru intre doua reparatii <br></i>
9 [Nr. Reparatiei 1] [Nr. Reparatiei 2]             
<br><br>

<i>
-> Generarea unei noi facturi <br></i>
10 <br>
[Numele clientului] [Tip client]  <br>
[Data emiterii facturii] [Nr.Factura] [TVA] [Stadiu plata (0 = Neplatita, 1 = Platita)], [Nr.Reparatii] <br>
<i>----> Apoi, pe rand, datele fiecarei reparatii ca in exemplul de mai sus.</i><br>
<br>

<i>
-> Afisarea sumei de plata, adunand toate facturile neplatite ale respectivului client.<br></i>
12 [Numele clientului]<br>           
<br><br>

<h3>Implementare OOP</h3>

<h4>Clase și Ierarhii</h4>
Proiectul conține următoarele clase: <br>
Client: Stochează informații despre clienți (nume, tip client). <br>
Mașină: Gestionează date despre vehicule (nr. înmatriculare, marcă, model, proprietar). <br>
Angajat: Administrează informații despre angajați (nume, stația de lucru). <br>
Reparație: Înregistrează detalii despre reparații (mașină, angajat, pointer catre serviciu). <br>
Factură: Gestionează facturile (client, reparații, data emitere, nr. factura, TVA, status plată). <br>
Serviciu: Clasa de bază din care avem următoarele clase derivate: <br>
--> SchimbUlei<br>
--> Diagnoza<br>
--> GeometrieRoti<br>
--> Electrica <br>
--> Vopsire <br><br>

<h4>Constructori și Destructori </h4>
Fiecare clasă implementează: <br>
<ul>
<li>Constructor implicit: Inițializează membrii cu valori implicite</li>
<li>Constructor parametrizat: Permite crearea obiectelor cu valori specifice</li>
<li>Constructor de copiere: Pentru copierea corectă a obiectelor</li>
<li>Operator de atribuire: Pentru asignarea corectă a obiectelor</li>
<li>Destructor: Pentru eliberarea resurselor (deși în acest proiect sunt simple, fără alocare dinamică)</li>
</ul>

Exemplu din clasa "Client": <br>
<code>Client();  // Constructor implicit <br>
Client(const std::string& m_nume, const std::string& m_tipClient);  // Constructor parametrizat<br>
~Client();  // Destructor<br>
Client(const Client& other);  // Constructor de copiere<br>
Client& operator=(const Client& other);  // Operator de atribuire<br>
</code>

<h4>Relațiile între clase</h4>
Proiectul folosește concepte OOP pentru a modela relațiile dintre entități:
<ul>
  <li>Compoziție<br> Clasa Mașină conține un obiect Client (proprietarul)</li>
  <li>Agregare<br>Clasa Reparație agregă obiecte Mașină și Angajat</li>
  <li>Mostenire <br>
    Există o ierarhie clară de clase: Serviciu este clasa de bază, iar clasele precum SchimbUlei, Diagnoza, GeometrieRoti, Electrica și Vopsire moștenesc din aceasta și extind comportamentul de bază. Astfel, codul este mai reutilizabil și ușor de extins cu noi tipuri de servicii.</li>
  <li>Polimorfism<br>
    - Sunt definite funcții virtuale pure în clasa de bază Serviciu (ex: virtual float calculeazaCost() const = 0;), iar fiecare clasă derivată implementează propriul algoritm de calcul.<br>
    - În cadrul clasei Reparatie, serviciul este gestionat printr-un pointer la clasa de bază (std::shared_ptr<Serviciu>), astfel încât metodele virtuale sunt apelate polimorfic, fără a cunoaște tipul concret al serviciului.</li>
</ul>

<h3>Bibliografie</h3>
https://www.youtube.com/watch?v=oRBK0Mh_gG0 <br>
https://www.makeareadme.com <br>
https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/cpp/virtual-functions.md <br>
https://www.reddit.com/r/cpp_questions/comments/15o5049/i_created_a_c_oop_template_kind_of_a_newbie_can/ <br>
https://www.youtube.com/watch?v=6yp0C5G5EKo <br>
https://bito.ai/resources/virtual-functions-in-c-plus/ <br>
https://www.youtube.com/watch?v=v2_Pth8MrKA&t=550s <br>
https://www.digitalocean.com/community/tutorials/return-array-in-c-plus-plus-function<br>
https://stackoverflow.com/questions/19042552/returning-a-pointer-of-a-local-variable-c<br>
https://forum.arduino.cc/t/can-a-function-return-a-char-array/63405<br>
https://how.dev/answers/how-to-get-the-current-date-and-time-in-cpp<br>
https://www.reddit.com/r/cpp_questions/comments/nfctj2/operator_overloading_while_doing_inheritance/<br>
https://stackoverflow.com/questions/3642010/can-i-compare-int-with-size-t-directly-in-c<br>
