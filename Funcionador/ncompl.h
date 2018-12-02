#ifndef NCOMPL_H
#define NCOMPL_H
//Números complexos!

class ncompl
{
    public:
        ncompl();//Só declara
        rcncompl(double repo,double arim, bool polrec);//Inicializa o garoto da forma ruim
        setc(double repo,double arim, bool polrec);//Seta o número da forma ruim
        setc(double repo,double arim, char rp);//Seta o número de forma boa
        ncompl add(ncompl* outros);//Soma
        ncompl mult(ncompl* outros);//Multiplica
        ncompl elev(double outro);//Eleva
        double getInfo(bool repo,bool more_arim);//Pega o número complexo de forma ruim
        double getInfo(char rima);//Pega o número complexo de forma boa
        operator+=(ncompl outro);//Soma
        operator*=(ncompl outro);//Multiplica
        operator^=(double real);//Eleva
        operator/=(ncompl outro);//Divide
        operator=(ncompl outro);//Seta
        fromDouble(double d);//Seta a partir de real

    protected:
        double mod;//Módulo
        double argu;//Argumento
    private:

};

#endif // NCOMPL_H
