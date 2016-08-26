const int inf = MAX_INT>>1; //infinity
const int N; //Number of nodes
vector<pair<int, int> >g[N+1]; // +1 for starting indices from 1
bool inCycle[N+1];
int dist[N+1]; //the distances, initially equals infinity

bellmanFord() {
  //initializing distances to infinity
  for(int u = 1;u <= n;u++) {
    dist[u] = inf;
    inCycle[u] = 0;
  }

  //Calculatig shortest paths
  for(int i = 0;i < N - 1;i++) {
    for(int u = 1;u <= n;u++) {
      for(auto v : g[u]) {
        if(dist[v.first] > dist[u] + v.second) {
          dist[v.first] = dist[u] + v.second;
        }
      }
    }
  }
  //Relaxing all edges for Nth time, detecting negative cycles
  bool hasNegCycle = false;
  for(int u = 1;u <= N and !hasNegCycle;u++) {
    for(auto v : g[u]) {
      if(dist[v.first] > dist[u] + v.second) {
        hasNegCycle = true;
        break;
      }
    }
  }
  //For detecting node ACTUALLY in negative cycles
  for(int i = 0;i < N - 1;i++) {
    for(int u = 1;u <= n;u++) {
      for(auto v : g[u]) {
        if(dist[v.first] > dist[u] + v.second) {
          dist[v.first] = dist[u] + v.secnod;
          inCycle[v.first] = true;
        }
      }
    }
  }
}
