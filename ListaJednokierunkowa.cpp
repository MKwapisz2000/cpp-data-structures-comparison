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
    // Usuwanie wszystkich elementów z listy
    while (poczatek != nullptr)
    {
        Wezel* temp = poczatek;
        poczatek = poczatek->nastepny;
        delete temp;
    }
}

// Dodawanie elementu na pocz¹tek listy
void ListaJK::dodawanie_poczatek(int wart)
{
    // Tworzenie nowego wêz³a
    Wezel* nowyWezel = new Wezel(wart);
    // Nowy wêze³ wskazuje na aktualny pocz¹tek listy
    nowyWezel->nastepny = poczatek;
    // Aktualizacja wskaŸnika na pocz¹tek listy
    poczatek = nowyWezel;
    // Zwiêkszenie rozmiaru listy
    rozmiar++;
}

// Usuwanie elementu z pocz¹tku listy
void ListaJK::odejmowanie_poczatek()
{
    // Sprawdzenie, czy lista nie jest pusta
    if (poczatek != nullptr)
    {
        // Zapisanie adresu pierwszego elementu
        Wezel* temp = poczatek;
        // Przesuniêcie wskaŸnika na pocz¹tek na kolejny element
        poczatek = poczatek->nastepny;
        // Usuniêcie pierwszego elementu
        delete temp;
        // Zmniejszenie rozmiaru listy
        rozmiar--;
    }
    else
    {
        // Komunikat o b³êdzie, gdy lista jest pusta
        cout << "Nie mo¿na usun¹æ elementu, lista jest pusta." << endl;
    }
}

// Dodawanie elementu na koniec listy
void ListaJK::dodawanie_koniec(int wart)
{
    // Tworzenie nowego wêz³a
    Wezel* nowyWezel = new Wezel(wart);
    // Jeœli lista jest pusta, nowy wêze³ staje siê pocz¹tkiem listy
    if (poczatek == nullptr)
    {
        poczatek = nowyWezel;
    }
    else
    {
        // Przechodzenie przez listê do ostatniego elementu
        Wezel* temp = poczatek;
        while (temp->nastepny != nullptr)
        {
            temp = temp->nastepny;
        }
        // Dodanie nowego wêz³a na koñcu listy
        temp->nastepny = nowyWezel;
    }
    // Zwiêkszenie rozmiaru listy
    rozmiar++;
}

// Usuwanie elementu z koñca listy
void ListaJK::odejmowanie_koniec()
{
    // Sprawdzenie, czy lista nie jest pusta
    if (poczatek == nullptr)
    {
        cout << "Nie mo¿na usun¹æ elementu, lista jest pusta." << endl;
        return;
    }

    // Jeœli lista ma tylko jeden element
    if (poczatek->nastepny == nullptr)
    {
        // Usuniêcie jedynego elementu
        delete poczatek;
        // Ustawienie wskaŸnika pocz¹tku listy na nullptr
        poczatek = nullptr;
    }
    else
    {
        // Przechodzenie przez listê do przedostatniego elementu
        Wezel* temp = poczatek;
        while (temp->nastepny->nastepny != nullptr)
        {
            temp = temp->nastepny;
        }
        // Usuniêcie ostatniego elementu
        delete temp->nastepny;
        // Ustawienie wskaŸnika nastêpnego elementu ostatniego elementu na nullptr
        temp->nastepny = nullptr;
    }
    // Zmniejszenie rozmiaru listy
    rozmiar--;
}

// Dodawanie elementu w dowolne miejsce listy
void ListaJK::dodawanie_dowolne(int wart, int index)
{
    // Sprawdzenie, czy indeks jest prawid³owy
    if (index < 1 || index > rozmiar + 1)
    {
        cout << "Niepoprawny indeks: " << index << endl;
        return;
    }

    // Jeœli indeks to 1, dodaj na pocz¹tku
    if (index == 1)
    {
        dodawanie_poczatek(wart);
        return;
    }

    // Tworzenie nowego wêz³a
    Wezel* nowyWezel = new Wezel(wart);
    // Przechodzenie przez listê do wêz³a poprzedzaj¹cego miejsce docelowe
    Wezel* temp = poczatek;
    for (int i = 1; i < index - 1; i++)
    {
        temp = temp->nastepny;
    }

    // Wstawienie nowego wêz³a za wêz³em poprzedzaj¹cym miejsce docelowe
    nowyWezel->nastepny = temp->nastepny;
    temp->nastepny = nowyWezel;
    // Zwiêkszenie rozmiaru listy
    rozmiar++;
}

// Usuwanie elementu z dowolnego miejsca listy
void ListaJK::odejmowanie_dowolne(int index)
{
    // Sprawdzenie, czy indeks jest prawid³owy
    if (index < 1 || index > rozmiar)
    {
        cout << "Niepoprawny indeks: " << index << " dla rozmiaru " << rozmiar << endl;
        return;
    }

    // Jeœli indeks to 1, usuñ z pocz¹tku
    if (index == 1)
    {
        odejmowanie_poczatek();
        return;
    }

    // Przechodzenie przez listê do wêz³a poprzedzaj¹cego miejsce docelowe
    Wezel* temp = poczatek;
    for (int i = 1; i < index - 1; i++)
    {
        temp = temp->nastepny;
    }

    // Zapisanie adresu usuwanego wêz³a
    Wezel* usuwany = temp->nastepny;
    // Usuniêcie wêz³a z listy
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

// Wyœwietla zawartoœæ listy
void ListaJK::wyswietl() const
{
    // Sprawdzenie, czy lista jest pusta
    if (poczatek == nullptr)
    {
        cout << "Lista jest pusta." << endl;
        return;
    }

    // Przechodzenie przez listê i wyœwietlanie elementów
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

// Wyszukuje losowy element listy i zwraca jego wartoœæ
int ListaJK::wyszukaj_losowo() const
{
    // Inicjowanie generatora liczb pseudolosowych
    srand(time(nullptr));
    // Generowanie losowego indeksu
    int losowyIndex = (rand() % rozmiar) + 1;
    // Przechodzenie przez listê do losowego elementu
    Wezel* temp = poczatek;
    for (int i = 1; i < losowyIndex; i++)
    {
        temp = temp->nastepny;
    }
    // Zwracanie wartoœci losowego elementu
    return temp->wartosc;
}

// Usuwa wszystkie elementy z listy
void ListaJK::wyczysc_liste()
{
    // Usuwanie wszystkich elementów z listy
    while (poczatek != nullptr)
    {
        Wezel* temp = poczatek;
        poczatek = poczatek->nastepny;
        delete temp;
    }
    // Resetowanie rozmiaru listy
    rozmiar = 0;
}
