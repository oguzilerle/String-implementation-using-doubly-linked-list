#include "String.h"

String::String() {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */
}

String::String(char *str) {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */

    // str is a null terminated C string.
    // (e.g. ['h','e','l','l','o','\0'])

    char *temp = str;

    while (*temp != '\0') {
        this->characters.insertAtTheEnd(*temp);
        temp++;
    }
}

int String::getLength() const {
    /* TODO */
    return this->characters.getSize();
}

bool String::isEmpty() const {
    /* TODO */
    return this->characters.isEmpty();
}

void String::appendCharacter(char character) {
    /* TODO */
    this->characters.insertAtTheEnd(character);
    
}

void String::insertCharacter(char character, int pos) 
{
    /* TODO */
    if(this->characters.getSize() > pos)
    {
        Node<char> *temp = this->characters.getNodeAtIndex(pos);
        this->characters.insertBeforeGivenNode(character, temp);
    }
    if(this->characters.getSize() == pos)
    {
        this->characters.insertAtTheEnd(character);
    }
}

void String::eraseCharacters(int pos, int len) {
    /* TODO */
    if(this->getLength() > (pos+len-1))
    {
        int i;
        for (i = pos; i<pos+len; i++)
        {
            Node<char> *temp = this->characters.getNodeAtIndex(i);
            this->characters.deleteNode(temp);
        }
    }
}

void String::eraseAllCharacters() {
    /* TODO */
    this->characters.deleteAllNodes();
}

String String::substring(int pos, int len) {
    /* TODO */
    String newString;
    int size, i;
    
    size = this->getLength();
    
    if ((size < pos+len) || (len == 0))
    {
        return newString;
    }
    else
    {
        for (i = pos; i < pos+len ; i++)
        {
            Node<char> *node = this->characters.getNodeAtIndex(i);
            newString.appendCharacter(node->data);
        }
    }
    return newString;
}

LinkedList<String> String::split(char separator) {
    /* TODO */
    LinkedList<String> list;
    String subs;
    String empty;
    int i, pos, len, size, count;
    Node<char> *head = this->characters.getActualHead();
    Node<char> *temp = head;
    size = this->getLength();
    len = 0;
    pos = 0;

    for (i = 0; i < size; i++)
    {
        count = 0;
        len += 1;
        if(head->data == separator)
        {
            while (temp->data == temp->next->data)
            {
                count += 1;
                temp = temp->next;
            }
            subs = this->substring(pos, len-1);
            pos += len;
            pos += count;
            len = 0;
            list.insertAtTheEnd(subs);
            
            while (head->data == head->next->data)
            {
                empty.insertCharacter('9', 0);
                empty.eraseAllCharacters();
                list.insertAtTheEnd(empty);
                i += 1;
                head = head->next;
            }
        }
        head = head->next;
        temp = temp->next;
    }
    
    subs = this->substring(pos, len);
    list.insertAtTheEnd(subs);
    return list;
    
    
}

bool String::isPalindrome() const {
    /* TODO */
    int size, i, j;
    size = this->characters.getSize();
    j = size-1;
    if (size <= 1)
    {
        return true;
    }

    for (i = 0; i<size/2; i++)
    {
        Node<char> *firstNode = this->characters.getNodeAtIndex(i);
        Node<char> *lastNode = this->characters.getNodeAtIndex(j);
        
        while (firstNode->data == ' ')
        {
            firstNode = firstNode->next;
            i += 1;
        }
        
        while (lastNode->data == ' ')
        {
            lastNode = lastNode->prev;
            j -= 1;
        }
        
        if (firstNode->data != lastNode->data)
        {
            return false;
        }
        j = j - 1;
    }
    return true;
    
}

bool String::operator<(const String &rhs) const {
    /* TODO */
    Node<char> *first = this->characters.getActualHead();
    Node<char> *last = this->characters.getDummyTail();
    Node<char> *sec = rhs.characters.getActualHead();
    int firstAscii, secAscii;
    
    while (first != last)
    {
        firstAscii = first->data;
        secAscii = sec->data;
        if (((firstAscii >= 97) && (secAscii >= 97)) || ((firstAscii < 97) && (secAscii < 97)))
        {
            if (firstAscii > secAscii)
            {
                return false;
            }
            if (firstAscii < secAscii)
            {
                return true;
            }
        }
        else if ((firstAscii > 32) && (firstAscii < 97))
        {
            firstAscii += 32;
            if (firstAscii > secAscii)
            {
                return false;
            }
            if (firstAscii < secAscii)
            {
                return true;
            }
        }
        else if ((secAscii > 32) && (secAscii < 97))
        {
            secAscii += 32;
            if (firstAscii > secAscii)
            {
                return false;
            }
            if (firstAscii < secAscii)
            {
                return true;
            }
        }
        else if (secAscii == 0) 
        {
            return false;
        }
        first = first->next;
        sec = sec->next;
    }
    
    return true;
}

void String::print(bool verbose) {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */

    Node<char> *node = this->characters.getActualHead();
    Node<char> *actualTailNode = this->characters.getActualTail();

    if (verbose) {
        std::cout << "[";
    }

    while (node && node->next) {
        if (verbose) {
            std::cout << "'" << node->data << "'";
            if (node != actualTailNode) {
                std::cout << ",";
            }
        } else {
            std::cout << node->data;
        }

        node = node->next;
    }

    if (verbose) {
        std::cout << "]";
    }

    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &os, const String &string) {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */

    Node<char> *node = string.characters.getActualHead();

    while (node && node->next) {
        os << node->data;
        node = node->next;
    }

    return os;
}
