#ifndef EXTERNS_H
#define EXTERNS_H

#include <libspectrum.h>
#include <stdint.h>

#include <libretro.h>
#include <settings.h>
#include <input.h>

// These defines shouldn't be here...
#define MAX_WIDTH  320
#define MAX_HEIGHT 240
#define MAX_PADS   7

// From the core
extern retro_environment_t env_cb;
extern retro_log_printf_t log_cb;
extern retro_audio_sample_batch_t audio_cb;
extern retro_input_state_t input_state_cb;
extern struct retro_perf_callback perf_cb;
extern uint16_t image_buffer[MAX_WIDTH * MAX_HEIGHT];
extern unsigned hard_width, hard_height;
extern int show_frame, some_audio;
extern retro_log_printf_t log_cb;
extern int64_t keyb_send;
extern int64_t keyb_hold_time;
extern input_event_t keyb_event;
extern int select_pressed;
extern int keyb_overlay;
extern unsigned keyb_x;
extern unsigned keyb_y;
extern int input_state[MAX_PADS][5];
extern void* snapshot_buffer;
extern size_t snapshot_size;
void update_variables(void);

// From Fuse
extern settings_info settings_current;
int fuse_init(int argc, char** argv);
int fuse_end(void);
int tape_is_playing(void);
void z80_do_opcodes(void);
int event_do_events(void);
int fuse_emulation_pause(void);
int fuse_emulation_unpause(void);
int snapshot_write(const char* filename);
int snapshot_read_buffer(const unsigned char* buffer, size_t length, libspectrum_id_t type);

#endif /* EXTERNS_H */