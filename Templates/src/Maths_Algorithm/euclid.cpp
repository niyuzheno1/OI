/*
 * euclid.cpp
 *
 *  Created on: 2013-3-4
 *      Author: Luke.Xuan
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int euclid(int x , int y)
{
	while (y > 0)
	{
		int temp = y;
		y = x % y;
		x = temp;
	}

	return x;
}
