class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        for (int num : nums)
        {
            if (num < k)
            {
                return -1;
            }
        }

        unordered_set<int> uniqueNums(nums.begin(), nums.end());
        vector<int> values(uniqueNums.begin(), uniqueNums.end());
        sort(values.rbegin(), values.rend());

        int operation = 0;

        for (int i = 0; i < values.size(); i++)
        {
            if (values[i] > k)
            {
                operation++;
            }
            else if (values[i] == k)
            {
                break;
            }
        }

        return operation;
    }
};