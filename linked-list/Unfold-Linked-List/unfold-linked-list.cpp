#include <iostream>
using namespace std;

class ListNode
{
public:
  int val = 0;
  ListNode* next = nullptr;

  ListNode(int val)
  {
    this->val = val;
  }
};

ListNode* reverse(ListNode*head) {
    if(!head || !head->next) {
        return head;
    }
    
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *frwd = NULL;
    
    while(curr) {
        frwd = curr->next;  //backup
        curr->next = prev;  //link
        prev = curr;        //move
        curr = frwd;
    }
    
    return prev;
}

void unfold(ListNode* head)
{
    if(!head || !head->next) {
        return;
    }
    
    ListNode *fh = head;
    ListNode *fp = head;
    
    ListNode *sh = head->next;
    ListNode *sp = head->next;
    
    while(sp && sp->next) {
        ListNode *f = sp->next;   //backup
        
        fp->next = f;             //link
        sp->next = f->next;
        
        fp = fp->next;           //move
        sp = sp->next;
    }
    fp->next = NULL;
    
    sh = reverse(sh);
    fp->next = sh;
}

void printList(ListNode* node)
{
  ListNode* curr = node;
  while (curr != nullptr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;
}

int main()
{
  int n;
  cin >> n;
  ListNode* dummy = new ListNode(-1);
  ListNode* prev = dummy;
  while (n-- > 0)
  {
    int val;
    cin >> val;
    prev->next = new ListNode(val);
    prev = prev->next;
  }

  ListNode* head = dummy->next;
  unfold(head);
  printList(head);

  return 0;
}
