using lli = long long ;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        lli n  = nums.size() ;
        vector<lli>pre(n+1,0) ;

        for(int i=1;i<=n;i++){
            pre[i]+= pre[i-1]+nums[i-1] ;
        }
        lli ans =0 ;
        unordered_map<int,int>mpp ;

        for(int i=0;i<n;i++){

            mpp[nums[i]]++ ;

            if(i>=k){
                mpp[nums[i-k]]-- ;
                if(mpp[nums[i-k]]==0) mpp.erase(nums[i-k]) ;
            }

            if(i>=k-1&&mpp.size()==k){
                ans = max(ans,pre[i+1]-pre[i-k+1]);
            }

        }

        return ans ;
    }
};