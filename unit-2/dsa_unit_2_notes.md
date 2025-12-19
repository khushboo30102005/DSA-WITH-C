# DSA Unit 2: Applications of Stack, Queue, and Array

## Application of Stack: Function Call Management

### Core Concept
A stack is a linear data structure that follows the **Last In, First Out (LIFO)** principle. In program execution, this behavior is essential for managing function calls and returns in an organized and safe manner.

### Role of Stack in Program Execution
Whenever a function is called in a program, certain information must be stored temporarily so that the program can return correctly after the function finishes. This information is stored using a **stack**, known as the **call stack**.

### Call Stack
The call stack is a stack data structure that keeps track of active function calls. For each function call, a new entry is pushed onto the stack, and when the function completes, that entry is popped.

### Stack Frame
Each function call creates a **stack frame**, which contains:
- Function parameters
- Local variables
- Return address (where to return after execution)

When the function execution ends, its stack frame is automatically removed from the stack.

### Working of Function Calls Using Stack
- When a function is called, its stack frame is **pushed** onto the stack.
- Control is transferred to the called function.
- When the function finishes execution, its stack frame is **popped**.
- Control returns to the calling function.

This ensures that the **last called function is the first to complete**, which perfectly matches the LIFO nature of stacks.

### Stack and Recursion
In recursion, a function calls itself. Each recursive call creates a new stack frame.
- Stack grows with each recursive call.
- A base condition stops further calls.
- If recursion does not terminate properly, it leads to **stack overflow**.

### Advantages of Using Stack for Function Calls
- Supports nested function calls
- Ensures correct return sequence
- Automatic memory management for local variables
- Fast execution due to constant-time push and pop operations

### Exam Focus Points
- Queue can be implemented using a one-dimensional array
- Front and rear control deletion and insertion operations
- Overflow occurs when rear reaches MAX - 1
- Memory wastage is a major drawback of simple array-based queue

---

## Program: Queue Implementation Using Array (in C)

The following program demonstrates the implementation of a **simple queue using an array**. It includes all basic queue operations such as enqueue, dequeue, and display.

### Key Points Before Program
- `front` and `rear` are initialized to `-1`
- Enqueue operation inserts an element at the rear
- Dequeue operation removes an element from the front
- Overflow and underflow conditions are handled

### C Program
```c
#include <stdio.h>
#define MAX 5

struct Queue {
    int arr[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

int isFull(struct Queue *q) {
    return (q->rear == MAX - 1);
}

void enqueue(struct Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot insert.
");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = data;
    printf("Enqueued: %d
", data);
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow! Cannot delete.
");
        return;
    }
    printf("Dequeued: %d
", q->arr[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.
");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("
");
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    dequeue(&q);
    display(&q);

    return 0;
}
```

### Program Explanation (Exam-Friendly)
- Queue is implemented using an array of fixed size
- `enqueue()` inserts elements at the rear end
- `dequeue()` removes elements from the front end
- Overflow and underflow conditions are properly checked
- This program represents a **simple linear queue**, not a circular queue


## Circular Queue

### Need for Circular Queue
A circular queue is introduced to overcome the limitation of the simple (linear) queue, where memory wastage occurs due to unused spaces after deletion. Circular queue efficiently reuses these empty spaces.

### Core Concept
A circular queue is a queue in which the last position of the array is logically connected to the first position, forming a circular structure. When the rear reaches the end of the array, it wraps around to the beginning.

### Circular Movement Using Modulus Operation
Circular movement of front and rear is achieved using the modulus operator:
- `rear = (rear + 1) % MAX`
- `front = (front + 1) % MAX`

This operation ensures that the index returns to the beginning of the array when it exceeds the maximum size.

### Role of Front and Rear
- **Front**: Points to the first element of the queue and is used during deletion.
- **Rear**: Points to the last inserted element and is used during insertion.

Initially, both front and rear are set to `-1`, indicating an empty queue.

### Empty Condition
A circular queue is empty when:
- `front == -1`

### Full Condition (Very Important)
A circular queue is full when:
- `(rear + 1) % MAX == front`

This condition indicates that no free space is available for insertion.

### Enqueue Operation in Circular Queue
Steps involved in insertion:
- Check if the queue is full
- If the queue is empty, set `front = rear = 0`
- Otherwise, move rear circularly using modulus operation
- Insert the element at the rear position

### Dequeue Operation in Circular Queue
Steps involved in deletion:
- Check if the queue is empty
- Remove the element at the front position
- If only one element exists, reset `front = rear = -1`
- Otherwise, move front circularly using modulus operation

### Advantages of Circular Queue
- Efficient utilization of memory
- Eliminates memory wastage present in simple queue
- Suitable for continuous data processing

### Applications of Circular Queue
- CPU scheduling
- Buffer management
- Producer–consumer problems
- Streaming and real-time systems

### Exam Focus Points
- Circular queue connects last index to first
- Modulus operation enables circular movement
- Full condition: `(rear + 1) % MAX == front`
- Empty condition: `front == -1`


## Deque (Double Ended Queue)

### Introduction
A deque (Double Ended Queue) is a linear data structure in which insertion and deletion of elements can be performed at both the front and the rear ends. It provides more flexibility compared to a simple queue.

### Need for Deque
In certain applications, data needs to be inserted or removed from both ends. A deque is introduced to fulfill this requirement where operations are not restricted to only one end.

### Operations in Deque
A deque supports the following operations:
- Insertion at the front
- Insertion at the rear
- Deletion from the front
- Deletion from the rear

### Relationship with Stack and Queue
- When insertion is done at rear and deletion at front, deque behaves like a queue.
- When insertion and deletion are done at the same end, deque behaves like a stack.

### Types of Deque

#### 1. Input-Restricted Deque
- Insertion is allowed at only one end
- Deletion is allowed at both ends
- Useful when data enters from a single direction but can be processed from either end

#### 2. Output-Restricted Deque
- Insertion is allowed at both ends
- Deletion is allowed at only one end
- Useful when deletion must follow a fixed direction

### Advantages of Deque
- Highly flexible data structure
- Can be used to implement stack and queue
- Efficient for certain algorithmic problems

### Applications of Deque
- Palindrome checking
- Sliding window problems
- Task scheduling
- Undo and redo operations

### Exam Focus Points
- Deque allows insertion and deletion at both ends
- Two types: input-restricted and output-restricted deque
- Deque can simulate both stack and queue behavior


## Priority Queue

### Introduction
A priority queue is a special type of queue in which each element is associated with a priority. Elements are removed from the queue based on their priority rather than their arrival time.

### Need for Priority Queue
In many real-life and computing scenarios, certain tasks must be processed before others based on their importance. A priority queue is used to handle such situations where priority matters more than order of insertion.

### Core Concept
Each element in a priority queue is stored along with a priority value. The element with the highest priority is deleted first. If two elements have the same priority, they are processed according to FIFO order.

### Types of Priority Queue

#### 1. Ascending Priority Queue
- Lower priority value indicates higher priority
- Element with the smallest priority value is deleted first

#### 2. Descending Priority Queue
- Higher priority value indicates higher priority
- Element with the largest priority value is deleted first

### Insertion Operation
- Elements are inserted based on their priority
- Proper position is determined by comparing priority values
- Shifting of elements may be required in array implementation

### Deletion Operation
- Element with the highest priority is removed
- Priority decides deletion, not position in the queue

### Advantages of Priority Queue
- Important tasks are processed first
- Useful for real-time and scheduling systems
- Improves efficiency in task management

### Applications of Priority Queue
- CPU scheduling
- Process management
- Emergency handling systems
- Shortest path algorithms
- Network routing

### Exam Focus Points
- Priority queue processes elements based on priority
- FIFO is followed when priorities are equal
- Two types: ascending and descending priority queue

