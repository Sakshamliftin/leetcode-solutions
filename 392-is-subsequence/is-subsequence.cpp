class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i= 0 ; 
        int j = 0 ;
        int cnt = s.size() ;
        int fnd =0 ;
        while(i<s.size()&&j<t.size()){
            if(s[i]==t[j]){
                fnd++ ;
                i++;j++ ;
            }
            else{
                j++ ;
            }
        }

        return fnd==cnt ;
    }
};