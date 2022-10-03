/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:47:22 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/09/24 15:03:12 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void not_rect(t_grid *map)
{
    if (map->width == map->height)
    {
        printf("ERROR\n Map cannot be a square!\n");
        exit(0);
    }
    
}
