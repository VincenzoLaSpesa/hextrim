#define BUFFER (1024*64)*sizeof(char)
//possibilmente 64k è multiplo della dimensione di una pagina.
//così mi evito di usare getpagesize() che non è ANSI
#include <cstdlib>
#include <iostream>
#include <cstring>

int hextoary(char* hexstring,int* buffer);
void hextrim(char *buffer,int *pattern,int patternlen,FILE *input,FILE *output);
