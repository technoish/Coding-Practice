void reverseArray(vector<int> &arr, int m)
{
    int n = arr.size();
    int s = m + 1;
    int e = n - 1;
    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}