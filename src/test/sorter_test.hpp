#ifndef SORTER_TEST_HPP
#define SORTER_TEST_HPP

#include <algorithm>
#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/Test.h>


class SorterTest : public CppUnit::TestFixture {
private:
    std::vector<int> nums;
    std::vector<int> numsEqual;
    std::vector<int> numsEmpty;



    template <typename T>
    bool isSorted (const std::vector<T>& sorted, std::vector<T>& original) {
        std::sort(original.begin(), original.end());

        for (size_t i = 0; i < original.size(); ++i) {
            if (original[i] != sorted[i])
                return false;
        }
        return true;
    }

public:
    void setUp();
    void tearDown();

    void testSelectionSort();
    void testSelectionSortEqual();
    void testSelectionSortEmpty();
    void testBubbleSort();
    void testBubbleSortEqual();
    void testBubbleSortEmpty();
    void testInsertionSort();
    void testInsertionSortEqual();
    void testInsertionSortEmpty();
    void testQuickSort();
    void testQuickSortEqual();
    void testQuickSortEmpty();
    void testMergeSort();
    void testMergeSortEqual();
    void testMergeSortEmpty();
    void testHeapSort();
    void testHeapSortEqual();
    void testHeapSortEmpty();
    void testRadixSort();
    void testRadixSortEqual();
    void testRadixSortEmpty();

    static CppUnit::Test* suite();
};

#endif