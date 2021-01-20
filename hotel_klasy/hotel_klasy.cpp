﻿#include <iostream>
#include <time.h>
//#include "header.h"
#include <vector>
#include <string>
#include <cstdlib>
#pragma once
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

class Obecny_pobyt_klienta;

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

	string zwroc_dane_spa()
	{
		return usluga + " " + to_string(numer_ID) + " " + to_string(data.godzina) + ":" + to_string(data.minuta) + " " + to_string(data.dzien) + "." + to_string(data.miesiac) + "." + to_string(data.rok) + " na: " + to_string(na_ile) + " minut";
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

	void dodaj_rezerwacje(int id, string u)
	{
		cout << "Podaj date na ktora chcesz zarezerwowac miejsce" << endl;
		data.wpisz_date_szczegolowa();
		usluga = u;
		cout << "\nPodaj na ile chcesz dokonac rezerwacji (w minutach): ";
		cin >> na_ile;

		int wybor;
		cout << "Aby potwierdzic rezerwacje wybierz '1', aby zmodyfikowac wybierz '2': ";
		cin >> wybor;
		if (wybor == 1)
		{
			cout << "\nTwoja rezerwacja zostala zapisana!" << endl;
		}
		else if (wybor == 2)
		{
			dodaj_rezerwacje(id, u);
		}
	}

};

inline int ilosc_dni(int y, int m, int d) {
	if (m < 3)
		y--, m += 12;
	return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}

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

inline void remove(vector<Data>& vec, size_t pos)
{
	vector<Data>::iterator it = vec.begin();
	advance(it, pos);
	vec.erase(it);
}

class Rezerwacja_pokoju {
public:

	Data data_poczatku;
	Data data_konca;
	Pokoj zarezerwowany_pokoj;
	bool dokonano_rezerwacji = false;

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



	void usun_rezerwacje() {
		if (dokonano_rezerwacji != false) {

			for (int i = 0; i < zarezerwowany_pokoj.lista_dostepnosci.poczatek.size(); i++) {

				if (data_poczatku.dzien == zarezerwowany_pokoj.lista_dostepnosci.poczatek[i].dzien && data_poczatku.miesiac == zarezerwowany_pokoj.lista_dostepnosci.poczatek[i].miesiac && data_poczatku.rok == zarezerwowany_pokoj.lista_dostepnosci.poczatek[i].rok) {

					remove(zarezerwowany_pokoj.lista_dostepnosci.poczatek, i);
					remove(zarezerwowany_pokoj.lista_dostepnosci.koniec, i);
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
	//metoda zwracajaca status rezerwacji, wykorzystana tylko dla Google Testów
	bool get_dokonano_rezerwacji()
	{
		return dokonano_rezerwacji;
	}

	bool obsluga_platnosci() {


		int dlugosc_pobytu = ilosc_dni(data_konca.rok, data_konca.miesiac, data_konca.dzien) - ilosc_dni(data_poczatku.rok, data_poczatku.miesiac, data_poczatku.dzien);

		if (data_konca.dzien - data_poczatku.dzien)
			cout << "Koszt wybranego pokoju wynosi " << zarezerwowany_pokoj.cena << " za dobe, twoj pobyt trwa " << dlugosc_pobytu << " dni." << endl;
		cout << "Calkowity koszt wyniesie " << dlugosc_pobytu * zarezerwowany_pokoj.cena << " PLN" << endl;
		cout << "Teraz pobrana zostanie połowa kwoty, czyli " << (dlugosc_pobytu * zarezerwowany_pokoj.cena)/2 << " PLN, druga połowa płatna przy wykwaterowaniu." << endl;
		cout << "Czy chcesz dokonac platnosci? " << endl << "[1] tak" << endl << "[2] nie" << endl;
		int decyzja;
		cin >> decyzja;
		if (decyzja == 1) {
			return true;
		}
		else
		{
			usun_rezerwacje();
			return false;
		}

	}

};




class Obecny_pobyt_klienta {

public:
	float saldo = 0;

	inline void rozpocznij_pobyt(Rezerwacja_pokoju& rezerwacja) {

		int dlugosc_pobytu = ilosc_dni(rezerwacja.data_konca.rok, rezerwacja.data_konca.miesiac, rezerwacja.data_konca.dzien) - ilosc_dni(rezerwacja.data_poczatku.rok, rezerwacja.data_poczatku.miesiac, rezerwacja.data_poczatku.dzien);

		saldo = (dlugosc_pobytu*rezerwacja.zarezerwowany_pokoj.cena)/2;

	};

	inline bool sprawdz_czy_przekroczono_termin(Rezerwacja_pokoju rezerwacja) {

		Data data;
		data.wpisz_date_ogolna();

		if (cmp_date(rezerwacja.data_konca, data) == 1) {

			nalicz_kare(rezerwacja, data);
			cout << endl << "Data zostala przekroczona." << endl;
			return true;

		}
		else cout << endl << "Data nie zostala przekroczona." << endl; return false;

		
	};

	inline void nalicz_kare(Rezerwacja_pokoju& rezerwacja, Data& data) {

		cout << "Przekroczono date pobytu, do rachunku zostanie naliczona kara." << endl;
		cout << "Saldo rachunku przed naliczeniem kary: " << saldo << " zl." << endl;

		int kara = 25;
		int dlugosc_bezprawnego_pobytu = ilosc_dni(data.rok,data.miesiac, data.dzien) - ilosc_dni(rezerwacja.data_konca.rok, rezerwacja.data_konca.miesiac, rezerwacja.data_konca.dzien);
		saldo += dlugosc_bezprawnego_pobytu * kara;
		
		cout << "Saldo rachunku po naliczeniu kary (koncowa kwota do zaplaty): " << saldo << " zl." << endl;


	};

	inline float sprawdz_stan_rachunku() {

		cout << "Saldo rachunku wynosi: " << saldo << " zl." << endl;

		return saldo;
	};

	inline void oplac_naleznosc() {
		int kwota;
		cout << endl << "Witamy w funkcji oplaty za pobyt!" << endl;
		cout << "Naleznosc za pobyt wynosi: " << saldo << " zl. " << endl;

		for (; ;) {
			cout << "Wpisz kwote jaka wplacasz: ";
			cin >> kwota;

			if (kwota < saldo) {
				cout << "Wplacona kwota jest za mala. " << endl;

			}

			else if (kwota > saldo) {
				cout << "Wplacona kwota jest wyzsza od naleznosci. Zwracamy reszte w wysokosci " << kwota - saldo << " zl." << endl;
				saldo = 0;
				cout << "Dziekujemy i zyczymy milego dnia!" << endl;
				return;


			}

			else if (kwota == saldo) {

				cout << "Dziekujemy za wplate. Zyczymy milego dnia! " << endl;
				saldo = 0;
				return;

			}
		}



	};

};

class Klient :public User {
private:
	int ID;
	bool zakwaterowany=false;
	Obecny_pobyt_klienta pobyt;
	Rezerwacja_pokoju rezerwacja;
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
	friend class Kierownik;
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
	void potwierdz_zakwaterowanie(int ID_klienta, vector<Klient>& lista_klientow) {
		
		for (int i = 0; i < lista_klientow.size(); i++) {
			if (lista_klientow[i].zwroc_ID() == ID_klienta) {
				lista_klientow[i].pobyt.rozpocznij_pobyt(lista_klientow[i].rezerwacja);
				lista_klientow[i].zakwaterowany = true;
				return;
			}
		}
		cout << "Klient o podanym ID nie istnieje! " << endl;

	}
	void potwierdz_wykwaterowanie(int ID_klienta, vector<Klient>& lista_klientow) {
		for (int i = 0; i < lista_klientow.size(); i++) {
			if (lista_klientow[i].zwroc_ID() == ID_klienta) {

				if (lista_klientow[i].pobyt.sprawdz_stan_rachunku() == 0) {
					lista_klientow[i].zakwaterowany == false;
					lista_klientow[i].rezerwacja.usun_rezerwacje();
				}
				else if (lista_klientow[i].pobyt.sprawdz_czy_przekroczono_termin(lista_klientow[i].rezerwacja) == true) {
					while (lista_klientow[i].pobyt.saldo != 0) {
						lista_klientow[i].pobyt.oplac_naleznosc();
					}
					lista_klientow[i].zakwaterowany == false;
					lista_klientow[i].rezerwacja.usun_rezerwacje();
				}
			}
		}
	}
};

struct Posilek {

	int nr_posilku = 0;
	string nazwa_posilku = "brak nazwy";
	float cena = 0.0;

};





class Zamowienie {
public:

	string status = "W trakcie";
	int nr_pokoju = 0;
	int nr_zamowienia = 0;
	vector <Posilek> koszyk;

	void potwierdz_zamowienie(vector <Zamowienie> lista_zamowien, Zamowienie& zamowienie, Obecny_pobyt_klienta& ob);  //metoda potweirdzenia zamowienia 
	void dodaj_do_koszyka(vector <Posilek>& koszyk, Posilek posilek);


};




class Kuchnia {
public:

	Posilek menu[5] = { {1, "Zupa pomidorowa", 10.0}, {2, "Nalesniki z serem", 15.0}, {3, "Salatka grecka", 17.0}, {4, "Ziemniaczki w mundurkach", 12.0}, {5, "Fasola po bretonsku", 20.0} };
	vector <Zamowienie> lista_zamowien;


	void wyswietl_menu();
	void zamow_jedzenie(Zamowienie z, Obecny_pobyt_klienta& ob);
	void dodaj_do_listy(vector <Zamowienie> lista_zamowien, Zamowienie zamowienie);
	Posilek zwroc_info_o_posilku(int nr); //metoda zwracajaca informacje o posilku - nazwa, cena ?? NUMER

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
	void zmiana_statusu_zamowienia(int nr_zamowienia, string nowy_status, vector <Zamowienie> &lista_zamowien) {
		for (int i = 0; i < lista_zamowien.size(); i++) {
			if (lista_zamowien[i].nr_zamowienia == nr_zamowienia) {
				lista_zamowien[i].status == nowy_status;
				return;
			}
		}
		cout << "Zamowienie o podanym numerze nie istnieje" << endl;

	}
	//void odbierz_zamowienie(Zamowienie zamowienie) {

	//}
};


//funkcja dodajcac posilek do zamowienia 
inline void Zamowienie::dodaj_do_koszyka(vector <Posilek>& koszyk, Posilek posilek) {

	koszyk.push_back(posilek);

}

//funckja dodajaca zamowienie do listy 
inline void dodaj_do_listy(vector <Zamowienie> lista_zamowien, Zamowienie& zamowienie) {

	lista_zamowien.push_back(zamowienie);

}


//metoda klasy Posilek zwracajaca informacje o posilku - dodatkowo NUMER
inline Posilek Kuchnia::zwroc_info_o_posilku(int nr) {
	int i = 1;
	while (i <= 5) {
		if (nr == menu[i - 1].nr_posilku) {

			return menu[i - 1];
		}
		else i++;
	}

}
//metoda klasy Zamowienie generujaca numer zamowienia 
inline void Zamowienie::potwierdz_zamowienie(vector <Zamowienie> lista_zamowien, Zamowienie& zamowienie, Obecny_pobyt_klienta& ob) {



	//generowanie numeru zamowienia
	srand(time(NULL));

	zamowienie.nr_zamowienia = (rand() % 100) + 1;


	//wyswietlenie informacji o zamowieniu
	cout << "Szczegoly zlozonego zamowienia:" << endl;
	int i, wybor;


	cout << "Numer pokoju: " << zamowienie.nr_pokoju << endl;
	cout << "Numer zamowienia: " << zamowienie.nr_zamowienia << endl;
	cout << "Status: " << zamowienie.status << endl;
	cout << "Posilki: ";
	cout << koszyk.size() << endl;

	for (i = 0; i < koszyk.size(); i++) {

		cout << koszyk[i].nr_posilku << ". " << koszyk[i].nazwa_posilku << " - " << koszyk[i].cena << "zl." << endl;
		ob.saldo += koszyk[i].cena; //dodanie kwoty do salda
	}
	cout << "Saldo: " << ob.saldo << " zl." << endl;
	cout << "[1] Potwierdz zamowienie" << endl << "[2] Anuluj zamowienie (wszystkie wybrane posilki zostana bezpowrotnie usuniete z listy)" << endl;

	for (;;) {
		cout << "Wybor: ";
		cin >> wybor;

		if (wybor == 1) {

			dodaj_do_listy(lista_zamowien, zamowienie);
			cout << "Zamowienie potwierdzone!" << endl;
			return;
		}
		else if (wybor == 2) {
			cout << "Zamowienie anulowane" << endl;
			koszyk.clear();
			return;
		}
		else cout << "Nie ma takiego wyboru!" << endl;

	}
}


//wyswietlanie tablicy posilkow
inline void Kuchnia::wyswietl_menu() {


	cout << "	MENU" << endl;
	int i;
	for (i = 0; i < 5; i++) {
		cout << menu[i].nr_posilku << ". " << menu[i].nazwa_posilku << " - " << menu[i].cena << " zl. " << endl;

	}

}


inline void Kuchnia::zamow_jedzenie(Zamowienie z1, Obecny_pobyt_klienta& ob) {
	int w, nr, s;

	wyswietl_menu();

	for (;;) {



		cout << "[1] Dodaj potrawe do koszyka" << endl;
		cout << "[2] Wyswietl koszyk i potwierdz zamowienie " << endl << "[3] Anuluj zamowienie" << endl;
		cout << "Wybor: ";
		cin >> w;


		switch (w) {

		case 1:

			for (;;) {
				cout << "Podaj numer potrawy ktora chcesz zamowic: ";
				cin >> nr;

				if (nr >= 6) {
					cout << "Nie ma potrawy o takim numerze!" << endl;



				}
				else if (nr < 6) {
					z1.dodaj_do_koszyka(z1.koszyk, zwroc_info_o_posilku(nr));
					cout << "Pomyslnie dodano do koszyka! Wybierz kolejne akcje" << endl;
					break;
				}



			}

			break;

		case 2:
			system("cls");
			z1.potwierdz_zamowienie(lista_zamowien, z1, ob);
			return;

			break;

		case 3:
			cout << "Zrezygnowano ze skladania zamowienia." << endl;

			return;
			break;

		default:
			cout << "Nie ma takiego wyboru!" << endl;

			break;

		}

	}
	return;
}
