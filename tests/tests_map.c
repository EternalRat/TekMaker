/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** test.c
*/

#include <criterion/criterion.h>
#include "map.h"

Test(map_get_char , classic)
{
    map_t map;
    map.map = "1234512345\¬";
    map.width = 5;
    char c = map_get_char(map, 0, 0);
    cr_assert_eq(c, '1');
}

Test(map_get_char , classic2)
{
    map_t map;
    map.map = "12345\n12345";
    map.width = 5;
    map.height = 5;
    char c = map_get_char(map, 0, 1);
    cr_assert_eq(c, '1');
}

Test(map_set_char , classic2)
{
    map_t map;
    map.map = strdup("12345\n12345");
    map.width = 5;
    map.height = 5;
    map_set_char(map, 0, 0, '2');
    cr_assert_eq(map.map[0], '2');
}

Test(map_create , classic2)
{
    map_t map;
    settings_t settings;

    map.map = NULL;
    map.height = 0;
    map.width = 0;
    map_load("tests/map_test", settings, &map);
    cr_assert_str_eq(map.map, "12345\n12345");
}