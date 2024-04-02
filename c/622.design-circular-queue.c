/*
 * @lc app=leetcode id=622 lang=c
 *
 * [622] Design Circular Queue
 */

// @lc code=start

typedef struct
{
    void *queue;
    size_t total_size;
    void *head;
    void *tail;
    size_t cur_size;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue *myCircularQueueCreate(int k)
{
    MyCircularQueue *circle_queue = calloc(1, sizeof(MyCircularQueue));
    circle_queue->queue = calloc(k, sizeof(int));
    circle_queue->total_size = k * sizeof(int);
    circle_queue->head = circle_queue->queue;
    circle_queue->tail = circle_queue->queue;
    return circle_queue;
}

/** Insert an element into the circular queue. Return true if the operation is
 * successful. */
bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{

    if (!obj || !obj->queue || (obj->cur_size == obj->total_size))
        return false;

    obj->cur_size += sizeof(int);
    if (obj->tail == obj->queue + obj->total_size)
        obj->tail = obj->queue;
    memcpy(obj->tail, &value, sizeof(int));
    obj->tail += sizeof(int);
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is
 * successful. */
bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
    if (!obj || !obj->queue || obj->cur_size == 0)
        return false;

    obj->head += sizeof(int);
    obj->cur_size -= sizeof(int);
    if (obj->head == obj->queue + obj->total_size) {
        obj->head = obj->queue;
    }
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue *obj)
{
    if (!obj || !obj->queue || obj->cur_size == 0)
        return -1;
    int out = 0;
    memcpy(&out, obj->head, sizeof(int));
    return out;
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue *obj)
{
    if (!obj || !obj->queue || obj->cur_size == 0)
        return -1;
    int out = 0;
    memcpy(&out, obj->tail - sizeof(int), sizeof(int));
    return out;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    if (!obj || !obj->queue)
        return false;
    return (obj->cur_size == 0) ? true : false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue *obj)
{
    if (!obj || !obj->queue || obj->cur_size == 0)
        return false;
    return (obj->cur_size == obj->total_size) ? true : false;
}

void myCircularQueueFree(MyCircularQueue *obj)
{
    if (obj)
    {
        free(obj->queue);
        obj->queue = NULL;
        free(obj);
        obj = NULL;
    }
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
// @lc code=end
