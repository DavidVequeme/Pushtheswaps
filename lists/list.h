/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:48:28 by dvidal            #+#    #+#             */
/*   Updated: 2025/08/27 14:31:33 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <stdlib.h>

typedef struct s_list
{
    int n;
    struct s_list *next;
    struct s_list *prev;
} t_list;

t_list *lst_last(t_list *lst);
void lst_add_front(t_list **lst, t_list *new);
void lst_clear(t_list **lst);
t_list *lst_new(int content);
void lst_add_back(t_list **lst, int new);
int lst_size(t_list *lst);
#endif