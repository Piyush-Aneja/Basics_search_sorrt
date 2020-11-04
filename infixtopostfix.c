#include<stdio.h>
#include<string.h>

char stack[30];char postfix[30];char input[30]; int top=-1,pf=0,len=0;;
int lesspriority(char op,char op_at_stack)
{
    char operators[]={'/','%','^','*','+','-'};
    char pr[]={2,2,2,2,1,1};
    int pr1,pr2;
    for(int i=0;i<sizeof(pr)/sizeof(pr[0]);i++)
    {

        if (op==operators[i])
            pr1=pr[i];
    }
      for(int i=0;i<sizeof(pr)/sizeof(pr[0]);i++)
    {

        if (op_at_stack==operators[i])
            pr2=pr[i];
    }
    if(pr1<=pr2)
        return(1);
    else
        return(0);
}
int inputexp()
{
    char c=' '; int i=0;
    char inp[30];
   

    printf("Enter the expression without spacing in between\n");
    scanf("%s",inp);
     input[0]='(';
    
    
    while(inp[i]!='\0')
    {
        input[i+1]=inp[i];
        i++;
    }
    input[i+1]=')';
    i++;
    return(strlen(input)); //returning length of expression

}
void push(char op)
{
    stack[++top]=op;
}
void pop()
{
    postfix[pf++]=stack[top];
    top--;
}
void display()
{
    printf("infix string:");
    for(int i=0;i<len;i++)
        printf("%c",input[i]);

     printf(", Postfix string :");
     
    for(int i=0;i<len-2;i++)
        printf("%c",postfix[i]);
    printf("\n");
   
}

int main()
{
    
    len=inputexp();
    printf("Before calculation-\n");
    display();
    for(int i=0;i<len;i++)
    {
        int pr;
        char op=input[i];
       
            if (op>=65 && op<=90 || op>=97 &&op<=122 || op>=48 && op<=57) //if it is operand then put that to postfix
                postfix[pf++]=op;
            else //it is operator
            {
                if (op=='(')
                {
                    push(op);
                }
                else if (op==')')
                {
                    while(stack[top]!='(')
                        pop();
                    top--; //to remove the opening braces as we cant use pop because then it would add to postifx str
                }
                else  //its a operator other than braces
                {
                      char op_at_stack=stack[top];
                      while(pr=lesspriority(op,op_at_stack) && op_at_stack!='(' && op_at_stack!=')')
                      {
                          pop();
                          op_at_stack=stack[top];
                          
                      }
                      push(op);
        
        
                }
            } //closing of its an operator
    }
    postfix[pf++]='\0'; //closing of for loop for calculation
    printf("After calculation-\n");
    display();
    
      
return 0;
}