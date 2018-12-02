#ifndef FILANTERIOR_H
#define FILANTERIOR_H

//Isso é uma lista de coisas que serve pra dizer se uma coisa já foi marcada na lista ou não
class filanterior
{
    public:
        filanterior(bool *lista,int tam);//Constrói a lista
        int prox();//Pega o próximo número não marcado
        reconstr(bool *lista,int tam);//Constrói a lista caso não tenha sido construída antes, só declarada.
    protected:

    private:
        bool *lis;//A lista mesmo
        int tama;//Número de coisas na lista
};

#endif // FILANTERIOR_H
