#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "TablicaDynamiczna.h"

using namespace std;

// Konstruktor klasy TablicaDynamiczna
TablicaDynamiczna::TablicaDynamiczna()
{
    tablica = nullptr;  // Inicjowanie wskaźnika na nullptr
    pojemnosc = 0;      // Inicjowanie pojemności tablicy na 0
    rozmiar = 0;        // Inicjowanie rozmiaru tablicy na 0
}

// Destruktor klasy TablicaDynamiczna
TablicaDynamiczna::~TablicaDynamiczna()
{
    delete[] tablica;   // Zwolnienie pamięci zaalokowanej dla tablicy
}

// Dodawanie elementu na początek tablicy
void TablicaDynamiczna::dodawanie_poczatek(int wart)
{
    dodawanie_dowolne(wart, 0);    // Wywołanie metody dodawania_dowolne z indeksem 0
    if (rozmiar >= pojemnosc)      // Sprawdzenie, czy tablica nie wymaga powiększenia
    {
        powiekszTablice();         // Jeśli tak, to powiększenie tablicy
    }

    // Przesunięcie wszystkich elementów o jedną pozycję w prawo
    for (int i = rozmiar; i > 0; --i)
    {
        tablica[i] = tablica[i - 1];
    }
    tablica[0] = wart;              // Wstawienie nowego elementu na początek
    rozmiar++;                      // Zwiększenie rozmiaru tablicy
}

// Usuwanie elementu z początku tablicy
void TablicaDynamiczna::odejmowanie_poczatek()
{
    if (rozmiar >= 0) {             // Sprawdzenie, czy tablica nie jest pusta
        // Przesunięcie wszystkich elementów o jedną pozycję w lewo
        for (int i = 0; i < rozmiar - 1; ++i) {
            tablica[i] = tablica[i + 1];
        }
        rozmiar--;                  // Zmniejszenie rozmiaru tablicy
    }
    else {
        cout << "Nie można usunąć elementu, tablica jest pusta." << endl;  // Komunikat o błędzie
    }
}

// Dodawanie elementu na koniec tablicy
void TablicaDynamiczna::dodawanie_koniec(int wart)
{
    if (rozmiar >= pojemnosc)      // Sprawdzenie, czy tablica nie wymaga powiększenia
    {
        powiekszTablice();         // Jeśli tak, to powiększenie tablicy
    }
    tablica[rozmiar++] = wart;     // Dodanie nowego elementu na koniec i zwiększenie rozmiaru
}

// Usuwanie elementu z końca tablicy
void TablicaDynamiczna::odejmowanie_koniec()
{
    if (rozmiar >= 0)
    {
        rozmiar--;                  // Zmniejszenie rozmiaru tablicy
    }
    else
    {
        cout << "Nie można usunąć elementu, tablica jest pusta." << endl;  // Komunikat o błędzie
    }
}

// Dodawanie elementu w dowolne miejsce tablicy
void TablicaDynamiczna::dodawanie_dowolne(int wart, int index)
{
    if (index < 0 || index > rozmiar)
    {
        cout << "Niepoprawny indeks." << endl;  // Komunikat o błędzie
        return;
    }

    if (rozmiar >= pojemnosc)
    {
        powiekszTablice();         // Jeśli tablica nie ma wystarczającej pojemności, to ją powiększ
    }

    // Przesunięcie wszystkich elementów o jedną pozycję w prawo
    for (int i = rozmiar; i > index; --i)
    {
        tablica[i] = tablica[i - 1];
    }
    tablica[index] = wart;          // Wstawienie nowego elementu na odpowiednie miejsce
    rozmiar++;                      // Zwiększenie rozmiaru tablicy
}

// Usuwanie elementu z dowolnego miejsca tablicy
void TablicaDynamiczna::odejmowanie_dowolne(int index)
{
    if (index < 0 || index >= rozmiar)
    {
        cout << "Niepoprawny indeks." << endl;  // Komunikat o błędzie
        return;
    }

    // Przesunięcie wszystkich elementów o jedną pozycję w lewo
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
        cout << "Tablica jest pusta." << endl;
        return -1;                  // Jeśli tak, to zwrócenie wartości -1
    }

    srand(time(NULL));              // Inicjowanie generatora liczb pseudolosowych
    int losowyIndex = (rand() % rozmiar) + 1; // Losowanie indeksu
    cout << "Wylosowany indeks to: " << losowyIndex << ", a wartość pod nim wynosi: ";
    return tablica[losowyIndex - 1];    // Zwracanie wartości losowego elementu (indeksowanie od zera)
}

// Usuwanie wszystkich elementów z tablicy
void TablicaDynamiczna::wyczysc_liste()
{
    delete[] tablica;               // Zwolnienie pamięci zaalokowanej dla tablicy
    tablica = nullptr;              // Ustawienie wskaźnika na nullptr
    pojemnosc = 0;                  // Resetowanie pojemności tablicy
    rozmiar = 0;                    // Resetowanie rozmiaru tablicy
}

// Zwraca obecny rozmiar tablicy
void TablicaDynamiczna::obecny_rozmiar() const
{
    cout << "Obecny rozmiar listy: " << rozmiar << endl;  // Zwracanie wartości rozmiaru tablicy
}
                  


// Wyświetla zawartość tablicy
void TablicaDynamiczna::wyswietl() const
{
    if (rozmiar == 0)               // Sprawdzenie, czy tablica jest pusta
    {
        cout << "Tablica jest pusta." << endl;    // Komunikat o pustej tablicy
        return;
    }

    cout << "POCZATEK" << endl;     // Wyświetlenie informacji o początku tablicy
    for (int i = 0; i < rozmiar; ++i)   // Przejście przez wszystkie elementy tablicy
    {
        cout << i+1<<".) "<<tablica[i] << endl;    // Wyświetlenie wartości elementu
    }
    cout << "KONIEC" << endl;       // Wyświetlenie informacji o końcu tablicy
}

// Powiększa tablicę dwukrotnie
void TablicaDynamiczna::powiekszTablice()
{
    int nowaPojemnosc;              // Zmienna przechowująca nową pojemność tablicy
    if (pojemnosc == 0)             // Sprawdzenie, czy tablica jest pusta
    {
        nowaPojemnosc = 1;          // Jeśli tak, to nowa pojemność wynosi 1
    }
    else
    {
        nowaPojemnosc = 2 * pojemnosc; // Jeśli nie, to nowa pojemność wynosi dwukrotność obecnej pojemności
    }

    // Utworzenie nowej tablicy o większej pojemności
    int* nowaTablica = new int[nowaPojemnosc];

    // Skopiowanie zawartości starej tablicy do nowej
    for (int i = 0; i < rozmiar; ++i)
    {
        nowaTablica[i] = tablica[i];
    }

    delete[] tablica;               // Zwolnienie pamięci zaalokowanej dla starej tablicy
    tablica = nowaTablica;          // Ustawienie wskaźnika na nową tablicę
    pojemnosc = nowaPojemnosc;      // Zaktualizowanie pojemności tablicy
}
