/*
 * SegmentTree.cpp
 *
 *  Created on: 2013-2-9
 *      Author: Luke.Xuan
 */

#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

/*	ToDo:
 *	@constants : To prevent RTE, modify the MAX_TREE_SIZE value here.
 */

long const MAX_TREE_SIZE = 400000;

/*	ToDo:
 *	@variables : Remember to add the operation_amount to this variable block.
 */

long data_amount;

/*	ToDo:
 *	@variables : Add data variables to this variable block.
 */

/*	ToDo:
 *	@variables : Add more variables to this variable block if is needed to record the alter.
 */
long delta[MAX_TREE_SIZE];
long active[MAX_TREE_SIZE];

long base , height;

void merge(long position)
{
	/*	ToDo:
	 *	@function : To merge data from [position * 2] and data [position * 2 + 1] into [position]
	 */
	return;
}

void refresh(long position , long alter)
{
	/*	ToDo:
	 *	@function : To apply alter to [position]
	 */
	if (position < base)
		active [position] = 1;
}

void pushdown(long position)
{
	if (active [position])
	{
		refresh(position << 1 , delta [position]);
		refresh((position << 1) + 1 , delta [position]);
		delta [position] = 0;
	}
	active [position] = 0;
}

void pushover(long pos)
{
	for(long i = height ; i ; i --)
		pushdown(pos >> i);
}

long point_request(long position)
{
	pushover(position += base);

	long Return;

	/*	ToDo:
	 *	@function : To move data [position] to Return
	 */

	return Return;
}

long segment_request(long Left , long Right)
{
	pushover(Left += base - 1);
	pushover(Right += base + 1);
	long Return = 0;
	while(Left + 1 < Right)
	{
		if (!(Left & 1))
		{
			/*	ToDo:
			 *  @function : To take data [l + 1] into account.
			 *
			 */
		}

		if (Right & 1)
		{
			/*	ToDo:
			 *  @function : To take data [r - 1] into account.
			 */
		}

		Left >>= 1;
		Right >>= 1;
	}
	/*	ToDo:
	 *	@function : To modify the final return value.
	 */
	return Return;
}

void point_change(long position , long alter)
{
	pushover(position += base);
	refresh(position , alter);
	for(long i = 1 ; i <= height ; i ++)
		merge(position >> i);
}

void segment_change(long Left , long Right , long alter)
{
	long ll = (Left += base - 1);
	long rr = (Right += base + 1);
	pushover(Left);
	pushover(Right);
	while(Left + 1 < Right)
	{
		if (!(Left & 1))
			refresh(Left + 1 , alter);
		if (Right & 1)
			refresh(Right - 1 , alter);
		Left >>= 1;
		Right >>= 1;
	}

	for(long i = 1 ; i <= height ; i ++)
	{
		merge (ll >> i);
		merge (rr >> i);
	}
}

void initialize(void)
{

	memset(active , 0 , sizeof(active));

	for(base = 1 , height = 0 ; base < data_amount + 2 ; height ++)
		base <<= 1;

	for(long i = 1 ; i <= data_amount ; i ++)
	{
		/*	ToDo:
		 *	@function : To input data into segment tree.
		 */
	}

	for(long i = base - 1 ; i ; i --)
		merge (i);

	return;
}
