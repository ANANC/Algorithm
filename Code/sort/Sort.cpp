#include <iostream>
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

		sort(p, length);
		for (int index = 0; index < length; index++)
		{
			cout << p[index] << " " << endl;
		}
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