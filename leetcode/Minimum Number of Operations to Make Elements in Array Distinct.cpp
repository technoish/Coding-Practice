class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int oper = 0;

        while (true)
        {
            unordered_set<int> unique(nums.begin(), nums.end());
            if (unique.size() == nums.size())
            {
                break;
            }

            if (nums.size() <= 3)
            {
                nums.clear();
            }
            else
            {
                nums.erase(nums.begin(), nums.begin() + 3);
            }

            oper++;
        }

        return oper;
    }
};