#pragma once

#include "global/types.h"

void BridgeTilt2_Setup(void);

void __cdecl BridgeTilt2_Floor(
    const ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *out_height);

void __cdecl BridgeTilt2_Ceiling(
    const ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *out_height);
