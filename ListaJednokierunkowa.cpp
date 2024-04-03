#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "ListaJednokierunkowa.h"

using namespace std;

// Konstruktor Wezla
ListaJK::Wezel::Wezel(int w) : wartosc(w) //konstruktor klasy Wezel, która jest zagnieżdżoną klasą w klasie ListaJK
{
    nastepny = nullptr;
}
//Zagnieżdżenie klasy może pomóc w hermetyzacji kodu poprzez ograniczenie dostępu do pewnych funkcji 
//lub danych tylko dla określonych części programu. Dzięki temu można uniknąć przypadkowego użycia 
//lub modyfikacji tych elementów przez inne części kodu.


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
        poczatek = poczatek->nastepny;  //przypisuje wskaźnikowi poczatek adres kolejnego elementu listy, 
                                        //który jest przechowywany w polu nastepny bieżącego elementu
        delete temp;
    }
}

// Dodawanie elementu na początek listy
void ListaJK::dodawanie_poczatek(int wart)
{
    // Tworzenie nowego węzła
    Wezel* nowyWezel = new Wezel(wart);
    // Nowy węzeł wskazuje na aktualny początek listy
    nowyWezel->nastepny = poczatek;
    // Aktualizacja wskaźnika na początek listy
    poczatek = nowyWezel;
    // Zwiększenie rozmiaru listy
    rozmiar++;
}

// Usuwanie elementu z początku listy
void ListaJK::odejmowanie_poczatek()
{
    // Sprawdzenie, czy lista nie jest pusta
    if (poczatek != nullptr)
    {
        // Zapisanie adresu pierwszego elementu
        Wezel* temp = poczatek;
        // Przesunięcie wskaźnika na początek na kolejny element
        poczatek = poczatek->nastepny;
        // Usunięcie pierwszego elementu
        delete temp;
        // Zmniejszenie rozmiaru listy
        rozmiar--;
    }
    else
    {
        // Komunikat o błędzie, gdy lista jest pusta
        cout << "Nie można usunąć elementu, lista jest pusta." << endl;
    }
}

// Dodawanie elementu na koniec listy
void ListaJK::dodawanie_koniec(int wart)
{
    // Tworzenie nowego węzła
    Wezel* nowyWezel = new Wezel(wart);
    // Jeśli lista jest pusta, nowy węzeł staje się początkiem listy
    if (poczatek == nullptr)
    {
        poczatek = nowyWezel;
    }
    else
    {
        // Przechodzenie przez listę do ostatniego elementu
        Wezel* temp = poczatek;
        while (temp->nastepny != nullptr)
        {
            temp = temp->nastepny;
        }
        // Dodanie nowego węzła na końcu listy
        temp->nastepny = nowyWezel;
    }
    // Zwiększenie rozmiaru listy
    rozmiar++;
}

// Usuwanie elementu z końca listy
void ListaJK::odejmowanie_koniec()
{
    // Sprawdzenie, czy lista nie jest pusta
    if (poczatek == nullptr)
    {
        cout << "Nie można usunąć elementu, lista jest pusta." << endl;
        return;
    }

    // Jeśli lista ma tylko jeden element
    if (poczatek->nastepny == nullptr)
    {
        // Usunięcie jedynego elementu
        delete poczatek;
        // Ustawienie wskaźnika początku listy na nullptr
        poczatek = nullptr;
    }
    else
    {
        // Przechodzenie przez listę do przedostatniego elementu
        Wezel* temp = poczatek;
        while (temp->nastepny->nastepny != nullptr)
        {
            temp = temp->nastepny;
        }
        // Usunięcie ostatniego elementu
        delete temp->nastepny;
        // Ustawienie wskaźnika następnego elementu ostatniego elementu na nullptr
        temp->nastepny = nullptr;
    }
    // Zmniejszenie rozmiaru listy
    rozmiar--;
}

// Dodawanie elementu w dowolne miejsce listy
void ListaJK::dodawanie_dowolne(int wart, int index)
{
    // Sprawdzenie, czy indeks jest prawidłowy
    if (index < 1 || index > rozmiar + 1)
    {
        cout << "Niepoprawny indeks: " << index << endl;
        return;
    }

    // Jeśli indeks to 1, dodaj na początku
    if (index == 1)
    {
        dodawanie_poczatek(wart);
        return;
    }

    // Tworzenie nowego węzła
    Wezel* nowyWezel = new Wezel(wart);
    // Przechodzenie przez listę do węzła poprzedzającego miejsce docelowe
    Wezel* temp = poczatek;
    for (int i = 1; i < index - 1; i++)
    {
        temp = temp->nastepny;
    }

    // Wstawienie nowego węzła za węzłem poprzedzającym miejsce docelowe
    nowyWezel->nastepny = temp->nastepny;
    temp->nastepny = nowyWezel;
    // Zwiększenie rozmiaru listy
    rozmiar++;
}

// Usuwanie elementu z dowolnego miejsca listy
void ListaJK::odejmowanie_dowolne(int index)
{
    // Sprawdzenie, czy indeks jest prawidłowy
    if (index < 1 || index > rozmiar)
    {
        cout << "Niepoprawny indeks: " << index << " dla rozmiaru " << rozmiar << endl;
        return;
    }

    // Jeśli indeks to 1, usuń z początku
    if (index == 1)
    {
        odejmowanie_poczatek();
        return;
    }

    // Przechodzenie przez listę do węzła poprzedzającego miejsce docelowe
    Wezel* temp = poczatek;
    for (int i = 1; i < index - 1; i++)
    {
        temp = temp->nastepny;
    }

    // Zapisanie adresu usuwanego węzła
    Wezel* usuwany = temp->nastepny;
    // Usunięcie węzła z listy
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

// Wyświetla zawartość listy
void ListaJK::wyswietl() const
{
    // Sprawdzenie, czy lista jest pusta
    if (poczatek == nullptr)
    {
        cout << "Lista jest pusta." << endl;
        return;
    }

    // Przechodzenie przez listę i wyświetlanie elementów
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

int ListaJK::wyszukaj_losowo() const
{
    // Inicjowanie generatora liczb pseudolosowych
    srand(time(NULL));

    // Sprawdzenie, czy lista nie jest pusta
    if (rozmiar == 0 || poczatek == nullptr) {
        cout << "Lista jest pusta." << endl;
        return -1;
    }

    // Generowanie losowego indeksu
    int losowyIndex = (rand() % rozmiar) + 1;
    cout << "Wylosowany indeks to: " << losowyIndex << ", a wartość pod nim wynosi: ";

    // Przechodzenie przez listę do losowego elementu
    Wezel* temp = poczatek;
    for (int i = 1; i < losowyIndex; i++)
    {
        temp = temp->nastepny;
    }

    // Zwracanie wartości losowego elementu
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
