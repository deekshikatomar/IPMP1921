class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int lks=0,curr=0,i=1;
        while(i<arr.size()){
            if(arr[i]<arr[curr]){
                i+=1; lks+=1;
                    if(lks==k) return arr[curr];
            }
            else{
                curr=i; i+=1; lks=1;
                    if(lks==k) return arr[curr];
            }
        }
        return arr[curr];
    }
};