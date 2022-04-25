#include<iostream>

using namespace std;

typedef long long LL; 
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5+10 ; 

/**
 * for example
 * BRBBW 
 * and we can get the reulst as 
 * Yes
 */

char ch[N];

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m ; 
        scanf("%d%s",&m,ch+1);
        ch[m+1] = 'W';
        int ok = 1 , c1 = 0 , c2 = 0;
        for(int i = 1 ; i <= m+1; i++)
        {
            if(ch[i] == 'W') {
                if(c1 == 0 && c2 > 0 || c2 == 0 && c1 > 0) {
                    ok = 0;
                }
                c1 = c2 = 0;
            }
            else if (ch[i] == 'R') 
                c1++;
            else 
                c2++;
        }
        puts(ok ? "Yes" : "No");
    }

    return 0;
}