/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:13:59 by dvidal            #+#    #+#             */
/*   Updated: 2025/08/18 14:15:52 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void clear(t_list **lst)
{
    if ((*lst)->next != NULL)
        clear (&((*lst)->next));
    free(*lst);
}

void lst_clear(t_list **lst)
{
    if (lst != NULL && (*lst)->next != NULL)
    {
        clear(lst);
        *lst = NULL;
    }
}