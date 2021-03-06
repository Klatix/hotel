#include "pch.h"
#include "../hotel_klasy/hotel_klasy.cpp"

TEST(METHOD_TEST, TEST_KONSTRUKTOROW_KLIENT) {
	Klient klient1;
	EXPECT_EQ(klient1.zwroc_dane(), "Niezidentyfikowany Klient");
	Klient klient2("Adam", "Malysz", "skoki@fake.com");
	EXPECT_EQ(klient2.zwroc_dane(), "Adam Malysz");
}

TEST(METHOD_TEST, TEST_KONSTRUKTOROW_KIEROWNIK) {
	Kierownik k1;
	EXPECT_EQ(k1.zwroc_dane(), "(Kierownik) Daniel Klata");
	Kierownik k2("Adam", "Malysz");
	EXPECT_EQ(k2.zwroc_dane(), "(Kierownik) Adam Malysz");
}

TEST(METHOD_TEST, TEST_KONSTRUKTOROW_KELNER) {
	Kelner k1;
	EXPECT_EQ(k1.zwroc_dane(), "(Kelner) Niezidentyfikowany Pracownik");
	Kelner k2("Adam", "Malysz");
	EXPECT_EQ(k2.zwroc_dane(), "(Kelner) Adam Malysz");
}
TEST(FUNCTION_TEST, TEST_CMP_DATA) {
	Data d1(1, 2, 2021);
	Data d2(7, 2, 2021);
	Data d3(1, 2, 2021);
	EXPECT_EQ(cmp_date(d1, d2), 2);
	EXPECT_EQ(cmp_date(d2, d1), 1);
	EXPECT_EQ(cmp_date(d1, d3), 0);
}
TEST(FUNCTION_TEST, TEST_REMOVE_VECTOR_CELL) {
	Dostepnosc_pokoju dostepnosc;
	Data dp1(1, 2, 2021);
	Data dp2(19, 2, 2021);
	dostepnosc.poczatek.push_back(dp1);
	dostepnosc.poczatek.push_back(dp2);

	int size1 = dostepnosc.poczatek.size();
	remove(dostepnosc.poczatek, 0);
	EXPECT_EQ(dostepnosc.poczatek[0].dzien, 19);
	int size2 = dostepnosc.poczatek.size();
	EXPECT_LT(size2, size1);
}
TEST(FUNCTION_TEST, TEST_ILOSC_DNI) {
	Data dp1(1, 2, 2021);
	Data dp2(19, 2, 2021);
	int val1 = ilosc_dni(dp1.rok, dp1.miesiac, dp1.dzien);
	int val2 = ilosc_dni(dp2.rok, dp2.miesiac, dp2.dzien);
	EXPECT_EQ(val2 - val1, 18);
	EXPECT_LT(val1, val2);
}
TEST(METHOD_TEST, TEST_SPRAWDZ_DOSTEPNOSC_POKOJU) {

	Data dp1(19, 2, 2021);
	Data dk1(23, 2, 2021); // rezerwacja 1
	Data dp7(19, 3, 2021);
	Data dk7(23, 3, 2021); // rezerwacja 2

	Data dp2(14, 2, 2021); //poprawny przypadek
	Data dk2(17, 2, 2021); //

	Data dp3(17, 2, 2021); //zly przypadek nr1
	Data dk3(24, 2, 2021); //

	Data dp4(20, 2, 2021); //zly przypadek nr2
	Data dk4(21, 2, 2021); //

	Data dp5(20, 2, 2021); //zly przypadek nr3
	Data dk5(25, 2, 2021); //

	Data dp6(17, 2, 2021); //zly przypadek nr4
	Data dk6(25, 2, 2021); //

	Data dp8(20, 3, 2021); //zly przypadek nr5 (do innej daty)
	Data dk8(25, 3, 2021); //
	Dostepnosc_pokoju dostepnosc;
	dostepnosc.poczatek.push_back(dp1);
	dostepnosc.koniec.push_back(dk1);
	dostepnosc.poczatek.push_back(dp7);
	dostepnosc.koniec.push_back(dk7);
	Pokoj pokoj1(1, 450, 3, dostepnosc);
	EXPECT_EQ(pokoj1.sprawdz_dostepnosc(dp2, dk2), true);
	EXPECT_EQ(pokoj1.sprawdz_dostepnosc(dp3, dk3), false);
	EXPECT_EQ(pokoj1.sprawdz_dostepnosc(dp4, dk4), false);
	EXPECT_EQ(pokoj1.sprawdz_dostepnosc(dp5, dk5), false);
	EXPECT_EQ(pokoj1.sprawdz_dostepnosc(dp6, dk6), false);
	EXPECT_EQ(pokoj1.sprawdz_dostepnosc(dp8, dk8), false);

}
/*
TEST(METHOD_TEST, TEST_USUN_REZERWACJE) {
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

	EXPECT_EQ(rez1.rezerwacja_pokoju(1, dp2, dk2, lista_pokojow), true);
	EXPECT_EQ(rez1.get_dokonano_rezerwacji(), true);

	rez1.usun_rezerwacje();
	EXPECT_EQ(rez1.get_dokonano_rezerwacji(), false);


}
*/
TEST(METHOD_TEST, TEST_MODYFIKACJA_REZERWACJI) {
	Rezerwacja_pokoju rez1;

	Data dp2(19, 2, 2021);
	Data dk2(23, 2, 2021);

	//rez1.usun_rezerwacje();
	bool result1 = rez1.get_dokonano_rezerwacji();
	rez1.potwierdz_modyfikacje(dp2, dk2);
	bool result2 = rez1.get_dokonano_rezerwacji();
	EXPECT_EQ(result1, false);
	rez1.usun_rezerwacje();
	EXPECT_EQ(result2, true);
}

TEST(METHOD_TEST, TEST_KONSTRUKTOR_SPA) {
	Spa s_test("BASEN", 1111, 18, 30, 14, 10, 2021, 45);

	EXPECT_EQ("BASEN 1111 18:30 14.10.2021 na: 45 minut", s_test.zwroc_dane_spa());
}


TEST(METHOD_TEST, TEST_DODAJ_DO_KOSZYKA) {
	Zamowienie z_test;
	Posilek p1;
	z_test.dodaj_do_koszyka(z_test.koszyk, p1);
	EXPECT_EQ(z_test.koszyk.size(), 1);

}

TEST(METHOD_TEST, TEST_DODAJ_DO_LISTY) {
	Zamowienie z1;
	Kuchnia k1;

	dodaj_do_listy(k1.lista_zamowien, z1);
	EXPECT_EQ(k1.lista_zamowien.size(), 1);

}


TEST(METHOD_TEST, TEST_NALICZ_KARE) {
	Obecny_pobyt_klienta ob1;

	Data dp(14, 2, 2021);
	Data dk(17, 2, 2021);
	Rezerwacja_pokoju r1 = { dp, dk, Pokoj(3, 50, 5), false };

	//Data d1;
	Data d1(20, 2, 2021);

	ob1.nalicz_kare(r1, d1);

	EXPECT_EQ(ob1.saldo, 75);

}

TEST(METHOD_TEST, TEST_SPRAWDZ_STAN_RACHUNKU) {
	Obecny_pobyt_klienta ob1;

	ob1.saldo = 50;

	EXPECT_EQ(ob1.sprawdz_stan_rachunku(), 50);

}


