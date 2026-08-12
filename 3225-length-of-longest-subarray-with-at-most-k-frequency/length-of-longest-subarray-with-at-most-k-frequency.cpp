class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        if(nums.size()<=1) return nums.size() ;
        int l = 0 , r = 1 ;
        unordered_map<int,int>mpp ;
        mpp[nums[l]]++ ;
        
        int result = 1 ;
        while(l<r&&r<nums.size()){
            mpp[nums[r]]++ ;
            
            // result = maxc ;
            // maxi = nums[r] ;
            bool found = false ;
            while(mpp[nums[r]]>k){
                
                if(nums[l]==nums[r]){
                    found = true ;
                }
                mpp[nums[l]]-- ;
                // if(maxi==nums[l]) maxc-- ;
                l++ ;
                if(found) break ;
        
            }
            result = max(result,r-l+1) ;
            r++ ;

        }

        return result ;
    }
};