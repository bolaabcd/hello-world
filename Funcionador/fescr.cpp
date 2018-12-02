#include "fescr.h"
#include <iostream>
#include <string>
using namespace std;
//Isso é uma string com partes selecionadas onde estão os argumentos e nomes da função. Deve ter como melhorar isso.

fescr::fescr(string in):strb(in)
{
 int n,magic=1;

//Setando posição do nome:
       pnome.ini=0;
       pnome.fin=strb.find('(')-1;

 //Setando número de vírgulas:
       nvirgs =0;
       for(n=0;n<strb.length();n++){
       if(strb[n]=='(') magic--;else if(strb[n]==')')magic++; else
       if(strb[n]==','&&magic==0)nvirgs ++;
       }

 //Setando número de argumentos:
       narg=nvirgs+1;

 //Criando arrays pras vírgulas argumentos e posição dos argumentos na string.
       virgs= new int[nvirgs];
       pargs= new pstr[narg+1];
       args= new string[narg];

 //Setando posição das vírgulas
       nvirgs=0;
       for(n=0;n<strb.length();n++){
       if(strb[n]=='(') magic--;else if(strb[n]==')')magic++; else
       if(strb[n]==','&&magic==0){
       virgs[nvirgs]=n;
       nvirgs ++;
       }
       }

 //Setando posição dos argumentos:
       for(n=0;n<narg;n++){
       pargs[0].ini=pnome.fin+2;
       pargs[narg-1].fin=strb.length()-2;
           if(n!=0)pargs[n].ini=virgs[n-1]+1;
           if(n!=narg-1)pargs[n].fin=virgs[n]-1;
       }
 
//Setando nome:
       nome=strb.substr(pnome.ini,pnome.fin-pnome.ini+1);

 //Setando argumentos:
       for(n=0;n<narg;n++){
args[n]=strb.substr(pargs[n].ini,pargs[n].fin-pargs[n].ini+1);
       }
}

//Imprime na tela os parâmetros. Seria legal ter um modo de obter os parâmetros e poder escolher que parâmetros imprimir.
fescr::getInfo(){
    int n;
cout<<narg<<endl<<nvirgs<<endl<<strb<<endl<<nome<<endl<<pnome.ini<<endl<<pnome.fin;
cout<<endl<<endl;
for(n=0;n<narg;n++)cout<<args[n]<<endl;
cout<<endl;
for(n=0;n<narg;n++)cout<<pargs[n].ini<<endl;
cout<<endl;
for(n=0;n<narg;n++)cout<<pargs[n].fin<<endl;
cout<<endl;
for(n=0;n<nvirgs;n++)cout<<virgs[n]<<endl;
cout<<endl;
    }

//Testa se é uma string válida para o programa.
bool fescr::isfescr(std::string in){
    int magic=0,i;
for(i=0;i<in.length();i++)if(in[i]=='('){magic=1;break;}
for(i=0;i<in.length();i++){if(in[i]=='(')magic--;else if(in[i]==')')magic++;if(magic >1) return false;}
if(magic!=1) return false;
magic=0;
for(i=0;i<in.length();i++){if(in[i]==')'){magic=1;continue;}if(magic==1&&!(in[i]==','))return false;else magic=0;}
return true;
}

//Pega a string base.
std::string fescr::getStrb(){return strb;}

//Reconstrói a fescr da mesma forma que o construtor.
fescr::reconstr(std::string in){
int n,magic=1;
strb=in;
       pnome.ini=0;
       pnome.fin=strb.find('(')-1;

       nvirgs =0;
       for(n=0;n<strb.length();n++){
       if(strb[n]=='(') magic--;else if(strb[n]==')')magic++; else
       if(strb[n]==','&&magic==0)nvirgs ++;
       }

       narg=nvirgs+1;

       virgs= new int[nvirgs];
       pargs= new pstr[narg+1];
       args= new string[narg];

       nvirgs=0;
       for(n=0;n<strb.length();n++){
       if(strb[n]=='(') magic--;else if(strb[n]==')')magic++; else
       if(strb[n]==','&&magic==0){
       virgs[nvirgs]=n;
       nvirgs ++;
       }
       }

       for(n=0;n<narg;n++){
       pargs[0].ini=pnome.fin+2;
       pargs[narg-1].fin=strb.length()-2;


           if(n!=0)pargs[n].ini=virgs[n-1]+1;
           if(n!=narg-1)pargs[n].fin=virgs[n]-1;
       }

       nome=strb.substr(pnome.ini,pnome.fin-pnome.ini+1);

       for(n=0;n<narg;n++){
args[n]=strb.substr(pargs[n].ini,pargs[n].fin-pargs[n].ini+1);
       }
}

//Pega o número de argumentos
int fescr::getNarg(){return narg;}

//Pega o número total de argumentos dentro da função e nas funções dentro dela
int fescr::nfins(std::string in){
int i,n=0;
 for(i=0;i<in.length();i++)
    if(in[i]==')'||in[i]==',')n++;
return n;
}

//Pega o número de funções dentro dela contando ela.
int fescr::nfun(std::string in){
int i,n=0;
 for(i=0;i<in.length();i++)
    if(in[i]==')')n++;
return n;
}

//Pega o número de níveis de hierarquia de função
int fescr::nhie(std::string in){
int i,n=1,ans=1;
 for(i=0;i<in.length();i++)
    if(in[i]=='('){
        n++;
        if(ans<n)ans=n;
    }
    else if(in[i]=='(')
        n--;
return ans;
}

//Pega a lista com os argumentos em forma de string.
std::string *fescr::getArgs(){
return args;
}

//Pega o nome em forma de string.
std::string fescr::getName(){
return nome;
}

//Aparentemente não faz absolutamente nada
int* fescr::ordenador(){

}
