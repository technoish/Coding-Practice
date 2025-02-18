#include <iostream>
#include <vector>

void user_logic(int n, const std::vector<int>& seat_preferences, std::vector<int>& final_seating);

int main() {
    int n;
    std::cin >> n;
    std::vector<int> seat_preferences(n);
    for (int i = 0; i < n; i++) {
        std::cin >> seat_preferences[i];
    }
    std::vector<int> final_seating(n);
    user_logic(n, seat_preferences, final_seating);
    for (int i = 0; i < n; ++i) {
        std::cout << final_seating[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

void user_logic(int n, const std::vector<int>& seat_preferences, std::vector<int>& final_seating) {
    std::vector<bool> seats_occupied(n + 1, false); 

    for (int i = 0; i < n; i++) {
        int preferred_seat = seat_preferences[i];
        int current_seat = preferred_seat;
        bool seat_found = false;

        while (!seat_found) {
            if (!seats_occupied[current_seat]) {
                final_seating[i] = current_seat;
                seats_occupied[current_seat] = true;
                seat_found = true;
            } else {
                current_seat = (current_seat % n) + 1; 
            }
        }
    }
}