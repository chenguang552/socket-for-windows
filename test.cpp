#include "sofile.h"
    int function(char charC,int intA,int intB){
        //test
        father *f = NULL;
        classA *a=new classA();
        classB *b=new classB();
        if(charC=='a'){
            f=a;
            cout<<"classA,10*" + to_string(intA) +"+"+ to_string(intB) +"=";
            return f->fun(intA,intB);
        }
        if(charC=='b'){
            f=b;
            cout<<"classB," + to_string(intA) +"+10*"+ to_string(intB) +"=";
            return f->fun(intA,intB);
        }
        return -1;
    }
// int main(){
//     father *f;
//     classA *a=new classA();
//     classB *b=new classB();
//     f=a;
//     f->fun(1,1);
//     f=b;
//     f->fun(1,1);
//     return 0;
// }