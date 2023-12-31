/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

int addOneHelper(Node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    int res = head->data + addOneHelper(head->next);
    head->data = res % 10;
    return res / 10;
}

Node *addOne(Node *head)
{
    int carry = addOneHelper(head);
    if (carry != 0)
    {

        Node *newHead = new Node(0);
        newHead->data = carry;
        newHead->next = head;
        return newHead;
    }

    return head;
}
