// Code for solving dp problems using convex hull trick when slopes and queries are given in sorted order.
// Time Complexity - O(n + q) where n is the number of lines and q is the number of queries.

struct line
{
    int m, c;
 
    int getValue(int x)
    {
        return m*x + c;
    }
 
    double intersectionX(line l)
    {
        return (c - l.c + 0.0) / (l.m - m);
    }
};
 
void convexHullTrick()
{
    deque<line> dq;
 
    dq.pf(some initial line);
 
    for(int i=1; i<n; i++)
    {
        while(dq.size() >= 2 && dq.back().getValue(x[i]) >= dq[dq.size()-2].getValue(x[i]))
            dq.popb();
 
        int val = dq.back().getValue(x[i]) + constant;
        ans = val;
 
        line cur = {make line from this x[i]};
 
        while(dq.size() >= 2 && cur.intersectionX(dq[0]) <= dq[0].intersectionX(dq[1]))
            dq.popf();
 
        dq.pf(cur);
    }
 
    return;
}
