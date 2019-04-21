// 记录无重复的位置，以及当前字符上次出现的位置，依据这两个位置的左右关系确定长度
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        vector<int> pos(256, -1);
        int maxLen = 0, start = -1;
        for(int i = 0; i < s.size(); i++) {
            int cur = s[i];
            int curLastPos = pos[cur];
            start = max(curLastPos, start);
            maxLen = max(maxLen, i - start);
            pos[cur] = i;
        }
        return maxLen;
    }
};
