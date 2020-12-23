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
 * pmt的值是字符串的前缀集合与后缀集合的交集中最长元素的长度.
 * example:
 * needle =  i  s  s  i  p
 * pmt    =  0  0  0  1  0
 * i:     prefix: ""                        suffix:""                        pmt = 0
 * is:    prefix: "i"                       suffix:"s"                       pmt = 0
 * iss:   prefix: "i", "is"                 suffix:"s", "ss"                 pmt = 0
 * issi:  prefix: "i", "is", "iss"          suffix:"i", "si", "ssi"          pmt = 1
 * issip: prefix: "i", "is", "iss", "issi"  suffix:"p", "ip", "sip", "ssip"  pmt = 0
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
 * haystack = a  b  b  b  a  b  b  b  a  b  b  a
 * needle   =          a  b  b  a
 * pmt      =          0  0  0  1
 * 第一位就不匹配, 就再移一位
 * haystack = a  b  b  b  a  b  b  b  a  b  b  a
 * needle   =             a  b  b  a
 * pmt      =             0  0  0  1
 * 后续同上
 */


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

