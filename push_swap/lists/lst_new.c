/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:48:08 by dvidal            #+#    #+#             */
/*   Updated: 2025/08/13 13:48:16 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list *lst_new(int content)
{
    t_list *node;
    
    node = malloc(sizeof (t_list));
    if (!node)
        return(NULL);
    node->n = content;
    node->next = NULL;
    node->last = NULL;

    return(node);
}