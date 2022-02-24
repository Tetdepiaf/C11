/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdufour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:30:56 by qdufour           #+#    #+#             */
/*   Updated: 2022/02/23 20:30:58 by qdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		asc;
	int		desc;

	i = 0;
	asc = 0;
	desc = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) >= 0)
			desc++;
		if (f(tab[i], tab[i + 1]) <= 0)
			asc++;
		i++;
	}
	if (asc == i || desc == i)
		return (1);
	return (0);
}
