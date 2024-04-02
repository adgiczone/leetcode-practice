/*
 * @lc app=leetcode id=167 lang=c
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//二分法主要在于缩小左右边界
int real_size = 0;
#ifdef method_1
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
#endif

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    if (!numbers || !numbersSize) {
        return 0;
    }
    int *return_array = (int *)malloc(2*sizeof(int));
    if (!return_array) {
        return 0;
    }
    *returnSize = 2;
    int left = 0, right = numbersSize - 1;
    while (left < right) {
        if ((numbers[left] + numbers[right])== target) {
            return_array[0] = left + 1;
            return_array[1] = right + 1;
            break;
        }
        else if ((numbers[left] + numbers[right]) < target) {
            left++;
        }
        else {
            right--;
        }
    }
    return return_array;
}
    // @lc code=end
