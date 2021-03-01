// artikel.cpp
#include "artikel.h"
// Class Artikel
void Artikel::outputDatenFromArtikel() {
	cout << setw(3) << right << artikel_artikel_nr << 
	 "|" << setw(25) << left << artikel_artikelbezeichnung << 
	 "|" << setw(5) << left << artikel_preis <<
	 "|" << setw(4) << left << artikel_lagerbestand << endl;
}
void Artikel::nextAddressFromArtikel(Artikel* artikel_next_address_VM) {
	artikel_next_address = artikel_next_address_VM;
}
Artikel* Artikel::nextAddressFromArtikel() {
	return artikel_next_address;
}
int Artikel::artikelArtikelNr() {
	return artikel_artikel_nr;
}
string Artikel::artikelArtikelbezeichnung() {
	return artikel_artikelbezeichnung;
}
double Artikel::artikelPreis() {
	return artikel_preis;
}
int Artikel::artikelLagerbestand() {
    int tmp = this->artikel_lagerbestand;
	return tmp;
}
Artikel::Artikel() 
	:artikel_artikelbezeichnung("empty") {
	artikel_artikel_nr = NULL;
	artikel_preis = NULL;
	artikel_lagerbestand = NULL;
	artikel_next_address = NULL;
}
Artikel::Artikel(int& artikel_artikel_nr_VM, string& artikel_artikelbezeichnung_VM,
				 double& artikel_preis_VM, int& artikel_lagerbestand_VM)
	:artikel_artikelbezeichnung(artikel_artikelbezeichnung_VM) {
	artikel_artikel_nr = artikel_artikel_nr_VM;
	artikel_preis = artikel_preis_VM;
	artikel_lagerbestand = artikel_lagerbestand_VM;
	artikel_next_address = NULL;
}

/*
int Artikel::getNr(){
    return this->artikel_artikel_nr;
}

*/
// END Class Artikel
// Class Liste
void Liste::firstNodeListe(Artikel* liste_first_node_VM) {
	liste_first_node = liste_first_node_VM;
}
Artikel* Liste::firstNodeListe() {
	return liste_first_node;
}
void Liste::lastNodeListe(Artikel* liste_last_node_VM) {
	liste_last_node = liste_last_node_VM;
}
Artikel* Liste::lastNodeListe() {
	return liste_last_node;
}
// END Class Liste 

