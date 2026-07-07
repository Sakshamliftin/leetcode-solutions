class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mpp ;
        vector<int>diff ;
        int od=0 , evn=0 ;

        for(int i=0;i<nums.size();i++){
            diff.push_back(od-evn) ;
            if(nums[i]==0){
                evn++ ;
            }
            else{
                od++ ;
            }
        }
        diff.push_back(od-evn) ;
        int longest = 0 ;
        for(int i=0;i<diff.size();i++){
            if(mpp.find(diff[i])==mpp.end()){
                mpp[diff[i]] = i ;
            }else{
                longest = max(longest,i-mpp[diff[i]]);
            }
        }
        return longest ;
    }
};
