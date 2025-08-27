/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:48:08 by dvidal            #+#    #+#             */
/*   Updated: 2025/08/26 16:00:26 by dvidal           ###   ########.fr       */
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
    node->prev = NULL;
    return(node);
}