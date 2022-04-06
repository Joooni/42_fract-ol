/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:23:53 by jsubel            #+#    #+#             */
/*   Updated: 2022/04/04 08:57:10 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H
# ifdef __linux__

#  define ARROW_LEFT		0xff51
#  define ARROW_RIGHT		0xff53
#  define ARROW_UP			0xff52
#  define ARROW_DOWN		0xff54

#  define MOUSE_UP			5
#  define MOUSE_DOWN		4

#  define KEY_ESCAPE		0xff1b
#  define KEY_SPACE			0x20
#  define KEY_PLUS			0xffab
#  define KEY_MINUS			0xffad
#  define KEY_R				0x72
#  define KEY_C				0x63
# else
#  define ARROW_LEFT		123
#  define ARROW_RIGHT		124
#  define ARROW_UP			126
#  define ARROW_DOWN		125

#  define MOUSE_UP			4
#  define MOUSE_DOWN		5

#  define KEY_ESCAPE		53
#  define KEY_SPACE			49
#  define KEY_PLUS			30
#  define KEY_MINUS			44
#  define KEY_R				15
#  define KEY_C				8
# endif
#endif