#include <iostream>
#include <ctime>
using namespace std;

class Quick
{
public:
	
	void sort(int a[],int length)
	{
		sort(a, 0, length - 1);
	}

	bool less(int left, int right)
	{
		return left < right;
	}
	
	void exch(int* a, int i, int j)
	{
		int v = a[i];
		a[i] = a[j];
		a[j] = v;
	}

private:
	void sort(int a[], int low, int hight)
	{
		if (hight <= low)
		{
			return;
		}

		int j = partition(a, low, hight);
		sort(a, low, j - 1);
		sort(a, j + 1, hight);
	}

	int partition(int a[], int low, int hight)
	{
		int i = low, j = hight + 1;
		int v = a[i];
		while (true)
		{
			while (less(a[++i], v))
			{
				if (i == hight)
				{
					break;
				}
			}
			while (less(v, a[--j]))
			{
				if (j == low)
				{
					break;
				}
			}
			if (i >= j)
			{
				break;
			}
		}

		exch(a, i, j);
		return j;
	}
	
};

