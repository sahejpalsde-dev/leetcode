class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        int start = 0 , end = 0 , mid , ans;
                int n = arr.size();

                if(k>n){
                    return -1;
                }
                for ( int i =0; i<n; i++){
                    start=max(start,arr[i]);
                    end += arr[i];
                } 
                while(start<=end){
                    int time = 0;
                    int count = 1;
                    mid = start + (end - start )/2;
                    for(int j = 0 ; j < n ; j++ ){
                        time+=arr[j];

                        if(time>mid){
                            count++ ;
                            time=arr[j];
                        }
                    }

                    if(count<=k){
                        ans=mid;
                        end = mid-1;
                    }
                    else{
                        
                        start= mid+1;
                    }
                }
                return ans; 
    }
};