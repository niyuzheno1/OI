/*
 * Prim.cpp
 *
 *  Created on: 2013-3-3
 *      Author: Luke.Xuan
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

namespace Prim
{
	const int MAX_VERTEX = 100;
	const int MAX_EDGE = 10000;

	int vertex_amount , edge_amount;
	int start [MAX_VERTEX];
	int distance [MAX_VERTEX];
	int used [MAX_VERTEX];

	int cost [MAX_EDGE];
	int begin [MAX_EDGE];
	int end [MAX_EDGE];
	int link [MAX_EDGE];
	int selected [MAX_EDGE];

	bool cmp(int x , int y);
	int Prim(int s);
}


bool Prim::cmp(int x , int y)
{
	if (distance [x] < distance [y])
		return true;
	else
		return false;
}

int Prim::Prim(int s)
{
	int visited [MAX_EDGE];

	memset(visited , 0 , sizeof(visited));

	memset(distance , 127 , sizeof(distance));

	int heap [MAX_VERTEX];
	int heap_amount = 0;

	distance [s] = 0;

	heap [heap_amount ++] = s;

	for(int i = 0 ; i < vertex_amount ; i ++)
	{
		pop_heap(heap , heap + heap_amount , cmp);
		int Vertex = heap [-- heap_amount];
		if (visited [Vertex])
			continue;
		visited [Vertex] = true;
		for(int Edge = start [Vertex] ; Edge ; Edge = link [Edge])
			if (!visited [end [Edge]])
				if (cost [Edge] < distance [end [Edge]])
				{
					selected [Edge] = true;
					selected [used [end [Edge]]] = false;
					distance [Edge] = cost [Edge];
					heap [heap_amount ++] = end [Edge];
					push_heap(heap , heap + heap_amount , cmp);
				}
	}

	int ans = 0;

	for(int Vertex = 1 ; Vertex <= vertex_amount ; Vertex ++)
		ans += distance [Vertex];

	return ans;
}
