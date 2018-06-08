##
## EPITECH PROJECT, 2018
##
## File description:
## Makefile
##

CC		=	gcc -g

CFLAGS		=	-I./include -Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized

LDFLAGS 	= 	-lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio -lm

LDFLAGS2	=	-lc_graph_prog

RM		=	rm -rf

SRC		=	main.c							\
			sources/quest/quest_2.c					\
			sources/create/create_struct_sound.c			\
			sources/sound/rect_sound.c 				\
			sources/funcs/funcs_sounds.c				\
			sources/warning/warning.c 				\
			sources/quest/quest_1.c 				\
			sources/dialog/dialog_management.c 			\
			sources/dungeon/go_back_city.c				\
			sources/dungeon/dungeon_reset.c 			\
			sources/dungeon/dungeon_1/spawn_dungeon1.c 		\
			sources/dungeon/dungeon_2/spawn_dungeon2.c 		\
			sources/dungeon/dungeon_mechanics.c 			\
			sources/dungeon/dungeon_1/go_to_scene_dungeon1.c	\
			sources/dungeon/dungeon_2/go_to_scene_dungeon2.c	\
			sources/mobs/animation_mob.c 				\
			sources/hunger_thirst/hunger_thirst.c 			\
			sources/death/death_management.c 			\
			sources/death/death_management_2.c 			\
			sources/animation/animation.c 				\
			sources/effect_graph/do_rain.c 				\
			sources/search_car/search_car.c 			\
			sources/map_management/read_shop_map.c 			\
			sources/minimap/minimap_ig.c 				\
			sources/minimap/display_player.c 			\
			sources/despawn/despawn_management.c 			\
			sources/spawning/spawning_management.c 			\
			sources/effect_graph/halo_centered_on_player.c 		\
			sources/teleportation/display_tp_btn.c 			\
			sources/stats/stat_management.c 			\
			sources/hud/hud_management.c 				\
			sources/hud/hud_management_2.c 				\
			sources/mobs/create_mobs.c 				\
			sources/mobs/create_mobs_2.c 				\
			sources/mobs/gestion_mobs.c 				\
			sources/mobs/collision_direction_mob.c 			\
			sources/shot/shot_management.c 				\
			sources/shot/shots_types.c 				\
			sources/collision/collision_management.c 		\
			sources/collision/collision_shots.c 			\
			sources/collision/collision_shots2.c 			\
			sources/camera/camera_right.c	 			\
			sources/camera/camera_left.c	 			\
			sources/camera/camera_up.c	 			\
			sources/camera/camera_down.c	 			\
			sources/clock/main_clock.c 				\
			sources/player/player_movement.c 			\
			sources/player/rotation_player.c 			\
			sources/player/animation.c 				\
			sources/player/init_player.c 				\
			sources/player/exp_management.c 			\
			sources/player/display_xp_in_bar.c 			\
			sources/player/damage_taken.c 				\
			sources/event/button_callback_management.c 		\
			sources/create/create_struct.c  			\
			sources/create/create_obj.c  				\
			sources/create/create_btn.c  				\
			sources/create/create_history.c				\
			sources/create/create_struct2.c  			\
			sources/create/init_inventory.c				\
			sources/create/create_structweapon.c  			\
			sources/create/loading.c 				\
			sources/create/init_linked_list.c 			\
			sources/core/hover_management.c 			\
			sources/core/core.c 					\
			sources/core/core_2.c 					\
			sources/lib/my_strcpy.c 				\
			sources/lib/get_file.c 					\
			sources/lib/my_getnbr.c					\
			sources/lib/my_put.c 					\
			sources/lib/my_str_to_wa.c 				\
			sources/lib/my_strcat.c 				\
			sources/lib/my_strcmp.c 				\
			sources/lib/my_strlen.c 				\
			sources/lib/my_getcharstar.c 				\
			sources/weapons/init_weapons.c 				\
			sources/load_scenes/scene_creater.c 			\
			sources/load_assets/load_textures.c 			\
			sources/load_assets/load_sounds.c 			\
			sources/load_assets/load_fonts.c 			\
			sources/load_scenes/get_size.c 				\
			sources/load_scenes/get_rect.c 				\
			sources/load_scenes/get_pos.c 				\
			sources/load_scenes/get_offset.c			\
			sources/load_scenes/get_id.c				\
			sources/load_scenes/get_state.c				\
			sources/load_scenes/get_str.c				\
			sources/load_scenes/get_color_type.c			\
			sources/load_scenes/get_sf_color.c			\
			sources/load_scenes/get_despawn.c 			\
			sources/load_scenes/parser_obj.c 			\
			sources/display/display.c 				\
			sources/display/display2.c 				\
			sources/display/display3.c 				\
			sources/display/display_minimap.c			\
			sources/display/display_stats.c 			\
			sources/display/display_stats2.c			\
			sources/funcs/init.c 					\
			sources/funcs/init2.c					\
			sources/funcs/go_to_scenes_1.c				\
			sources/funcs/go_to_scenes_2.c				\
			sources/funcs/go_to_scenes_3.c				\
			sources/funcs/take_item.c				\
			sources/funcs/funcs_carac.c 				\
			sources/inventory/inventory.c 				\
			sources/map_management/read_map.c 			\
			sources/debug/display_obstacles.c 			\
			sources/funcs/funcs_inventory.c				\
			sources/funcs/funcs_inventory2.c			\
			sources/funcs/funcs_in_weapon.c				\
			sources/funcs/funcs_in_weapon2.c			\
			sources/inventory/inventory2.c 				\
			sources/shop/initshop.c 				\
			sources/shop/initshop2.c 				\
			sources/shop/initshop3.c 				\
			sources/shop/displayshop.c 				\
			sources/funcs/func_shop1.c 				\
			sources/funcs/func_shop2.c 				\
			sources/funcs/func_shop3.c 				\
			sources/funcs/func_shop4.c 				\
			sources/funcs/func_shop5.c 				\
			sources/funcs/funcs_htp.c 				\
			sources/funcs/funcs_menu.c 				\
			sources/funcs/funcs_pause.c 				\
			sources/display/display_string.c 			\

OBJS		=	$(SRC:.c=.o)

NAME		=	my_rpg

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CLFAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
