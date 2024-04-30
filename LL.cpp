class Node{
public:
    int data;
    Node* next;
    
    Node(int data1){
        data = data1;
        next = nullptr;
    }
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

void print(Node* head){
    Node* curr = head;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

Node* reverse(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

Node* create(vector<int>& arr){
    int n = arr.size();
    if(n == 0) return nullptr;
    Node* curr = new Node(arr[0]);
    Node* head = curr;
    for(int i=1; i<n; i++){
        Node* temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }
    return head;
}


int main() {
    vector<int>arr(5);
    arr = {1, 2, 3, 4, 5};
    Node* head = create(arr);
    print(head);
    head = reverse(head);
    cout<<endl;
    print(head);
}
