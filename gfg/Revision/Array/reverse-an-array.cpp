class Solution
{
public:
    void reverseArray(vector<int> &arr)
    {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }
};