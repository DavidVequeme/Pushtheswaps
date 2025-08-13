/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:57:25 by dvidal            #+#    #+#             */
/*   Updated: 2025/08/13 13:55:29 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void lst_add_back(t_list **lst, t_list *new)
{
    t_list *node;
    if (lst != NULL)
    {
        if(*lst != NULL)
        {
            node = lstlast(*lst);
            node->next = new;
            new->last = node;
        }
        else
            *lst = lst_new(lst);
    }
}