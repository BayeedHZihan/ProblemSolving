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

```cpp
// N-ary Tree Level Order Traversal
vector<vector<int>> levelOrder(Node* root) {
  vector<vector<int>> res;
  queue<Node*> q;
  if (root) q.push(root);
  while(!q.empty()) {
    vector<int> v;
    int size = q.size();
    for (int i=0; i<size; i++) {
      Node* front = q.front();
      q.pop();
      v.push_back(front->val);
      for (auto child: front->children){
        q.push(child);
      }
    }
    res.push_back(v);
  }
  return res;
}
```
