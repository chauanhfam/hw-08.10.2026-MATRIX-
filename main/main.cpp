#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
    Matrix<A> m1(2, 2);
    Matrix<A> m2(2, 2);

    cout << "First matrix:" << endl;
    m1.RandomFill();
    m1.Print();

    cout << "\nSecond matrix:" << endl;
    m2.RandomFill();
    m2.Print();

    cout << "\nAddition:" << endl;
    Matrix<A> sum = m1 + m2;
    sum.Print();

    cout << "\nSubtraction:" << endl;
    Matrix<A> sub = m1 - m2;
    sub.Print();

    cout << "\nMultiplication:" << endl;
    Matrix<A> mul = m1 * m2;
    mul.Print();

    cout << "\nDivision:" << endl;
    Matrix<A> div = m1 / m2;
    div.Print();

    cout << "\nMaximum: " << m1.Max() << endl;
    cout << "Minimum: " << m1.Min() << endl;

    return 0;
}
