#include <iostream>
#include <time.h>
#include "header.h"
#include <vector>
#include <string>
using namespace std;
//klasa abstrakcyjna z której dziedziczyć będą klasy Kelner, Klient i Kierownik
class User {
protected:
	string imie;
	string nazwisko;
	string profesja;

public:
	void wypisz_uzytkownika() {
		cout << "Uzytkownik " << imie << " " << nazwisko << " | Rola: " << profesja << endl;
	}
	virtual string zwroc_dane() = 0;
};



struct Data {

	int godzina, minuta, dzien, miesiac, rok = NULL;
	Data() {};
	Data(int h, int m, int d, int mth, int yr) {
		if (h >= 0 && h < 24 && m >= 0 && m < 60 && d > 0 && d < 31 && mth > 0 && mth < 13 && yr > 2020)
		{
			godzina = h;
			minuta = m;
			dzien = d;
			miesiac = mth;
			rok = yr;
		}
		else
		{
			cout << "BLEDNIE WPROWADZONA DATA!" << endl;
		}
	}
	Data(int d, int m, int y) {
		if (d > 0 && d < 31 && m > 0 && m < 13 && y > 2020)
		{
			dzien = d;
			miesiac = m;
			rok = y;
		}
		else
		{
			cout << "BLEDNIE WPROWADZONA DATA!" << endl;
		}

	}
	void wpisz_date_ogolna() {
		cout << "Podaj date ( D M R ): ";
		cin >> dzien;
		cin >> miesiac;
		cin >> rok;

		if (dzien > 0 && dzien < 31 && miesiac > 0 && miesiac < 13 && rok > 2020)
		{
				//cout << "Data zostala zapisana!" << endl;
		}
		else {
			cout << "BLEDNIE WPROWADZONA DATA!" << endl;
			dzien = NULL;
			miesiac = NULL;
			rok = NULL;
		}
	}
	void wpisz_date_szczegolowa() {
		cout << "Podaj date ( D M R ): " << endl;
		cin >> dzien;
		cin >> miesiac;
		cin >> rok;
		cout << "Podaj godzine ( H M ): " << endl;
		cin >> godzina;
		cin >> minuta;

		if (dzien > 0 && dzien < 31 && miesiac > 0 && miesiac < 13 && rok > 2020 && godzina >= 0 && godzina < 25 && minuta >= 0 && minuta < 65)
		{
				//cout << "Data zostala zapisana!" << endl;
		}
		else {
			cout << "BLEDNIE WPROWADZONA DATA!" << endl;
			dzien = NULL;
			miesiac = NULL;
			rok = NULL;
			minuta = NULL;
			godzina = NULL;
		}
	}
};

class Klient :public User {
private:
	int ID;
	string email;
public:
	string zwroc_dane() {
		string dane_klienta = imie + " " + nazwisko;
		return dane_klienta;
	}
	int zwroc_ID() {                               // zwraca ID
		return ID;
	}
	void wprowadz_dane() {
		cout << "Podaj imie: ";
		cin >> imie;
		cout << "Podaj nazwisko: ";
		cin >> nazwisko;
		cout << "Podaj email: ";
		cin >> email;
		ID = 100000 + rand() % 899999;              //dodanie generacji ID 
		profesja = "Klient";                        // i profesji
	}
	Klient() {
		imie = "Niezidentyfikowany";
		nazwisko = "Klient";
		email = "brak informacji";
		ID = NULL;
		profesja = "Klient";
	}
	Klient(string i, string n, string e) {
		imie = i;
		nazwisko = n;
		email = e;
		ID = 100000 + rand() % 899999;
		profesja = "Klient";
	}
};

class Kierownik :public User {
public:
	string zwroc_dane() {
		string dane_pracownika = "(Kierownik) " + imie + " " + nazwisko;
		return dane_pracownika;
	}
	Kierownik() {
		imie = "Daniel";
		nazwisko = "Klata";
		profesja = "Kierownik";
	}
	Kierownik(string i, string n) {
		imie = i;
		nazwisko = n;
		profesja = "Kierownik";
	}
	void potwierdz_zakwaterowanie(int ID_klienta) {

	}
	void potwierdz_wykwaterowanie(int ID_klienta) {

	}
};
class Kelner :public User {
public:
	string zwroc_dane() {
		string dane_pracownika = "(Kelner) " + imie + " " + nazwisko;
		return dane_pracownika;
	}
	Kelner() {
		imie = "Niezidentyfikowany";
		nazwisko = "Pracownik";
		profesja = "Kelner";
	}
	Kelner(string i, string n) {
		imie = i;
		nazwisko = n;
		profesja = "Kelner";
	}
	void zmiana_statusu_zamowienia(int nr_zamowienia, string nowy_status) {

	}
	void odbierz_zamowienie(Zamowienie zamowienie) {

	}
};

struct Rezerwacja_spa
{
	Data data;
	string usluga;
	int numer_ID, na_ile; // na_ile w minutach
};

class Spa :public Rezerwacja_spa {
	Rezerwacja_spa lista;
public:
		Spa() {}

		Spa(string u, int id, int g, int m, int d, int mth, int y, int ile)
	{
		usluga = u;
		numer_ID = id;
		data.godzina = g;
		data.minuta = m;
		data.dzien = d;
		data.miesiac = mth;
		data.rok = y;
		na_ile = ile;
	}

	void wyswietl_rezerwacje(vector<Spa> lista)
	{
		cout << "Zajete terminy: " << endl;
		for (int i = 0; i < lista.size(); i++)
		{
			cout << "Od " << lista[i].data.godzina << ":" << lista[i].data.minuta << " " << lista[i].data.dzien << "." << lista[i].data.miesiac << "." << lista[i].data.rok << " do ";
			if (lista[i].data.minuta + lista[i].na_ile >= 60)
			{
				lista[i].data.godzina = lista[i].data.godzina + 1;
				lista[i].data.minuta = lista[i].data.minuta + lista[i].na_ile - 60;
				cout << lista[i].data.godzina << ":" << lista[i].data.minuta << " " << lista[i].data.dzien << "." << lista[i].data.miesiac << "." << lista[i].data.rok << endl;
			}
			else {
				cout << lista[i].data.godzina << ":" << lista[i].data.minuta + lista[i].na_ile << " " << lista[i].data.dzien << "." << lista[i].data.miesiac << "." << lista[i].data.rok << endl;
			}
		}
	}

		void dodaj_rezerwacje(int id)
	{
		cout << "Podaj date na ktora chcesz zarezerwowac miejsce" << endl;
		data.wpisz_date_szczegolowa();
		cout << "Podaj rodzaj uslugi (BASEN/SAUNA): ";
		cin >> usluga;
		cout << "Podaj na ile chcesz dokonac rezerwacji (w minutach): ";
		cin >> na_ile;
		cout << "\nTwoja rezerwacja zostala zapisana!" << endl;
	}


};

//funkcja porownojaca dwie daty, wykorzystywana przy sprawdzaniu dostepnosci przy rezerwacji pokoju
//zwraca 1 jesli pierwsza data jest pozniejsza, zwraca 2 jesli druga data jest pozniejsza, zwraca 0 jesli sa rowne
inline int cmp_date(Data data1, Data data2) {
	if (data1.rok > data2.rok) {
		return 1;
	}
	else if (data1.rok < data2.rok) {
		return 2;
	}
	else if (data1.miesiac > data2.miesiac) {
		return 1;
	}
	else if (data1.miesiac < data2.miesiac) {
		return 2;
	}
	else if (data1.dzien > data2.dzien) {
		return 1;
	}
	else if (data1.dzien < data2.dzien) {
		return 2;
	}
	else {
		return 0;
	}
}

struct Dostepnosc_pokoju {
	vector<Data> poczatek;
	vector<Data> koniec;
};

class Pokoj {
public:
	int nr_pokoju = NULL;
	float cena = NULL;
	int max_ilosc_osob = NULL;
	Dostepnosc_pokoju lista_dostepnosci;

	bool sprawdz_dostepnosc(Data data_uzytkownia_p, Data data_uzytkownia_k) {


		for (int i = 0; i < lista_dostepnosci.poczatek.size(); i++) {
			if (((cmp_date(data_uzytkownia_p, lista_dostepnosci.poczatek[i]) == 1) && (cmp_date(data_uzytkownia_p, lista_dostepnosci.koniec[i]) == 2)) ||
				((cmp_date(data_uzytkownia_k, lista_dostepnosci.poczatek[i]) == 1) && (cmp_date(data_uzytkownia_k, lista_dostepnosci.koniec[i]) == 2)) ||
				((cmp_date(lista_dostepnosci.poczatek[i], data_uzytkownia_p) == 1) && (cmp_date(lista_dostepnosci.poczatek[i], data_uzytkownia_k) == 2)) ||
				((cmp_date(lista_dostepnosci.koniec[i], data_uzytkownia_p) == 1) && (cmp_date(lista_dostepnosci.koniec[i], data_uzytkownia_k) == 2))
				) {

				cout << "Data od " << lista_dostepnosci.poczatek[i].dzien << "." << lista_dostepnosci.poczatek[i].miesiac << "." << lista_dostepnosci.poczatek[i].rok << " do " << lista_dostepnosci.koniec[i].dzien << "." << lista_dostepnosci.koniec[i].miesiac << "." << lista_dostepnosci.koniec[i].rok << " jest zajeta" << endl;
				return false;
			}
		}
		cout << "Podana data jest dostepna!" << endl;
		return true;

	}

	Pokoj() {}
	Pokoj(int nr, float c, int max) {
		nr_pokoju = nr;
		cena = c;
		max_ilosc_osob = max;

	}
	Pokoj(int nr, float c, int max, Dostepnosc_pokoju ld) {
		nr_pokoju = nr;
		cena = c;
		max_ilosc_osob = max;
		lista_dostepnosci = ld;
	}

};

class Rezerwacja_pokoju {
private:

	Data data_poczatku;
	Data data_konca;
	Pokoj zarezerwowany_pokoj;
	bool dokonano_rezerwacji = false;
public:

	void wybierz_pokoj(vector<Pokoj> lista_pokojow)
	{
		int nr_pokoju;
		for (int i = 0; i < lista_pokojow.size(); i++) {
			cout << "Pokoj [" << i + 1 << "] | cena: " << lista_pokojow[i].cena << "PLN | maksymalna ilosc osob w pokoju: " << lista_pokojow[i].max_ilosc_osob << endl;
		}
		cout << "Wybierz pokoj: " << endl;
		cin >> nr_pokoju;
		Data data_uzytkownia_p, data_uzytkownia_k;
		cout << "Data poczatku pobytu: " << endl;
		data_uzytkownia_p.wpisz_date_ogolna();
		cout << "Data konca pobytu: " << endl;
		data_uzytkownia_k.wpisz_date_ogolna();
		rezerwacja_pokoju(nr_pokoju, data_uzytkownia_p, data_uzytkownia_k, lista_pokojow);
	}


	void remove(vector<Data>& vec, size_t pos)
	{
		vector<Data>::iterator it = vec.begin();
		advance(it, pos);
		vec.erase(it);
	}
	void usun_rezerwacje() {
		if (dokonano_rezerwacji != false) {

			for (int i = 0; i < zarezerwowany_pokoj.lista_dostepnosci.poczatek.size(); i++) {

				if (data_poczatku.dzien == zarezerwowany_pokoj.lista_dostepnosci.poczatek[i].dzien && data_poczatku.miesiac == zarezerwowany_pokoj.lista_dostepnosci.poczatek[i].miesiac && data_poczatku.rok == zarezerwowany_pokoj.lista_dostepnosci.poczatek[i].rok) {

					remove(zarezerwowany_pokoj.lista_dostepnosci.poczatek, i);
					remove(zarezerwowany_pokoj.lista_dostepnosci.koniec, i);
					//zarezerwowany_pokoj.lista_dostepnosci.poczatek.erase(zarezerwowany_pokoj.lista_dostepnosci.poczatek.begin() + i);
					//zarezerwowany_pokoj.lista_dostepnosci.poczatek.erase(zarezerwowany_pokoj.lista_dostepnosci.koniec.begin() + i);
					dokonano_rezerwacji = false;
				}


			}

			//remove(zarezerwowany_pokoj.lista_dostepnosci.poczatek.begin(), zarezerwowany_pokoj.lista_dostepnosci.poczatek.end(), data_poczatku);
			//remove(zarezerwowany_pokoj.lista_dostepnosci.koniec.begin(), zarezerwowany_pokoj.lista_dostepnosci.koniec.end(), data_konca);
		}
	}
	void modyfikuj_rezerwacje() {
		if (dokonano_rezerwacji != false) {
			int a;
			cout << "Co chcesz zrobic ze swoja rezerwacja?" << endl;
			cout << "[1] usun" << endl;
			cout << "[2] zmien date" << endl;
			cin >> a;
			if (a == 1) {
				usun_rezerwacje();
			}
			else if (a == 2) {
				zmien_date();
			}
		}
	}
	void zmien_date() {
		Data n_data_p, n_data_k;
		cout << "Twoja obecna data rezerwacji: " << data_poczatku.dzien << "." << data_konca.miesiac << "." << data_konca.rok << endl;
		cout << "Wprowadz nowa date:" << endl;
		cout << "Poczatek: ";
		n_data_p.wpisz_date_ogolna();
		cout << "Koniec: ";
		n_data_k.wpisz_date_ogolna();
		if (zarezerwowany_pokoj.sprawdz_dostepnosc(n_data_p, n_data_k) == true) {
			potwierdz_modyfikacje(n_data_p, n_data_k);
		}
	}
	bool rezerwacja_pokoju(int nr, Data p, Data k, vector<Pokoj> lista_pokojow) {
		if (lista_pokojow[nr - 1].sprawdz_dostepnosc(p, k) == true) {
			/*
			if (a == 1) {
				zarezerwowany_pokoj = lista_pokojow[nr_pokoju - 1];
				potwierdz_rezerwacje(nr_pokoju, data_uzytkownia_p, data_uzytkownia_k);
			}
			if (a == 2) {
				cout << "Rezerwacja anulowana" << endl;
			}
			*/
			cout << "Rezerwacja potwierdzona" << endl;
			data_poczatku = p;
			data_konca = k;
			zarezerwowany_pokoj = lista_pokojow[nr - 1];
			zarezerwowany_pokoj.lista_dostepnosci.poczatek.push_back(p);
			zarezerwowany_pokoj.lista_dostepnosci.koniec.push_back(k);
			dokonano_rezerwacji = true;
			return true;
		}
		else {
			return false;
		}

	}
	void potwierdz_modyfikacje(Data p, Data k) {
		data_poczatku = p;
		data_konca = k;
		usun_rezerwacje();
		zarezerwowany_pokoj.lista_dostepnosci.poczatek.push_back(p);
		zarezerwowany_pokoj.lista_dostepnosci.koniec.push_back(k);
		dokonano_rezerwacji = true;
	}
	bool get_dokonano_rezerwacji()
	{
		return dokonano_rezerwacji;
	}
	bool obsluga_platnosci() {}

};