#include<stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;

int pop(){
  if(top == -1){
    printf("Stack Underflow!!, Nothing to remove.\n");
    return -1;
  } else{
    int removed = stack[top];
    top--;
    printf("\n%d popped from stack.", removed);
    return removed;
  }
}
void display(){
  if (top == -1){
    printf("Stack is empty.\n");
  } else{
    printf("\nStack Elements: ");
    for (int i = 0; i<= top; i++){
      printf(" %d", stack[i]);
    }
  }
}

int main(){
  stack[++top] = 10;
  stack[++top] = 20;
  stack[++top] = 30;
  stack[++top] = 40;
  stack[++top] = 50;
  display();
  pop();
  pop();
  display();

}
