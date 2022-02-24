/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:57:59 by qdufour           #+#    #+#             */
/*   Updated: 2022/02/24 14:58:01 by qdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);

int	ft_atoi(char *str)
{
	int		i;
	int		neg;
	char	res;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] && (str[i] > 47 && str[i] < 58))
	{
		res = 10 * res + str[i] - 48;
		i++;
	}
	return (res * neg);
}

void	ft_putnbr(int nbr)
{
	long int	nbr2;
	int			i;
	int			res;

	i = 0;
	res = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr2 = nbr;
		nbr2 = -nbr2;
		i++;
	}
	else
		nbr2 = nbr;
	if (nbr2 >= 10)
		ft_putnbr(nbr2 / 10);
	res = nbr2 % 10 + 48;
	write(1, &res, 1);
}
