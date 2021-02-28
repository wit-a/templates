// artikel.h 
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Artikel {
private:
// (eine Zeile der Artikel.txt hat folgende Struktrt : Artikelnr.; Artikelbezeichnung; Preis; Lagerbestand)
	int artikel_artikel_nr;
	string artikel_artikelbezeichnung;
	double artikel_preis;
	int artikel_lagerbestand;
	Artikel* artikel_next_address;
public:
	void outputDatenFromArtikel();
	void nextAddressFromArtikel(Artikel*);
	Artikel* nextAddressFromArtikel();
	/*
	inline int artikelArtikelNr() {
			return this->artikel_artikel_nr;
	}
	*/
	string artikelArtikelbezeichnung();
    int getNr();
	double artikelPreis();
	int artikelLagerbestand();



	Artikel();
	Artikel(int&, string&, double&, int&);
};

class Liste {
private:
	Artikel* liste_first_node;
	Artikel* liste_last_node;
public:
	void firstNodeListe(Artikel*);
	Artikel* firstNodeListe();
	void lastNodeListe(Artikel*);
	Artikel* lastNodeListe();
};

