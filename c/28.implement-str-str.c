/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 */

// @lc code=start

/**
 * KMP 算法
 * 时间复杂度: O(n)
 * 当检测到不匹配的时候, 就已经知道不匹配之前的字符, 可以利用这种信息来避免重复匹配字符
 * 需要对匹配的字符进行处理来知道需要跳过哪些字符:
 * 构造长度等同needle的数组pmt(Partial Match Table)用来匹配每个字符中对应的需要跳过的字符个数.
 * pmt的值是字符串的前缀集合与后缀集合的交集中最长的非空字符串的长度.
 * example:
 * needle =  i  s  s  i  p
 * pmt    =  0  0  0  1  0
 * ------------------------------------------------------------------------------------
 * i     | prefix: ""                       | suffix:""                       | pmt = 0
 * is    | prefix: "i"                      | suffix:"s"                      | pmt = 0
 * iss   | prefix: "i", "is"                | suffix:"s", "ss"                | pmt = 0
 * issi  | prefix: "i", "is", "iss"         | suffix:"i", "si", "ssi"         | pmt = 1
 * issip | prefix: "i", "is", "iss", "issi" | suffix:"p", "ip", "sip", "ssip" | pmt = 0
 * ------------------------------------------------------------------------------------
 * 当移动到
 * haystack = m  i  s  s  i |s| s  i  p  p  i
 * needle   =    i  s  s  i |p|
 * pmt      =    0  0  0  1  0
 * 因 s 和 p 不匹配, 前三位已经比较过,第四位与前面有一个共同的字符, 移动位数 = 已匹配的字符数 - 对应的部分匹配值(4 - 1)
 * 同样
 * haystack = a  b  b  b  a  b  b  b  a  b  b  a
 * needle   = a  b  b  a
 * pmt      = 0  0  0  1
 * 第四位不匹配, 后移3 位
 * haystack = a  b  b |b| a  b  b  b  a  b  b  a
 * needle   =         |a| b  b  a
 * pmt      =          0  0  0  1
 * 第一位就不匹配, 就再移一位
 * haystack = a  b  b  b  a  b  b  b  a  b  b  a
 * needle   =             a  b  b  a
 * pmt      =             0  0  0  1
 * 后续同上
 */

/**
 * 假设sub_str = "ababa"
 */
void get_pmt_val(char sub_str[], int pmt[])
{
    if (!sub_str || !pmt) {
        return NULL;
    }
    int  str_len = strlen(sub_str);
    int  index = 0, len = 0;     // len为当前共同最长字符串的长度
    pmt[0] = 0;                 // 第一位总是0
    while ((++index) < str_len) {
        while (len > 0 && sub_str[index] != sub_str[len]) {
            // 如果最长的共同字符串长度>0, 但是当前字符不相同, len
            // 就赋值前一位的长度, 让当前字符和前一位进行对比, 看是否有符合.
            // 如果符合, 因为前面已经比较过, 所以共同字符串的长度就与前一位相同.
            // 如果直到len = 0 的时都没有相同的字符, 就不必比较, 退出循环,
            // 因为前面已经对比过没有相同的字符
            len = pmt[len - 1];
        }
        if (sub_str[index] == sub_str[len]) {
            // 既然相等, 说明当前至少有共同的字符
            // len和index向前进一位
            len++;
        }
        pmt[index] = len;
    }
}

int strStr(char *haystack, char *needle)
{
    int result = -1;
    if (!haystack || !needle || strlen(needle) > strlen(haystack)) {
        return result;
    }
    int  max_len   = strlen(haystack);
    int  sub_len   = strlen(needle);
    int *pmt_value = calloc(sub_len, sizeof(int));
    int  sub_index = 0;

    if (!pmt_value || sub_len == 0) {
        return 0;
    }

    get_pmt_val(needle, pmt_value);
    int i = 0;
    while (i < max_len && sub_index < sub_len) {
        if (needle[sub_index] == haystack[i]) {
            if (sub_index == (sub_len - 1)) {
                result = i - (sub_len - 1); // 最后一个匹配成功就退出
                break;
            }
            sub_index++;
            i++;
        } else {
            i         = (sub_index) ? i - pmt_value[sub_index - 1] : i + 1;
            sub_index = 0;
            result    = -1;
        }
    }
    free(pmt_value);
    return result;
}
// @lc code=end
