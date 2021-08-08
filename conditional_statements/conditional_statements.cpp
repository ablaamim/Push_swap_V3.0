/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditional_statements.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaamimi <alaamimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 14:24:43 by alaamimi          #+#    #+#             */
/*   Updated: 2021/08/08 14:26:31 by alaamimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int	main(void)
{
	int	n;

	cin>>n;
	if (n >= 1 && n <= 9)
	{
		if (n == 1)
			cout<<"one";
		else if (n == 2)
			cout<<"two";
		else if (n == 3)
			cout<<"three";
		else if (n == 4)
			cout<<"four";
		else if (n == 5)
			cout<<"five";
		else if (n == 6)
			cout<<"six";
		else if (n == 7)
			cout<<"seven";
		else if (n == 8)
			cout<<"eight";
		else
			cout<<"nine";
	}
	else
		cout<<"Greater than 9";
	return (0);
}

