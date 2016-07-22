#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;

string input;
char convert_input[100];
int length;

void infix_to_postfix(char arr[100]);
void infix_to_prefix(char arr[100]);

class Stack
{
public:
    const static int MAX = 100;
    const static int MAX1 = 100;
    char arr[MAX];
    char arr1[MAX1];
    int top;
    int top1;

    Stack ()
    {
        top = -1;
        top1 = -1;
    }

    void push(char data)
    {
        top = top + 1;
        arr[top] = data;
    }

    void pop()
    {
        top = top - 1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int peek()
    {
        return arr[top];
    }

    void addToAnswer(char data)
    {
        top1 = top1 + 1;
        arr1[top1] = data;
    }

    int answerPeek()
    {
        return arr1[top1];
    }

    void postfix_print()
    {
        for (int i=0; i<=top1; i++)
        {
            cout << arr1[i];
        }
    }

    void prefix_print()
    {
        for (int i=top1; i>=0; i--)
        {
            cout << arr1[i];
        }
    }
};

int main()
{
    int choice;

    cout << "Enter your choice in numerical value" <<endl <<endl;
    cout << "1. Infix to Postfix" <<endl;
    cout << "2. Infix to Prefix" <<endl;
    cout << "3. Postfix to Infix" <<endl;
    cout << "4. Postfix to Prefix" <<endl;
    cout << "5. Prefix to Infix" <<endl;
    cout << "6. Prefix to Postfix" <<endl <<endl;

    cin >> choice;
    getline(cin,input);

    switch (choice)
    {
        case 1:
            cout << "Enter your infix expression" <<endl;
            getline(cin,input);
            length = input.length();
            strcpy(convert_input,input.c_str());
            infix_to_postfix(convert_input);
            break;
        case 2:
            cout << "Enter your infix expression" <<endl;
            getline(cin,input);
            length = input.length();
            strcpy(convert_input,input.c_str());
            infix_to_prefix(convert_input);
            break;
    }

    return 0;
}

void infix_to_postfix(char arr[100])
{
    Stack s;
    for(int i=0; arr[i]!= '\0'; i++)
    {
        if (arr[i]>='0' && arr[i]<='9')
        {
            s.addToAnswer(arr[i]);
        }

        else if (arr[i] >=65 && arr[i]<=90)
        {
            s.addToAnswer(arr[i]);
        }

        else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')
        {
            if (s.isEmpty())
            {
                s.push(arr[i]);
            }

            else
            {
                if (arr[i] == '+')
                {
                    int limit = s.top;
                    for (int j=0; j<=limit+1; j++)
                    {
                        if (s.peek() == 43 || s.peek() == 42 || s.peek() == 45 || s.peek() == 47)
                        {
                            s.addToAnswer(s.peek());
                            s.pop();
                        }
                        else
                        {
                            s.push(arr[i]);
                            break;
                        }
                    }
                }

                else if(arr[i] == '*')
                {
                    int limit = s.top;
                    for (int j=0; j<=limit+1; j++)
                    {
                        if (s.peek() == 42 || s.peek() == 47)
                        {
                            s.addToAnswer(s.peek());
                            s.pop();
                        }
                        else
                        {
                            s.push(arr[i]);
                            break;
                        }
                    }
                }

                else if(arr[i] == '/')
                {
                    int limit = s.top;
                    for (int j=0; j<=limit+1; j++)
                    {
                        if (s.peek() == 42 || s.peek() == 47)
                        {
                            s.addToAnswer(s.peek());
                            s.pop();
                        }
                        else
                        {
                            s.push(arr[i]);
                            break;
                        }
                    }
                }

                else if (arr[i] == '-')
                {
                    int limit = s.top;
                    for (int j=0; j<=limit+1; j++)
                    {
                        if (s.peek() == 43 || s.peek() == 42 || s.peek() == 45 || s.peek() == 47)
                        {
                            s.addToAnswer(s.peek());
                            s.pop();
                        }
                        else
                        {
                            s.push(arr[i]);
                            break;
                        }
                    }
                }
            }
        }

        else if (arr[i] == '(' || arr[i] == ')')
        {
            if (arr[i] == '(')
            {
                s.push(arr[i]);
            }

            else
            {
                while (1)
                {
                    if (s.peek() == '(')
                    {
                        s.pop();
                        break;
                    }
                    else
                    {
                        s.addToAnswer(s.peek());
                        s.pop();
                    }

                }
            }
        }
    }
    while (!s.isEmpty())
    {
        s.addToAnswer(s.peek());
        s.pop();
    }
    cout << endl;
    cout << "The postfix expression : ";
    s.postfix_print();
};



void infix_to_prefix(char arr[100])
{
    Stack s;
    for (int i=length-1; i>=0; i--)
    {
        if (arr[i]>='0' && arr[i]<='9')
        {
            s.addToAnswer(arr[i]);
        }

        else if (arr[i] >=65 && arr[i]<=90)
        {
            s.addToAnswer(arr[i]);
        }

        else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/')
        {
            if (s.isEmpty())
            {
                s.push(arr[i]);
            }

            else
            {
                if (arr[i] == '+')
                {
                    int limit = s.top;
                    for (int j=0; j<=limit+1; j++)
                    {
                        if (s.peek() == 43 || s.peek() == 42 || s.peek() == 45 || s.peek() == 47)
                        {
                            s.addToAnswer(s.peek());
                            s.pop();
                        }
                        else
                        {
                            s.push(arr[i]);
                            break;
                        }
                    }
                }

                else if(arr[i] == '*')
                {
                    int limit = s.top;
                    for (int j=0; j<=limit+1; j++)
                    {
                        if (s.peek() == 42 || s.peek() == 47)
                        {
                            s.addToAnswer(s.peek());
                            s.pop();
                        }
                        else
                        {
                            s.push(arr[i]);
                            break;
                        }
                    }
                }

                else if(arr[i] == '/')
                {
                    int limit = s.top;
                    for (int j=0; j<=limit+1; j++)
                    {
                        if (s.peek() == 42 || s.peek() == 47)
                        {
                            s.addToAnswer(s.peek());
                            s.pop();
                        }
                        else
                        {
                            s.push(arr[i]);
                            break;
                        }
                    }
                }

                else if (arr[i] == '-')
                {
                    int limit = s.top;
                    for (int j=0; j<=limit+1; j++)
                    {
                        if (s.peek() == 43 || s.peek() == 42 || s.peek() == 45 || s.peek() == 47)
                        {
                            s.addToAnswer(s.peek());
                            s.pop();
                        }
                        else
                        {
                            s.push(arr[i]);
                            break;
                        }
                    }
                }
            }
        }

        else if (arr[i] == '(' || arr[i] == ')')
        {
            if (arr[i] == ')')
            {
                s.push(arr[i]);
            }

            else
            {
                while (1)
                {
                    if (s.peek() == ')')
                    {
                        s.pop();
                        break;
                    }
                    else
                    {
                        s.addToAnswer(s.peek());
                        s.pop();
                    }

                }
            }
        }
    }
    while (!s.isEmpty())
    {
        s.addToAnswer(s.peek());
        s.pop();
    }
    cout << endl;
    cout << "The prefix expression : ";
    s.prefix_print();
};
