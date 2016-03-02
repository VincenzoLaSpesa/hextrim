//---------------------------------------------------------------------------

#pragma hdrstop
#include "Finder.h"

Finder::Finder(int* pattern,int lenpattern ){
this->stato=0;
this->pattern=pattern;
this->lenpattern=lenpattern;
backtrace = (int *)malloc(lenpattern*sizeof(int));
compilabacktrace();
}

Finder::~Finder(){free(backtrace);};

int Finder::setsource(char* source,int lensource){
    this->cursore=0;
    this->source=source;
    this->lensource=lensource;  
    return this->lensource;
};

inline void Finder::compilabacktrace(){
/**
Analizza le ridondanze interne al pattern e compila la tavola dei backtrace
**/
int a,b,c,len;
len=this->lenpattern;
bool flag;
backtrace[0]=0;
for(c=1;c<len;c++){// :-)
        backtrace[c]=0;
        for(a=1;a<c;a++){flag=true;
                for(b=0;b<a;b++)flag&=(pattern[c+b-a]==pattern[b]);
                if(flag)backtrace[c]=a;
        }
}
};

int Finder::find(int inizio){
cursore=inizio;
return findnext();
}

int Finder::findnext(){
int goal=this->lenpattern;int fine=lensource;
while(stato!=goal&&cursore<fine){
        if(pattern[stato]==source[cursore]){
                stato++;
                cursore++;
                }
                else{//                     se tutte le backtrace[stato]
                if(stato==0)cursore++;      //sono zero l'algoritmo si
                stato=backtrace[stato];     //riduce ad una ricerca sequenziale
        }
}
if(stato==goal)return cursore-goal+1;
return -1;
}

//---------------------------------------------------------------------------
#pragma package(smart_init) //old Borland stuff. 
