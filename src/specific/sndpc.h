#ifndef T1M_SPECIFIC_SNDPC_H
#define T1M_SPECIFIC_SNDPC_H

#include <stdint.h>

#include "global/types.h"

#define SOUND_INVALID_HANDLE NULL

int32_t SoundInit();
void SoundLoadSamples(char **sample_pointers, int32_t num_samples);
SAMPLE_DATA *SoundLoadSample(char *content);
int32_t SoundMakeSample(SAMPLE_DATA *sample_data);

int32_t MusicInit();
int32_t S_MusicPlay(int16_t track);
int32_t S_MusicStop();
void S_MusicLoop();
void S_MusicVolume(int16_t volume);

void *S_SoundPlaySample(
    int32_t sample_id, uint16_t volume, uint16_t pitch, int16_t pan);
void *S_SoundPlaySampleLooped(
    int32_t sample_id, uint16_t volume, uint16_t pitch, int16_t pan);
int32_t S_SoundSampleIsPlaying(void *handle);
void S_SoundStopAllSamples();
void S_SoundStopSample(void *handle);
void S_SoundSetPanAndVolume(void *handle, int16_t pan, int16_t volume);

void T1MInjectSpecificSndPC();

#endif
