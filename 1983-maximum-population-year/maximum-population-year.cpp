class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>mpp ;

        for(auto log:logs){
            mpp[log[0]]++ ;
            mpp[log[1]]-- ;
        }

        int curr = 0  ; 
        int maxpop= 0 ; 
        int minyear = INT_MAX ;

        for(auto it:mpp){
            curr+= it.second ;
            if(curr>maxpop){
                maxpop = curr ;
                minyear = it.first;
            }
        }

        return minyear ;
    }
};