/*
 * euclid_extended.cpp
 *
 *  Created on: 2013-3-4
 *      Author: Luke.Xuan
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

/*	Description:
 *	solve a * x + b * y = 1.
 */

bool euclid_extended(int a , int b , int * x , int * y)
{
	int _x , _y;

	if (b > 0)
		if (! euclid_extended(b , a % b , & _x , & _y))
			return false;

	if (b == 0)
	{
		if (a != 1)
			return false;
		(* x) = 1;
		(* y) = 0;
	}
	else
	{
		(* x) = _y;
		(* y) = _x - (a / b) * _y;

	}

	return true;
}
