/*
    Solved By : Kazi Mahbubur Rahman (MAHBUB)
                Level - 3, Term - 2,
                Khulna University of Engineering and Technology,
                Khulna - 9203
    Time :
    Rank :
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
#define ff first
#define ss second

#define EPS 1e-9
#define SQR(x) ((x)*(x))
#define INF 99999999

#define ALL_BITS ((1 << 31) - 1)
#define NEG_BITS(mask) (mask ^= ALL_BITS)
#define TEST_BIT(mask, i) (mask & (1 << i))
#define ON_BIT(mask, i) (mask |= (1 << i))
#define OFF_BIT(mask, i) (mask &= NEG_BITS(1 << i))

typedef long long LL;
typedef vector<char> VC;
typedef vector<vector<char> > VVC;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PII;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, int> MSI;

int GCD(int a,int b) {   while(b)b^=a^=b^=a%=b;  return a;   }
int LCM(int a,int b) {   return a / GCD(a, b) * b;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

inline int src() { int ret; scanf("%d", &ret); return ret; }

//---------------------------- GLOBAL VARIABLES ----------------------------

#define MAX_N 105


int base[4][4] = { {0, 0, 0, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1} };
int unit[4][4] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} };
int constants[4] = { 0, 0, 0, 0};
int MOD = 10007;

void matMul(int a[4][4], int b[4][4])
{
   int i, j, k, r[4][4];
   FOR(i, 0, 3) FOR(j, 0, 3) {
      r[i][j] = 0;
      FOR(k, 0, 3) {
         r[i][j] += a[i][k] * b[k][j];
         if(r[i][j] >= MOD) r[i][j] %= MOD;
      }
   }
   memcpy(a, r, sizeof r);
}

void matPow(int r[4][4], int p)
{
   int b[4][4];
   memcpy(b, base, sizeof base);
   memcpy(r, unit, sizeof unit);

   while(p) {
      if(p & 1) matMul(r, b);
      matMul(b, b);
      p >>= 1;
   }
}


int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   int res[4][4];
   int N;

   TC = src();

   FOR(tc, 1, TC) {
      scanf("%d %d %d %d", &N, &base[0][0], &base[0][2], &constants[3]);

      if(N < 2) printf("Case %d: %d\n", tc, 0);
      else {
         matPow(res, N-2);
         int ans = 0;
         FOR(i, 0, 3) {
            ans += res[0][i] * constants[i];
         }
         ans %= MOD;
         printf("Case %d: %d\n", tc, ans);
      }
   }

   return 0;
}
