class CustomStack {
public:
    vector<int>v;
    int sz;
    CustomStack(int maxSize) {
        sz=maxSize;
    }
    
    void push(int x) {
        if(v.size()<sz)v.push_back(x);
    }
    
    int pop() {
        if(v.empty())return -1;
        int x=v.back();
        v.pop_back();
        return x;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<k and i<v.size(); i++){
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */