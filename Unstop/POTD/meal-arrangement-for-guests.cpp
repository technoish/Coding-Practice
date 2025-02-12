#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

struct DishGroup {
    char dish;
    int count;
};

bool compareDishGroups(const DishGroup& a, const DishGroup& b) {
    if (a.count != b.count) {
        return a.count > b.count;
    }
    return a.dish < b.dish;
}

void arrange_guests(const std::string& dishes) {
    if (dishes.empty()) {
        cout << "NULL" << endl;
        return;
    }

    map<char, int> vegDishes;
    map<char, int> nonVegDishes;

    for (int i = 0; i < dishes.length(); i++) {
        char dish = dishes[i];
        if (isVowel(dish)) {
            vegDishes[dish]++;
        } else {
            nonVegDishes[dish]++;
        }
    }

    vector<DishGroup> vegGroups;
    for (map<char, int>::iterator it = vegDishes.begin(); it != vegDishes.end(); ++it) {
        vegGroups.push_back({it->first, it->second});
    }

    vector<DishGroup> nonVegGroups;
    for (map<char, int>::iterator it = nonVegDishes.begin(); it != nonVegDishes.end(); ++it) {
        nonVegGroups.push_back({it->first, it->second});
    }

    sort(vegGroups.begin(), vegGroups.end(), compareDishGroups);
    sort(nonVegGroups.begin(), nonVegGroups.end(), compareDishGroups);

    string result = "";

    for (int i = 0; i < vegGroups.size(); i++) {
        result += vegGroups[i].dish;
        result += to_string(vegGroups[i].count);
    }

    for (int i = 0; i < nonVegGroups.size(); i++) {
        result += nonVegGroups[i].dish;
        result += to_string(nonVegGroups[i].count);
    }

    if (result.empty()) {
        cout << "NULL" << endl;
    } else {
        cout << result << endl;
    }
}

int main() {
    std::string dishes;
    std::getline(std::cin, dishes);

    arrange_guests(dishes);
    return 0;
}