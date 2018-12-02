#include <iostream>
#include "fescr.h"
#include <cstdlib>
#include "func.h"
using namespace std;

int main()
{
    char op;
    do{
    int i=0;

    string in;
    system("cls");
    cout<<"Entre com a funcaum!"<<endl;
    cin>>in;
    fescr teste(in);
    while(!teste.isfescr(in)){
        system("cls");
        cout<<"Entrada invalida!";
        _sleep(500);
        system("cls");
        cout<<"Entre com a funcaum!"<<endl;
        cin>>in;
        teste.reconstr(in);
}
func testf(teste.getName());
teste.getInfo();
system("pause>>NULL");

system("cls");
testf.fromFescr(teste);
system("pause>>NULL");

system("cls");
cout<<"Digite 'r' se deseja repetir?"<<endl;
cin>>op;
    }while(op=='r');
    return 0;
}
//A(B(C,D,E),F(G(H,I),J(K,L,M)),N)
//A(B(10,18,245),F(G(-83,584),J(32,26,19)),31)
//A(3,B(17))
