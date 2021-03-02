/*
* 24.02.2021 C++
* Aufgabe zu Tamplates
*
* 1) Schreiben Sie ein Programm in C++, welches die Textdatei Artikel.txt zeilenweise Ausliest und 
* die entsprechenden Werte in die Objekte einer Klasse artikel schreibt.
* (eine Zeile der Artikel.txt hat folgende Struktrt: Artikelnr.;Artikelbezeichnung; Preis; Lagerbestand)
*
* 2) Legen Sie einen Array vom Typ artikel* an, in welchem sie die Adressen der erzeugten Objekte speichern. 
* Diesen Array halten Sie in einer Klasse liste. (Wenn Sie wollen können Sie statt dessen auch mit einer verketteten Liste arbeiten, 
* aber wem das zu kompliziert ist kann auch mit einem Array mit 18 Speicherplätzen arbeiten)
* Schreiben Sie eine Methode „sortieren“ der Klasse liste (als Template) welche die Liste umsortiert. 
* 
* 3) Es soll möglich sein nach Artikelnummer, nach Artikelname und auch nach dem Preis oder Lagerbestand sortieren zu lassen.
*
* 4) Lassen Sie die Liste anschließend ausgeben.
*
*/
#include "artikel.h"

template<class T> bool testSort(T first_element, T last_element) {
	return first_element > last_element;
}

void kopfAusgabe();
void listeAusgeben(Liste&);
void fileEinlesen(Liste&);
int anzahlElementeInListe(Liste&);

void buubleSort(Liste& artikel_liste, int sort_nach) {
	bool wechsel_node = false;
	bool first_node_address = false;
	bool last_node_address = false;
	int anzahl_elemente_in_liste = 17; 
	// anzahlElementeInListe(artikel_liste);
	Artikel* addresse_artikel_tmp_1 = artikel_liste.firstNodeListe();
	Artikel* addresse_artikel_tmp_2 = NULL;
	Artikel* addresse_artikel_swap = NULL;
	Artikel* addresse_artikel_swap_next = NULL;
	Artikel* addresse_artikel_swap_befor = NULL;

	for (int i = anzahl_elemente_in_liste; i > 1; i--) {
		for (int j = 0; j < anzahl_elemente_in_liste - 1; j++) {
			if (addresse_artikel_tmp_1 != artikel_liste.lastNodeListe()) {
				addresse_artikel_tmp_2 = addresse_artikel_tmp_1->nextAddressFromArtikel();
			}
			if (sort_nach == 1) { // sort nach ArtikelNr
				if ( testSort(addresse_artikel_tmp_1->outputArtikelNr(), addresse_artikel_tmp_2->outputArtikelNr() ) ) {
					wechsel_node = true;
				}
			}
			if (sort_nach == 2) { // sort nach Bezeichnung

			}
			if (sort_nach == 3) { // sort nach Preis

			}
			if (sort_nach == 4) { // sort nach Lagerbestand 

			}
			if (wechsel_node == true) {
				if (artikel_liste.firstNodeListe() == addresse_artikel_tmp_1) { // ist das erste Element
					first_node_address = true;
					/* 
						1. mit 2 tauschen 
						damit das funktioniert:
						Element 3 Addresse speichern 
						Elemente Tauschen 1 - 2 (mit swap)
						2. next Element die adresse von der 3 geben 
						1. next Element die adresse von der 2 geben 
						1. alst first node eintragen 
					*/
					addresse_artikel_swap_next = addresse_artikel_tmp_2->nextAddressFromArtikel();
					addresse_artikel_swap = addresse_artikel_tmp_1;
					addresse_artikel_tmp_1 = addresse_artikel_tmp_2;
					addresse_artikel_tmp_2 = addresse_artikel_swap;
					addresse_artikel_tmp_2->nextAddressFromArtikel(addresse_artikel_swap_next);
					addresse_artikel_tmp_1->nextAddressFromArtikel(addresse_artikel_tmp_2);
					artikel_liste.firstNodeListe(addresse_artikel_tmp_1);
				}
				if (artikel_liste.lastNodeListe() == addresse_artikel_tmp_2) { // das letzte Element
					last_node_address = true;
					
				}
				// 3 er tausch
				addresse_artikel_swap = addresse_artikel_tmp_1;
				addresse_artikel_swap_next = addresse_artikel_tmp_1->nextAddressFromArtikel(); // nechster node

				addresse_artikel_tmp_1 = addresse_artikel_tmp_2;
				addresse_artikel_tmp_2 = addresse_artikel_swap;


				wechsel_node = false;
			}
			addresse_artikel_tmp_1 = addresse_artikel_tmp_2;
		}
	}
} // END buubleSort



int main(){
	int sort_nach = 0;
	Liste artikel_liste;

	cout << endl << endl << "Artikel DB" << endl << endl;

	fileEinlesen(artikel_liste);
	listeAusgeben(artikel_liste);

	do { // main meunu loop
		cout << " Nach was moechten Sie sortieren?" << endl
			<< " 1 - Nr" << endl
			<< " 2 - Bezeichnung" << endl
			<< " 3 - Preis" << endl
			<< " 4 - Lagerbestand" << endl
			<< " 0 - end " << endl;
		cin >> sort_nach;
		if (sort_nach == 1) {
			buubleSort(artikel_liste, sort_nach);
		}
		if (sort_nach == 2) {
			;
		}
		if (sort_nach == 3) {
			;
		}
		if (sort_nach == 4) {
			;
		}
		listeAusgeben(artikel_liste);
	} while (sort_nach != 0);

} // END main
void kopfAusgabe() {
	cout << endl << endl << setw(25) << "Artikel DB" << endl << endl
		<< setw(3) << right << "Nr" <<
		"|" << setw(25) << left << "Bezeichnung" <<
		"|" << setw(5) << left << "Preis" <<
		"|" << setw(4) << left << "Bestand" << endl;
	for (int i = 0; i <= 42; i++) {
		cout << "-";
	}
	cout << endl;
} // END kopfAusgabe

void listeAusgeben(Liste& artikel_liste) {
	kopfAusgabe();
	Artikel* addresse_neu_1 = artikel_liste.firstNodeListe();
	Artikel* addresse_neu_2 = NULL;

	while (addresse_neu_2 != artikel_liste.lastNodeListe()){
		addresse_neu_1->outputDatenFromArtikel();
		addresse_neu_2 = addresse_neu_1;
		addresse_neu_1 = addresse_neu_2->nextAddressFromArtikel();
	}
} // END listeAusgeben

void fileEinlesen(Liste& artikel_liste) {
	Artikel* addresse_neu_1 = NULL;
	Artikel* addresse_neu_2 = NULL;
	bool check_first_node = true;
	string tmp;
	int art_nr = NULL;
	string art_bez;
	double art_preis = 0.0;
	int art_lag_best = NULL;

	ifstream open_csv_file("Artikel.csv");

	while (getline(open_csv_file, tmp, ';')) {
		// getline geht nur mit string um deswegen werden die string mit sto* gekastet 
		art_nr = stoi(tmp);
		getline(open_csv_file, art_bez, ';');
		getline(open_csv_file, tmp, ';');
		art_preis = stod(tmp);
		getline(open_csv_file, tmp);
		art_lag_best = stoi(tmp);

		addresse_neu_1 = new Artikel(art_nr, art_bez, art_preis, art_lag_best);

		if (check_first_node == true) {
			artikel_liste.firstNodeListe(addresse_neu_1);
			check_first_node = false;
		}
		else {
			addresse_neu_2->nextAddressFromArtikel(addresse_neu_1);
		}
		addresse_neu_2 = addresse_neu_1;
	}

	artikel_liste.lastNodeListe(addresse_neu_1);
	open_csv_file.close();
} // END fileEinlesen


// DEBUG THIS
int anzahlElementeInListe(Liste& artikel_liste) {
	int elemente_in_liste = 0;
	// Bestimme anzahl der Elemente in der Liste 
	Artikel* addresse_neu_1 = artikel_liste.firstNodeListe();
	Artikel* addresse_neu_2 = NULL;

	while (addresse_neu_1 != artikel_liste.lastNodeListe()) {
		elemente_in_liste++;
		addresse_neu_1->nextAddressFromArtikel();
	}
	return elemente_in_liste;

} // END anzahlElementeInListe