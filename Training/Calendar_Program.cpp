//Garner Deng
//Jan-3-2023
//Calender_Program.cpp returns the day of the week when given any input date, in m/d/yyyy format.

#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>

using namespace std;

void calendar(string input);
void drawMonth(int monthNum, int dayNum, int yearNum, string day);
void insertBlank(vector<string>& v, int blanks);
int day2num(string day);
string num2day(int num);

const int TEST_YEAR = 1924;   //Seed Year. Do not change.

bool MARK_DATE = false;       //Mark the date with "__".
bool CURRENT_YEAR = true;     //List all the months of the current year.
bool INPUT_ONLY = true;       //Only print the user input.

int main(){
    string input = "9/11/2001";

    if(INPUT_ONLY){
        MARK_DATE = true;
        cout<<"input M/D/YYYY: "<<endl<<"      ";
        getline(cin,input);
        calendar(input);
    }else{
        string testDates[] = {
        input,
        "2/25/1951",
        "2/26/1951",
        "2/27/1951",
        "2/28/1951",
        "2/29/1951",
        "13/1/1951",
        "5/31/1968",
        "2/28/1972",
        "8/9/1988",
        "3/1/1996",
        "5/26/2023",
        };
        
        if(!CURRENT_YEAR){
            for(string e : testDates)
            calendar(e);
        }else{
            time_t now = time(0);
            tm *ltm = localtime(&now);
            string currentYear1 = to_string(1900 + ltm->tm_year);
            vector<string> allMonths= {"1/1/","2/1/","3/1/","4/1/","5/1/","6/1/","7/1/","8/1/","9/1/","10/1/","11/1/","12/1/"};
            for(string& e : allMonths)
                e += currentYear1;
            for(string e : allMonths)
                calendar(e);
        }  
    }

    return 0;
}

//Finds day of the week given a date in M/D/YYYY format. Works for all dates past 1924
void calendar(string input){
    string answer, passed;
    int day,month,year,total,month2day,year2day;

    day = stoi(input.substr(input.find("/")+1,input.rfind("/")-input.find("/")-1));
    month = stoi(input.substr(0,input.find("/")));
    year = (stoi(input.substr(input.rfind("/")+1,input.length()-input.rfind("/")))-TEST_YEAR);

//False Leap Year Catcher. Also catches invalid input such as negative dates or dates that exceed month capacity. 
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

        vector<int> m2d = {0,0,31,59,90,120,151,181,212,243,273,304,334};
        month2day = m2d[month];
    
        cout<<endl<<month<<"-"<<day<<"-"<<year+TEST_YEAR<<"  "<<"The day is: "<<num2day((year2day +month2day + day) % 7);

        drawMonth(month,day,year+TEST_YEAR,num2day((year2day +month2day + 1) % 7));
    }
}

//Converts day Int into day String. Based on 1924 date.
string num2day(int total){
    vector<string> days = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    return days[total];
}

//Accepts a M/D/YYYY, and a Day input, and draws the Month in the console. 
void drawMonth(int monthNum, int dayNum, int yearNum, string day){
    string month;
    int daysInMonth,count = 0;
    vector<string> monthV;

    switch(monthNum){
        case 1: 
            month = "January";
            daysInMonth = 31;
            break;
        case 2: 
            month = "February";
            daysInMonth = (yearNum%4 == 0) ? 29 : 28;            
            break;
        case 3: 
            month = "March";
            daysInMonth = 31;            
            break;
        case 4: 
            month = "April";
            daysInMonth = 30;            
            break;
        case 5: 
            month = "May";
            daysInMonth = 31;            
            break;
        case 6: 
            month = "June";
            daysInMonth = 30;            
            break;
        case 7: 
            month = "July";
            daysInMonth = 31;            
            break;
        case 8: 
            month = "August";
            daysInMonth = 31;
            break;
        case 9: 
            month = "September";
            daysInMonth = 30;            
            break;
        case 10: 
            month = "October";
            daysInMonth = 31;            
            break;
        case 11: 
            month = "November";
            daysInMonth = 30;            
            break;
        case 12: 
            month = "December";
            daysInMonth = 31;            
            break;
    }

    //Draws month
    for(int i = 1; i < 1 + daysInMonth; i++){
        MARK_DATE ? (dayNum == i ? monthV.push_back("__") : monthV.push_back(std::to_string(i))) : (monthV.push_back(std::to_string(i)));
    }

    insertBlank(monthV, day2num(day));
    
    cout<<" "<<month<<"-"<<yearNum<<endl;

    for(int y = 0; y < 7; y++ ){
        for(int x = 0; x < 7; x++){
            cout.width(3);
            cout<<monthV.at(count)<<" ";
            count++;
            if(count==monthV.size())
                break;
        }
            if(count==monthV.size())
                break;
        cout<<endl;
    }
    cout<<endl;
}

//adds number of blank spaces to beginning of vector of strings, and then the day titles
void insertBlank(vector<string>& v, int blanks){
    string dayNames[] = {"Sa","F","Th","W","Tu","M","Su"};

    for(int i = 0; i < blanks; i++){
        v.insert(v.begin(), " ");
    }
    for(string e : dayNames){
        v.insert(v.begin(), e);
    }
}

//Converts day to num to find starting point for drawn calendar
int day2num(string day){
    vector<string> days = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

    for(int i = 0; i < days.size(); i++){
        if(day == days[i])
            return i;
    }
}