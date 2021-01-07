/*
 * @lc app=leetcode id=344 lang=c
 *
 * [344] Reverse String
 */

// @lc code=start


void reverseString(char* s, int sSize)
{
    if (!s || !sSize) {
        return;
    }

    for (int i = 0; i < sSize / 2; ++i)
    {
        char temp = s[i];
        s[i] = s[sSize - 1 - i];
        s[sSize - 1 - i] = temp;
    }
}
// @lc code=end

