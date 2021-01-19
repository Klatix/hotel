//#include <iostream>
#include "hotel_klasy.cpp"
int main() {
	Rezerwacja_pokoju rez1;
	Data dp1(1, 2, 2021);
	Data dk1(7, 2, 2021);
	Data dp2(19, 2, 2021);
	Data dk2(23, 2, 2021);
	Data dp3(27, 2, 2021);
	Data dk3(28, 2, 2021);
	Dostepnosc_pokoju dostepnosc;
	dostepnosc.poczatek.push_back(dp1);
	dostepnosc.koniec.push_back(dk1);
	dostepnosc.poczatek.push_back(dp3);
	dostepnosc.koniec.push_back(dk3);

	vector<Pokoj> lista_pokojow;
	Pokoj pokoj1(1, 450, 3, dostepnosc);
	lista_pokojow.push_back(pokoj1);

	//EXPECT_EQ(rez1.rezerwacja_pokoju(1, dp2, dk2, lista_pokojow), true);
	//EXPECT_EQ(rez1.get_dokonano_rezerwacji(), true);
	rez1.rezerwacja_pokoju(1, dp2, dk2, lista_pokojow);
	rez1.usun_rezerwacje();
	//EXPECT_EQ(rez1.get_dokonano_rezerwacji(), false);


	////////////////////
	//DATA BANK
	//zawiera informacje o pokojach
	////////////////////
/*
	Data dp1(1, 2, 2021);
	Data dk1(7, 2, 2021);
//	Data dp2(19, 2, 2021);
//	Data dk2(23, 2, 2021);
	Dostepnosc_pokoju dostepnosc;
	dostepnosc.poczatek.push_back(dp1);
	dostepnosc.koniec.push_back(dk1);
	//dostepnosc.poczatek.push_back(dp2);
	//dostepnosc.koniec.push_back(dp2);
	vector<Pokoj> lista_pokojow;
	Pokoj pokoj1(1, 450, 3, dostepnosc);
	Pokoj pokoj2(2, 540, 4, dostepnosc);
	Pokoj pokoj3(3, 300, 2, dostepnosc);
	Pokoj pokoj4(4, 249, 1, dostepnosc);
	lista_pokojow.push_back(pokoj1);
	lista_pokojow.push_back(pokoj2);
	lista_pokojow.push_back(pokoj3);
	lista_pokojow.push_back(pokoj4);
	*/

	//cout << rez1.nr_rezerwacji;
	///////////////////////////

	/*
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
	*/
}
