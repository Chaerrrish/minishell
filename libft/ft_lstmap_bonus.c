/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaoh <chaoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 19:39:58 by chaoh             #+#    #+#             */
/*   Updated: 2023/10/25 16:53:11 by chaoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*rt_list;
	void	*tmp;

	rt_list = 0;
	if (lst == NULL || f == NULL || del == NULL)
		return (0);
	while (lst != NULL)
	{
		tmp = f(lst -> content);
		if (tmp == NULL)
			return (0);
		n_list = ft_lstnew(tmp);
		if (n_list == NULL)
		{
			free(tmp);
			ft_lstclear(&rt_list, del);
			return (0);
		}
		ft_lstadd_back(&rt_list, n_list);
		lst = lst -> next;
	}
	return (rt_list);
}
