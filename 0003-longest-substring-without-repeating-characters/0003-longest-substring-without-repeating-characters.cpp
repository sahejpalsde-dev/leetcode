class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256, 0);

        int i = 0;
        int len = 0;

        for (int j = 0; j < s.size(); j++) {
            count[s[j]]++;
            if(count[s[j]]==0){
                count[s[j]]=1;
            }
            while (count[s[j]] > 1 ) {
                count[s[i]]--;
                i++;
            }

            len = max(len, j - i + 1);
        }

        return len;
    }
};