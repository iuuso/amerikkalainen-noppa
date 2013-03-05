#include "noppa.h"
#include "asetukset.h"
#include "apufunktiot.h"

//-----------------Tiedosto noppa.h------------------------------------------------------
// Sisältää varsinaisen pelin toteutuksen.

//------------------FUNKTIOT-------------------------------------------------------------

void Noppa()								// Noppa-peli
{

//------------------MUUTTUJAT-------------------------------------------------------------

	int saldo = 10;							// Pelitilin saldo
	unsigned int panos;						// Pelaajan antama panostus
	int tulos;								// Noppien yhteenlaskettu tulos
	int voitto;								// Voiton suuruus
	int tilanne = 2;						// Tarkkailija tilanteelle ( 1 = saldo on muutttunut )
	int buffer;								// Puskurin tyhjennuksen avustusmuuttuja

//------------------TERVEHDYS-----------------------------------------------------------

	printf("\n");
	Tahdet();
	printf(BOLDGREEN " HEITETÄÄN NOPPAA!\n" RESET);

//------------------PANOKSEN ASETTAMINEN JA VALIDOINTI------------------------------------

	do
	{
		loop: ;		
		printf( BOLDCYAN "\n *** Saldo =  %d ***\n Aseta panos ( 1-%d ) > " RESET, saldo, saldo);
		panos = Validaattori();

		//while ((buffer = getchar()) != EOF && buffer != '\n') ; // Tyhjennetään puskuri

		if ( panos > saldo )
		{
			printf( BOLDRED " Et voi antaa noin isoa panosta! Panoksen oltava %d tai alle sen.\n" RESET , saldo);
			goto loop; }
		//------------------------------OHJEET----------------------------} 
		else if ( panos == 0 )
		{
			printf( BOLDRED " Et voi antaa noin pientä panosta. Panoksen oltava isompi kuin 0.\n" RESET ); 
			printf( RESET);
			goto loop;
		}

		saldo = saldo - panos;		// Vähennetään panos saldosta oikean tuloksen saamiseksi

//------------------VARSINAINEN NOPAN HEITTO------------------------------

		do
		{

			// Suoritetaan heitto
			srand ( time(NULL) );
			tulos = rand() % 12 + 2;

			switch ( tulos )
			{

				case 11: case 7:
//--------------------------------------VOITTO----------------------------			
					saldo = saldo + panos * 2;
					voitto = panos * 2;

					printf( BOLDGREEN );
					printf("\n Heittotulos : %d\n", tulos);
					printf(" >> Voitto! Voitit %d euroa !\n\n", voitto);
					printf( RESET );

					tilanne = 1; //Saldo muuttuu, poistutaan kierrokselta
					if ( saldo > 0 ) {
						Jatko(&saldo);
					}
					else if ( saldo == 0 ) {
						printf( BOLDYELLOW "\n Saldo = %d euroa, hävisit pelin.\n\n" RESET, saldo);
					}

					break;
				case 2: case 3: case 12:
//--------------------------------------HÄVIÖ------------------------------
					printf( BOLDMAGENTA );			
					printf("\n Heittotulos : %d\n", tulos);
					printf(" >> Aijjai, takkiin tuli. Hävisit panostuksesi. :(\n\n");
					printf( RESET );

					// Tarkistetaan onko tilillä rahaa, ja katsotaan voidaanko peliä jatkaa
					if ( saldo > 0 ) {
						Jatko(&saldo);
					}
					else if ( saldo == 0 ) {
						printf( BOLDYELLOW "\n Saldo = %d euroa, hävisit pelin.\n\n" RESET, saldo);
					}
					
					tilanne = 1;
					break;
				default:
//--------------------------------------EI OSUMAA---------------------------
					printf( BOLDWHITE );
					printf("\n Heittotulos : %d\n", tulos);
					printf(" >> Ei osumaa. ");
					printf("Paina [ENTER] heittääksesi uudelleen. ");
					printf( RESET );

					while(getchar() != '\n'); // Tyhjä looppi, poimitaan enter

					tilanne = 2;
					break;

			}
		} while ( tilanne != 1 );
	
	} while (saldo > 0);
//	printf( BOLDYELLOW "\n Saldo = %d euroa, hävisit pelin.\n\n" RESET, saldo); // Tilin saldo nolla, peli lopetetaan.
}

//----------------------APUFUNKTIOT-----------------------------------------

void Jatko( int *saldo ) 
{
	char jatko;
	printf( BOLDYELLOW "\n Haluatko jatkaa pelaamista? (K/e) > " RESET);

	// Tähänkin pitäisi laittaa input-validaattori

	scanf("%c", &jatko);
	jatko = toupper(jatko);

		if ( jatko == 'K' ) {
			//*saldo = 2;
		} 
		else {
			printf( BOLDCYAN );
			printf(" Kiitos pelaamisesta!\n");
			printf(" Saldosi oli %d\n", *saldo);
			*saldo = 0;
			printf( RESET );
		}
		
}