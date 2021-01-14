#include "pch.h"
#include "../hotel_klasy/hotel_klasy.cpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(USER_TEST, TEST_KONSTRUKTOROW_KLIENT) {
	Klient klient1;
	EXPECT_EQ(klient1.zwroc_dane(), "Niezidentyfikowany Klient");
	Klient klient2("Adam", "Malysz", "skoki@fake.com");
	EXPECT_EQ(klient2.zwroc_dane(), "Adam Malysz");
}

TEST(USER_TEST, TEST_KONSTRUKTOROW_KIEROWNIK) {
	Kierownik k1;
	EXPECT_EQ(k1.zwroc_dane(), "(Kierownik) Daniel Klata");
	Kierownik k2("Adam", "Malysz");
	EXPECT_EQ(k2.zwroc_dane(), "(Kierownik) Adam Malysz");
}

TEST(USER_TEST, TEST_KONSTRUKTOROW_KELNER) {
	Kelner k1;
	EXPECT_EQ(k1.zwroc_dane(), "(Kelner) Niezidentyfikowany Pracownik");
	Kelner k2("Adam", "Malysz");
	EXPECT_EQ(k2.zwroc_dane(), "(Kelner) Adam Malysz");
}