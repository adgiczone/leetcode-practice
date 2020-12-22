/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 */

// @lc code=start


int strStr(char * haystack, char * needle)
{
    int result = -1;
    if (!haystack || !needle || strlen(needle) > strlen(haystack)) {
        return result;
    }
    int max_len = strlen(haystack);
    int sub_len = strlen(needle);
    int sub_index = 0;
    if (sub_len == 0) {
        return 0;
    }
    for (int i = 0; i < max_len; i++) {
        if (needle[sub_index] == haystack[i]) {
            if (!sub_index){
                if ((i + sub_len) > max_len) {
                    break;
                }
                result = i;
            }
            sub_index++;
        } else if ((needle[sub_index] != haystack[i]) && sub_index != sub_len) {
            result = -1;
        }
    }
    return result;
}
// @lc code=end

