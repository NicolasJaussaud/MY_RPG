/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init.c
*/

#include "my.h"

fptr_t				*init_fptr1(fptr_t *f)
{
	f[10].fptr = &inventory_button4;
	f[11].fptr = &inventory_button5;
	f[12].fptr = &inventory_button6;
	f[13].fptr = &inventory_button7;
	f[14].fptr = &weapon_button1;
	f[15].fptr = &weapon_button2;
	f[16].fptr = &weapon_button3;
	f[17].fptr = &weapon_button4;
	f[18].fptr = &weapon_button5;
	f[19].fptr = &weapon_buttonselect;
	f[20].fptr = &go_to_scene_2;
	f[21].fptr = &go_to_scene_3;
	f[22].fptr = &shop1_buy;
	f[23].fptr = &shop1_close;
	return (f);
}

fptr_t				*init_fptr2(fptr_t *f)
{
	f[24].fptr = &shop1_button1;
	f[25].fptr = &shop1_button2;
	f[26].fptr = &shop1_button3;
	f[27].fptr = &shop2_buy;
	f[28].fptr = &shop2_button1;
	f[29].fptr = &shop2_button2;
	f[30].fptr = &shop2_button3;
	f[31].fptr = &shop2_button4;
	f[32].fptr = &shop3_buy;
	f[33].fptr = &shop3_button1;
	return (f);
}

fptr_t 				*init_fptr3(fptr_t *f)
{
	f[34].fptr = &shop3_button2;
	f[35].fptr = &shop3_button3;
	f[36].fptr = &shop3_button4;
	f[37].fptr = &shop3_button5;
	f[38].fptr = &shop3_button6;
	f[39].fptr = &shop3_button7;
	f[40].fptr = &shop3_button8;
	f[41].fptr = &shop3_button9;
	f[42].fptr = &shop3_button10;
	f[43].fptr = &shop3_button11;
	f[44].fptr = &go_to_scene_8;
	f[45].fptr = &search_car;
	f[46].fptr = &go_to_scene_6;
	f[47].fptr = &go_to_scene_4;
	f[48].fptr = &go_to_scene_5;
	f[49].fptr = &go_to_scene_9;
	f[50].fptr = &go_to_scene_10;
	f[51].fptr = &go_to_scene_11;
	return (f);
}

fptr_t 				*init_fptr4(fptr_t *f)
{
	f[52].fptr = &go_to_scene_12;
	f[53].fptr = &go_to_scene_0;
	f[54].fptr = &go_to_scene_13;
	f[55].fptr = &go_to_scene_14;
	f[56].fptr = &go_to_htp;
	f[57].fptr = &go_to_htpmenu;
	f[58].fptr = &quit_htp;
	f[59].fptr = &go_to_htppause;
	f[60].fptr = &go_to_continuepause;
	return (f);
}

fptr_t				*init_fptr5(fptr_t *f)
{
	f[61].fptr = &take_item_hospital;
	f[62].fptr = &go_to_dungeon_2;
	f[63].fptr = &go_to_dungeon_2_2;
	f[64].fptr = &go_to_dungeon_2_3;
	f[65].fptr = &take_item_pharmacie;
	f[66].fptr = &go_to_scene_21;
	f[67].fptr = &sound_plus_one;
	f[68].fptr = &sound_less_one;
	f[69].fptr = &go_to_old_scene;
	f[70].fptr = &quit_scene_settings_sound;
	f[71].fptr = &search_quest_2;
	f[72].fptr = &go_to_scene_23;
	f[73].fptr = &go_to_htp2;
	return (f);
}
