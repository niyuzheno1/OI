/*
 * Union_Set.cpp
 *
 *  Created on: 2013-3-3
 *      Author: Luke.Xuan
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

namespace Disjoint_Set
{
	/*	ToDo:
	 *	@constants : modify here to adjust the size of arrays.
	 */

	const int MAX_DATA = 10000;

	/*	Locator:
	 *	@arguments : @[arrays] , @[variables]
	 */

	int rank [MAX_DATA];
	int set [MAX_DATA];

	/*	Locator:
	 *	@arguments : @[functions] , @[initialize] , @[merge] , @[root] , @[union_set] , @[define]
	 */

	void initialize();
	void merge (int x , int y);
	int root (int x);
}

void Disjoint_Set::initialize()
{
	memset(rank , 0 , sizeof(rank));

	for(int x = 1 ; x < MAX_DATA ; x ++)
		set [x] = x;

	return;
}

/*	Locator:
 *	@arguments : @[functions] , @[merge] , @[union_set] , @[code]
 */

void Disjoint_Set::merge (int x , int y)
{
	if (rank [x] <= rank [y])
	{
		rank [x] ++;
		set [y] = root (x);
	}
	else
	{
		rank [y] ++;
		set [x] = root (y);
	}

	return;
}

/*	Locator:
 *	@arguments : @[functions] , @[root] , @[union_set] , @[code]
 */

int Disjoint_Set::root (int x)
{
	if (set [x] != set [set [x]])
		set [x] = root (set [x]);

	return set [x];
}
