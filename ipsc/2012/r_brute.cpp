#include<stdio.h>
#include<math.h>
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
		int ans = 0;

		scanf("%d", &r);
		for (int x = -r; x <= r; x++)
		for (int y = -r; y <= r; y++)
		for (int z = -r; z <= r; z++)
		{
			if (x*x + y*y + z*z < r*r)
			{
				int s = (int)(sqrt(x*x + y*y + z*z + 0.0) + 0.5);
				if (s*s == x*x + y*y + z*z)
				{
					printf ("%d %d %d\n", x, y, z);
					ans++;
				}
			}
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}
