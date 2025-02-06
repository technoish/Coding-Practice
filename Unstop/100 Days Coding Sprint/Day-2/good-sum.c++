#include <iostream>
#include <vector>

int good_sum(int N, std::vector<int> &A) {
    std::vector<int> stack;  
    int sum = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] < 0) {  
            int required = -A[i];  
            int temp_sum = 0;

            
            while (!stack.empty() && temp_sum < required) {
                temp_sum += stack.back();
                stack.pop_back();
            }

            stack.push_back(abs(A[i]));
        } else {
            stack.push_back(A[i]); 
        }
    }

    int final_sum = 0;
    for (int num : stack) {
        final_sum += num;
    }

    return final_sum;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::cout << good_sum(N, A) << std::endl;
    return 0;
}
