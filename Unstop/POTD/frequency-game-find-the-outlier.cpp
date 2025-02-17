#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

int find_minority_element_index(int N, std::vector<int>& nums) {
    std::map<int, int> frequencies;
    for (int i = 0; i < N; i++) {
        frequencies[nums[i]]++;
    }

    std::vector<int> freq_values;
    for (std::map<int, int>::iterator it = frequencies.begin(); it != frequencies.end(); ++it) {
        freq_values.push_back(it->second);
    }
    std::sort(freq_values.begin(), freq_values.end());

    double median_freq;
    if (freq_values.size() % 2 == 0) {
        median_freq = (freq_values[freq_values.size() / 2 - 1] + freq_values[freq_values.size() / 2]) / 2.0;
    } else {
        median_freq = freq_values[freq_values.size() / 2];
    }
    
    int closest_freq = -1;
    double min_diff = 1e9;

    for(int i = 0; i < freq_values.size(); i++){
        double diff = abs(freq_values[i] - median_freq);
        if(diff < min_diff){
            min_diff = diff;
            closest_freq = freq_values[i];
        }
    }


    int minority_element = -1;
    int min_val = 1e9;
    int min_index = -1;

    for (int i = 0; i < N; ++i) {
        if (frequencies[nums[i]] == closest_freq) {
            if (nums[i] < min_val) {
                min_val = nums[i];
                min_index = i;
                minority_element = nums[i];
            }
        }
    }

    return min_index + 1;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }

    int result = find_minority_element_index(N, nums);
    std::cout << result << std::endl;

    return 0;
}