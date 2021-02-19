/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:16:27 by mmatsego          #+#    #+#             */
/*   Updated: 2021/01/16 13:28:12 by mmatsego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list		*list;

	if (lst == NULL)
		return ;
	list = lst;
	while (list->next != NULL)
	{
		f(list->content);
		list = list->next;
	}
	f(list->content);
}
