#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

const char* program_name;

//Imprime informacion de uso para este programa en STREAM, tipicamente
//en stdout o stderr, y cierra el programa con exit_code. No retorna nada
void print_usage (FILE* stram, int exit_code){
    fprintf (stram, "Usage: %s options [ inputfile ...]\n", program_name);
    fprintf (stream, 
                " -h --help             Display this usage information.\n"
                " -o --output filename  Write output to file.\n"
                " -v --verbose          Print verbose messages.\n");
    exit (exit_code);
}

int main(int argc,char* argv[]){
    int next_option;
    //una cadena con las letras de opciones cortas validas
    const char* const short_opcions = "ho:v";
    //un array que describe las opciones largas validas
    const struct option long_options[] = {
        {"help",    0,  NULL,   'h'},
        {"output",  1,  NULL,   'o'},
        {"verbose", 0,  NULL,   'v'},
        {"NULL",    0,  NULL,   0}
    };
    //el nombre del archivo que recibira el output del programa, o null si es que es por el output estandar
    const char* output_filename = NULL;
    //si es que se imprimiran mensajes verbose
    int verbose = 0;

    //se guarda el nombre del programa
    program_name = argv[0];

    do{
        next_option=getopt_long(argc,argv,short_opcions,long_options,NULL);
        switch (next_option)
        {
        case 'h':
            //el usuario requirio informacion de uso. Imprime en la salida estandaar
            //y sale con el codigo de salida cero.
            print_usage(stdout, 0);
        case 'o':
            //esta opcion toma un argumento, el nombre del archivo de salida
            output_filename = optarg;
            break;
        case 'v':
            verbose = 1;
            break;
        case '?': //el usuario solicito una opcion no valida, se imprime en el salida de error estandar, y se sale con codigo de salida 1
            print_usage(stderr,1);
        case -1 //no mas opciones
            break;
        default:
            //algo inesperado
            abort();
        }
    }while(next_option != -1);

    if(verbose){
        int i;
        for(i = optind; i < argc ;++i)
            printf("Argument: %s\n", arg[i]);
    }
}