class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int, vector<int>, greater<int>> minh;
        int n=arr.size();
        int j=0;
        for(int i=0;i<n;i++){
            minh.push(arr[i]);
            if(minh.size()>k){
                arr[j]=minh.top();
                j++;
                minh.pop();
            }
        }
        while(minh.size()>0){
            arr[j]=minh.top();
            minh.pop();
            j++;
        }
    }
};