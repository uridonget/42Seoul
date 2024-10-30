/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haejeong <haejeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:03:37 by haejeong          #+#    #+#             */
/*   Updated: 2023/10/19 12:04:23 by haejeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*set;

	if ((!(lst)) || (!(f)))
		return (NULL);
	new = NULL;
	while (lst)
	{
		set = f(lst->content);
		node = ft_lstnew(set);
		if (!(node))
		{
			del(set);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	lst = NULL;
	return (new);
}
