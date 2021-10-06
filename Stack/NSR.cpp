//Find the nearest smaller numbers on right side in an array (NSR)

vector<int> small_to_right(vector<int> &A)
{
    int n= A.size();
    vector<int> ans(n,-1);
    stack<int> st;
    
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty())
        {
            if(st.top()< A[i])  
            {
                ans[i]=st.top();
                break;
            }
            else st.pop();   // keep deleting
        }
        st.push(A[i]);  
    }
    return ans;
}
