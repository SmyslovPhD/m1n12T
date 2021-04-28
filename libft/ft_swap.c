/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:55:05 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/16 20:56:27 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, size_t k)
{
	char	tmp;

	while (k--)
	{
		tmp = ((char*)a)[k];
		((char *)a)[k] = ((char *)b)[k];
		((char *)b)[k] = tmp;
	}
}