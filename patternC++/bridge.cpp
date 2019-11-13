#include <stdio.h>
#include <iostream>
using namespace std;
#include <map>
#include <memory>
#include <list>
#include <algorithm>
#include <functional>
#include <vector>

// Implementor角色，数据采集器
 class DatacCollector 
 {
public:
    // 采集数据
    virtual void collect()=0;
};

//Concrete Implementor角色，数据库数据采集器
 class DbDataCollector :public DatacCollector 
 {

public:
     void collect() {
        cout << "我是数据库数据采集器，负责采集DB中的数据。" << endl;
     }
};
//Concrete Implementor角色，csv数据采集器
class CsvDataCollector :public DatacCollector {

    public:
     void collect() {
        cout << "我是CSV数据采集器，负责采集CSV数据。"<< endl;
    }
};


// Abstraction 角色， 抽象报表
class AbstractReport {
public:
    // 数据采集器
    DatacCollector* datacCollector;

     void setDatacCollector(DatacCollector* coll) 
     {
        datacCollector = coll;
    }

    // 报表显示
    virtual void view()=0;
};
// Refined Abstraction角色，扩充了抽象类，调用在DataCollector中定义的业务方法。
 class SheetReport: public AbstractReport {

     void view() {
        datacCollector->collect();// 调用采集数据方法
       cout << "以表格的形式显示报表。" << endl;
    }
};

// Refined Abstraction角色，扩充了抽象类，调用在DataCollector中定义的业务方法。
 class ChartReport :public AbstractReport {

   
    public:
     void view() {
        datacCollector->collect(); // 调用采集数据方法
        cout << "以图形的方式展现报表"<< endl;
    }
};


int main()
{
     AbstractReport* report = new ChartReport();
    DatacCollector* datacCollector = new DbDataCollector();
    report->setDatacCollector(datacCollector);
    report->view();
    return 0;
}