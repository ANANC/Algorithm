#include <iostream>
#include <ctime>
using namespace std; 

class  PriorityQueue
{
	int* p;

public :
	void Run(int a[], int length, int TopCount)
	{
		p = new int[length];
		for (int index = 0; index < length; index++)
		{
			p[index] = a[index];
		}
		cout << "intput:------------------------ ";

		int maxValue = p[0];
		for (int index = 0; index < length; index++)
		{
			int curValue = p[index];

			cout << curValue << " ";

			if (index > TopCount)
			{
				delMin();
			}
		}

		cout << "max:------------------------ ";

		for (int index = 0; index < length; index++)
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
