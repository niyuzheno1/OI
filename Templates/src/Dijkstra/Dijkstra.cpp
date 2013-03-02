/*
 * Dijkstra.cpp
 *
 *  Created on: 2013-3-2
 *      Author: Luke.Xuan
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

namespace Dijkstra
{

	/*	ToDo:
	 *	@constants : modify here to adjust the size of arrays.
	 */

	/*	Locator:
	 *	@arguments : @[scalars] , @[constants] , @[sizes]
	 */

	const int MAX_VERTEX = 100;
	const int MAX_EDGE = 10000;

	/*	Locator:
	 *	@arguments : @[scalars] , @[variables] , @[amounts]
	 */

	int vertex_amount , edge_amount;

	/*	Locator:
	 *	@arguments : @[arrays] , @[variables] , @[vertexes] , @[edges]
	 */

	int start [MAX_VERTEX];
	int distance [MAX_VERTEX];

	int cost[MAX_EDGE];
	int begin[MAX_EDGE];
	int end [MAX_EDGE];
	int link [MAX_EDGE];

	/*	Locator:
	 *	@arguments : @[functions] , @[cmp] , @[main] , @[dijkstra] , @[define]
	 */

	bool cmp(int x , int y);
	bool dijkstra(int s);
}

/*	Locator:
 *	@arguments : @[functions] , @[cmp] , @[dijkstra] , @[code]
 */

bool Dijkstra::cmp(int x , int y)
{
	if (distance [x] < distance [y])
		return true;
	else
		return false;
}

/*	Locator:
 *	@arguments : @[functions] , @[main] , @[dijkstra] , @[code]
 */

bool Dijkstra::dijkstra(int s)
{

	distance [s] = 0;

	int heap [MAX_VERTEX];

	int heap_amount = 0;

	heap [heap_amount ++] = s;

	bool visited[MAX_VERTEX];

	memset(visited , 0 , sizeof(visited));

	for(int i = 0 ; i < vertex_amount ; i ++)
	{
		if (heap_amount == 0)
			return false;
		pop_heap (heap , heap + heap_amount , cmp);
		int Vertex = heap [-- heap_amount];
		if (visited [Vertex])
			continue;
		visited [Vertex] = true;
		for(int Edge = start [Vertex] ; Edge ; Edge = link [Edge])
			if (!visited [Vertex])
				if (cmp (distance [Vertex] + cost [Edge] , distance [end [Edge]]))
				{
					distance [end [Edge]] = distance [Vertex] + cost [Edge];
					heap [heap_amount ++] = end [Edge];
					push_heap(heap , heap + (heap_amount ++) , cmp);
				}
	}

	return true;
}
