/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:07:35 by dvidal            #+#    #+#             */
/*   Updated: 2025/08/26 16:00:05 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void lst_add_front(t_list **lst, t_list *new)
{
    if (lst != NULL)
    {
        if (new == NULL)
            return;
        new->next = *lst;
        (*lst)->prev = new;
        *lst = new;
    }
}