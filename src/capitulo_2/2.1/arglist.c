#include <stdio.h>

int main(int argc, char* argv[]){

    printf("The name of this program is '%s'",argv[0]);
    printf("\nthis program was invoked with %d arguments\n",argc-1 );


    if( argc > 1){
        int i;
        printf("Those arguments are: \n");
        for (i=1;i<argc;++i){
            printf("'%s'\n",argv[i]);
        }
    } 
    return 0;
}