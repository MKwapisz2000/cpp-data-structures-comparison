#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "TablicaDynamiczna.h"

using namespace std;

// Konstruktor klasy TablicaDynamiczna
TablicaDynamiczna::TablicaDynamiczna()
{
    tablica = nullptr;  // Inicjowanie wskaŸnika na nullptr
    pojemnosc = 0;      // Inicjowanie pojemnoœci tablicy na 0
    rozmiar = 0;        // Inicjowanie rozmiaru tablicy na 0
}

// Destruktor klasy TablicaDynamiczna
TablicaDynamiczna::~TablicaDynamiczna()
{
    delete[] tablica;   // Zwolnienie pamiêci zaalokowanej dla tablicy
}

// Dodawanie elementu na pocz¹tek tablicy
void TablicaDynamiczna::dodawanie_poczatek(int wart)
{
    dodawanie_dowolne(wart, 0);    // Wywo³anie metody dodawania_dowolne z indeksem 0
    if (rozmiar >= pojemnosc)      // Sprawdzenie, czy tablica nie wymaga powiêkszenia
    {
        powiekszTablice();         // Jeœli tak, to powiêkszenie tablicy
    }

    // Przesuniêcie wszystkich elementów o jedn¹ pozycjê w prawo
    for (int i = rozmiar; i > 0; --i)
    {
        tablica[i] = tablica[i - 1];
    }
    tablica[0] = wart;              // Wstawienie nowego elementu na pocz¹tek
    rozmiar++;                      // Zwiêkszenie rozmiaru tablicy
}

// Usuwanie elementu z pocz¹tku tablicy
void TablicaDynamiczna::odejmowanie_poczatek()
{
    if (rozmiar >= 0) {             // Sprawdzenie, czy tablica nie jest pusta
        // Przesuniêcie wszystkich elementów o jedn¹ pozycjê w lewo
        for (int i = 0; i < rozmiar - 1; ++i) {
            tablica[i] = tablica[i + 1];
        }
        rozmiar--;                  // Zmniejszenie rozmiaru tablicy
    }
    else {
        cout << "Nie mo¿na usun¹æ elementu, tablica jest pusta." << endl;  // Komunikat o b³êdzie
    }
}

// Dodawanie elementu na koniec tablicy
void TablicaDynamiczna::dodawanie_koniec(int wart)
{
    if (rozmiar >= pojemnosc)      // Sprawdzenie, czy tablica nie wymaga powiêkszenia
    {
        powiekszTablice();         // Jeœli tak, to powiêkszenie tablicy
    }
    tablica[rozmiar++] = wart;     // Dodanie nowego elementu na koniec i zwiêkszenie rozmiaru
}

// Usuwanie elementu z koñca tablicy
void TablicaDynamiczna::odejmowanie_koniec()
{
    if (rozmiar >= 0)
    {
        rozmiar--;                  // Zmniejszenie rozmiaru tablicy
    }
    else
    {
        cout << "Nie mo¿na usun¹æ elementu, tablica jest pusta." << endl;  // Komunikat o b³êdzie
    }
}

// Dodawanie elementu w dowolne miejsce tablicy
void TablicaDynamiczna::dodawanie_dowolne(int wart, int index)
{
    if (index < 0 || index > rozmiar)
    {
        cout << "Niepoprawny indeks." << endl;  // Komunikat o b³êdzie
        return;
    }

    if (rozmiar >= pojemnosc)
    {
        powiekszTablice();         // Jeœli tablica nie ma wystarczaj¹cej pojemnoœci, to j¹ powiêksz
    }

    // Przesuniêcie wszystkich elementów o jedn¹ pozycjê w prawo
    for (int i = rozmiar; i > index; --i)
    {
        tablica[i] = tablica[i - 1];
    }
    tablica[index] = wart;          // Wstawienie nowego elementu na odpowiednie miejsce
    rozmiar++;                      // Zwiêkszenie rozmiaru tablicy
}

// Usuwanie elementu z dowolnego miejsca tablicy
void TablicaDynamiczna::odejmowanie_dowolne(int index)
{
    if (index < 0 || index >= rozmiar)
    {
        cout << "Niepoprawny indeks." << endl;  // Komunikat o b³êdzie
        return;
    }

    // Przesuniêcie wszystkich elementów o jedn¹ pozycjê w lewo
    for (int i = index; i < rozmiar - 1; ++i)
    {
        tablica[i] = tablica[i + 1];
    }
    rozmiar--;                      // Zmniejszenie rozmiaru tablicy
}

// Wyszukiwanie losowego elementu w tablicy
int TablicaDynamiczna::wyszukaj_losowo() const
{
    if (rozmiar == 0)               // Sprawdzenie, czy tablica nie jest pusta
    {
        return -1;                  // Jeœli tak, to zwrócenie wartoœci -1
    }

    srand(time(nullptr));           // Inicjowanie generatora liczb pseudolosowych
    int losowyIndex = (rand() % rozmiar);    // Losowanie indeksu
    return tablica[losowyIndex];    // Zwracanie wartoœci losowego elementu
}

// Usuwanie wszystkich elementów z tablicy
void TablicaDynamiczna::wyczysc_liste()
{
    delete[] tablica;               // Zwolnienie pamiêci zaalokowanej dla tablicy
    tablica = nullptr;              // Ustawienie wskaŸnika na nullptr
    pojemnosc = 0;                  // Resetowanie pojemnoœci tablicy
    rozmiar = 0;                    // Resetowanie rozmiaru tablicy
}

// Zwraca obecny rozmiar tablicy
void TablicaDynamiczna::obecny_rozmiar() const
{
    cout << "Obecny rozmiar listy: " << rozmiar << endl;  // Zwracanie wartoœci rozmiaru tablicy
}
                  


// Wyœwietla zawartoœæ tablicy
void TablicaDynamiczna::wyswietl() const
{
    if (rozmiar == 0)               // Sprawdzenie, czy tablica jest pusta
    {
        cout << "Tablica jest pusta." << endl;    // Komunikat o pustej tablicy
        return;
    }

    cout << "POCZATEK" << endl;     // Wyœwietlenie informacji o pocz¹tku tablicy
    for (int i = 0; i < rozmiar; ++i)   // Przejœcie przez wszystkie elementy tablicy
    {
        cout << i+1<<".) "<<tablica[i] << endl;    // Wyœwietlenie wartoœci elementu
    }
    cout << "KONIEC" << endl;       // Wyœwietlenie informacji o koñcu tablicy
}

// Powiêksza tablicê dwukrotnie
void TablicaDynamiczna::powiekszTablice()
{
    int nowaPojemnosc;              // Zmienna przechowuj¹ca now¹ pojemnoœæ tablicy
    if (pojemnosc == 0)             // Sprawdzenie, czy tablica jest pusta
    {
        nowaPojemnosc = 1;          // Jeœli tak, to nowa pojemnoœæ wynosi 1
    }
    else
    {
        nowaPojemnosc = 2 * pojemnosc; // Jeœli nie, to nowa pojemnoœæ wynosi dwukrotnoœæ obecnej pojemnoœci
    }

    // Utworzenie nowej tablicy o wiêkszej pojemnoœci
    int* nowaTablica = new int[nowaPojemnosc];

    // Skopiowanie zawartoœci starej tablicy do nowej
    for (int i = 0; i < rozmiar; ++i)
    {
        nowaTablica[i] = tablica[i];
    }

    delete[] tablica;               // Zwolnienie pamiêci zaalokowanej dla starej tablicy
    tablica = nowaTablica;          // Ustawienie wskaŸnika na now¹ tablicê
    pojemnosc = nowaPojemnosc;      // Zaktualizowanie pojemnoœci tablicy
}
