/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Software Engineer,
                Samsung R&D Institute Bangladesh (SRBD),
                Dhaka, Bangladesh.
    Time :
    Rank :
    Complexity:
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define FOR(i, L, U) for(int i=(int)L; i<=(int)U; i++)
#define FORD(i, U, L) for(int i=(int)U; i>=(int)L; i--)

#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

#define PQ priority_queue
#define PB push_back
#define SZ size()

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999
#define TO_DEG 57.29577951
#define PI 2*acos(0.0)

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b)    {   while(b)b^=a^=b^=a%=b;  return a;   }
int LCM(int a, int b)   {   return a/GCD(a,b)*b;                }

// UP, RIGHT, DOWN, LEFT, UPPER-RIGHT, LOWER-RIGHT, LOWER-LEFT, UPPER-LEFT
int dx[8] = {-1, 0, 1, 0, -1, 1,  1, -1};
int dy[8] = { 0, 1, 0,-1,  1, 1, -1, -1};

// Represents all moves of a knight in a chessboard
int dxKnightMove[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dyKnightMove[8] = { 2,  1, -1, -2, -2, -1, 1, 2};

inline int src() { int ret; scanf("%d", &ret); return ret; }

#define WHITE 0
#define GRAY 1
#define BLACK 2

#define MAX_NODE 10000

int NODES;      // Denotes number of NODES
int EDGES;      // Denotes number of EDGES

VVI G;          // Adjacency List of Graph
VI dist;        // Distance from source node
VC color;       // State of a node
VI parent;      // Parent of a node
VI path;        // Desired Path

/**
Use these prototypes for based on your problem:
When multi-dimension comes in your problem don't use vector, it will increase your coding time.
int dist[MAX][MAX][MAX];    // Multi-dimensional dist array
char color[MAX][MAX][MAX];  // Multi-dimensional color array
char grid[MAX][MAX][MAX];   // Multi-dimensional grid array
**/

void BFS(int source)
{
    int u, v;
    queue<int> Q;

    dist = VI(MAX_NODE);
    color = VC(MAX_NODE);
    parent = VI(MAX_NODE);

    Q.push(source);
    dist[source] = 0;
    parent[source] = -1;
    color[source] = GRAY;

    while( !Q.empty() ) {
        u = Q.front(); Q.pop();

        FOR(i, 0, G[u].SZ-1) {
            v = G[u][i];
            if(color[v] == WHITE) {
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                Q.push(v);
            }
        }
        color[u] = BLACK;
    }
}

void MakePath(int sink)
{
    if(parent[sink] == -1) {
        path.PB(sink);
        return;
    }

    MakePath(parent[sink]);
    path.PB(sink);
}

void ShowPath()
{
    FOR(i, 0, path.SZ-1)
        cout << path[i] << " ";
    cout << endl;
}


int main()
{
    //READ("input.txt");
    //WRITE("output.txt");
    int i, j, k;
    int TC, tc;

    double cl = clock();

    int u, v;

    cin >> NODES >> EDGES;
    G = VVI(NODES + 1);

    FOR(i, 1, EDGES) {
        cin >> u >> v;
        G[u].PB(v);
        G[v].PB(u);
    }

    BFS(6);

    MakePath(8);

    ShowPath();


    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
