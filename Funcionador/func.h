#ifndef FUNC_H
#define FUNC_H
#include <string>
#include "fescr.h"
#include "ncompl.h"
#include "filanterior.h"
class func
{
    public:
        func(std::string nome);
        func();
        setName(std::string nome);
        setVai(bool b);
        ncompl *getIns();
        bool getPodi();
        int getHie();
        int getNins();
        std::string getName();
        Magic();
        ncompl getOut();
        fromFescr(fescr main);
        setIns(ncompl *in);
        setHie(int hi);
        ncompl* arrfromto(ncompl*arrg,int pri,int ult);
    protected:

    private:
    setvals(fescr main, int *hie, func* funcs, int gf, ncompl **listas, int ga, int ia,filanterior *f
            );
    int hie;
    bool podi;
    std::string name;
    int nins;
    ncompl *ins;
    ncompl *out;
};

#endif // FUNC_H
