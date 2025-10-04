#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include "sorter.hpp"

TEST_CASE("Testing Sorter Class") {
    std::vector<int> nums = {
    17, 83, 42, 9, 65,
    31, 78, 24, 56, 3,
    91, 12, 47, 68, 20,
    7, 88, 36, 59, 14,
    72, 5, 27, 95, 60
    };

    std::vector<int> sorted = nums;
    std::sort(sorted.begin(), sorted.end());

    std::vector<int> numsEmpty = {};

    SECTION("Selection Sort") {
        Sorter::selectionSort(nums);
        Sorter::selectionSort(numsEmpty);

        REQUIRE(nums == sorted);
        REQUIRE(numsEmpty.empty());
    }

    SECTION("Bubble Sort") {
        Sorter::bubbleSort(nums);
        Sorter::bubbleSort(numsEmpty);

        REQUIRE(nums == sorted);
        REQUIRE(numsEmpty.empty());
    }

    SECTION("Insertion Sort") {
        Sorter::insertionSort(nums);
        Sorter::insertionSort(numsEmpty);

        REQUIRE(nums == sorted);
        REQUIRE(numsEmpty.empty());
    }

    SECTION("Quick Sort") {
        Sorter::quickSort(nums);
        Sorter::quickSort(numsEmpty);

        REQUIRE(nums == sorted);
        REQUIRE(numsEmpty.empty());
    }

    SECTION("Merge Sort") {
        Sorter::mergeSort(nums);
        Sorter::mergeSort(numsEmpty);

        REQUIRE(nums == sorted);
        REQUIRE(numsEmpty.empty());
    }

    SECTION("Heap Sort") {
        Sorter::heapSort(nums);
        Sorter::heapSort(numsEmpty);

        REQUIRE(nums == sorted);
        REQUIRE(numsEmpty.empty());
    }

    SECTION("Radix Sort") {
        Sorter::radixSort(nums);
        Sorter::radixSort(numsEmpty);

        REQUIRE(nums == sorted);
        REQUIRE(numsEmpty.empty());
    }
}