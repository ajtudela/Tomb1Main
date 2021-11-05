#include "specific/music.h"

#include "config.h"
#include "game/sound.h"
#include "global/vars.h"
#include "global/vars_platform.h"
#include "log.h"

static int32_t MusicNumTracks = 0;
static int16_t MusicTrackLooped = 0;

int32_t S_Music_Init()
{
    MCI_OPEN_PARMS open_parms;
    open_parms.dwCallback = 0;
    open_parms.wDeviceID = 0;
    open_parms.lpstrDeviceType = (LPSTR)MCI_DEVTYPE_CD_AUDIO;
    open_parms.lpstrElementName = NULL;
    open_parms.lpstrAlias = NULL;

    MCIERROR result = mciSendCommandA(
        0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID, (DWORD_PTR)&open_parms);
    if (result) {
        LOG_ERROR("cannot initailize music device: %x", result);
        return 0;
    }
    MCIDeviceID = open_parms.wDeviceID;

    AuxDeviceID = 0;
    for (int i = 0; i < auxGetNumDevs(); i++) {
        AUXCAPSA caps;
        auxGetDevCapsA((UINT_PTR)i, &caps, sizeof(AUXCAPSA));
        if (caps.wTechnology == AUXCAPS_CDAUDIO) {
            AuxDeviceID = i;
        }
    }

    MCI_STATUS_PARMS status_parms;
    status_parms.dwItem = MCI_STATUS_NUMBER_OF_TRACKS;
    mciSendCommandA(
        MCIDeviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD_PTR)&status_parms);
    MusicNumTracks = status_parms.dwReturn;
    return 1;
}

void S_Music_AdjustVolume(int16_t volume)
{
    int32_t volume_aux = volume * 0xFFFF / 0xFF;
    volume_aux |= volume_aux << 16;
    auxSetVolume(AuxDeviceID, volume_aux);
}

void S_Music_Pause()
{
    MCIERROR result;
    MCI_GENERIC_PARMS pause_parms;

    result = mciSendCommandA(
        MCIDeviceID, MCI_PAUSE, MCI_WAIT, (DWORD_PTR)&pause_parms);
    if (result) {
        LOG_ERROR("Error while calling mciSendCommandA: 0x%lx", result);
    }
}

void S_Music_Unpause()
{
    MCIERROR result;
    MCI_GENERIC_PARMS pause_parms;

    result = mciSendCommandA(
        MCIDeviceID, MCI_RESUME, MCI_WAIT, (DWORD_PTR)&pause_parms);
    if (result) {
        LOG_ERROR("Error while calling mciSendCommandA: 0x%lx", result);
    }
}

int32_t S_Music_PlayImpl(int16_t track)
{
    if (CurrentLevel == GF.title_level_num && T1MConfig.disable_music_in_menu) {
        return 0;
    }

    if (track < 2) {
        return 0;
    }

    if (track >= 57) {
        MusicTrackLooped = track;
    }

    MusicLoop = false;

    uint32_t volume = T1MConfig.music_volume * 0xFFFF / 10;
    volume |= volume << 16;
    auxSetVolume(AuxDeviceID, volume);

    MCI_SET_PARMS set_parms;
    set_parms.dwTimeFormat = MCI_FORMAT_TMSF;
    if (mciSendCommandA(
            MCIDeviceID, MCI_SET, MCI_SET_TIME_FORMAT, (DWORD_PTR)&set_parms)) {
        return 0;
    }

    MCI_PLAY_PARMS open_parms;
    open_parms.dwFrom = track;
    open_parms.dwCallback = (DWORD_PTR)TombHWND;

    DWORD_PTR dwFlags = MCI_NOTIFY | MCI_FROM;
    if (track != MusicNumTracks) {
        open_parms.dwTo = track + 1;
        dwFlags |= MCI_TO;
    }

    if (mciSendCommandA(
            MCIDeviceID, MCI_PLAY, dwFlags, (DWORD_PTR)&open_parms)) {
        return 0;
    }

    return 1;
}

void S_Music_PlayLooped()
{
    if (MusicLoop && MusicTrackLooped > 0) {
        S_Music_PlayImpl(MusicTrackLooped);
    }
}

int32_t S_Music_Play(int16_t track_id)
{
    if (T1MConfig.fix_secrets_killing_music && track_id == 13) {
        Sound_Effect(SFX_SECRET, NULL, SPM_ALWAYS);
        return 1;
    }

    if (track_id == 0) {
        S_Music_Stop();
        return 0;
    }

    if (track_id == 5) {
        return 0;
    }

    MusicTrack = track_id;
    return S_Music_PlayImpl(track_id);
}

int32_t S_Music_Stop()
{
    MusicTrack = 0;
    MusicTrackLooped = 0;
    MusicLoop = false;

    MCI_GENERIC_PARMS gen_parms;
    return !mciSendCommandA(
        MCIDeviceID, MCI_STOP, MCI_WAIT, (DWORD_PTR)&gen_parms);
}

void S_Music_Loop()
{
    MusicLoop = true;
}