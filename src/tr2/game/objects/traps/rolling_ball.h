#pragma once

#include "global/types.h"

void __cdecl RollingBall_Initialise(int16_t item_num);
void __cdecl RollingBall_Control(int16_t item_num);
void __cdecl RollingBall_Collision(
    int16_t item_num, ITEM *lara_item, COLL_INFO *coll);
