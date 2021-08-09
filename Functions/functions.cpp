/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaamimi <alaamimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:15:41 by alaamimi          #+#    #+#             */
/*   Updated: 2021/08/08 21:32:26 by alaamimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d)
{
	int max;
	if (a > b && a > c && a > d)
		 max = a;
	else if (b > c && b > d)
		max = b;
	else if (c > d)
		max = c;
	else
		max = d;
	return (max);
}

int main(void)
{
	int a;
	int b;
	int c;
	int d;
	int max;

	cin>>a;
	cin>>b;
	cin>>c;
	cin>>d;
	max = max_of_four(a, b, c, d);
	cout<<max<<endl; 
	return (0);
}
