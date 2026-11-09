#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

// stack class using an array
class Stack{
private:
    char arr[MAX];
    int top;

public:
    // initializes an empty stack
    Stack(){
        top = -1;
    }

    // check if the stack is empty
    bool isEmpty(){
        return top == -1;
    }

    // push an opening symbol onto the stack
    void push(char c){
        arr[++top] = c;
    }

    // pop the top symbol from the stack
    char pop(){
        if (isEmpty())
            return '\0';

        return arr[top--];
    }
};

// check if opening and closing symbols match
bool match(char open, char close){
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// check whether the expression is balanced
bool checkBalance(string exp){
    // create a stack
    Stack s;

    // read each character
    for(char ch : exp){
        // ignore non-symbol characters

        // push opening symbols
        if(ch=='('||ch=='['||ch=='{'){
            s.push(ch);
        }
        // process closing symbols
        else if(ch==')'||ch==']'||ch=='}'){
            // report error if stack is empty
            if(s.isEmpty())
                return false;

            // pop the top opening symbol
            char temp = s.pop();
                
            // compare opening and closing symbols
            if(!match(temp,ch))
                return false;
        }
    }
    // stack must be empty
    return s.isEmpty();
}

int main(){
    string expression;

    // ask the user for an expression
    cout<<"Enter expression: ";
    getline(cin,expression);

    // display the result
    if(checkBalance(expression))
        cout<<"Expression is Balanced."<<endl;
    else
        cout<<"Expression is Not Balanced."<<endl;

    return 0;
}