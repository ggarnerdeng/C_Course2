#include <iostream>
#include <vector>

using namespace std;

//References and Pointers
vector<int> squareAllElements(vector<int> v);
void cleanse(vector<int> vs);
void purge(vector<int>& vs);
void p4(int& a);
void swapInts(int& a, int& b);
void compareThenSwap(int& a, int& b);
void organizeVector(vector<int>& vs);

int main(){

    vector<int> v1 = {1,2,3,4,5,6,7,8,9};
    //vector<int> v2 = {9,8,7,6,5,4,3,2,1,11,12,13,454,2,3,4};
    vector<int> v2 = {4,3,2,1,100,5};

    /*
    v1 = squareAllElements(v1);
    purge(v1);
    for(int e : v1)
        cout<<e<<" ";

    int a = 12413;
    p4(a);
    cout<<"final a is "<<a;

    int a = 1;
    int b = 2;
    swapInts(a,b);
    cout<<a<<" "<<b;

    int a = 12;
    int b = 2;
    compareThenSwap(a,b);
    cout<<a<<" "<<b;
*/
    organizeVector(v2);
    //RANGED-BASED FOR LOOP:::
    for(int e : v2)
        cout<<" "<<e;
    
    return 0;
}

void organizeVector(vector<int>& vs){
    for(int i = 0; i < vs.size(); i++){
        for(int j = 0; j < (vs.size()-1-i); j++){
            int k = j + 1;
            compareThenSwap(vs.at(j),vs.at(k));
            //cout<<"j is: "<<j<<" and k is "<<k<<endl;
        }
    }
}

void compareThenSwap(int& a, int& b){
    if(a>b){
        swapInts(a,b);
    }
}

void swapInts(int& a, int& b){
    int temporary;
    temporary = a;
    a = b;
    b = temporary;
}


void p4(int& a){
     while(a!=1){
         if(a%2==0){
        a=a/2;
        cout<<a<<endl;
          }else{
        a = 3*a +1;
        cout<<a<<endl;
    }
     }
   
}

//Does not do anything, because "vs" is passed as a copy.
void cleanse(vector<int> vs){
 vs.clear();

}
//Actually clears, because the REFERENCE of "vs" is passed. 
void purge(vector<int>& vs){
 vs.clear();

}
vector<int> squareAllElements(vector<int> v){
    for(int& e : v){
        e *= e;
    }
    return v;
}

