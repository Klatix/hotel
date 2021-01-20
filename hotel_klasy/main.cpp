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


	vector<Spa> lista_rezerwacji_basen;
	vector<Spa> lista_rezerwacji_sauna;
	/*
	Spa b1("BASEN", klient1.zwroc_ID(), 10, 30, 11, 10, 2021, 45);
	Spa b2("BASEN", klient1.zwroc_ID(), 12, 30, 14, 10, 2021, 55);
	Spa b3("BASEN", klient1.zwroc_ID(), 13, 30, 18, 10, 2021, 25);
	Spa b4("BASEN", klient1.zwroc_ID(), 17, 00, 22, 10, 2021, 25);
	lista_rezerwacji_basen.push_back(b1);
	lista_rezerwacji_basen.push_back(b2);
	lista_rezerwacji_basen.push_back(b3);
	lista_rezerwacji_basen.push_back(b4);
	Spa s1("SAUNA", klient1.zwroc_ID(), 10, 30, 11, 12, 2021, 45);
	Spa s2("SAUNA", klient1.zwroc_ID(), 12, 30, 14, 12, 2021, 55);
	Spa s3("SAUNA", klient1.zwroc_ID(), 13, 30, 18, 12, 2021, 25);
	Spa s4("SAUNA", klient1.zwroc_ID(), 17, 00, 22, 12, 2021, 25);
	lista_rezerwacji_sauna.push_back(s1);
	lista_rezerwacji_sauna.push_back(s2);
	lista_rezerwacji_sauna.push_back(s3);
	lista_rezerwacji_sauna.push_back(s4);
	*/

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

	srand(time(NULL));
	cout << "Jestem:\nPracownikiem\t[1]\nKlientem\t[2]\nKelnerem\t[3]\nWybor: ";
	int wybor;
	cin >> wybor;
	cout << endl;
	if (wybor == 1)
	{
		int wybor = NULL;
		string haslo;
		
		cout << "Podaj haslo: ";
		cin >> haslo;
		cout << endl;
		if (haslo == "admin")
		{
			cout << "Podales poprawne haslo!" << endl;
			while (wybor != 3)
			{
				cout << "Wybierz opcje:\nZarzadzanie zakwaterowaiem\t[1]\nZarzadzanie wykwaterowaiem\t[2]\nWyjscie\t\t\t\t[3]\nWybor:";
				cin >> wybor;
				cout << endl;
			}
			
		}
		else
		{
			cout << "Podales bledne haslo!" << endl;
		}


	}
	else if (wybor == 2)
	{
		int wybor = NULL;
		int wybor_spa = NULL;
		Klient klient1;
		Spa infinitySpa;
		Obecny_pobyt_klienta ob1;
		Posilek p1;
		Zamowienie z1;
		Kuchnia k1;
		Data d1;
		Rezerwacja_pokoju r1;
		r1.data_konca.dzien = 7;

		while (wybor != 5)
		{
			cout << "Wybierz opcje:\nRezerwacja pokoju\t[1]\nModyfikacja rezerwacji\t[2]\nZamawianie jedzenia\t[3]\nSpa\t\t\t[4]\nWyjscie\t\t\t[5]\nWybor: ";
			cin >> wybor;
			cout << endl;
			switch (wybor)
			{
			case 1:
				break;
			case 2:

				break;
			case 3:

				system("cls");
				k1.zamow_jedzenie(z1, ob1);
				system("cls");

				break;
			case 4:
				wybor_spa = NULL;
				cout << "Chce zarezerwowac:\nBasen\t[1]\nSaune\t[2]\nWybor: ";
				cin >> wybor_spa;
				cout << endl;
				switch (wybor_spa)
				{
				case 1:
					cout << "\nWyswietl aktualne rezerwacje\t[1]\nDodaj rezerwacje\t\t[2]\nWybor: ";
					cin >> wybor_spa;
					cout << endl;
					if (wybor_spa == 1)
					{
						infinitySpa.wyswietl_rezerwacje(lista_rezerwacji_basen);

					}
					else if (wybor_spa == 2)
					{
						infinitySpa.dodaj_rezerwacje(klient1.zwroc_ID(), "BASEN", ob1);
						lista_rezerwacji_basen.push_back(infinitySpa);
					}
					cout << endl;
					break;
				case 2:
					cout << "\nWyswietl aktualne rezerwacje\t[1]\nDodaj rezerwacje\t\t[2]\nWybor: ";
					cin >> wybor_spa;
					cout << endl;
					if (wybor_spa == 1)
					{
						infinitySpa.wyswietl_rezerwacje(lista_rezerwacji_sauna);
					}
					else if (wybor_spa == 2)
					{
						infinitySpa.dodaj_rezerwacje(klient1.zwroc_ID(), "SAUNA", ob1);
						lista_rezerwacji_sauna.push_back(infinitySpa);
					}
					cout << endl;
					break;
				default:
					cout << "Bledna wartosc!" << endl;
					break;
				}
				break;
			case 5:
				wybor == 5;
				break;
			default:
				cout << "Blad! Wybierz ponownie!" << endl;
			}

			//klient1.wprowadz_dane();
			//klient1.wypisz_uzytkownika();



			//Spa s4("BASEN", klient1.zwroc_ID(), 11, 45, 14, 10, 2021, 25);

			//s4.dodaj_rezerwacje(&lista_rezerwacji_basen, "BASEN", klient1.zwroc_ID(), 11, 45, 14, 10, 2021, 25)

			//lista_rezerwacji_basen.push_back(s4);
			//s4.dodaj_rezerwacje(&lista_rezerwacji_basen, "BASEN", klient1.zwroc_ID(), 11, 45, 14, 10, 2021, 25)
			//infinitySpa.dodaj_rezerwacje(klient1.zwroc_ID());
			//lista_rezerwacji_basen.push_back(infinitySpa);



			//s1.wyswietl_rezerwacje(lista_rezerwacji_basen);
			//cout << s1.zwroc_dane_spa() << endl;
		}
	}
	else if (wybor == 3)
	{
		//tu kelner
	}
	else
	{
		cout << "BLAD!" << endl;
	}

}