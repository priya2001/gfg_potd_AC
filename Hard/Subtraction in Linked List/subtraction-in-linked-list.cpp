//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
      Node* reverseList(Node* head)
    {
        if(head == NULL || head->next == NULL)return head;
        
        Node* prev = NULL;
        Node* curr = head;
        Node* nxt = head->next;
        
        while(nxt)
        {
            curr->next=prev;
            prev = curr;
            curr = nxt;
            
            nxt = nxt->next;
        }
        
        curr->next = prev;
        return curr;
    }
    
    int lengthOfList(Node* node)
    {
        if(node == NULL)return 0;
        return 1 + lengthOfList(node->next);
    }
public:
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
           while(head1 && head1->data == 0)head1 = head1->next;
        while(head2 && head2->data == 0)head2 = head2->next;
        
        // If both are zeroes then difference is zero
        if(head1 == NULL && head2 == NULL){
            Node* zeroNode = new Node(0);
            return zeroNode;
        }
        
        // If one of them is zero then absolute diff is zero
        if(head1 == NULL)return head2;
        if(head2 == NULL)return head1;
        
        int len1 = lengthOfList(head1);
        int len2 = lengthOfList(head2);
        
        // If length of second list is greater then obviously second number is greater, so swap 
        if(len1 < len2)return subLinkedList(head2,head1);
        
        // If lengths are equal , we must decide which one is greater 
        if(len1 == len2)
        {
            Node* temp1 = head1;
            Node* temp2 = head2;
            bool ok = false;
            
            while(temp1 && temp2 && !ok)
            {
                if(temp2->data > temp1->data)
                {
                    return subLinkedList(head2,head1);
                }
                else if(temp2->data < temp1->data)
                {
                    ok = true;
                }
                
                temp1 = temp1->next;
                temp2 = temp2->next;
                len1--;
            }
            
            // If all comparisons are done without disturbing then both numbers are equal
            // So difference between equals is zero
            if(len1 == 0 && !ok){
                Node* zeroNode = new Node(0);
                return zeroNode;
            }
        }
        
        // Reversing lists, as subtractions are performed from end
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        
        // Never ever lose head pointers in LinkedList
        Node* temp1 = head1;
        Node* temp2 = head2;
        int carry = 0;
        
        //New linked list's head and tail
        Node* new_head = NULL;
        Node* tail = NULL;
        
        
        //Recollect 4th class math
        // Remember those boring subtraction methods😒
        while(temp1 && temp2)
        {
            int sum = temp1->data - temp2->data - carry;
            
            if(sum < 0)
            {
                sum = sum + 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            if(new_head == NULL)
            {
                new_head = new Node(sum);
                tail = new_head;
            }
            else
            {
                tail->next = new Node(sum);
                tail = tail -> next;
            }
            
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        while(temp1)
        {
            int sum = temp1->data - carry;
            
            if(sum < 0)
            {
                sum = sum + 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            
            tail->next = new Node(sum);
            tail = tail->next;
            temp1 = temp1->next;
        }
        
        // We have performed subtraction by reversing , so reverse answer to get the original one
        new_head = reverseList(new_head);
        
        // Remove leading zeroes
        while(new_head && new_head->next && new_head->data == 0)
        {
            new_head = new_head->next;
        }
        
        return new_head;
        
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends