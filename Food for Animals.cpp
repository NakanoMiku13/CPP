#include<bits/stdc++.h>
using namespace std;
auto main()->int{
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long int a,b,c,x,y,n;
    cin>>n;
    for(auto i=0;i<n;i++){
        cin>>a>>b>>c>>x>>y;
        //dogs x
        //cats y
        int counter=0;
        if(a>=x and b>=y) cout<<"YES\n";
        else if((x+y)<=c) cout<<"YES\n";
        else if(x==0 and y==0 and a==0 and b==0 and c==0) cout<<"YES\n";
        else if(a==0 and b==0 and c==0 or (x==0 and y==0)) cout<<"NO\n";
        else{
            //dogs
            x-=a;
            if(x<=0) counter++;
            else{
                //using general food
                if(c>=x){
                    c-=x;
                    x=0;
                    counter++;
                }
            }
            //cats
            y-=b;
            if(y<=0) counter++;
            else{
                //using general food
                if(c>=y){
                    y=0;
                    c=0;
                    counter++;
                }
            }
            if(counter==2) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}