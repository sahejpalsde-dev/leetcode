class Solution {
public:
    void findlps(vector<int> &lps , string s){
        int pre=0, suff=1;
        while(suff<s.size()){
        
            if(s[pre]==s[suff]){
            lps[suff]=pre+1;
            pre++;
            suff++;
            }
            else{
                if(pre==0){
                    lps[suff]=0;
                    suff++;
                }
                else{
                    pre=lps[pre - 1];
                }
            }
        } 
    }
    
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> lps(m,0);
        findlps(lps,needle);


        int first=0, second=0;

        while(first<haystack.size() && second<needle.size()){

            if(haystack[first]==needle[second]){
                first++ ;
                second++ ;
            }
            else{
                if(second==0){
                    first++;
                }
                else{
                    second=lps[second - 1];
                }
                
            }
        }
        if(second==needle.size())
        return first - second ;
        
        return -1;
    }
};