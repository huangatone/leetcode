#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class ProductBaseA
{
public:
    ProductBaseA()
    {

    }
    virtual ~ProductBaseA()
    {

    }

    virtual void showProduct() = 0;
};


class ProductA1 : public ProductBaseA
{
public:
    ProductA1():ProductBaseA()
    {

    }
    virtual ~ProductA1()
    {

    }

    virtual void showProduct() 
    {
        cout << "Product A1 created" << endl;
    }
};

class ProductA2 : public ProductBaseA
{
public:
    ProductA2():ProductBaseA()
    {

    }
    virtual ~ProductA2()
    {

    }

    virtual void showProduct() 
    {
        cout << "Product A2 created" << endl;
    }
};


class ProductA3 : public ProductBaseA
{
public:
    ProductA3():ProductBaseA()
    {

    }
    virtual ~ProductA3()
    {

    }

    virtual void showProduct() 
    {
        cout << "Product A3 created" << endl;
    }
};
//type 2
class ProductBaseB
{
public:
    ProductBaseB()
    {

    }
    virtual ~ProductBaseB()
    {

    }

    virtual void showProduct() = 0;
};


class ProductB1 : public ProductBaseB
{
public:
    ProductB1():ProductBaseB()
    {

    }
    virtual ~ProductB1()
    {

    }

    virtual void showProduct() 
    {
        cout << "Product B1 created" << endl;
    }
};

class ProductB2 : public ProductBaseB
{
public:
    ProductB2():ProductBaseB()
    {

    }
    virtual ~ProductB2()
    {

    }

    virtual void showProduct() 
    {
        cout << "Product B2 created" << endl;
    }
};


class ProductB3 : public ProductBaseB
{
public:
    ProductB3():ProductBaseB()
    {

    }
    virtual ~ProductB3()
    {

    }

    virtual void showProduct() 
    {
        cout << "Product B3 created" << endl;
    }
};

template<class A,class B>
class AbstractFactory
{
public:
    AbstractFactory()
    {
        _a = nullptr;
        _b = nullptr;
    }
    ~AbstractFactory()
    {

    }
    void create()
    {
        if (_a)
            delete _a;
        if (_b)
            delete _b;
        _a = new A();
        _b = new B();
    }

    A* getProductA()
    {
        return _a;
    }

    B* getProductB()
    {
        return _b;
    }

private:
    A* _a;
    B* _b;
};



int main()
{
    AbstractFactory<ProductA1,ProductB1> a1b1;
    AbstractFactory<ProductA2,ProductB2> a2b2;
    AbstractFactory<ProductA3,ProductB3> a3b3;
    

    a1b1.create();
    a1b1.getProductA()->showProduct();
    a1b1.getProductB()->showProduct();
    return 0;
}