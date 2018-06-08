/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** parser_obj.c
*/

#include "my.h"

void 				parser_obj(all_t *all, char *line)
{
	obj_val_t ov;

	ov.rect = get_rect(line);
	ov.size_max = get_size_max(line);
	ov.offset = get_offset(line);
	ov.pos.x = get_pos_x(line);
	ov.pos.y = get_pos_y(line);
	ov.type = get_type(line);
	ov.display = get_display(line);
	ov.opacity = get_opacity(line);
	ov.despawn = get_despawn(line);
	ov.texture = all->textures[get_texture_id(line)];
	create_object(all, ov);
}

void 				parser_btn(all_t *all, char *line)
{
	btn_val_t bv;
	bv.size.x = get_size_x(line);
	bv.size.y = get_size_y(line);
	bv.pos.x = get_pos_x(line);
	bv.pos.y = get_pos_y(line);
	bv.rect = get_rect(line);
	bv.offset = get_offset(line);
	bv.state = get_state(line);
	bv.display = get_display(line);
	bv.callback = get_func_id(line);
	bv.type = get_type(line);
	bv.texture = all->textures[get_texture_id(line)];
	create_button(all, bv);
}

void 				parser_txt(all_t *all, char *line)
{
	txt_val_t tv;

	tv.type = get_type(line);
	tv.str = get_str(line);
	tv.display = get_display(line);
	tv.pos.x = get_pos_x(line);
	tv.pos.y = get_pos_y(line);
	tv.size = get_size(line);
	tv.font = all->fonts[get_font_id(line)];
	tv.color = get_sf_color(get_color(line));
	create_text(all, tv);
}
