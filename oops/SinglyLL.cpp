#include<iostream>

//creating a node.,
class Node{
    public:
    //data
    int data;

    Node *next;


    Node(int data){
        this -> data = data;
        this -> next = nullptr;
    }
};

 //insertion at head
void insertHead(Node *&head, int data){
        Node *temp = new Node(data);
        temp -> next =  head;
        head = temp;
}


//insertion at tail
void insertTail(Node *&tail, int data){
    Node *temp  = new Node(data);
    tail -> next = temp;
    tail = temp;
}


//generic insertion 
void insertMiddle(Node *&head,Node *&tail, int data, int pos,int count = 1){
    
    if(head->next == NULL&&count==pos){
        insertTail(tail,data);
        return;
        }
    
   else  if(pos==1){
        insertHead(head,data);
        return;
    }
    else if(count == pos){
        Node *temp  = new Node(data);
        temp -> next = head->next;
        head ->next  = temp;
        return;
    }

    insertMiddle(head->next,tail,data,pos,count+1);
}

//generic deletion






//print
void printList(Node *&temp){
    if(temp->next ==nullptr){
        std::cout<<temp->data<<std::endl;
        return;
    }
    std::cout<<temp -> data<<std::endl;
    printList(temp->next);

}
int main(){


    Node *node1 = new Node(10);
    
    Node *head  = node1;
    Node *tail = node1;
    insertHead(head, 5);
    insertTail(tail,15);
    insertMiddle(head,tail,8,3);
    printList(head);

    std::cout<<std::endl;
    std::cout<<head->data<<" "<<tail->data;
    
    
}