#ifndef NCOMPL_H
#define NCOMPL_H

class ncompl
{
    public:
        ncompl();
        rcncompl(double repo,double arim, bool polrec);
        setc(double repo,double arim, bool polrec);
        setc(double repo,double arim, char rp);
        ncompl add(ncompl* outros);
        ncompl mult(ncompl* outros);
        ncompl elev(double outro);
        double getInfo(bool repo,bool more_arim);
        double getInfo(char rima);
        operator+=(ncompl outro);
        operator*=(ncompl outro);
        operator^=(double real);
        operator/=(ncompl outro);
        operator=(ncompl outro);
        fromDouble(double d);

    protected:
        double mod;
        double argu;
    private:

};

#endif // NCOMPL_H
