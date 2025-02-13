#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N; 

    vector<int> votes(N);
    int totalVotes = 0;

    for (int i = 0; i < N; ++i) {
        cin >> votes[i];
        totalVotes += votes[i];
    }

    int majorityThreshold = totalVotes / 2;

    sort(votes.rbegin(), votes.rend());

    int selectedVotesSum = 0;
    vector<int> selectedVotes;

    for (int vote : votes) {
        selectedVotes.push_back(vote);
        selectedVotesSum += vote;
        if (selectedVotesSum > majorityThreshold) {
            break;
        }
    }

    for (int vote : selectedVotes) {
        cout << vote << " ";
    }
    cout << endl;

    return 0;
}