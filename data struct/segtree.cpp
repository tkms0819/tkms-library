/*
seg(int N) 長さNのセグ木を作成
seg(vec<int>v)配列でセグ木を作成
act(int i)配列のi番目にアクセス
up(int i T x)配列のi番目を更新
out(int l,int r)l以上r未満の区間の値を出力
*/
#include <bits/stdc++.h>
template<typename T>
struct seg{
    int N;
    vector<T>V;

    //関数f
    T f(T a,T b){
        return a+b;
    }

    //単位元e
    T e=0;

    int makeN(int n){
        int t=1;
        while(t<n){
            t*=2;
        }
        return t;
    }

    //長さだけ
    seg(int n){
        N=makeN(n);
        V.resize(N*4);
    }

    //配列込み
    seg(vector<T>v){
        N=makeN(v.size());
        V.resize(N*2);
        for(int i=0;i<(int)v.size();i++)V[i+N-1]=v[i];
        for(int i=N-2;i>=0;i--){
            V[i]=f(V[i*2+1],V[i*2+2]);
        }
    }

    //アクセス
    T act(int i){
        return(V[i+N-1]);
    }
    //更新
    void up(int i,T x){
        i+=N-1;
        V[i]=x;
        while(i>0){
            i=(i-1)/2;
            V[i]=f(V[i*2+1],V[i*2+2]);
        }
    }

    //区間出力
    T out(int l,int r){return sum(l,r,0,0,N);}
    T sum(int l,int r,int k,int a,int b){
        if(r<=a||b<=l){
            return e;
        }
        if(l<=a&&b<=r){
            return V[k];
        }
        T nl=sum(l,r,k*2+1,a,(a+b)/2);
        T nr=sum(l,r,k*2+2,(a+b)/2,b);
        return f(nl,nr);
    }
};
