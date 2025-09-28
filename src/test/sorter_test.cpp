#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include "sorter.hpp"
#include "sorter_test.hpp"


void SorterTest::setUp() {
    nums = {
    73, 12, 58, 91, 6,
    44, 37, 85, 19, 67,
    23, 50, 3, 71, 96,
    40, 28, 62, 17, 89,
    35, 9, 78, 54, 31
    };
    numsEqual = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    numsEmpty = {};
}

void SorterTest::tearDown() {}

void SorterTest::testSelectionSort() {
    std::vector<int> test = nums;
    std::vector<int> original = nums;

    Sorter::selectionSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testSelectionSortEqual() {
    std::vector<int> test = numsEqual;
    std::vector<int> original = numsEqual;

    Sorter::selectionSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testSelectionSortEmpty() {
    std::vector<int> test = numsEmpty;
    CPPUNIT_ASSERT(Sorter::selectionSort(test).empty());
}

void SorterTest::testBubbleSort() {
    std::vector<int> test = nums;
    std::vector<int> original = nums;

    Sorter::bubbleSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testBubbleSortEqual() {
    std::vector<int> test = nums;
    std::vector<int> original = nums;

    Sorter::bubbleSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testBubbleSortEmpty() {
    std::vector<int> test = numsEmpty;
    CPPUNIT_ASSERT(Sorter::bubbleSort(test).empty());
}

void SorterTest::testInsertionSort() {
    std::vector<int> test = nums;
    std::vector<int> original = nums;

    Sorter::insertionSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testInsertionSortEqual() {
    std::vector<int> test = nums;
    std::vector<int> original = nums;

    Sorter::insertionSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testInsertionSortEmpty() {
    std::vector<int> test = numsEmpty;
    CPPUNIT_ASSERT(Sorter::insertionSort(test).empty());
}

void SorterTest::testQuickSort() {
    std::vector<int> test = nums;
    std::vector<int> original = nums;

    Sorter::quickSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testQuickSortEqual() {
    std::vector<int> test = nums;
    std::vector<int> original = nums;

    Sorter::quickSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testQuickSortEmpty() {
    std::vector<int> test = numsEmpty;
    CPPUNIT_ASSERT(Sorter::quickSort(test).empty());
}

void SorterTest::testMergeSort() {
    std::vector<int> test = nums;
    std::vector<int> original = nums;

    Sorter::mergeSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testMergeSortEqual() {
    std::vector<int> test = nums;
    std::vector<int> original = nums;

    Sorter::mergeSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testMergeSortEmpty() {
    std::vector<int> test = numsEmpty;
    CPPUNIT_ASSERT(Sorter::mergeSort(test).empty());
}

void SorterTest::testHeapSort() {
    std::vector<int> test = nums;
    std::vector<int> original = nums;

    Sorter::heapSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testHeapSortEqual() {
    std::vector<int> test = nums;
    std::vector<int> original = nums;

    Sorter::heapSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testHeapSortEmpty() {
    std::vector<int> test = numsEmpty;
    CPPUNIT_ASSERT(Sorter::heapSort(test).empty());
}

void SorterTest::testRadixSort() {
    std::vector<int> test = nums;
    std::vector<int> original = nums;

    Sorter::radixSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testRadixSortEqual() {
    std::vector<int> test = nums;
    std::vector<int> original = nums;

    Sorter::radixSort(test);
    CPPUNIT_ASSERT(SorterTest::isSorted(test, original));
}

void SorterTest::testRadixSortEmpty() {
    std::vector<int> test = numsEmpty;
    CPPUNIT_ASSERT(Sorter::radixSort(test).empty());
}

CppUnit::Test* SorterTest::suite() {
    CppUnit::TestSuite* suiteOfTests = new CppUnit::TestSuite("SorterTest");
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testSelectionSort",
                                            &SorterTest::testSelectionSort));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testSelectionSortEqual",
                                            &SorterTest::testSelectionSortEqual));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testSelectionSortEmpty",
                                            &SorterTest::testSelectionSortEmpty));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testBubbleSort",
                                            &SorterTest::testBubbleSort));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testBubbleSortEqual",
                                            &SorterTest::testBubbleSortEqual));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testBubbleSortEmpty",
                                            &SorterTest::testBubbleSortEmpty));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testInsertionSort",
                                            &SorterTest::testInsertionSort));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testInsertionSortEqual",
                                            &SorterTest::testInsertionSortEqual));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testInsertionSortEmpty",
                                            &SorterTest::testInsertionSortEmpty));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testQuickSort",
                                            &SorterTest::testQuickSort));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testQuickSortEqual",
                                            &SorterTest::testQuickSortEqual));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testQuickSortEmpty",
                                            &SorterTest::testQuickSortEmpty));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testMergeSort",
                                            &SorterTest::testMergeSort));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testMergeSortEqual",
                                            &SorterTest::testMergeSortEqual));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testMergeSortEmpty",
                                            &SorterTest::testMergeSortEmpty));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testHeapSort",
                                            &SorterTest::testHeapSort));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testHeapSortEqual",
                                            &SorterTest::testHeapSortEqual));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testHeapSortEmpty",
                                            &SorterTest::testHeapSortEmpty));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testRadixSort",
                                            &SorterTest::testRadixSort));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testRadixSortEqual",
                                            &SorterTest::testRadixSortEqual));
    suiteOfTests->addTest(new CppUnit::TestCaller<SorterTest>(
                                            "testRadixSortEmpty",
                                            &SorterTest::testRadixSortEmpty));
    return suiteOfTests;
}