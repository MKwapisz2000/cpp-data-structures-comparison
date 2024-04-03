#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "lista_dwukierunkowa.h"

using namespace std;

Wezel::Wezel(int w) : wartosc(w)
{
	nastepny = nullptr;
	poprzedni = nullptr;
}

ListaDK::ListaDK()
{
	rozmiar = 0;
	poczatek = nullptr;
	koniec = nullptr;
}

ListaDK::~ListaDK()
{
	Wezel* obecny = poczatek;
	while (obecny)
	{
		Wezel* tymczasowy = obecny;
		obecny = obecny->nastepny;
		delete tymczasowy;
	}
}


void ListaDK::dodawanie_poczatek(int wart)
{
	//Za�o�enia:
	//Je�eli lista jest pusta ->
	//   nowy w�ze� jest jej pocz�tkiem i ko�cem,
	//   jego elememnty "poprzedni" i "nast�pny" ju� s� ustawione domy�lnie na nullptr,
	// 
	//Je�eli nie ->
	//   nowy_w�ze�->nast�pny = pocz�tek (dotychczasowy weze� b�d�cy pocz�tkiem)
	// 
	//   pocz�tek->poprzedni = nowy_w�ze�
	//   pocz�tek = nowy_w�ze�
	// 
	//zawi�kszenie rozmiary listy o 1

	Wezel* nowy = new Wezel(wart);
	if (poczatek == nullptr)
	{
		poczatek = nowy;
		koniec = nowy;
	}
	else
	{
		nowy->nastepny = poczatek;

		poczatek->poprzedni = nowy;
		poczatek = nowy;
	}

	rozmiar++;
}



void ListaDK::odejmowanie_poczatek()
{
	//Za�o�enia:
	//Je�eli lista jest pusta ->
	//   return
	//   
	//Je�eli nie ->
	//   Je�eli lista zawiera jeden element->
	//     stworzenie wska�nika "*tymczasowy" na element do usuni�cia(pocz�tek),
	//     pocz�tek = nullptr,
	//     koniec = nullptr,
	//     delete tymczasowy,
	// 
	//   Je�eli nie->
	//     stworzenie wska�nika "*tymczasowy" na element do usuni�cia(pocz�tek),
	//     pocz�tek = pocz�tek->nast�pny,
	//     pocz�tek->poprzedni = nullptr,
	//     delete *tymczasowy
	// 
	//zmniejszenie rozmiaru listy o 1

	if (poczatek == nullptr)
	{
		cout << "Nie mozna odjac elementu, poniewaz lista jest pusta" << endl;
		return;
	}

	else
	{

		if (poczatek == koniec)
		{
			Wezel* tymczasowy = poczatek;
			poczatek = nullptr;
			koniec = nullptr;
			delete tymczasowy;
		}

		else
		{
			Wezel* tymczasowy = poczatek;
			poczatek = poczatek->nastepny;
			poczatek->poprzedni = nullptr;
			delete tymczasowy;
		}
	}

	rozmiar--;
}


void ListaDK::dodawanie_koniec(int wart)
{
	//Za�o�enia:
	//Tworzymy nowy wezel,
	//Je�eli lista jest pusta ->
	//   poczatek = nowy,
	//   koniec = nowy,
	//   
	//Je�eli nie ->
	//   koniec->nastepny = nowy,
	//   nowy->poprzedni = koniec,
	//   koniec = nowy,
	//   
	//zawi�kszenie rozmiary listy o 1

	Wezel* nowy = new Wezel(wart);
	if (koniec == nullptr)
	{
		poczatek = nowy;
		koniec = nowy;
	}

	else
	{
		koniec->nastepny = nowy;
		nowy->poprzedni = koniec;
		koniec = nowy;
	}

	rozmiar++;
}

void ListaDK::odejmowanie_koniec()
{
	//Za�o�enia:
	//Je�eli lista jest pusta ->
	//   return
	// 
	//Je�eli nie ->
	//   Je�eli lista zawiera jeden element->
	//     stworzenie wska�nika "*tymczasowy" na element do usuni�cia(koniec),
	//     pocz�tek = nullptr,
	//     koniec = nullptr,
	//     delete tymczasowy,
	// 
	//   Je�eli nie->
	//     stworzenie wska�nika "*tymczasowy" na element do usuni�cia(koniec),
	//     pocz�tek = pocz�tek->nast�pny,
	//     pocz�tek->poprzedni = nullptr,
	//     delete tymczasowy
	// 
	//zmniejszenie rozmiaru listy o 1

	if (poczatek == nullptr)
	{
		cout << "Nie mozna odjac elementu, poniewaz lista jest pusta" << endl;
		return;
	}

	else
	{

		if (poczatek == koniec)
		{
			Wezel* tymczasowy = koniec;
			poczatek = nullptr;
			koniec = nullptr;
			delete tymczasowy;
		}

		else
		{
			Wezel* tymczasowy = koniec;
			koniec = koniec->poprzedni;
			koniec->nastepny = nullptr;
			delete tymczasowy;
		}
	}

	rozmiar--;
}


void ListaDK::dodawanie_dowolne(int wart, int index)
{
	if (index > rozmiar + 1 || index < 1)
	{
		cout << "Nie ma takiego elememtu" << endl;
		return;
	}

	if (index == 1)
	{
		dodawanie_poczatek(wart);
		return;
	}

	if (index == rozmiar + 1)
	{
		dodawanie_koniec(wart);
		return;
	}

	Wezel* nowy = new Wezel(wart);
	Wezel* tymczasowy;

	if (index <= rozmiar / 2)
	{
		tymczasowy = poczatek;
		for (int i = 1; i < index - 1; i++)
		{
			tymczasowy = tymczasowy->nastepny;
		}
	}

	else
	{
		tymczasowy = koniec;
		for (int i = rozmiar; i > index - 1; i--)
		{
			tymczasowy = tymczasowy->poprzedni;
		}
	}

	nowy->nastepny = tymczasowy->nastepny;
	nowy->poprzedni = tymczasowy;
	tymczasowy->nastepny->poprzedni = nowy;
	tymczasowy->nastepny = nowy;

	rozmiar++;
}


void ListaDK::odejmowanie_dowolne(int index)
{
	if (index > rozmiar || index < 1)
	{
		cout << "Nie ma takiego elememtu" << endl;
		return;
	}

	if (index == 1)
	{
		odejmowanie_poczatek();
		return;
	}

	if (index == rozmiar)
	{
		odejmowanie_koniec();
		return;
	}

	Wezel* tymczasowy;

	if (index <= rozmiar / 2)
	{
		tymczasowy = poczatek;
		for (int i = 1; i < index; i++)
		{
			tymczasowy = tymczasowy->nastepny;
		}
	}

	else
	{
		tymczasowy = koniec;
		for (int i = rozmiar; i > index; i--)
		{
			tymczasowy = tymczasowy->poprzedni;
		}
	}

	tymczasowy->poprzedni->nastepny = tymczasowy->nastepny;
	tymczasowy->nastepny->poprzedni = tymczasowy->poprzedni;
	delete tymczasowy;

	rozmiar--;

}


void ListaDK::obecny_rozmiar() const
{
	cout << "Obecny rozmiar listy: " << rozmiar << endl;
}


void ListaDK::wyswietl() const
{
	Wezel* tymczasowy = poczatek;
	cout << "POCZATEK" << endl;
	for (int i = 0; i < rozmiar; i++)
	{
		cout << i + 1 << ".) " << tymczasowy->wartosc << endl;
		tymczasowy = tymczasowy->nastepny;
	}
	cout << "KONIEC" << endl;
	delete tymczasowy;
}


int ListaDK::wyszukaj() const
{
	srand(time(NULL));
	int wylosowany_index = (rand() % rozmiar) + 1;
	Wezel* tymczasowy;

	if (wylosowany_index <= rozmiar / 2)
	{
		tymczasowy = poczatek;
		for (int i = 1; i < wylosowany_index; i++)
		{
			tymczasowy = tymczasowy->nastepny;
		}
		cout << "Wylosowany indeks to: " << wylosowany_index << ", a wartosc pod nim wynosi: ";
	}

	else
	{
		tymczasowy = koniec;
		for (int i = rozmiar; i > wylosowany_index; i--)
		{
			tymczasowy = tymczasowy->poprzedni;
		}
		cout << "Wylosowany indeks to: " << wylosowany_index << ", a wartosc pod nim wynosi: ";
	}

	return tymczasowy->wartosc;
}

void ListaDK::wyczysc_liste()
{
	while (poczatek != nullptr)
	{
		Wezel* tymczasowy = poczatek;
		poczatek = poczatek->nastepny;
		delete tymczasowy;
	}
	koniec = nullptr;
	poczatek = nullptr;
}