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
int anzahlElementeInListe(Liste&); // BUG 


void buubleSort(Liste& artikel_liste, int sort_nach) {
	bool wechsel_node = false;
	int anzahl_elemente_in_liste = 17; 
	// anzahlElementeInListe(artikel_liste);
	Artikel* addresse_artikel_tmp_1 = artikel_liste.firstNodeListe();
	Artikel* addresse_artikel_tmp_2 = NULL;
	Artikel* addresse_artikel_swap = NULL;
	Artikel* addresse_artikel_swap_next = NULL;
	Artikel* addresse_artikel_swap_vor_vor_letztes = NULL;

	for (int i = anzahl_elemente_in_liste; i > 1; i--) {
		for (int j = 0; j < anzahl_elemente_in_liste - 1; j++) {
			
			if (addresse_artikel_tmp_1 != artikel_liste.lastNodeListe()) { // somst entshet ein Pionter mit overflow 
				addresse_artikel_tmp_2 = addresse_artikel_tmp_1->nextAddressFromArtikel();
			}
			if (sort_nach == 1) { // sort nach ArtikelNr
				if ( testSort(addresse_artikel_tmp_1->outputArtikelNr(), addresse_artikel_tmp_2->outputArtikelNr() ) ) {
					wechsel_node = true;
				}
			}
			if (sort_nach == 2) { // sort nach Bezeichnung
				if (testSort(addresse_artikel_tmp_1->outputArtikelBezeichnung(), addresse_artikel_tmp_2->outputArtikelBezeichnung())) {
					wechsel_node = true;
				}
			}
			if (sort_nach == 3) { // sort nach Preis
				if (testSort(addresse_artikel_tmp_1->outputArtikelPreis(), addresse_artikel_tmp_2->outputArtikelPreis())) {
					wechsel_node = true;
				}
			}
			if (sort_nach == 4) { // sort nach Lagerbestand 
				if (testSort(addresse_artikel_tmp_1->outputArtikelLagerbestand(), addresse_artikel_tmp_2->outputArtikelLagerbestand())) {
					wechsel_node = true;
				}
			}
			if (wechsel_node == true) {
				if (artikel_liste.firstNodeListe() == addresse_artikel_tmp_1) { // ist das erste Element
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
					// addresse_artikel_swap_next->outputDatenFromArtikel();
					addresse_artikel_swap = addresse_artikel_tmp_1;
					addresse_artikel_tmp_1 = addresse_artikel_tmp_2;
					addresse_artikel_tmp_2 = addresse_artikel_swap;
					addresse_artikel_tmp_1->nextAddressFromArtikel(addresse_artikel_tmp_2);
					addresse_artikel_tmp_2->nextAddressFromArtikel(addresse_artikel_swap_next);
					artikel_liste.firstNodeListe(addresse_artikel_tmp_1);
					wechsel_node = false;
					break;
				}
				if (artikel_liste.lastNodeListe() == addresse_artikel_tmp_2) { // das letzte Element muss getauscht werden
					addresse_artikel_tmp_1; // vor letztes element
					addresse_artikel_tmp_2; // das letzte element 
					// brauch das vor vor letztes noch für next addres
					Artikel* tmp1 = artikel_liste.firstNodeListe();
					Artikel* tmp2 = NULL;
					while (tmp2 != addresse_artikel_tmp_1){
						if (tmp1->nextAddressFromArtikel() == addresse_artikel_tmp_1) {
							addresse_artikel_swap_vor_vor_letztes = tmp1; // vor vor letztes element 
							break;
						}
						tmp2 = tmp1->nextAddressFromArtikel();
						tmp1 = tmp2;
					}
					// 1.1 das vor letzte ins swap
					addresse_artikel_swap = addresse_artikel_tmp_2;
					// 1.2 das vor letzte wird mit letztem überschrieben
					addresse_artikel_tmp_2 = addresse_artikel_tmp_1;
					// 1.3 das letzte wird zu swap 
					addresse_artikel_tmp_1 = addresse_artikel_swap;
					// 2.1 das vor vor letzte element braucht die addresse vom vor letzten element
					addresse_artikel_swap_vor_vor_letztes->nextAddressFromArtikel(addresse_artikel_tmp_1);
					artikel_liste.lastNodeListe(addresse_artikel_tmp_2);
					// NULL - next bei letzten 
					addresse_artikel_tmp_2->nextAddressFromArtikel(NULL);
					// den vorletzten mit dem letzten verknöpfen
					addresse_artikel_tmp_1->nextAddressFromArtikel(addresse_artikel_tmp_2);
					//addresse_artikel_swap_vor_vor_letztes->outputDatenFromArtikel();
					wechsel_node = false;
					break;
				}
				else{
					addresse_artikel_tmp_1; // first
					addresse_artikel_tmp_2; // next 
					// vor firs 
					Artikel* tmp1 = artikel_liste.firstNodeListe();
					Artikel* tmp2 = NULL;
					while (tmp2 != addresse_artikel_tmp_1) {
						if (tmp1->nextAddressFromArtikel() == addresse_artikel_tmp_1) {
							addresse_artikel_swap_vor_vor_letztes = tmp1; // vor first 
							break;
						}
						tmp2 = tmp1->nextAddressFromArtikel();
						tmp1 = tmp2;
					}
					// Addrese dex nechsten elements nach next 
					addresse_artikel_swap_next = addresse_artikel_tmp_2->nextAddressFromArtikel();

					addresse_artikel_swap_vor_vor_letztes->outputDatenFromArtikel(); // 9 = 1
					addresse_artikel_tmp_1->outputDatenFromArtikel(); // 11 = 2
					addresse_artikel_tmp_2->outputDatenFromArtikel(); // 10 = 3 
					addresse_artikel_swap_next->outputDatenFromArtikel(); // 12 = 4 
					// Tausche 2 mit 3 
					addresse_artikel_swap = addresse_artikel_tmp_1;
					addresse_artikel_tmp_1 = addresse_artikel_tmp_2; // tmp_1 wird zu tmp_2
					addresse_artikel_tmp_2 = addresse_artikel_swap;  // tmp_2 wird zu tmp_1
					// 10 = 3 tmp_2
					// 11 = 2 tmp_1 
										/*
					addresse_artikel_swap_vor_vor_letztes->outputDatenFromArtikel(); // 9 = 1
					addresse_artikel_tmp_1->outputDatenFromArtikel(); // 10 = 2
					addresse_artikel_tmp_2->outputDatenFromArtikel(); // 11 = 3
					addresse_artikel_swap_next->outputDatenFromArtikel(); // 12 = 4 
					*/
					addresse_artikel_swap_vor_vor_letztes->nextAddressFromArtikel(addresse_artikel_tmp_1);
					addresse_artikel_tmp_1->nextAddressFromArtikel(addresse_artikel_tmp_2);
					addresse_artikel_tmp_2->nextAddressFromArtikel(addresse_artikel_swap_next);
					wechsel_node = false;
					break;
				}
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