// LH mods
#define HM_C LSFT_T(KC_C)
#define HM_S RCTL_T(KC_S)
#define HM_N LALT_T(KC_N)
#define HM_T LGUI_T(KC_T)

#define HM_F RALT_T(KC_F)

// RH mods
#define HM_A RGUI_T(KC_A)
#define HM_E LALT_T(KC_E)
#define HM_I RCTL_T(KC_I)
#define HM_H RSFT_T(KC_H)

#define HM_DOT RALT_T(KC_DOT)

#define HM_DOWN RGUI_T(KC_DOWN)
#define HM_UP LALT_T(KC_UP)
#define HM_RIGHT RCTL_T(KC_RIGHT)

// Layers
#define LT_R   LT(1,KC_R)
#define LT_ESC LT(2,KC_ESC)
#define LT_TAB LT(3,KC_TAB)
#define LT_SPC LT(4,KC_SPC)
#define LT_BSPC LT(5,KC_BSPC)

// MacOS
#define MC_CPY LGUI(KC_C)
#define MC_PST LGUI(KC_V)
#define MC_CUT LGUI(KC_X)

// vi
#define VI_JMP LCTL(KC_CIRC)
#define VI_IN  LCTL(KC_I)
#define VI_OUT LCTL(KC_O)
#define VI_DOWN LCTL(KC_D)
#define VI_UP   LCTL(KC_U)
#define VI_HOME KC_CIRC
#define VI_END  KC_DLR

// dk
// TODO: figure out what to do for other operating systems than macOS...
#define DK_OE RALT(KC_O)
#define DK_AA RALT(KC_A)
#define DK_AE RALT(KC_QUOT)

// meta keys
#define GUIC LGUI(KC_C)
#define GUIS LGUI(KC_S)
#define GUIN LGUI(KC_N)
#define GUIT LGUI(KC_T)
#define GUIF LGUI(KC_F)

#define GUIV LGUI(KC_V)
#define GUIW LGUI(KC_W)
#define GUIM LGUI(KC_M)
#define GUIG LGUI(KC_G)
#define GUIZ LGUI(KC_Z)
#define GUIQ LGUI(KC_Q)
#define GUIB LGUI(KC_B)
#define GUIP LGUI(KC_P)
#define GUIL LGUI(KC_L)
#define GUID LGUI(KC_D)
#define GUIJ LGUI(KC_J)

#define HM_GUIC LSFT_T(GUIC)
#define HM_GUIS LALT_T(GUIS)
#define HM_GUIN LALT_T(GUIN)
#define HM_GUIT LGUI_T(GUIT)
#define HM_GUIF RALT_T(GUIF)
