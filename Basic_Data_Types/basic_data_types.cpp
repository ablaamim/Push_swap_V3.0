/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_data_types.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaamimi <alaamimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 20:47:27 by alaamimi          #+#    #+#             */
/*   Updated: 2021/08/07 20:48:24 by alaamimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	int nb;
	long long_number;
	char character;
	float decimal;
	double double_decimal;

	scanf("%d %ld %c %f %lf", &nb, &long_number, &character, &decimal, &double_decimal);
	printf("%d\n%ld\n%c\n%f\n%lf\n", nb, long_number, character, decimal, double_decimal);
	return (0);
}
