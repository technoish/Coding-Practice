#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> user_logic(vector<int> &fat, vector<int> &protein, vector<int> &vitamin) {
    int fat_count = 0;
    int protein_count = 0;
    int vitamin_count = 0;

    unordered_set<int> protein_set(protein.begin(), protein.end());
    unordered_set<int> vitamin_set(vitamin.begin(), vitamin.end());
    unordered_set<int> fat_set(fat.begin(), fat.end());

    for (int f : fat) {
        if (protein_set.find(f) == protein_set.end() && vitamin_set.find(f) == vitamin_set.end()) {
            fat_count++;
        }
    }

    for (int p : protein) {
        if (fat_set.find(p) == fat_set.end() && vitamin_set.find(p) == vitamin_set.end()) {
            protein_count++;
        }
    }

    for (int v : vitamin) {
        if (fat_set.find(v) == fat_set.end() && protein_set.find(v) == protein_set.end()) {
            vitamin_count++;
        }
    }

    return {fat_count, protein_count, vitamin_count};
}

int main() {
    int n;
    cin >> n;
    vector<int> fat(n), protein(n), vitamin(n);
    for (int i = 0; i < n; ++i) {
        cin >> fat[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> protein[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> vitamin[i];
    }
    vector<int> result = user_logic(fat, protein, vitamin);
    cout << result[0] << " " << result[1] << " " << result[2] << endl;
    return 0;
}