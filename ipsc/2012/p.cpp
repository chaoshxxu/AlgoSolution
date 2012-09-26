#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
pii w[20000];
int total;

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		total = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &w[i].first);
			w[i].second = i;
			total += w[i].first;
		}
		sort(w, w + n);
		
		int s1 = 0;
		int s2 = 0;
		vi ans1;
		vi ans2;
		for (int i = n - 2; i >= 0; i--)
		{
			if (s1 < s2)
			{
				s1 += w[i].first;
				ans1.push_back(w[i].second);
			} else {
				s2 += w[i].first;
				ans2.push_back(w[i].second);
			}
		}
		printf("%d", ans1.size());
		for (int i = 0; i < ans1.size(); i++)
		{
			printf(" %d", ans1[i] + 1);
		}
		puts("");

		printf("%d", ans2.size());
		for (int i = 0; i < ans2.size(); i++)
		{
			printf(" %d", ans2[i] + 1);
		}
		puts("");

//		printf("%d %d %d %c\n", s1, s2, total, (s1 <= total/2.0 && s2 <= total/2.0 ? 'y' : 'n') );
	}
	return 0;
}
