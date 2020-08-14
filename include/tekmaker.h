/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** tekmaker.h
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Config.h>
#include <SFML/Window.h>
#include "map.h"
#include "parser/settings.h"
#include "parser/key.h"
#include "button.h"
#include "list_map.h"
#include "editor.h"
#include "player.h"
#include "game.h"
#include "menu.h"
#include "enemy.h"

#ifndef _TEKMAKER_H_
#define _TEKMAKER_H_

#define MENU 0
#define EDITOR 1
#define CREATE_LIST 2
#define LIST_MAP 3
#define EDITOR_MENU 4
#define EDIT_MAP 5
#define EDITOR_PAUSE 6
#define GAME 7
#define GAME_PAUSE 8
#define TEXTURE_PERSO "res/player.png"
#define FONT "./res/textures/SuperMario256.ttf"

typedef struct windows_s windows_t;
struct windows_s
{
    settings_t settings;
    sfRenderWindow *window;
    sfEvent event;
    sfVideoMode mode;
};

typedef struct selected_block_s selected_block_t;
struct selected_block_s {
    sfTexture *selected_block_texture;
    sfSprite *selected_block_sprite;
    char selected_block_id;
};

typedef struct text_area_s text_area_t;
struct text_area_s {
    char *s;
    sfText *text;
    char *test;
    int keycode[27];
    sfFont *font;
};

typedef struct tekmaker_s tekmaker_t;
struct tekmaker_s
{
    windows_t windows;
    key_config_t key;
    menu_t menu;
    menu_t editor_menu;
    menu_t editor_menu_pause;
    menu_t game_pause;
    game_t game;
    files_t files;
    editor_t editor;
    map_t map;
    selected_block_t selected_block;
    text_area_t text_area;
    int states;
    int old_states;
};

void map_editor(tekmaker_t *tek);
void list_map(tekmaker_t *tek);
void event_key(tekmaker_t *tek);
void create_sprites(tekmaker_t *tekmaker);
void create_list(tekmaker_t *tek);
void parser_texture(char *file, tekmaker_t *tekmaker);
void move_background(background_t *background, int state, float value);
void check_if_destructible(map_e_t *block);
int check_collision_with_hurting_block(tekmaker_t *tek, int value,
sfVector2f player_pos);
void destroy_all_fireball(fireball_t *fireball);
int count_fireball(fireball_t *fireball);
void menu_mort(tekmaker_t *tek);
void menu_win(tekmaker_t *tek);
int count_array(char **array);
void display_fireball(power_up_t *power, windows_t windows, tekmaker_t *tek);
void shooting_fire(tekmaker_t *tek);
void move_enemy(tekmaker_t *tek, int value);
void check_bonus(tekmaker_t *tek);
void menu_start(tekmaker_t *tek);
int check_collision_with_hurting_blocks(tekmaker_t *tek,
sfVector2f player_pos);
int check_pos(sfVector2i m_pos, tekmaker_t *tek);
sfRenderWindow *create_windows(sfVideoMode mode);
void display_enemy(tekmaker_t *tek, int value);
int is_on_a_block(map_e_t *map, sfVector2f enemy_pos);
int count_enemy(enemy_t *enemy);
void check_for_bonus(tekmaker_t *tek, map_e_t *block);
void destroy_all_mob(enemy_t *enemy);
void destroy_one_mob(enemy_t *mob);
int is_enemy_visible(enemy_t *tmp, settings_t setting);
void init_tek(tekmaker_t *tek, char *file);
void loop(tekmaker_t *tek);
void pause_menu(tekmaker_t *tek);
void evt_pause_menu(tekmaker_t *tek);
void go_to_edit_map(tekmaker_t *tek);
int check_if_a_block_is_hit_up(tekmaker_t *tek);
int check_if_a_block_is_hit_down(tekmaker_t *tek);
int check_collision_jump_down(tekmaker_t *tek);
int check_collision_jump_up(tekmaker_t *tek);
void animation_enemy(enemy_t **tmp, map_e_t *map, int gravity, int move);
void go_to_editor(tekmaker_t *tek);
void go_to_editor_menu(tekmaker_t *tek);
void exit_game(tekmaker_t *tek);
void go_back(tekmaker_t *tek);
void go_to_list(tekmaker_t *tek);
void move_block_selection_right(tekmaker_t *tek);
int count_block(map_e_t *map);
void destroy_map_block(map_e_t *map);
void move_block_selection_left(tekmaker_t *tek);
void jump(tekmaker_t *tek);
void event_handler(tekmaker_t *tek);
void select_map_to_edit(tekmaker_t *tek);
void map_display(map_e_t *maps, windows_t window, int state);
int check_if_a_block_is_hit_down_enemy(enemy_t *tmp, map_e_t *map_e);
void move_to_left(tekmaker_t *tek);
int is_on_a_block(map_e_t *map, sfVector2f enemy_pos);
int check_collision_enemy(map_e_t *map, int value, sfVector2f enemy_pos);
void check_if_dead(tekmaker_t *tek, map_e_t *block);
map_e_t *remove_block(tekmaker_t *tek, sfVector2i m_pos);
void move_to_right(tekmaker_t *tek);
void move_to_up(tekmaker_t *tek);
void move_to_down(tekmaker_t *tek);
void display_list(files_t file, windows_t windows);
void map_editor_menu(tekmaker_t *tek);
int check_collision_with_ennemy(tekmaker_t *tek, sfVector2f player_pos);
void parser(tekmaker_t *tek, char *files);
void event_mouse(tekmaker_t *tek);
int place_block(tekmaker_t *tek, sfVector2i m_pos);
int check_collision_with_end(tekmaker_t *tek, int value, sfVector2f player_pos);
void init_player(player_t *player, game_settings_t game_settings);
void destroy_all(tekmaker_t *tek);
void fill_list(int *ind, sfVector2f *pos);
void event_image(list_files_t *files, sfRenderWindow *window);
void create_selected_block(selected_block_t *selected_block,
sfTexture *texture, char id);
int count_image_list(image_t * image);
void choose_states(tekmaker_t *tek);
int create_blocks(tekmaker_t *tek);
void play_game(tekmaker_t *tek);
void move_cam(int state, void *params, int value_x, int value_y);
void init_game(tekmaker_t *tek);
void jump_player(tekmaker_t *tek);
void edt_pause_back(tekmaker_t *tek);
int check_map(char *map);
void move_player_left(tekmaker_t *tek);
void move_player_right(tekmaker_t *tek);
void edt_pause_save_map(tekmaker_t *tek);
void edt_pause_quit_menu(tekmaker_t *tek);
void event_editor_pause(tekmaker_t *tek);
void editor_pause(tekmaker_t *tek);
void editor_pause_loop(tekmaker_t *tek);
int check_if_good_block_is_hit_down(tekmaker_t *tek, char c);
map_e_t *selected_a_block_to_move(map_e_t *map, sfVector2i m_pos,
selected_block_t *block, tekmaker_t *tek);

#endif