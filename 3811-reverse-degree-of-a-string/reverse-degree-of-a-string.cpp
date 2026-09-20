class Solution {
public:
    int reverseDegree(string s) {
        int res = 0 ;
        for(int i=1;i<=s.size();i++){
            res+= (26-(s[i-1]-'a'))*i ;
        }
        return res ;
    }
};