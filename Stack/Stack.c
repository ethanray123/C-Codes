#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 5

typedef char ElemArray[MAX];
typedef struct{
        ElemArray E;
        int top;
}Stack;
typedef enum{TRUE,FALSE}boolean;

void display(Stack);
void push(Stack *,char);
void pop(Stack *);
char top(Stack);
void initStack(Stack *);
boolean isFull(Stack);
boolean isEmpty(Stack);
void insertBottom(Stack *,char);
void insertSorted(Stack *,char);


int main()
{
    int choice;
    char check,nelem;
    Stack C;
    initStack(&C);
        do{
       system("cls");
       printf("Stack C\n\n");
       display(C);
       printf("\n1 - search();\n");
       printf("2 - push();\n");
       printf("3 - pop();\n");
       printf("4 - top();\n");
       printf("5 - insertbottom();\n");
       printf("6 - insertsorted();\n");
       printf("7 - isEmpty();\n");
       printf("8 - isFull();\n");
       printf("9 - initStack();\n\n");
       printf("Enter a number that corresponds to your desired function: "); fflush(stdin);
       scanf("%d",&choice);
       system("cls");
       switch(choice){
              case 0:printf("Exiting program..");break;
              case 1:break;
              case 2:printf("\n\n");display(C);
                     printf("\nEnter an Element to Push into Stack C: ");fflush(stdin);
                     scanf("%c",&nelem);
                     push(&C,nelem);
                     break;
              case 3:pop(&C);printf("\n");display(C);
                     break;
              case 4:printf("The Element at the top of the Stack is %c\n\n",top(C));
                     display(C);break;
              case 5:printf("Enter an Element to Insert(Bottom) into Stack C: ");fflush(stdin);
                     scanf("%c",&nelem);
                     insertBottom(&C,nelem);
                     display(C);break;
              case 6:printf("Enter an Element to Insert(Sorted) into Stack C: ");fflush(stdin);
                     scanf("%c",&nelem);
                     insertSorted(&C,nelem);
                     display(C);break;
              case 7:if(isEmpty(C)==TRUE){
                           printf("Stack is Empty\n\n");
                     }else{
                           printf("Stack is Not Empty\n\n");
                     }
                     display(C);break;
              case 8:if(isFull(C)==TRUE){
                           printf("Stack is Full\n\n");
                     }else{
                           printf("Stack is Not Full\n\n");
                     }
                     display(C);break;
              case 9:initStack(&C);
                     display(C);break;
              default:printf("Incorrect choice.. Please try again");
       }
       getch();
    }while(choice!=0);
    getch();
    return 0;
}

void display(Stack C)
{
     int i;
     if(C.top==-1){
          printf("| {} |\n");         
     }else{
          for(i=C.top;i>-1;i--)
          printf("| %c |\n",C.E[i]);
     }
}

void push(Stack *C,char elem)
{
     if(C->top!=MAX-1){ 
           C->top++;
           C->E[C->top]=elem;
           printf("elem pushed = %c\n",elem);
     }else{
           printf("Error:Free Memory\n");
     }
}

void pop(Stack *C)
{
     if(C->top>-1){
           C->top--;
     }else{
           printf("Error:No Elements To Free\n");
     }
}

char top(Stack C)
{
     return (C.top!=-1)?C.E[C.top]:'~';
     //returns -1 when stack is empty
}

void initStack(Stack *C)
{
     C->top=-1;
     //initializes the stack to logically have no elements
}

boolean isFull(Stack C)
{
        return (C.top==MAX-1)?TRUE:FALSE;
}

boolean isEmpty(Stack C)
{
        return (C.top==-1)?TRUE:FALSE;
}

void insertBottom(Stack *C, char elem) 
{
     Stack temp;
     initStack(&temp);
     if(isFull(*C)!=TRUE){
     while(isEmpty(*C)!=TRUE){ //C->top!=0;
        push(&temp,top(*C)); 
        pop(C);                 
        /*temp.E[temp.top]=C->E[C->top-1];
        C->top--;
        temp.top++;*/
     }
     push(C,elem);
     /*C->E[C->top]=elem;
     C->top++;*/
     while(isEmpty(temp)!=TRUE){ //temp.top!=0;
        push(C,top(temp));
        pop(&temp);
        /*C->E[C->top]=temp.E[temp.top-1];
        C->top++;
        temp.top--;*/
     }
     }else{
           printf("Error:Free Memory\n");
     }
}

void insertSorted(Stack *C,char nelem)
{
     Stack fake;
     if(isFull((*C))!=TRUE){
            initStack(&fake);
            while(nelem>top(*C)){
                 push(&fake,top(*C));
                 pop(C);
            }
            push(C,nelem);
            while(isEmpty(fake)==FALSE){
                 push(C,top(fake));
                 pop(&fake);
            }
     }else{
            printf("Error:Free Memory\n");
     }
}
