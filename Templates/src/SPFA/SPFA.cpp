/*
 * SPFA.cpp
 *
 *  Created on: 2013-3-3
 *      Author: Luke.Xuan
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

namespace SPFA
{
	const int MAX_VERTEX = 100;
	const int MAX_EDGE = 10000;

	int start [MAX_VERTEX];
	int distance [MAX_VERTEX];

	int cost [MAX_EDGE];
	int begin [MAX_EDGE];
	int end [MAX_EDGE];
	int link [MAX_EDGE];

	bool cmp(int x , int y);
	void SPFA(int s);
}

bool SPFA::cmp(int x , int y)
{
	if (x < y)
		return true;
	else
		return false;
}

void SPFA::SPFA(int s)
{
	int visited [MAX_VERTEX];
	memset(visited , 0 , sizeof(visited));

	int queue[100000];

	int open = 0 , close = 1;

	queue [0] = s;


	while(open < close)
	{
		int Vertex = queue [open ++];
		if (visited [Vertex])
			continue;
		visited [Vertex] = true;
		for(int Edge = start [Vertex] ; Edge ; Edge ++)
			if (!visited [Vertex])
				if (cmp (distance [Vertex] + cost [Edge] , distance [end [Edge]]))
				{
					queue [close ++] = end [Edge];
					distance [end [Edge]] = distance [Vertex] + cost [Edge];
				}
	}

	return;
}
