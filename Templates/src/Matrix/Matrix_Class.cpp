/*
 * matrix_class.cpp
 *
 *  Created on: 2013-2-8
 *      Author: Luke.Xuan
 */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

class matrix
{
public:
	long data [100][100];
	long width;
	long height;
	matrix operator * (matrix mulplier);
	long * operator [] (long pos);
	matrix power(long index);
};

long * matrix::operator [] (long pos)
{
	return data [pos];
}

matrix matrix::operator * (matrix mulplier)
{
	matrix ret;

	memset(ret . data , 0 , sizeof(ret . data));

	ret . height = mulplier . height;
	ret . width = width;

	for(long i = 0 ; i < width ; i ++)
	for(long j = 0 ; j < mulplier . height ; j ++)
	for(long k = 0 ; k < height ; k ++)
		ret [i][j] += data[i][k] * mulplier [k][j];

	return ret;
}

matrix matrix::power (long index)
{
	matrix ret , base;
	base = * this;
	memset(ret . data , 0 , sizeof(ret . data));

	ret . height = ret . width = height;
	for(long i = 0 ; i < ret . height ; i ++)
		ret [i][i] = 1;

	for(long counter = index ; counter ; counter /= 2)
	{
		if (counter % 2)
			ret = ret * base;
		base = base * base;
	}

	return ret;
}

