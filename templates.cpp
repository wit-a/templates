/*
* 24.02.2021 C++
* 
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
*/
#include "artikel.h"

#define LEN 18 // Anzahl der Objekte im Array (war 18 vorgegeben= 

//beim aufrufen name<type>(var1, var2); aufrufen 
template<class T> bool testSort(T first, T next) {
	return first > next;
} // END template

void kopfAusgabe();
void outputDatenArr(Artikel*[], int); // 4)
void bubleSortArr(Artikel* [], int, int); // 3)

int main(){
	string tmp;
	int art_nr = NULL;
	string art_bez;
	double art_preis = 0.0;
	int art_lag_best = NULL;
	Artikel* artikel_arr[LEN];
	int counter_artikel = 0;
	int sort_nach = 0;

	ifstream open_csv_file("Artikel.csv");

// 1 - 2)
	while (getline(open_csv_file, tmp, ';')) {
		// getline geht nur mit string um deswegen werden die string mit sto* gekastet 
		art_nr = stoi(tmp);
		getline(open_csv_file, art_bez, ';');
		getline(open_csv_file, tmp, ';');
		art_preis = stod(tmp);
		getline(open_csv_file, tmp);
		art_lag_best = stoi(tmp);

		artikel_arr[counter_artikel] = new Artikel(art_nr, art_bez, art_preis, art_lag_best);
		counter_artikel++;
	}
	open_csv_file.close();
	// Ausgabe nach einlesen 
	outputDatenArr(artikel_arr, counter_artikel);
	
	do { // main meunu loop
		cout << " Nach was moechten Sie sortieren?" << endl
			<< " 1 - Nr" << endl
			<< " 2 - Bezeichnung" << endl
			<< " 3 - Preis" << endl
			<< " 4 - Lagerbestand" << endl
			<< " 0 - end " << endl;
		cin >> sort_nach;
		if (sort_nach == 1) {
			bubleSortArr(artikel_arr, counter_artikel, sort_nach);
		}
		if (sort_nach == 2) {
			bubleSortArr(artikel_arr, counter_artikel, sort_nach);
		}
		if (sort_nach == 3) {
			bubleSortArr(artikel_arr, counter_artikel, sort_nach);
		}
		if (sort_nach == 4) {
			bubleSortArr(artikel_arr, counter_artikel, sort_nach);
		}
		outputDatenArr(artikel_arr, counter_artikel);
	} while (sort_nach!= 0);
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

// 4)
void outputDatenArr(Artikel* artikel_arr[], int counter_artikel) {
	kopfAusgabe();
	Artikel* addresse_artikel_tmp;
	for (int i = 0; i < counter_artikel; i++) {
		addresse_artikel_tmp = artikel_arr[i];
		artikel_arr[i]->outputDatenFromArtikel();
	}
}// END outputDatenArr

// 3)
void bubleSortArr(Artikel* artikel_arr[], int counter_artikel, int sort_nach) {
	Artikel* addresse_artikel_tmp_1 = NULL;
	Artikel* addresse_artikel_tmp_2 = NULL;
	bool swap_artikel_obj = false;
	for (int i = counter_artikel; i > 1; i--) {
		for (int j = 0; j < counter_artikel - 1; j++) {
			if (sort_nach == 1) { // sortierung nach Artikel nr

				addresse_artikel_tmp_1 = artikel_arr[j];
				addresse_artikel_tmp_2 = artikel_arr[j + 1];

				if (testSort<int>(artikel_arr[j]->artikelArtikelNr(), artikel_arr[j + 1]->artikelArtikelNr())) {
					swap_artikel_obj = true;
				}
			}
			if (sort_nach == 2) { // sortierung nach Bezeichnung
				addresse_artikel_tmp_1 = artikel_arr[j];
				addresse_artikel_tmp_2 = artikel_arr[j + 1];
				// direkter strig vergleich... zum testen aber auch das template kann mit string umgehen 
				if (testSort<string>(artikel_arr[j]->artikelArtikelbezeichnung(), artikel_arr[j + 1]->artikelArtikelbezeichnung())) {
					swap_artikel_obj = true;
				}

			}
			if (sort_nach == 3) { // sortierung nach Preis

				addresse_artikel_tmp_1 = artikel_arr[j];
				addresse_artikel_tmp_2 = artikel_arr[j + 1];

				if (testSort<double>(artikel_arr[j]->artikelPreis(), artikel_arr[j + 1]->artikelPreis())) {
					swap_artikel_obj = true;
				}
			}
			if (sort_nach == 4) { // sortierung nach Lagerbestand 

				addresse_artikel_tmp_1 = artikel_arr[j];
				addresse_artikel_tmp_2 = artikel_arr[j + 1];

				if (testSort<int>(artikel_arr[j]->artikelLagerbestand(), artikel_arr[j + 1]->artikelLagerbestand())) {
					swap_artikel_obj = true;
				}
			}
			if (swap_artikel_obj == true) {
				Artikel* swap_artikel_tmp = NULL;
				swap_artikel_tmp = artikel_arr[j];
				artikel_arr[j] = artikel_arr[j + 1];
				artikel_arr[j + 1] = swap_artikel_tmp;
				swap_artikel_obj = false;
			}
		}
	}
} // END bubleSortArr