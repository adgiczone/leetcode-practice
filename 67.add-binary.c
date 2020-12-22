/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

// @lc code=start

char * addBinary(char * a, char * b)
{
    int a_len = strlen(a);
    int b_len = strlen(b);
    char *min = NULL, *max = NULL;
    int max_len = 0, min_len = 0;
    int carry = 0;
    int m = 0, n = 0;

    if (a_len > b_len) {
        max_len = a_len;
        max = a;
        min_len = b_len;
        min = b;
    } else {
        max_len = b_len;
        max = b;
        min_len = a_len;
        min = a;
    }

    static char target[100000] = {0};
    memset(target, 0, sizeof(target));

    for (int i = 0; i <= max_len; i++) {
        carry = (n + m + carry) / 2;
        n = (i < min_len) ? min[min_len - i - 1] - '0' : 0;
        m = (i < max_len) ? max[max_len - i - 1] - '0' : 0;
        target[max_len - i] = (n + m + carry) % 2 + '0';
        printf("m:%d, n:%d, target[%d]: %c, carry:%d\r\n", m, n, max_len - i, target[max_len - i], carry);
    }
    return target + (1 - carry);
}
// @lc code=end

