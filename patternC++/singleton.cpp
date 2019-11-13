#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class SingleTon
{
public:
    static SingleTon* getInstance()
    {
        if(_instance == nullptr)
            _instance = new SingleTon();
        return _instance;
    }
    ~SingleTon()
    {
        cout << "Free single ton instance" << endl;
    }
private:
class freeSingleTon
{
    public:
    freeSingleTon(){}
    ~freeSingleTon()
    {
        if (_instance)
            delete _instance;
        std::cout<<"():Singleton Instance Deleted."<<std::endl;
    }  
    static freeSingleTon _freeInstance;
};

    static SingleTon* _instance;
    
    SingleTon()
    {

    }
    //note 1: to avoid copy construction function and = operator;
    SingleTon( const SingleTon& st);
    SingleTon & operator=(const SingleTon& st);


};


//eager mode, will new a SingleTon here. new a instance what ever it need or not
//lazy mode, initial as null and new when needed.
SingleTon* SingleTon::_instance = new SingleTon();
SingleTon::freeSingleTon SingleTon::freeSingleTon::_freeInstance ;
int main()
{
    SingleTon *pST = SingleTon::getInstance();
    SingleTon* pA = pST;
    //if no  note 1, the fellow statement are work and have 2 more SingleTon
    //SingleTon a = *pST;
    //SingleTon b(*pST);

    cout << pST <<endl << pA << endl ;
}
