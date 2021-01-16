#include "hotel_kuchnia.h"
#include <iostream>
#include <string>
#include <time.h>

//funkcja dodajcac posilek do zamowienia 
void Zamowienie::dodaj_do_koszyka(Koszyk*& head, Posilek posilek) {

	Koszyk* pom = new Koszyk;
	pom = head;
	Koszyk* dodawany = new Koszyk;
	dodawany->posilek = posilek;
	if (head == NULL) {
		head = dodawany;
	}
	else
	{
		while (pom->next != NULL) {
			pom = pom->next;
		}

	}
	dodawany->next = pom->next;
	pom->next = dodawany;

}

//funckja dodajaca zamowienie do listy 
void dodaj_do_listy(ListaZam*& head, Zamowienie zamowienie) {

	ListaZam* pom = new ListaZam;
	pom = head;
	ListaZam* zam = new ListaZam;
	zam->zamowienie = zamowienie;

	if (head == NULL) {
		head = zam;
	
	}

	while (pom->next != NULL) {
		pom = pom->next;
	}
	zam->next = pom->next;
	pom->next = zam;
}


//metoda klasy Posilek zwracajaca informacje o posilku - dodatkowo NUMER
Posilek Posilek::zwroc_info_o_posilku(int nr, Posilek menu[]) {
	int i = 1;
	while (i <11){
		if (nr == menu[i-1].nr_posilku) {

			return menu[i];
		}
		else i++;
}

}
//metoda klasy Zamowienie generujaca numer zamowienia 
void Zamowienie::potwierdz_zamowienie() {}


//wyswietlanie tablicy posilkow
void Kuchnia::wyswietl_menu() {

}

//metoda dla klienta
void Kuchnia::zamow_jedzenie() {}