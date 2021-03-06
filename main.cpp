#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;

bool eqv(bool a, bool b)
{
    return (!(a ^ b));
}//эквивалентность <->
bool imp(bool a, bool b)
{
    return (!a || b);
}//импликация ->
bool aimp(bool a, bool b)
{
    return (!(!a || b));
}//антиимпликация !->
bool mod(bool a, bool b)
{
    return ((a + b) % 2);
}//сложение по модулю 2
bool adiz(bool a, bool b)
{
    return (!(a || b));
}//антидизъюнкция
bool akon(bool a, bool b)
{
    return (!(a && b));
}//антиконъюнкция
bool f1(bool x, bool y)
{
    bool l = (eqv(x,!y))||(adiz(y,x)); //вводимаая функция
    return l;
}
bool f2(bool x, bool y, bool z)
{
    bool l = mod((!(imp(x,!(y))&&!(z))),(!(x&&y))); //вводимаая функция
    return l;
}

int main()
{
    bool x, y, z;
    cout << setw(3) << "x" << setw(3) << "y"<< setw(3) << "f1" << setw(3) << endl;
    for (int i = 0; i < 4; i++) {
        if (i < 2) {
            x = 0;
        } else {
            x = 1;
        }
        if (i % 2) {
            y = 1;
        } else {
            y = 0;
        }
        cout << setw(3) << x << setw(3) << y << setw(3) << f1(x, y) << endl;
    }
    cout << endl;
    cout << setw(3) << "x" << setw(3) << "y" << setw(3) << "z" << setw(3) << "f2";
    cout << endl;
    for (int i = 0; i < 8; i++) {
        if (i < 4) {
            x = 0;
        } else {
            x = 1;
        }
        if ((i <= 1) || (i == 4) || (i == 5)) {
            y = 0;
        } else {
            y = 1;
        }
        if (i % 2) {
            z = 1;
        } else {
            z = 0;
        }
        cout << setw(3) << x << setw(3) << y << setw(3) << z << setw(3) << f2(x, y, z) << endl;
    }
    return 0;
}
