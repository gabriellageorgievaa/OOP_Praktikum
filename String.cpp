#include <iostream>
#include "String.h"
#define nullptr NULL

using namespace std;


String::String()
{
    this -> Stringg = nullptr;
    this -> Size = 0;
}

String::String(const char* Stringg)
{
    this -> Stringg = new char [ strlen(Stringg)+1 ];
    strcpy(this -> Stringg,Stringg);

}

String::~String()
{
    destroy();
}



char* String::getStringg()
{
    return this -> Stringg;
}

void String::setStringg(const char* newStringg)
{
  delete[] Stringg;
  if ( newStringg )

  {
      size_t len = strlen(newStringg);
      if ( len != 0 )
      {
          Stringg = new char [ len+1 ];
          strcpy(Stringg,newStringg);
      }
      else
      {
          Stringg = new char[1];
          Stringg[0] = '\0';
      }
  }


  else
  {
      Stringg = new char[1];
      Stringg[0] = '\0';
  }
}



int String::getSize()
{
    return Size;
}

void String::setSize(int newSize)
{
    Size = newSize;

}


void String::destroy()
{
    delete[] this -> Stringg;
    this -> Size = 0;
}
