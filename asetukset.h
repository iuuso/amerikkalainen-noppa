#ifndef ASETUKSET_H_INCLUDED
#define ASETUKSET_H_INCLUDED

//------------------------------KIRJASTOT-----------------------

#include <stdio.h>
#include <fcntl.h>		// read()-funktio
#include <stdlib.h>		// srand()-funktio
#include <time.h>		// randomistamaan srandia
#include <ctype.h>

//------------------------------VÄRIMÄÄRITTELYT-----------------

#define RESET		"\033[0m"		// Normaali, alkuperäinen väri
#define BOLDRED		"\033[1m\033[31m"	// Punainen bold, varattu virheilmoituksille
#define BOLDGREEN	"\033[1m\033[32m"	// Vihreä bold, varattu voittoa varten
#define BOLDWHITE	"\033[1m\033[37m"	// Valkoinen bold
#define BOLDYELLOW	"\033[1m\033[33m"	// Keltainen bold, häviö
#define BOLDCYAN	"\033[1m\033[36m"	// 
#define BOLDMAGENTA	"\033[1m\033[35m"	// 

#endif
