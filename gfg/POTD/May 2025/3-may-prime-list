class Node
{
public:
    int val;
    Node *next;
    Node(int num)
    {
        val = num;
        next = NULL;
    }
};

class Solution
{
public:
    Node *primeList(Node *head)
    {
        int m = 0;
        for (auto p = head; p; p = p->next)
            m = max(m, p->val);
        vector<char> s(2 * m + 1, 1);
        s[0] = s[1] = 0;
        for (int i = 2; i * i <= 2 * m; ++i)
            if (s[i])
                for (int j = i * i; j <= 2 * m; j += i)
                    s[j] = 0;
        for (auto p = head; p; p = p->next)
        {
            int num = p->val, d = 0;
            while (1)
            {
                if (num - d > 1 && s[num - d])
                {
                    p->val = num - d;
                    break;
                }
                if (num + d <= 2 * m && s[num + d])
                {
                    p->val = num + d;
                    break;
                }
                ++d;
            }
        }
        return head;
    }
};