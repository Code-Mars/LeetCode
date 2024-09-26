class MyCalendar {
public:
    map<int, int>map;
    bool book(int start, int end) {
        auto it= map.upper_bound(start);
        if(it==map.end()|| end<=it->second){
            map[end]=start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */