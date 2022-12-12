#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// A doubly linked list node
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void insert_after(struct Node **cursor, struct Node **head, char new_data)
{

    Node *newNode = new Node;

    Node *last = *cursor;

    if (last == NULL || last->next == NULL)
    {
        newNode->data = new_data;

        newNode->next = NULL;

        if (*head == NULL)
        {
            newNode->prev = NULL;
            *head = newNode;
            *cursor = newNode;
            return;
        }

        last->next = newNode;
        newNode->prev = last;
        *cursor = newNode;
    }

    else
    {
        newNode->data = new_data;

        // set next of newnode to next of prev node
        newNode->next = last->next;

        // set next of prev node to newnode
        last->next = newNode;

        // now set prev of newnode to prev node
        newNode->prev = last;

        // set prev of new node's next to newnode
        if (newNode->next != NULL)
            newNode->next->prev = newNode;
    }
    return;
}

void deleteNode(Node **head, Node *del)
{   
    Node *curr = del;
    if(curr->next == NULL) {
        cout << "Cursor at rightmost char. No char can be deleted!" << "\n";
        return;
    }
    curr = curr->next;

    /* base case */
    if (*head == NULL || curr == NULL)
        return;

    /* If node to be deleted is head node */
    if (*head == curr)
        *head = curr->next;

    /* Change next only if node to be 
    deleted is NOT the last node */
    if (curr->next != NULL)
        curr->next->prev = del;
    
    /* Change prev only if node to be
    deleted is NOT the first node */
    if (curr->prev != NULL)
        curr->prev->next = curr->next;

    /* Finally, free the memory occupied by del*/
    free(curr);
    return;
}

void right(struct Node **cursor)
{
    Node *curr = *cursor;
    if(curr->next == NULL){
        cout<<"Already at rightmost character \n";
        return;
    }
    else if (curr->next != NULL)
    {
        curr = curr->next;
    }
    *cursor = curr;
    return;
}
void left(struct Node **cursor)
{
    Node *curr = *cursor;
    if(curr->prev == NULL){
        cout<<"Already at leftmost character \n";
        return;
    }
    else if (curr->prev != NULL)
    {
        curr = curr->prev;
    }
    *cursor = curr;
    return;
}

void displayList(struct Node *node)
{
    Node *last;

    while (node != NULL)
    {
        cout << char(node->data) << " ";
        last = node;
        node = node->next;
    }
    if (node == NULL)
        cout << "";
}
void displayAtCursor(struct Node *node)
{
    if (!node)
    {
        cout << "cursor not initiated";
    }
    else
        cout << char(node->data);

    return;
}

void console()
{
    cout << "\n[1] Insert an element.";
    cout << "\n[2] Remove an element.";
    cout << "\n[3] Move cursor to left";
    cout << "\n[4] Move cursor to right";
    cout << "\n[5] char at current cursor";
    cout << "\n[6] Display List";
    cout << "\n[7] Exit";
}

// main program
int main()
{
    /* Start with the empty list */
    Node *head = NULL;
    Node *cursor = NULL;
    char c;
    char i;

    while (1)
    {
        console();
        cout << "\n+-------------------------------+";
        cout << "\nEnter your choice: ";
        cin >> c;
        switch (c)
        {
        case '1':
            cout << "Enter an element to insert: ";
            cin >> i;

            insert_after(&cursor, &head, i);
            displayList(head);

            break;
        case '2':

            deleteNode(&head, cursor);
            displayList(head);

            break;
        case '3':
            cout << "Move Cursor to left \n";
            left(&cursor);
            cout<<"The cursor now points at char: ";
            displayAtCursor(cursor);
            break;
            
        case '4':
            cout << "Move cursor to right \n";
            right(&cursor);
            cout<<"The cursor now points at char: ";
            displayAtCursor(cursor);

            break;
        case '5':
            cout<<"The cursor points at char: ";
            displayAtCursor(cursor);

            break;
        case '6':
            displayList(head);
            break;
        case '7':
            exit(0);
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    //    // Insert 40 as last node
    //    insert_end(&head, 'a');

    //    // insert 20 at the head
    //    insert_front(&head, 'b');

    //    // Insert 10 at the beginning.
    //    insert_front(&head, 'c');

    //    // Insert 50 at the end.
    //    insert_end(&head, 'd');

    //    // Insert 30, after 20.
    //    insert_After(head->next, 'e');

    //    cout<<"Doubly linked list is as follows: "<<endl;
    //    displayList(head);
    return 0;
}