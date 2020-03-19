#include <iostream>
#include <ctime>
using namespace std;


class SortExample
{
protected:
	int* p;

	bool less(int v, int w)
	{
		return v < w;
	}

	void exch(int* a, int i, int j)
	{
		int v = a[i];
		a[i] = a[j];
		a[j] = v;
	}

public:	
	
	void Run(int a[],int length)
	{
		p = new int[length];
		for (int index = 0; index < length; index++)
		{
			p[index] = a[index];
		}

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

	virtual void sort(int* a, int length) = 0;

	bool isSorted(int a[],int length)
	{
		for (int index = 1; index < length; index++)
		{
			if (less(a[index], a[index - 1]))
			{
				return false;
			}
		}
		return true;
	}
};

//Ñ¡ÔñÅÅÐò
class SelectionSort :public SortExample
{
public:
	void sort(int* a, int length)
	{
		for (int index = 0; index < length; index++)
		{
			int min = index;
			for (int j = index + 1; j < length; j++)
			{
				if (less(p[j], p[min]))
				{
					min = j;
				}
			}
			exch(p, index, min);
		}
	}
};

//²åÈëÅÅÐò
class InsertionSort :public SortExample
{
public: 
	void sort(int* a, int length)
	{
		for (int index = 1; index < length; index++)
		{
			for (int j = index; j > 0 && less(a[j], a[j - 1]); j--)
			{
				exch(a, j, j - 1);
			}
		}
	}
};

//Ï£¶ûÅÅÐò
class ShellSort :public SortExample
{
public:
	void sort(int* a, int length)
	{
		int h = 1;
		int group = 5;
		while (h < length / group) {
			h = group * h + 1;
		}
		while (h >= 1)
		{
			for (int index = h; index < length; index++)
			{
				for (int j = index; j >= h && less(a[j], a[j - h]); j -= h)
				{
					exch(a, j, j - h);
				}
			}
			h = h / group;
		}
	}
};