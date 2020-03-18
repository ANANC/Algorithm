#include <iostream>
using namespace std;


class SortExample
{
protected:
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
		int *p = sort(a, length);
		for (int index = 0; index < length; index++)
		{
			cout << p[index] << " " << endl;
		}
	}

	virtual int* sort(int* a, int length) = 0;

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
	int* sort(int* a, int length)
	{
		int* p = a;
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
		return p;
	}
};