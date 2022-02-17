#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template<class T>
class LinkedList {
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T> &obj);

    ~LinkedList();

    int getSize() const;
    bool isEmpty() const;
    bool contains(Node<T> *node) const;

    Node<T> *getDummyHead() const;
    Node<T> *getDummyTail() const;
    Node<T> *getActualHead() const;
    Node<T> *getActualTail() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void insertAtTheBeginning(const T &data);
    void insertAtTheEnd(const T &data);
    void insertBeforeGivenNode(const T &data, Node<T> *node);

    void deleteNode(Node<T> *node);
    void deleteNode(const T &data);
    void deleteAllNodes();

    void swapNodes(Node<T> *node1, Node<T> *node2);

    void traverse() const;

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *dummyHead;
    Node<T> *dummyTail;
};

template<class T>
LinkedList<T>::LinkedList() {
    /* TODO */
    
    this->dummyTail = new Node<T>();
    this->dummyHead = new Node<T>();
    this->dummyHead->next = this->dummyTail;
    this->dummyTail->prev = this->dummyHead;
    
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj) 
{
    /* TODO */
    Node<T> *objHead = obj.getActualHead();
    Node<T> *current;
    this->dummyTail = new Node<T>();
    this->dummyHead = new Node<T>();
    this->dummyHead->next = this->dummyTail;
    this->dummyTail->prev = this->dummyHead;
    current = this->dummyHead;
    
    
        
    
        while((objHead != NULL) && (objHead != obj.getDummyTail()))
        {
            Node<T> *temp = new Node<T>();
            
            temp->prev = current;
            temp->data = objHead->data;
            temp->next = current->next;
            
            temp->prev->next = temp;
            temp->next->prev = temp;
            
            
            current = current->next;
            objHead = objHead->next;
        }
        
    }
    

template<class T>
LinkedList<T>::~LinkedList() {
    /* TODO */

    this->deleteAllNodes();
    
    delete this->dummyHead;
    delete this->dummyTail;
}

template<class T>
int LinkedList<T>::getSize() const {
    /* TODO */
    int size = 0;
    Node<T> *temp = this->dummyHead;
    
    while (temp->next != this->dummyTail)
    {
        size += 1;
        temp = temp->next;
    }
    return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const {
    /* TODO */
    return (this->dummyHead->next == this->dummyTail);
    
}

template<class T>
bool LinkedList<T>::contains(Node<T> *node) const {
    /* TODO */
    Node<T> *temp = this->dummyHead->next;
    
    while (temp != this->dummyTail)
    {
        if ((temp->prev == node->prev) && (temp->data == node->data) && (temp->next == node->next))
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<class T>
Node<T> *LinkedList<T>::getDummyHead() const {
    /* TODO */
    Node<T> *dummy = this->dummyHead;
    
    return dummy;
}

template<class T>
Node<T> *LinkedList<T>::getDummyTail() const {
    /* TODO */
    Node<T> *dummy = this->dummyTail;
    
    return dummy;
    
}

template<class T>
Node<T> *LinkedList<T>::getActualHead() const {
    /* TODO */
    Node<T> *dummy = this->dummyHead->next;
    
    if (this->dummyHead->next == this->dummyTail)
    {
        return NULL;
    }
    
    return dummy;
}

template<class T>
Node<T> *LinkedList<T>::getActualTail() const {
    /* TODO */
    Node<T> *dummy = this->dummyTail->prev;
    
    if(this->dummyTail->prev == this->dummyHead)
    {
        return NULL;
    }
    
    return dummy;
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const {
    /* TODO */
    Node<T> *temp = this->dummyHead->next;
    
    while (temp != this->dummyTail)
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const {
    /* TODO */
    int i;
    int nodeCount;
    Node<T> *temp = this->dummyHead->next;
    i = 0;
    if (temp == this->dummyTail)
    {
        return NULL;
    }
    while (temp != this->dummyTail)
    {
        if (i == index)
        {
            return temp;
        }
        i++;
        temp = temp->next;
    }
    return NULL;
}

template<class T>
void LinkedList<T>::insertAtTheBeginning(const T &data) {
    /* TODO */
    Node<T> *newHead = new Node<T>();
    
    newHead->prev = this->dummyHead;
    newHead->data = data;
    newHead->next = this->dummyHead->next;
    
    newHead->prev->next = newHead;
    newHead->next->prev = newHead;
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data) {
    /* TODO */
    Node<T> *newTail = new Node<T>();
    
    newTail->prev = this->dummyTail->prev;
    newTail->data = data;
    newTail->next = this->dummyTail;
    
    newTail->prev->next = newTail;
    newTail->next->prev = newTail;
}

template<class T>
void LinkedList<T>::insertBeforeGivenNode(const T &data, Node<T> *node) {
    /* TODO */
    if (this->contains(node))
    {
        Node<T> *newNode = new Node<T>();
        
        newNode->prev = node->prev;
        newNode->data = data;
        newNode->next = node;
        
        newNode->prev->next = newNode;
        newNode->next->prev = newNode;
    }
}

template<class T>
void LinkedList<T>::deleteNode(Node<T> *node) {
    /* TODO */
    if (this->contains(node))
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        delete node;
    }
}

template<class T>
void LinkedList<T>::deleteNode(const T &data) {
    /* TODO */
    if (this->getNode(data))
    {
        Node<T> *node = this->getNode(data);
        
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        delete node;
    }
}

template<class T>
void LinkedList<T>::deleteAllNodes() {
    /* TODO */
    
    if (this->dummyHead->next != this->dummyTail)
    {
        Node<T> *first = this->dummyHead->next;
        Node<T> *second = first->next;
        
        while (second != this->dummyTail)
        {
            first->prev->next = first->next;
            first->next->prev = first->prev;
            
            delete first;
            
            first = second;
            second = second->next;
        }
        first->prev->next = first->next;
        first->next->prev = first->prev;
        
        delete first;
    }
    
    
}

template<class T>
void LinkedList<T>::swapNodes(Node<T> *node1, Node<T> *node2) {
    /* TODO */
    if((this->contains(node1)) && (this->contains(node2)))
    {   
        if (node2->next == node1)
        {
            Node<T> *node2Next = node2->next;
            Node<T> *node2Prev = node2->prev;
            Node<T> *node1Next = node1->next;
            Node<T> *node1Prev = node1->prev;
            
            node2Prev->next = node1;
            
            node1Next->prev = node2;
            
            node1->prev = node2->prev;
            node1->next = node2;
            
            node2->prev = node1;
            node2->next = node1Next;
        }
        if (node1->next == node2)
        {
            Node<T> *node2Next = node2->next;
            Node<T> *node2Prev = node2->prev;
            Node<T> *node1Next = node1->next;
            Node<T> *node1Prev = node1->prev;
            
            node1Prev->next = node2;
            
            node2Next->prev = node1;
            
            node2->prev = node1->prev;
            node2->next = node1;
            
            node1->prev = node2;
            node1->next = node2Next;
        }
        else
        {
            Node<T> *node2Next = node2->next;
            Node<T> *node2Prev = node2->prev;
            Node<T> *node1Next = node1->next;
            Node<T> *node1Prev = node1->prev;
        
            node1Prev->next = node2;
            node1Next->prev = node2;

            node2Prev->next = node1;
            node2Next->prev = node1;
        
            node2->next = node1->next;
            node2->prev = node1->prev;
        
            node1->next = node2Next;
            node1->prev = node2Prev;
        }
    }
}

template<class T>
void LinkedList<T>::traverse() const {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */

    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T> *node = this->getActualHead();

    while (node && node->next) {
        std::cout << *node << std::endl;
        node = node->next;
    }
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) 
{
    /* TODO */
    Node<T> *rhsActualHead = rhs.getActualHead();

    if (this != &rhs)
    {
        this->deleteAllNodes();
        if ((rhs.getActualHead() != NULL) && (rhs.getActualHead() != rhs.getDummyTail()))
            {
                while(rhsActualHead != rhs.getDummyTail())
                    {
                        this->insertAtTheEnd(rhsActualHead->data);
                        rhsActualHead = rhsActualHead->next;
                    }
            }
    }
    return *this;
}

#endif //LINKEDLIST_H
