int solve(vector<int> &arr, int s, int e, int target){
    if(s > e){
        return -1;
    }

    int mid = s + (e - s)/2;

    if(arr[mid] == target){
        return mid;
    }

    if(arr[mid] < target){
        return solve(arr, mid + 1, e, target);
    }
    else{
        return solve(arr, s, mid - 1, target);
    }
}
int search(vector<int> &nums, int target) {
    return solve(nums, 0, nums.size() - 1, target);
}