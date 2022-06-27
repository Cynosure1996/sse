/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 14:22:20 by fchrysta          #+#    #+#             */
/*   Updated: 2021/10/23 16:57:31 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void*))
{
	t_list	*t_next;

	while (*lst)
	{
		t_next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = t_next;
	}
	free(*lst);
	lst = NULL;
}
