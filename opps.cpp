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
