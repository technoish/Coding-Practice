class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        int maximum = INT_MIN, difference = 0, n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            maximum = max(maximum, nums[i]);
            if (i >= 2)
                ans = max(ans, (long long)difference * nums[i]);
            if (i >= 1)
                difference = max(difference, maximum - nums[i]);
        }

        return ans;
    }
};