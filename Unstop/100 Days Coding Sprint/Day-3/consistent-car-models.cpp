#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    string components;
    cin >> components;

    int n;
    cin >> n;

    vector<string> models(n);
    for (int i = 0; i < n; i++) {
        cin >> models[i];
    }

    unordered_set<char> allowedComponents;
    for (char c : components) {
        allowedComponents.insert(c);
    }

    int consistentCarCount = 0;
    for (const string& model : models) {
        bool isConsistent = true;
        for (char component : model) {
            if (allowedComponents.find(component) == allowedComponents.end()) {
                isConsistent = false;
                break;
            }
        }
        if (isConsistent) {
            consistentCarCount++;
        }
    }

    cout << consistentCarCount << endl;

    return 0;
}