/// code for ntt 
const int mod = 998244353;// 
const int root = 565042129; // nth root of mod
const int root_1 = 950391366;// inverse of root
const int root_pw = 1<<20; // value of n (goes till 2**3 as 998244353-1==119*2**23)
struct NTT{ 
   void fft(int a[],bool invert,int n){
      int i,j;
       for(i=1,j=0;i<n;++i){
          int bit=n>>1;
          for(;j>=bit;bit>>=1){
             j-=bit;
          }
          j+=bit;
          if(i<j)swap(a[i],a[j]);
       }
       for(int len=2;len<=n;len<<=1){
          int wlen=invert?root_1:root;
           for(i=len;i<root_pw;i<<=1){
              wlen=(wlen*wlen%mod);
           }
        for(i=0;i<n;i+=len){
            int w=1;
            for(j=0;j<len/2;++j){
                int u=a[i+j],v=(int)(a[i+j+len/2]*w%mod);
                a[i+j]=(u+v+mod)%mod;
                a[i+j+len/2]=(u-v+mod)%mod;
                w=(w*wlen%mod);
            }
        }
    }
      if(invert){
        int nrev=xymodp(n,mod-2,mod);
        for(i=0;i<n;++i){
            a[i]=(a[i]*nrev%mod);
         }
      }
   }
  void multiply(const vector<int> &a,const vector<int> &b,vector<int> &res){
    vector<int> fa(a.begin(),a.end()),fb(b.begin(),b.end());
    size_t n=1;
    while(n<max(a.size(),b.size())) n<<=1;
    n<<= 1;
    fa.resize(n),fb.resize(n);
    fft(fa,false),fft(fb,false);
    for(size_t i=0;i<n;++i){
        fa[i]*=fb[i];
    }
    fft(fa,true);
    res.resize(n);
    for(size_t i=0;i<n;++i){
        res[i]=fa[i];
    }
 }
 void polyexpo(int a[],int n,int s){   
    fft(a,0,s);
    for(int i=0;i<s;i++)a[i]=xymodp(a[i],n,hell);
    fft(a,1,s);
 }
}ntt;
