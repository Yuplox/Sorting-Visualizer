#include <iostream>
#include "sorter.hpp"

int main() {
    std::vector<int> nums1 = {55, 88, 23, 10, 90, 33, 79, 1, 30, 55, 100};
    std::vector<int> nums2 = {55, 88, 23, 10, 90, 33, 79, 1, 30, 55, 100};


    Sorter::selectionSort<int>(nums1);
    Sorter::bubbleSort<int>(nums2);

    for (int n : nums1) {
        std::cout << n << " "; 
    }
    std::cout << std::endl;

    for (int n : nums2) {
        std::cout << n << " "; 
    }
    std::cout << std::endl;
}