#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Product
{
public:
    Product()
    {

    }
    virtual ~Product()
    {

    }

    virtual void showProduct() = 0;
};


class ProductA : public Product
{
public:
    ProductA():Product()
    {

    }
    virtual ~ProductA()
    {

    }

    virtual void showProduct() 
    {
        cout << "Product A created" << endl;
    }
};

class ProductB : public Product
{
public:
    ProductB():Product()
    {

    }
    virtual ~ProductB()
    {

    }

    virtual void showProduct() 
    {
        cout << "Product B created" << endl;
    }
};


class ProductC : public Product
{
public:
    ProductC():Product()
    {

    }
    virtual ~ProductC()
    {

    }

    virtual void showProduct() 
    {
        cout << "Product C created" << endl;
    }
};


enum Product_Type 
 {
    Product_A = 0,
    Product_B,
    Product_C
};


class SimpleFactory
{
private:
    /* data */
public:
    SimpleFactory(/* args */);
    ~SimpleFactory();

    Product* create(Product_Type type)
    {
        switch (type)
        {
        case Product_A:
            return new ProductA();
            break;
        case Product_B:
            return new ProductB();
            break;
        case Product_C:
            return new ProductC();
            break;
        default:
            break;
        }

        return nullptr;
    }
};

SimpleFactory::SimpleFactory(/* args */)
{
}

SimpleFactory::~SimpleFactory()
{
}

int main()
{
    vector<Product*> lt;
    SimpleFactory factory;
    lt.push_back(factory.create(Product_A));
    lt.push_back(factory.create(Product_C));
    lt.push_back(factory.create(Product_B));

    for(auto p: lt)
        p->showProduct();

    return 0;
}