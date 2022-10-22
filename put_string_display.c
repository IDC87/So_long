/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:45:56 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/10/19 19:09:10 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_string(t_tudo *tudo)
{
    if(tudo->grid.move_count != 0)
    mlx_clear_window(tudo->mlx_init, tudo->mlx_window);
    
    mlx_string_put(tudo->mlx_init, tudo->mlx_window, tudo->grid.width, tudo->grid.height * 44 + 22, 
    GOLD, "Number of moves:");
    mlx_string_put(tudo->mlx_init, tudo->mlx_window, tudo->grid.width + 110, tudo->grid.height * 44 + 22, 
    GOLD, ft_itoa(tudo->grid.move_count)); 

    

    
}

