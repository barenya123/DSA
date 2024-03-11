// "First Method without using stack"...............................................................................

// #include<iostream>
// #include<stack>
// using namespace std;
// int main()
// {
//     char expression[50]; // declaration of char type array
//     int x=0, i=0; // declaration of two integer type variables
//     printf("\nEnter an expression");
//     gets (expression);
// // Scanning the expression until we reach the end of the expression.
//  while(expression[i]!= '\0')
//     {
//     // Condition to check the symbol is '('
//      if(expression[i]=='(')
//         {
//             x++;    // incrementing 'x' variable
//         }
//      // condition to check the symbol is ')'
//      else if(expression[i]==')')
//         {
//             x--;   // decrementing 'x' variable
//             if(x<0)
//             break;
//         }
//     i++;       // incrementing 'i' variable.
//     }
//     // Condition to check whether x is equal to 0 or not.
//     if(x==0)
//     {
//         printf("Expression is balanced");
//     }

//     else
//     {
//         printf("Expression is unbalanced");
//     }
//     return 0;
// }



// "Second method ussing stsck"...................................................................


#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#define MAX 20 
 
struct stack 
{ 
    char stk[MAX]; 
    int top; 
}s; 
 
void push(char item) 
{ 
    if (s.top == (MAX - 1)) 
        printf ("Stack is Full\n"); 
    else 
    { 
        s.top = s.top + 1; // Push the char and increment top 
        s.stk[s.top] = item; 
    } 
} 
 
void pop() 
{ 
    if (s.top == - 1) 
    { 
        printf ("Stack is Empty\n"); 
    } 
    else 
    { 
        s.top = s.top - 1; // Pop the char and decrement top 
    } 
} 
 
int main() 
{ 
    char exp[MAX]; 
    int i = 0; 
    s.top = -1; 
    printf("\nINPUT THE EXPRESSION : "); 
    scanf("%s", exp); 
    for(i = 0;i < strlen(exp);i++) 
    { 
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') 
        { 
            push(exp[i]); // Push the open bracket 
            continue; 
        } 
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}') // If a closed bracket is encountered 
        { 
            if(exp[i] == ')') 
            { 
                if(s.stk[s.top] == '(') 
                { 
                    pop(); // Pop the stack until closed bracket is found 
                } 
                else 
                { 
                    printf("\nUNBALANCED EXPRESSION\n"); 
                    break; 
                } 
            } 
            if(exp[i] == ']') 
            { 
                if(s.stk[s.top] == '[') 
                { 
                    pop(); // Pop the stack until closed bracket is found 
                } 
                else 
                { 
                    printf("\nUNBALANCED EXPRESSION\n"); 
                    break; 
                } 
            } 
            if(exp[i] == '}') 
            { 
                if(s.stk[s.top] == '{') 
                { 
                    pop(); // Pop the stack until closed bracket is found 
                } 
                else 
                { 
                    printf("\nUNBALANCED EXPRESSION\n"); 
                    break; 
                } 
            } 
        } 
    } 
    if(s.top == -1) 
    { 
        printf("\nBALANCED EXPRESSION\n"); // Finally if the stack is empty, display that the expression is balanced 
    }
    else{
        printf("\nUnbalanced Expression\n");
    }
}
// #include<stdio.h> 
// #include<stdlib.h> 
// #include<string.h> 
// #define MAX 20 
 
// struct stack 
// { 
//     char stk[MAX]; 
//     int top; 
// }s; 
 
// void push(char item) 
// { 
//     if (s.top == (MAX - 1)) 
//         printf ("Stack is Full\n"); 
//     else 
//     { 
//         s.top = s.top + 1; // Push the char and increment top 
//         s.stk[s.top] = item; 
//     } 
// } 
 
// void pop() 
// { 
//     if (s.top == - 1) 
//     { 
//         printf ("Stack is Empty\n"); 
//     } 
//     else 
//     { 
//         s.top = s.top - 1; // Pop the char and decrement top 
//     } 
// } 
 
// int main() 
// { 
//     char exp[MAX]; 
//     int i = 0; 
//     s.top = -1; 
//     printf("\nINPUT THE EXPRESSION : "); 
//     scanf("%s", exp); 
//     for(i = 0;i < strlen(exp);i++) 
//     { 
//         if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') 
//         { 
//             push(exp[i]); // Push the open bracket 
//             continue; 
//         } 
//         else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}') // If a closed bracket is encountered 
//         { 
//             if(exp[i] == ')') 
//             { 
//                 if(s.stk[s.top] == '(') 
//                 { 
//                     pop(); // Pop the stack until closed bracket is found 
//                 } 
//                 else 
//                 { 
//                     printf("\nUNBALANCED EXPRESSION\n"); 
//                     break; 
//                 } 
//             } 
//             if(exp[i] == ']') 
//             { 
//                 if(s.stk[s.top] == '[') 
//                 { 
//                     pop(); // Pop the stack until closed bracket is found 
//                 } 
//                 else 
//                 { 
//                     printf("\nUNBALANCED EXPRESSION\n"); 
//                     break; 
//                 } 
//             } 
//             if(exp[i] == '}') 
//             { 
//                 if(s.stk[s.top] == '{') 
//                 { 
//                     pop(); // Pop the stack until closed bracket is found 
//                 } 
//                 else 
//                 { 
//                     printf("\nUNBALANCED EXPRESSION\n"); 
//                     break; 
//                 } 
//             } 
//         } 
//     } 
//     if(s.top == -1) 
//     { 
//         printf("\nBALANCED EXPRESSION\n"); // Finally if the stack is empty, display that the expression is balanced 
//     } 
// }