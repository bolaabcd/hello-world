#include <string>
#include "pstr.h"
#ifndef FESCR_H
#define FESCR_H


class fescr
{
    public:
        fescr(std::string in);
        reconstr(std::string in);
        getInfo();
        bool isfescr(std::string in);
        std::string getStrb();
        std::string getName();
        int nfun(std::string in);
        int nfins(std::string in);
        int getNarg();
        int nhie(std::string in);
        std::string *getArgs();
        int* ordenador();
    protected:

    private:
    int *virgs;
    int narg;
    int nvirgs ;
    std::string *args;
    std::string strb;
    std::string nome;
    pstr *pargs;
    pstr pnome;
};

#endif // FESCR_H
