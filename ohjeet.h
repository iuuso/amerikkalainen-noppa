/* Pitäisi saada jotenkin lukemaan tiedostosta ohjeet.txt ohjeet
   ja tulostamaan ne sitten käyttäjälle. Vai tekiskö vain printtiversion töstä?
    */


void Ohjeet()
{
    char buffer[256];
    FILE * myfile;
	
    myfile = fopen("ohjeet.txt","r");
	
    while (!feof(myfile))
    {
        fgets(buffer,256,myfile);
        printf("%s",buffer);
    }
	
    fclose(myfile);
}
