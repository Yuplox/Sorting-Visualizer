#ifndef SORTER_H
#define SORTER_H

#include <vector>

class Sorter {
public:
    // Comparison Sorting Algorithms

    template<typename T>
    static std::vector<T>& selectionSort(std::vector<T>& nums) {
        size_t length = nums.size();
        for (size_t i = 0; i < length; ++i) {
            size_t minInd = i;
            for (size_t j = i; j < length; ++j) {
                if (nums[j] < nums[minInd])
                    minInd = j;
                }
                T temp = nums[i];
                nums[i] = nums[minInd];
                nums[minInd] = temp;
            }
        return nums;
    }

    template<typename T>
    static std::vector<T>& bubbleSort(std::vector<T>& nums) {
        size_t length = nums.size();
        for (size_t i = length - 1; i > 0; --i) {
            for (size_t j = 1; j <= i; ++j) {
                if (nums[j - 1] > nums[j]) {
                    T temp = nums[j - 1];
                    nums[j - 1] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        return nums;
    }

    template<typename T>
    static std::vector<T>& insertionSort(std::vector<T>& nums);

    template<typename T>
    static std::vector<T>& quickSort(std::vector<T>& nums);

    template<typename T>
    static std::vector<T>& mergeSort(std::vector<T>& nums);

    template<typename T>
    static std::vector<T>& heapSort(std::vector<T>& nums);

    // Non-Comparison Sorting Algorithms
    template<typename T>
    static std::vector<T>& radixSort(std::vector<T>& nums);

private:
    template<typename T>
    static std::vector<T>& countingSort(std::vector<T>& nums);
    
    template<typename T>
    static std::vector<T>& quickSortHelper(std::vector<T>& nums);
};


#endif