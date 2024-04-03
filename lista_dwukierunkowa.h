#pragma once
#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>


using namespace std;

class Wezel
{

    Wezel(int w);
    Wezel* nastepny;
    Wezel* poprzedni;
    int wartosc;

    friend class ListaDK;
};


class ListaDK
{
    Wezel* poczatek;
    Wezel* koniec;
    int rozmiar;

public:
    ListaDK();
    ~ListaDK();

    void dodawanie_poczatek(int wart);
    void odejmowanie_poczatek();

    void dodawanie_koniec(int wart);
    void odejmowanie_koniec();

    void dodawanie_dowolne(int wart, int index);
    void odejmowanie_dowolne(int index);

    int wyszukaj() const;

    void obecny_rozmiar() const;
    void wyswietl() const;

    void wyczysc_liste();


};

