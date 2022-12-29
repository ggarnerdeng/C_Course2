#include <iostream>
#include <cmath>

using namespace std;

void loopExercises();
void infiniteInput();
void drawTri();
void drawTri2();
void multTab();
void infLoop();
void palindrome();
void midterm1();
void switchCase();
void calendar(string input);
int main(){
//infiniteInput();
//loopExercises();
//drawTri();
//drawTri2();
// multTab();
// infLoop();
//palindrome();
//midterm1(); 2.0 + (0 && 1)

//cout<< (1 < 2 ? 2.0 : -2.0) + (3 >= 4 && 2 < 3 ? -3.0);

//switchCase();
/*for(int i = 0, j = 10; i < j; i++, j--)
 cout << i << " " << j << endl;

int i = 0;
int j = 10;

while(i<j){
 cout << i << " " << j << endl;
 i++;
 j--;
}*/
cout<<"input M/D/YYYY: ";
string input;
getline(cin,input);
calendar(input);
calendar("2/25/1951");
calendar("2/26/1951");
calendar("2/27/1951");
calendar("2/28/1951");
calendar("2/29/1951");
calendar("3/1/1951");
calendar("3/2/1951");
calendar("3/3/1951");
calendar("3/4/1951");

calendar("13/1/1951");
calendar("3/32/1951");
calendar("3/-3/1951");
calendar("-3/4/1951");


    return 0;
}


void infiniteInput(){ //converts to ASCII Dec. 10 is the code for ENTER
    cout<< "press a key"<<endl;
    char c;

    while(cin.get(c)){
        cout<< (int)(c) << " ";
    }
}

void loopExercises(){
    //1
    int i = 1;
    while(i<9){
        cout<<i<<endl;
        i++;
    }
    //2
    i = 1;
    while(i<10){
        cout<<i<<endl;
        i=i+2;
    }
    //3
    double j = 1.0;
    bool check = true;
    while(check){
        if(j>5.0){
            check = false;
        }
        cout<<j<<endl;
        j+=0.3;
    }
    //4
    i = 65;
    char c;
    while(i<91){
        c = i;
        cout<<c<<endl;
        i++;
    }
    //5
    i=0;
    while(i<8){
        cout<<pow(2,i)<<endl;
        i++;
    }
    //6
    i=100;
    check = true;
    while(check){
        if(i==0){
            check = false;
        }
        cout<<i<<endl;
        (i%2==0)?i=i/2:i=i-1;
    }
    //7
    i=0;
    int k =20;
    while(i<=20){
        if(i<=10){
            cout<<"i is "<<i<<endl;
        }
        if(k>=0){
            cout<<"k is "<<k<<endl;
        }
        i++;
        k--;
    }
    //8
    
}

void drawTri(){

    cout<<"input rows for triangle"<<endl;

    int rows,cols,mid,lead_blanks,mid_blanks,start;
    int i = 1;//minimum input

    cin>>rows;
    cols = rows*2-1;

    while(i<=rows){
        lead_blanks = rows - i;
        mid_blanks = (i-1)*2-1;
        start = 0;
        while(start<lead_blanks){
            cout<<" ";
            start++;
        }
        if(i==1){
            cout<<"*"<<endl;
        }else{//not first or last row
            cout<<"*";
            mid = 0;
            if(i!=rows){
                    while(mid<mid_blanks){
                                    cout<<" ";
                                    mid++;
                }
            }else{
                while(mid<mid_blanks){
                                    cout<<"*";
                                    mid++;
            }
            }       
            cout<<"*"<<endl;
        }
        i++;
    }
}

void drawTri2(){
    //instead of char by char printing, print whole-ass strings.
    int rows,row,check,mid;

    cout<<"input rows of triangle: ";
    cin>>rows;

    row = 1;
    while(row <= rows){
        check = rows-row;
        mid = (row-1)*2-1;
        if(row == 1){
            cout<<string(check,' ')<<"*"<<endl;
        }else{
            if(row!=rows){
                cout<<string(check,' ')<<"*"<<string(mid,' ')<<"*"<<endl;
            }else{
                cout<<string(check,' ')<<"*"<<string(mid,'*')<<"*"<<endl;
            }
        }
        row++;
    }
}

void multTab(){
    for(int y = 0;y<=10; y++){
        for(int x = 0;x<=10; x++){
            cout.width(4);
            cout<<x*y;
        }
        cout<<endl;
    }
}

void infLoop(){
    int x, prod = 1;
    while(cin >> x) {
    prod *= x;
    cout << "ans: "<<prod<<" NEXT INPT: ";
    if(x==0)
        break;
    }
}

void palindrome(){
    cout<<"enter palindrome to check";
    string input,reverse;
    getline(cin,input);
    for(char c : input)
        reverse = c + reverse;

    bool isPal = true;
    for(int i = 0; i<input.length();i++){
        if(input.at(i)!=reverse.at(i)){
             cout<<"not a palindrome at: "<<i;
             isPal=false;
             break;
        }
    }
    cout<<endl<<isPal<<input<<endl<<reverse;
}

void midterm1(){
    string data = "matt,scott,mark";
data.substr(data.find(",") + 1, (data.rfind(",") - 1) - (data.find(",") + 1) + 1);
//"matt,scott,mark"
//"0123456789"11 14
//data.substr(4+1,(10-1)-(4+1)+1                    )
//5,5
/*
replace middle name.

data.replace(start, length, content)

data.replace(   data.find(",")+1,           
                data.rfind(",")-1-(start),
                "content"  )
I might ask you to write an if-else chain to handle some set of conditions, possibly involving multiple
variables. E.g., write an if-else chain that will compare the two variables i and j and print “Less than” if i is
less than j , “Greater than” if i is greater than j , or “Equal” if they are equal. (Question: if we had three
variables, how many ways can they be arranged?)

if(i < j){
    cout<<"less than";
}else{
    if(i > j){
        cout<<"more than";
    }else{
        cout<<"Equal";
    }
}

cout <<( i < j ? "Less than" : "Greater Than" );

int i = 1;
int j = 2;
cout <<( i < j ? "Less than" : (i > j ? "Greater Than" : "Equal" ));
i = 3;
j = 2;
cout <<( i < j ? "Less than" : (i > j ? "Greater Than" : "Equal" ));
i = 2;
j = 2;
cout <<( i < j ? "Less than" : (i > j ? "Greater Than" : "Equal" ));

Area = 2 pi r
*/
}

void switchCase(){
    /*
    if(x == 0)
        cout << "OK";
    else if(x == 1 || x == 2)
        cout << "Getting warm";
    else if(x == 3)
        cout << "Hot";
    else
        cout << "Extreme conditions detected";

    CONVERT TO SWITCH CASE
    */

   cout<<"Input 0,1,2, or 3"<<endl;
   int input;
   cin >> input;

   switch(input){
    case 0:
        cout<<"OK"<<endl;
        break;
    case 1: 
    case 2: 
        cout<<"Getting Warmer"<<endl;
        break;
    case 3:
        cout<<"Hot"<<endl;
        break;
    default:
        cout<<"Extreme conditions detected"<<endl;
        break;
   }
}

void calendar(string userInput){
    //Works for all dates past 1924.
    string input,monthS,dayS,yearS,answer;
    int day,year,month,total,month2day,year2day;
    const int TEST_YEAR = 1924;

    input = userInput;

    monthS = input.substr(0,input.find("/"));
    dayS = input.substr(input.find("/")+1,input.rfind("/")-input.find("/")-1);
    yearS = input.substr(input.rfind("/")+1,input.length()-input.rfind("/"));

    day = stoi(dayS);
    month = stoi(monthS);
    year = (stoi(yearS)-TEST_YEAR);

//False Leap Year Catcher.
//Negative dates
//Positive dates
    if((year%4!=0&&month==2&&day>=29) ||
        year<0 || day < 1 || month < 1 || month > 12||
        ((month==1||month==3||month==5||month==7||month==8||month==10||month==12) && day > 31 ) ||
        ((month==4||month==6||month==9||month==11) && day > 30 )){    

        cout<<endl<<input<<" !ERROR: This date does not exist.";
    }else{
        year2day = year * 365 + year / 4 + 1;

        if(year%4==0&&month<3&&day<=29){//Leap year hasn't happened yet.
            year2day-=1;
        }

        month2day = 0;

        switch(month){
            case 1:
            month2day += 0;
                break;
            case 2:
            month2day += 31;
                break;
            case 3:
            month2day += 59;
                break;
            case 4:
            month2day += 90;
                break;
            case 5:
            month2day += 120;
                break;
            case 6:
            month2day += 151;
                break;
            case 7:
            month2day += 181;
                break;
            case 8:
            month2day += 212;
                break;
            case 9:
            month2day += 243;
                break;
            case 10:
            month2day += 273;
                break;
            case 11:
            month2day += 304;
                break;
            case 12:
            month2day += 334;
                break;
            default:
                break;
        }

    total = (year2day +month2day + day) % 7;

    switch(total){
        case 0: 
            answer = "Monday";
            break;
        case 1: 
            answer = "Tuesday";
            break;
        case 2: 
            answer = "Wednesday";
            break;
        case 3: 
            answer = "Thursday";
            break;
        case 4: 
            answer = "Friday";
            break;
        case 5: 
            answer = "Saturday";
            break;
        case 6: 
            answer = "Sunday";
            break;
    }
        cout<<endl<<month<<"-"<<dayS<<"-"<<yearS<<"-"<<"The day is: "<<answer;
    }

}