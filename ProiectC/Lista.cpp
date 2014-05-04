#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <ctype.h>


#include "Lista.h"
#include "NodLista.h"

//////////////////////////////////////
//          constructor
//////////////////////////////////////

Lista::Lista()
{
	first = NULL;
	last  = NULL;
}

//////////////////////////////////////
//           cautare
//////////////////////////////////////

int Lista::Cautare(char* cauta)
{
	NodLista *c = first;

	while (c!=last)
	{
		if (!strcmp(cauta, c->inf))
		{
			return 1;
		}

		c = c->urm;
	};

	if (first != NULL)
	{
		if (!strcmp(cauta, c->inf))
		{
			return 1;
		}
	}
	return 0;
}

//////////////////////////////////////
//            reuniune
//////////////////////////////////////

void Lista::Reuniune(Lista l)
{
	if (l.first != NULL)
	{
		NodLista *c = l.first;

		while (c!=l.last)
		{
			Introducere(c->inf);
			c = c->urm;
		};

		if (l.first != NULL)
		{
			Introducere(c->inf);
		}

		c = NULL;
	}
}

//////////////////////////////////////
//     introducere de nod nou
//////////////////////////////////////

void Lista::Introducere (char *strnou)
{
	int found = 0;
	NodLista *nod = new NodLista(strnou);

	if (first==NULL)
	{
		first = nod;
		last  = nod;

		found = 1;
	}
	else
	{
		NodLista *c=first, *d;
		do
		{
			if (strcmp(nod->inf, c->inf)<=0)
			{
				// introducere inaintea lui c

				if (c == first)
				{
					// introducere in capatul listei

					nod->urm = first;
					first->ant = nod;
					first = nod;
				}
				else
				{
					// introducem intre d si c

					d = c->ant;
					d->urm = nod;
					nod->ant = d;
					nod->urm = c;
					c->ant = nod;
				}

				found = 1;

				break;
			}
			else
			{
				if (c != last)
				{
					c = c->urm;
				}
			}
		} while (c != last);

		// adugam inainte de last

		if (!found)
		{
			if (strcmp(nod->inf, last->inf)<=0)
			{
				d = last->ant;
				d->urm = nod;
				nod->urm = last;
				nod->ant = d;
				last->ant = nod;
				found = 1;
			}
			else
			{
				// am parcurs intreaga lista, adaugam la sfarsit

				last->urm = nod;
				nod->ant = last;
				last = nod;
			}
		}
	}
}

//////////////////////////////////////
//            afisare
//////////////////////////////////////

void Lista::Afisare ()
{
	if (first != NULL)
	{
		NodLista *c = first;

		while (c!=last)
		{
			std::cout<<c->inf<<" ";
			c = c->urm;
		}

		std::cout<<last->inf;

		std::cout<<std::endl;
	}
	else
	{
		std::cout<<"Lista este goala."<<std::endl;
	}
}

//////////////////////////////////////
//      constructor de copiere
//////////////////////////////////////

Lista::Lista(Lista &l)
{
	NodLista *c = l.first;

	this->first = NULL;
	this->last  = NULL;

	while (c!=l.last)
	{
		this->Introducere(c->inf);
		c = c->urm;
	}

	if (l.first != NULL)
	{
		this->Introducere(c->inf);
	}

}

//////////////////////////////////////
//          operator=
//////////////////////////////////////

void Lista::operator= (Lista* l)
{
	NodLista *c = first;


	NodLista *d;

	while (c!=last)
	{
		d = c->urm;
		delete c;
		c = d;
	}

	if (first!=NULL)
	{
		delete c;
	}

	first = last = NULL;

	c = l->first;
	while (c!=l->last)
	{
		Introducere(c->inf);
	}

	if (l->first!=NULL)
	{
		Introducere(c->inf);
	}

}

//////////////////////////////////////
//          destructor
//////////////////////////////////////

Lista::~Lista ()
{
	NodLista *c = first, *d;

	if (first!=NULL)
	{

		while (c!=last)
		{
			d = c->urm;
			delete c;
			c = d;
		}

		delete c;
	}

	c = d = NULL;
	first = NULL;
	last  = NULL;

}