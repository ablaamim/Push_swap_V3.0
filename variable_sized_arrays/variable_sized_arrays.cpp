/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_sized_arrays.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaamimi <alaamimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 02:09:19 by alaamimi          #+#    #+#             */
/*   Updated: 2021/08/09 16:54:55 by alaamimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
using namespace std;

int main(void)
{
	int	N;
	int	Q;
	int	k;
	int	**data;

	scanf("%d %d", &N, &Q);
	data = new int*[N];
	int i = 0;
	while (i < N) 
	{
		scanf("%d", &k);
		data[i] = new int[k];
		int j = 0;
		while (j < k) 
		{
			scanf("%d", &data[i][j]);
			j++;
		}
		i++;
	}

	int	a;
	int	b;

	i = 0;
	while (i < Q)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", data[a][b]);
		i++;
	}
	return (0);
}
