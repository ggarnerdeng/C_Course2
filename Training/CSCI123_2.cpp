#include <iostream>
#include <vector> //dynamic array
#include<fstream> //file manipulation

using namespace std;

vector<int> read_input(int n);
void makeEditFile();
void vectorProblem1(int a,int b,int c);
void vectorProblem2(vector<int> v);
void vectorProblem3(vector<int> v);
void doubleArrayPuzzle(int a, int b);
//void printDarray(int a[][]); THIS DOESNT WORK
//void printDarray(int a[][10]); THIS DOES?>?>? need to maintain rec shape

int main(){
    //VECTORS
        /*
        v.front()       Gives the first element of v
        v.back()        Gives the last element of v
        v.push_back(e)  Add another element e to the end of v
        v.pop_back()    Remove the last element of the vector
        v.empty()       Returns true if v ’s size is 0
        v.assign(s,e)   Set the size to s and then fill with e. clear + resize
        v.resize(n) .   Cuts or fills withdefault values
            v.resize(n, new_element); Fills with new_element
        v.size() Length of the vector, as an int
        v.at(pos) Extract/modify a single element
        */
    //vectorProblem1(1,2,3);
    //vector<int> v2 = {1,2,3,4,5,6,7,8};
    //vectorProblem2(v2);
    //vectorProblem3(v2);
    //vector<vector<int>> b(8, vector<int>(8)); //vector of vectors
    //accessing vector element: b.at(x).at(y) // for vectors. Empty vectors fill default.
//vector<int> vf(10); // Vector of size 10, all elements 0 (default)
//vector<float> vf(5,-1.0); // Vector of size 5, all elements -1.0

    //ARRAYS
    //int a[] = {1, 2, 3}; // Size determined from initial contents;
    //int b[3]; // No initial contents -> must specify size
    //accessing array element: a[x][y] // for arrays. Empty arrays have UNDEFINED elements
    //Looping over ALL elements of a container: 
    //  for(int v : values) cout<<v<<endl;
    doubleArrayPuzzle(4,7);
    return 0;
}
void doubleArrayPuzzle(int a, int b){
//Draw 3x3, 4x4, 5x5 grids with elements numbered sequentially. Given a particular x and y, how can we
//compute the i (index), written in each cell?

    int xy[a][b];
    int count = 0;
    for(int i = 0; i <= a-1; i++){
        for(int j = 0; j <= b-1; j++){
            xy[i][j]=count;
            count++;
        }
    }
        for(int i = 0; i <= a-1; i++){
            for(int j = 0; j <= b-1; j++){
                cout.width(3);
                cout<< xy[i][j] << " ";
            }
            cout<<endl;
        }
}
void vectorProblem3(vector<int> v){
    //Example: Without using size, write a loop which counts the number of elements in a vector
    vector<int> v2 = v;
    int count =0;
    while(!v2.empty()){
        v2.pop_back();
        count++;
    }
    cout<<"vector has this many elements: "<<count;
}
void vectorProblem2(vector<int> v){
    //input vector, reverses vector and print.
    for(int i = v.size()-1; i>=0;i--){
        cout<<v.at(i)<<endl;
    }
}

void vectorProblem1(int a, int b, int c){
    /*
Example: Prompt the user for three ints a, b, and c and then creates a vector that contains (in order) a copies of
a, b copies of b, and c copies of c, and then prints the size of the vector.
    */
   vector<int> v1;
   for(int i=0;i<a;i++){
    v1.push_back(a);
   }
    for(int i=0;i<b;i++){
    v1.push_back(b);
   }
    for(int i=0;i<c;i++){
    v1.push_back(c);
   }
   cout<<"vector size is: "<<v1.size()<<endl;
   for(int i=0; i<=v1.size()-1;i++)
   cout<<v1.at(i)<<endl;
}

vector<int> read_input(int n){
    vector<int> data;
    int e;

    while(cin>>e&&n!=0){
        data.push_back(e);
        n--;
    }

    return data;
}

 void makeEditFile(){
    cout<<"test";
    fstream file("myfile.txt", ios_base::in | ios_base::out | ios_base::app);
    file<<endl<<"test";
    file.close();
 }