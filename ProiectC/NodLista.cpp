#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "NodLista.h"
#include <conio.h>
#include <ctype.h>


//////////////////////////////////////
//          constructor
//////////////////////////////////////

NodLista::NodLista()
{
	inf = new char[1];
	inf[0] = '\0';
	urm = NULL;
	ant = NULL;
}

//////////////////////////////////////
//          constructor
//////////////////////////////////////

NodLista::NodLista(char *string)
{
	int length = strlen(string);
	inf = new char[length+1];
	strcpy(inf, string);
	urm = NULL;
	ant = NULL;
}