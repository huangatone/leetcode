#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    //字符串转换为数字
    istringstream iss("3.14");
    double pi;
    if(iss >> pi)
    {
        cout << "PI = " << pi<< endl;
    }
    //数字转换为字符串
    ostringstream oss;
    if(oss << pi)
    {
        string PI = oss.str();
        cout << "PI = " << PI << endl;
    }

    return 0;
}