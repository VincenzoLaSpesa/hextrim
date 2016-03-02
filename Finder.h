//---------------------------------------------------------------------------
#ifndef FinderH
#define FinderH
#include <iostream>
#include <string>

//using namespace std;

class Finder{
public:
Finder(int* pattern,int lenpattern );
~Finder();
int clearstato(){return stato=0;};
int setsource(char* source,int lensource);
int find(int inizio=0);
int findnext();
private:
inline void compilabacktrace();
int cursore,lenpattern,lensource,stato;
int* backtrace;
char* source;
int* pattern;
};
//---------------------------------------------------------------------------
#endif
