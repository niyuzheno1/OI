/*
 * Tree_Array.cpp
 *
 *  Created on: 2013-2-23
 *      Author: Luke.Xuan
 */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

namespace Tree_Array
{
	/*	ToDo:
	 *	@constants : modify here to adjust the size of arrays.
	 */

	const long MAX_SIZE = 10000;

	long data_amount;

	long data[MAX_SIZE];

	#define lowbit(x)			x&(-x)
	void initialize();
	void refresh(long position , long delta);
	long addup(long position);
	void point_change(long position , long delta);
	long segment_request(long right);
}

void Tree_Array::initialize()
{
	long _data [MAX_SIZE];

	memcpy(_data , data , sizeof(data));
	memset(data , 0 , sizeof(data));

	for(long position = 1 ; position <= data_amount ; position ++)
		point_change(position , _data [position]);

	return;
}

void Tree_Array::refresh(long position , long delta)
{
	/*	ToDo:
	 *	@function : To refresh the data [position].
	 */
}

long Tree_Array::addup(long position)
{
	/*	ToDo:
	 *	@function : To add up the data [position].
	 */

	return data [position];
}

void Tree_Array::point_change(long position , long delta)
{
	for(;position <= data_amount ; position += lowbit (position))
		refresh(position , delta);

	return;
}

long Tree_Array::segment_request(long position)
{
	long Return = 0;

	for(;position > 0 ; position -= lowbit (position))
		Return += addup(position);

	return Return;
}
