#include <iostream>
#include "Funtions.h"
#include <cctype>


int get_level_of_precedence(char operador){
    if(operador == '+' || operador == '-')
        return 1;
    else if(operador == '*' || operador == '/')
        return 2;
    else if(operador == '^')
        return 3;
    return -1;
}

bool is_an_operator(char operador){
    if(operador == '+' || operador == '-' || operador == '*' || operador == '/' || operador == '^' )
        return 1;
    return 0;
}

bool is_open_bracket(char operador){
    if(operador == '{' || operador == '[' || operador == '(')
        return 1;

    return 0;
}

bool is_closed_bracket(char operador){
    if(operador == '}' || operador == ']' || operador == ')')
        return 1;

    return 0;
}

bool is_bracket(char operador){
    if(operador == '{' || operador == '[' || operador == '(' || operador == '}' || operador == ']' || operador == ')')
        return 1;

    return 0;
}

string infix_to_postfix(string expression){
    vector<char> stack;
    string buffer;

    for(int i = 0; i < expression.size(); i++){
        
        if(expression[i] == ' ')
            continue;

        if(isalpha(expression[i]))
            buffer += expression[i];
        else if(is_open_bracket(expression[i]))
            stack.push_back(expression[i]);
        else if(is_closed_bracket(expression[i])){
            while(!stack.empty() && !is_open_bracket(stack.back())){
                buffer += stack.back();
                stack.pop_back();
            }
            if( stack.back() == '(' || stack.back() == '{' )
                stack.pop_back();
        }
        else if(is_an_operator(expression[i]) && stack.empty()){
            stack.push_back(expression[i]);
        }
        else if (!stack.empty()) {
            if(get_level_of_precedence(expression[i]) > get_level_of_precedence(stack.back())){
                stack.push_back(expression[i]);
            }
            else if(get_level_of_precedence(expression[i]) == get_level_of_precedence(stack.back()) && expression[i] == '^'){
                stack.push_back(expression[i]);
            }
            else {
                while(!stack.empty() && get_level_of_precedence(expression[i]) <= get_level_of_precedence(stack.back())){
                    buffer += stack.back();
                    stack.pop_back();
                }
                stack.push_back(expression[i]);
            }

        }
    }

    while(!stack.empty()){
        buffer += stack.back();
        stack.pop_back();
    }

    return buffer;
}

int main(){

    string expression;
    cout<< "Infix: ";
    getline(cin, expression);
    cout<< "Postfix: "<< infix_to_postfix(expression)<<endl;

    return 0;
}