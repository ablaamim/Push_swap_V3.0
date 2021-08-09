/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaamimi <alaamimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:54:08 by alaamimi          #+#    #+#             */
/*   Updated: 2021/08/08 15:17:00 by alaamimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int	main(void)
{
	int	a;
	int	b;
	int i;

	string value[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	cin>> a >> b;
	i = a;
	while (i <= b)
	{
		if (i > 9)
		{
			if (i % 2 == 0)
				cout<<"even"<<endl;
			else 
				 cout<<"odd"<<endl;
		}
		else
			cout<<value[i]<<endl;
		i++;
	}
	return (0);
}
