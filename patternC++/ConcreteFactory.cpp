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
/*
template<class A,class B>
class ConcreteFacory
{
public:
    ConcreteFacory()
    {
        _a = nullptr;
        _b = nullptr;
    }
    ~ConcreteFacory()
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
*/



class ConcreteFacory
{
public:
    ConcreteFacory()
    {
        _a = nullptr;
        _b = nullptr;
    }
    ~ConcreteFacory()
    {

    }
    virtual void create() = 0;

    ProductBaseA* getProductA()
    {
        return _a;
    }

    ProductBaseB* getProductB()
    {
        return _b;
    }

protected:
    ProductBaseA* _a;
    ProductBaseB* _b;
};

class FactoryA1B1 : public ConcreteFacory
{
public:
    FactoryA1B1() : ConcreteFacory()
    {

    }
    ~FactoryA1B1()
    {

    }

    void create()
    {
        if (_a)
            delete _a;
        if (_b)
            delete _b;
        _a = new ProductA1();
        _b = new ProductB1();
    }
};

class FactoryA1B2 : public ConcreteFacory
{
public:
    FactoryA1B2() : ConcreteFacory()
    {

    }
    ~FactoryA1B2()
    {

    }

    void create()
    {
        if (_a)
            delete _a;
        if (_b)
            delete _b;
        _a = new ProductA1();
        _b = new ProductB2();
    }
};



class FactoryA1B3 : public ConcreteFacory
{
public:
    FactoryA1B3() : ConcreteFacory()
    {

    }
    ~FactoryA1B3()
    {

    }

    void create()
    {
        if (_a)
            delete _a;
        if (_b)
            delete _b;
        _a = new ProductA1();
        _b = new ProductB3();
    }
};
//A2

class FactoryA2B1 : public ConcreteFacory
{
public:
    FactoryA2B1() : ConcreteFacory()
    {

    }
    ~FactoryA2B1()
    {

    }

    void create()
    {
        if (_a)
            delete _a;
        if (_b)
            delete _b;
        _a = new ProductA2();
        _b = new ProductB1();
    }
};

class FactoryA2B2 : public ConcreteFacory
{
public:
    FactoryA2B2() : ConcreteFacory()
    {

    }
    ~FactoryA2B2()
    {

    }

    void create()
    {
        if (_a)
            delete _a;
        if (_b)
            delete _b;
        _a = new ProductA2();
        _b = new ProductB2();
    }
};



class FactoryA2B3 : public ConcreteFacory
{
public:
    FactoryA2B3() : ConcreteFacory()
    {

    }
    ~FactoryA2B3()
    {

    }

    void create()
    {
        if (_a)
            delete _a;
        if (_b)
            delete _b;
        _a = new ProductA2();
        _b = new ProductB3();
    }
};

//a3

class FactoryA3B1 : public ConcreteFacory
{
public:
    FactoryA3B1() : ConcreteFacory()
    {

    }
    ~FactoryA3B1()
    {

    }

    void create()
    {
        if (_a)
            delete _a;
        if (_b)
            delete _b;
        _a = new ProductA3();
        _b = new ProductB1();
    }
};

class FactoryA3B2 : public ConcreteFacory
{
public:
    FactoryA3B2() : ConcreteFacory()
    {

    }
    ~FactoryA3B2()
    {

    }

    void create()
    {
        if (_a)
            delete _a;
        if (_b)
            delete _b;
        _a = new ProductA3();
        _b = new ProductB2();
    }
};



class FactoryA3B3 : public ConcreteFacory
{
public:
    FactoryA3B3() : ConcreteFacory()
    {

    }
    ~FactoryA3B3()
    {

    }

    void create()
    {
        if (_a)
            delete _a;
        if (_b)
            delete _b;
        _a = new ProductA3();
        _b = new ProductB3();
    }
};


int main()
{
    vector<ConcreteFacory*> lt;
    lt.push_back( new FactoryA1B1());
    lt.push_back( new FactoryA1B2());
    lt.push_back( new FactoryA1B3());
   
    lt.push_back( new FactoryA2B1());
    lt.push_back( new FactoryA2B2());
    lt.push_back( new FactoryA2B3());

    lt.push_back( new FactoryA3B1());
    lt.push_back( new FactoryA3B2());
    lt.push_back( new FactoryA3B3());

    for(auto f:lt)
    {
        f->create();
        if (f->getProductA())
            f->getProductA()->showProduct();
        if (f->getProductB())
            f->getProductB()->showProduct();
    }


    return 0;
}