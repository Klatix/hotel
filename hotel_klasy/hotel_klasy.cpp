#include <iostream>
#include <time.h>
#include "header.h"
<<<<<<< Updated upstream
=======
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
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
<<<<<<< Updated upstream
=======

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
	
	void potwiedz_rezerwacje(int numer_ID, int godzina, int minuta, int dzien, int miesiac, int rok, int na_ile, Rezerwacja_spa*& head,obecny_pobyt_klienta &ob)
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
		//dodanie do salda
		ob.saldo += 2 * na_ile;

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
struct Data {

	int godzina, minuta, dzien, miesiac, rok = NULL;
	Data() {};
	Data(int h, int m, int d, int mth, int yr) {
		godzina = h;
		minuta = m;
		dzien = d;
		miesiac = mth;
		rok = yr;
	}
	Data(int d, int m, int y) {
		dzien = d;
		miesiac = m;
		rok = y;

	}
	void wpisz_date_ogolna() {
		cout << "Podaj date ( D M R ): ";
		cin >> dzien;
		cin >> miesiac;
		cin >> rok;
	}
	void wpisz_date_szczegolowa() {
		cout << "Podaj date ( D M R ): " <<endl;
		cin >> dzien;
		cin >> miesiac;
		cin >> rok;
		cout << "Podaj godzine ( H M ): " << endl;
		cin >> godzina;
		cin >> minuta;
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
	int nr_pokoju=NULL;
	float cena = NULL;
	int max_ilosc_osob = NULL;
	Dostepnosc_pokoju lista_dostepnosci;

	bool sprawdz_dostepnosc(Data data_uzytkownia_p, Data data_uzytkownia_k) {


		for (int i = 0; i < lista_dostepnosci.poczatek.size(); i++) {
			if ( ((cmp_date(data_uzytkownia_p, lista_dostepnosci.poczatek[i]) == 1) && (cmp_date(data_uzytkownia_p, lista_dostepnosci.koniec[i]) == 2)) ||
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

	Pokoj(){}
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
			cout << "Pokoj [" << i+1 << "] | cena: " << lista_pokojow[i].cena << "PLN | maksymalna ilosc osob w pokoju: " << lista_pokojow[i].max_ilosc_osob << endl;
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

	void usun_rezerwacje(){
		if (dokonano_rezerwacji != false) {
			
			for (int i = 0; i < zarezerwowany_pokoj.lista_dostepnosci.poczatek.size(); i++) {
				
				if (data_poczatku.dzien == zarezerwowany_pokoj.lista_dostepnosci.poczatek[i].dzien && data_poczatku.miesiac == zarezerwowany_pokoj.lista_dostepnosci.poczatek[i].miesiac && data_poczatku.rok == zarezerwowany_pokoj.lista_dostepnosci.poczatek[i].rok) {
					
					zarezerwowany_pokoj.lista_dostepnosci.poczatek.erase(zarezerwowany_pokoj.lista_dostepnosci.poczatek.begin() + i);
					zarezerwowany_pokoj.lista_dostepnosci.poczatek.erase(zarezerwowany_pokoj.lista_dostepnosci.koniec.begin() + i);
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
			zarezerwowany_pokoj=lista_pokojow[nr-1];
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

	void potwierdz_zamowienie(vector <Zamowienie> lista_zamowien, Zamowienie& zamowienie, obecny_pobyt_klienta &ob);  //metoda potweirdzenia zamowienia 
	void dodaj_do_koszyka(vector <Posilek>& koszyk, Posilek posilek);


};




class Kuchnia {
public:

	Posilek menu[5] = { {1, "Zupa pomidorowa", 10.0}, {2, "Nalesniki z serem", 15.0}, {3, "Salatka grecka", 17.0}, {4, "Ziemniaczki w mundurkach", 12.0}, {5, "Fasola po bretonsku", 20.0} };
	vector <Zamowienie> lista_zamowien;


	void wyswietl_menu();
	void zamow_jedzenie(Zamowienie z);
	void dodaj_do_listy(vector <Zamowienie> lista_zamowien, Zamowienie zamowienie);
	Posilek zwroc_info_o_posilku(int nr); //metoda zwracajaca informacje o posilku - nazwa, cena ?? NUMER

};


//funkcja dodajcac posilek do zamowienia 
void Zamowienie::dodaj_do_koszyka(vector <Posilek>& koszyk, Posilek posilek) {

	koszyk.push_back(posilek);

}

//funckja dodajaca zamowienie do listy 
void dodaj_do_listy(vector <Zamowienie> lista_zamowien, Zamowienie& zamowienie) {

	lista_zamowien.push_back(zamowienie);

}


//metoda klasy Posilek zwracajaca informacje o posilku - dodatkowo NUMER
Posilek Kuchnia::zwroc_info_o_posilku(int nr) {
	int i = 1;
	while (i <= 5) {
		if (nr == menu[i - 1].nr_posilku) {

			return menu[i - 1];
		}
		else i++;
	}

}
//metoda klasy Zamowienie generujaca numer zamowienia 
void Zamowienie::potwierdz_zamowienie(vector <Zamowienie> lista_zamowien, Zamowienie& zamowienie,obecny_pobyt_klienta& ob) {



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
	cout << "Saldo :" << ob.saldo << endl;
	cout << "[1] Potwierdz zamowienie" << endl << "[2] Anuluj zamowienie (wszystkie wybrane posilki zostana bezpowrotnie usuniete z listy)" << endl;
	cout << "Wybor: ";
	cin >> wybor;

	if (wybor == 1) {

		dodaj_do_listy(lista_zamowien, zamowienie);
		cout << "Zamowienie potwierdzone!" << endl;

	}
	else if (wybor == 2) {
		cout << "Zamowienie anulowane" << endl;
		koszyk.clear();
	}


}


//wyswietlanie tablicy posilkow
void Kuchnia::wyswietl_menu() {


	cout << "	MENU" << endl;
	int i;
	for (i = 0; i < 5; i++) {
		cout << menu[i].nr_posilku << ". " << menu[i].nazwa_posilku << " - " << menu[i].cena << " zl. " << endl;

	}

}

//metoda dla klienta
void Kuchnia::zamow_jedzenie(Zamowienie z1) {
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
			z1.potwierdz_zamowienie(lista_zamowien, z1);
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


class obecny_pobyt_klienta {

public:
	float saldo = 0;

	void rozpocznij_pobyt(Rezerwacja_pokoju& rezerwacja) {


		saldo = saldo + 25 * (rezerwacja.data_konca.dzien - rezerwacja.data_poczatku.dzien);

	};

	bool sprawdz_czy_przekroczono_termin(Rezerwacja_pokoju& rezerwacja, Data& data) {


		cout << "Wpisz date." << endl;
		cout << "Godzina (bez minut):";
		cin >> data.godzina;
		cout << "Minuty: ";
		cin >> data.minuta;
		cout << "Dzien: ";
		cin >> data.dzien;
		cout << "Miesiac: ";
		cin >> data.miesiac;
		cout << "Rok";
		cin >> data.rok;

		if (cmp_date(rezerwacja.data_konca, data) == 1) {
			return true;
		}
		else return false;


	};

	void nalicz_kare(Rezerwacja_pokoju& rezerwacja, Data& data) {

		cout << "Przekroczono date pobytu, do rachunku zostanie naliczona kara.";
		cout << "Saldo rezerwacji przed naliczeniem kary: " << saldo << endl;

		int kara = 25;
		saldo += (data.dzien - rezerwacja.data_konca.dzien) * kara;

		cout << "Saldo rachunku po naliczeniu kary (koncowa kwota do zaplaty): " << saldo << endl;


	};

	float sprawdz_stan_rachunku() {

		cout << "Saldo rachunku wynosi: " << saldo<<endl;

		return saldo;
	};

	void oplac_naleznosc();
};
>>>>>>> Stashed changes
