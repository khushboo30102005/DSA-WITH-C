#include<stdio.h>
#define MAX 5
int stack[MAX];
int top =-1;

int  peek(){
  if(top == -1){
    printf("Stack is empty.");
    return -1;
  } else{
    return stack[top];
  }
}

int size(){
  return top+1;
}
void isEmpty(){
  if(top == -1){
    printf("Stack is empty.\n");
  } else{
    printf("Stack is not Empty.\n");
  }
}
void display(){
  if (top == -1){
    printf("Stack is empty.\n");
  } else{
    printf("Stack Elements: ");
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
  printf("top_element is: %d\n", peek());
  printf("Size is: %d\n", size());
  isEmpty();
  display();

}

