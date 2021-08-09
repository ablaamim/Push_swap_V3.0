/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaamimi <alaamimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 02:04:39 by alaamimi          #+#    #+#             */
/*   Updated: 2021/08/09 02:06:26 by alaamimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int	main(void)
{
	int size;
	cin>> size;
	int arr[size];
	int i;

	i  = 0;
	while (i < size)
	{
		cin>>arr[i];
		i++;
	}
	i = size - 1;
	while (i >= 0)
	{
		cout<<arr[i]<<" ";
		i--;
	}
	return (0);
}
