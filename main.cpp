#define VERSION "0.2"
#define DEBUG true

#include "functions.h"
#include <cstdio>
#include <cstdlib>
//using namespace std;

int main(int argc, char *argv[])
{
    FILE *input,*output;

#if DEBUG==true
    printf("Debug Mode!\n");
    char* patternstr="414d4c45544f";//AMLETO
    input=fopen  ( "amleto.txt"  , "rb" );
    output=fopen  ( "output.hex"  , "wb" );
#else
    char* patternstr=argv[1];
    input =stdin;
    output =stdout;
    if(argc<2){
	fprintf(stderr, "%s: missing parameter\n", argv[0]);
	return -1;
	}
#endif
    if(output==NULL || input==NULL){
	fprintf(stderr, "%s: impossibile accedere agli stream\n", argv[0]);
	};

    char *buffer=(char*)malloc(BUFFER);//64k
    int patternlen=strlen(patternstr)/2;
    int* pattern=(int *)malloc(patternlen*sizeof(int));
    if (hextoary(patternstr,pattern)<0){
	fprintf(stderr, "%s: stringa esadecimale non valida\n", argv[0]);
	return -1;
	}

	hextrim(buffer,pattern,patternlen,input,output);

    fclose (input) ;
    fclose (output) ;
    free(pattern);
    free(buffer);
    return EXIT_SUCCESS;
};


