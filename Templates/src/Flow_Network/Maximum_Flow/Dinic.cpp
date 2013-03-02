/*
 * Dinic.cpp
 *
 *  Created on: 2013-2-15
 *      Author: Luke.Xuan
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

namespace Maximum_Flow_Dinic
{
	/*	ToDo:
	 *	@constants : modify here to adjust the maximum of answer.
	 */
	const long MAX = 10000;

	/*	ToDo:
	 *	@constants : modify here to adjust the size of arrays.
	 */

	/*	Locator:
	 *	@argument : @[scalars] , @[constants] , @[sizes]
	 */

	const long MAX_EDGE = 10000;
	const long MAX_VERTEX = 100;

	/*	Locator:
	 *	@argument : @[scalars] , @[variables] ,  @[amounts] , @[positions]
	 */

	long vertex_amount , edge_amount , s , t;

	/*	Locator:
	 *	@argument : @[arrays] , @[variables] ,  @[edges] , @[vertexes] , @[graph]
	 */

	long start[MAX_VERTEX];
	long _start[MAX_VERTEX];
	long distance[MAX_VERTEX];

	long begin[MAX_EDGE];
	long capacity[MAX_EDGE];
	long end[MAX_EDGE];
	long flow[MAX_EDGE];
	long link[MAX_EDGE];

	/*	Locator:
	 *	@argument : @[functions] , @[bfs] , @[dfs] , @[main] , @[dinic] , @[define]
	 */

	bool dinic_dfs(const long position , long * delta);
	bool dinic_bfs();
	long dinic();

}

/*	Locator:
 *	@argument : @[functions] , @[dfs] , @[dinic] , @[code]
 */

bool Maximum_Flow_Dinic::dinic_dfs (const long position , long * delta)
{
	if (position == t)
		return true;

	if (position == 0)
		return false;

	for (long Edge = _start [position] ; Edge ; Edge = link [Edge])
	if (distance [position] + 1 == distance [end [Edge]])
	{
		long Delta = * delta;
		if (Edge <= edge_amount)
		{
			if (flow [Edge] < capacity [Edge])
				if (dinic_dfs(end [Edge] , & (Delta = min (* delta , capacity [Edge] - flow [Edge]))))
				{
					flow [Edge] += Delta;
					_start [position] = Edge;
					* delta = Delta;
					return true;
				}
		}
		else
		{
			long Delta = * delta;
			long _Edge = Edge - edge_amount;
			if (flow [_Edge] > 0)
			{
				if (dinic_dfs(end [Edge] , & (Delta = min (* delta , flow [_Edge]))))
				{
					flow [_Edge] -= Delta;
					* delta = Delta;
					return true;
				}
			}
		}
	}

	_start [position] = 0;

	return false;
}

/*	Locator:
 *	@argument : @[functions] , @[bfs] , @[dinic] , @[code]
 */

bool Maximum_Flow_Dinic::dinic_bfs ()
{
	memset(distance , 0 , sizeof (distance));

	long open = 0 , close = 1;

	long queue [MAX_EDGE];

	queue [0] = s;

	while(open < close)
	{
		long Vertex = queue [open ++];
		for(long Edge = start [Vertex] ; Edge ; Edge = link [Edge])
		{
			if (Edge <= edge_amount)
			{
				if (flow [Edge] < capacity [Edge])
					if (distance [end [Edge]] == 0)
					{
						distance [end [Edge]] = distance [Vertex] + 1;
						queue [close ++] = end [Edge];
					}
			}
			else
			{
				if (flow [Edge - edge_amount] > 0)
					if (distance [end [Edge]] == 0)
					{
						distance [end [Edge]] = distance [Vertex] + 1;
						queue [close ++] = end [Edge];
					}
			}
		}
	}

	return distance[t];
}

/*	Locator:
 *	@argument : @[functions] , @[main] , @[dinic] , @[code]
 */

long Maximum_Flow_Dinic::dinic ()
{
	long Return = 0;

	while(dinic_bfs())
	{
		long Delta;

		memcpy(_start , start , sizeof(start));

		while(dinic_dfs(s , & (Delta = MAX)))
			Return += Delta;
	}

	return Return;
}
