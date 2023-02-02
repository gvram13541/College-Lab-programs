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


