```cpp
// Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* l3 = new ListNode();
  int cnt = 0;
  ListNode *p1 = l1, *p2 = l2, *p3 = l3;

  while (p1 && p2) {
    int cur = p1->val + p2->val + cnt;
    cnt = cur / 10;
    cur %= 10;
    ListNode* temp = new ListNode(cur);
    p3->next = temp;
    p3 = p3->next;
    p1 = p1->next;
    p2 = p2->next;
  }

  while (p1) {
    int cur = p1->val + cnt;
    cnt = cur/10;
    cur %= 10;
    ListNode* temp = new ListNode(cur);
    p3->next = temp;
    p3 = p3->next;
    p1 = p1->next;
  }

  while (p2) {
    int cur = p2->val + cnt;
    cnt = cur/10;
    cur %= 10;
    ListNode* temp = new ListNode(cur);
    p3->next = temp;
    p3 = p3->next;
    p2 = p2->next;
  }

  if (cnt == 1) {
    p3->next = new ListNode(1);
  }

  return l3->next;
}
```

```cpp
// Merge Nodes in Between Zeros
ListNode* mergeNodes(ListNode* head) {
  ListNode* itr = new ListNode();
  ListNode* newHead = itr;
  int sum = 0;
  head = head->next;
  while (head) {
    if (head->val == 0) {
      ListNode* temp = new ListNode(sum);
      itr->next = temp;
      itr = itr->next;
      sum = 0;
    }
    else {
      sum += head->val;
    }
    head = head->next;
  }
  return newHead->next;
}
```

```cpp
// Maximum Twin Sum of a Linked List
int pairSum(ListNode* head) {
  vector<int> v;
  while (head) {
    v.push_back(head->val);
    head = head->next;
  }
  int res = 0;
  int l = 0, r = v.size() - 1;
  while (l < r) {
    res = max(res, v[l] + v[r]);
    l++, r--;
  }
  return res;
}
```

```cpp
// Spiral Matrix IV
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
  vector<vector<int>> res(m, vector<int> (n, -1));
  int row = 0, col = 0;
  while(head) {
    //go right
    while (col < n && head && res[row][col] == -1) {
      res[row][col] = head->val;
      col++;
      head = head->next;
    }
    col--;
    row++;
    //go down
    while(row < m && head && res[row][col] == -1) {
      res[row][col] = head->val;
      row++;
      head = head->next;
    }
    row--;
    col--;
    //go left
    while(col >= 0 && head && res[row][col] == -1) {
      res[row][col] = head->val;
      col--;
      head = head->next;
    }
    col++;
    row--;
    //go up
    while(row >= 0 && head && res[row][col] == -1) {
      res[row][col] = head->val;
      row--;
      head = head->next;
    }
    row++;
    col++;
  }
  return res;
}
```

```cpp
// Odd Even Linked List
ListNode* oddEvenList(ListNode* head) {
  if (!head || !head->next) return head;
  ListNode *p = head->next, *last;
  int n = 1;
  while (1){
    last = p;
    for (int i=0; i<n; i++) {
        last = last->next;
        if (!last) return head;
    }
    ListNode* part = p;
    while (part!=last){
        swap(last->val, part->val);
        part = part->next;
    }
    p = p->next;
    n++;
  }
  return head;
}
```

```cpp
// Swap Nodes in Pairs
ListNode* swapPairs(ListNode* head) {
  if (!head || !head->next) return head;
  ListNode *first = head, *third = head->next->next;
  head->next->next = first;
  head = first->next;
  first->next = swapPairs(third);
  return head;
}
```

```cpp
// Populating Next Right Pointers in Each Node
Node* connect(Node* root) {
  dfs(root, NULL);
  return root;
}
void dfs (Node* l, Node* r){
  if (!l) return;
  l->next = r;
  dfs(l->left, l->right);
  dfs(l->right, l->next ? l->next->left : NULL);
}
```

```cpp
// Sort List
ListNode* sortList(ListNode* head) {
  if (!head) return NULL;
  vector<int> v;
  listToV(head, v);
  sort(v.begin(), v.end());
  return vToList(v);
}
void listToV (ListNode* head, vector<int>& v) {
  while (head) {
    v.push_back(head->val);
    head = head->next;
  }
}
ListNode* vToList (vector<int>& v) {
  ListNode* head = new ListNode(v[0]), *cur = head;
  for (int i=1; i<v.size(); i++){
    cur->next = new ListNode(v[i]);
    cur = cur->next;
  }
  return head;
}
```

```cpp
// Copy List with Random Pointer
Node* copyRandomList(Node* head) {
  if (!head) return head;
  Node* newHead = cloneList(head);
  Node* hp = head, *np = newHead;
  while (hp) {
    Node* curRand = hp->random;
    Node* p1 = head, *p2 = newHead;
    while (p1 != curRand) {
      p1 = p1->next;
      p2 = p2->next;
    }
    np->random = p2;
    hp = hp->next;
    np = np->next;
  }
  return newHead;
}
Node* cloneList (Node* head) {
  Node* newHead = new Node(head->val);
  Node* prev = newHead;
  Node* temp = head;
  while (temp) {
    temp = temp->next;
    if (temp) prev->next = new Node(temp->val);
    else prev->next = NULL;
    prev = prev->next;
  }
  return newHead;
}
```

```cpp
// Linked List Cycle II

// L1 is defined as the distance between the head point and entry point
// L2 is defined as the distance between the entry point and the meeting point
// Distance traveled by slow when they meet: L1+L2
// Distance traveled by fast when they meet: L1+L2+x+L2, where x is the remaining length of the cycle (meeting point to start of the cycle).

// 2(L1+L2) = L1+L2+x+L2
// 2L1 + 2L2 = L1+2L2+x
// => x = L1
ListNode *detectCycle(ListNode *head) {
  ListNode *fast, *slow;
  fast = slow = head;
  while (fast && fast->next){
    fast = fast->next->next;
    slow = slow->next;
    if (fast==slow) break;
  }
  if (!fast || !fast->next) return NULL;
  fast = head;
  while(slow != fast){
    fast = fast->next;
    slow = slow->next;
  }
  return fast;
}
```

```cpp
// Remove Nth Node From End of List
ListNode* removeNthFromEnd(ListNode* head, int n) {
  int len = 0;
  ListNode* temp = head;
  while(temp){
    len++;
    temp = temp->next;
  }
  n = len - n;
  if (n == 0) {
    head = head->next;
    return head;
  }
  n--;
  temp = head;
  while (n--) temp = temp->next;
  temp->next = temp->next->next;
  return head;
}
```

```cpp
// Rotate List
ListNode* rotateRight(ListNode* head, int k) {
  if (!head) return head;
  ListNode* travTemp = head;
  int cnt = 0;
  while (travTemp){
    cnt++;
    travTemp = travTemp->next;
  }
  k = k%cnt;
  while (k--){
    ListNode* temp = head;
    while (temp && temp->next && temp->next->next){
      temp = temp->next;
    }
    ListNode* last = temp->next;
    temp->next = NULL;
    if (last){
      last->next = head;
      head = last;
    }
  }
  return head;
}
```
