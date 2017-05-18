#pragma once
#include <cstring>

class String
{
private:
    char* data;
    size_t length;

public:
    String(const char* _data);
    String();
    String(const String& other);
    String& operator=(const String& other);
    ~String();

    const char* getData() const;
    size_t getLength() const;

    void setData(const char* _data);

    char& operator[](size_t index);
    const char& operator[](size_t index) const;
};
