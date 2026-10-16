#pragma once
#include <iostream>
#include "A.h"
using namespace std;

template <typename T>
class Matrix
{
private:
    T* data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
        data = new T[rows * cols];
    }

    Matrix(const Matrix<T>& other)
    {
        rows = other.rows;
        cols = other.cols;

        data = new T[rows * cols];

        for (int i = 0; i < rows * cols; i++)
        {
            data[i] = other.data[i];
        }
    }

    ~Matrix()
    {
        delete[] data;
    }

    void Clear()
    {
        delete[] data;
        data = nullptr;
        rows = 0;
        cols = 0;
    }

    void Input()
    {
        for (int i = 0; i < rows * cols; i++)
        {
            cout << "Element " << i + 1 << ": ";
            cin >> data[i];
        }
    }

    void RandomFill()
    {
        for (int i = 0; i < rows * cols; i++)
        {
            data[i] = T(rand() % 10 + 1);
        }
    }
    void Print() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i * cols + j] << "\t";
            }

            cout << endl;
        }
    }
    T Max() const
    {
        T maxValue = data[0];

        for (int i = 1; i < rows * cols; i++)
        {
            if (data[i] > maxValue)
                maxValue = data[i];
        }

        return maxValue;
    }

    T Min() const
    {
        T minValue = data[0];

        for (int i = 1; i < rows * cols; i++)
        {
            if (data[i] < minValue)
            {
                minValue = data[i];
            }
        }

        return minValue;
    }

    Matrix<T>& operator=(const Matrix<T>& other)
    {
        if (this != &other)
        {
            T* newData = new T[other.rows * other.cols];

            for (int i = 0; i < other.rows * other.cols; i++)
            {
                newData[i] = other.data[i];
            }

            delete[] data;

            data = newData;
            rows = other.rows;
            cols = other.cols;
        }

        return *this;
    }

    Matrix<T> operator+(const Matrix<T>& other) const
    {
        Matrix<T> result(rows, cols);

        if (rows != other.rows || cols != other.cols)
        {
            cout << "Different matrix sizes!" << endl;
            return result;
        }

        for (int i = 0; i < rows * cols; i++)
        {
            result.data[i] = data[i] + other.data[i];
        }

        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) const
    {
        Matrix<T> result(rows, cols);

        if (rows != other.rows || cols != other.cols)
        {
            cout << "Different matrix sizes!" << endl;
            return result;
        }

        for (int i = 0; i < rows * cols; i++)
        {
            result.data[i] = data[i] - other.data[i];
        }

        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const
    {
        if (cols != other.rows)
        {
            cout << "Wrong matrix sizes for multiplication!" << endl;
            return Matrix<T>(1, 1);
        }

        Matrix<T> result(rows, other.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.cols; j++)
            {
                T sum = T(0);

                for (int k = 0; k < cols; k++)
                {
                    sum = sum +
                        data[i * cols + k] *
                        other.data[k * other.cols + j];
                }

                result.data[i * other.cols + j] = sum;
            }
        }

        return result;
    }

    Matrix<T> operator/(const Matrix<T>& other) const
    {
        Matrix<T> result(rows, cols);

        if (rows != other.rows || cols != other.cols)
        {
            cout << "Different matrix sizes!" << endl;
            return result;
        }

        for (int i = 0; i < rows * cols; i++)
        {
            if (other.data[i] == T(0))
            {
                cout << "Division by zero!" << endl;
                return result;
            }
        }

        for (int i = 0; i < rows * cols; i++)
        {
            result.data[i] = data[i] / other.data[i];
        }

        return result;
    }

};
