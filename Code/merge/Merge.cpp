#include <iostream>
#include <ctime>
#include<algorithm>
using namespace std;

class Merge
{
protected:
	int* p;
	int* aux;

	bool less(int left,int right)
	{
		return left < right;
	}

	void merge(int a[], int low, int mid, int height)
	{
		int index = low;
		int j = mid + 1;

		for (int k = low; k <= height; k++) {
			aux[k] = a[k];
		}

		for (int k = low; k <= height; k++)
		{
			if (index > mid)
			{
				a[k] = aux[j++];
			}
			else if(j > height)
			{
				a[k] = aux[index++];
			}
			else if (less(aux[j], aux[index]))
			{
				a[k] = aux[j++];
			}
			else
			{
				a[k] = aux[index++];
			}
		}
	}

	virtual void sort(int* a, int low, int height) = 0;

public:
	virtual void Run(int a[], int length)
	{
		p = new int[length];
		for (int index = 0; index < length; index++)
		{
			p[index] = a[index];
		}

		aux = new int[length];

		clock_t time_start = clock();
		sort(p, 0, length-1);
		clock_t time_end = clock();
		cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

		if (length <= 100)
		{
			for (int index = 0; index < length; index++)
			{
				cout << p[index] << " ";
				if ((index + 1) % 100 == 0)
				{
					cout << endl;
				}
			}
		}

		cout << endl;
	}
};

class TopDownMerge :public Merge
{
protected:
	void sort(int* a, int low, int height)
	{
		if (height <= low)
		{
			return;
		}

		int mid = low + (height - low) / 2;
		sort(a, low, mid);
		sort(a, mid + 1, height);
		merge(a, low, mid, height);
	}
};

class BottmUpMerge : public Merge
{
protected:
	void sort(int* a, int length)
	{
		for (int sz = 1; sz < length; sz = sz + sz)
		{
			for (int low = 0; low < length - sz; low += sz + sz)
			{
				merge(a, low, low + sz - 1, min(low + sz + sz - 1, length - 1));
			}
		}
	}
	void sort(int* a, int low, int height) {}

public :
	virtual void Run(int a[], int length)
	{
		p = new int[length];
		for (int index = 0; index < length; index++)
		{
			p[index] = a[index];
		}

		aux = new int[length];

		clock_t time_start = clock();
		sort(p, length);
		clock_t time_end = clock();
		cout << "time use:" << 1000 * (time_end - time_start) / (double)CLOCKS_PER_SEC << "ms" << endl;

		if (length <= 100)
		{
			for (int index = 0; index < length; index++)
			{
				cout << p[index] << " ";
				if ((index + 1) % 100 == 0)
				{
					cout << endl;
				}
			}
		}

		cout << endl;
	}
};