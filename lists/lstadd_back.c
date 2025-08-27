/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:57:25 by dvidal            #+#    #+#             */
/*   Updated: 2025/08/27 14:50:51 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

void lst_add_back(t_list **lst, int new)
{
    t_list *node;
    t_list *end;

    if (lst != NULL)
    {
        node = lst_new(new);
        if(node != NULL)
        {
            if(*lst != NULL)
            {
                end = lst_last(*lst);
                node->prev = end;
                end->next = node;
            } 
            else
                *lst = node;
        }   
    }
}