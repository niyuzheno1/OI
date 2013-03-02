/*
 * minfmaxf.cpp
 *
 *  Created on: 2013-2-20
 *      Author: Luke.Xuan
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

namespace Minimal_Fee_Maximum_Flow
{
	const long MAX = 10000;

	const long MAX_VERTEX = 100;
	const long MAX_EDGE = 10000;

	long edge_amonut , vertex_amount , s , t;

	long distance [MAX_VERTEX];
	long start [MAX_VERTEX];

	long begin [MAX_EDGE];
	long end [MAX_EDGE];
	long link [MAX_EDGE];
	long fee [MAX_EDGE];
	long capacity [MAX_EDGE];
	long flow [MAX_EDGE];
	long total_fee;

	bool minfmaxf_SPFA(long postion , long * delta);
	long minfmaxf();
}

bool Minimal_Fee_Maximum_Flow::minfmaxf_SPFA (long position , long * delta)
{
	return false;
}

long Minimal_Fee_Maximum_Flow::minfmaxf ()
{
	long Delta , Return = 0;
	while(minfmaxf_SPFA(s , & (Delta = MAX)))
		Return += Delta;

	return Return;
}
