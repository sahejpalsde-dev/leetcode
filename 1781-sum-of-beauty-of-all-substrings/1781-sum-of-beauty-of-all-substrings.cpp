class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            int mf=1;
            int lf=1;
            int freq[26]={0};
            freq[s[i]-'a']++;
            int clf=1;
            for(int j=i+1;j<n;j++){
                int currFreq=++freq[s[j]-'a'];
                if(currFreq>mf) mf=currFreq;
                if(currFreq<lf){
                    lf=currFreq;
                    clf=1;
                }
                else if(currFreq==lf) clf++;
                else if(currFreq==lf+1 && --clf==0){
                    lf++;
                    for(int k=0;k<26;k++){
                        if(lf==freq[k]) clf++;
                    }
                }
                if(mf-lf!=0) ans+=mf-lf; 
            }
        }
        return ans;
    }
}; 