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
bool f1(bool x, bool y, bool z)
{
    bool l = x&&(mod(y,z)); //вводимаая функция
    return l;
}
bool f2(bool x, bool y, bool z)
{
    bool l = mod((x&&y),(x&&z)); //вводимаая функция
    return l;
}

int main()
{
    string SDNF1 = "(";
    string SDNF2 = "(";
    bool x, y, z, fun, fun1;
    cout << endl;
    cout << setw(3) << "x" << setw(3) << "y"<< setw(3)<< "z" << setw(3) << "f1" << setw(3) << "f2" << setw(3) << endl;
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
        cout << setw(3) << x << setw(3) << y << setw(3) << z << setw(3) << f1(x, y, z) << setw(3) << f2(x, y, z) << setw(3) << endl;
        fun = f1(x, y, z);
        fun1 = f2(x, y, z);
        if (fun == 1) {

            if (x == 1) {
                SDNF1 = SDNF1 + "x";
            } else {
                SDNF1 = SDNF1 + "!x";
            }
            if (y == 1) {
                SDNF1 = SDNF1 + "y";
            } else {
                SDNF1 = SDNF1 + "!y";
            }
            if (z == 1) {
                SDNF1 = SDNF1 + "z";
            } else {
                SDNF1 = SDNF1 + "!z";
            }

            SDNF1 = SDNF1 + ")+(";

        }
        if (fun1 == 1) {

            if (x == 1) {
                SDNF2 = SDNF2 + "x";
            } else {
                SDNF2 = SDNF2 + "!x";
            }
            if (y == 1) {
                SDNF2 = SDNF2 + "y";
            } else {
                SDNF2 = SDNF2 + "!y";
            }
            if (z == 1) {
                SDNF2 = SDNF2 + "z";
            } else {
                SDNF2 = SDNF2 + "!z";
            }

            SDNF2 = SDNF2 + ")+(";

        }
        if (f1(x, y, z) != f2(x, y, z)) {
            cout << " Вывод: f1 не эквивалентна f2" << endl;
            break;

        } else {
            if (i == 7) {
                cout << "Вывод: f1 эквивалентна f2" << endl;
            }
            continue;
        }


    }
    SDNF1 = SDNF1.substr(0, SDNF1.size() - 2);
    SDNF2 = SDNF2.substr(0, SDNF2.size() - 2);
    cout << "SDNF1: " << SDNF1 << endl;
    cout << "SDNF2: " << SDNF2 << endl;
    return 0;
}
