#include <iostream>
#include "fescr.h"
#include <cstdlib>
#include "func.h"
using namespace std;
//Abridor de programa

int main()
{
    char op;
    do{
    
    //No final disso você tem a string base que define a função
    int i=0;
    string in;
    system("cls");
    cout<<"Entre com a funcaum!"<<endl;
    cin>>in;
    fescr teste(in);//Pra testar se é válido precisa transformar numa fescr primeiro... Desperdiça um poco aí em...
    while(!teste.isfescr(in)){
        system("cls");
        cout<<"Entrada invalida!";
        _sleep(500);
        system("cls");
        cout<<"Entre com a funcaum!"<<endl;
        cin>>in;
        teste.reconstr(in);
}
        
func testf(teste.getName());//Cria a função a partir da fescr, mas não constrói direto precisa do fromfescr...
teste.getInfo();//Imprime os parâmetros da Fescr pra ver se deu certo
system("pause>>NULL");

system("cls");
testf.fromFescr(teste);//Aqui que realmente constrói e já fala os parâmetros da função e no final o resultado.
//temq separar falar os parâmetros de construir e de falar o resultado final, separar essas coisas.
system("pause>>NULL");

system("cls");
cout<<"Digite 'r' se deseja repetir?"<<endl;//Repete basicamente
cin>>op;
    }while(op=='r');
    return 0;
}

//Para testar 1:Se está dividindo a string corretamente, 2:Se está pegando os valores corretamente
//A(B(C,D,E),F(G(H,I),J(K,L,M)),N)
//A(B(10,18,245),F(G(-83,584),J(32,26,19)),31)
