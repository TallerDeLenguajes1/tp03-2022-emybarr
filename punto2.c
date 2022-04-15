#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

char *Buff;
char *Nombre[5];
int i ;

Buff= (char *) malloc(100*sizeof(char));
    for(i = 0; i < 5; i++){

                             printf("Ingrese sus nombres: ");
                             gets(Buff);
                             Nombre[i]= (char *) malloc((strlen(Buff)+1)*sizeof(char));
                             strcpy(Nombre[i],Buff);
  
}

free(Buff);

           for( int j=0; j < 5; j++){
                           puts(Nombre[j]);

}
    return 0;

}