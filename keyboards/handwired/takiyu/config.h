#pragma once

// Connect USB to right side
#define MASTER_RIGHT

// Make it easier for fast typists to use dual-function keys
#define PERMISSIVE_HOLD

// Disable mechanical locking support
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// Limit layer up to 8
#define LAYER_STATE_8BIT

// Mouse
#define MOUSEKEY_INTERVAL    20
#define MOUSEKEY_DELAY       0
#define MOUSEKEY_TIME_TO_MAX 30
#define MOUSEKEY_MAX_SPEED   7
#define MOUSEKEY_WHEEL_DELAY 0

// Auto Shift
#define AUTO_SHIFT_TIMEOUT 200
#define NO_AUTO_SHIFT_ALPHA
#define NO_AUTO_SHIFT_SPECIAL
