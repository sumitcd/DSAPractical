
struct Queue {
    int front;
    int rear;
    int size;
    int* array;
};

Queue* createQueue(int size){
    Queue* q = new Queue;
    if(!q) return NULL;
    q->size = size;
    q->front = q->rear = -1;
    q->array = new int[q->size];
    if(!q->array) return NULL;
    return q;
}

int isFull(Queue* q){
    return (q->rear + 1)%q->size == q->front;
}

int isEmpty(Queue* q){
    return q->front == -1;
}

void enqueue(Queue* q, int data){
    if(isFull(q)) return;
    q->rear = (q->rear + 1)%q->size;
    q->array[q->rear] = data;
    if(q->front == -1){
        q->front = q->rear;
    }
}

int dequeue(Queue* q){
    if(isEmpty(q)) return -1;
    int data = q->array[q->front];
    if(q->front == q->rear){
        q->front = q->rear = -1;
    }
    else{
        q->front = (q->front + 1) % q->size;
    }
    return data;
}

void deleteQueue(Queue* q){
    if(q){
        if(q->array){
            free(q->array);
        }
        free(q);
    }
}

int main(){
    Queue* q = createQueue(10);
    enqueue(q, 10);
    enqueue(q, 12);
    enqueue(q, 12);
    cout<<dequeue(q);
    cout<<dequeue(q);
    cout<<dequeue(q);
    cout<<dequeue(q);
}
