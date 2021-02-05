/*
 * @lc app=leetcode id=151 lang=c
 *
 * [151] Reverse Words in a String
 */

// @lc code=start

#define time_On_space_On 1
#ifdef time_On_space_On
int trim_space(char *s)
{
    if (!s) {
        return 0;
    }
    bool is_space = false;
    int len = strlen(s), idx = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            if (is_space) {
                s[idx++] = s[i];
                is_space = false;
            }
        } else {
            s[idx++] = s[i];
            is_space = true;
        }
    }
    return idx;
}

char *reverseWords(char *s)
{
    int len = trim_space(s);
    if (!s || !len) {
        return NULL;
    }
    char *return_array = (char *)malloc(sizeof(char) * (len + 1));
    int idx = 0;
    memset(return_array, 0, sizeof(char) * len);
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == ' ') {

        } else {

        }
    }
}
#else

#endif
// @lc code=end