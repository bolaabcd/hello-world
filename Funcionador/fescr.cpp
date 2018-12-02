#include "fescr.h"
#include <iostream>
#include <string>
using namespace std;
fescr::fescr(string in):strb(in)
{
 int n,magic=1;

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
bool fescr::isfescr(std::string in){
    int magic=0,i;
for(i=0;i<in.length();i++)if(in[i]=='('){magic=1;break;}
for(i=0;i<in.length();i++){if(in[i]=='(')magic--;else if(in[i]==')')magic++;if(magic >1) return false;}
if(magic!=1) return false;
magic=0;
for(i=0;i<in.length();i++){if(in[i]==')'){magic=1;continue;}if(magic==1&&!(in[i]==','))return false;else magic=0;}


return true;
}
std::string fescr::getStrb(){return strb;}
//A(B(C,D,E),F(G(H,I),J(K,L,M)),N)
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
int fescr::getNarg(){return narg;}
int fescr::nfins(std::string in){
int i,n=0;
 for(i=0;i<in.length();i++)
    if(in[i]==')'||in[i]==',')n++;
return n;
}
int fescr::nfun(std::string in){
int i,n=0;
 for(i=0;i<in.length();i++)
    if(in[i]==')')n++;
return n;
}
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

std::string *fescr::getArgs(){
return args;
}
std::string fescr::getName(){
return nome;
}
int* fescr::ordenador(){

}
