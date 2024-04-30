//Implement Stack Using array
struct Stack{
    int top;
    int capacity;
    int* array;
};

Stack* createStack(int capacity){
    struct Stack* st = new Stack;
    if(!st){
        return NULL;
    }
    st->top = -1;
    st->capacity = capacity;
    st->array = new int[st->capacity];
    if(!st->array) return NULL;
    return st;
}

int isFull(Stack* st){
    return st->top == st->capacity-1;
}

int isEmpty(Stack* st){
    return st->top == -1;
}

void push(Stack* st, int data){
    if(isFull(st)) return;
    st->array[++st->top] = data;
}

int pop(Stack* st){
    if(isEmpty(st)) return -1;
    int data = st->array[st->top--];
    return data;
}

int peek(Stack* st){
    if(isEmpty(st)) return -1;
    return st->array[st->top];
}

void deleteStack(Stack* st){
    if(st){
        if(st->array){
            free(st->array);
        }
        free(st);
    }
}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Stack* st = createStack(5);
    push(st, arr[0]);
    push(st, arr[1]);
    push(st, arr[2]);
    cout<<pop(st)<<endl;
    
    cout<<peek(st);
    
    
}
