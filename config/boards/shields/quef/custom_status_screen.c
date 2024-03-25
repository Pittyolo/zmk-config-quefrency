/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include "custom_status_screen.h"
#include "widgets/peripheral_battery_status.h"
#include "widgets/modifiers.h"
#include "widgets/bongo_cat.h"


#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

/*static struct zmk_widget_peripheral_battery_status peripheral_battery_status_widget;
*static struct zmk_widget_modifiers modifiers_widget;
*static struct zmk_widget_bongo_cat bongo_cat_widget;
*/

#if IS_ENABLED(CONFIG_CUSTOM_WIDGET_PERIPHERAL_BATTERY_STATUS)
static struct zmk_widget_peripheral_battery_status peripheral_battery_status_widget;
#endif

#if IS_ENABLED(CONFIG_CUSTOM_WIDGET_MODIFIERS)
static struct zmk_widget_modifiers modifiers_widget;
#endif

#if IS_ENABLED(CONFIG_CUSTOM_WIDGET_BONGO_CAT)
static struct zmk_widget_bongo_cat bongo_cat_widget;
#endif

lv_style_t global_style;

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;

    screen = lv_obj_create(NULL);
//CONFIG_ZMK_SPLIT_ROLE_CENTRAL
    lv_style_init(&global_style);
    lv_style_set_text_font(&global_style, &lv_font_unscii_8);
    lv_style_set_text_letter_space(&global_style, 1);
    lv_style_set_text_line_space(&global_style, 1);
    lv_obj_add_style(screen, &global_style, LV_PART_MAIN);

#if IS_ENABLED(CONFIG_CUSTOM_WIDGET_PERIPHERAL_BATTERY_STATUS)
    zmk_widget_peripheral_battery_status_init(&peripheral_battery_status_widget, screen);
    lv_obj_align(zmk_widget_peripheral_battery_status_obj(&peripheral_battery_status_widget), LV_ALIGN_BOTTOM_RIGHT, 0, 0);
#endif

#if IS_ENABLED(CONFIG_CUSTOM_WIDGET_BONGO_CAT)
    zmk_widget_bongo_cat_init(&bongo_cat_widget, screen);
    lv_obj_align(zmk_widget_bongo_cat_obj(&bongo_cat_widget), LV_ALIGN_BOTTOM_RIGHT, 0, -7);
#endif

#if IS_ENABLED(CONFIG_CUSTOM_WIDGET_MODIFIERS)
    zmk_widget_modifiers_init(&modifiers_widget, screen);
    lv_obj_align(zmk_widget_modifiers_obj(&modifiers_widget), LV_ALIGN_BOTTOM_LEFT, 0, 0);
#endif

    return screen;
}