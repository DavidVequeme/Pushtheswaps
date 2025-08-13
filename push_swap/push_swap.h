/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:23:53 by dvidal            #+#    #+#             */
/*   Updated: 2025/08/13 14:52:31 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "lists/list.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct s_ab
{
    int a;
    struct s_ab *next;
    struct s_ab *previous;
} t_ab;

int ft_isalpha(int c);
int parcing(char *s);
int ft_issign(int c);
int ft_leng(char *s);
void ft_close();
char	**ft_split(char const *s, char c);
int arr(t_ab **lst, char *s);
int parcing(char *s);


# endif