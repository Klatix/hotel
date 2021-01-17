#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Posilek {
public:
	int nr_posilku = 0;
	string nazwa_posilku = "brak nazwy";
	float cena = 0.0;

};





class Zamowienie {
private:

	string status = "W trakcie";
	int nr_pokoju = 0;
	int nr_zamowienia = 0;
	vector <Posilek> koszyk;

public:

	void potwierdz_zamowienie(vector <Zamowienie> lista_zamowien,Zamowienie &zamowienie);  //metoda potweirdzenia zamowienia ??generuje numer zamowienia??

	void dodaj_do_koszyka(vector <Posilek> koszyk,Posilek posilek);


};




class Kuchnia {
public:

	Posilek menu[5] = { {1, "Zupa pomidorowa", 10.0}, {2, "Nalesniki z serem", 15.0}, {3, "Salatka grecka", 17.0}, {4, "Ziemniaczki w mundurkach", 12.0}, {5, "Fasola po bretonsku", 20.0} };
	vector <Zamowienie> lista_zamowien;


	void wyswietl_menu();
	void zamow_jedzenie();
    void dodaj_do_listy(vector <Zamowienie> lista_zamowien, Zamowienie zamowienie);
    Posilek zwroc_info_o_posilku(int nr, Kuchnia k); //metoda zwracajaca informacje o posilku - nazwa, cena ?? NUMER

};


//funkcja dodajcac posilek do zamowienia 
void Zamowienie::dodaj_do_koszyka(vector <Posilek> koszyk, Posilek posilek) {

	koszyk.push_back(posilek);

}

//funckja dodajaca zamowienie do listy 
void dodaj_do_listy(vector <Zamowienie> lista_zamowien,Zamowienie &zamowienie) {

	lista_zamowien.push_back(zamowienie);

}


//metoda klasy Posilek zwracajaca informacje o posilku - dodatkowo NUMER
Posilek Kuchnia::zwroc_info_o_posilku(int nr, Kuchnia k) {
	int i = 1;
	while (i < 6) {
		if (nr == k.menu[i - 1].nr_posilku) {

			return k.menu[i];
		}
		else i++;
	}

}
//metoda klasy Zamowienie generujaca numer zamowienia 
void Zamowienie::potwierdz_zamowienie(vector <Zamowienie> lista_zamowien, Zamowienie &zamowienie) {

	//generowanie numeru zamowienia
	srand(time(NULL));

	zamowienie.nr_zamowienia = (rand() % 100 ) + 1;


	//wyswietlenie informacji o zamowieniu
	cout << "Szczegoly zlozonego zamowienia:" << endl;
	int i,wybor;


	cout << "Numer pokoju: " << zamowienie.nr_pokoju << endl;
	cout << "Numer zamowienia: " << zamowienie.nr_zamowienia << endl;
	cout << "Status: " << zamowienie.status << endl;
	cout << "Posilki: ";

	/*
	for (i = 0; i < koszyk.size(); i++) {
	
		cout << koszyk[i].nr_posilku << ". " << koszyk[i].nazwa_posilku <<" - "<<koszyk[i].cena << "zl." << endl;
	
	}
	*/
	//potwierdzenie zamowienia przez uzytkownika
	cout << "[1] Potwierdz zamowienie" << endl << "[2] Anuluj zamowienie (wszystkie wybrane posilki zostana bezpowrotnie usuniete z listy)" << endl;
	cout << "Wybor: ";
	cin >> wybor;

	if (wybor == 1) {

	dodaj_do_listy(lista_zamowien,zamowienie);
	}
	else if(wybor == 2) {
		cout << "Zamowienie anulowane" << endl;
		koszyk.clear();
	}


}


//wyswietlanie tablicy posilkow
void Kuchnia::wyswietl_menu() {


	cout << "	MENU" << endl;
	int i;
	for (i = 0; i < 5; i++) {
		cout << menu[i].nr_posilku  << ". "<< menu[i].nazwa_posilku << " - "<< menu[i].cena << " zl. " << endl;
	
	}

}

//metoda dla klienta
void Kuchnia::zamow_jedzenie() {}

int main() {
	Kuchnia k1;
	Zamowienie z1;
	Posilek p1;
	k1.wyswietl_menu();
	z1.potwierdz_zamowienie(k1.lista_zamowien, z1);

}