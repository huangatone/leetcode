#include <stdio.h>
#include <iostream>

using namespace std;

class Tool
{
public:
    Tool ()
    {

    }
    virtual ~Tool()
    {

    }

    virtual void doWork() = 0;

};

class ToolStategy
{
public:
    ToolStategy(Tool* t)
    {
        _tool = t;
    }
    virtual ~ToolStategy()
    {

    }

    void work()
    {
        _tool->doWork();
    }
private:

    Tool* _tool;
};


class MouseTool : public Tool
{
public:
    MouseTool (){

    }
    ~MouseTool ()
    {

    }
    void doWork()
    {
        cout << "do work" << endl; 
    }
};
int main()
{
    ToolStategy ts(new MouseTool());
    ts.work();
    return 0;
}