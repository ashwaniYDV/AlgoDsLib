Find the nearest smaller numbers on left side in an array (NSL)

 vector<int> small_to_left(vector<int> &A)
{
    int n= A.size();
    vector<int> ans(n,-1);
    stack<int> st;
    
    for(int i=0;i<n;i++)
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
