#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

char *Buff;
char **Nombre;
int i, n ;

Buff= (char *) malloc(100*sizeof(char));
Nombre=(char **)malloc(100*sizeof(char));

   printf("Ingrese el numero de nombres a ingresar ");
   scanf("%d",&n);
   fflush(stdin);

    for(i = 0; i < n; i++){

                             printf("Ingrese los nombres: ");
                             gets(Buff);
                             fflush(stdin);
                             Nombre[i]= (char *) malloc((strlen(Buff)+1)*sizeof(char));
                             strcpy(Nombre[i],Buff);
  
}

free(Buff);
printf("\n");
           for( int j=0; j < n; j++){
                        
                           printf("Nombre ingresado %d: ", j+1);
                           puts(Nombre[j]);

}
    return 0;

}