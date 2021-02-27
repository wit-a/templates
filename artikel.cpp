// artikel.cpp

#include "artikel.h"
// Class Artikel
void Artikel::outputDatenFromArtikel() {
	cout << setw(10) << artikel_artikel_nr << artikel_artikelbezeichnung << artikel_preis << artikel_lagerbestand;
}

void Artikel::nextAddressFromArtikel(Artikel* artikel_next_address_VM) {
	artikel_next_address = artikel_next_address_VM;
}
Artikel* Artikel::nextAddressFromArtikel() {
	return artikel_next_address;
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
	:artikel_artikelbezeichnung(artikel_artikelbezeichnung) {
	artikel_artikel_nr = artikel_artikel_nr_VM;
	artikel_preis = artikel_preis_VM;
	artikel_lagerbestand = artikel_lagerbestand_VM;
}
// END Class Artikel

// Class Liste
void Liste::firstNodeListe(Artikel* liste_first_node_VM) {
	liste_first_node = liste_first_node_VM;
}
Artikel* Liste::firstNodeListe() {
	return liste_first_node;
}
void Liste::lastNodeListe(Artikel* liste_first_node_VM) {
	liste_first_node = liste_first_node_VM;
}
Artikel* Liste::lastNodeListe() {
	return liste_last_node;
}
// END Class Liste 