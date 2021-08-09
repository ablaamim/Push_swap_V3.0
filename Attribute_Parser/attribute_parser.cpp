/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_parser.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaamimi <alaamimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 22:30:27 by alaamimi          #+#    #+#             */
/*   Updated: 2021/08/09 22:32:51 by alaamimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class HrmlDoc
{
	string	path_;
	map<string, string> attributes_;

public:
	void operator<<(const string& s)
    {
		if (s.compare(0, 2, "</") == 0)
		{
            //string tag = s.substr(2, s.find('>', 2) - 2);
			path_.resize(path_.rfind('.'));
		}
		else
		{
			string::size_type p, q;

			p = s.find(' ', 2);
			if (p == string::npos)
			{
				p = s.find('>', 2);
				path_ += "." + s.substr(1, p - 1);
			}
			else
			{
				path_ += "." + s.substr(1, p - 1);

				++p;
				while ((q = s.find(" = ", p)) != string::npos) 
				{
					string attr = s.substr(p, q - p);
					p = s.find('"', q) + 1;
					q = s.find('"', p);
					string value = s.substr(p, q - p);

					attributes_[path_.substr(1) + "~" + attr] = value;
					p = q + 2;
				}
			}
		}
	}

	string query(const string& path) const
	{
		const auto& i = attributes_.find(path);
		if (i == attributes_.end())
			return ("Not Found!");
		else
			 return (i->second);
	}
};


int	main(void) 
{
	int N, Q;
	string s;
	HrmlDoc hrml;
	stringstream ss;

	getline(cin, s);
	ss<<s;
    ss>>N>>Q;

	while (N--) 
	{
		getline(cin, s);
		hrml<<s;
	}

	while (Q--) 
	{
		getline(cin, s);
		cout<<hrml.query(s)<<std::endl;
	}

	return (0);
}
