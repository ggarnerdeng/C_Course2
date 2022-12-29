#include <iostream>
#include <vector>

using namespace std;

//References and Pointers
vector<int> squareAllElements(vector<int> v);
void cleanse(vector<int> vs);
void purge(vector<int>& vs);
void p4(int& a);
int main(){

    vector<int> v1 = {1,2,3,4,5,6,7,8,9};
    /*
    v1 = squareAllElements(v1);
    purge(v1);
    for(int e : v1)
        cout<<e<<" ";
*/
    int a = 12413;
   
    p4(a);
    cout<<"final a is "<<a;
    return 0;
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
void cleanse(vector<int> vs){
 vs.clear();

}
void purge(vector<int>& vs){
 vs.clear();

}
vector<int> squareAllElements(vector<int> v){
    for(int& e : v){
        e *= e;
    }
    return v;
}