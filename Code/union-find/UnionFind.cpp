#include <iostream>
using namespace std;


class UF
{
protected:
	int* id;
	int idLength;
	int count;

public :
	UF(int n)
	{
		id = new int[n];
		for (int index = 0; index < n; index++)
		{
			id[index] = index;
		}
		count = n;
		idLength = n;
	};

	int Count() 
	{
		return count;
	};

	bool connect(int p, int q)
	{
		return find(p) == find(q);
	};

	//查找标志
	virtual int find(int p) = 0;

	//连接
	virtual void uniton(int p, int q) = 0;

	void Run(int arr[])
	{
		for (int index = 0; index < idLength - 1; index += 2)
		{
			int q = arr[index];
			int p = arr[index + 1];

			if (connect(q, p))
			{
				continue;
			}
			uniton(q, p);
			cout << q << ":" << id[q] << " " << p << ":" << id[p] << "\n" << endl;
		}

		cout << Count() << " components" << endl;
	};
};


class QuickFind :public UF
{
public:
	QuickFind(int n) :UF(n) {}

	int find(int p)
	{
		return id[p];
	}

	void uniton(int p, int q)
	{
		int pId = find(p);
		int qId = find(q);

		if (pId == qId)
		{
			return;
		}

		for (int index = 0; index < idLength; index++)
		{
			if (id[index] == pId)
			{
				id[index] = qId;
			}
		}

		count--;
	}
};


class QuickUnion : public UF {
public:
	QuickUnion(int n) :UF( n) {}

	int find(int p)
	{
		while (p != id[p])
		{
			p = id[p];
		}
		return p;
	}

	void uniton(int p, int q)
	{
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot == qRoot)
		{
			return;
		}

		id[pRoot] = qRoot;
		count--;
	}
};

class UnionFind :public UF {
private:
	int* sz;

public:
	UnionFind(int n) :UF( n) {
		sz = new int[n];
		for (int index = 0; index < n; index++)
		{
			sz[index] = index;
		}
	}

	int find(int p)
	{
		while (p != id[p])
		{
			p = id[p];
		}
		return p;
	}

	void uniton(int p, int q)
	{
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot == qRoot)
		{
			return;
		}

		if (sz[pRoot] < sz[qRoot]) {
			id[pRoot] = q;
			sz[q] += sz[q];
		}
		else
		{
			id[qRoot] = p;
			sz[p] += sz[q];
		}
		count--;
	}
};