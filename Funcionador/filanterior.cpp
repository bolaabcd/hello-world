#include "filanterior.h"


filanterior::filanterior(bool *lista,int tam){
lis=lista;
tama=tam;
}
int filanterior::prox(){
int i;
for(i=0;i<tama;i++)
    if(lis[i]==true) {lis[i]=false;return i;}
return -1;
}
filanterior::reconstr(bool *lista,int tam){
lis=lista;
tama=tam;
}
