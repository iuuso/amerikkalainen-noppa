//-----------------Tiedosto main.c--------------------------------------------------
// Noppapelin main-tiedosto; pitää sisällään kokonaisuuden.
//
// Written by Juuso Karlström in 2013. All rights reserved

//Header-tiedostot
#include "asetukset.h"
#include "apufunktiot.h"
#include "noppa.h"

//------------------MAIN----------------------------------------

int main ( void ) 
{

//------------------MUUTTUJAT-----------------------------------

	signed int valinta;
	signed int tulos;
	double luku2;
	int buffer;

	Tervehdys();

	do
	{
		Valikko();

		valinta = Validaattori();
				
		switch (valinta)
		{
			case 1:
//------------------------------PELAA------------------------------
				Noppa();
				break;

			case 2:
//------------------------------OHJEET----------------------------
				Ohjeet();
				break;

			case 0:
//------------------------------POISTU-----------------------------
				printf(" \n Kiitos ja hei!\n");
				break;
			default:
				printf("\n Virhe - Syötetty numero on liian iso, kokeile uudestaan \n ");
				break;
		}

		
	}while ( valinta != 0);

	return 0;
}



