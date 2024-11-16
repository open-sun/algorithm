#include<iostream>
#include<math.h>
#include <iomanip>  
using namespace std;
class node
{
public:
	double x;
	double y;
};
void nihe(node line[1000], int i, int j,double &a,double &b)
{
	int n = i - j;
	double sumx2 = 0,sumx=0,sumxy=0,sumy=0;
	for (; j < i; j++)
	{
		sumx2+=line[j].x * line[j].x;
		sumx += line[j].x;
		sumxy += line[j].x * line[j].y;
		sumy += line[j].y;
	}
	 a = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
	 b = (sumy -a*sumx) / n ;
}

int main()
{
	int n = 0;
	double c = 0.00;
	cin >> n >> c;
	node line[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> line[i].x >> line[i].y;
	}
	double df[1000] = { 0.00 };
	for (int i = 1; i <= n; i++)
	{
		double minerr = 100000000000;
		for (int j = 0; j < i; j++)
		{
			double err = 0;
			double a = 0, b = 0;
			nihe(line, i, j, a, b);
			for (int q=j; q <i; q++)
			{
				 err += (line[q].y - (a * line[q].x + b)) * (line[q].y - (a * line[q].x + b));
			}
			err += df[j];
			err += c;
			if (err < minerr)
				minerr = err;
		}

		df[i] = minerr;
	}
	cout << fixed << std::setprecision(2) <<df[n];
	/*double err = 0;
	double a = 0, b = 0;
	nihe(line, n, 0, a, b);
	cout << a << " " << b << endl;
	for (int j=0; j < n; j++)
	{
		err += (line[j].y - (a * line[j].x + b)) * (line[j].y - (a * line[j].x + b));
	}
	cout << err;*/
	return 0;
}