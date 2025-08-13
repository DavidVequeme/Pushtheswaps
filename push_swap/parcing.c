/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvidal <dvidal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:44:18 by dvidal            #+#    #+#             */
/*   Updated: 2025/08/13 14:46:55 by dvidal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
int ft_issign(int c)
{
    if (c == '-' || c == '+')
        return(1);
    else
        return (0);
}

long ft_atoi(char *str)
{
    int index;
    long sign;
    long result;

    index = 0;
    sign = 1;
    result = 0;
    while (str[index] == ' ' || (str[index] >= '\t' && str[index] <= '\r'))
        index++;
    if (str[index] == '-' || str[index] == '+')
    {
        if (str[index] == '-')
            sign = -1;
        index++;
    }
    while (str[index] >= '0' && str[index] <= '9')
    {
        result = result * 10 + (str[index] - '0');
        index++;
    }
    return(sign * result);
}
int arr(t_ab **lst, char *s)
{
    int i;
    int *arr;
    long num;

    i = 0;
    num = 0;
    arr = ft_split(s, ' ');
    while (arr[i])
    {
        num = ft_atoi(arr[i]);
        if (num > INT_MAX && num < INT_MIN)
            return (0);
        lst_add_back(lst, lst_new(num));
    }
    return(1);
}


int parcing(char *s)
{
    int i;

    i = 0;
    while(s[i])
    {
        if (ft_isalpha(s[i]))
            return(0);  
        if (ft_issign(s[i]) && s[i] != ' ')
        {
            if (ft_issign(s[i + 2]))
                return(0);
            if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
                return(0);
        }
        i++;
    }
    return(1);
}

void ft_close()
{
    printf("entrou\n");
}