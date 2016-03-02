#include "functions.h"
#include "Finder.h"
#include <cstdio>

inline int hexchar(char carattere){
    if(carattere=='0')return 0;
    if(carattere=='1')return 1;
    if(carattere=='2')return 2;
    if(carattere=='3')return 3;
    if(carattere=='4')return 4;
    if(carattere=='5')return 5;
    if(carattere=='6')return 6;
    if(carattere=='7')return 7;
    if(carattere=='8')return 8;
    if(carattere=='9')return 9;
    if(carattere=='A' || carattere=='a')return 10;
    if(carattere=='B' || carattere=='b')return 11;
    if(carattere=='C' || carattere=='c')return 12;
    if(carattere=='D' || carattere=='d')return 13;
    if(carattere=='E' || carattere=='e')return 14;
    if(carattere=='F' || carattere=='f')return 15;
    return -100;
};

int hextoary(char* hexstring,int* buffer){
    int len=strlen(hexstring);

    for(int a=0;a<len;a=a+2){
        buffer[a/2]=hexchar(hexstring[a])*16+hexchar(hexstring[a+1]);
	if (buffer[a/2]<0) return -1;
    }
    return 1;
};

void hextrim(char *buffer,int *pattern,int patternlen,FILE *input,FILE *output){
	Finder finder(pattern,patternlen);
	char *buffer2;
	int pos,len;
	do {//cicla i buffer
	len = fread (buffer , 1 , BUFFER , input );
	if( len ){
		buffer2=buffer;
		pos=0;
		do{//cicla le occorenze dentro il buffer
		//printf("A");
		buffer2+=pos;
		len-=pos;
		finder.setsource(buffer2,len);
		pos=finder.find(0);
		if(pos>0){//scrivo la parte precedente l'occorrenza
			//printf("B");
			fwrite (buffer2 , pos-1 , 1 , output );
			pos+=patternlen-1;
			finder.clearstato();
		}else{//scrivo tutto ciò che resta del buffer
			//printf("C");
			fwrite (buffer2 , len , 1 , output );
		}
			fflush(output);
		}while( pos>0);
	}
	}while ( len ) ;
};
