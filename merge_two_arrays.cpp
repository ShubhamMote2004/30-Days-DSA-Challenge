#include <iostream>
#include <vector>

void merge(std::vector<int>& arr1, std::vector<int>& arr2) {
    int m = arr1.size(); // Size of arr1
    int n = arr2.size(); // Size of arr2

    // Extend arr1 to make space for arr2
    arr1.resize(m + n);

    // Initialize pointers
    int i = m - 1; // Last index of the original arr1
    int j = n - 1; // Last index of arr2
    int k = m + n - 1; // Last index of the extended arr1

    // Merge in reverse order
    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }

    // Copy remaining elements of arr2, if any
    while (j >= 0) {
        arr1[k--] = arr2[j--];
    }

    // The remaining elements in arr1 are already in place, no need to copy them
    // The arrays are now merged and sorted in-place
}

int main() {
    std::vector<int> arr1 = {1, 3, 5, 7}; // Original array with enough space
    std::vector<int> arr2 = {2, 4, 6, 8}; // Array to be merged

    // Merge arr2 into arr1
    merge(arr1, arr2);

    // Output the result
    std::cout << "arr1: ";
    for (int num : arr1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Output the result for arr2 is not needed as arr2 is merged into arr1
    return 0;
}
