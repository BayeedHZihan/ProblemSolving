```cpp
// Find Center of Star Graph
int findCenter(vector<vector<int>>& edges) {
  return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ?
      edges[0][0] : edges[0][1];
}
```

```cpp
// Find if Path Exists in Graph
// dfs
unordered_map<int, vector<int>> graph;
unordered_set<int> visited;
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
  createGraph(n, edges);
  return dfs(source, destination);
}
bool dfs(int src, int dst) {
  if (src == dst) return true;
  if (visited.find(src) != visited.end()) return false;
  visited.insert(src);
  for (auto vertex: graph[src]) {
      if (dfs(vertex, dst)) return true;
  }
  return false;
}
void createGraph(int n, vector<vector<int>>& edges){
  for (auto edge: edges){
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
  }
}
// bfs
bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
  unordered_map<int, vector<int>> graph;
  createGraph(edges, graph);
  return checkIfPath(graph, start, end);
}

bool checkIfPath(unordered_map<int, vector<int>> graph, int start, int end) {
  queue<int> q;
  q.push(start);
  unordered_set<int> visited;
  while (!q.empty()) {
      int cur = q.front();
      if (cur == end) return true;
      visited.insert(cur);
      q.pop();
      for (int i=0; i<graph[cur].size(); i++) {
          if (visited.find(graph[cur][i]) == visited.end())
              q.push(graph[cur][i]);
      }
  }

  return false;
}

void createGraph(vector<vector<int>> edges, unordered_map<int, vector<int>>& graph) {
  for (int i=0; i<edges.size(); i++) {
      graph[edges[i][0]].push_back(edges[i][1]);
      graph[edges[i][1]].push_back(edges[i][0]);
  }
}
```

```cpp
// Find the Town Judge
int findJudge(int N, vector<vector<int>>& trust) {
  int rows = trust.size();
  if (rows==0) return 1;
  vector<int> res;
  for (int i=0; i<rows; i++){
      int suspect = trust[i][1];
      int j;
      for(j=0; j<rows; j++){
          if (trust[j][0] == suspect) break;
          if (trust[j][1] == suspect)
              res.push_back(trust[j][0]);
      }
      if (j==rows){
          sort(res.begin(), res.end());
          int poko = 1;
          for (int i=0; i<res.size(); i++){
              if (poko == suspect) poko++;
              if (res[i]==poko) poko++;
          }
          if (poko>N) return suspect;
          if (poko==N && poko==suspect) return suspect;
      }
      res.clear();
  }
  return -1;
}
```

```cpp
// All Paths From Source to Target
// recursive stack (dfs)
vector<vector<int>> res;
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> v = {0};
    dfs(graph, v, 0);
    return res;
}
void dfs(vector<vector<int>>& graph, vector<int>& path, int src) {
    if (src == graph.size()-1) {
        res.push_back(path);
        return;
    }
    for (auto vertex: graph[src]) {
        path.push_back(vertex);
        dfs(graph, path, vertex);
        path.pop_back();
    }
}
// iterative stack
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
  stack<int> s;
  s.push(0);
  vector<vector<int>> res;
  int dst = graph.size() - 1;
  vector<int> temp;

  while (!s.empty()) {
    int cur = s.top();
    s.pop();

    if (cur == -1) {
      temp.erase(temp.end()-1);
      continue;
    }

    temp.push_back(cur);

    if (cur == dst) res.push_back(temp);

    if (cur == dst || graph[cur].empty()) {
      temp.erase(temp.end()-1);
      continue;
    }

    s.push(-1);
    for (int i=0; i<graph[cur].size(); i++) {
      s.push(graph[cur][i]);
    }
  }

  return res;
}
```

```cpp
// Minimum Number of Vertices to Reach All Nodes
vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
  unordered_set<int> uset;

  for (int i=0; i<edges.size(); i++) {
    uset.insert(edges[i][1]);
  }

  vector<int> res;

  for (int i=0; i<n; i++) {
    if (uset.find(i) == uset.end()) res.push_back(i);
  }

  return res;
}
```

```cpp
// Keys and Rooms
bool canVisitAllRooms(vector<vector<int>>& rooms) {
  int rows = rooms.size();
  rooms[0].push_back(-1);
  for(int i=0; i<rooms[0].size()-1; i++){
    dfs(rooms, 0, i);
  }
  for(int i=0; i<rows; i++){
    int cols = rooms[i].size();
    if (cols == 0) continue;
    if (rooms[i][cols-1] != -1) return false;
  }
  return true;
}
void dfs (vector<vector<int>>& rooms, int i, int j){
  int nr = rooms[i][j], nrcols = rooms[nr].size();
  if (nrcols==0 || rooms[nr][nrcols-1]==-1) return;
  rooms[nr].push_back(-1);
  for(int k=0; k<rooms[nr].size()-1; k++){
      dfs(rooms, nr, k);
  }
}
```

```cpp
// Number of Provinces
int findCircleNum(vector<vector<int>>& isConnected) {
  unordered_map<int, vector<int>> graph;
  int n = isConnected.size();
  //cout << n;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (i != j && isConnected[i][j]==1) graph[i].push_back(j);
    }
  }
  unordered_set<int> visited;
  int res = 0;
  for (int i=0; i<n; i++) {
    if (visited.find(i) == visited.end()) {
      //dfs(graph, visited, i);
      bfs(graph, visited, i);
      res++;
    }
  }
  return res;
}

void bfs(unordered_map<int, vector<int>> graph, unordered_set<int>& visited, int src) {
  queue<int> q;
  q.push(src);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (visited.find(cur) != visited.end()) continue;
    visited.insert(cur);
    for (int i=0; i<graph[cur].size(); i++) {
      if (visited.find(graph[cur][i]) == visited.end())
          q.push(graph[cur][i]);
    }
  }
}

void dfs(unordered_map<int, vector<int>> graph, unordered_set<int>& visited, int src) {
  if (visited.find(src) != visited.end()) return;
  visited.insert(src);
  for (int i=0; i<graph[src].size(); i++) {
    dfs(graph, visited, graph[src][i]);
  }
}
```

```cpp
// Redundant Connection
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
  unordered_map<int, vector<int>> graph;
  createGraph(edges, graph);
  for (int i=edges.size()-1; i>=0; i--) {
    if (check(edges[i][0], edges[i][1], graph)) return edges[i];
  }
  return {};
}
bool check(int x, int y, unordered_map<int, vector<int>> graph) {
  int cnt = 0;
  unordered_set<int> uset;
  uset.insert(x);
  for (int i=0; i<graph[x].size(); i++) {
    if (dfs(graph[x][i], y, graph, uset)) cnt++;
    if (cnt == 2) return true;
  }
  return false;
}
bool dfs(int x, int y, unordered_map<int, vector<int>> graph, unordered_set<int> uset) {
  queue<int> q;
  q.push(x);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == y) return true;
    uset.insert(cur);
    for (int i=0; i<graph[cur].size(); i++) {
      if (uset.find(graph[cur][i]) == uset.end())
        q.push(graph[cur][i]);
    }
  }
  return false;
}
void createGraph(vector<vector<int>>& edges, unordered_map<int, vector<int>>& graph) {
  for (int i=0; i<edges.size(); i++){
    graph[edges[i][0]].push_back(edges[i][1]);
    graph[edges[i][1]].push_back(edges[i][0]);
  }
}
```

```cpp
long long maximumImportance(int n, vector<vector<int>>& roads) {
  // Maximum Total Importance of Roads
  int l = roads.size();
  unordered_map<int, int> freq;
  for (auto road: roads){
    freq[road[0]]++, freq[road[1]]++;
  }
  vector<pair<int, int>> s;
  for (auto i=freq.begin(); i!=freq.end(); i++) {
    s.push_back(*i);
  }
  sort(s.begin(), s.end(), [=](pair<int, int>& a, pair<int, int>& b){
    return a.second > b.second;
  });
  unordered_map<int, int> cnt;
  int cur = n;
  for (auto pair: s) {
    cnt[pair.first] = n;
    n--;
  }
  long long res = 0;
  for (auto road: roads) {
    res += cnt[road[0]] + cnt[road[1]];
  }
  return res;
}
```

```cpp
// Evaluate Division
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
  vector<double> res;
  unordered_map<string, vector<pair<string, double>>> graph;
  for (int i=0; i<equations.size(); i++) {
    graph[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
    graph[equations[i][1]].push_back(make_pair(equations[i][0], 1/values[i]));
  }
  for (int i=0; i<queries.size(); i++) {
    unordered_set<string> vis;
    double ans = dfs(queries[i][0], queries[i][1], graph, vis, 1.0);
    res.push_back(ans);
  }
  return res;
}
double dfs(string src, string dst, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& vis, double val) {
  if (src == dst && graph.find(src) != graph.end()) return val;
  vis.insert(src);
  for (int i=0; i<graph[src].size(); i++) {
    if (vis.find(graph[src][i].first) == vis.end()) {
      double res = dfs(graph[src][i].first, dst, graph, vis, val*graph[src][i].second);
      if (res != - 1.0) return res;
    }
  }
  return -1.0;
}
```

```cpp
// Maximal Network Rank
int maximalNetworkRank(int n, vector<vector<int>>& roads) {
  unordered_map<int, vector<int>> graph;
  for (int i=0; i<roads.size(); i++) {
    graph[roads[i][0]].push_back(roads[i][1]);
    graph[roads[i][1]].push_back(roads[i][0]);
  }
  int most = 0, secmost = 0;
  for (auto itr=graph.begin(); itr!=graph.end(); itr++){
    int size = itr->second.size();
    if (size > most) {
      secmost = most;
      most = size;
    }
    else if (size > secmost) secmost = size;
  }
  if (most == 0) return 0;
  //cout << most << " " << secmost;
  vector<int> firvec, secvec;
  for (auto itr=graph.begin(); itr!=graph.end(); itr++){
    int size = itr->second.size();
    if (size == most) firvec.push_back(itr->first);
    else if (size == secmost) secvec.push_back(itr->first);
  }
  int fs = firvec.size();
  int cnt = 0;
  if (fs > 1) {
    for (int i=0; i<fs; i++) {
      for (int j=i+1; j<fs; j++) {
        cnt = 0;
        for (int k=0; k<graph[firvec[j]].size(); k++) {
          if (graph[firvec[j]][k] == firvec[i]) {
            cnt = 1;
            break;
          }
        }
        if (cnt == 0) return most*2;
      }
    }
    return most*2-1;
  }
  int ss = secvec.size();
  for (int i=0; i<ss; i++) {
    cnt = 0;
    for (int j=0; j<graph[secvec[i]].size(); j++){
      if (graph[secvec[i]][j] == firvec[0]) {
        cnt = 1;
        break;
      }
    }
    if (cnt == 0) return most + secmost;
  }
  return most + secmost - 1;
}
```

```cpp
// Most Stones Removed with Same Row or Column
int removeStones(vector<vector<int>>& stones) {
  unordered_map<int, vector<int>> graph;
  int n = stones.size();
  for (int i=0; i<n; i++) {
    int ck = 0;
    for (int j=i+1; j<n; j++) {
      if (stones[j][0] == stones[i][0] || stones[j][1] == stones[i][1]) {
        graph[i].push_back(j);
        graph[j].push_back(i);
        ck = 1;
      }
    }
    if (ck == 0) graph.insert(make_pair(i, vector<int>{}));
  }
  unordered_set<int> visited;
  int cnt = 0;
  for (int i=0; i<n; i++) {
    if (visited.find(i) == visited.end()) {
      cnt++;
      dfs(i, visited, graph);
    }
  }
  return n - cnt;
}
void dfs(int src, unordered_set<int>& visited, unordered_map<int, vector<int>>& graph) {
  visited.insert(src);
  for (int i=0; i<graph[src].size(); i++) {
    if (visited.find(graph[src][i]) == visited.end()) {
      dfs(graph[src][i], visited, graph);
    }
  }
}
```

```cpp
// Is Graph Bipartite?
bool isBipartite(vector<vector<int>>& graph) {
  int n = graph.size();
  vector<int> colors(n, 0);
  for (int i=0; i<n; i++) {
    if (colors[i] == 0 && !valid(graph, colors, i, 1)) return false;
  }
  return true;
}
bool valid (vector<vector<int>>& graph, vector<int>& colors, int node, int color) {
  if (colors[node] != 0) {
    return colors[node] == color;
  }
  colors[node] = color;
  for (int i=0; i<graph[node].size(); i++) {
    if (!valid(graph, colors, graph[node][i], -color))
      return false;
  }
  return true;
}
```

```cpp
// Network Delay Time
typedef pair<int,int> pd;

struct myComp {
  constexpr bool operator()(
    pair<int, int> const& a,
    pair<int, int> const& b)
    const noexcept
  {
    return b.second < a.second;
  }
};

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
  unordered_map<int, vector<pair<int,int>>> graph;
  for (int i=0; i<times.size(); i++) {
    graph[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
  }
  vector<int> dist(n+1, INT_MAX);
  dist[k] = 0;
  priority_queue <pd, vector<pd>, myComp> pq;
  pq.push(make_pair(k, 0));
  unordered_set<int> visited;
  while (!pq.empty()) {
    int curkey = pq.top().first;
    int curval = pq.top().second;
    if (dist[curkey] >= curval) dist[curkey] = curval;
    if (visited.find(curkey) == visited.end()) {
      visited.insert(curkey);
      for (int i=0; i<graph[curkey].size(); i++) {
        int key = graph[curkey][i].first;
        int val = graph[curkey][i].second + curval;
        pq.push(make_pair(key, val));
      }
    }
    pq.pop();
  }
  int ans = dist[1];
  for (int i=2; i<=n; i++) {
    ans = max(ans, dist[i]);
  }
  return ans == INT_MAX ? -1 : ans;
}
```

```cpp
// All Ancestors of a Node in a Directed Acyclic Graph
vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
  unordered_map<int, vector<int>> graph;
  createGraph(n, edges, graph);
  vector<vector<int>> res(n, vector<int> {});
  for (int i=0; i<n; i++) {
    unordered_set<int> vis;
    dfs(i, i, graph, vis, res);
  }
  return res;
}
void dfs(int src, int dst, unordered_map<int, vector<int>>& graph, unordered_set<int>& vis, vector<vector<int>>& res) {
  if (vis.find(dst) != vis.end()) return;
  vis.insert(dst);
  if (src != dst) res[dst].push_back(src);
  for (int i=0; i<graph[dst].size(); i++) {
    dfs(src, graph[dst][i], graph, vis, res);
  }
}
void createGraph(int n, vector<vector<int>>& edges, unordered_map<int, vector<int>>& graph) {
  for (auto edge: edges) {
    graph[edge[0]].push_back(edge[1]);
  }
  for (int i=0; i<n; i++) {
    if (graph.find(i) == graph.end()) graph[i] = {};
  }
}
```

```cpp
vector<vector<int>> edges;
unordered_map<int, vector<int>> graph;
vector<bool> vis;
int n;
long long res = 0, sum = 0, curConn = 0;
long long countPairs(int nodesCount, vector<vector<int>>& e) {
  edges = e;
  n = nodesCount;
  createGraph();
  initVis();
  for (int i=0; i<n; i++) {
    if (!vis[i]) {
      countConnected(i);
      long long cur = curConn;
      res += sum * cur;
      sum += cur;
      curConn = 0;
    }
  }
  return res;
}
void countConnected(int src) {
  if (vis[src]) return;
  vis[src] = true;
  curConn++;
  for (auto node: graph[src]) {
    countConnected(node);
  }
}
void createGraph() {
  for (auto edge: edges) {
    graph[edge[0]].push_back(edge[1]);
    graph[edge[1]].push_back(edge[0]);
  }
  for (int i=0; i<n; i++) {
    if (graph.find(i) == graph.end()) graph[i] = {};
  }
}
void initVis() {
  for (int i=0; i<n; i++) vis.push_back(false);
}
```

```cpp
// Shortest Path in Binary Matrix
int n;
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
  n = grid.size();
  queue<pair<int,int>> q;
  if (grid[0][0] == 0) q.push({0,0});
  vector<vector<int>> visited(n, vector<int> (n, false));
  int res = 1;
  while(!q.empty()) {
    int size = q.size();
    for (int i=0; i<size; i++) {
      auto front = q.front();
      q.pop();
      if (front.first == n-1 && front.second == n-1) return res;
      if (visited[front.first][front.second]) continue;
      visited[front.first][front.second] = true;
      pushNeighbors(q, front, grid);
    }
    res++;
  }
  return -1;
}

vector<pair<int,int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

void pushNeighbors(queue<pair<int,int>>& q, pair<int,int> cur, vector<vector<int>>& grid) {
  for(auto dir: dirs) {
    int x = cur.first + dir.first, y = cur.second + dir.second;
    if(isValid(x) && isValid(y) && grid[x][y] == 0)
      q.push({x,y});
  }
}

bool isValid(int x) {
  return x>=0 && x<n;
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
