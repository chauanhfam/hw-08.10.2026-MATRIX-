#pragma once
#include <iostream>
using namespace std;
class A
{
private:
    double value;

public:
    A(double value = 0)
    {
        this->value = value;
    }
    double getValue() const
    {
        return value;
    }
    void setValue(double v)
    {
        value = v;
    }
    
    void Input()
    {
        cin >> value;
    }

    void Print() const
    {
        cout << value;
    }

    A operator+(const A& other) const
    {
        return A(value + other.value);
    }

    A operator-(const A& other) const
    {
        return A(value - other.value);
    }

    A operator*(const A& other) const
    {
        return A(value * other.value);
    }

    A operator/(const A& other) const
    {
        if (other.value == 0)
        {
            return A(0);
        }

        return A(value / other.value);
    }

    bool operator>(const A& other) const
    {
        return value > other.value;
    }

    bool operator<(const A& other) const
    {
        return value < other.value;
    }
    bool operator==(const A& other) const
    {
        return value == other.value;
    }
};
inline ostream& operator<<(ostream& os, const A& obj)
{
    os << obj.getValue(); 
    return os;
}

inline istream& operator>>(istream& is, A& obj)
{
    double temp;
    is >> temp;
    obj.setValue(temp); 
    return is;
}

