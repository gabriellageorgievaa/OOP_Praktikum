#include "String.h"

String::String(const char* _data)
{
    data = nullptr;
    setData(_data);
}

String::String()
{
    data = nullptr;
    setData('\0');
}

String::String(const String& other)
{
    data = nullptr;
    setData(other.data);
}

String& String::operator=(const String& other)
{
    if (this == &other)
        return *this;

    setData(other.data);
    return *this;
}

String::~String()
{
    delete[] data;
}

const char* String::getData() const
{
    return data;
}

size_t String::getLength() const
{
    return length;
}

void String::setData(const char* _data)
{
    delete[] data;

    if (_data != nullptr)
    {
        size_t len = strlen(_data);
        if (len > 0)
        {
            length = len;
            data = new char [length + 1];
            strcpy(data, _data);
            return;
        }
    }

    data = new char [1];
    data[0] = '\0';
    length = 0;
}

char& String::operator[](size_t index)
{
    return data[index];
}

const char& String::operator[](size_t index) const
{
    return data[index];
}
