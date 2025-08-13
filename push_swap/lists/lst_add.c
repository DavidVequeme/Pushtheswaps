/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:07:35 by dvidal            #+#    #+#             */
/*   Updated: 2025/08/13 11:55:30 by dvidal           ###   ########.fr       */
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
        (*lst)->last = new;
        *lst = new;
    }
}