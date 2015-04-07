
#ifndef PARSE_H
#define PARSE_H

struct screen_info_s;
struct console_info_s;
struct entity_s;
struct lua_State;

#define CVAR_NAME_SIZE 32
#define CVAR_LUA_TABLE_NAME "cvars"

#include "bullet/LinearMath/btScalar.h"

extern lua_State *engine_lua;

char *parse_token(char *data, char *token);

float SC_ParseFloat(char **ch);
int   SC_ParseInt(char **ch);

int lua_ParseScreen(lua_State *lua, struct screen_info_s *sc);
int lua_ParseRender(lua_State *lua, struct render_settings_s *rs);
int lua_ParseAudio(lua_State *lua, struct audio_settings_s *as);
int lua_ParseConsole(lua_State *lua, struct console_info_s *cn);
int lua_ParseControls(lua_State *lua, struct control_settings_s *cs);

bool lua_GetOverridedSamplesInfo(lua_State *lua, int *num_samples, int *num_sounds, char *sample_name_mask);
bool lua_GetOverridedSample(lua_State *lua, int sound_id, int *first_sample_number, int *samples_count);

int  lua_GetGlobalSound(lua_State *lua, int global_sound_id);
int  lua_GetSecretTrackNumber(lua_State *lua);
int  lua_GetNumTracks(lua_State *lua);
bool lua_GetSoundtrack(lua_State *lua, int track_index, char *track_path, int *load_method, int *stream_type);
bool lua_GetLoadingScreen(lua_State *lua, int level_index, char *pic_path);
const char* lua_GetString(lua_State *lua, int string_index, size_t *string_length = NULL);

btScalar lua_GetScalarField(lua_State *lua, const char *key);
int lua_SetScalarField(lua_State *lua, const char *key, btScalar val);
const char *lua_GetStrField(lua_State *lua, const char *key);
int lua_SetStrField(lua_State *lua, const char *key, const char *val);

int lua_ActivateEntity(lua_State *lua, int id_object, int id_activator, int id_callback);
int lua_DoTasks(lua_State *lua, btScalar time);

#endif