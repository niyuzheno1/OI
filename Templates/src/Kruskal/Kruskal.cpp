/*
 * Kruskal.cpp
 *
 *  Created on: 2013-3-5
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

const int MAX_VERTEX = 100;
const int MAX_EDGE = 10000;

int vertex_amount , edge_amount;

int start [MAX_VERTEX];
int distance [MAX_VERTEX];

int cost [MAX_EDGE];
int begin [MAX_EDGE];
int end [MAX_EDGE];
int link [MAX_EDGE];
bool selected[MAX_EDGE];

bool cmp(int x , int y)
{
	if (cost [x] < cost [y])
		return true;
	else
		return false;
}

int kruskal()
{
	using namespace Disjoint_Set;

	initialize();

	int edge_list[MAX_EDGE];

	for(int Edge = 0 ; Edge < edge_amount ; Edge ++)
		edge_list [Edge] = Edge + 1;

	sort(edge_list , edge_list + edge_amount , cmp);

	int ans = 0;

	memset(selected , 0 , sizeof(selected));

	for(int index = 0 ; index < edge_amount ; index ++)
	{
		int Edge = edge_list [index];
		if (root (begin [Edge] != root (end [Edge])))
			{
				ans += cost [Edge];
				selected [Edge] = true;
				merge(begin [Edge] , end [Edge]);
			}
	}


	return ans;
}
