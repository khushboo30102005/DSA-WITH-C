#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push(){
  int value;
  if(top == MAX-1){
    printf("Stack Overflow!!,can't Push.\n");
  } else{
    printf("Enter value to push..\n");
    scanf("%d", &value);
    top++;
    stack[top] = value;
    printf("%d pushed into stack.\n", value);
  }
}

void pop(){
  if(top == -1){
    printf("Stack underflow!! Nothing to popped.\n");
  }else{
    printf("Popped element: %d\n", stack[top]);
    top--;
  }
}

void peek(){
  if(top == -1){
    printf("stack is empty.\n");
  } else{
    printf("Top element is:%d\n", stack[top]);
  }
}

void isEmpty(){
  if(top == -1){
    printf("stack is empty.\n");
  } else{
    printf("Stack is NonEmpty.\n");
  }  
}

void size(){
  printf("Size of Stack is: %d\n", top+1);
}

void display() {
  if(top == -1){
    printf("stack is empty.\n");
  } else{
    printf("Stack elements: ");
    for(int i=top; i>=0; i--){
      printf("\n%d ", stack[i]);
    }
  }
}
int main(){
  int choice;
  while (1)
  {
    printf("\n------ STACK MENU ------\n");
    printf("1. PUSH\n");
    printf("2. POP\n");
    printf("3. PEEK\n");
    printf("4. DISPLAY\n");
    printf("5. SIZE\n");
    printf("6. IS EMPTY\n");
    printf("7. EXIT\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
      switch (choice)
  {
  case 1:
    push();
    break;
  case 2:
    pop();
    break;
  case 3:
    peek();
    break;
  case 4:
    display();
    break;
  case 5:
    size();
    break;
  case 6:
    isEmpty();
    break;
  case 7:
    exit(0);  
  default:printf("Invalid choice! Try again.\n");
    break;
  }
  }
  return 0;  
}