#include <iostream>
#include <cmath>
using namespace std;
//https://staffwww.fullcoll.edu/aclifton/courses/cs123/syllabus_11774_fa22.html
//week 1-3, String manipulation, Input/Output, for loop, while loop, if
void problem2();
void question1();
void question2();
void findAndReplace();
void compare2nums();
void compare2nums2();
void upper2lower();
void sumProductAverage();
void initials();
void replace1();
void insert1();
void problem1();
void problem1_2();
void menuSwitch();

int globalVariable = 1;
string teststring = "Testing this very long string";
int main(){
    //problem2();
    //question1();
    //findAndReplace();
   //compare2nums2();
   //upper2lower();
   //sumProductAverage();
   //initials();
   //replace1();
   //insert1();
   //problem1();
   //problem1_2();
   menuSwitch();
    return 0;
}

void problem2(){
    int input,output;
    cout<<"Enter the height in inches: "<<endl;
    cin>> input;
    output = 5280 *12 / input;
    cout<<"You would fit "<<output<<" times in one mile."<<endl;
}

void question1(){
    string s1 = "Hello";
    string s2 = "Goodbye";

    bool result = s1.size() > s2.size(); 
    cout<<"when comparing sizes, result is: "<<result<<endl;
    result = s1 > s2; 
    cout<<"wtf is this then: "<<result<<endl;
}

void question2(){
    char c = 101; // THIS IS AN ASCII CHAR OF 'e'
    char d = 'A';
    cout<<c<<endl<<d<<endl;
}

void findAndReplace(){
    string sentence,input2,input3,newSentence;
    char c;
    cout<<"Enter a sentence: \n";
    getline(cin, sentence);

    cout<<"Enter a WORD to REPLACE: \n";
    getline(cin, input2);

    cout<<"Enter replacement: \n";
    getline(cin, input3);
    //cin.get(c);
    cout<<"Checking if target exists in input... \n";

    int location = sentence.find(input2);
    if(location == string::npos){
        cout<<"not found"<<endl;
    }else{
        cout<<location<<" IS THE TARGET LOCATION."<<endl;
    //This very bad
    //0123456789
        int a = location+input2.length();
        newSentence = sentence.substr(0,location)+input3+sentence.substr(a,sentence.length()-a);
        cout<<endl<<newSentence;
    }
}

void compare2nums(){
    float n1,n2;
    cout<<"enter 2 numbers: \n";
    cin>>n1>>n2;
    if(n1>n2){
        cout<<"the bigger num is: "<<n1;
    }else{
        cout<<"the bigger num is: "<<n2;
    }
}

void compare2nums2(){
    float n1,n2;
    cout<<"enter 2 numbers: \n";
    cin>>n1>>n2;

    float high = n1>n2?n1:n2;
    float low = n1<n2?n1:n2;
    /*
    A ? B : C 
        conditional operator. IF expression A is true, pick B. Else pick C. 
    */
   cout<<"high is "<<high<<endl<<"low is "<<low;
}

void upper2lower(){
    int noHardCodes = 'A'-'a'; //would give u a negative 32. u want positive tho
    char c,d;
    cout<<"enter an upper case letter:\n";
    cin>>c;
    d = c - noHardCodes;
    cout<<"Lower case is "<<d;
}

void sumProductAverage(){
    float n1,n2,n3,sum,product,average;
    cout<<"Enter 3 numbers\n";
    cin>>n1>>n2>>n3;
    
    sum = n1 + n2 +n3;
    product = n1 * n2 * n3;
    average = sum / 3.0;
    cout<< "sum is: "<<sum<<endl<<"product is: "<<product<<endl<<"average is: "<<average;
}

void initials(){
string input,first,middle,last;
int p1,p2;
char a,b,c;
//Garner Gao Deng
//0123456789
cout<<"Enter your FULL name, FIRST, MIDDLE, LAST \n";
getline(cin, input);
p1 = input.find(' ')+1;
p2 = input.rfind(' ')+1;

first=input.substr(0,p1);
middle=input.substr(p1,p2-p1);
last=input.substr(p2,input.length());

a = input.at(0);
b = input.at(p1);
c = input.at(p2);
cout<<"0123456789"<<endl;
cout<<"first: "<<first<<endl;
cout<<"middle: "<<middle<<endl;
cout<<"last: "<<last<<endl;
cout<<"positions are: "<<endl<<p1<<endl<<p2<<endl;
cout<<"initials are: "<<endl<<a<<endl<<b<<endl<<c;
}

void replace1(){
    string s1 = "Testing this very long string"; 
    //Testing this very long string
    //0123456789
    s1.replace(8,4,"a very very and finally");
    cout<<s1;
}

void insert1(){
     string s1 = "Testing this very long string"; 
    //Testing this very long string
    //0123456789
    s1.insert(20,"a very very and finally");
    cout<<s1;
}

void problem1(){
    float n1,n2,sum,product,smaller;
    cin>>n1>>n2;
    sum = n1+n2;
    product = n1*n2;
    cout<<"sum, product "<<sum<<" "<<product<<endl;

    smaller = sum < product ? sum : product;

    cout<<"smaller is "<<smaller;
}

void problem1_2(){
    //given a and b, find c, the hypotenuse
    float a,b,c;
    cin>>a>>b;
    cout<<"a and b are: "<<a<<" "<<b<<endl;
    c = sqrt(a*a+b*b);
    cout<<"c is: "<<c;
}

void menuSwitch(){
    bool cont;
    char c;
    while(!cont){
        cout<<"Enter 1,2, or q to quit.\n";
        cin>>c;
        switch(c){
            case '1': 
                cout<<"1 was pressed. Trying again.\n";
                break;
            case '2':
                cout<<"2 was pressed. Trying again.\n";
                break;
            case 'q':
                cout<<"q was pressed. Exiting.\n";
                cont = true;
                break;
            default:
                cout<<"INCORRECT INPUT Trying again.\n";
        }
    }
}