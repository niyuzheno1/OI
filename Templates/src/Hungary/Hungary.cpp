/*
 * Hungary.cpp
 *
 *  Created on: 2013-2-8
 *      Author: Luke.Xuan
 */
namespace Hungary
{
	/*	ToDo:
	 * 	@constants : modify here to adjust the size of arrays.
	 */

	/*	Locator:
	 *	@arguments : @[scalar] , @[variables] , @[sizes]
	 */

	long const MAX_EDGE = 10000;
	long const MAX_VERTICE = 100;

	/*	Locator:
	 *	@argument : @[arrays] , @[variables] , @[edges] , @[vertices] , @[graphs]
	 */

	long start [MAX_VERTICE];
	long visited [MAX_VERTICE];
	long match [MAX_EDGE];
	long link [MAX_EDGE];
	long begin [MAX_EDGE];
	long end [MAX_EDGE];

	/*	Locator:
	 *	@argument : @[functions] , @[dfs] , @[hungary] , @[define]
	 */

	bool hungary_dfs(long position);
}

/*	Locator:
 *	@argument : @[functions] , @[dfs] , @[hungary] , @[define]
 */

bool Hungary::hungary_dfs (long position)
{
	if (visited [position] == 0)
		return 0;
	if (position == 0)
		return 1;
	for(long e = start [position] ; e ; e ++)
	{
		long y = end [e];
		if (hungary_dfs(match [y]))
		{
			match [y] = position;
			return 1;
		}
	}

	return 0;
}
