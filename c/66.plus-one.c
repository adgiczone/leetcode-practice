/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    if (digitsSize <= 0) {
        return NULL;
    }
    int *recvArray = (int*)malloc(sizeof(int) * (digitsSize + 1));
    if (!recvArray) {
        return NULL;
    }
    int plus = 1, realSize = digitsSize;
    for (int i = digitsSize; i > 0; i--) {
        recvArray[i] = (digits[i - 1] + plus) % 10;
        plus = (digits[i - 1] + plus) / 10;
    }

    if (!recvArray[1] && plus) {
        recvArray[0] = 1;
        realSize++;
    }
    int *returnArray = (int*) malloc(realSize * sizeof(int));
    if (!returnArray) return NULL;

    if (realSize!=digitsSize) {
        memcpy(returnArray, recvArray, sizeof(int) * realSize);
    } else {
        memcpy(returnArray, recvArray + 1, sizeof(int) * realSize);
    }
    free(recvArray);
    if (!returnSize) {
        returnSize = (int*)malloc(sizeof(int));
        if (!returnSize) return NULL;
    }
    (*returnSize) = realSize;

    return returnArray;
}
// @lc code=end

