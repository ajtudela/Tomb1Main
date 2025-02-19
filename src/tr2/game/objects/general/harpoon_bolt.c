#include "game/objects/general/harpoon_bolt.h"

#include "decomp/effects.h"
#include "game/gun/gun_misc.h"
#include "game/items.h"
#include "game/math.h"
#include "game/objects/general/window.h"
#include "game/room.h"
#include "global/funcs.h"
#include "global/vars.h"

void HarpoonBolt_Setup(void)
{
    OBJECT *const obj = Object_GetObject(O_HARPOON_BOLT);
    obj->control = HarpoonBolt_Control;
    obj->save_position = 1;
}

void __cdecl HarpoonBolt_Control(const int16_t item_num)
{
    ITEM *const item = Item_Get(item_num);

    if (!(Room_Get(item->room_num)->flags & RF_UNDERWATER)) {
        item->fall_speed += GRAVITY / 2;
    }

    const XZ_32 old_pos = {
        .x = item->pos.x,
        .z = item->pos.z,
    };

    item->pos.x += (item->speed * Math_Sin(item->rot.y)) >> W2V_SHIFT;
    item->pos.z += (item->speed * Math_Cos(item->rot.y)) >> W2V_SHIFT;
    item->pos.y += item->fall_speed;

    int16_t room_num = item->room_num;
    const SECTOR *const sector =
        Room_GetSector(item->pos.x, item->pos.y, item->pos.z, &room_num);
    item->floor = Room_GetHeight(sector, item->pos.x, item->pos.y, item->pos.z);
    if (item->room_num != room_num) {
        Item_NewRoom(item_num, room_num);
    }

    for (int16_t target_num = Room_Get(item->room_num)->item_num;
         target_num != NO_ITEM; target_num = Item_Get(target_num)->next_item) {
        ITEM *const target_item = Item_Get(target_num);
        const OBJECT *const target_obj =
            Object_GetObject(target_item->object_id);

        if (target_item == g_LaraItem) {
            continue;
        }

        if (!target_item->collidable) {
            continue;
        }

        if (target_item->object_id != O_WINDOW_1
            && (target_item->status == IS_INVISIBLE
                || target_obj->collision == NULL)) {
            continue;
        }

        const FRAME_INFO *const frame = Item_GetBestFrame(target_item);
        const BOUNDS_16 *const bounds = &frame->bounds;

        const int32_t cdy = item->pos.y - target_item->pos.y;
        if (cdy < bounds->min_y || cdy > bounds->max_y) {
            continue;
        }

        const int32_t cy = Math_Cos(target_item->rot.y);
        const int32_t sy = Math_Sin(target_item->rot.y);
        const int32_t cdx = item->pos.x - target_item->pos.x;
        const int32_t cdz = item->pos.z - target_item->pos.z;
        const int32_t odx = old_pos.x - target_item->pos.x;
        const int32_t odz = old_pos.z - target_item->pos.z;

        const int32_t rx = (cy * cdx - sy * cdz) >> W2V_SHIFT;
        const int32_t sx = (cy * odx - sy * odz) >> W2V_SHIFT;
        if ((rx < bounds->min_x && sx < bounds->min_x)
            || (rx > bounds->max_x && sx > bounds->max_x)) {
            continue;
        }

        const int32_t rz = (sy * cdx + cy * cdz) >> W2V_SHIFT;
        const int32_t sz = (sy * odx + cy * odz) >> W2V_SHIFT;
        if ((rz < bounds->min_z && sz < bounds->min_z)
            || (rz > bounds->max_z && sz > bounds->max_z)) {
            continue;
        }

        if (target_item->object_id == O_WINDOW_1) {
            Window_Smash(target_num);
        } else {
            if (target_obj->intelligent && target_item->status == IS_ACTIVE) {
                DoLotsOfBlood(
                    item->pos.x, item->pos.y, item->pos.z, 0, 0, item->room_num,
                    5);
                Gun_HitTarget(target_item, NULL, g_Weapons[LGT_HARPOON].damage);
                g_SaveGame.statistics.hits++;
            }
            Item_Kill(item_num);
            return;
        }
    }

    const int32_t ceiling =
        Room_GetCeiling(sector, item->pos.x, item->pos.y, item->pos.z);
    if (item->pos.y >= item->floor || item->pos.y <= ceiling) {
        Item_Kill(item_num);
    } else if (Room_Get(item->room_num)->flags & RF_UNDERWATER) {
        CreateBubble(&item->pos, item->room_num);
    }
}
