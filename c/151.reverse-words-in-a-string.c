/*
 * @lc app=leetcode id=151 lang=c
 *
 * [151] Reverse Words in a String
 */

// @lc code=start

#define time_O_n_space_O_n 1
#ifdef time_O_n_space_O_n
int trim_space(char * s)
{
    if (!s) {
        return 0;
    }
    bool is_space = false;
    int len = strlen(s), idx = 0;
    for (int i = 0; i < len; ++i) {
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
    return (s[idx - 1] == ' ') ? idx - 1 : idx;
}

char *reverseWords(char *s)
{
    int len = trim_space(s);
    if (!s || !len) {
        return NULL;
    }
    char *return_array = (char *)malloc(sizeof(char) * (len + 1));
    if (!return_array) {
        return NULL;
    }
    memset(return_array, 0, sizeof(char) * (len + 1));
    int cur_index = 0, last_index = 0;
    for (int i = 0; i < len; i++) {
        if (i == len - 1 || s[i] == ' ') {
            i = (i == len - 1) ? len : i;
            memcpy(return_array + len - i, s + last_index, i - last_index);
            (len - i == 0) ? return_array[i - last_index] = ' ' : (return_array[len - i - 1] = ' ');
            last_index = i + 1;
        }
    }
    return_array[len] = '\0';
    return return_array;
}
#else

#endif
// @lc code=end