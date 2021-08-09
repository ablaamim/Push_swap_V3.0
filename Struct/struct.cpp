/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaamimi <alaamimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:34:16 by alaamimi          #+#    #+#             */
/*   Updated: 2021/08/09 22:36:05 by alaamimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

struct Student
{
	int	age;
	string	first_name;
	string	last_name;
	int	standard;
};

int main(void)
{
	Student	st;

	cin>>st.age>>st.first_name>>st.last_name>>st.standard;
	cout<<st.age<<" "<<st.first_name<<" "<<st.last_name<<" "<<st.standard;

	return (0);
}
