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
    int carry = 0, m = 0, n = 0;
    int max_len = a_len > b_len ? a_len : b_len;

    char *target = malloc((max_len + 2) * sizeof(char));
    memset(target, 0, (max_len + 2) * sizeof(char));

    while (max_len >= 0) {
        //carry = (n + m + carry) / 2;
        carry = (n + m + carry) >> 1;
        n = (b_len) ? b[--b_len] - '0' : 0;
        m = (a_len) ? a[--a_len] - '0' : 0;
        //target[max_len--] = (n + m + carry) % 2 + '0';
        target[max_len--] = ((n + m + carry) & 1) + '0';
        //printf("m:%d, n:%d, target[%d]: %c, carry:%d\r\n", m, n, max_len + 1, target[max_len + 1], carry);
    }
    return target + (1 - carry);
}
// @lc code=end

