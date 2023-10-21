#include<iostream>

//Node class with insertion and deletion methods for a doubly linked list
class Node{
    public:

    int value;
    Node *next;
    Node *prev;

    Node(int value){
        this->value  = value;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        this->prev = NULL;
        this->next = NULL;
    }

    // method to insert element at Head
    void insertatHead( Node *&head){
        this->next = head;
        this->prev = NULL;
        head->prev = this;
        head =  this;
        return;
    }


    //method to insert element anywhere
    void insertElement(Node *&head, Node *&tail, int index, int count=0){
        
        if(index==0){
            insertatHead(head);
            return;
        }
        else if(head->next == NULL&&count+1 == index){
            head->next = this;
            this->prev = head;
            this->next = NULL;
            tail = this;
            return;
        
        }
        else if(count==index){
            Node *temp = head ->prev;
            this->prev = head->prev;
            this->next = head;
            temp->next = this;
            head->prev = this;

            delete temp;

            return;
        }


        insertElement(head->next,tail,index,++count);
    }
 
};


//traversing a doubly linked list:

//1. printing the linked list
void printList(Node *&head){
    if(head->next==NULL){
        std::cout<<head->value<<std::endl;
        return;
    }
    std::cout<<head->value<<std::endl;
    printList(head->next);
}

//2. getting the length of the said linked list
int getlen(Node *&head,int count= 0){
    if(head->next ==NULL){
        count ++;
        return count;
    }
    count++;
    getlen(head->next,count);
}

int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    
    Node *node2 = new Node(5);
    node2->insertatHead(head);

    Node *node3 = new Node(1);
    node3->insertatHead(head);

    Node *node4 = new Node(11);
    node4->insertElement(head,tail,3);

    printList(head);
    std::cout<<std::endl;
    std::cout<<head->value<<std::endl<<tail->value<<std::endl;
    

}
