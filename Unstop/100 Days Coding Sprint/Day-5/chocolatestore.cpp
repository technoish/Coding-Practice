#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void processQueries(int q, const vector<vector<string>>& queries) {
    unordered_map<string, int> chocolateStock;

    for (const auto& query : queries) {
        int type = stoi(query[0]); 
        string chocolateName = query[1];
        int count = stoi(query[2]); 

        if (type == 1) { 
            chocolateStock[chocolateName] += count;
        } else { 
            if (chocolateStock.count(chocolateName) > 0) { 
                if (chocolateStock[chocolateName] >= count) {
                    cout << count << endl;
                    chocolateStock[chocolateName] -= count;
                } else {
                    cout << chocolateStock[chocolateName] << endl;
                    chocolateStock[chocolateName] = 0;
                }
            } else {
                cout << 0 << endl;
            }
        }
    }
}

int main() {
    int q;
    cin >> q;
    vector<vector<string>> queries(q, vector<string>(3));

    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    processQueries(q, queries);

    return 0;
}