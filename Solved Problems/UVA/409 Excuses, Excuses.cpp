/*
    Solved By : Kazi Mahbubur Rahman (MASUD)
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
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector< vector<bool> > VVB;
typedef pair<int, int> PI;
typedef map<int, int> MII;
typedef map<char, int> MCI;
typedef map<string, bool> MSB;
typedef map<string, int> MSI;

int GCD(int a,int b){   while(b)b^=a^=b^=a%=b;  return a;   }

#define WHITE 0
#define GRAY 1
#define BLACK 2

int K, E;
VS sens;
MSB m;
int counts[21];
int maxCount;

int main()
{
    READ("input.txt");
//    WRITE("output.txt");
   int i, j, k;
   int TC, tc;
   string line, str;

   tc = 1;
   while(cin >> K >> E) {
      FOR(i, 1, K) {
         cin >> str;
         m[str] = true;
      }

      getline(cin, line);
      maxCount = -1;
      FOR(i, 0, E-1) {
         getline(cin, line);
         sens.PB(line);

         FOR(i, 0, line.size()-1) {
            if(isupper(line[i])) line[i] = tolower(line[i]);
            else if(!isalpha(line[i])) line[i] = ' ';
         }

         counts[i] = 0;
         stringstream ss(line);
         while(ss >> str) {
            if(m[str] == true) counts[i]++;
            maxCount = max(maxCount, counts[i]);
         }
      }

      printf("Excuse Set #%d\n", tc++);
      FOR(i, 0, E-1) {
         if(maxCount == counts[i]) cout << sens[i] << "\n";
      }
      cout << "\n";

      sens.clear();
      m.clear();
   }

   return 0;
}
