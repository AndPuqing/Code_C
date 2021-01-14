/*这是完成了一个循环队列的数据结构
可循环，即充分利用空余空间
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int *data;       //数据指针
    int front, rear; //头数据，尾数据
    int length;      //数据长度
} MyCircularQueue;

bool myCircularQueueIsEmpty(); //这两处的函数声明并不是无中生有
bool myCircularQueueIsFull();  //因为这两个函数没写的时候要用到这两个函数，所以声明了一下

MyCircularQueue *myCircularQueueCreate(int k)
{
    if (k < 0)
        return NULL;                                                             //检查输入数据范围
    MyCircularQueue *p = (MyCircularQueue *)malloc(k * sizeof(MyCircularQueue)); //动态申请数据空间
    p->data = (int *)malloc(sizeof(int) * (k + 1));                              //申请动态数组空间
    p->front = 0;
    p->rear = 0;
    p->length = k + 1;
    return p;
}
/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
    if (myCircularQueueIsFull(obj))
        return false;
    obj->data[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->length;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
        return false;
    obj->front = (obj->front + 1) % obj->length;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->data[obj->front % obj->length];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue *obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->data[(obj->rear - 1 + obj->length) % obj->length];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    if (obj->rear == obj->front)
        return true;
    return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue *obj)
{
    if ((obj->rear + 1) % obj->length == obj->front)
        return true;
    return false;
}

void myCircularQueueFree(MyCircularQueue *obj)
{
    free(obj->data);
    obj->data = NULL;
    free(obj);
    obj = NULL;
}

int main()
{
    MyCircularQueue *obj = myCircularQueueCreate(6);
    printf("%d", myCircularQueueEnQueue(obj, 5));
    myCircularQueueFree(obj);
}
/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/