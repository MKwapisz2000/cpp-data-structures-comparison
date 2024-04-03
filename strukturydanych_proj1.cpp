#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "lista_dwukierunkowa.h"
#include "TablicaDynamiczna.h"
#include "ListaJednokierunkowa.h"
#include "ListaJednokierunkowaZGlowaIOgonem.h"
#include <stdio.h>
#include <chrono>

using namespace std;



int main()
{

	//..............................OBIEKTY POSZCZEGOLNYCH STRUKTUR...........................................


	ListaDK L1;
	TablicaDynamiczna TD;
	ListaJK LJ;
	ListaJKOG LJOG;

	//.......................................................................................................





	//..............................WCZYTANIE DANYCH Z PLIKU...............................................

	ifstream plik;
	string nazwa = "dane1_2k.txt";
	plik.open(nazwa, ios::out);
	if (!plik.good())
	{
		cout << "Blad przy otwarciu pliku." << endl;
		return -1;
	}

	else
	{
		int liczba;
		while (plik >> liczba)
		{
			L1.dodawanie_koniec(liczba);
			TD.dodawanie_koniec(liczba);
			LJ.dodawanie_koniec(liczba);
			LJOG.dodawanie_koniec(liczba);
		}
	}
	plik.close();

	//.....................................................................................................





	//..................................POMIAR CZASU......................................................
	/*
		auto begin = chrono::high_resolution_clock::now();
		L1.wyszukaj();
		auto end = chrono::high_resolution_clock::now();
		auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

		auto begin = chrono::high_resolution_clock::now();
		TD.wyszukaj();
		auto end = chrono::high_resolution_clock::now();
		auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

		auto begin = chrono::high_resolution_clock::now();
		LJ.wyszukaj();
		auto end = chrono::high_resolution_clock::now();
		auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

		auto begin = chrono::high_resolution_clock::now();
		LJGO.wyszukaj();
		auto end = chrono::high_resolution_clock::now();
		auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
	*/
	//.....................................................................................................






	//.......................................MENU..........................................................

	int zmienna1;
	char zmienna2;
	int wart;
	int index;
	cout << "STRUKTURY DANYCH:" << endl
		<< "[1] Lista dynamiczna" << endl
		<< "[2] Lista jednokierunkowa z glowa" << endl
		<< "[3] Lista jednokierunkowa z glowa i ogonem" << endl
		<< "[4] Lista dwukierunkowa" << endl;
	cout << "Przechodze do struktury numer: ";
	cin >> zmienna1;
	system("cls");
	switch (zmienna1)
	{
	case 1:
	{
		cout << "Wybierz funkcje z ktorej chcesz skorzystac:" << endl
			<< "[a] dodawanie elementu na poczatku" << endl
			<< "[b] dodawanie elementu na koncu" << endl
			<< "[c] usuwanie elementu na poczatku" << endl
			<< "[d] usuwanie elementu na koncu" << endl
			<< "[e] dodawanie elementu w wybranym miejscu" << endl
			<< "[f] usuwanie elementu z wybranego miejsca" << endl
			<< "[g] wyszukanie elementu" << endl;
		cout << "Przechodze do funkcji: ";
		cin >> zmienna2;

		switch (zmienna2)
		{
		case 'a':
		{
			cout << "Podaj wartosc ktora chcesz dodac: ";
			cin >> wart;
			TD.dodawanie_poczatek(wart); 
			cout << endl;
			system("cls");
			TD.obecny_rozmiar();
			TD.wyswietl();
			
			break;
		}

		case 'b':
		{
			cout << "Podaj wartosc ktora chcesz dodac: ";
			cin >> wart;
			TD.dodawanie_koniec(wart); 
			cout << endl;
			system("cls");
			TD.obecny_rozmiar();
			TD.wyswietl();
			
			break;
		}

		case 'c':
		{
			TD.odejmowanie_poczatek(); 
			cout << endl;
			system("cls");
			TD.obecny_rozmiar();
			TD.wyswietl();
			
			break;
		}

		case 'd':
		{
			TD.odejmowanie_koniec(); 
			cout << endl;
			system("cls");
			TD.obecny_rozmiar();
			TD.wyswietl();
			
			break;
		}

		case 'e':
		{
			cout << "Podaj wartosc ktora chcesz dodac oraz pozycje na ktorej ma sie znalezc: ";
			cin >> wart >> index;
			TD.dodawanie_dowolne(wart, index); 
			cout << endl;
			system("cls");
			TD.obecny_rozmiar();
			TD.wyswietl();
			
			break;
		}

		case 'f':
		{
			cout << "Podaj pozycje ktora ma zostac usunieta: ";
			cin >> index;
			TD.odejmowanie_dowolne(index); 
			cout << endl;
			system("cls");
			TD.obecny_rozmiar();
			TD.wyswietl();
			
			break;
		}

		case 'g':
		{
			cout << "Zostanie wysolowana pozycja do wyszukania." << endl;;
			int szukana = TD.wyszukaj_losowo(); 
			cout << szukana << endl;
			cout << endl;
			TD.obecny_rozmiar();
			TD.wyswietl();
			
			break;
		}

		default:
			break;
		}
	}

	case 2: // Obsługa opcji dla listy jednokierunkowej z glowa
	{
		cout << "Wybierz funkcje z ktorej chcesz skorzystac:" << endl << "[a] dodawanie elementu na poczatku" << endl
			<< "[b] dodawanie elementu na koncu" << endl << "[c] usuwanie elementu na poczatku" << endl
			<< "[d] usuwanie elementu na koncu" << endl << "[e] dodawanie elementu w wybranym miejscu" << endl
			<< "[f] usuwanie elementu z wybranego miejsca" << endl << "[g] wyszukanie elementu" << endl;
		cout << "Przechodze do funkcji: ";
		cin >> zmienna2;

		switch (zmienna2)
		{
		case 'a':
		{
			cout << "Podaj wartosc ktora chcesz dodac: ";
			cin >> wart;
			LJ.dodawanie_poczatek(wart); 
			cout << endl;
			system("cls");
			LJ.obecny_rozmiar();
			LJ.wyswietl();
			
			
			break;
		}

		case 'b':
		{
			cout << "Podaj wartosc ktora chcesz dodac: ";
			cin >> wart;
			LJ.dodawanie_koniec(wart); 
			cout << endl;
			system("cls");
			LJ.obecny_rozmiar();
			LJ.wyswietl();
			
			break;
		}

		case 'c':
		{
			LJ.odejmowanie_poczatek(); 
			cout << endl;
			system("cls");
			LJ.obecny_rozmiar();
			LJ.wyswietl();
			
			break;
		}

		case 'd':
		{
			LJ.odejmowanie_koniec(); 
			cout << endl;
			system("cls");
			LJ.obecny_rozmiar();
			LJ.wyswietl();
			
			break;
		}

		case 'e':
		{
			cout << "Podaj wartosc ktora chcesz dodac oraz pozycje na ktorej ma sie znalezc: ";
			cin >> wart >> index;
			LJ.dodawanie_dowolne(wart, index); 
			cout << endl;
			system("cls");
			LJ.obecny_rozmiar();
			LJ.wyswietl();
			
			break;
		}

		case 'f':
		{
			cout << "Podaj pozycje ktora ma zostac usunieta: ";
			cin >> index;
			LJ.odejmowanie_dowolne(index); 
			cout << endl;
			system("cls");
			LJ.obecny_rozmiar();
			LJ.wyswietl();
			
			break;
		}

		case 'g':
		{
			cout << "Zostanie wysolowana pozycja do wyszukania." << endl;;
			int szukana = LJ.wyszukaj_losowo(); 
			cout << szukana << endl;
			cout << endl;
			LJ.obecny_rozmiar();
			LJ.wyswietl();
			
			
			break;
		}

		default:

			break;
		}
	}



	case 3: // Obsługa opcji dla listy jednokierunkowej z głową i ogonem
	{
		cout << "Wybierz funkcje z ktorej chcesz skorzystac:" << endl << "[a] dodawanie elementu na poczatku" << endl
			<< "[b] dodawanie elementu na koncu" << endl << "[c] usuwanie elementu na poczatku" << endl
			<< "[d] usuwanie elementu na koncu" << endl << "[e] dodawanie elementu w wybranym miejscu" << endl
			<< "[f] usuwanie elementu z wybranego miejsca" << endl << "[g] wyszukanie elementu" << endl;
		cout << "Przechodze do funkcji: ";
		cin >> zmienna2;

		switch (zmienna2)
		{
		case 'a':
		{
			cout << "Podaj wartosc ktora chcesz dodac: ";
			cin >> wart;
			LJOG.dodawanie_poczatek(wart); 
			cout << endl;
			system("cls");
			LJOG.obecny_rozmiar();
			LJOG.wyswietl();
			
			break;
		}

		case 'b':
		{
			cout << "Podaj wartosc ktora chcesz dodac: ";
			cin >> wart;
			LJOG.dodawanie_koniec(wart); 
			cout << endl;
			system("cls");
			LJOG.obecny_rozmiar();
			LJOG.wyswietl();
			
			break;
		}

		case 'c':
		{
			LJOG.odejmowanie_poczatek(); 
			cout << endl;
			system("cls");
			LJOG.obecny_rozmiar();
			LJOG.wyswietl();
			
			break;
		}

		case 'd':
		{
			LJOG.odejmowanie_koniec(); 
			cout << endl;
			system("cls");
			LJOG.obecny_rozmiar();
			LJOG.wyswietl();
			
			break;
		}

		case 'e':
		{
			cout << "Podaj wartosc ktora chcesz dodac oraz pozycje na ktorej ma sie znalezc: ";
			cin >> wart >> index;
			LJOG.dodawanie_dowolne(wart, index); 
			cout << endl;
			system("cls");
			LJOG.obecny_rozmiar();
			LJOG.wyswietl();
			
			break;
		}

		case 'f':
		{
			cout << "Podaj pozycje ktora ma zostac usunieta: ";
			cin >> index;
			LJOG.odejmowanie_dowolne(index); 
			cout << endl;
			system("cls");
			LJOG.obecny_rozmiar();
			LJOG.wyswietl();
			
			break;
		}

		case 'g':
		{
			cout << "Zostanie wysolowana pozycja do wyszukania." << endl;
			int szukana = LJOG.wyszukaj_losowo(); 
			cout << szukana << endl;
			cout << endl;
			LJOG.obecny_rozmiar();
			LJOG.wyswietl();
			
			break;
		}

		default:

			break;
		}
	}


	case 4:
	{
		cout << "Wybierz funkcje z ktorej chcesz skorzystac:" << endl << "[a] dodawanie elementu na poczatku" << endl
			<< "[b] dodawanie elementu na koncu" << endl << "[c] usuwanie elementu na poczatku" << endl
			<< "[d] usuwanie elementu na koncu" << endl << "[e] dodawanie elementu w wybranym miejscu" << endl
			<< "[f] usuwanie elementu z wybranego miejsca" << endl << "[g] wyszukanie elementu" << endl;
		cout << "Przechodze do funkcji: ";
		cin >> zmienna2;

		switch (zmienna2)
		{
		case 'a':
		{
			cout << "Podaj wartosc ktora chcesz dodac: ";
			cin >> wart;
			L1.dodawanie_poczatek(wart);
			cout << endl;
			system("cls");
			L1.obecny_rozmiar();
			L1.wyswietl();
			break;
		}

		case 'b':
		{
			cout << "Podaj wartosc ktora chcesz dodac: ";
			cin >> wart;
			L1.dodawanie_koniec(wart);
			cout << endl;
			system("cls");
			L1.obecny_rozmiar();
			L1.wyswietl();
			break;
		}

		case 'c':
		{
			L1.odejmowanie_poczatek();
			cout << endl;
			system("cls");
			L1.obecny_rozmiar();
			L1.wyswietl();
			break;
		}

		case 'd':
		{
			L1.odejmowanie_koniec();
			cout << endl;
			system("cls");
			L1.obecny_rozmiar();
			L1.wyswietl();
			break;
		}

		case 'e':
		{
			cout << "Podaj wartosc ktora chcesz dodac oraz pozycje na ktorej ma sie znalezc: ";
			cin >> wart >> index;
			L1.dodawanie_dowolne(wart, index);
			cout << endl;
			system("cls");
			L1.obecny_rozmiar();
			L1.wyswietl();
			break;
		}

		case 'f':
		{
			cout << "Podaj pozycje ktora ma zostac usunieta: ";
			cin >> index;
			L1.odejmowanie_dowolne(index);
			cout << endl;
			system("cls");
			L1.obecny_rozmiar();
			L1.wyswietl();
			break;
		}

		case 'g':
		{
			cout << "Zostanie wysolowana pozycja do wyszukania." << endl;;
			int szukana = L1.wyszukaj();
			cout << szukana << endl;
			cout << endl;
			L1.obecny_rozmiar();
			L1.wyswietl();
			break;
		}

		default:

			break;
		}
	}



	default:

		break;
	}

	//...............................................................................................





	//.......................................WYNIKI...................................................

	//	L1.wyczysc_liste();
	//	cout << "Czas wykonania: " << static_cast<double>(elapsed.count()) * 1e-9 << " sekund." << endl;

	//	TD.wyczysc_liste();
	//	cout << "Czas wykonania: " << static_cast<double>(elapsed.count()) * 1e-9 << " sekund." << endl;

	//	LJ.wyczysc_liste();
	//	cout << "Czas wykonania: " << static_cast<double>(elapsed.count()) * 1e-9 << " sekund." << endl;


	//	LJOG.wyczysc_liste();
	//	cout << "Czas wykonania: " << static_cast<double>(elapsed.count()) * 1e-9 << " sekund." << endl;


	return 0;
}
//...............................................................................................





