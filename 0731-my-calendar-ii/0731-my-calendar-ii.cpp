class MyCalendarTwo {
public:
    map<int, int>map;
    bool book(int start, int end) {
        map[start]++;
        map[end]--;
        int booked=0;
        for(auto [k, v]:map){
            booked+=v;
            if(booked>=3){
                map[start]--;
                map[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */