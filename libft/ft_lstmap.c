/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:25:04 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/31 12:23:01 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	if (result == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, tmp);
		lst = lst->next;
	}
	return (result);
}
