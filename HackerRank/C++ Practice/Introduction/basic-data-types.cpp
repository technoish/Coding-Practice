#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    int i;
    long l;
    char ch;
    float f;
    double d;
    cin >> i >> l >> ch >> f >> d;
    cout<< i <<endl;
    cout<< l <<endl;
    cout<< ch <<endl;
    cout<< fixed << setprecision(3) << f <<endl;
    cout<< fixed << setprecision(9) << d <<endl; 
    return 0;
}
