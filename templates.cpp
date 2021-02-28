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

#include <iostream>

using namespace std;

#define LEN 18

//template<class T> bool testSort(T, T);
template<class T> bool testSort(T first, T next) {
	return first > next;
}

void kopfAusgabe();

void outputDatenArr(Artikel *artikel_arr[], int counter_artikel) {
    Artikel *a;
    for (int i = 0; i < counter_artikel; i++) {
        a = artikel_arr[i];
        artikel_arr[i]->outputDatenFromArtikel();
	}
}// END outputDatenArr

void bubleSortArr(Artikel* artikel_arr[], int counter_artikel, int sort_nach) {
	Artikel* tmp;
    Artikel* a1, *a2;
	bool wechsel = false;
    for (int i = counter_artikel; i > 1; i--) {
		for (int j = 0; j < counter_artikel; j++) {

                if (sort_nach == 1) { // Artikel nr

                    a1 = artikel_arr[j];
                    a2 = artikel_arr[j + 1];

                    if (testSort<int>(artikel_arr[j]->getNr(), artikel_arr[j + 1]->getNr())) {
						wechsel = true;
					}
				}
                else if(sort_nach == 4){

                    a1 = artikel_arr[j];
                    a2 = artikel_arr[j + 1];

                    if (testSort<int>(artikel_arr[j]->artikelLagerbestand(), artikel_arr[j + 1]->artikelLagerbestand())) {
                        wechsel = true;
                    }
                }
				if (wechsel == true) {
					tmp = artikel_arr[j];
					artikel_arr[j] = artikel_arr[j + 1];
					artikel_arr[j + 1] = tmp;
					wechsel = false;
				}
		}
	}
}

int main(){
	string tmp;
	int art_nr = NULL;
	string art_bez;
	double art_preis = 0.0;
	int art_lag_best = NULL;
	Artikel* artikel_arr[LEN];
	int counter_artikel = 0;



	ifstream open_csv_file("Artikel.csv");
// 1)
	while (getline(open_csv_file, tmp, ';')) {
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
	// Ausgabe 
	kopfAusgabe();
	outputDatenArr(artikel_arr, counter_artikel);

	int sort_nach = 0;
	cout << " Nach was moechten Sie sortieren?" << endl
		<< " 1 - Nr" << endl
		<< " 2 - Bezeichnung" << endl
		<< " 3 - Preis" << endl
		<< " 4 - Lagerbestand" << endl;
	cin >> sort_nach;

	if (sort_nach == 1) {
		bubleSortArr(artikel_arr, counter_artikel, sort_nach);
	}
	if (sort_nach == 4) {
		bubleSortArr(artikel_arr, counter_artikel, sort_nach);
	}
	kopfAusgabe();
	outputDatenArr(artikel_arr, counter_artikel);


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
