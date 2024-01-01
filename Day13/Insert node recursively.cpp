/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
Node* InsertNode(Node *head, int pos, Node* newNode)
{
     if (pos < 0) {
        std::cout << "Invalid position\n";
        return head;
    }

    if (pos == 0) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    int currentPos = 0;
    while (current != nullptr && currentPos < pos - 1) {
        current = current->next;
        currentPos++;
    }

    if (current == nullptr) {
        std::cout << "Position out of range\n";
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
   
}
