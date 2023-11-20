#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int const N=100000;
vector<int>graph[N];
int ar[N];
int mod=1000000007;
signed main(){
        cout<<"S";
        map<string,string>is,ad,dl,reg,cc;
        map<string,int>mpsymind;
        map<string,vector<int>>mplitind;
        is["STOP"]="00";
        is["ADD"]="01";
        is["SUB"]="02";
        is["MULT"]="03";
        is["MOVER"]="04";
        is["MOVEM"]="05";
        is["COMP"]="06";
        is["BC"]="07";
        is["DLU"]="08";
        is["READ"]="09";
        is["PRINT"]="10";
        ad["START"]="01";
        ad["END"]="02";
        ad["EQU"]="04";
        ad["ORIGIN"]="03";
        ad["LTORG"]="05";
        dl["DS"]="01";
        dl["DC"]="02";
        reg["AREG"]="01";
        reg["BREG"]="02";
        reg["CREG"]="03";
        cc["EQ"]="01";
        cc["LT"]="02";
        cc["GT"]="03";
        cc["LE"]="04";
        cc["GE"]="05";
        cc["NE"]="06";
        cc["ANY"]="07";
        fstream inp,symtable,littable,pooltable,ic;
        inp.open("input.txt",ios::in);
        littable.open("lit.txt",ios::out);
        symtable.open("sym.txt",ios::out);
        pooltable.open("pooltable.txt",ios::out);
        int lc=0;
        int litcount=0;
        int poolind=0;
        int nooflit=0;
        string line;
        vector<string>vecsym;
        map<string,int>mpsym;
        vector<string>veclit;
        while(getline(inp,line)){
            if(line[0]==' '){
                vector<string>s;
                string dm="";
                for(int i=1;i<line.size();i++){
                    if((line[i]==' ' || line[i]==',')){
                        s.push_back(dm);dm="";
                    }
                    else dm+=line[i];
                }
                s.push_back(dm);
                // cout<<s[0]<<endl;
                if(s[0]=="START"){
                    lc=stoi(s[1]);
                }
                else if(s[0]=="LTORG"|| s[0]=="END"){
                    for(int i=0;i<veclit.size();i++){
                        mplitind[veclit[i]].push_back(litcount);
                        littable<<litcount<<" "<<veclit[i]<<" "<<lc<<endl;
                        lc++;
                        litcount++;
                    }
                    pooltable<<poolind<<" "<<nooflit<<endl;
                    poolind++;
                    nooflit=veclit.size();
                    veclit.clear();
                }
                else if(s[0]=="ORIGIN" ){
                    vector<string>s1;
                    string dm="";
                    for(auto c : s[1]){
                        if(c=='+'){
                            s1.push_back(dm);
                            s1.push_back("+");
                            dm="";
                        }
                        else if(c=='-'){
                            s1.push_back(dm);
                            s1.push_back("-");
                            dm="";
                        }
                        else dm+=c;
                    }
                    if(s1.size()==0){
                        lc=mpsym[s1[0]];
                    }
                    else{
                        if(s1[1]=="+"){
                            lc=mpsym[s1[0]]+stoi(s1[2]);
                        }
                        else{
                            lc=mpsym[s1[0]]+stoi(s1[2]);
                        }
                    }
                }
                else{
                    if(s[s.size()-1][0]=='='){
                        veclit.push_back(s[s.size()-1]);
                    }
                    else{
                        if((find(vecsym.begin(),vecsym.end(),s[s.size()-1])==vecsym.end())and s.size()>1) vecsym.push_back(s[s.size()-1]);
                    }
                    lc++;
                }
            }
            else{
                vector<string>s;
                string dm="";
                for(auto c: line){
                    if((c==' ' || c==',')){
                        s.push_back(dm);dm="";
                    }
                    else dm+=c;
                }
                s.push_back(dm);
                if(find(vecsym.begin(),vecsym.end(),s[0])==vecsym.end()) vecsym.push_back(s[0]);
                if(s[1]=="EQU"){
                    vector<string>s2;
                    string dm1="";
                    for(auto c : s[2]){
                        if(c=='+'){
                            s2.push_back(dm1);
                            // cout<<dm1<<" "<<c<<endl;
                            s2.push_back("+");dm1="";
                        }
                        else if(c=='-'){
                            s2.push_back(dm1);
                            cout<<dm1<<" "<<c<<endl;
                            s2.push_back("-");dm1="";
                        }
                        else dm1+=c;
                    }
                    s2.push_back(dm1);
                    if(s2.size()==1){
                        mpsym[s[0]]=mpsym[s[2]];
                    }
                    else{
                        if(s2[1]=="+"){
                            mpsym[s[0]]=mpsym[s2[0]]+stoi(s2[2]);
                        }
                        else{
                            mpsym[s[0]]=mpsym[s2[0]]-stoi(s2[2]);
                        }
                    }
                }
                else if(s[1]=="DS"){
                    mpsym[s[0]]=lc;
                    lc=lc+stoi(s[s.size()-1]);
                }
                else if(s[1]=="DC"){
                    mpsym[s[0]]=lc;
                    lc++;
                }
                else{
                    mpsym[s[0]]=lc;
                    if(s[s.size()-1][0]=='='){
                        veclit.push_back(s[s.size()-1]);
                    }
                    else{
                        if(find(vecsym.begin(),vecsym.end(),s[s.size()-1])==vecsym.end()) vecsym.push_back(s[s.size()-1]);
                    }
                    lc++;
                }
            }
        }
        for(int i=0;i<vecsym.size();i++){
            mpsymind[vecsym[i]]=i;
            symtable<<i<<" "<<vecsym[i]<<" "<<mpsym[vecsym[i]]<<endl;
        }
        inp.close();
        littable.close();
        symtable.close();
        pooltable.close();
        // inp.open("input.txt",ios::in);
        // ic.open("ic.txt",ios::out);
        // string put="     ";
        // vector<string>pic;
        // while(getline(inp,line)){
        //     vector<string>pic;
        //     pic.push_back(put);
        //     pic.push_back(put);
        //     pic.push_back(put);
        //     if(line[0]==' '){
        //         vector<string>s;
        //         string dm="";
        //         for(int i=1;i<line.size();i++){
        //             if((line[i]==' ' || line[i]==',')){
        //                 s.push_back(dm);dm="";
        //             }
        //             else dm+=line[i];
        //         }
        //         s.push_back(dm);
        //         if(s[s.size()-1][0]=='=') veclit.push_back(s[s.size()-1]);
        //         if(s[0]=="LTORG" || s[0]=="END"){
        //             for(int i=0;i<veclit.size();i++){
        //                 string xy="";
        //                 for(int y=2;y<veclit[i].size()-1;y++){
        //                     xy+=veclit[i][y];
        //                 }
        //                 ic<<"(DL,02) (C,"<<xy<<")"<<endl;;
        //             }
        //             veclit.clear();
        //         }
        //         else{
        //             for(int i=0;i<s.size();i++){
                        
        //                 if(is.find(s[i])!=is.end()){
        //                     // cout<<s[i]<<" ";
        //                     pic[0]="(IS,"+is[s[i]]+")";
        //                 }
        //                 else if(ad.find(s[i])!=ad.end()){
        //                     pic[0]="(AD,"+ad[s[i]]+")";
        //                 }
        //                 else if(reg.find(s[i])!=reg.end()){
        //                     // cout<<s[i]<<" ";
        //                     pic[1]="(REG,"+reg[s[i]]+")";
        //                 }
        //                 else if(cc.find(s[i])!=cc.end()){
        //                     // cout<<s[i]<<" ";
        //                     pic[1]="(CC,"+cc[s[i]]+")";
        //                 }
        //                 else if(mpsymind.find(s[i])!=mpsymind.end()){
        //                     string ye=to_string(mpsymind[s[i]]);
        //                     pic[2]="(S,"+ye+")";
        //                 }
        //                 else if(mplitind.find(s[i])!=mplitind.end()){
        //                     string ye=to_string(mplitind[s[i]][0]);
        //                     pic[2]="(L,"+ye+")";
        //                     mplitind[s[i]].erase(mplitind[s[i]].begin());
        //                 }
        //             }
                    
        //             if(s[0]=="START"){
        //                 pic[1]="(C,"+s[1]+")";
        //             }
        //             for(int y=0;y<3;y++){
        //                 if(pic[y]==put and y==2) break;
        //                 ic<<pic[y]<<" ";
        //             }
        //             // cout<<endl;
        //             ic<<endl;
                    
                    
        //         }
                
                
        //     }
        //     else{
        //         vector<string>s;
        //         string dm="";
        //         for(auto c: line){
        //             if((c==' ' || c==',')){
        //                 s.push_back(dm);dm="";
        //             }
        //             else dm+=c;
        //         }
        //         s.push_back(dm);
        //         if(s[1]=="EQU"){
        //             // cout<<mpsym[s[0]]<<endl;
        //             pic[0]="(AD,"+ad[s[1]]+")";
        //             string ye=to_string(mpsym[s[0]]);
        //             pic[1]="(C,"+ye+")";
        //             for(int y=0;y<3;y++){
        //                 if(pic[y]==put and y==2) break;
        //                 ic<<pic[y]<<" ";
        //             }
        //             ic<<endl;
        //         }
        //         else if(s[1]=="DS" || s[1]=="DC"){
        //             pic[0]="(DL,"+dl[s[1]]+")";
        //             pic[1]="(C,"+s[2]+")";
        //             for(int y=0;y<3;y++){
        //                 if(pic[y]==put and y==2) break;
        //                 ic<<pic[y]<<" ";
        //             }
        //             ic<<endl;
        //             // cout<<pic[0]<<" "<<pic[1]<<endl;
        //         }
        //         else{
        //             for(int i=1;i<s.size();i++){
        //                 if(is.find(s[i])!=is.end()){
        //                     pic[0]="(IS,"+is[s[i]]+")";
        //                 }
        //                 else if(ad.find(s[i])!=ad.end()){
        //                     pic[0]="(AD,"+ad[s[i]]+")";
        //                 }
        //                 else if(reg.find(s[i])!=reg.end()){
        //                     pic[1]="(REG,"+reg[s[i]]+")";
        //                 }
        //                 else if(cc.find(s[i])!=cc.end()){
        //                     pic[1]="(+CC,"+cc[s[i]]+")";
        //                 }
        //                 else if(mpsymind.find(s[i])!=mpsymind.end()){
        //                     string ye=to_string(mpsymind[s[i]]);
        //                     pic[2]="(S,"+ye+")";
        //                 }
        //                 else if(mplitind.find(s[i])!=mplitind.end()){
        //                     string ye=to_string(mplitind[s[i]][0]);
        //                     pic[2]="(L,"+ye+")";
        //                     mplitind[s[i]].erase(mplitind[s[i]].begin());
        //                 }
        //             }
        //         // cout<<pic[0]<<" "<<pic[1]<<endl;
        //             for(int y=0;y<3;y++){
        //                 if(pic[y]==put and y==2) break;
        //                 ic<<pic[y]<<" ";
        //             }
        //             ic<<endl;
        //         }
        //     }
        // }
        // inp.close();
        // ic.close();
    return 0;
}