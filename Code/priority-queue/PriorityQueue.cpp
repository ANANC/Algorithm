#include <iostream>
#include <ctime>
using namespace std; 

class  PriorityQueue
{
public:
	int* p;
	int arrayLength = 0;

public :
	void Run(int a[], int length, int TopCount)
	{
		p = new int[length+1];
		for (int index = 0; index < length; index++)
		{
			int curValue = a[index];

			insert(curValue);
		}

		cout << "\n\intput:------------------------ \n";

		for (int index = 0; index <= length; index++)
		{
			int curValue = p[index];
			cout << curValue << " ";
		}

		//todo:效果还是不对

		delMin();
//		delMax();

		cout << "\n\nmax:------------------------ \n";

		for (int index = 0; index <= length; index++)
		{
			int curValue = p[index];
			cout << curValue << " ";
		}

		cout << endl;
	}

protected:
	virtual void insert(int v) = 0;
	virtual int max() = 0;
	virtual int delMax() = 0;
	virtual int delMin() = 0;
	virtual bool isEmpty() = 0;
	virtual int size() = 0;
};

class HeapPriorityQueue:public PriorityQueue
{
protected:
	 
	bool isEmpty()
	{
		return arrayLength == 0;
	}

	int size()
	{
		return arrayLength;
	}

	void insert(int value)
	{
		arrayLength++;
		p[arrayLength] = value;
		swim(p,arrayLength);
	}

	int delMax()
	{
		int max = p[1];

		exch(p,1, arrayLength--);

		p[arrayLength+1] = NULL;

		sink(p, arrayLength,1);

		return max;
	}

	int delMin()
	{
		int min = p[1];
		arrayLength -= 1;

		p[1] = NULL;

		swim(p, arrayLength);

		return min;
	}

	int max()
	{
		int max = p[1];
		return max;
	}

private:
	bool less(int i, int j)
	{
		return i < j;
	}

	void exch(int* a, int i, int j)
	{
		int v = a[i];
		a[i] = a[j];
		a[j] = v;
	}

	void swim(int* a, int k)
	{
		while (k > 1 && less(a[k / 2], a[k]))
		{
			exch(a, k / 2, k);
			k = k / 2;
		}
	}

	void sink(int* a,int length, int k)
	{
		while (2 * k <= length)
		{
			int j = 2 * k;
			if (j < length && less(a[j],a[j+1]))
			{
				j++;
			}
			if (!less(a[k], a[j]))
			{
				break;
			}
			exch(a,k,j);
			k = j;
		}
	}
};
