#ifndef FUNC_H
#define FUNC_H
#include <string>
#include "fescr.h"
#include "ncompl.h"
#include "filanterior.h"
//Essa é a verdadeira função. 

class func
{
    public:
        func(std::string nome);//Cria a partir de uma string
        func();//Só pra declarar msm
        setName(std::string nome);//Seta o nome da função
        setVai(bool b);//Seta esse bool que eu não lembro pra que usei
        ncompl *getIns();//Pega as entradas da função
        bool getPodi();//pega o bool que eu não lembro pra que usei
        int getHie();//Pega a hierarquia da função
        int getNins();//Pega o número de entradas da função
        std::string getName();//Pega o nome da função
        Magic();//Faz a função e seta o resultado
        ncompl getOut();//Pega o resultado
        fromFescr(fescr main);//Converte a partir de uma fescr
        setIns(ncompl *in);//Seta as entradas
        setHie(int hi);//Seta a hierarquia
        ncompl* arrfromto(ncompl*arrg,int pri,int ult);//Pega um pedaço de array de números complexos. Dá pra melhorar isso.
    protected:

    private:
    setvals(fescr main, int *hie, func* funcs, int gf, ncompl **listas, int ga, int ia,filanterior *f);//Seta as entradas
    //complicadamente sinceramente
    int hie;//Hierarquia
    bool podi;//Bool que eu não sei pq existe
    std::string name;//Nome
    int nins;//Número de entradas
    ncompl *ins;//Entradas
    ncompl *out;//Saída
};

#endif // FUNC_H
