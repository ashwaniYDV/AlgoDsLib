//Find the nearest greater numbers on left side in an array (NSL)

vector<int> big_to_left(vector<int> const &input)
{
    int n = input.size();
    vector<int> result(n, -1);
 
    stack<int> s;

    for (int i = 0; i <n ; i--)
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
