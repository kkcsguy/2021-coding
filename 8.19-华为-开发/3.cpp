/* https://www.nowcoder.com/discuss/482588?type=post&order=time&pos=&page=1&channel=1013&source_id=search_post
 * 这题题目没描述清楚，测试用例很薄弱。
 * 这个是牛客上的一个答案,不能完全满足题意,但是已经过OJ了
 * --------------------
 * 输入: 0022
 *      23
 * 按题意应该输出 2
 * 代码会输出 3
 * --------------------
 * 输入: 0000
 *      2111
 * 应该输出 1
 * 代码会输出 2
 * --------------------
 */
#include "bits/stdc++.h"

using namespace std;

int helper(vector<int> &frame, vector<int> &brick) {
    int frame_n = frame.size(), brick_n = brick.size();
    int res = 1000000;
    for (int i = 0; i <= frame_n - brick_n; i++) {
        int max_h = 0, total_max_h;
        for (int j = 0; j < brick_n; j++)
            max_h = max(max_h, brick[j] + frame[i + j]);
        total_max_h = max_h;
        int r = 100000;
        for (int j = 0; j < frame_n; j++) {
            total_max_h = max(total_max_h, frame[j]);
            if (j < i || j >= (i + brick_n))
                r = min(r, frame[j]);
            else
                r = min(frame[j] + brick[j - i] == max_h ? max_h : frame[j], r);
        }
        res = min(res, total_max_h - r);
    }
    return res;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> frame(s1.size()), brick(s2.size());
    for (int i = 0; i < s1.size(); i++) frame[i] = s1[i] - '0';
    for (int i = 0; i < s2.size(); i++) brick[i] = s2[i] - '0';
    cout << helper(frame, brick);
    return 0;
}