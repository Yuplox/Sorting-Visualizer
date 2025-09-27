#include <iostream>
#include "sorter.hpp"

int main() {
    std::vector nums1 = {55, 88, 23, 10, 90, 33, 79, 1, 30, 55, 100};
    std::vector nums2 = {55.1, 88.0, 23.0, 10.0, 90.0, 33.0, 79.0, 1.0, 30.0, 55.0, 100.0};
    std::vector nums3 = {55, 88, 23, 10, 90, 33, 79, 1, 30, 55, 100};

    Sorter::selectionSort(nums1);
    Sorter::quickSort(nums2);
    Sorter::mergeSort(nums3);


    for (auto n : nums1) {
        std::cout << n << " "; 
    }
    std::cout << std::endl;

    for (auto n : nums2) {
        std::cout << n << " "; 
    }
    std::cout << std::endl;

    for (auto n : nums3) {
        std::cout << n << " "; 
    }
    std::cout << std::endl;
}