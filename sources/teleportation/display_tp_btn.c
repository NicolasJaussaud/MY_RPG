/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** display_tp_btn.c
*/

#include "my.h"

void 				display_only_near_tp_txt(all_t *all)
{
	text_t *txt = all->scenes[all->current_scene].txt;
	object_t *p = all->scenes[all->current_scene].obj;

	while (p && p->type != PLAYER)
		p = p->next;
	while (txt) {
		if (txt->type == TP_TXT) {
			if (p->pos.x + p->rect.width + 50 > txt->pos.x &&
			p->pos.x < txt->pos.x + 150 + 50 &&
			p->pos.y + p->rect.height + 50 > txt->pos.y &&
			p->pos.y < txt->pos.y + 50 + 50)
				txt->display = 1;
			else
				txt->display = 0;
		}
		txt = txt->next;
	}
}

void 				display_only_near_tp_btn_core
(button_t *btn, object_t *p)
{
	if ((btn->type == TP || btn->type == CAR ) && btn->enable == 1) {
		if (p->pos.x + p->rect.width + 50 > btn->pos.x &&
		p->pos.x < btn->pos.x + btn->size.x + 50 &&
		p->pos.y + p->rect.height + 50 > btn->pos.y &&
		p->pos.y < btn->pos.y + btn->size.y + 50) {
			btn->display = 1;
		} else
			btn->display = 0;
	}
}

void 				display_only_near_tp_btn(all_t *all)
{
	button_t *btn = all->scenes[all->current_scene].btn;
	object_t *p = all->scenes[all->current_scene].obj;

	if (CST != GAME && CST != SHOP && CST != LABO &&
	CST != HOSPITAL && CST != PHARMACIE)
		return;
	while (p && p->type != PLAYER)
		p = p->next;
	while (btn) {
		display_only_near_tp_btn_core(btn, p);
		btn = btn->next;
	}
	display_only_near_tp_txt(all);
}