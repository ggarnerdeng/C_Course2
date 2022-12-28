#include <iostream>
#include <iomanip>
using namespace std;

void palindrome();
void diceGame(int a, int b);
string rollsSumToThis(int total, int x, int y);
int main(){
    //palindrome();
    diceGame(7,3);

    return 0;
}

void diceGame(int a, int b){
   int maxSum = a + b;
    for(int i = 2; i <= maxSum; i++){
        cout<<i<<" "<<rollsSumToThis(i,a,b)<<endl;
    }
}

string rollsSumToThis(int total, int x, int y){
    string pounds;
       for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if((i+j)==total){
                    pounds+="#";
                }
    }}

    return pounds;
}
void palindrome(){
    cout<<"Enter Palindrome to check for: ";
    string input,reverse;
    bool isPalindrome = true;
    getline(cin,input);

    for(int i = 0, j = input.length()-1; i <= input.length()-1; i++, j--){
        if(input.at(i)!=input.at(j)){
            cout<<"not a palindrome at I position: "<<i<<", and J position: "<<j<<endl;
            isPalindrome = false;
            break;
        }
    }
            cout<<"Loop finished: "<<isPalindrome;

}