class Solution
{
public:
    vector<int> nthRowOfPascalTriangle(int n)
    {
        vector<long long> fact(n);
        fact[0] = 1;
        for (int i = 1; i < n; i++)
        {
            fact[i] = fact[i - 1] * i;
        }
        vector<int> row(n);
        for (int k = 0; k < n; k++)
        {
            row[k] = fact[n - 1] / (fact[k] * fact[n - 1 - k]);
        }
        return row;
    }
};