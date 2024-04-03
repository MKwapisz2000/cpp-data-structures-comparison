#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "ListaJednokierunkowaZGlowaIOgonem.h"

using namespace std;

// Konstruktor Wezla
ListaJKOG::Wezel::Wezel(int w) : wartosc(w)
{
    nastepny = nullptr;
}

// Konstruktor klasy ListaJKOG
ListaJKOG::ListaJKOG()
{
    poczatek = nullptr;
    koniec = nullptr;
    rozmiar = 0;
}

// Destruktor klasy ListaJKOG
ListaJKOG::~ListaJKOG()
{
    // Usuwanie wszystkich element�w z listy
    Wezel* temp;
    while (poczatek)
    {
        temp = poczatek;
        poczatek = poczatek->nastepny;
        delete temp;
    }
}

// Dodawanie elementu na pocz�tek listy
void ListaJKOG::dodawanie_poczatek(int wart)
{
    // Tworzenie nowego w�z�a
    Wezel* nowy_wezel = new Wezel(wart);
    // Je�li lista jest pusta, nowy w�ze� staje si� zar�wno pocz�tkiem, jak i ko�cem listy
    if (poczatek == nullptr)
    {
        poczatek = nowy_wezel;
        koniec = nowy_wezel;
    }
    else
    {
        // Dodawanie nowego w�z�a na pocz�tek listy
        nowy_wezel->nastepny = poczatek;
        poczatek = nowy_wezel;
    }
    // Zwi�kszenie rozmiaru listy
    rozmiar++;
}

// Usuwanie elementu z pocz�tku listy
void ListaJKOG::odejmowanie_poczatek()
{
    // Sprawdzenie, czy lista nie jest pusta
    if (poczatek == nullptr) {
        cout << "Nie mozna usunac elementu, poniewaz lista jest pusta" << endl;
        return;
    }

    // Je�li lista zawiera tylko jeden element
    if (poczatek == koniec)
    {
        // Usuni�cie jedynego elementu
        delete poczatek;
        // Ustawienie wska�nik�w pocz�tku i ko�ca na nullptr
        poczatek = nullptr;
        koniec = nullptr;
    }
    else
    {
        // Zapisanie adresu pierwszego elementu
        Wezel* temp = poczatek;
        // Przesuni�cie wska�nika pocz�tku na kolejny element
        poczatek = poczatek->nastepny;
        // Usuni�cie pierwszego elementu
        delete temp;
    }
    // Zmniejszenie rozmiaru listy
    rozmiar--;
}

// Dodawanie elementu na koniec listy
void ListaJKOG::dodawanie_koniec(int wart)
{
    // Tworzenie nowego w�z�a
    Wezel* nowy_wezel = new Wezel(wart);
    // Je�li lista jest pusta, nowy w�ze� staje si� zar�wno pocz�tkiem, jak i ko�cem listy
    if (poczatek == nullptr) {
        poczatek = nowy_wezel;
        koniec = nowy_wezel;
    }
    else
    {
        // Dodawanie nowego w�z�a na koniec listy
        koniec->nastepny = nowy_wezel;
        koniec = nowy_wezel;
    }
    // Zwi�kszenie rozmiaru listy
    rozmiar++;
}

// Usuwanie elementu z ko�ca listy
void ListaJKOG::odejmowanie_koniec()
{
    // Sprawdzenie, czy lista nie jest pusta
    if (poczatek == nullptr)
    {
        cout << "Nie mozna usunac elementu, poniewaz lista jest pusta" << endl;
        return;
    }

    // Je�li lista zawiera tylko jeden element
    if (poczatek == koniec)
    {
        // Usuni�cie jedynego elementu
        delete koniec;
        // Ustawienie wska�nik�w pocz�tku i ko�ca na nullptr
        poczatek = nullptr;
        koniec = nullptr;
    }
    else
    {
        // Zapisanie adresu ostatniego elementu
        Wezel* temp = koniec;
        // Przechodzenie przez list� do przedostatniego elementu
        Wezel* obecny = poczatek;
        while (obecny->nastepny != koniec)
        {
            obecny = obecny->nastepny;
        }
        // Ustawienie nowego ko�ca listy
        koniec = obecny;
        koniec->nastepny = nullptr;
        // Usuni�cie ostatniego elementu
        delete temp;
    }
    // Zmniejszenie rozmiaru listy
    rozmiar--;
}

// Dodawanie elementu w dowolne miejsce listy
void ListaJKOG::dodawanie_dowolne(int wart, int index)
{
    // Sprawdzenie, czy indeks jest prawid�owy
    if (index < 1 || index > rozmiar + 1)
    {
        cout << "Niepoprawny indeks" << endl;
        return;
    }

    // Dodawanie na pocz�tek listy
    if (index == 1)
    {
        dodawanie_poczatek(wart);
        return;
    }

    // Dodawanie na koniec listy
    if (index == rozmiar + 1)
    {
        dodawanie_koniec(wart);
        return;
    }

    // Tworzenie nowego w�z�a
    Wezel* nowy_wezel = new Wezel(wart);
    Wezel* temp = poczatek;
    for (int i = 1; i < index - 1; i++)
    {
        temp = temp->nastepny;
    }

    // Wstawienie nowego w�z�a w odpowiednie miejsce listy
    nowy_wezel->nastepny = temp->nastepny;
    temp->nastepny = nowy_wezel;
    // Zwi�kszenie rozmiaru listy
    rozmiar++;
}

// Usuwanie elementu z dowolnego miejsca listy
void ListaJKOG::odejmowanie_dowolne(int index)
{
    // Sprawdzenie, czy indeks jest prawid�owy
    if (index < 1 || index > rozmiar)
    {
        cout << "Niepoprawny indeks: " << index << endl;
        return;
    }

    // Usuwanie z pocz�tku listy
    if (index == 1)
    {
        odejmowanie_poczatek();
        return;
    }

    // Usuwanie z ko�ca listy
    if (index == rozmiar)
    {
        odejmowanie_koniec();
        return;
    }

    // Przeszukiwanie listy do odpowiedniego miejsca
    Wezel* temp = poczatek;
    for (int i = 1; i < index - 1; i++)
    {
        temp = temp->nastepny;
    }

    // Usuni�cie odpowiedniego elementu
    Wezel* usuwany = temp->nastepny;
    temp->nastepny = temp->nastepny->nastepny;
    delete usuwany;
    // Zmniejszenie rozmiaru listy
    rozmiar--;
}

// Zwraca obecny rozmiar listy
void ListaJKOG::obecny_rozmiar() const
{
    cout << "Obecny rozmiar listy: " << rozmiar << endl;
}

// Wy�wietla zawarto�� listy
void ListaJKOG::wyswietl() const
{
    // Sprawdzenie, czy lista jest pusta
    if (poczatek == nullptr) {
        cout << "Lista jest pusta" << endl;
        return;
    }

    // Wy�wietlenie zawarto�ci listy
    Wezel* temp = poczatek;
    cout << "POCZATEK" << endl;
    int i = 1;
    while (temp)
    {
        cout <<i<<".) "<< temp->wartosc << endl;
        temp = temp->nastepny;
        i++;
    }
    cout << "KONIEC" << endl;
}

// Wyszukuje losowy element listy i zwraca jego warto��
int ListaJKOG::wyszukaj_losowo() const
{
    // Inicjowanie generatora liczb pseudolosowych
    srand(time(NULL));
    // Losowanie indeksu
    int wylosowany_index = (rand() % rozmiar) + 1;
    // Przechodzenie przez list� do losowego elementu
    Wezel* temp = poczatek;
    for (int i = 1; i < wylosowany_index; i++)
    {
        temp = temp->nastepny;
    }
    // Zwracanie warto�ci losowego elementu
    return temp->wartosc;
}

// Usuwa wszystkie elementy z listy
void ListaJKOG::wyczysc_liste()
{
    // Usuwanie wszystkich element�w z listy
    while (poczatek != nullptr)
    {
        Wezel* temp = poczatek;
        poczatek = poczatek->nastepny;
        delete temp;
    }
    // Resetowanie rozmiaru listy
    koniec = nullptr;
    rozmiar = 0;
}
