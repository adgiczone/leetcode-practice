/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 */

// @lc code=start

char *longestCommonPrefix(char **strs, int strsSize)
{
    if (!strs || strsSize == 0) {
        return "";
    }
    int  short_len = 200;
    bool outer     = false;
    for (int i = 0; i < strsSize; i++) {
        if (strlen(strs[i]) < short_len) {
            short_len = strlen(strs[i]);
        }
    }
    char *common_prefix = calloc(short_len + 2, sizeof(char));
    if (!common_prefix) {
        return "";
    }
    for (int i = 0; i < short_len; i++) {
        char standra = strs[0][i];
        for (int j = 0; j < strsSize; j++) {
            if (strs[j][i] != standra) {
                outer = true;
                break;
            }
        }
        if (!outer) {
            common_prefix[i] = standra;
        } else {
            break;
        }
    }
    return common_prefix;
}
// @lc code=end
