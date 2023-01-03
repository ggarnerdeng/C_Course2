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

int* min(int* a, int* b);

int main(){

    vector<int> v1 = {1,2,3,4,5,6,7,8,9};

    /*
    v1 = squareAllElements(v1);
    purge(v1);
    for(int e : v1)
        cout<<e<<" ";

    int a = 12413;
    p4(a);
    cout<<"final a is "<<a;

    //SWAPING ANY INTS A AND B
    int a = 1;
    int b = 2;
    swapInts(a,b);
    cout<<a<<" "<<b;

    //SWAPPING LOWER<BIGGER INTS
    int a = 12;
    int b = 2;
    compareThenSwap(a,b);
    cout<<a<<" "<<b;

    //RANGED-BASED FOR LOOP:::
    vector<int> v2 = {4,3,2,1,100,5};
    organizeVector(v2);
    for(int e : v2)
        cout<<" "<<e;

    int a = 1;
    int* b = &a;
    cout<<a<<endl<<b<<endl<<*b;
*/
    //int* = "Pointer to an integer"
    //&a = "Pointer of a"(address of a??)
    //b = b holds the memory address of a.
    //Default value of pointer is nullptr, null pointer. Dangerous to use, so check with if(b)
    //*b = a :What is at this address b
    //&b = int** Pointer TO Pointer to int.
    //PRE* means removing layer of pointer to. PRE& adds ANOTHER LAYER
    /*POINTER TO ARRAYS:
        int data[5];
        int* p = &data[1];
        int* q = data + 1; // same thing

    FOR VECTORS:
        For a vector, you have to use
        vector<int> values(10);
        int* r = &values.at(1);

    ONLY USE POINTERS ON CONTAINERS THAT WONT CHANGE SIZEES
    POINTER USAGE: modify memory address's contents directly.

    vector<int> v = {1,3, 1, 2, 3, 5};
    int* p = &v.at(0);
    cout<<"p is: "<<p<<" *p deref "<<*p<<endl;
    ++p;
    cout<<"p is: "<<p<<" *p deref "<<*p<<endl;
    *p = 132;
    cout<<"p is: "<<p<<" *p deref "<<*p<<endl;
    for(int e : v)
        cout<<" "<<e;
    
    FIND AND RETURN ADDRESS OF TARGET ELEMENT IN VECTOR:
        int* find(vector<int> data, int target) {
            for(int i = 0; i < data.size(); i++)
                if(data.at(i) == target)
                    return &(data.at(i));
            return nullptr;

    RANGED LOOP ALTERNATIVE::
    int& = modify element DIRECTLY. OTHEERWISE e WILL come from different scope.
    &e = address.
        int* find(vector<int> data, int target) {
            for(int& e : data)
                if(e == target)
                    return &e;
            return nullptr;

    POINTER TO FUNCTION:
        Creates a "vague" pointer to function.

                    int add(int a, int b) {
                        return a + b;
                        }
                    int subtract(int a, int b) {
                        return a - b;
                        }
            int main() {
                cout << "Enter two numbers: ";
                int a,b;
                cin >> a >> b;
                cout << "Do you want to add or subtract (a/s)? ";
                char choice;
                cin >> choice;
                
                int (*operation)(int,int) = (choice == 'a' ? &add : &subtract);
                cout << "The result is " << operation(a,b) << endl;
                return 0;
            }
            }
            }


*/
    int a = 100, b = 2;
    int* c = &a;
    int* d = &b;
    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<endl<<min(c,d)<<endl;
    *min(c,d)= 132;
    cout<<a<<endl<<b<<endl;

    return 0;
}

int* min(int* a, int *b) {
 return *a < *b ? a : b;
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

