#include <iostream>
#include <vector>
#include <algorithm>  // For std::reverse

std::vector<int> findLeaders(const std::vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return {};

    std::vector<int> leaders;
    int max_from_right = arr[n - 1];  // Initialize with the last element
    leaders.push_back(max_from_right);

    // Traverse the array from the second last element to the beginning
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] > max_from_right) {
            leaders.push_back(arr[i]);
            max_from_right = arr[i];
        }
    }

    // Reverse the leaders vector to maintain the original order
    std::reverse(leaders.begin(), leaders.end());

    return leaders;
}

int main() {
    std::vector<int> arr = {16, 17, 4, 3, 5, 2};
    std::vector<int> leaders = findLeaders(arr);

    std::cout << "Leaders in the array are: ";
    for (int leader : leaders) {
        std::cout << leader << " ";
    }
    std::cout << std::endl;

    return 0;
}
