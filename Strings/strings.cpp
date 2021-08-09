/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaamimi <alaamimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:21:01 by alaamimi          #+#    #+#             */
/*   Updated: 2021/08/09 19:34:41 by alaamimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
using namespace std;

int	main(void)
{
	string str1;
	string str2;

	cin>>str1;
	cin>>str2;

	int len1;
	int len2;

	len1 = str1.size();
	len2 = str2.size();
	cout<<len1<<" ";
	cout<<len2<<endl;
	string cancat;

	cancat = str1 + str2;
	cout<<cancat<<endl;
	char tmp;

	tmp = str1[0];
	str1[0] = str2[0];
	str2[0] = tmp;
	cout<<str1<<" "<<str2;    
	return (0);
}
