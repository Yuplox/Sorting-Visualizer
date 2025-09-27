#ifndef SORTER_HPP
#define SORTER_HPP

#include <cstddef>
#include <random>
#include <vector>

class Sorter {
public:
    template <typename T>
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

    template <typename T>
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

    template <typename T>
    static std::vector<T>& insertionSort(std::vector<T>& nums) {
        size_t length = nums.size();
        for (size_t i = 1; i < length; ++i) {
            T key = nums[i];

            // Inserts elements from index 1 to i - 1
            size_t j = i - 1;
            while(j > 0 && key < nums[j]) {
                nums[j + 1] = nums[j];
                --j;
            }

            // Because j is type size_t and can underflow
            // Index 0 is handled outside the loop
            if (j == 0 && key < nums[0]) {
                nums[1] = nums[0];
                nums[0] = key;
            } else {
                nums[j + 1] = key; 
            }
        }
        return nums;
    }

    template <typename T>
    static std::vector<T>& quickSort(std::vector<T>& nums) {
        return quickSortHelper(nums, 0, nums.size());
    }

    template <typename T>
    static std::vector<T>& mergeSort(std::vector<T>& nums) {
        return mergeSortHelper(nums, 0, nums.size());
    }

    template <typename T>
    static std::vector<T>& heapSort(std::vector<T>& nums) {
        // Convert vector nums into a heap
        for (size_t i = (nums.size() - 1) / 2; i > 0; --i) {
            heapify(nums, i, nums.size());
        }
        heapify(nums,0, nums.size());

        
        // Move the max to the end of the heap and
        // recall heapify with one shorter length
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            T max = nums[0];
            nums[0] = nums[nums.size() - i - 1];
            nums[nums.size() - i - 1] = max;
            heapify(nums, 0, nums.size() - i - 1);
        }

        return nums;
    }

    static std::vector<int>& radixSort(std::vector<int>& nums){
        // Find max integer in vector nums
        int max = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > max) {
                max = nums[i];
            }
        }

        for (int div = 1; max / div > 0; div *= 10) {
            countingSort(nums, div);
        }
        return nums;
    }

private: 
    template <typename T>
    static std::vector<T>& quickSortHelper(std::vector<T>& nums, size_t begin, size_t end) {
        // Base case of length <= 1
        if (end - begin <= 1)
            return nums;

        
        // Randomly select pivot and sawp with last element
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(begin, end - 1);
        size_t pi =  dist(gen);
        T temp = nums[pi];
        nums[pi] = nums[end - 1];
        nums[end - 1] = temp;

        // Elements <= pivot are moved 
        // to the left half of the array
        size_t i = begin;
        for (size_t j = begin; j < end - 1; ++j) {
            if (nums[j] <= nums[end - 1]) {
                T temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                ++i;
            }
        }

        // Swap pivot with the first element 
        // in the right half of the array
        temp = nums[i];
        nums[i] = nums[end - 1];
        nums[end - 1] = temp;

        // Call quick sort on both halves of 
        // the array excluding the pivot
        quickSortHelper(nums, begin, i);
        quickSortHelper(nums, i + 1, end);
        return nums;
    }

    template <typename T>
    static std::vector<T>& mergeSortHelper(std::vector<T>& nums, size_t begin, size_t end) {
        // Base case of length <= 1
        if (end - begin <= 1)
            return nums;
        
        // Call mergeSort on left and right half of the array
        size_t mid = begin + (end - begin) / 2;
        mergeSortHelper(nums, begin, mid);
        mergeSortHelper(nums, mid, end);

        // Copy left and right halves for merging
        std::vector<T> left(nums.begin() + begin, nums.begin() + mid);
        std::vector<T> right(nums.begin() + mid, nums.begin() + end);
        size_t li = 0;
        size_t ri = 0;

        // Merge left and right copies back to the original vector
        while (li < left.size() && ri < right.size()) {
            if (left[li] <= right[ri]) {
                nums[begin + li + ri] = left[li];
                ++li;
            } else {
                nums[begin + li + ri] = right[ri];
                ++ri;
            }
        }

        // Copy remaining elements
        while (li < left.size()) {
            nums[begin + li + ri] = left[li];
            ++li;
        }
        while (ri < right.size()) {
            nums[begin + li + ri] = right[ri];
            ++ri;
        }

        return nums;
    }

    template <typename T>
    static std::vector<T>& heapify(std::vector<T>& nums, size_t index, size_t length) {
        T key = nums[index];

        size_t i = index;
        while (i < length) {
            size_t li = i * 2 + 1;
            size_t ri = i * 2 + 2;
            if (ri < length && nums[ri] > key && nums[ri] > nums[li]) {
                nums[i] = nums[ri];
                i = ri;
            } else if (li < length && nums[li] > key) {
                nums[i] = nums[li];
                i = li;
            } else {
                nums[i] = key;
                break;
            }
        }

        return nums;
    }

    static std::vector<int>& countingSort(std::vector<int>& nums, int div) {
        // Creates vector for output and digit frequency
        std::vector<int> count(10, 0);
        std::vector<int> output = nums;

        // Counts frequency of each digit
        for (size_t i = 0; i < nums.size(); ++i) {
            int digit = (nums[i] / div) % 10;
            ++count[digit];
        }

        // Converts frequencies to index values for ouput
        // [1, 5, 0, 1, 6, 7] -> [1, 6, 6, 7, 13, 20]
        for (int i = 1; i < 10; ++i) {
            count[i] += count[i - 1];
        }

        // Fills output based on indices in count
        for (size_t i = nums.size() - 1; i > 0; --i) {
            int digit = (nums[i] / div) % 10;
            output[--count[digit]] = nums[i];
        }
        output[--count[(nums[0] / div) % 10]] = nums[0];

        nums = output;
        return nums;
    }
};

#endif