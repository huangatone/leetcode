#include <stdio.h>
#include <iostream>
using namespace std;
#include <map>
#include <memory>
#include <list>
#include <algorithm>
#include <functional>
#include <vector>
enum colour 
 {
     Red, 
     Green, 
     Yellow
}; // Normally in header file
// struct apple
// {
//     float weight;
//     colour c; 
// };
struct
{
    float weight;
    colour c; 
} apple;

typedef struct Car
{
    int a;
} Car ,*car;

class TestCon
{
public:
    TestCon(string name,string job)
    {
        _name = new char[name.size()];
        strcpy(_name, name.data());
        _job = new string(job);
       
        _age =10;
        
    }

    TestCon(const TestCon& con)
    {
        _age = con.getAge();
        _name = new char[ strlen( con.getName())];
        strcpy(_name, con.getName());
        _job = new string(*con.getJob());
    }
    TestCon& operator =(const TestCon& con)
    {
        if(this == &con)
        {
            return *this;
        }
        delete [] _name;
        delete _job;
         _age = con.getAge();
        _name = new char[ strlen( con.getName())];
        strcpy(_name, con.getName());
        _job = new string(*con.getJob());
        return * this;
    }

    void print()
    {
        cout << "name:" << _name << endl;
        cout << "Job:" << *_job << endl;
        cout << "age:" << _age << endl;
    }

    int getAge() const
    {
        return _age;
    }
    const char* getName() const
    {
        return _name;
    }
    const string* getJob() const
    {
        return _job;
    }

    void setAge(int n)
    {
        _age = n;
    }
protected:


private:
    int _age;
    char* _name;
    string *_job;
};


void ss(int values[], int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i; j++)
        {
            if( values[j]< values[i])
                swap( values[i], values[j]);
           
            
        }
    }
}
struct Sample
{
    Sample(){}
    Sample(const Sample & obj)
    {
        std::cout<<"Sample copy constructor"<<std::endl;
    }
};
int main()
{
    Car aCar;
    car bCar;
    aCar.a = 10;
    bCar->a = 11;
    int a[] = {1,2,3,4,5};
    int *ptr = (int*)(a+1);
    cout << *(a+1) << "-- " << *(ptr-1);
    std::vector<Sample> vecOfInts;
 
    std::cout<<"Capacity :: "<<vecOfInts.capacity()<<std::endl;
    std::cout<<"Size :: "<<vecOfInts.size()<<std::endl;
    int capcity = vecOfInts.capacity();
    for(int i = 0; i < capcity + 1; i++)
        vecOfInts.push_back(Sample());
    
    std::cout<<"Capacity :: "<<vecOfInts.capacity()<<std::endl;
        std::cout<<"Size :: "<<vecOfInts.size()<<std::endl;
 
    for(int i = 0; i < capcity + 1; i++)
            vecOfInts.push_back(Sample());
 
    std::cout<<"Capacity :: "<<vecOfInts.capacity()<<std::endl;
    std::cout<<"Size :: "<<vecOfInts.size()<<std::endl;
 
    return 0;
}
int main123()
{
    TestCon com("bob","engneer");
    com.print();
    TestCon con1(com);
    con1.setAge(99);
    TestCon con2 = com;
    con2.setAge(100);
    con1.print();
    con2.print();
    // auto cm = [](auto a, auto b)
    // {
    //     return *a<*b;
    // };
    std::list<int> l= {1, 4, 3};
    l.sort();
    //sort(l.begin(), l.end());
    vector<int > lt = {1,25,8,5};
    swap(lt[0],lt[2]);


    int numLt[] = {10,8,5,7,3,12,9,7,10};
    ss(numLt, sizeof(numLt)/sizeof(int));

    for (auto i: numLt)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> ltVVV;
    int a1 =0;
    ltVVV.push_back(a1);
    cout << &a1 << " - " << &ltVVV[0] << endl;

    return 0;
}


int mapTest()
{
    map<int,int> _map;
    _map[100] = 10;
    _map[10] = 100;
    _map[20] = 0;
    for (auto it = _map.begin(); it != _map.end(); it++)
    {
        cout << it->first << " = " <<  it->second << endl;
    }
    for (auto it: _map)
        cout << it.first << " = " <<  it.second << endl;

        apple.weight = 10;


    int* a = new int(10);

   

    unique_ptr<int> p1(a); 

    *p1 = 19;
    cout << "p = " << *p1 << endl;

    auto od = make_shared<int>(55);
    auto pee = make_unique<int>(87);

shared_ptr<int> apppp(new int(99));
//weak_ptr<int> pp(new int(898));
//unique_ptr<int> p2 = p1;
//*p2 = 11;
   unique_ptr<int> arrr ;
   shared_ptr<int> b;
   weak_ptr<int> c;

   
   
    
    return 0;
}