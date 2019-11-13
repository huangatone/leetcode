#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std; 
#include <vector>
#include <stack>

template<class T>
class Stack
{
public:
  Stack()
  {

  }
  virtual ~Stack()
  {

  }
  static int a;

  bool empty() const//Test whether container is empty (public member function )
  {
      return lt.empty();
  }

  int size() const//Return size (public member function )
  {
    return lt.size();
  }

  T& top() //Access next element (public member function )
  {
      return lt[lt.size()-1];
  }

  void push(T value)//Insert element (public member function )
  {
    lt.push_back(value);
  }

  void emplace ()//Construct and insert element (public member function )
  {

  }
  T pop()//Remove top element (public member function )
  {
      T v = lt.back();
      lt.pop_back();
      return v;
  }
  void swap (T &v1, T& v2)
  {

  }


  private:
    vector<T> lt;
};


int main()
{
  vector<int> lt = {0,2,3,4,5,6,7,8,9};
  cout << lt.at(7) << endl;
  //cout << lt[7] << endl;


  std::stack<int> mystack;

  mystack.push(10);
  std::cout << "mystack.top() is now " << mystack.top() << '\n';
  mystack.push(20);
std::cout << "mystack.top() is now " << mystack.top() << '\n';
  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';


  cout << "---------------\n";
  Stack<int> sk;
  cout << "size = " << sk.size() << endl;
  sk.push(5);
  cout << "size = " << sk.size()<< endl;
  sk.push(9);
  cout << "size = " << sk.size() << endl;
  sk.push(66);
  cout << "size = " << sk.size()<<endl;
  int a = sk.top();
  cout << "pop: " << a << endl;
cout << "size = " << sk.size()<<endl;
cout << "pop: " << sk.pop() << endl;
cout << "size = " << sk.size() << " top is:" << sk.top() <<endl;
  


  char name[6], title[256];
 
  std::cout << "Please, enter your name: ";
  std::cin.getline (name,4);
  //代码通过字数限制存入数组后就不再运行11-12行代码，而是直接16行 
 
  std::cout << "Please, enter your favourite movie: ";
  std::cin.getline (title,10,'#');
	
	
  std::cout<<std::endl;	
  std::cout << name << " " << title;

std::cout<<std::endl;	

Stack<int> a;
Stack<int> b;
a.a =10;
b.a = 20;
return 0;
}