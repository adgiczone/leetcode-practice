/*
 * @lc app=leetcode id=167 lang=c
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int real_size = 0;
int binary_search(int *array, int arraySizes, int target)
{
    int size = arraySizes / 2;
    if (!size) {
        return 0;
    }
    int *slipe = array;
    if (target == array[size]) {
        return real_size + size;
    }
    if (target > array[size]) {
        slipe = array + size;
        real_size += size;
    }
    return binary_search(slipe, arraySizes - size, target);
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)
{
    int *returnArray = calloc(2, sizeof(int));
    (*returnSize) = 2;
    for (int i = 0; i < numbersSize; i++) {
        real_size = 0;
        returnArray[0] = i + 1;
        int finder = binary_search(numbers + i, numbersSize - i, target - numbers[i]);
        if (finder) {
            returnArray[1] = finder + i + 1;
            break;
        }
    }
    return returnArray;
}
// @lc code=end

