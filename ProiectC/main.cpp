#include <iostream>
//#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"
#include "NodLista.h"
#include <conio.h>
#include <ctype.h>


Lista* liste;
int n;

//////////////////////////////////////
//          diferenta
//////////////////////////////////////

Lista* Diferenta(Lista* inter)
{
	Lista *rz = new Lista;

	NodLista *c = inter->first;

	for (int i=0; i<n; i++)
	{
		c = liste[i].first;

		// parcurgem fiecare lista si verificam daca elementul curent
		// se gaseste in intersectie, daca nu, se adauga la `rz`

		while (c!=liste[i].last)
		{
			if (!inter->Cautare(c->inf))
			{
				rz->Introducere(c->inf);
			}

			c = c->urm;
		}

		// aceeasi conditie pentru ultimul element

		if (liste[i].first != NULL)
		{
			if (!inter->Cautare(c->inf))
			{
				rz->Introducere(c->inf);
			}
		}

	}

	return rz;
}

//////////////////////////////////////
//           intersectie
//////////////////////////////////////

Lista* Intersectie()
{
	int ok;

	Lista *rz = new Lista;

	// parcurgem prima lista si cautam elementele care se gasesc in toate
	// celelalte liste, un element care apartine intersectiei trebuie
	// sa se gaseasca in toate listele

	Lista a = liste[0];

	NodLista *c = a.first;

	while (c!=a.last)
	{
		ok = 1;

		for (int i=1; i<n; i++)
		{
			if (!liste[i].Cautare(c->inf))
			{
				// elementul nu a fost gasit -> nu apartine intersectiei

				ok = 0;
			}
		}

		if (ok)
		{
			rz->Introducere(c->inf);
		}

		c = c->urm;
	};

	// aceleasi operatii pentru ultimul element in cazul in care
	// lista nu este vida

	if (a.first != NULL)
	{
		ok = 1;

		for (int i=1; i<n; i++)
		{
			if (!liste[i].Cautare(c->inf))
			{
				ok = 0;
			}
		}

		if (ok)
		{
			rz->Introducere(c->inf);
		}

	}

	return rz;
}


//////////////////////////////////////
//             main
//////////////////////////////////////

void main()
{
	std::cout<<"Cate liste doriti sa folositi? ";
	std::cin>>n;

	liste = new Lista[n];

	int m;
	char temp[255];		// dimensiunea maxima a unui element am presupus 255 caractere

	for (int i=0; i<n; i++)
	{
		std::cout<<"Lista "<<i+1<<":"<<std::endl;

		std::cout<<"Nr elemente: ";
		std::cin>>m;
		for (int j=0; j<m; j++)
		{
			std::cout<<"Elementul "<<j+1<<": ";
			std::cin>>temp;
			liste[i].Introducere(temp);
		}

		std::cout<<"Lista: ";
		liste[i].Afisare();
		std::cout<<std::endl;
	}


	char opt;
	int go = 1;
	while (go)
	{
		std::cout<<std::endl;
		std::cout<<std::endl<<"----------------------------------------"<<std::endl;
		std::cout<<"1. Introducere element"<<std::endl;
		std::cout<<"2. Afisare liste"<<std::endl;
		std::cout<<"3. Reuniune"<<std::endl;
		std::cout<<"4. Intersectie"<<std::endl;
		std::cout<<"5. Diferenta"<<std::endl;

		std::cout<<"0. Iesire"<<std::endl;
		std::cout<<"----------------------------------------"<<std::endl;
		std::cout<<"Optiunea: "<<std::endl;
		opt = getch();

		std::cout<<std::endl<<std::endl;
		switch (opt)
		{
			case '1':
			{
				// introducere
				
				std::cout<<"Multimea unde doriti introducerea: ";
				std::cin>>m;

				if (m>n || m<1)
				{
					std::cout<<"Nu exista multimea dorita!";
				}
				else
				{
					std::cout<<"Introduceti valoarea: ";
					std::cin>>temp;
					liste[m-1].Introducere(temp);

					std::cout<<std::endl<<"Rezultat: ";
					liste[m-1].Afisare();
				}
			} break;
			case '2':
			{
				// afisarea
				
				std::cout<<std::endl;
				for (int i=0; i<n; i++)
				{
					std::cout<<"Lista "<<i+1<<": "<<std::endl;
					liste[i].Afisare();
				}
			} break;
			case '3':
			{
				// reuniunea
				
				Lista *rez = new Lista;

				for (int i=0; i<n; i++)
				{
					rez->Reuniune(liste[i]);
				}

				rez->Afisare();
				delete rez;
			} break;
			case '4':
			{
				// intersectia

				Lista *rez = new Lista;
				rez = Intersectie();

				rez->Afisare();
				delete rez;
			} break;

			case '5':
			{
				// diferenta

				Lista *dif, *inter = Intersectie();

				dif = Diferenta(inter);

				dif->Afisare();

				delete inter;
				delete dif;
			} break;

			case '0':
			{
				go = 0;
			} break;
		}
	}

}
