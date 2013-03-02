/*
 * KMP.cpp
 *
 *  Created on: 2013-2-26
 *      Author: Luke.Xuan
 */

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

namespace KMP
{
	char pattern [100];
	char origin [10000];
	int preffix [100];

	void KMP(void);
}


void KMP::KMP(void)
{
	int preffix [1000];

	preffix [0] = -1;
	int shift = preffix [0];

	for(unsigned int index = 1 ; index < strlen(pattern) ; index ++)
	{
		while ((preffix [0] > 0) && (pattern [index] != pattern [shift]))
			shift = preffix [shift];
		if(pattern [index] == pattern [shift])
			shift ++;
		preffix [index] = shift;
	}

	for(unsigned int index = 1 ; index < strlen(pattern) ; index ++)
	{
		while((preffix [0] > 0)&&(pattern [index] != pattern [shift]))
			shift = preffix [shift];
		if (shift == strlen (pattern))
			printf("Pattern occurs with shift: %d\n" , index - shift);
	}

	return;
}
