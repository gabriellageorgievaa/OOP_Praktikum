#pragma once
template<typename T>
class Vector
{
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize(size_t _capacity)
    {
        T* temp = new T [_capacity];
        for(size_t i = 0; i < size; i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        size = capacity = _capacity;
    }

public:
    Vector()
    {
        data = nullptr;
        size = capacity = 0;

    }

    Vector(const Vector& other)
    {
        setData(other.data, other.size);
    }

    Vector& operator=(const Vector& other)
    {
        if (this == &other)
            return *this;

        setData(other.data, other.size);
        return *this;
    }

    ~Vector()
    {
        delete[] data;
    }

    T& operator[] (size_t idx)
    {
        return data[idx];
    }

    const T& operator[] (size_t idx) const
    {
        return data[idx];
    }

    size_t getSize() const
    {
        return size;
    }

    void setData(T* _data, size_t _size)
    {
        delete[] data;
        if (_data != nullptr & _size > 0)
        {
            size = capacity = _size;
            data = new T [size];
            for (size_t i = 0; i < size; i++)
            {
                data[i] = _data[i];
            }
        }
        else
        {
            data = nullptr;
            size = capacity = 0;
        }
    }

    void push_back(const T& element)
    {
        if((size + 1) > size)
        {
            if (capacity == 0)
            {
                capacity = 1;
            }
            resize(capacity * 2);
        }
        data[size] = element;
        size++;
    }


};

