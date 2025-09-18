class StockSpanner {
public:
    stack<pair<int,int>> st; // st(price,index)
    int index;
    StockSpanner() {
        index=-1;
    }
    
    int next(int price) {
        index+=1;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        int ans;
        if(st.empty()){
            ans=index+1;
        }else ans=index-st.top().second;
    st.push({price,index});
    return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */