/*
** EPITECH PROJECT, 2018
** MY_RPG
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>

#define ALL_HUD_BAR LIFE_BAR && tmp->type != XP_BAR && tmp->type != HUNGER_BAR && tmp->type != THIRST_BAR && tmp->type != HUD_BAR
#define NOT_MOVABLE_WITH_CAMERA tmp->type != PLAYER && tmp->type != ALL_HUD_BAR && tmp->type != MINIMAP && tmp->type != RAIN && tmp->type != YOU_QUEST && tmp->type != NOT_YET_DUNGEON
#define CST all->scenes[all->current_scene].type
#define NOT_ECHAP CST != GAME && CST != SHOP && CST != MENU && CST != HOSPITAL && CST != LABO && CST != PHARMACIE
#define PLAYING_SCENE CST == GAME || CST == SHOP || CST == HOSPITAL || CST == LABO || CST == PHARMACIE
#define OST all->old_scene
#define OLD_PLAYING_SCENE OST == GAME || OST == SHOP || OST == HOSPITAL || OST == LABO || OST == PHARMACIE
#define NOT_PLAYING_SCENE CST != GAME && CST != SHOP && CST != HOSPITAL && CST != LABO && CST != PHARMACIE
#define CAN_ESCAPE_SCENE CST == INVENTORY || CST == MINIMAP_S || CST == BOISSONS || CST == NOURRITURES || CST == ARMES || CST == PROF_DIALOGUE
#define STEP all->his.step_h
#define STEP_QUEST STEP != 0 && STEP != 1 && STEP != 4 && STEP != 5 && STEP != 12 && STEP != 13
#define STEP_NOT_QUEST STEP != 2 && STEP != 3 && STEP != 6 && STEP != 7  && STEP != 8  && STEP != 9  && STEP != 10  && STEP != 11
#define INTERMEDIATE_STEP STEP == 0 || STEP == 1 || STEP == 3 || STEP == 5 || STEP == 7 || STEP == 9 || STEP == 11 || STEP == 13
#define RANDOM_SHOTS -1.0 + ((double)all->player.stat.stat_precision / 100), (1.0 - ((double)all->player.stat.stat_precision / 100))
#define BTN_MOVABLE_CAM btn->type == TP || btn->type == CAR || btn->type == Q21 || btn->type == Q22 || btn->type == Q23

#define DIAL_1 "John, maintenant que j\'ai trouve comment faire l\'antidote,\nil faut que tu m\'aides. Va chercher dans l\'hopital une XXX.\nL\'hopital se situe au nord ouest de la ville.\n Rapporte le moi des que tu as finis!"
#define DIAL_2 "C\'est bien, tu as ete rapide. Il me faudrait\nmaintenant du sang de zombie pour pouvoir\nfaire mon antidote.\nTa mission est d\'aller en tuer 30. Reviens me voir apres"
#define DIAL_3 "Grace a ce sang John, nous allons surement\npouvoir sauver des millions de vies! Il faudrait\nmaintenant que tu ailles chercher de l\'oleox\ndans la pharmacie, qui se situe au nord est\nde la ville. Reviens me voir apres"
#define DIAL_4 "Parfait! Par contre nous nous sommes fait\nattaquer, la population de zombie dans la ville\na double. Mais il faudrait quand meme que tu\nailles recuperer XXX dans la voiture, a cote de\nl'hospital. Reviens me voir apres"
#define DIAL_5 "Merci ! L\'invasion continue... \nIl faut que tu ailles me chercher XXX dans la\nville. Dans le camion pompier a cote du macdo.\nReviens me voir apres"
#define DIAL_6 "Tu es vraiment bon. Il me manque plus qu\'XXX\na aller chercher dans le seul bus de la ville, comme d\'habitude.\nReviens me voir apres"
#define DIAL_7 "Parfait ! Il ne manque qu\'un element pour\nrealiser l\'antidote ! Il se situe dans la fac de\nscience, c\'est encore un medicament : du zaldiar. Reviens me voir apres"
#define DIAL_8 "Bien joue ! Je vais enfin pouvoir finir\nl\'antidote et eradiquer ce fichu virus\nde la ville ! Le colorado est sauve !"

typedef struct all_s all_t;
typedef struct object_s object_t;
typedef struct button_s button_t;
typedef struct text_s text_t;
typedef struct shot_s shot_t;
typedef struct mob_s mob_t;

typedef enum 			type_txt_s
{
	LEVEL, TXT_CARAC, AGILITY, PRECISION, THIRST, HUNGER, TO_SHARE, MONEY, TP_TXT, DIALOGUE, CAR_MONEY, CAR_FOOD, QUEST_1
}				type_txt_t;

typedef enum 			direction_s
{
	UP, DOWN, RIGHT, LEFT
}				direction_t;

typedef enum 			type_btn_s
{
	ADD_CARAC, INVENTORYB, TP, NEXT, CAR, Q21, Q22, Q23
}				type_btn_t;

typedef enum 			type_scene_s
{
	GAME, MENU, INVENTORY, PROF_DIALOGUE, BOISSONS, NOURRITURES, ARMES, MINIMAP_S, SHOP, HOSPITAL, DEATH, LABO, HTPPOPUP, HTP, PAUSE, PHARMACIE, SOUND, FIND_ITEM, INTRO, HTP2
}				type_scene_t;

typedef enum 			type_obj_s
{
	PLAYER, BG, TITLE, OBJ, LIFE_BAR, XP_BAR, HUNGER_BAR, THIRST_BAR, HUD_BAR, HALO, BLOOD, CURSOR_PLAYER, MINIMAP, RAIN, CAR_FOOD_O, B_A_W, KAZ, RECUP_OBJ, YOU_QUEST, NOT_YET_DUNGEON, SOUND1
}				type_obj_t;

typedef struct			sound_s
{
	float			sound_env;
}				sound_t;

typedef struct 			dialog_s
{
	char 			*str;
}				dialog_t;

typedef struct 			history_s
{
	int 			step_h;
	int			quest_1;
	dialog_t 		*dialog;
}				history_t;

typedef struct 			htp_s
{
	int 			old_scene;
}				htp_t;

typedef struct 			pause_s
{
	int 			init;
	int 			old_scene;
}				pause_t;

typedef struct 			shot_s
{
	sfSprite 		*sprite;
	sfVector2f 		pos;
	int			scene;
	int 			actual_range;
	shot_t 			*next;
	sfVector2f 		speed;
	sfVector2f 		random_pres;
	int 			hit;
}				shot_t;

typedef struct 			my_clock_s
{
	sfTime 			time;
	sfClock 		*clock;
	int 			n;
	int 			n2;
	float 			seconds;
}				my_clock_t;

typedef struct 			obj_val_s
{
	int 			display;
	sfVector2f 		pos;
	sfIntRect 		rect;
	int 			offset;
	int 			size_max;
	sfTexture 		*texture;
	int 			opacity;
	int 			despawn;
	type_obj_t 		type;
}				obj_val_t;

typedef struct 			object_s
{
	int 			display;
	sfSprite 		*sprite;
	sfVector2f 		pos;
	sfVector2f 		old_pos;
	sfIntRect 		rect;
	int 			offset;
	int 			size_max;
	type_obj_t		type;
	int 			despawn;
	int 			spawned;
	object_t 		*next;
}				object_t;

typedef struct 			btn_val_s
{
	int 			display;
	sfVector2f 		size;
	sfVector2f 		pos;
	sfIntRect 		rect;
	int 			offset;
	int 			state;
	int 			callback;
	sfTexture 		*texture;
	type_btn_t 		type;
}				btn_val_t;

typedef struct 			button_s
{
	type_btn_t 		type;
	int 			display;
	sfRectangleShape	*shape;
	sfVector2f 		size;
	sfVector2f 		pos;
	sfVector2f 		old_pos;
	sfIntRect		rect;
	int 			enable;
	int 			offset;
	int 			state;
	void			(*callback)(all_t *);
	button_t 		*next;
}				button_t;

typedef struct 			txt_val_s
{
	int 			display;
	char 			*str;
	sfVector2f 		pos;
	int	 		size;
	sfColor 		color;
	sfFont 			*font;
	type_txt_t 		type;
}				txt_val_t;

typedef struct 			text_s
{
	int 			display;
	sfText 			*text;
	char 			*str;
	int 			size;
	sfVector2f 		pos;
	sfVector2f 		old_pos;
	type_txt_t 		type;
	text_t 			*next;
}				text_t;

typedef struct 			scene_s
{
	object_t 		*obj;
	mob_t 			*mob;
	button_t		*btn;
	text_t			*txt;
	type_scene_t 		type;
	int 			id;
}				scene_t;

typedef struct 			window_s
{
	sfRenderWindow 		*window;
	sfEvent 		event;
}				window_t;

typedef struct 			fptr_s
{
	void 			(*fptr)(all_t *);
}				fptr_t;

typedef enum			type_wp_s
{
	THREE, ONE, UNLIMITED
}				type_wp_t;

typedef struct 			weapons_s
{
	int 			degat;
	int 			range_max;
	int 			cadence;
	type_wp_t		type;
}				wp_t;

typedef struct 			stats_s
{
	int 			agility;
	int 			hunger;
	int 			precision;
	int 			stat_precision;
	int 			fourchette_pres;
	int 			thirst;
	int 			to_share;
}				stats_t;

typedef struct 			player_s
{
	stats_t 		stat;
	int 			walking;
	int 			speed_w;
	int 			speed_w_base;
	direction_t 		direction;
	int 			collision;
	int 			angle;
	wp_t 			wp;
	int 			lvl;
	int 			xp;
	int 			health;
	int 			health_max;
	int 			food;
	int 			drink;
	int 			money;
}				player_t;

typedef struct 			info_s
{
	int			next_lvl_xp;
	float 			cst_xp;
}				info_t;

typedef struct 			tabfood_s
{
	int 			nb;
	int 			select;
} 				tabfood_t;

typedef struct 			tabweapon_s
{
	int 			draw;
	int 			select;
} 				tabweapon_t;

typedef struct 			inv_s
{
	sfSprite		*sfood;
	sfTexture		*tfood;
	sfSprite 		*swater;
	sfTexture 		*twater;
	sfSprite		*slife;
	sfTexture		*tlife;
	sfText 			*food;
	sfText 			*water;
	sfText 			*life;
	sfIntRect 		rfood;
	sfIntRect 		rwater;
	sfIntRect 		rlife;
	tabfood_t		*tabfood;
	tabweapon_t 		*tabweapon;
	int 			weapon_select;
	sfSprite		*sitem[7];
	sfTexture		*titem[7];
	sfSprite		*sweapon[11];
	sfTexture		*tweapon[11];
	sfFont*			font;
	sfText*			text[7];
	sfText*			textweapon[11];
	sfText			*textmoney;
}				inv_t;

typedef struct 			map_s
{
	int 			**map;
	int 			len_x;
	int 			len_y;
}				map_t;

typedef enum 			mob_type_s
{
	ZOMBIE
}				mob_type_t;

typedef struct 			mob_s
{
	sfSprite 		*sprite;
	sfSprite 		*bar_life;
	sfVector2f 		pos_bar_life;
	sfIntRect 		rect_bar_life;
	sfVector2f 		pos;
	sfVector2f		speed;
	sfIntRect 		rect;
	int 			offset;
	int 			size_max;
	int 			health;
	int 			health_max;
	int 			damage;
	mob_type_t		type;
	int 			id;
	mob_t 			*next;
}				mob_t;

typedef struct			shop1_s //BOISSONS
{
	sfText			*text;
	sfText			*textprice;
	char 			*name;
	int 			price;
	int 			select;
}				shop1_t;

typedef struct			shop2_s //NOURRITURES
{
	sfText			*text;
	sfText			*textprice;
	char 			*name;
	int 			price;
	int 			select;
}				shop2_t;

typedef struct			shop3_s //NOURRITURES
{
	sfText			*text;
	sfText			*textprice;
	char			*name;
	int 			price;
	int 			select;
	int 			level;
}				shop3_t;

typedef struct 			string_s
{
	sfTime 			time;
	sfClock 		*clock;
	float 			seconds;
}				string_t;

typedef struct 			all_s
{
	sfSprite		*gun_s;
	sfTexture		**gun_t;

	htp_t 			htp;
	info_t 			info;
	sfTexture 		**textures;
	int 			nb_textures;

	history_t		his;

	sfFont 			**fonts;
	int 			nb_fonts;

	sfMusic			**sounds;
	int 			nb_sounds;

	scene_t 		*scenes;
	int 			current_scene;
	int 			old_scene;
	int 			nb_scenes;

	sound_t			settings_sound;

	shot_t 			*shots;

	int 			rotation_player;

	int 			clicking;
	int 			shotted_one;
	wp_t 			*wp;
	player_t 		player;
	my_clock_t 		clock;
	window_t 		window;
	fptr_t 			*fptr;
	inv_t			inv;
	map_t 			map;
	shop1_t			*shop1;
	shop2_t			*shop2;
	shop3_t			*shop3;
	string_t		string;
	pause_t 		pause;
}				all_t;

//MAIN//
int				rand_a_b(int a, int b);
double  			frand_a_b(double a, double b);

//LIB//
char 				*my_strcpy(char *s);
char 				*get_file(int fd);
int 				my_getnbr(char *str);
void 				my_putchar(char c);
void 				my_putstr(char *str);
void 				my_putnbr(int nb);
char 				*my_strcat(char *s1, char *s2);
int 				my_strcmp(char *s1, char *s2);
int 				my_strncmp(char *s1, char *s2, int n);
int 				my_strlen(char *str);
char 				**my_str_to_wa(char *s);
char 				**my_str_to_wa_hard(char *s);
char 				**malloc_wa(char *s);
void 				my_getcharstar(int nb, char *str);

//CREATE.C//
all_t 				create_all(void);
window_t 			create_window(void);
void				create_button(all_t *all, btn_val_t bv);
void				create_text(all_t *all, txt_val_t tv);
void 	 			create_object(all_t *all, obj_val_t ov);
void				initinventory(all_t *all);
void 				initplayer(all_t *all);
void 				initweapon(all_t *all);
void 				weapon_management(all_t *all);
void				init_texture_inventory(all_t *all);
void				init_tab_food(all_t *all);
void				init_tabweapon(all_t *all);
void				initinventory2(all_t *all);
void				inittext(all_t *all);


//CORE.C//
void 				core(all_t *all);

//SCENE_CREATER/SCENE_CREATER.C//
void 				parser_scenes(char **file, int *y, all_t *all);
void 				parser(char **file, all_t *all);
void 				load_scenes(all_t *all);
char				**file_create(void);
int 				scene_counter(char **file_dd);

//LOAD_ASSETS/LOAD_TEXTURES.C//
void 				load_textures(all_t *all);
char 				*get_path(char *s);
int 				count_lines(char **ss);

//LOAD_SCENES/GET.C//
int                     	get_pos_x(char *line);
int                    		get_pos_y(char *line);
sfIntRect 			get_rect(char *line);
int                     	get_size_x(char *line);
int                     	get_size_y(char *line);
int                    		get_size_max(char *line);
int                     	get_offset(char *line);
int 				get_opacity(char *line);
int                     	get_texture_id(char *line);
int                     	get_font_id(char *line);
int 				get_despawn(char *line);
int                     	get_state(char *line);
int 				get_display(char *line);
int                     	get_func_id(char *line);
char                            *get_str(char *line);
char				*get_color(char *file);
int 				get_type(char *line);
int                     	get_size(char *line);

//GET_SF_COLOR//
sfColor 			get_sf_color(char *s);

//FUNCS/INIT.C//
fptr_t				*init_fptr(void);
fptr_t				*init_fptr1(fptr_t *f);
fptr_t				*init_fptr2(fptr_t *f);
fptr_t				*init_fptr3(fptr_t *f);
fptr_t				*init_fptr4(fptr_t *f);
fptr_t				*init_fptr5(fptr_t *f);

void 				add_agility(all_t *all);
void 				add_hunger(all_t *all);
void 				add_precision(all_t *all);
void 				add_thirst(all_t *all);
void 				inventory_use(all_t *all);
void 				inventory_button1(all_t *all);
void 				inventory_button2(all_t *all);
void 				inventory_button3(all_t *all);
void 				inventory_button4(all_t *all);
void 				inventory_button5(all_t *all);
void 				inventory_button6(all_t *all);
void 				inventory_button7(all_t *all);
void				switchitem(all_t *all, int a);
void 				weapon_button1(all_t *all);
void 				weapon_button2(all_t *all);
void 				weapon_button3(all_t *all);
void 				weapon_button4(all_t *all);
void 				weapon_button5(all_t *all);
void 				weapon_buttonselect(all_t *all);
void 				go_to_scene_0(all_t *all);
void 				go_to_scene_6(all_t *all);
void 				go_to_scene_1(all_t *all);
void 				go_to_scene_2(all_t *all);
void 				go_to_scene_3(all_t *all);
void 				go_to_scene_8(all_t *all);
void 				go_to_scene_5(all_t *all);
void 				go_to_scene_4(all_t *all);
void 				go_to_scene_7(all_t *all);
void 				go_to_scene_9(all_t *all);
void 				go_to_scene_10(all_t *all);
void 				go_to_scene_11(all_t *all);
void 				go_to_scene_12(all_t *all);
void 				go_to_scene_13(all_t *all);
void 				go_to_scene_14(all_t *all);
void 				go_to_dungeon_2(all_t *all);
void				switchitemweapon(all_t *all, int a);
void 				shop1_buy(all_t *all);
void 				shop1_close(all_t *all);
void 				shop1_button1(all_t *all);
void 				shop1_button2(all_t *all);
void 				shop1_button3(all_t *all);
void 				shop2_buy(all_t *all);
void 				shop2_button1(all_t *all);
void 				shop2_button2(all_t *all);
void 				shop2_button3(all_t *all);
void 				shop2_button4(all_t *all);
void 				shop3_buy(all_t *all);
void 				shop3_button1(all_t *all);
void 				shop3_button2(all_t *all);
void 				shop3_button3(all_t *all);
void 				shop3_button4(all_t *all);
void 				shop3_button5(all_t *all);
void 				shop3_button6(all_t *all);
void 				shop3_button7(all_t *all);
void 				shop3_button8(all_t *all);
void 				shop3_button9(all_t *all);
void 				shop3_button10(all_t *all);
void 				shop3_button11(all_t *all);

//EVENT/EVENT_MM.C/
int 				button_is_clicked(button_t *tmp, sfVector2i click_position);
void 				gestion_hover(all_t *all);

//LOAD_ASSETS/PARSER_OBJ.C//
void 				parser_obj(all_t *all, char *line);
void 				parser_btn(all_t *all, char *line);
void 				parser_txt(all_t *all, char *line);

//LOAD_ASSETS/LOAD_SOUNDS.C//
void 				load_sounds(all_t *all);

//LOAD_ASSETS/LOAD_FONTS.C//
void 				load_fonts(all_t *all);

//DISPLAY/DISPLAY.C//
void 				display_scenes(all_t *all);
void 				display_agility(all_t *all);
void 				display_thirst(all_t *all);
void 				display_precision(all_t *all);
void 				display_stats(all_t *all);
void 				display_shot(all_t *all);
void 				display_obj(all_t *all);
void 				display_btn(all_t *all);
void 				display_txt(all_t *all);
void 				display_mobs(all_t *all);
void 				display_halo(all_t *all);
void 				display_player(all_t *all);
void 				display_rain(all_t *all);
void 				display_hud(all_t *all);
void 				display_minimap(all_t *all);
void				display_string(all_t *all, char *string);

//MAP_MANAGEMENT/LOAD_MAP.C//
void 				load_map(all_t *all);
int 				get_len_y(char **map);
int 				**char_dd_to_int_dd(char **map, int len_x, int len_y);

//CREATE/INIT_LINKED_LIST.C//
text_t 				*init_list_text(void);
shot_t 				*init_shots(void);
button_t 			*init_list_btn(void);
object_t 			*init_list_object(void);
mob_t 				*init_list_mob(void);
void 				my_exit(all_t *all);

//EVENT//BUTTON_CALLBACK_MANAGEMENT.C//
void 				button_callback_management(all_t *all);

//PLAYER/PLAYER_MOVEMENT.C//
void 				player_movement(all_t *all);

//PLAYER/EXP_MANAGEMENT.C//
void 				exp_management(all_t *all);
void 				display_xp_in_bar(all_t *all);

//CLOCK/MAIN_CLOCK.C//
my_clock_t 			create_clock(void);
void				main_clock_management(all_t *all);

//PLAYER/ROTATION_PLAYER.C//
void 				animation_player(all_t *all);
void	 			rotation_player(all_t *all);

//PLAYER/INIT_PLAYER.C//
player_t 			init_player(all_t *all);
info_t 				init_info(void);

//PLAYER/DAMAGE_TAKEN.C//
void 				damage_taken(all_t *all);

//CAMERA/CAMERA_MANAGEMENT.C//
void 				camera_move_left(all_t *all);
void 				camera_move_right(all_t *all);
void 				camera_move_down(all_t *all);
void 				camera_move_up(all_t *all);

//COLLISIONS/COLLISIONS_MANAGEMENT.C//
int 				collision_left(object_t *player, all_t *all);
int 				collision_down(object_t *player, all_t *all);
int 				collision_up(object_t *player, all_t *all);
int 				collision_right(object_t *player, all_t *all);

//COLISIONS/COLISIONS_MOBS.C//
int 				collision_mobs(all_t *all, mob_t *mob);

//SHOT/SHOT_MANAGEMENT.C//
void 				fire_shot(all_t *all);
void 				shot_management(all_t *all);
void 				add_new_shot(all_t *all, sfVector2f speed);

//SHOT/SHOTS_TYPES.C//
void 				three_shot(all_t *all, sfVector2f speed);
void 				one_shot(all_t *all, sfVector2f speed);
void 				unlimited_shot(all_t *all, sfVector2f speed);

//SHOT/COLLISIONS_SHOTS.C//
void 				collision_shots(all_t *all);
int	 			delete_hitted_shots(all_t *all);
int 				delete_dead_zombies(all_t *all);

//WEAPONS/INIT_WEAPONS.C//
wp_t 				*init_wp(void);

//MAP_MANAGEMENT/READ_MAP.C//
int 				**get_map(all_t *all);

//MOBS/COLLISION_DIRECTION_MOBS.C//
int 				collision_mob_obj_up(all_t *all, mob_t *mob);
int 				collision_mobs(all_t *all, mob_t *mob);
int 				collision_mob_obj_down(all_t *all, mob_t *mob);
int 				collision_mob_obj_left(all_t *all, mob_t *mob);
int 				collision_mob_obj_right(all_t *all, mob_t *mob);
void 				animation_mob(all_t *all);

//SPAWNING/SPAWNING_MANAGEMENT.C//
void 				spawning_management(all_t *all);

//INVENTORY/INVENTORY.C//
void				displayinventory(all_t *all);
void 				displaycoins(all_t *all);
void 				displayweapon(all_t *all);
void 				displaybar(all_t *all);

//PATHFINDING/PATHFINDING.C//
void				pathfinding_mob(all_t *all);

//MOBS/CREATE_MOBS.C//
void 				create_mobs(all_t *all, int scene, int pos[2], int health);
void 				create_mobs_random(all_t *all);
int 				management_bar_life_mob(all_t *all);

//DEBUG/DISPLAY_OBSTACLES.C//
void 				display_obstacles(all_t *all);

//hud/HUD_MANAGEMENT.C//
void 				hud_management(all_t *all);

//STAT/STAT_MANAGEMENT.C//
void 				stat_management(all_t *all);

//TELEPORTATION/DISPLAY_TP_BTN.C//
void 				display_only_near_tp_btn(all_t *all);

//EFFECT_GRAPH/HALO_CENTERED_ON_PLAYER.C//
void 				halo_centered_on_player(all_t *all);
void 				do_rain(all_t *all);

//DESPAWN/DESPAWN_MANAGEMENT.C//
void 				despawn_management(all_t *all);

//MINIMAP/DISPLAY_PLAYER.C//
void 				minimap_management(all_t *all);

//MINIMAP/MINIMAP_IG.C//
void 				minimap_ig(all_t *all);

//MAP_MANAGEMENT/READ_SHOP_MAP.C//
void 				get_map_shop(all_t *all);
void 				read_map(all_t *all, char *path, int scene, int block_size);


//SEARCH_CAR/SEARCH_CAR.C//
void 				search_car(all_t *all);

//SHOP/DISPLAYSHOP//
void 				initshop(all_t *all);
void 				initshop2(all_t *all);
void 				initshop3(all_t *all);
void 				displayshop(all_t *all);
void				displayshop2(all_t *all);
void				displayshop3(all_t *all);

//ANIMATION/ANIMATION.C
void 				gestion_animation_rect(all_t *all);

//DEATH/DEATH_MANAGEMENT.C
void 				death_management(all_t *all);
void 				reset_btn_txt(all_t *all);
void 				reset_obj(all_t *all);
void 				reset_player_and_bg(all_t *all, object_t **player, object_t **bg);

//HUNGER_THIRST.C
void 				hunger_thirst(all_t *all);

void 				spawn_hospital_1(all_t *all);
void 				spawn_hospital_2(all_t *all);
void 				spawn_hospital_3(all_t *all);
int				there_is_zombie(all_t *all);
void 				display_kaz(all_t *all);
void 				kaz_management(all_t *all);
void 				reset_scene_dungeon(all_t *all, int scene);

void 				go_to_htp(all_t *all);
void 				go_to_htp2(all_t *all);
void 				quit_htp(all_t *all);
void 				go_to_htpmenu(all_t *all);
void 				go_to_htppause(all_t *all);
void 				go_to_continuepause(all_t *all);

void 				take_item_hospital(all_t *all);
void 				take_item_pharmacie(all_t *all);
void 				display_recup_obj(all_t *all);
void 				obj_recup_management(all_t *all);


//DIALOG/
void 				dialog_management(all_t *all);

//DUNGEON_2/
void 				go_to_dungeon_2(all_t *all);
void 				spawn_pharmacie_1(all_t *all);
void 				spawn_pharmacie_2(all_t *all);
void 				spawn_pharmacie_3(all_t *all);
void 				go_to_dungeon_2_2(all_t *all);
void 				go_to_dungeon_2_3(all_t *all);

//QUEST_1/
void 				quest_1_management(all_t *all);
void 				quest_1_display_string(all_t *all);

//WARNING
void 				put_one_warning_quest(all_t *all);
void 				gestion_warning_quest(all_t *all);
void 				put_one_warning_not_yet_dungeon(all_t *all);

void 				gestion_click_btn(all_t *all);
void 				set_rect_btn(all_t *all);
history_t 			create_history(void);
void 				malloc_scenes(all_t *all);
void 				put_type_on_scene(all_t *all);
void 				change_rect_and_display(all_t *all, int rect, sfSprite *loadings, sfSprite *load_bars);
void 				init_loadings(sfSprite *loadings, sfSprite *load_bars, all_t *all);
void 				reset_obj_core(all_t *all, int x, int y, object_t **obj);
void 				reset_pos_player_in_labo(all_t *all);
void 				go_to_scene_21(all_t *all);
void 				go_to_scene_23(all_t *all);

//FUNCS_SOUND
void 				sound_plus_one(all_t *all);
void 				sound_less_one(all_t *all);
sound_t 			init_sound(void);
void				go_to_old_scene(all_t *all);
void 				rect_sound_management(all_t *all);
void 				quit_scene_settings_sound(all_t *all);
void				set_volume(all_t *all);

void 				thirst_hud_management(all_t *all);
void 				hunger_hud_management(all_t *all);
void 				xp_hud_management(all_t *all);

void				search_quest_2(all_t *all);
void				quest_2_management(all_t *all);

void				core_3(all_t *all);
#endif /* !MY_H_ */