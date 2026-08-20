class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>odd,even ;
        if(nums.size()<=2) return nums ;

        odd.push_back(nums[1]) ; even.push_back(nums[0]) ;

        for(int i=2;i<nums.size();i++){
            if(even.back()>odd.back()){
                even.push_back(nums[i]) ;
            }else{
                odd.push_back(nums[i]) ;
            }
        }

       vector<int>result ;
       reverse(even.begin(),even.end()) ;
       while(!even.empty()){
        int el = even.back() ;
        even.pop_back() ;
        result.push_back(el) ;
       }
       reverse(odd.begin(),odd.end()) ;
       while(!odd.empty()){
        int el = odd.back() ;
        odd.pop_back() ;
        result.push_back(el) ;
       }
        return result ;
       
    }
};