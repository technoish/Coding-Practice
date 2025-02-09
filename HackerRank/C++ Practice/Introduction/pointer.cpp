#include <iostream>
using namespace std;

void sum_and_difference(int* a, int* b){
    int sum;
    int difference;
    sum = *a + *b;
    cout << sum << endl;
    difference = *a - *b;
    if(difference < 0){
        difference = -(difference);
        cout << difference << endl;
    }
    else cout << difference;  
}


int main() {
    int a, b;
    cin >> a; 
    cin >> b;
    sum_and_difference(&a, &b);  
    return 0;
}
