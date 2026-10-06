class MyCalendarTwo {
public:
    map<int,int> events ;
    MyCalendarTwo() {
    }
    
    bool book(int startTime, int endTime) {
        events[startTime]++ ;
        events[endTime]-- ;
        int curr = 0 ;
        int ans =0  ;

        for(auto event :events){
            curr+= event.second ;
            if(curr>2) {
                events[startTime]-- ;
                events[endTime]++ ;
                curr-= event.second ;
                return false ;
            }
            if(curr>ans){
                ans = curr ;
            
            }
        }
        return true ;
            
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */