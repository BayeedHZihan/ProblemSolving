```cpp
// Populating Next Right Pointers in Each Node
Node* connect(Node* root) {
  if (!root) return root;
  queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    int size = q.size();
    Node* last = NULL;
    for (int i=0; i<size; i++) {
      Node* front = q.front();
      q.pop();
      if (front->left) {
        q.push(front->left);
        q.push(front->right);
      }
      if (last != NULL) last->next = front;
      last = front;
    }
    last->next = NULL;
  }
  return root;
}
```
