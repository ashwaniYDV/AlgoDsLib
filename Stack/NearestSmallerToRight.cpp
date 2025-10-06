#include <bits/stdc++.h>
using namespace std;

vector<int> small_to_right(vector<int> const &input)
{
    int n = input.size();
    vector<int> result(n, -1);
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty())
        {
            if (s.top() < input[i]) {
                result[i] = s.top();
                break;
            } else {
                s.pop();
            }
        }
        s.push(input[i]);
    }
    return result;
}

int main()
{
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = small_to_right(arr);
    for (int x : ans) cout << x << " ";
}
