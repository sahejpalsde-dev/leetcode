class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       
        int start = 1;
        int end = 0;
        for (int pile : piles) {
            end = max(end, pile);
        }

        int ans = end;

        
        while (start <= end) { 
            int mid = start + (end - start) / 2;
            long long count = 0; 
            for (int i = 0; i < piles.size(); i++) {
                
                if (piles[i] <= mid) {
                    count++;
                } else if (piles[i] % mid == 0) {
                    int num =  piles[i] / mid;
                    count = count + num;
                    num = 0;
                } else {
                    count += (piles[i] / mid) + 1;
                }
            }

            if (count <= h) { 
                ans = mid;        
                end = mid - 1;   
            } else {
                start = mid + 1;  
            }
        }

        return ans;
    }
};