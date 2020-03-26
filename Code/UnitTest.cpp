#include "union-find/UnionFind.cpp"
#include "sort/Sort.cpp"
#include "merge/Merge.cpp"

#include <iostream>
using namespace std;

class UnitTest
{
public:
	void Start() 
	{
		//__UnionFind();// 并查集
		//__Sort();//常见排序
		__Megre();//递归排序
	}

private:
	void __UnionFind()
	{
		cout << "/*---------------  UnionFind ---------------*/" << endl;

		int args[] = { 4,3,3,8,6,5,9,4,2,1,5,0,7,2,6,1,1,0,6,7 };
		int N = sizeof(args) / sizeof(int);

		UF* ps[] =
		{
			new QuickFind(N),
			new QuickUnion(N),
			new UnionFind(N)
		};
		string title[] = { "QuickFind" ,"QuickUnion" "UnionFind" };

		int testCount = sizeof(title) / sizeof(string);

		for (int index = 0; index < testCount; index++)
		{
			cout << title[index] << endl;
			ps[index]->Run(args);
		}

		delete(ps);
	}

	void __Sort() 
	{
		cout << "/*---------------  Sort  ---------------*/" << endl;

		int N = 50;
		int* args = new int[N];
		for (int index = 0; index < N; index++)
		{
			srand(index * time(0));
			args[index] = rand();
		}

		SortExample* ps[] =
		{
			new SelectionSort(),
			new InsertionSort(),
			new ShellSort()
		};
		string title[] = { "SelectionSort" ,"InsertionSort","ShellSort"};

		int testCount = sizeof(title)/sizeof(string);

		for (int index = 0; index < testCount; index++)
		{
			cout << title[index] << endl;
			ps[index]->Run(args, N);
			cout << endl;
		}

	}

	void __Megre()
	{
		cout << "/*---------------  Merge  ---------------*/" << endl;

		int N = 10;
		int* args = new int[N];
		for (int index = 0; index < N; index++)
		{
			srand(index * time(0));
			args[index] = rand();
		}

		Merge* ps[] =
		{
			new TopDownMerge(),
		};
		string title[] = { "Merge"  };

		int testCount = sizeof(title) / sizeof(string);

		for (int index = 0; index < testCount; index++)
		{
			cout << title[index] << endl;
			ps[index]->Run(args, N);
			cout << endl;
		}
	}
}; 