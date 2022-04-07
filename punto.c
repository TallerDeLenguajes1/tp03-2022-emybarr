#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    char *Buff;

    Buff =(char*) malloc(100*sizeof(char));
    printf("ingrese una frase");
    gets(Buff);
    //  printf("%s", Buff);
    puts(Buff);
    free(Buff);

    return 0 ;
 
}