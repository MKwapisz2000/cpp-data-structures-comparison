#pragma once
#pragma once
#include <iostream>


class ListaJK 
{
private:
    class Wezel
    {
    public:
        Wezel(int w);
        int wartosc;
        Wezel* nastepny;

      

    };
    Wezel* poczatek;
    int rozmiar;

public:
    ListaJK();
    ~ListaJK();

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
};