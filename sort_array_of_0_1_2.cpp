// Sort an array having 0,1,2

#include <iostream>
#include <vector>

void sort012(std::vector<int>& arr) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;
    
    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                std::swap(arr[low++], arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                std::swap(arr[mid], arr[high--]);
                break;
        }
    }
}

int main() {
    std::vector<int> arr = {0, 1, 2, 1, 0, 2, 1, 0};
    
    sort012(arr);
    
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
