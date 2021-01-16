#include <iostream>
#include "hotel_klasy.cpp"
int main() {
	Rezerwacja_spa* head = new Rezerwacja_spa;
	head->next = NULL;
	srand(time(NULL));

	cout << "Jestem:\nPracownikiem\t[1]\nKlientem\t[2]\nWybor: ";
	int wybor;
	cin >> wybor;
	cout << endl;
	if (wybor == 1)
	{
		string haslo;
		cout << "Podaj haslo: ";
		cin >> haslo;
		cout << endl;
		if (haslo == "admin")
		{
			cout << "Podales poprawne haslo!" << endl;
			//wybor co chce robic
		}
		else
		{
			cout << "Podales bledne haslo!" << endl;
		}
	}
	else if (wybor == 2)
	{
		Klient klient1;
		klient1.wprowadz_dane();
		//klient1.wypisz_uzytkownika();


		Spa s1;
		s1.potwiedz_rezerwacje(klient1.zwroc_ID(), 18, 30, 12, 11, 2021, 45, head);
	}
	else
	{
		cout << "BLAD!" << endl;
	}
}
