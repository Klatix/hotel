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

struct Rezerwacja_spa
{
	Rezerwacja_spa* next;
	int numer_ID, godzina, minuta, dzien, miesiac, rok, na_ile; // na_ile w minutach
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
		cout  << "Podaj nazwisko: ";
		cin >> nazwisko;
		cout  << "Podaj email: ";
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

class Spa :public Rezerwacja_spa {
	Rezerwacja_spa listaRezerwacji;
public:
	void dodaj_rezerwacje(int numer_ID, int godzina, int minuta, int dzien, int miesiac, int rok, int na_ile, Rezerwacja_spa*& head)
	{
		Rezerwacja_spa* pom = new Rezerwacja_spa;
		pom = head;
		Rezerwacja_spa* nodetoadd = new Rezerwacja_spa;
		nodetoadd->numer_ID = numer_ID;
		nodetoadd->godzina = godzina;
		nodetoadd->minuta = minuta;
		nodetoadd->dzien = dzien;
		nodetoadd->miesiac = miesiac;
		nodetoadd->rok = rok;
		nodetoadd->na_ile = na_ile;

		if (head == NULL)
		{
			head = nodetoadd;
		}
		else
		{
			while (pom->next != NULL)
			{
				pom = pom->next;
			}
			nodetoadd->next = pom->next;
			pom->next = nodetoadd;
		}
	}

	void usun_rezerwacje(int godzina, Rezerwacja_spa*& head)
	{
		Rezerwacja_spa* pom = new Rezerwacja_spa;
		pom = head;

		if (head == NULL)
		{
			
		}
		else
		{
			Rezerwacja_spa* pom2 = new Rezerwacja_spa;
			pom2 = head->next;
			while (pom2->next != NULL && godzina != pom2->godzina)
			{
				pom = pom->next;
				pom2 = pom2->next;
			}
			pom->next = pom2->next;
			delete pom2;
		}
	}
	
	void potwiedz_rezerwacje(int numer_ID, int godzina, int minuta, int dzien, int miesiac, int rok, int na_ile, Rezerwacja_spa*& head)
		{
			cout << "Twoja rezerwacja zaczyna sie od: " << godzina << ":" << minuta << " " << dzien << "." << miesiac << "." << rok << " do ";
		if (minuta + na_ile >= 60) 
		{
			godzina = godzina + 1;
			minuta = minuta + na_ile - 60;
			cout << godzina  << ":" << minuta << " " << dzien << "." << miesiac << "." << rok << endl;
		}
		else {
			cout << godzina << ":" << minuta + na_ile << " " << dzien << "." << miesiac << "." << rok << endl;
		}

		cout << "Aby potwierdzic Twoja rezerwacje wpisz '1', aby odrzucic wpisz '2' " << endl;
		int wybor;
		cin >> wybor;
		cout << endl;
		if (wybor == 1)
		{
			cout << "Twoje rezerwacja zostala zapisana!" << endl;
			dodaj_rezerwacje(numer_ID, godzina, minuta, dzien, miesiac, rok, na_ile, head);
		}
		else {
			cout << "Twoja rezeracja nie zostala zapisana!" << endl;
		}
		}

};
