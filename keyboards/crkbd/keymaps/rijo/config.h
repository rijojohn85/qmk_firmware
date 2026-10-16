#pragma once

// Home-row mod tuning
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define FLOW_TAP_TERM 150

// Hold both home-row shifts (F + J) to start Caps Word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Locked NUM layer drops back to base after 60s idle
#define LAYER_LOCK_IDLE_TIMEOUT 60000

// Master -> slave sync of Caps Word / NUM-lock state for RGB indicators
#define SPLIT_TRANSACTION_IDS_USER USER_SYNC_INDICATORS
