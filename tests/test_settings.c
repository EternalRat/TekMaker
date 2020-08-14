/*
** EPITECH PROJECT, 2020
** TekMaker
** File description:
** test_settings
*/

#include "parser/settings.h"
#include "test.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static Test(change_all_settings, change)
{
    settings_t config;
    int settings[3];

    settings[0] = 60;
    settings[1] = 1280;
    settings[2] = 720;
    parser_settings(&config, "config/settings");
    cr_assert_eq(config.setting[0], settings[0]);
    cr_assert_eq(config.setting[1], settings[1]);
    cr_assert_eq(config.setting[2], settings[2]);
}

static Test(error_settings, change, .init = redirect_all_std)
{
    settings_t config;

    cr_assert_eq(parser_settings(&config, "tests/error_settings"), 1);
    cr_assert_stdout_eq_str("Invalid(s) setting(s).\n");
}

static Test(error_settings2, change, .init = redirect_all_std)
{
    settings_t config;

    cr_assert_eq(parser_settings(&config, "tests/error_settings_2"), 1);
    cr_assert_stdout_eq_str("Invalid(s) setting(s).\n");
}