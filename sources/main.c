/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:15:12 by ablaamim          #+#    #+#             */
/*   Updated: 2022/03/25 11:59:17 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	if (argc - 1 == 0x0)
		return (EXIT_FAILURE);
	data = ft_data_initializer(argc, argv);
	return (EXIT_SUCCESS);
}
