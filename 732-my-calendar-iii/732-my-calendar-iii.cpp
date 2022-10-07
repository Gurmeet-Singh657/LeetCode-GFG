class MyCalendarThree {
public:
    map<int,int> arr;
    int maxi=1;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        arr[start]++;
        arr[end]--;
        int count=0;
        for(auto it:arr)
        {
           count+=it.second;
            maxi=max(maxi,count);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */