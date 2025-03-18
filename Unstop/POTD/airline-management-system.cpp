#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

void user_logic(int n, int q, vector<pair<int, int>> &events) {
    queue<int> waiting;
    set<int> boarded;
    vector<int> called;
    vector<int> result;

    for (auto &event : events) {
        if (event.first == 1) {
            if (waiting.size() < n) {
                waiting.push(waiting.size() + 1);
                called.push_back(waiting.back());
            } else {
              int next_person = 1;
              while(find(called.begin(), called.end(), next_person) != called.end()){
                next_person++;
              }
              waiting.push(next_person);
              called.push_back(next_person);
            }
        } else if (event.first == 2) {
            boarded.insert(event.second);
        } else if (event.first == 3) {
            queue<int> temp_queue = waiting;
            int longest_waiting = -1;
            while (!temp_queue.empty()) {
                int person = temp_queue.front();
                temp_queue.pop();
                if (boarded.find(person) == boarded.end()) {
                    longest_waiting = person;
                    break;
                }
            }
            if (longest_waiting != -1) {
                result.push_back(longest_waiting);
            }
        }
    }

    for (int person : result) {
        cout << person << endl;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> events;
    for (int i = 0; i < q; i++) {
        int event_type;
        cin >> event_type;
        if (event_type == 1 || event_type == 3) {
            events.emplace_back(event_type, 0);
        } else if (event_type == 2) {
            int person;
            cin >> person;
            events.emplace_back(event_type, person);
        }
    }
    user_logic(n, q, events);
    return 0;
}