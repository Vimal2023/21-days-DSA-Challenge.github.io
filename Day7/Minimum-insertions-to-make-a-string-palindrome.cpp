/*
    Time Complexity: O(|str| ^ 2)
    Space Complexity: O(|str| ^ 2)

    Where |str| is the length of the given string 'str'.
*/

int minimumInsertionsHelper(vector<vector<int>> &lookUp, string &str, int start, int end)
{
    // Base case.
    if (start >= end)
    {
        return 0;
    }

    // If the ans for this subproblem exist.
    if (lookUp[start][end] != -1)
    {
        return lookUp[start][end];
    }

    int ans = 0;

    if (str[start] == str[end])
    {
        ans = minimumInsertionsHelper(lookUp, str, start + 1, end - 1);
    }
    else
    {
        int a = minimumInsertionsHelper(lookUp, str, start + 1, end);
        int b = minimumInsertionsHelper(lookUp, str, start, end - 1);

        ans = 1 + min(a, b);
    }

    // Storing the ans for further use.
    lookUp[start][end] = ans;

    return ans;
}

int minimumInsertions(string &str)
{
    int n = str.length();

    vector<vector<int>> lookUp(n, vector<int>(n, -1));

    return minimumInsertionsHelper(lookUp, str, 0, n - 1);
}



