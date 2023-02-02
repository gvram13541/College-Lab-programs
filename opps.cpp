// program 1:

#include <iostream>
using namespace std;
void copyString(){
    int i = 0;
    char str1[100];
    char str2[100];
    cout << "ENTER THE STRING-1\n";
    cin >> str1;
    while(str1[i] != '\0'){
        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';
    cout << "ENTERED STRING IS: " << str1 << endl;
    cout << "COPYED STRING IS: " <<  str2 << endl;
}

int strLen(char str[]){
    int len = 0;
    while(str[len] != '\0'){
        len++;
    }
    return len;
}

void concatString(){
    char str1[100];
    char str2[100];
    cout << "ENTER THE STRING-1\n";
    cin >> str1;
    cout << "ENTER THE STRING-2\n";
    cin >> str2;
    int len1 = strLen(str1);
    int len2 = strLen(str2);
    int i;
    for(i = len1; i < len1+len2; i++)
    str1[i] = str2[i-len1];
    str1[i] = '\0';
    cout << "CONCAATENATED STRING IS: " << str1 << endl;
}

int main(){
    int ch, stop = 1;
    while(stop){
        cout << "1.COPY STRING\n2.CONCATENATE STRING\n";
        cin >> ch;
        switch(ch){
          case 1: copyString();
          break;
          case 2: concatString();
          break;
          default: cout << "INVALID CHOICE\n";
        }
        cout << "DO YOU WANA PERFORM ANOTHER OPERATION if yes press 0 else 1\n";
        cin >> stop;
    }
    return 0;
}



// program 2:

#include <iostream>
using namespace std;
#define max 5
class Stack{
    int arr[max];
    int top;
    public:
    void init(){
        top = -1;
    }
    void push(){
        int i;
        if(top == max-1)
        cout << "STACK OVERFLOW.\n";
        else{
            cout << "ENTER THE ELEMENT TO BE PUSHED.\n";
            cin >> i;
            arr[++top] = i;
            cout << "THE ELEMENT " << arr[top] << " IS  PUSHED INTO THE STACK.\n";
        }
    }
    void pop(){
        if(top == -1)
        cout << "STACK UNDERFLOW.\n";
        else
        cout << "THE ELEMENT " << arr[top--] << " IS  POPPED FROM THE STACK.\n";
    }
    void display(){
        if(top == -1)
        cout << "STACK UNDERFLOW\n";
        else{
            cout << "THE ELEMENTS IN THE STACK ARE: ";
            for(int i = top; i >= 0; i--){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main(){
    int ch, i, stop = 1;
    Stack s1;
    s1.init();
    while(stop){
        cout << "1.PUSH\n2.POP\n3.DISPLAY\n";
        cin >> ch;
        switch(ch){
           case 1: s1.push();
           break;
           case 2: s1.pop();
           break;
           case 3: s1.display();
           break;
           default: cout << "INVALID CHOICE\n";
        }
        cout << "DO YOU WANA PERFORM ANOTHER OPERATION if yes press 0 else 1\n";
        cin >> stop;
    }
    return 0;
}



// program 3

#include <iostream>
using namespace std;

class Employee{
    long long employeeNo;
    string employeeName;
    float basicSalary;
    float DA;
    float IT;
    float netSalary;
    float grossSalary;
    public:
    void readData(){
        cout << "ENTER THE EMPLOYEE ID, NAME AND BASICSALARY\n";
        cin >> employeeNo >> employeeName >> basicSalary;
    }
    void calcNetsalary(){
        DA = (0.52)*basicSalary;
        grossSalary = DA + basicSalary;
        IT = (0.3)*grossSalary;
        netSalary = DA + basicSalary - IT;
    }
    void printData(){
        cout << "EmployeeName:" << employeeName << endl;
        cout << "EmpoyeeId:" << employeeNo << endl;
        cout << "BasicSalary:" << basicSalary << endl;
        cout << "DA:" << DA << endl;
        cout << "IT" << IT << endl;
        cout << "GrossSalary:" << grossSalary << endl;
        cout << "NetSalary:" << netSalary << endl;
    }
};

int main(){
    int n;
    cout << "Enter no of employee's\n";
    cin >> n;
    Employee e[n], *p;
    for(int i = 0; i < n; i++){
        p = &e[i];
        p->readData();
        p->calcNetsalary();
    }
    for(int i = 0; i < n; i++){
        printf("<<<------------------------------>>>\n");
        p = &e[i];
        p->printData();
        printf("<<<------------------------------>>>\n");
    }
    return 0;
}



// program 4

#include <iostream>
#include <algorithm>
using namespace std;

class Student{
    // public:
    string USN;
    string Name;
    float avg;
    float marks[3];
    public:
    Student(){
        cout << "ENTER THE USN, NAME AND MARKS\n";
        cin >> USN >> Name >> marks[0] >> marks[1] >> marks[2];
    }
    
    void calcAvgofbestoftwo(){
        sort(marks, marks+3);
        avg = (marks[1]+marks[2])/2;
    }
    void printData(){
        cout << "StudentName:" << Name << endl;
        cout << "USN:" << USN << endl;
        cout << "Average of best of 2 marks:" << avg << endl;
    }
    friend void topper(int n, Student s[]);
};

void topper(int n, Student s[]){
        float totalmarks, maxmarks = 0;
        string tomper;
        for(int i = 0; i < n; i++){
            totalmarks = s[i].marks[0]+s[i].marks[1]+s[i].marks[2];
            if(maxmarks < totalmarks){
                tomper = s[i].Name;
                maxmarks = totalmarks;
            }
        }
        cout << tomper << "is the topper" << endl;
}

int main(){
    int n;
    cout << "Enter no of employee's\n";
    cin >> n;
    Student s[n];
    for(int i = 0; i < n; i++){
        s[i].calcAvgofbestoftwo();
    }
    for(int i = 0; i < n; i++){
        printf("<<<------------------------------>>>\n");
        s[i].printData();
        printf("<<<------------------------------>>>\n");
    }
    topper(n, s);
    return 0;
}



// program 5

/* A static variable in C++ is a variable that retains its value between function calls. It is declared with the "static" keyword before the type of the 
variable, and is usually placed within the scope of a function. Unlike local variables, which are destroyed when a function returns, a static variable 
retains its value even after the function has finished executing. This makes it useful for keeping track of information that needs to persist across 
multiple calls to a function. Additionally, a static variable in C++ has file scope, meaning it can be accessed from any function within the same file.*/

#include <iostream>
using namespace std;

class Counter{
    public:
    static int count;
    Counter(){
        count++;
    }
    ~Counter(){
        count--;
    }
};

int Counter::count;

void fun(){
    Counter temp;
    cout << "Objects in existence: " << Counter::count << endl;
}

int main(){
    Counter o1;
    cout << "Objects in existence: " << Counter::count << endl;
    Counter o2;
    cout << "Objects in existence: " << Counter::count << endl;
    Counter o3;
    cout << "Objects in existence: " << Counter::count << endl;
    Counter o4;
    cout << "Objects in existence: " << Counter::count << endl;
    fun();
    cout << "Objects in existence: " << Counter::count << endl;
    return 0;
}



// program 6

#include <iostream>
#include <cstring>
using namespace std;
class Date{
    int date, month, year;
    public:
    Date(int d, int m, int y){
        date = d;
        month = m;
        year = y;
    }
    Date(int d, string m, int y){
        string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for(int i = 0; i < 12; i++){
            if(m.compare(months[i]) == 0)
            month = i+1;
        }
        date = d;
        year = y;
    }
    Date(string d){
        date = stoi(d.substr(0, 2));
        month = stoi(d.substr(3, 2));
        year = stoi(d.substr(6,4));
    }
    void printDate(){
        cout << "dd/m/yy: " << date << "/"<< month << "/" << year << endl;
    }
};

int main(){
    Date d1(29, 12, 2004), d2(29, "Dec", 2004), d3("29/12/2004");
    d1.printDate();
    d2.printDate();
    d3.printDate();
    return 0;
}


// program 7

#include <iostream>
#include <cstring>
using namespace std;
class Patient{
    string name;
    string adm_date;
    string dis_date;
    public:
    int age;
    void getData(){
        cout << "Enter Name, addmited date, discharge date, age\n";
        cin >> name >> adm_date >> dis_date >> age;
    }
    void display(){
        cout << name << "\t" << age << "\t" << adm_date << "\t" << dis_date << endl;
    }
};

class Pediatric:public Patient{
    string vaccine;
    public:
    void pedgetData(){
        getData();
        cout << "Enter the vaccine to be given: ";
        cin >> vaccine;
    }
    void pediatricdisplay(){
        if(age < 12){
            display();
            cout << "\t" << vaccine << endl;
        }
        else
        cout << "NOT A PEDIATRIC PATIENT\n";
    }
};


int main(){
    int n;
    cout << "Enter the no.of pateints\n";
    cin >> n;
    Patient A[n];
    for(int i = 0; i < n; i++)
    A[i].getData();
    cout << "PATIENT DATABASE\n";
    cout << "NAME OF THE PATIENT\tAGE\tDATE OF ADMISSION\tDATE OF DISCHARGE\n";
    for(int i = 0; i < n; i++){
        A[i].display();
        cout << endl;
    }
    int m;
    cout << "Enter the no.of pediatric pateints\n";
    cin >> m;
    Pediatric C[m];
    for(int i = 0; i < m; i++)
    C[i].pedgetData();
    cout << "PATIENT DATABASE\n";
    cout << "NAME OF THE PATIENT\tAGE\tDATE OF ADMISSION\tDATE OF DISCHARGE\tVACCINE NAME\n";
    for(int i = 0; i < m; i++){
        C[i].pediatricdisplay();
        cout << endl;
    }
    return 0;
}
