#include <string>
#include "pstr.h"
#ifndef FESCR_H
#define FESCR_H
//Isso é um tipo de objeto que tem uma string base e posições dos argumentos da string, talvez seja desnecessário.

class fescr
{
    public:
        fescr(std::string in);//Cria o objeto com base numa string e já seta as propriedades dele
        reconstr(std::string in);//seta as propriedades caso não tenha dado na primeira
        getInfo();//Imprime as propriedades na tela
        bool isfescr(std::string in);//Vê se a string é válida
        std::string getStrb();//Pega a string base
        std::string getName();//Pega o nome da função maior
        int nfun(std::string in);//Pega o número de funções da função maior
        int nfins(std::string in);//Pega o número total de funções
        int getNarg();//Pega o número de argumentos da função maior
        int nhie(std::string in);//Pega o número de níveis de hierarquia total
        std::string *getArgs();//Pega todos os argumentos
        int* ordenador();//Sei qq é isso não
    protected:

    private:
    int *virgs;//Posições das vírgulas
    int narg;//Número de argumentos
    int nvirgs ;//Número de vírgulas
    std::string *args;//Argumentos
    std::string strb;//String base
    std::string nome;//Nome da função total
    pstr *pargs;//Posição incial e final dos argumentos
    pstr pnome;//Posição inicial e final dos argumentos
};

#endif // FESCR_H
