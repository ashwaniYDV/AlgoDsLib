/// Union-find                                                 -    O (n)
/// Union-find using union by rank/size                        -    O (log n)


/// Union-find using union by rank/size and path compression   -    O (4) OR  O (log n)
///O (log n)
    int p[100001];
    int r[100001];
    void initialize(){
        for(int i=0;i<26;i++)
            p[i]=i,r[i]=0;
    }
    int find(int i){
        if (p[i]==i)
            return p[i];
        return p[i]=find(p[i]);
    }
    void Union(int a, int b) {
        a=find(a);
        b=find(b);
        if(a!= b)
        {
            if(r[a]<r[b])
                swap(a,b);
            p[b]=a;
            if(r[a]==r[b])
                r[a]++;
        }
    }
