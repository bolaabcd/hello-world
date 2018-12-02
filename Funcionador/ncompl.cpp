#include "ncompl.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
ncompl::ncompl()//Construtor inútil
{
    //ctor
}

ncompl::operator/=(ncompl outro){//Divisão
mod/=outro.mod;
argu-=outro.argu;
}

ncompl::operator+=(ncompl outro){//Soma
double temp=mod;
mod=pow(pow(outro.mod*cos(outro.argu)+mod*cos(argu),2)+pow(outro.mod*sin(outro.argu)+mod*sin(argu),2),0.5);
argu=atan((outro.mod*sin(outro.argu)+temp*sin(argu))/(outro.mod*cos(outro.argu)+temp*cos(argu)));
}

ncompl::operator=(ncompl outro){//Setação
mod=outro.mod;
argu=outro.argu;
}

ncompl::operator*=(ncompl outro){//Tiplicação
mod*=outro.mod;
argu+=outro.argu;
}

ncompl::operator^=(double real){//Elevação
if(real!=0){
mod=pow(mod,real);
argu*=real;
} else {mod=1;argu=0;}
}

ncompl::fromDouble(double d){//Setação a partir de real
if(mod>=0){mod=d;argu=0;}
else{mod=-1*d,argu=M_PI;std::cout<<"afgbabaiefbafbkajsdf"<<std::endl<<std::endl;}
}

double ncompl::getInfo(bool repo,bool more_arim){//Pega o número complexo de forma ruim
if(repo){
    if(more_arim)
    return mod*cos(argu);
    else
    return mod*sin(argu);
} else{
    if(more_arim)
    return mod;
    else
    return argu;
}
}

double ncompl::getInfo(char rima){//Pega o número complexo de forma boa
switch(rima){
case 'r':
    return mod*cos(argu);
break;
case 'i':
    return mod*sin(argu);
break;
case 'm':
    return mod;
break;
case 'a':
    return argu;
break;
default:
std::cout<<"ERRO: Entrada GetInfo inválida!";
exit(-1);
}
}

ncompl::setc(double more,double arim,bool polrec){//Seta o número complexo de forma ruim
if(polrec){mod=more;argu=arim*M_PI/180;}
else{mod=pow(pow(more,2)+pow(arim,2),0.5);if(more>=0)argu=atan(arim/more);else if(atan(arim/more)<=0) argu=atan(arim/more)+M_PI;else argu=atan(arim/more)-M_PI;}
}

ncompl::setc(double repo,double arim, char rp){//Seta o número complexo de forma boa
if(rp=='p'){mod=repo;argu=arim*M_PI/180;}
else if(rp=='r'){mod=pow(pow(repo,2)+pow(arim,2),0.5);if(repo>=0)argu=atan(arim/repo);else if(atan(arim/repo)<=0) argu=atan(arim/repo)+M_PI;else argu=atan(arim/repo)-M_PI;}
else {std::cout<<"Entrada Inválida na função setc!";exit(-1);}
}
