#include "game/objects/general/gong_bonger.h"

#include "game/items.h"
#include "game/music.h"
#include "game/room.h"
#include "global/vars.h"

static void M_ActivateHeavyTriggers(int16_t item_num);

static void M_ActivateHeavyTriggers(const int16_t item_num)
{
    const ITEM *const item = Item_Get(item_num);
    Room_TestTriggers(item);
    Item_Kill(item_num);
}

void GongBonger_Setup(void)
{
    OBJECT *const obj = Object_GetObject(O_GONG_BONGER);
    obj->control = GongBonger_Control;
    obj->save_flags = 1;
    obj->save_anim = 1;
}

void __cdecl GongBonger_Control(const int16_t item_num)
{
    ITEM *const item = Item_Get(item_num);

    Item_Animate(item);
    if (item->frame_num - g_Anims[item->anim_num].frame_base == 41) {
        Music_Play(MX_REVEAL_1, MPM_ALWAYS);
        g_Camera.bounce -= 50;
    }

    if (item->frame_num == g_Anims[item->anim_num].frame_end) {
        M_ActivateHeavyTriggers(item_num);
    }
}
