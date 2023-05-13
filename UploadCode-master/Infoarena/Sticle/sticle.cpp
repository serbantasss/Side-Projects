#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("sticle.in");
ofstream cout("sticle.out");

int main()
{
	int t, n, put, nr;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		put = 1;
		nr = 0;
		while (put < n)
		{
			put = put * 2;
			nr++;
		}
		cout << nr<<'\n';
	}
	return 0;
}