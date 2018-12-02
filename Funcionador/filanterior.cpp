#include "filanterior.h"

//Só seta o que já tá pronto num objeto mais prático
filanterior::filanterior(bool *lista,int tam){
lis=lista;
tama=tam;
}

//Pega o próximo não marcado e marca ele. Deveria poder separar a parte de pegar e marcar, com um parâmetro opicinal.
//Tipo um MODO DE EXECUÇÃO DE FUNÇÃO. Modo teste, modo normal e modos especiais. COLOCAR NO PRÓPRIO ARQUIVO UMA LISTA
//DE MODOS ESPECiAIS DE ABRIR FUNÇÃO
int filanterior::prox(){
int i;
for(i=0;i<tama;i++)
    if(lis[i]==true) {lis[i]=false;return i;}
return -1;
}

//Reconstrói só
filanterior::reconstr(bool *lista,int tam){
lis=lista;
tama=tam;
}
