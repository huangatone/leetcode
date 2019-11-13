#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std; 

#include <sstream>

class TTS
{
  public:
  TTs()
  {

  }
  static int a;
}
class String
{
public:
  String(const char* str= nullptr)
  {
    if (str)
    {
      _length = strlen(str);
      _data = new char[_length+1];
      strcpy(_data, str);
    }
    else
    {
      _data = new char[1];
      _length = 0;
      _data[0] = '\0';
    }
  }
  String(const String& str)
  {
    _length = str.size();
      _data = new char[ str.size() +1];
      strcpy(_data, str.data());
  }

  size_t size() const
  {
    return _length;
  }

  const char* data() const
  {
    return _data;
  }

  String & operator =(const String &str)
  {
    delete [] _data;
    _length = str.size();
    _data = new char[ _length +1];
    strcpy(_data, str.data());
    return *this;
  }

  String & operator +=(const String &str)
  {
    _length += str.size() ;
    char *newData = new char[_length+1];
    strcpy(newData, _data);
    strcat(newData, str.data());
    delete [] _data;
    _data = newData;
    return *this;
  }

  char& operator[](int n) const
  {
    assert(n<_length);
    return _data[n];
  }


  private:
    char* _data;
    size_t _length;
};


int main ()
{
  std::string name;

  std::cout << "Please, enter your full name: ";
  std::getline (std::cin,name,'#');
  std::cout << "Hello, " << name << "!\n";

  string S, T; 
    
  getline(cin,S); 
    
 
    
  stringstream X(S); 
    
  while(getline(X, T, ' ')) 

  { 
     cout<<T<<endl; 
  } 

  String s1("abcde");
  cout << "String s1 is " << s1.data() << " length is " << s1.size() << endl;
  String s2(s1);
  cout << "String s2 is " << s2.data() << " length is " << s2.size() << endl;

  
  s1 += s2;
  cout << "String s1 is " << s1.data() << " length is " << s1.size() << endl;

  cout << "2,4 ,6" << s2[2] << endl;
  cout << "2,4 ,6" << s2[4] << endl;
  cout << "2,4 ,6" << s2[6] << endl;

  TTS a
  return 0;
}