/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaamimi <alaamimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:35:16 by alaamimi          #+#    #+#             */
/*   Updated: 2021/08/09 01:28:11 by alaamimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

void	update(int *a,int *b)
{
	int	sum;
	int	diff;
	int	pa;
	int	pb;
	pa = *a;
	pb = *b;
	sum = pa + pb;
	*a = sum;
	cout<<*a<<endl;
	diff = pa - pb;
	if (diff < 0)
	{
		*b = -1 * diff; 
		cout<<*b<<endl;
	}
	else
	{
		*b = diff;
		cout<<*b<<endl;
	}
}

int	main(void)
{
	int	a, b;
	int	*pa = &a, *pb = &b;

	cin>> a >> b ;
	update(pa, pb);
	return 0;
}
