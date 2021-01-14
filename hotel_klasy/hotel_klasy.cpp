#include <iostream>
#include <time.h>
#include "header.h"
using namespace std;
//klasa abstrakcyjna z której dziedziczyć będą klasy Kelner, Klient i Kierownik
class User{
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

class Klient :public User {
private:
	int ID;
	string email;
public:
	string zwroc_dane() {
		string dane_klienta = imie + " " + nazwisko;
		return dane_klienta;
	}
	void wprowadz_dane() {
		cout << "Podaj imie: ";
		cin >> imie;
		cout  << "Podaj nazwisko: ";
		cin >> nazwisko;
		cout  << "Podaj email: ";
		cin >> email;
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
		string dane_pracownika = "(Kierownik) " + imie + " " + nazwisko;
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