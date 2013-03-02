/*
 * NP_thoery.cpp
 *
 *  Created on: 2013-2-7
 *      Author: Luke.Xuan
 */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

namespace NP_Thoery
{
	/*	ToDo:
	 *	@constants : modify here to adjust the size of arrays.
	 */
	long const MAXN = 10000;
	char dp(long originstatus , long shift_amount , long (* shift)(long origin , long index));
}

char NP_Thoery::dp (long originstatus , long shift_amount , long (* shift)(long origin , long index))
{
	long np [MAXN];
	memset(np , 0 , sizeof(np));
	for(long i = 0 ; i < originstatus ; i ++)
	if (np [i] == 0)
		for(long j = 0 ; j < shift_amount ; j ++)
			np [shift(i , j)] = 1;
	
	if (np [originstatus] == 0)
		return 'P';
	else
		return 'N';
}
