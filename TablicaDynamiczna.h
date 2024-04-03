#pragma once
#include <iostream>


class TablicaDynamiczna 
{
private:
    int* tablica;
    int pojemnosc;
    int rozmiar;

public:
    TablicaDynamiczna();
    ~TablicaDynamiczna();

    void dodawanie_poczatek(int wart);
    void odejmowanie_poczatek();

    void dodawanie_koniec(int wart);
    void odejmowanie_koniec();

    void dodawanie_dowolne(int wart, int index);
    void odejmowanie_dowolne(int index);

    int wyszukaj_losowo() const;

    void obecny_rozmiar() const;
    void wyswietl() const;

    void wyczysc_liste();

private:
    void powiekszTablice();
};
