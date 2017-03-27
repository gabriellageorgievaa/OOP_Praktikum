#pragma once
#include <cstring>
#include <cstddef>

using namespace std;


class String
{
private:
    char* Stringg;
    int Size;
public:
    String();
    String(const char* Stringg );
    ~String();

    char* getStringg();
    int getSize();

    void setStringg(const char* Stringg);
    void setSize(int Size);

    void destroy();
};
