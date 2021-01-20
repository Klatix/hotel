//#include <iostream>
#include "hotel_klasy.cpp"
#include <windows.h>

int main() {

////////////////////
//DATA BANK
//zawiera informacje o wszelkich obiektach wykorzystywanych w trakcie dzialania programu
////////////////////
	Rezerwacja_pokoju rez1;
	Kuchnia k1;
	Klient klient1;
	Kierownik kierownik1;
	vector<Klient> lista_klientow;
	
	Spa infinitySpa;
	Obecny_pobyt_klienta ob1;
	Posilek p1;
	Zamowienie z1;

	Data d1;
	Rezerwacja_pokoju r1;
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
	Pokoj pokoj1(1, 330, 3, dostepnosc);
	Pokoj pokoj2(2, 490, 4, dostepnosc);
	Pokoj pokoj3(3, 300, 2, dostepnosc);
	Pokoj pokoj4(4, 249, 1, dostepnosc);
	lista_pokojow.push_back(pokoj1);
	lista_pokojow.push_back(pokoj2);
	lista_pokojow.push_back(pokoj3);
	lista_pokojow.push_back(pokoj4);

	vector<Spa> lista_rezerwacji_basen;
	vector<Spa> lista_rezerwacji_sauna;

	///////////////////////////
	for (;;) {
		system("cls");
		srand(time(NULL));
		cout << "Jestem:\nRecepcjonista\t[1]\nKlientem\t[2]\nKelnerem\t[3]\nWybor: ";
		int wybor;
		int id;
		cin >> wybor;
		cout << endl;
		system("cls");
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
				Sleep(500);
				system("cls");
				while (wybor != 3)
				{
					cout << "Wybierz opcje:\nZarzadzanie zakwaterowaiem\t[1]\nZarzadzanie wykwaterowaiem\t[2]\nWyjscie\t\t\t\t[3]\nWybor:";
					cin >> wybor;
					if (wybor == 1) {
						if (klient1.rezerwacja.get_dokonano_rezerwacji() == true) {
							cout << "Wprowadz ID klienta: ";
							cin >> id;
							kierownik1.potwierdz_zakwaterowanie(id, lista_klientow);
							cout << "Pomyslnie zakwaterowano klienta " << klient1.zwroc_dane();
							Sleep(3000);
							system("cls");
						}
						else {
							cout << "Brak rezerwacji" << endl;
							Sleep(3000);
							system("cls");
						}
					}
					else if (wybor == 2) {
						if (klient1.rezerwacja.get_dokonano_rezerwacji() == true) {
							cout << "Wprowadz ID klienta: ";
							cin >> id;
							kierownik1.potwierdz_wykwaterowanie(id, lista_klientow);
							cout << "Pomyslnie wykwaterowano klienta " << klient1.zwroc_dane();
							klient1.rezerwacja.dokonano_rezerwacji = false;
							Sleep(3000);
							system("cls");
						}
						else {
							cout << "Brak rezerwacji" << endl;
							Sleep(3000);
							system("cls");
						}
					}
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

			r1.data_konca.dzien = 7;

			while (wybor != 5)
			{
				cout << "Wybierz opcje:\nRezerwacja pokoju\t[1]\nModyfikacja rezerwacji\t[2]\nZamawianie jedzenia\t[3]\nSpa\t\t\t[4]\nWyjscie\t\t\t[5]\nWybor: ";
				cin >> wybor;
				cout << endl;
				system("cls");
				switch (wybor)
				{
				case 1:
					if (klient1.rezerwacja.get_dokonano_rezerwacji() == false) {
						klient1.wprowadz_dane();
						cout << "Twoj nr ID to " << klient1.zwroc_ID() << endl;
						system("pause");
						klient1.rezerwacja.wybierz_pokoj(lista_pokojow);
						lista_klientow.push_back(klient1);
					}
					else {
						cout << "Dokonano juz rezerwacji" << endl;
					}
					break;
				case 2:
					if (klient1.rezerwacja.get_dokonano_rezerwacji() == true) {
						klient1.rezerwacja.modyfikuj_rezerwacje();
					}
					else {
						cout << "Brak rezerwacji" << endl;
						Sleep(3000);
					}
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
					system("cls");
					switch (wybor_spa)
					{
					case 1:
						cout << "\nWyswietl aktualne rezerwacje\t[1]\nDodaj rezerwacje\t\t[2]\nWybor: ";
						cin >> wybor_spa;
						cout << endl;
						system("cls");
						if (wybor_spa == 1)
						{
							infinitySpa.wyswietl_rezerwacje(lista_rezerwacji_basen);

						}
						else if (wybor_spa == 2)
						{
							infinitySpa.dodaj_rezerwacje(klient1.zwroc_ID(), "BASEN", ob1);
							lista_rezerwacji_basen.push_back(infinitySpa);
							Sleep(1000);
							system("cls");
						}
						cout << endl;
						break;
					case 2:
						cout << "\nWyswietl aktualne rezerwacje\t[1]\nDodaj rezerwacje\t\t[2]\nWybor: ";
						cin >> wybor_spa;
						cout << endl;
						system("cls");
						if (wybor_spa == 1)
						{
							infinitySpa.wyswietl_rezerwacje(lista_rezerwacji_sauna);
						}
						else if (wybor_spa == 2)
						{
							infinitySpa.dodaj_rezerwacje(klient1.zwroc_ID(), "SAUNA", ob1);
							lista_rezerwacji_sauna.push_back(infinitySpa);
							Sleep(1000);
							system("cls");
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
			}
		}
		else if (wybor == 3)
		{
			Kelner kelner1("Jan", "Kowalski");
			int a = 0;
			int nr_zam;
			float cena = 0;
			string nowy_st;
			while (a != 2) {
				system("cls");
				cout << "Wybierz opcje:\nZarzadzaj zamowieniami\t\t[1]\nWyjscie\t\t\t\t[2]\nWybor: ";
				cin >> a;
				switch (a)
				{
				case 1:
					system("cls");

					cout << "Lista zamowien:" << endl;
					for (int i = 0; i < k1.lista_zamowien.size(); i++) {
						cout << "Zamowienie " << k1.lista_zamowien[i].nr_zamowienia << ":" << endl;
						for (int k = 0; k < k1.lista_zamowien[i].koszyk.size(); k++) {
							cout << k1.lista_zamowien[i].koszyk[k].nazwa_posilku << ", ";
							cena += k1.lista_zamowien[i].koszyk[k].cena;
						}
						cout << endl << "Koszt calkowity " << cena << "zl" << endl << endl;
					}
					if (k1.lista_zamowien.size() == 0) {
						cout << "Brak zamowien" << endl;
						Sleep(2000);
						break;
					}
					cout << "Ktore zamowienie chcesz zaktualizowac? :" << endl;

					cin >> nr_zam;
					cout << "Wprowadz nowy status :" << endl;
					cin >> nowy_st;
					kelner1.zmiana_statusu_zamowienia(nr_zam, nowy_st, k1.lista_zamowien);
					cout << "Pomyslnie zmieniono status zamowienia " << nr_zam << " na " << nowy_st << endl;
					Sleep(3000);
					break;

				case 2:
					break;
				default:
					cout << "Wprowadzono zle dane" << endl;
					Sleep(3000);
					break;
				}
			}
		}
		else
		{
			cout << "BLAD!" << endl;
			Sleep(3000);
		}

	}
}