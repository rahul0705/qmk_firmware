#pragma once
#include "quantum.h"
#include "process_records.h"
#include "custom_keycodes.h"
#include "custom_tap_dance.h"

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

enum unicode_name {
    THINK, // thinking face 🤔
    GRIN, // grinning face 😊
    SMRK, // smirk 😏
    WEARY, // good shit 😩
    UNAMU, // unamused 😒

    SNEK, // snke 🐍
    PENGUIN, // 🐧
    DRAGON, // 🐉
    MONKEY, // 🐒
    CHICK, // 🐥
    BOAR, // 🐗

    OKOK, // 👌
    EFFU, // 🖕
    INUP, // 👆
    THUP, // 👍
    THDN, // 👎

    BBB, // dat B 🅱
    POO, // poop 💩
    HUNDR, // 100 💯
    EGGPL, // EGGPLANT 🍆
    WATER, // wet 💦
    TUMBLER, // 🥃

    LIT, // fire 🔥
    BANG, // ‽
    IRONY, // ⸮
    DEGREE // °
};
