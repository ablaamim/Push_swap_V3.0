/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_streams.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaamimi <alaamimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:57:34 by alaamimi          #+#    #+#             */
/*   Updated: 2021/08/09 19:19:27 by alaamimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str)
{
	stringstream ss(str);
	vector<int> result;
	char	ch;
	int		tmp;

	while (ss >> tmp)
	{
		result.push_back(tmp);
		ss >> ch;
	}

	return result;
}
int	main(void)
{
	string	str;
    cin >>str;
    vector<int> integers = parseInts(str);
    int	i;

	i = 0;
	while (i < integers.size())
	{
		cout << integers[i] << "\n";
		i++;
	}

	return (0);
}
