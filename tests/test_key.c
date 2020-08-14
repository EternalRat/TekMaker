/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** test_key
*/

#include "parser/key.h"
#include "test.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static Test(change_all_key, change)
{
    key_config_t config;
    int key[6];

    config.key[5] = 0;
    key[5] = 0;
    key[JUMP] = 57;
    key[LEFT] = 17;
    key[RIGHT] = 4;
    key[DOWN] = 19;
    key[FIRE] = 5;
    parser_key(&config, "config/key");
    cr_assert_eq(config.key[0], key[0]);
    cr_assert_eq(config.key[1], key[1]);
    cr_assert_eq(config.key[2], key[2]);
    cr_assert_eq(config.key[3], key[3]);
    cr_assert_eq(config.key[4], key[4]);
    cr_assert_eq(config.key[5], key[5]);
}

static Test(error, change, .init = redirect_all_std)
{
    key_config_t config;

    config.key[5] = 0;
    cr_assert_eq(parser_key(&config, "tests/error"), 1);
    cr_assert_stdout_eq_str("Invalid(s) key(s).\n");
}