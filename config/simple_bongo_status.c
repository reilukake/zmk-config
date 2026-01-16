/*
 * Copyright (c) 2024 The ZMK Contributors
 * Simple Stable OLED Display for Sofle SSD1306 - No White Noise Edition
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/display/cfb.h>

#include <zmk/display.h>
#include <zmk/event_manager.h>
#include <zmk/events/layer_state_changed.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/events/ble_active_profile_changed.h>
#include <zmk/keymap.h>
#include <zmk/battery.h>
#include <zmk/ble.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static uint8_t current_layer = 0;
static uint8_t battery_level = 100;
static uint8_t bt_profile = 0;
static bool bt_connected = false;

// Simple bongo cat faces - no complex animations
static const char* cat_faces[] = {
    "(o.o)",  // Default
    "(^.^)",  // Layer 1
    "(@.@)",  // Layer 2  
    "(~.~)"   // Layer 3+
};

// Simple layer names
static const char* layer_names[] = {
    "QWERTY",
    "LOWER", 
    "RAISE",
    "EXTRA"
};

void zmk_display_status_screen_update_cb(const struct device *dev) {
    if (dev == NULL) {
        return;
    }

    // Clear display
    cfb_framebuffer_clear(dev, false);

    // === SIMPLE LAYOUT FOR 128x32 SSD1306 ===
    
    // Line 1: Bongo cat face + Layer name
    char line1[32];
    const char* cat_face = current_layer < 4 ? cat_faces[current_layer] : cat_faces[0];
    const char* layer_name = current_layer < 4 ? layer_names[current_layer] : "CUSTOM";
    snprintf(line1, sizeof(line1), "%s [%s]", cat_face, layer_name);
    cfb_draw_text(dev, line1, 0, 0);
    
    // Line 2: Battery level
    char line2[32];
    snprintf(line2, sizeof(line2), "BAT: %d%%", battery_level);
    cfb_draw_text(dev, line2, 0, 8);
    
    // Line 3: Bluetooth status
    char line3[32];
    if (bt_connected) {
        snprintf(line3, sizeof(line3), "BT:%d Connected", bt_profile);
    } else {
        snprintf(line3, sizeof(line3), "BT:%d Disconnected", bt_profile);
    }
    cfb_draw_text(dev, line3, 0, 16);
    
    // Line 4: Simple status
    char line4[32];
    if (current_layer == 0) {
        snprintf(line4, sizeof(line4), "Ready to type!");
    } else if (current_layer == 1) {
        snprintf(line4, sizeof(line4), "Numbers & Symbols");
    } else if (current_layer == 2) {
        snprintf(line4, sizeof(line4), "Navigation & RGB");
    } else {
        snprintf(line4, sizeof(line4), "Layer %d", current_layer);
    }
    cfb_draw_text(dev, line4, 0, 24);

    cfb_framebuffer_finalize(dev);
}

static int status_screen_listener(const zmk_event_t *eh) {
    if (as_zmk_layer_state_changed(eh)) {
        current_layer = zmk_keymap_highest_layer_active();
        return ZMK_EV_EVENT_BUBBLE;
    }
    
    if (as_zmk_battery_state_changed(eh)) {
        battery_level = zmk_battery_state_of_charge();
        return ZMK_EV_EVENT_BUBBLE;
    }
    
    if (as_zmk_ble_active_profile_changed(eh)) {
        bt_profile = zmk_ble_active_profile_index();
        bt_connected = zmk_ble_active_profile_is_connected();
        return ZMK_EV_EVENT_BUBBLE;
    }
    
    return ZMK_EV_EVENT_BUBBLE;
}

static int simple_bongo_init(void) {
    // Initialize state
    current_layer = zmk_keymap_highest_layer_active();
    battery_level = zmk_battery_state_of_charge();
    bt_profile = zmk_ble_active_profile_index();
    bt_connected = zmk_ble_active_profile_is_connected();
    
    return 0;
}

ZMK_LISTENER(bongo_status_screen, status_screen_listener);
ZMK_SUBSCRIPTION(bongo_status_screen, zmk_layer_state_changed);
ZMK_SUBSCRIPTION(bongo_status_screen, zmk_battery_state_changed);
ZMK_SUBSCRIPTION(bongo_status_screen, zmk_ble_active_profile_changed);

SYS_INIT(simple_bongo_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);