//#include "main.c"
#include "asetukset.h"
#include "apufunktiot.h"
#include "noppa.h"

//--------------------------TULOSTAA RIVILLISEN TÄHTIÄ-----------
void Tahdet()
{
	int tahti;
	int maara = 50;

	for ( tahti = 1; tahti <= maara; tahti++)
		putchar('*');
		putchar('\n');
}

//----------------------------ALKUTERVEHDYS-----------------------
void Tervehdys()
{
	Tahdet();
	printf("\tAMERIKKALAINEN NOPPA\n");
	Tahdet();
}

//---------------------------INPUT VALIDAATTORI-------------------
int Validaattori( void )
{
	int luku=0;
	int palautus=0;
	int buffer;
	char merkki = ' ';
 		while( (luku=scanf("%d%c", &palautus, &merkki) == 0 || ( luku == 2 && merkki != '\n')))
		{
   		   while ((buffer = getchar()) != EOF && buffer != '\n') ; // Tyhjennetään puskuri

		   printf( BOLDRED );
   		   printf("\n Virhe - Väärä syöte, kokeile uudestaan > ");
		   printf( RESET );
 		}
	return palautus;
}

//------------------------------ALKUVALIKKO-------------------------
void Valikko()
{
	printf( BOLDWHITE );
	printf("\n PÄÄVALIKKO \n");
	printf("\n 1) Pelaa\n");
	printf(" 2) Ohjeet\n");
	printf(" 0) Poistu\n");
	printf("\n Anna valinta > ");
	printf( RESET );
}

//---------------------------OHJEET JA PELIN SÄÄNNÖT-----------------
void Ohjeet()
{
    char buffer[256];
    char line[80];
    FILE * myfile;
	
    myfile = fopen("ohjeet.txt","rt");
	
    while (!feof(myfile))
    {
    while(fgets(line, 80, myfile) != NULL)
    {
        fgets(buffer,256,myfile);
        printf("%s",buffer);
    }
	}
    fclose(myfile);
}
