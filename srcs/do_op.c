/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:30:21 by qdufour           #+#    #+#             */
/*   Updated: 2022/02/24 14:30:24 by qdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_atoi(char *str);
void	ft_putnbr(int nbr);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	is_operateur(char *op)
{
	int	i;

	i = 0;
	while (op[i])
		i++;
	if (i != 1)
		return (1);
	if (op[0] != '+' && op[0] != '-' && op[0] != '*'
		&& op[0] != '/' && op[0] != '%')
		return (1);
	return (0);
}

void	cas_div(int nbr1, int nbr2)
{
	if (nbr2 == 0)
		ft_putstr("Stop : division by zero");
	else
		ft_putnbr(nbr1 / nbr2);
}

void	do_op(char *nb1, char *op, char *nb2)
{
	int	nbr1;
	int	nbr2;

	nbr1 = ft_atoi(nb1);
	nbr2 = ft_atoi(nb2);
	if (op[0] == '+')
		ft_putnbr(nbr1 + nbr2);
	if (op[0] == '-')
		ft_putnbr(nbr1 - nbr2);
	if (op[0] == '*')
		ft_putnbr(nbr1 * nbr2);
	if (op[0] == '/')
		cas_div(nbr1, nbr2);
	if (op[0] == '%')
	{
		if (nbr2 == 0)
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr(nbr1 % nbr2);
	}
	ft_putstr("\n");
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	if (is_operateur(av[2]))
	{
		ft_putstr("0\n");
		return (0);
	}
	do_op(av[1], av[2], av[3]);
	return (0);
}
