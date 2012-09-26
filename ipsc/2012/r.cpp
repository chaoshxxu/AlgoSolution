#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
typedef vector<int> vi;

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		int r;
		vector<pii> ans[55555];
		set<ppiii> s;

		scanf("%d", &r);
		for (int m = 1; m <= r / m; m++)
		{
			for (int n = 1; n < m; n++)
			{
				int a = m * m - n * n;
				int b = 2 * m * n;
				int c = m * m + n * n;
				if (c <= r)
				{
//					printf("%d %d %d\n", a, b, c);
					ans[c].push_back(make_pair(min(a, b), max(a, b)));
				}
			}
		}
		for (int m = 1; m <= r; m++)
		{
			for (int n = 1; n < m; n++)
			{
				int a = m * m - n * n;
				int b = 2 * m * n;
				int c = m * m + n * n;
				if (a > b)
				{
					swap(a, b);
				}
				if (b > r)
				{
					continue;
				}
//				printf("%d %d\n", a, b);
				for (int i = 0; i < ans[b].size(); i++)
				{
					int a1 = a;
					int b1 = ans[b][i].first;
					int c1 = ans[b][i].second;
					
					int a2 = min(a1, min(b1, c1));
					int c2 = max(a1, max(b1, c1));
					int b2 = a1 + b1 + c1 - a2 - c2;
//					printf("%d %d %d\n", a2, b2, c2);
//					printf("s.size = %d\n", s.size());
					s.insert(make_pair(make_pair(a2, b2), c2));
				}
			}
		}
//		printf("s.size = %d\n", s.size());
		
		int res = 1 + 6 * (r - 1);
		for (int i = 1; i <= r; i++)
		{
			for (int j = 0; j < ans[i].size(); j++)
			{
				if (ans[i][j].first == ans[i][j].second)
				{
					res += 12;
				} else 
				{
					res += 24;
				}
			}
		}
		for (set<ppiii>::iterator it = s.begin(); it != s.end(); it++)
		{
			int a = it -> first.first; 
			int b = it -> first.second; 
			int c = it -> second;
			printf ("%d %d %d\n", a, b, c);

			if (a == b && b == c)
			{
				res += 8;
			} else if (a == b || b == c)
			{
				res += 24;
			} else 
			{
				res += 48;
			}
		}
		printf("%d\n", res);
	}
	
	return 0;
}
