class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end()) ;
        int st = intervals[0][0], end= intervals[0][1] ;
        vector<vector<int>>result ;
        for(int i=1;i<intervals.size();i++){
            int newst = intervals[i][0], newend=intervals[i][1] ;
            if(newst==st){
                end = max(end,newend) ;
            }else{
                if(newend<=end){
                    continue ;
                }else{
                    result.push_back({st,end}) ;
                    st = newst ;
                    end = newend ;
                }
            }
        }
        result.push_back({st,end}) ;
        return result.size() ;
    }
};