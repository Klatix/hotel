#include <iostream>
#include "hotel_klasy.cpp"
<<<<<<< Updated upstream
=======
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

	vector<Spa> lista_rezerwacji_basen;
	vector<Spa> lista_rezerwacji_sauna;

>>>>>>> Stashed changes

int main() {
<<<<<<< Updated upstream
	Rezerwacja_spa* head = new Rezerwacja_spa;
	head->next = NULL;
=======
	////////////////////
	//DATA BANK
	//zawiera informacje o pokojach
	////////////////////

	Data dp1(1, 6, 2021);
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

	vector<Spa> lista_rezerwacji_basen;
	vector<Spa> lista_rezerwacji_sauna;


	//cout << rez1.nr_rezerwacji;
	///////////////////////////
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======

	
>>>>>>> Stashed changes
	srand(time(NULL));
	//system("cls");
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
		//klient1.wprowadz_dane();
		//klient1.wypisz_uzytkownika();


		Spa s1("BASEN", klient1.zwroc_ID(), 18, 30, 14, 10, 2021, 45);
		Spa s2("BASEN", klient1.zwroc_ID(), 15, 30, 14, 10, 2021, 55);
		Spa s3("BASEN", klient1.zwroc_ID(), 13, 30, 14, 10, 2021, 25);
<<<<<<< Updated upstream
		Spa s4("BASEN", klient1.zwroc_ID(), 11, 45, 14, 10, 2021, 25);
=======
		//Spa s4("BASEN", klient1.zwroc_ID(), 11, 45, 14, 10, 2021, 25);
		Spa infinitySpa;
>>>>>>> Stashed changes

		lista_rezerwacji_basen.push_back(s1);
		lista_rezerwacji_basen.push_back(s2);
		lista_rezerwacji_basen.push_back(s3);
<<<<<<< Updated upstream
		lista_rezerwacji_basen.push_back(s4);
		//s4.dodaj_rezerwacje(&lista_rezerwacji_basen, "BASEN", klient1.zwroc_ID(), 11, 45, 14, 10, 2021, 25)
=======
		//lista_rezerwacji_basen.push_back(s4);
		//s4.dodaj_rezerwacje(&lista_rezerwacji_basen, "BASEN", klient1.zwroc_ID(), 11, 45, 14, 10, 2021, 25)
		infinitySpa.dodaj_rezerwacje(klient1.zwroc_ID());
		lista_rezerwacji_basen.push_back(infinitySpa);
>>>>>>> Stashed changes


		s1.wyswietl_rezerwacje(lista_rezerwacji_basen);

	}
	else
	{
		cout << "BLAD!" << endl;
	}
<<<<<<< Updated upstream
<<<<<<< Updated upstream
=======
	
>>>>>>> Stashed changes
=======
	
>>>>>>> Stashed changes
}
