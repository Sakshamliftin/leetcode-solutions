using lli = long long ;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n  = height.size() ;
        int left = 0 ;
        int right  = n-1 ;
        lli ans= 0 ;
        while(left<right ){
            ans = max(ans, 1LL*(right -left)*min(height[left],height[right])) ;
            if(height[left]>height[right]){
                right-- ;
            }else{
                left++ ;
            }
        }

        return ans ;
    }
};