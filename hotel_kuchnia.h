#pragma once
#include <iostream>
#include <string>
using namespace std;


class Posilek {
private:
	int nr_posilku;
	string nazwa_posilku;
	float cena;
public:
	
	Posilek zwroc_info_o_posilku(int nr, Posilek menu[10]); //metoda zwracajaca informacje o posilku - nazwa, cena ?? NUMER

};



//lista z posilkami do koszyka 
struct Koszyk {

	Koszyk* next;
	Posilek posilek;
};



class Zamowienie:public Koszyk {
private:
	int n;
	string status;
	int nr_pokoju;
	int nr_zamowienia;
public:

	void potwierdz_zamowienie();  //metoda potweirdzenia zamowienia ??generuje numer zamowienia??

	void dodaj_do_koszyka(Koszyk*& head, Posilek posilek);

	
};


//lista zamowien

struct ListaZam {
	ListaZam* next;
	Zamowienie zamowienie;

};

void dodaj_do_listy(ListaZam& head, Zamowienie zamowienie);



class Kuchnia: public ListaZam {
private:
	int k;
	Posilek menu[10]; 
	ListaZam lista_zamowien;

public:
	void wyswietl_menu();
	void zamow_jedzenie();
	friend void dodaj_do_listy(ListaZam& head, Zamowienie zamowienie);

	
};
