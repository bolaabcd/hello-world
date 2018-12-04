#include "func.h"
#include "ncompl.h"
#include "fescr.h"
#include "pstr.h"
#include "filanterior.h"
#include <string>
#include <math.h>
#include <iostream>
#include <cstdlib>
using namespace std;

//Construtor que coloca nome
func::func(string nome):name(nome){}

//Construtor q n faz nada
func::func(){}

//Setar o bool q eu não sei pra q existe
func::setVai(bool b){podi=b;}

//Pegar as entradas
ncompl* func::getIns(){return ins;}

//Pegar o bool q eu não sei pra q existe
bool func::getPodi(){return podi;}

//Pegar o nome
std::string func::getName(){return name;}

//Pegar a saída
ncompl func::getOut(){return *out;}

//Pegar a hierarquia da função
int func::getHie(){return hie;}

//Pegar o número total de funções dentro da função
int func::getNins(){return nins;}

//Setar as entradas da função
func::setIns(ncompl*in){ins=in;}

//Setar a hierarquia da função
func::setHie(int hi){hie=hi;}

//Pegar um pedaço de array de números complexos, do array arrg, do pri ao ult.
ncompl* func::arrfromto(ncompl*arrg,int pri,int ult){
    int i;
    ncompl*ans=new ncompl[ult-pri+1];
    for(i=0;i<=ult-pri;i++)ans[i]=arrg[pri+i];
    return ans;
    }

//A função que faz a saída da função com base nas entradas!
func::Magic(){
    int i;
if(!name.compare("rec")){//Retangular, devolve um número complexo com base no x e y especificados
        if(nins!=2){cout<<"ERRO:Número de argumentos incorreto!"<<endl;exit(-1);}
        out->setc(ins[0].getInfo(true,true),ins[1].getInfo(true,true),false);
}
    
else if(!name.compare("pol")){//Polar, devolve um número complexo com base num argumento e num ângulo
    if(nins!=2){cout<<"ERRO:Número de argumentos incorreto!"<<endl;exit(-1);}
    out->setc(ins[0].getInfo(true,true),ins[1].getInfo(true,true),true);
}
    
else if(!name.compare("add")){//Soma todos os números complexos
    if(nins==0){cout<<"ERRO:Número de argumentos impossível!"<<endl;exit(-1);}
    int i;
    double ansr=0,ansi=0;
    for(i=0;i<nins;i++){
        ansr+=ins[i].getInfo(true,true);
        ansi+=ins[i].getInfo(true,false);
    }
    out->setc(ansr,ansi,false);
}
    
else if(!name.compare("sub")){//Subrai todos do primeiro
    if(nins==1||nins==0){cout<<"ERRO:Número de argumentos impossível!"<<endl;exit(-1);}
    int i;
    double ansr=ins[0].getInfo('r'),ansi=ins[0].getInfo('i');
    for(i=1;i<nins;i++){
        ansr-=ins[i].getInfo('r');
        ansi-=ins[i].getInfo('i');
    }
    out->setc(ansr,ansi,false);
}
    
else if(!name.compare("mult")){//Multiplica todos os números
    if(nins==0){cout<<"ERRO:Número de argumentos impossível!"<<endl;exit(-1);}
    int i;
    double ansm=1,ansa=0;
    for(i=0;i<nins;i++){
        ansm*=ins[i].getInfo(false,true);
        ansa+=ins[i].getInfo(false,false);
    }
    out->setc(ansm,ansa,true);
}
    
else if(!name.compare("div")){//Divide o primeiro pelo segundo
    if(nins!=2){cout<<"ERRO:Número de argumentos incorreto!"<<endl;exit(-1);}
    out->setc(ins[0].getInfo('m')/ins[1].getInfo('m'),ins[0].getInfo('a')*180/M_PI-ins[1].getInfo('a')*180/M_PI,'p');
}
    
else if(!name.compare("ele")){//Eleva o número complexo pelo real
    if(nins!=2){cout<<"ERRO:Número de argumentos incorreto!"<<endl;exit(-1);}
    out->setc(pow(ins[0].getInfo('m'),ins[1].getInfo('r')),ins[0].getInfo('a')*180/M_PI*ins[1].getInfo('r'),'p');
}
    
else if(!name.compare("divt")){//Faz divisor de tensão com tensão, resistência que quer saber e outras resistências
    if(nins<3){cout<<"ERRO:Número de argumentos impossível para a função divt!"<<endl;exit(-1);}
int i;
ncompl ans;
ans.setc(1,1,'r');
for(i=1;i<nins;i++){
    ans+=ins[i];
}
ans^=-1;
ans*=ins[0];
ans*=ins[1];
out->setc(ans.getInfo('m'),ans.getInfo('a'),'p');
}
    
else if(!name.compare("divc")){//Faz divisor de corrente com corrente, resistência que quer saber e outras resistências

}
    
else if(!name.compare("ser")){//Soma os números todos
    if(nins==0){cout<<"ERRO:Número de argumentos impossível!"<<endl;exit(-1);}
    int i;
    ncompl x;
    x.setc(-1,-1,'r');
    for(i=0;i<nins;i++)
    x+=ins[i];
out->setc(x.getInfo('r')+1,x.getInfo('i')+1,'r');
}
    
else if(!name.compare("par")){//Faz um paralelo dos números todos
    if(nins==0){cout<<"ERRO:Número de argumentos impossível!"<<endl;exit(-1);}
    int i;
    ncompl x;
    ncompl arum;
    arum.setc(1,1,'r');
    x.setc(-1,-1,'r');
    for(i=0;i<nins;i++){
    ins[i]^=-1;
    x+=ins[i];}
    x+=arum;
    x^=-1;
    out->setc(x.getInfo('m'),x.getInfo('a'),'p');
}
    
else if(!name.compare("pol")){}
else if(!name.compare("pol")){}
    
else{cout<<"ERRO:Nome de função Inválido!";exit(-1);}
}

//Seta o nome
func::setName(std::string nome){
    name=nome;
}

//Faz a super conversão setando os valores de todas as funções e conectando suas saídas com a entrada das outras!
func::setvals(fescr main, int* hie, func* funcs, int gf,ncompl **listas, int ga, int ia,filanterior *f
              ){
int i;
(*hie)++;

cout<<"a"<<gf;
funcs[gf].ins=new ncompl[main.getNarg()];
funcs[gf].nins=main.getNarg();
funcs[gf].hie=*hie;
funcs[gf].name=main.getName();
funcs[gf].out=new ncompl[1];

for(i=0;i<main.getNarg();i++)
    if(!main.isfescr(main.getArgs()[i])){funcs[gf].ins[i].fromDouble(atof(main.getArgs()[i].c_str()));
    }
    else {funcs[gf].ins[i].fromDouble(-666);
    setvals(main.getArgs()[i],hie,funcs,(f->prox()),listas,gf,i,f);
    }
if(ia!=-1&&ga!=-1)funcs[gf].out=&funcs[ga].ins[ia];
(*hie)--;
}

//Converte a partir de uma fescr.
func::fromFescr(fescr main){
    bool *lista=new bool[main.nfins(main.getStrb())];
    int i,hi=0,d,ia=-1,ga=-1,maxhie=1;
    for(i=0;i<main.nfins(main.getStrb());i++)lista[i]=true;
    filanterior *f=new filanterior(lista,main.nfins(main.getStrb()));
    int *hie=&hi;
    ncompl **listas=new ncompl*[main.nfun(main.getStrb())];
    func*funcs=new func[main.nfun(main.getStrb())];
setvals(main,hie, funcs,f->prox(),listas,ga,ia,f);
out=funcs[0].out;
ins=new ncompl[main.getNarg()];
while(maxhie){
        maxhie=0;

for(i=0;i<main.nfun(main.getStrb());i++)
    if(funcs[i].hie>maxhie)maxhie=funcs[i].hie;

if(maxhie==0)break;

for(i=0;i<main.nfun(main.getStrb());i++)
    if(funcs[i].hie==maxhie){funcs[i].Magic();funcs[i].hie=0;}

}

for(i=0;i<main.nfun(main.getStrb());i++){
        cout<<funcs[i].getName()<<endl;
        cout<<funcs[i].getNins()<<endl;
        cout<<funcs[i].getHie()<<endl<<endl;
    for(d=0;d<funcs[i].getNins();d++)
    cout<<funcs[i].getIns()[d].getInfo(true,true)<<endl;
cout<<endl<<endl;
        }
system("pause>>NULL");
system("cls");
cout<<funcs[0].getOut().getInfo('m')<<endl<<funcs[0].getOut().getInfo('a')*180/M_PI;

}

//TESTES:
//A(B(10,18,245),F(G(-83,584),J(32,26,19)),31)
//add(add(rec(10,0),rec(18,0),rec(245,0)),add(add(rec(-83,0),rec(584,0)),add(rec(32,0),rec(26,0),rec(19,0))),rec(31,0))
//add(rec(1,2),rec(3,4))
//mult(rec(3,3),rec(3,3))
