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

int main(){

	Artikel* addresse_neu_1;
	Artikel* addresse_neu_2;
	bool check_first_node = true;
	string tmp;

	int art_nr = NULL;
	string art_bez;
	double art_preis = 0.0;
	int art_lag_best = NULL;

	Liste artikel_liste;

	cout << endl << endl << "Artikel DB" << endl << endl;

	ifstream open_csv_file("Artikel.csv");


	while ( getline(open_csv_file, tmp, ';') ){
		art_nr = stoi(tmp);
		getline(open_csv_file, art_bez,';');
		getline(open_csv_file, tmp, ';');
		art_preis = stod(tmp);
		getline(open_csv_file, tmp);
		art_lag_best = stoi(tmp);
		
		addresse_neu_1 = new Artikel(art_nr, art_bez, art_preis, art_lag_best);
		//cout << art_nr << " - " << art_bez << " - " << art_preis << " - " << art_lag_best << endl;
		if (check_first_node == true) {
			artikel_liste.firstNodeListe(addresse_neu_1);
		}
		else {

		}

	}
	


}
