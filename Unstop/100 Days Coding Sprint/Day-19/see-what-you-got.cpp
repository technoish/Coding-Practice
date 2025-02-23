#include <iostream>
using namespace std;

int user_logic(int A, int B, int C) {
    return A ^ (B & C);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;
        int result = user_logic(A, B, C);
        cout << result << endl;
    }
    return 0;
}