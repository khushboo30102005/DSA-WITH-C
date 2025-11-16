#include<stdio.h>
#define MAX 5

int stack[MAX];

int top = -1;

void push(int value){
  if(top == MAX-1){
    printf("Stack overflow!!, can't insert %d\n", value);
  } else{
    top++;
    stack[top] = value;
    printf("%d pushed into stack.\n", value);
  }
}
void display(){
  if(top == -1){
    printf("Stack is empty");
  } else{
    printf("Stack elements: ");
    for(int i = 0; i<=top; i++){
      printf("%d ", stack[i]);
    }
  }
}
int main(){
  push(10);
  push(20);
  push(30);
  push(40);
  push(50);
  push(60);
  display();
}