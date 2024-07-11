#include<iostream>
using namespace std;
struct ListNode{
    int value;
    ListNode* next;
    ListNode(int x):value(x),next(nullptr){}
};
ListNode * reverseLinkedList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;
    while(current != nullptr){
        next = current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return  prev;
};
void display(ListNode* head){
    while(head != nullptr){
        cout<<head->value<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    ListNode* head=new ListNode(1);
    head->next = new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    cout<<"Original Linked List "<<endl;
    display(head);
    cout<<"Reverse Linked List "<<endl;
    ListNode* reverseHead=reverseLinkedList(head);
    display(reverseHead);
}