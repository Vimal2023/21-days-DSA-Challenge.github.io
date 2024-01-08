/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K) {
    if (head == NULL) {
        return head;
    }

    vector<Node*> nodeList;
    Node* temp = head;
    while (temp != NULL) {
        nodeList.push_back(temp);
        temp = temp->next;
    }
    if (K == nodeList.size()) {
        Node* next = head->next;
        head->next = NULL;
        delete head;
        head = next;
    } else {
        nodeList[nodeList.size() - K - 1]->next = nodeList[nodeList.size() - K]->next;
        
        delete nodeList[nodeList.size() - K];
    }
    return head;
}
