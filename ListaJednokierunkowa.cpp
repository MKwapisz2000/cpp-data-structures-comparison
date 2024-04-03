#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "ListaJednokierunkowa.h"

using namespace std;

// Konstruktor Wezla
ListaJK::Wezel::Wezel(int w) : wartosc(w)
{
    nastepny = nullptr;
}

// Konstruktor klasy ListaJK
ListaJK::ListaJK()
{
    poczatek = nullptr;
    rozmiar = 0;
}

// Destruktor klasy ListaJK
ListaJK::~ListaJK()
{
    // Usuwanie wszystkich element�w z listy
    while (poczatek != nullptr)
    {
        Wezel* temp = poczatek;
        poczatek = poczatek->nastepny;
        delete temp;
    }
}

// Dodawanie elementu na pocz�tek listy
void ListaJK::dodawanie_poczatek(int wart)
{
    // Tworzenie nowego w�z�a
    Wezel* nowyWezel = new Wezel(wart);
    // Nowy w�ze� wskazuje na aktualny pocz�tek listy
    nowyWezel->nastepny = poczatek;
    // Aktualizacja wska�nika na pocz�tek listy
    poczatek = nowyWezel;
    // Zwi�kszenie rozmiaru listy
    rozmiar++;
}

// Usuwanie elementu z pocz�tku listy
void ListaJK::odejmowanie_poczatek()
{
    // Sprawdzenie, czy lista nie jest pusta
    if (poczatek != nullptr)
    {
        // Zapisanie adresu pierwszego elementu
        Wezel* temp = poczatek;
        // Przesuni�cie wska�nika na pocz�tek na kolejny element
        poczatek = poczatek->nastepny;
        // Usuni�cie pierwszego elementu
        delete temp;
        // Zmniejszenie rozmiaru listy
        rozmiar--;
    }
    else
    {
        // Komunikat o b��dzie, gdy lista jest pusta
        cout << "Nie mo�na usun�� elementu, lista jest pusta." << endl;
    }
}

// Dodawanie elementu na koniec listy
void ListaJK::dodawanie_koniec(int wart)
{
    // Tworzenie nowego w�z�a
    Wezel* nowyWezel = new Wezel(wart);
    // Je�li lista jest pusta, nowy w�ze� staje si� pocz�tkiem listy
    if (poczatek == nullptr)
    {
        poczatek = nowyWezel;
    }
    else
    {
        // Przechodzenie przez list� do ostatniego elementu
        Wezel* temp = poczatek;
        while (temp->nastepny != nullptr)
        {
            temp = temp->nastepny;
        }
        // Dodanie nowego w�z�a na ko�cu listy
        temp->nastepny = nowyWezel;
    }
    // Zwi�kszenie rozmiaru listy
    rozmiar++;
}

// Usuwanie elementu z ko�ca listy
void ListaJK::odejmowanie_koniec()
{
    // Sprawdzenie, czy lista nie jest pusta
    if (poczatek == nullptr)
    {
        cout << "Nie mo�na usun�� elementu, lista jest pusta." << endl;
        return;
    }

    // Je�li lista ma tylko jeden element
    if (poczatek->nastepny == nullptr)
    {
        // Usuni�cie jedynego elementu
        delete poczatek;
        // Ustawienie wska�nika pocz�tku listy na nullptr
        poczatek = nullptr;
    }
    else
    {
        // Przechodzenie przez list� do przedostatniego elementu
        Wezel* temp = poczatek;
        while (temp->nastepny->nastepny != nullptr)
        {
            temp = temp->nastepny;
        }
        // Usuni�cie ostatniego elementu
        delete temp->nastepny;
        // Ustawienie wska�nika nast�pnego elementu ostatniego elementu na nullptr
        temp->nastepny = nullptr;
    }
    // Zmniejszenie rozmiaru listy
    rozmiar--;
}

// Dodawanie elementu w dowolne miejsce listy
void ListaJK::dodawanie_dowolne(int wart, int index)
{
    // Sprawdzenie, czy indeks jest prawid�owy
    if (index < 1 || index > rozmiar + 1)
    {
        cout << "Niepoprawny indeks: " << index << endl;
        return;
    }

    // Je�li indeks to 1, dodaj na pocz�tku
    if (index == 1)
    {
        dodawanie_poczatek(wart);
        return;
    }

    // Tworzenie nowego w�z�a
    Wezel* nowyWezel = new Wezel(wart);
    // Przechodzenie przez list� do w�z�a poprzedzaj�cego miejsce docelowe
    Wezel* temp = poczatek;
    for (int i = 1; i < index - 1; i++)
    {
        temp = temp->nastepny;
    }

    // Wstawienie nowego w�z�a za w�z�em poprzedzaj�cym miejsce docelowe
    nowyWezel->nastepny = temp->nastepny;
    temp->nastepny = nowyWezel;
    // Zwi�kszenie rozmiaru listy
    rozmiar++;
}

// Usuwanie elementu z dowolnego miejsca listy
void ListaJK::odejmowanie_dowolne(int index)
{
    // Sprawdzenie, czy indeks jest prawid�owy
    if (index < 1 || index > rozmiar)
    {
        cout << "Niepoprawny indeks: " << index << " dla rozmiaru " << rozmiar << endl;
        return;
    }

    // Je�li indeks to 1, usu� z pocz�tku
    if (index == 1)
    {
        odejmowanie_poczatek();
        return;
    }

    // Przechodzenie przez list� do w�z�a poprzedzaj�cego miejsce docelowe
    Wezel* temp = poczatek;
    for (int i = 1; i < index - 1; i++)
    {
        temp = temp->nastepny;
    }

    // Zapisanie adresu usuwanego w�z�a
    Wezel* usuwany = temp->nastepny;
    // Usuni�cie w�z�a z listy
    temp->nastepny = temp->nastepny->nastepny;
    delete usuwany;
    // Zmniejszenie rozmiaru listy
    rozmiar--;
}

// Zwraca obecny rozmiar listy
void ListaJK::obecny_rozmiar() const
{
    cout << "Obecny rozmiar listy: " << rozmiar << endl;
}

// Wy�wietla zawarto�� listy
void ListaJK::wyswietl() const
{
    // Sprawdzenie, czy lista jest pusta
    if (poczatek == nullptr)
    {
        cout << "Lista jest pusta." << endl;
        return;
    }

    // Przechodzenie przez list� i wy�wietlanie element�w
    Wezel* temp = poczatek;
    int i = 1;
    cout << "POCZATEK" << endl;
    while (temp != nullptr)
    {
        cout <<i<<".) "<< temp->wartosc << endl;
        temp = temp->nastepny;
        i++;
    }
    cout << "KONIEC" << endl;
}

// Wyszukuje losowy element listy i zwraca jego warto��
int ListaJK::wyszukaj_losowo() const
{
    // Inicjowanie generatora liczb pseudolosowych
    srand(time(nullptr));
    // Generowanie losowego indeksu
    int losowyIndex = (rand() % rozmiar) + 1;
    // Przechodzenie przez list� do losowego elementu
    Wezel* temp = poczatek;
    for (int i = 1; i < losowyIndex; i++)
    {
        temp = temp->nastepny;
    }
    // Zwracanie warto�ci losowego elementu
    return temp->wartosc;
}

// Usuwa wszystkie elementy z listy
void ListaJK::wyczysc_liste()
{
    // Usuwanie wszystkich element�w z listy
    while (poczatek != nullptr)
    {
        Wezel* temp = poczatek;
        poczatek = poczatek->nastepny;
        delete temp;
    }
    // Resetowanie rozmiaru listy
    rozmiar = 0;
}
