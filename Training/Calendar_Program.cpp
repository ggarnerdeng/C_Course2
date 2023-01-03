//Garner Deng
//Jan-3-2023
//Calender_Program.cpp returns the day of the week when given any input date, in m/d/yyyy format.

#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>


using namespace std;

void calendar(string input);
void drawMonth(string input);
void insertBlank(vector<string>& v, int blanks);
int day2num(string day);

int main(){
    string input = "9/11/2001";

    cout<<"input M/D/YYYY: "<<endl;
        
    drawMonth(input);

    //getline(cin,input);
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
    drawMonth("yes");

    return 0;
}

//Finds day of the week given a date in M/D/YYYY format. Works for all dates past 1924
void calendar(string userInput){
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

//Accepts a M/D/YYYY, and a Day input, and draws the Month in the console. 
void drawMonth(string input){
    //8/1/2017 was a Tuesday, so Sun/M are blank. 
    input = "yes";
    string month = "August";
    string day = "Tuesday";
    string year = "2017";
    int augDays = 31;
    int count = 0;
    bool pushed = false;
    vector<string> monthV;

    for(int i = 1; i<32;i++){
        monthV.push_back(std::to_string(i));
    }

    insertBlank(monthV, day2num(day));
    
    cout<<endl<<month<<"-"<<year<<endl;

    for(int y = 0; y < 6; y++ ){
        for(int x = 0; x < 7; x++){
            cout.width(3);
            cout<<monthV.at(count)<<" ";
            count++;
            if(count==monthV.size()){
                break;
            }
        }
            if(count==monthV.size()){
                break;
            }
        cout<<endl;
    }
}

//adds number of blank spaces to beginning of vector of strings. 
void insertBlank(vector<string>& v, int blanks){
    string blank = " ";
    for(int i = 0; i < blanks; i++){
        v.insert(v.begin(), blank);
    }
}

int day2num(string day){
    if(day=="Sunday"){
        return 0;
    }else if(day=="Monday"){
        return 1;
    }else if(day=="Tuesday"){
        return 2;
    }else if(day=="Wednesday"){
        return 3;
    }else if(day=="Thursday"){
        return 4;
    }else if(day=="Friday"){
        return 5;
    }else if(day=="Saturday"){
        return 6;
    }
}
