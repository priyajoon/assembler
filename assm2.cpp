#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int const N=100000;
vector<int>graph[N];
int ar[N];
int mod=1000000007;
signed main(){
    map<string,string>lit,sym;
    fstream ltab,stab;
    ltab.open("lit.txt",ios::in);
    string l;
    while(getline(ltab,l)){
        vector<string>vs;
        string dm="";
        for(auto c : l){
            if(c==' '){
                vs.push_back(dm);dm="";
            }
            else{
                dm+=c;
            }
        }
        vs.push_back(dm);
        lit[vs[0]]=vs[2];
    }
    stab.open("sym.txt",ios::in);
    while(getline(stab,l)){
        vector<string>vs;
        string dm="";
        for(auto c : l){
            if(c==' '){
                vs.push_back(dm);dm="";
            }
            else{
                dm+=c;
            }
        }
        vs.push_back(dm);
        sym[vs[0]]=vs[2];
    }
    fstream ic,mc;
    mc.open("mc.txt",ios::out);
    ic.open("ic.txt",ios::in);
    while(getline(ic,l)){
        vector<string>vs;
        string dm="";
        int f=0;
        for(int i=0;i<l.size();i++){
            if(l[i]==')'){
                dm+=l[i];
                vs.push_back(dm);
                dm="";   
            }
            else if(l[i]=='('){
                if(dm.size()>1){
                    vs.push_back(dm);
                }
                dm="(";
            }
            else dm+=l[i];
        }
        string s1="";
        for(int i=1;i<=2;i++){
            s1+=vs[0][i];
        }
        string sb="";
        
        if(s1=="AD"){
            mc<<endl;
        }
        else if(s1=="DL"){
            string s2="";
            for(int i=vs[1].size()-2;i>=0;i--){
                if(vs[1][i]==',') break;
                else s2=vs[1][i]+s2;
            }
            mc<<"00 00 "<<s2<<endl;
        }
        else if(vs[0]=="(IS,00)") break;
        else{
            for(int i=0;i<vs.size();i++){
                if(i==0){
                    string s="";
                    s+=vs[0][4];
                    s+=vs[0][5];
                    mc<<s<<" ";
                }
                if(i==1){
                    // if(vs[1]=="       "){
                    //     mc<<"00"<<" ";
                    // }
                    // else{
                    //     string s=
                    // }
                    string s="";
                    s+=vs[1][vs[1].size()-3];
                    s+=vs[1][vs[1].size()-2];

                    if(s!="  ") mc<<s<<" ";
                    else mc<<"00"<<" ";
                }
                if(i==2){
                    string s="";
                    s+=vs[2][vs[2].size()-2];
                    if(vs[2][1]=='S'){
                        mc<<sym[s]<<endl;
                    }
                    else{
                        mc<<lit[s]<<endl;
                    }
                }
            }

        }
        
    }
    mc.close();
    ic.close();
    ltab.close();
    stab.close();
    return 0;
}