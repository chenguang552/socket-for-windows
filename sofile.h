#include <iostream>
#include <string>
using namespace std;
class father{
    public:
        virtual int fun(int,int)=0;
};
class classA:public father
{
    virtual int fun(int a,int b){
        // int c=a+b;
        // cout<<"classA "+to_string(c)<<endl;
        return 10*a+b;
    }

};
class classB:public father
{
    virtual int fun(int a,int b){
        // int c=a+b;
        // cout<<"classB "+to_string(c)<<endl;
        return a+10*b;
    }

};
int function(char charC,int intA,int intB);