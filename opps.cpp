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
