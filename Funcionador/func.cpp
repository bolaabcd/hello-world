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
func::func(string nome):name(nome){}
func::func(){}
func::setVai(bool b){podi=b;}
ncompl* func::getIns(){return ins;}
bool func::getPodi(){return podi;}
std::string func::getName(){return name;}
ncompl func::getOut(){return *out;}
int func::getHie(){return hie;}
int func::getNins(){return nins;}
func::setIns(ncompl*in){ins=in;}
func::setHie(int hi){hie=hi;}
ncompl* func::arrfromto(ncompl*arrg,int pri,int ult){
    int i;
    ncompl*ans=new ncompl[ult-pri+1];
    for(i=0;i<=ult-pri;i++)ans[i]=arrg[pri+i];
    return ans;
    }
func::Magic(){
    int i;
if(!name.compare("rec")){
        if(nins!=2){cout<<"ERRO:Número de argumentos incorreto!"<<endl;exit(-1);}
        out->setc(ins[0].getInfo(true,true),ins[1].getInfo(true,true),false);
//if(ins[0].getInfo(true,true)==-83&&ins[1].getInfo(true,true)==0)
//cout<<ins[0].getInfo(true,true)<<"    "<<ins[1].getInfo(true,true)<<"    "<<out->getInfo(true,true)<<"    "<<out->getInfo(true,false)<<endl;

}
else if(!name.compare("pol")){
    if(nins!=2){cout<<"ERRO:Número de argumentos incorreto!"<<endl;exit(-1);}
    out->setc(ins[0].getInfo(true,true),ins[1].getInfo(true,true),true);
}//pol(1.414213562373,45)
else if(!name.compare("add")){
    if(nins==0){cout<<"ERRO:Número de argumentos impossível!"<<endl;exit(-1);}
    int i;
    double ansr=0,ansi=0;
    for(i=0;i<nins;i++){
        ansr+=ins[i].getInfo(true,true);
        ansi+=ins[i].getInfo(true,false);
    }
    out->setc(ansr,ansi,false);

//cout<<ins[0].getInfo(true,true)<<"    "<<ins[1].getInfo(true,true)<<"    "<<out->getInfo(true,true)<<"    "<<out->getInfo(true,false)<<"    "<<ansr<<"     "<<ansi<<endl;

}
else if(!name.compare("sub")){
    if(nins==1||nins==0){cout<<"ERRO:Número de argumentos impossível!"<<endl;exit(-1);}
    int i;
    double ansr=ins[0].getInfo('r'),ansi=ins[0].getInfo('i');
    for(i=1;i<nins;i++){
        ansr-=ins[i].getInfo('r');
        ansi-=ins[i].getInfo('i');
    }
    out->setc(ansr,ansi,false);

}//sub(rec(3,4),rec(2,2));  sub(pol(1.414213562373,45),pol(1.414213562373,45),rec(2,-5));
else if(!name.compare("mult")){
    if(nins==0){cout<<"ERRO:Número de argumentos impossível!"<<endl;exit(-1);}
    int i;
    double ansm=1,ansa=0;
    for(i=0;i<nins;i++){
        ansm*=ins[i].getInfo(false,true);
        ansa+=ins[i].getInfo(false,false);
    }
    out->setc(ansm,ansa,true);
//cout<<endl<<endl<<ins[0].getInfo(false,false)<<"    "<<ins[1].getInfo(false,false)<<"    "<<ansa;
}
else if(!name.compare("div")){
    if(nins!=2){cout<<"ERRO:Número de argumentos incorreto!"<<endl;exit(-1);}
    out->setc(ins[0].getInfo('m')/ins[1].getInfo('m'),ins[0].getInfo('a')*180/M_PI-ins[1].getInfo('a')*180/M_PI,'p');
}//div(rec(3,4),pol(5,45))
else if(!name.compare("ele")){
    if(nins!=2){cout<<"ERRO:Número de argumentos incorreto!"<<endl;exit(-1);}
    out->setc(pow(ins[0].getInfo('m'),ins[1].getInfo('r')),ins[0].getInfo('a')*180/M_PI*ins[1].getInfo('r'),'p');
}//ele(rec(3,4),2)
else if(!name.compare("divt")){//tensão,res q quer a queda, outras res
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

}//divt(6,45,90)=2
else if(!name.compare("divc")){

}
else if(!name.compare("ser")){
    if(nins==0){cout<<"ERRO:Número de argumentos impossível!"<<endl;exit(-1);}
    int i;
    ncompl x;
    x.setc(-1,-1,'r');
    for(i=0;i<nins;i++)
    x+=ins[i];
out->setc(x.getInfo('r')+1,x.getInfo('i')+1,'r');
}//ser(rec(2,3),rec(3,4))
else if(!name.compare("par")){
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
}//par(rec(3,0),rec(0,4))
else if(!name.compare("pol")){}
else if(!name.compare("pol")){}
else{cout<<"ERRO:Nome de função Inválido!";exit(-1);}
}
func::setName(std::string nome){
    name=nome;
}
func::setvals(fescr main, int* hie, func* funcs, int gf,ncompl **listas, int ga, int ia,filanterior *f
              ){
int i;//l=número da lista
(*hie)++;

cout<<"a"<<gf;
funcs[gf].ins=new ncompl[main.getNarg()];
funcs[gf].nins=main.getNarg();
funcs[gf].hie=*hie;
funcs[gf].name=main.getName();
funcs[gf].out=new ncompl[1];

for(i=0;i<main.getNarg();i++)//g= número do in, i= número do argumento da função atual.
    if(!main.isfescr(main.getArgs()[i])){funcs[gf].ins[i].fromDouble(atof(main.getArgs()[i].c_str()));
    }
    else {funcs[gf].ins[i].fromDouble(-666);
    setvals(main.getArgs()[i],hie,funcs,(f->prox()),listas,gf,i,f);
    }
//funcs[gf].ins=listas[gf];add(add(rec(10,0),rec(18,0),rec(245,0)),add(add(rec(-83,0),rec(584,0)),add(rec(32,0),rec(26,0),rec(19,0))),rec(31,0))
if(ia!=-1&&ga!=-1)funcs[gf].out=&funcs[ga].ins[ia];
//cout<<"gf="<<gf<<"  ga="<<ga<<"  ia="<<ia<<"  funcs[ga].ins[ia]="<<funcs[ga].ins[ia].getInfo(true,true)<<endl;
(*hie)--;
}


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

//funcs[0].Magic();

//cout<<" AaSDASD ";
//add(rec(2,3),rec(3,2))

for(i=0;i<main.nfun(main.getStrb());i++){
        cout<<funcs[i].getName()<<endl;
        cout<<funcs[i].getNins()<<endl;
        cout<<funcs[i].getHie()<<endl<<endl;
    for(d=0;d<funcs[i].getNins();d++)
    cout<<funcs[i].getIns()[d].getInfo(true,true)<<endl;
    //cout<<funcs[i].out->getInfo(true,true)<<endl<<funcs[i].out->getInfo(true,false)<<endl<<endl;
cout<<endl<<endl;
        }
system("pause>>NULL");
system("cls");
cout<<funcs[0].getOut().getInfo('m')<<endl<<funcs[0].getOut().getInfo('a')*180/M_PI;

}
//A(B(10,18,245),F(G(-83,584),J(32,26,19)),31)
//add(add(rec(10,0),rec(18,0),rec(245,0)),add(add(rec(-83,0),rec(584,0)),add(rec(32,0),rec(26,0),rec(19,0))),rec(31,0))
//add(rec(1,2),rec(3,4))
//mult(rec(3,3),rec(3,3))
