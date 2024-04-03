#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "TablicaDynamiczna.h"

using namespace std;

// Konstruktor klasy TablicaDynamiczna
TablicaDynamiczna::TablicaDynamiczna()
{
    tablica = nullptr;  // Inicjowanie wska�nika na nullptr
    pojemnosc = 0;      // Inicjowanie pojemno�ci tablicy na 0
    rozmiar = 0;        // Inicjowanie rozmiaru tablicy na 0
}

// Destruktor klasy TablicaDynamiczna
TablicaDynamiczna::~TablicaDynamiczna()
{
    delete[] tablica;   // Zwolnienie pami�ci zaalokowanej dla tablicy
}

// Dodawanie elementu na pocz�tek tablicy
void TablicaDynamiczna::dodawanie_poczatek(int wart)
{
    dodawanie_dowolne(wart, 0);    // Wywo�anie metody dodawania_dowolne z indeksem 0
    if (rozmiar >= pojemnosc)      // Sprawdzenie, czy tablica nie wymaga powi�kszenia
    {
        powiekszTablice();         // Je�li tak, to powi�kszenie tablicy
    }

    // Przesuni�cie wszystkich element�w o jedn� pozycj� w prawo
    for (int i = rozmiar; i > 0; --i)
    {
        tablica[i] = tablica[i - 1];
    }
    tablica[0] = wart;              // Wstawienie nowego elementu na pocz�tek
    rozmiar++;                      // Zwi�kszenie rozmiaru tablicy
}

// Usuwanie elementu z pocz�tku tablicy
void TablicaDynamiczna::odejmowanie_poczatek()
{
    if (rozmiar >= 0) {             // Sprawdzenie, czy tablica nie jest pusta
        // Przesuni�cie wszystkich element�w o jedn� pozycj� w lewo
        for (int i = 0; i < rozmiar - 1; ++i) {
            tablica[i] = tablica[i + 1];
        }
        rozmiar--;                  // Zmniejszenie rozmiaru tablicy
    }
    else {
        cout << "Nie mo�na usun�� elementu, tablica jest pusta." << endl;  // Komunikat o b��dzie
    }
}

// Dodawanie elementu na koniec tablicy
void TablicaDynamiczna::dodawanie_koniec(int wart)
{
    if (rozmiar >= pojemnosc)      // Sprawdzenie, czy tablica nie wymaga powi�kszenia
    {
        powiekszTablice();         // Je�li tak, to powi�kszenie tablicy
    }
    tablica[rozmiar++] = wart;     // Dodanie nowego elementu na koniec i zwi�kszenie rozmiaru
}

// Usuwanie elementu z ko�ca tablicy
void TablicaDynamiczna::odejmowanie_koniec()
{
    if (rozmiar >= 0)
    {
        rozmiar--;                  // Zmniejszenie rozmiaru tablicy
    }
    else
    {
        cout << "Nie mo�na usun�� elementu, tablica jest pusta." << endl;  // Komunikat o b��dzie
    }
}

// Dodawanie elementu w dowolne miejsce tablicy
void TablicaDynamiczna::dodawanie_dowolne(int wart, int index)
{
    if (index < 0 || index > rozmiar)
    {
        cout << "Niepoprawny indeks." << endl;  // Komunikat o b��dzie
        return;
    }

    if (rozmiar >= pojemnosc)
    {
        powiekszTablice();         // Je�li tablica nie ma wystarczaj�cej pojemno�ci, to j� powi�ksz
    }

    // Przesuni�cie wszystkich element�w o jedn� pozycj� w prawo
    for (int i = rozmiar; i > index; --i)
    {
        tablica[i] = tablica[i - 1];
    }
    tablica[index] = wart;          // Wstawienie nowego elementu na odpowiednie miejsce
    rozmiar++;                      // Zwi�kszenie rozmiaru tablicy
}

// Usuwanie elementu z dowolnego miejsca tablicy
void TablicaDynamiczna::odejmowanie_dowolne(int index)
{
    if (index < 0 || index >= rozmiar)
    {
        cout << "Niepoprawny indeks." << endl;  // Komunikat o b��dzie
        return;
    }

    // Przesuni�cie wszystkich element�w o jedn� pozycj� w lewo
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
        return -1;                  // Je�li tak, to zwr�cenie warto�ci -1
    }

    srand(time(nullptr));           // Inicjowanie generatora liczb pseudolosowych
    int losowyIndex = (rand() % rozmiar);    // Losowanie indeksu
    return tablica[losowyIndex];    // Zwracanie warto�ci losowego elementu
}

// Usuwanie wszystkich element�w z tablicy
void TablicaDynamiczna::wyczysc_liste()
{
    delete[] tablica;               // Zwolnienie pami�ci zaalokowanej dla tablicy
    tablica = nullptr;              // Ustawienie wska�nika na nullptr
    pojemnosc = 0;                  // Resetowanie pojemno�ci tablicy
    rozmiar = 0;                    // Resetowanie rozmiaru tablicy
}

// Zwraca obecny rozmiar tablicy
void TablicaDynamiczna::obecny_rozmiar() const
{
    cout << "Obecny rozmiar listy: " << rozmiar << endl;  // Zwracanie warto�ci rozmiaru tablicy
}
                  


// Wy�wietla zawarto�� tablicy
void TablicaDynamiczna::wyswietl() const
{
    if (rozmiar == 0)               // Sprawdzenie, czy tablica jest pusta
    {
        cout << "Tablica jest pusta." << endl;    // Komunikat o pustej tablicy
        return;
    }

    cout << "POCZATEK" << endl;     // Wy�wietlenie informacji o pocz�tku tablicy
    for (int i = 0; i < rozmiar; ++i)   // Przej�cie przez wszystkie elementy tablicy
    {
        cout << i+1<<".) "<<tablica[i] << endl;    // Wy�wietlenie warto�ci elementu
    }
    cout << "KONIEC" << endl;       // Wy�wietlenie informacji o ko�cu tablicy
}

// Powi�ksza tablic� dwukrotnie
void TablicaDynamiczna::powiekszTablice()
{
    int nowaPojemnosc;              // Zmienna przechowuj�ca now� pojemno�� tablicy
    if (pojemnosc == 0)             // Sprawdzenie, czy tablica jest pusta
    {
        nowaPojemnosc = 1;          // Je�li tak, to nowa pojemno�� wynosi 1
    }
    else
    {
        nowaPojemnosc = 2 * pojemnosc; // Je�li nie, to nowa pojemno�� wynosi dwukrotno�� obecnej pojemno�ci
    }

    // Utworzenie nowej tablicy o wi�kszej pojemno�ci
    int* nowaTablica = new int[nowaPojemnosc];

    // Skopiowanie zawarto�ci starej tablicy do nowej
    for (int i = 0; i < rozmiar; ++i)
    {
        nowaTablica[i] = tablica[i];
    }

    delete[] tablica;               // Zwolnienie pami�ci zaalokowanej dla starej tablicy
    tablica = nowaTablica;          // Ustawienie wska�nika na now� tablic�
    pojemnosc = nowaPojemnosc;      // Zaktualizowanie pojemno�ci tablicy
}
