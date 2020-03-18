#include "union-find/UnionFind.cpp"
#include "sort/Sort.cpp"

#include <iostream>
using namespace std;

class UnitTest
{
public:
	void Start() 
	{
		//__UnionFind();// ≤¢≤ÈºØ
		__Sort();//≈≈–Ú
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
	}

	void __Sort() 
	{
		cout << "/*---------------  Sort ---------------*/" << endl;

		int args[] = { 4,30,3,28,65,25,49,34,22,1,5,30,7,24,36,10,21,70,66,27 };
		int N = sizeof(args) / sizeof(int);

		SortExample* ps[] = 
		{
			new SelectionSort(),
			new InsertionSort(),
		};
		string title[] = { "SelectionSort" ,"InsertionSort"};

		int testCount = sizeof(title)/sizeof(string);

		for (int index = 0; index < testCount; index++)
		{
			cout << title[index] << endl;
			ps[index]->Run(args, N);
		}

	}
}; 