//Find the nearest greater numbers on right side in an array (NGR)

vector<int> big_to_right(vector<int> const &input)
{
    int n = input.size();
    vector<int> result(n, -1);
 
    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!s.empty())
        {
            // pop elements that aren't greater than the current element
            if (s.top() > input[i]) {
                result[i] = s.top();
                break;
            }
            else {
                s.pop();
            }
        }
        s.push(input[i]);
    }
 
    return result;
}
