#include <iostream>
#include <time.h>
#include "header.h"
<<<<<<< Updated upstream
=======
#include <vector>
#include <string>

>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
			cout << "Data zostala zapisana!" << endl;
=======
			//cout << "Data zostala zapisana!" << endl;
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
			cout << "Data zostala zapisana!" << endl;
=======
			//cout << "Data zostala zapisana!" << endl;
>>>>>>> Stashed changes
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

struct Rezerwacja_spa
{
	Data data;
	string usluga;
	int numer_ID, na_ile; // na_ile w minutach
};

class Spa :public Rezerwacja_spa {
	Rezerwacja_spa lista;
public:
<<<<<<< Updated upstream
	Spa(){}
=======
	Spa() {}
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
	/*
	void dodaj_rezerwacje(vector<Spa> *lista2, string u, int id, int g, int m, int d, int mth, int y, int ile)
	{
		cout << "Podaj czas na ktory chcesz zarezerwowac miejsce" << endl;
		cout << "Podaj godzine: ";
		cin >> data.godzina;
		cout << "\nPodaj minute: ";
		cin >> data.minuta;
		cout << "\nPodaj dzien: ";
		cin >> data.dzien;
		cout << "\nPodaj miesiac: ";
		cin >> data.miesiac;
		cout << "\nPodaj rok: ";
		cin >> data.rok;
		cout << endl;
		int rozmiar = <int>lista.size();
		lista2[rozmiar] = u;
		lista2[rozmiar].numer_ID = id;
		lista2[rozmiar].data.godzina = g;
		lista2[rozmiar].data.minuta = m;
		lista2[rozmiar].data.dzien = d;
		lista2[rozmiar].data.miesiac = mth;
		lista2[rozmiar].data.rok = y;
		lista2[rozmiar].na_ile = ile;
	}*/
=======
	
	void dodaj_rezerwacje(int id)
	{
		cout << "Podaj data na ktora chcesz zarezerwowac miejsce" << endl;
		data.wpisz_date_szczegolowa();
		cout << "Podaj rodzaj uslugi (BASEN/SAUNA): ";
		cin >> usluga;
		cout << "Podaj na ile chcesz dokonac rezerwacji (w minutach): ";
		cin >> na_ile;
		cout << "\nTwoja rezerwacja zostala zapisana!" << endl;
	}
>>>>>>> Stashed changes





	/*void dodaj_rezerwacje(string usluga, int numer_ID, int godzina, int minuta, int dzien, int miesiac, int rok, int na_ile)
	{
<<<<<<< Updated upstream
		
=======

>>>>>>> Stashed changes
		nodetoadd->numer_ID = numer_ID;
		nodetoadd->data.godzina = godzina;
		nodetoadd->data.minuta = minuta;
		nodetoadd->data.dzien = dzien;
		nodetoadd->data.miesiac = miesiac;
		nodetoadd->data.rok = rok;
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
	}*/
	/*
	void usun_rezerwacje(int godzina, Rezerwacja_spa*& head)
	{
		Rezerwacja_spa* pom = new Rezerwacja_spa;
		pom = head;
		if (head == NULL)
		{
<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
		}
		else
		{
			Rezerwacja_spa* pom2 = new Rezerwacja_spa;
			pom2 = head->next;
			while (pom2->next != NULL && godzina != pom2->data.godzina)
			{
				pom = pom->next;
				pom2 = pom2->next;
			}
			pom->next = pom2->next;
			delete pom2;
		}
	}*/
	/*
	void potwiedz_rezerwacje(string usluga, int numer_ID, int godzina, int minuta, int dzien, int miesiac, int rok, int na_ile, Rezerwacja_spa*& head)
	{
		cout << "Twoja rezerwacja " << usluga << " zaczyna sie od: " << godzina << ":" << minuta << " " << dzien << "." << miesiac << "." << rok << " do ";
		if (minuta + na_ile >= 60)
		{
			godzina = godzina + 1;
			minuta = minuta + na_ile - 60;
			cout << godzina << ":" << minuta << " " << dzien << "." << miesiac << "." << rok << endl;
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
			dodaj_rezerwacje(usluga, numer_ID, godzina, minuta, dzien, miesiac, rok, na_ile, head);
		}
		else {
			cout << "Twoja rezeracja nie zostala zapisana!" << endl;
		}
	}*/

};
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
=======


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
>>>>>>> Stashed changes

struct Dostepnosc_pokoju {
	vector<Data> poczatek;
	vector<Data> koniec;
};

class Pokoj {
public:
	int nr_pokoju=NULL;
	float cena = NULL;
	int max_ilosc_osob = NULL;
	Dostepnosc_pokoju lista_dostepnosci;

	bool sprawdz_dostepnosc(Data data_uzytkownia_p, Data data_uzytkownia_k) {


		for (int i = 0; i < lista_dostepnosci.poczatek.size(); i++) {
			if ((data_uzytkownia_p.dzien > lista_dostepnosci.poczatek[i].dzien && data_uzytkownia_p.dzien < lista_dostepnosci.koniec[i].dzien)|| (data_uzytkownia_k.dzien > lista_dostepnosci.poczatek[i].dzien && data_uzytkownia_k.dzien < lista_dostepnosci.koniec[i].dzien)) {
				cout << "Data od " << lista_dostepnosci.poczatek[i].dzien << "." << lista_dostepnosci.poczatek[i].miesiac << "." << lista_dostepnosci.poczatek[i].rok << " do " << lista_dostepnosci.koniec[i].dzien << "." << lista_dostepnosci.koniec[i].miesiac << "." << lista_dostepnosci.koniec[i].rok << " jest zajeta" << endl;
				return false;
			}
		}
		cout << "Podana data jest dostepna!" << endl;
		return true;

	}
	Pokoj(){}
	Pokoj(int nr, float c, int max) {
		nr_pokoju = nr;
		cena = c;
		max_ilosc_osob = max;
		//lista_dostepnosci = ld;
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
	int nr_rezerwacji = NULL;
public:
	
	void zarezerwuj_pokoj(vector<Pokoj> lista_pokojow)
	{
		int nr_pokoju;
		for (int i = 0; i < lista_pokojow.size(); i++) {
			cout << "Pokoj [" << i+1 << "] | cena: " << lista_pokojow[i].cena << "PLN | maksymalna ilosc osob w pokoju: " << lista_pokojow[i].max_ilosc_osob << endl;
		}
		cout << "Wybierz pokoj: " << endl;
		cin >> nr_pokoju;
		Data data_uzytkownia_p, data_uzytkownia_k;
		cout << "Data poczatku pobytu: " << endl;
		data_uzytkownia_p.wpisz_date_ogolna();
		cout << "Data konca pobytu: " << endl;
		data_uzytkownia_k.wpisz_date_ogolna();
		if (lista_pokojow[nr_pokoju - 1].sprawdz_dostepnosc(data_uzytkownia_p, data_uzytkownia_k) == true) {
			int a;
			cout << "Potwierdz rezerwacje - 1 " << endl;
			cout << "Anuluj rezerwacje - 2 " << endl;
			cin >> a;
			if (a == 1) {

				zarezerwowany_pokoj = lista_pokojow[nr_pokoju - 1];
				potwierdz_rezerwacje(nr_pokoju, data_uzytkownia_p, data_uzytkownia_k);
			}
			if (a == 2) {
				cout << "Rezerwacja anulowana" << endl;
			}
		}
	}
	//void potwierdz_rezerwacje() {}
	void usun_rezerwacje(){
		if (nr_rezerwacji != NULL) {

			zarezerwowany_pokoj.lista_dostepnosci.poczatek.erase(zarezerwowany_pokoj.lista_dostepnosci.poczatek.begin() + nr_rezerwacji-1);
			zarezerwowany_pokoj.lista_dostepnosci.poczatek.erase(zarezerwowany_pokoj.lista_dostepnosci.poczatek.begin() + nr_rezerwacji-1);
		}
	}
	void modyfikuj_rezerwacje() {
		if (nr_rezerwacji != NULL) {
			int a;
			cout << "Co chcesz zrobic ze swoja rezerwacja?" << endl;
			cout << "[1] usun" << endl;
			cout << "[2] zmien date" << endl;
			cin >> a;
			if (a==1) {
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
	void potwierdz_rezerwacje(int nr, Data p, Data k) {
		cout << "Rezerwacja potwierdzona" << endl;
		data_poczatku = p;
		data_konca = k;
		zarezerwowany_pokoj.lista_dostepnosci.poczatek.push_back(p);
		zarezerwowany_pokoj.lista_dostepnosci.koniec.push_back(k);
		nr_rezerwacji = zarezerwowany_pokoj.lista_dostepnosci.poczatek.size();
	}
	void potwierdz_modyfikacje(Data p, Data k) {
		data_poczatku = p;
		data_konca = k;
		usun_rezerwacje();
		zarezerwowany_pokoj.lista_dostepnosci.poczatek.push_back(p);
		zarezerwowany_pokoj.lista_dostepnosci.koniec.push_back(k);
		nr_rezerwacji = zarezerwowany_pokoj.lista_dostepnosci.poczatek.size();
	}
	bool obsluga_platnosci() {}

};
>>>>>>> Stashed changes
