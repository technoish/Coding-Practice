bool isPossible(vector<int> boards, int n, int k, int mid){
    int painterCount = 1;
    int boardSum = 0;

    for(int i = 0; i < n; i++){
        if(boardSum + boards[i] <= mid){
            boardSum += boards[i];
        }
        else{
            painterCount++;
            if(painterCount > k || boards[i] > mid){
                return false;
            }
            boardSum = boards[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int s = 0;
    int sum = 0;

    for(int i = 0; i < n; i++){
        sum += boards[i];
    }

    int e = sum;
    int ans = -1;

    if(k > n) return -1; 
    
    while(s <= e){
        int mid = s + (e - s)/2;
        if(isPossible(boards, n, k, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
};