#include "game/inventory/inventory_ring.h"

#include "config.h"
#include "game/game_string.h"
#include "game/inventory.h"
#include "game/inventory/inventory_vars.h"
#include "game/option/option_examine.h"
#include "game/output.h"
#include "game/overlay.h"
#include "game/text.h"
#include "global/const.h"
#include "global/types.h"
#include "global/vars.h"
#include "math/math_misc.h"

#include <libtrx/game/objects/names.h>

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

TEXTSTRING *g_InvItemText[IT_NUMBER_OF] = { NULL };
TEXTSTRING *g_InvRingText = NULL;

static TEXTSTRING *m_InvDownArrow1 = NULL;
static TEXTSTRING *m_InvDownArrow2 = NULL;
static TEXTSTRING *m_InvUpArrow1 = NULL;
static TEXTSTRING *m_InvUpArrow2 = NULL;
static TEXTSTRING *m_ExamineItemText = NULL;
static TEXTSTRING *m_UseItemText = NULL;

static GAME_OBJECT_ID m_RequestedObjectID = NO_OBJECT;

static TEXTSTRING *M_InitExamineText(
    int32_t x_pos, const char *role_str, const char *input_str);
static void M_HandleRequestedObject(RING_INFO *ring);

static TEXTSTRING *M_InitExamineText(
    const int32_t x_pos, const char *const role_str,
    const char *const input_str)
{
    char role[100];
    sprintf(role, role_str, input_str);

    TEXTSTRING *const text = Text_Create(x_pos, -100, role);
    Text_AlignBottom(text, true);
    Text_CentreH(text, true);
    Text_Hide(text, true);

    return text;
}

static void M_HandleRequestedObject(RING_INFO *const ring)
{
    if (m_RequestedObjectID == NO_OBJECT) {
        return;
    }

    for (int32_t i = 0; i < ring->number_of_objects; i++) {
        const GAME_OBJECT_ID item_id = ring->list[i]->object_id;
        if (item_id == m_RequestedObjectID && Inv_RequestItem(item_id) > 0) {
            ring->current_object = i;
            break;
        }
    }

    m_RequestedObjectID = NO_OBJECT;
}

void Inv_Ring_SetRequestedObjectID(const GAME_OBJECT_ID object_id)
{
    m_RequestedObjectID = object_id;
}

void Inv_Ring_Init(
    RING_INFO *ring, int16_t type, INVENTORY_ITEM **list, int16_t qty,
    int16_t current, IMOTION_INFO *imo)
{
    ring->type = type;
    ring->radius = 0;
    ring->list = list;
    ring->number_of_objects = qty;
    ring->current_object = current;
    ring->angle_adder = 0x10000 / qty;

    M_HandleRequestedObject(ring);

    if (g_InvMode == INV_TITLE_MODE) {
        ring->camera_pitch = 1024;
    } else {
        ring->camera_pitch = 0;
    }
    ring->rotating = 0;
    ring->rot_count = 0;
    ring->target_object = 0;
    ring->rot_adder = 0;
    ring->rot_adder_l = 0;
    ring->rot_adder_r = 0;

    ring->imo = imo;

    ring->camera.pos.x = 0;
    ring->camera.pos.y = CAMERA_STARTHEIGHT;
    ring->camera.pos.z = 896;
    ring->camera.rot.x = 0;
    ring->camera.rot.y = 0;
    ring->camera.rot.z = 0;

    Inv_Ring_MotionInit(ring, OPEN_FRAMES, RNG_OPENING, RNG_OPEN);
    Inv_Ring_MotionRadius(ring, RING_RADIUS);
    Inv_Ring_MotionCameraPos(ring, CAMERA_HEIGHT);
    Inv_Ring_MotionRotation(
        ring, OPEN_ROTATION,
        0xC000 - (ring->current_object * ring->angle_adder));

    ring->ringpos.pos.x = 0;
    ring->ringpos.pos.y = 0;
    ring->ringpos.pos.z = 0;
    ring->ringpos.rot.x = 0;
    ring->ringpos.rot.y = imo->rotate_target - OPEN_ROTATION;
    ring->ringpos.rot.z = 0;

    ring->light.x = -1536;
    ring->light.y = 256;
    ring->light.z = 1024;
}

bool Inv_Ring_CanExamine(void)
{
    return g_Config.enable_item_examining && m_ExamineItemText != NULL
        && !m_ExamineItemText->flags.hide;
}

void Inv_Ring_InitExamineOverlay(void)
{
    if ((g_InvMode != INV_GAME_MODE && g_InvMode != INV_KEYS_MODE)
        || !g_Config.enable_item_examining || m_ExamineItemText != NULL) {
        return;
    }

    m_ExamineItemText =
        M_InitExamineText(-100, GS(ITEM_EXAMINE_ROLE), GS(KEYMAP_LOOK));
    m_UseItemText =
        M_InitExamineText(100, GS(ITEM_USE_ROLE), GS(KEYMAP_ACTION));
}

void Inv_Ring_RemoveExamineOverlay(void)
{
    if (m_ExamineItemText == NULL) {
        return;
    }

    Text_Remove(m_ExamineItemText);
    Text_Remove(m_UseItemText);
    m_ExamineItemText = NULL;
    m_UseItemText = NULL;
}

void Inv_Ring_InitHeader(RING_INFO *ring)
{
    if (g_InvMode == INV_TITLE_MODE) {
        return;
    }

    if (!g_InvRingText) {
        switch (ring->type) {
        case RT_MAIN:
            g_InvRingText = Text_Create(0, 26, GS(HEADING_INVENTORY));
            break;

        case RT_OPTION:
            if (g_InvMode == INV_DEATH_MODE) {
                g_InvRingText = Text_Create(0, 26, GS(HEADING_GAME_OVER));
            } else {
                g_InvRingText = Text_Create(0, 26, GS(HEADING_OPTION));
            }
            break;

        case RT_KEYS:
            g_InvRingText = Text_Create(0, 26, GS(HEADING_ITEMS));
            break;
        }

        Text_CentreH(g_InvRingText, 1);
    }

    if (g_InvMode != INV_GAME_MODE) {
        return;
    }

    if (!m_InvUpArrow1) {
        if (ring->type == RT_OPTION
            || (ring->type == RT_MAIN && g_InvKeysObjects)) {
            m_InvUpArrow1 = Text_Create(20, 28, "\\{arrow up}");
            m_InvUpArrow2 = Text_Create(-20, 28, "\\{arrow up}");
            Text_AlignRight(m_InvUpArrow2, 1);
        }
    }

    if (!m_InvDownArrow1) {
        if (ring->type == RT_MAIN || ring->type == RT_KEYS) {
            m_InvDownArrow1 = Text_Create(20, -15, "\\{arrow down}");
            m_InvDownArrow2 = Text_Create(-20, -15, "\\{arrow down}");
            Text_AlignBottom(m_InvDownArrow1, 1);
            Text_AlignBottom(m_InvDownArrow2, 1);
            Text_AlignRight(m_InvDownArrow2, 1);
        }
    }
}

void Inv_Ring_RemoveHeader(void)
{
    if (!g_InvRingText) {
        return;
    }

    Text_Remove(g_InvRingText);
    g_InvRingText = NULL;

    if (m_InvUpArrow1) {
        Text_Remove(m_InvUpArrow1);
        Text_Remove(m_InvUpArrow2);
        m_InvUpArrow1 = NULL;
        m_InvUpArrow2 = NULL;
    }
    if (m_InvDownArrow1) {
        Text_Remove(m_InvDownArrow1);
        Text_Remove(m_InvDownArrow2);
        m_InvDownArrow1 = NULL;
        m_InvDownArrow2 = NULL;
    }
}

void Inv_Ring_RemoveAllText(void)
{
    Inv_Ring_RemoveHeader();
    Inv_Ring_RemoveExamineOverlay();
    for (int i = 0; i < IT_NUMBER_OF; i++) {
        if (g_InvItemText[i]) {
            Text_Remove(g_InvItemText[i]);
            g_InvItemText[i] = NULL;
        }
    }
}

void Inv_Ring_Active(INVENTORY_ITEM *inv_item)
{
    if (g_InvItemText[IT_NAME] == NULL
        && inv_item->object_id != O_PASSPORT_OPTION) {
        g_InvItemText[IT_NAME] =
            Text_Create(0, -16, Object_GetName(inv_item->object_id));
        Text_AlignBottom(g_InvItemText[IT_NAME], 1);
        Text_CentreH(g_InvItemText[IT_NAME], 1);
    }

    char temp_text[128];
    int32_t qty = Inv_RequestItem(inv_item->object_id);

    bool show_examine_option = false;

    switch (inv_item->object_id) {
    case O_SHOTGUN_OPTION:
        if (!g_InvItemText[IT_QTY] && !(g_GameInfo.bonus_flag & GBF_NGPLUS)) {
            sprintf(
                temp_text, "%5d A", g_Lara.shotgun.ammo / SHOTGUN_AMMO_CLIP);
            Overlay_MakeAmmoString(temp_text);
            g_InvItemText[IT_QTY] = Text_Create(64, -56, temp_text);
            Text_AlignBottom(g_InvItemText[IT_QTY], 1);
            Text_CentreH(g_InvItemText[IT_QTY], 1);
        }
        break;

    case O_MAGNUM_OPTION:
        if (!g_InvItemText[IT_QTY] && !(g_GameInfo.bonus_flag & GBF_NGPLUS)) {
            sprintf(temp_text, "%5d B", g_Lara.magnums.ammo);
            Overlay_MakeAmmoString(temp_text);
            g_InvItemText[IT_QTY] = Text_Create(64, -56, temp_text);
            Text_AlignBottom(g_InvItemText[IT_QTY], 1);
            Text_CentreH(g_InvItemText[IT_QTY], 1);
        }
        break;

    case O_UZI_OPTION:
        if (!g_InvItemText[IT_QTY] && !(g_GameInfo.bonus_flag & GBF_NGPLUS)) {
            sprintf(temp_text, "%5d C", g_Lara.uzis.ammo);
            Overlay_MakeAmmoString(temp_text);
            g_InvItemText[IT_QTY] = Text_Create(64, -56, temp_text);
            Text_AlignBottom(g_InvItemText[IT_QTY], 1);
            Text_CentreH(g_InvItemText[IT_QTY], 1);
        }
        break;

    case O_SG_AMMO_OPTION:
        if (!g_InvItemText[IT_QTY]) {
            sprintf(temp_text, "%d", qty * NUM_SG_SHELLS);
            Overlay_MakeAmmoString(temp_text);
            g_InvItemText[IT_QTY] = Text_Create(64, -56, temp_text);
            Text_AlignBottom(g_InvItemText[IT_QTY], 1);
            Text_CentreH(g_InvItemText[IT_QTY], 1);
        }
        break;

    case O_MAG_AMMO_OPTION:
        if (!g_InvItemText[IT_QTY]) {
            sprintf(temp_text, "%d", Inv_RequestItem(O_MAG_AMMO_OPTION) * 2);
            Overlay_MakeAmmoString(temp_text);
            g_InvItemText[IT_QTY] = Text_Create(64, -56, temp_text);
            Text_AlignBottom(g_InvItemText[IT_QTY], 1);
            Text_CentreH(g_InvItemText[IT_QTY], 1);
        }
        break;

    case O_UZI_AMMO_OPTION:
        if (!g_InvItemText[IT_QTY]) {
            sprintf(temp_text, "%d", Inv_RequestItem(O_UZI_AMMO_OPTION) * 2);
            Overlay_MakeAmmoString(temp_text);
            g_InvItemText[IT_QTY] = Text_Create(64, -56, temp_text);
            Text_AlignBottom(g_InvItemText[IT_QTY], 1);
            Text_CentreH(g_InvItemText[IT_QTY], 1);
        }
        break;

    case O_MEDI_OPTION:
        Overlay_BarSetHealthTimer(40);
        if (!g_InvItemText[IT_QTY] && qty > 1) {
            sprintf(temp_text, "%d", qty);
            Overlay_MakeAmmoString(temp_text);
            g_InvItemText[IT_QTY] = Text_Create(64, -56, temp_text);
            Text_AlignBottom(g_InvItemText[IT_QTY], 1);
            Text_CentreH(g_InvItemText[IT_QTY], 1);
        }
        break;

    case O_BIGMEDI_OPTION:
        Overlay_BarSetHealthTimer(40);
        if (!g_InvItemText[IT_QTY] && qty > 1) {
            sprintf(temp_text, "%d", qty);
            Overlay_MakeAmmoString(temp_text);
            g_InvItemText[IT_QTY] = Text_Create(64, -56, temp_text);
            Text_AlignBottom(g_InvItemText[IT_QTY], 1);
            Text_CentreH(g_InvItemText[IT_QTY], 1);
        }
        break;

    case O_KEY_OPTION_1:
    case O_KEY_OPTION_2:
    case O_KEY_OPTION_3:
    case O_KEY_OPTION_4:
    case O_LEADBAR_OPTION:
    case O_PICKUP_OPTION_1:
    case O_PICKUP_OPTION_2:
    case O_PUZZLE_OPTION_1:
    case O_PUZZLE_OPTION_2:
    case O_PUZZLE_OPTION_3:
    case O_PUZZLE_OPTION_4:
    case O_SCION_OPTION:
        if (!g_InvItemText[IT_QTY] && qty > 1) {
            sprintf(temp_text, "%d", qty);
            Overlay_MakeAmmoString(temp_text);
            g_InvItemText[IT_QTY] = Text_Create(64, -56, temp_text);
            Text_AlignBottom(g_InvItemText[IT_QTY], 1);
            Text_CentreH(g_InvItemText[IT_QTY], 1);
        }

        show_examine_option = !Option_Examine_IsActive()
            && Option_Examine_CanExamine(inv_item->object_id);
        break;

    default:
        break;
    }

    if (inv_item->object_id == O_MEDI_OPTION
        || inv_item->object_id == O_BIGMEDI_OPTION) {
        if (g_Config.healthbar_location == BL_TOP_LEFT) {
            Text_Hide(m_InvUpArrow1, true);
        } else if (g_Config.healthbar_location == BL_TOP_RIGHT) {
            Text_Hide(m_InvUpArrow2, true);
        } else if (g_Config.healthbar_location == BL_BOTTOM_LEFT) {
            Text_Hide(m_InvDownArrow1, true);
        } else if (g_Config.healthbar_location == BL_BOTTOM_RIGHT) {
            Text_Hide(m_InvDownArrow2, true);
        }
        g_GameInfo.inv_showing_medpack = true;
    } else {
        Text_Hide(m_InvUpArrow1, false);
        Text_Hide(m_InvUpArrow2, false);
        Text_Hide(m_InvDownArrow1, false);
        Text_Hide(m_InvDownArrow2, false);
        g_GameInfo.inv_showing_medpack = false;
    }

    if (m_ExamineItemText != NULL) {
        Text_Hide(m_ExamineItemText, !show_examine_option);
        Text_Hide(m_UseItemText, !show_examine_option);
    }
}

void Inv_Ring_ResetItem(INVENTORY_ITEM *const inv_item)
{
    inv_item->drawn_meshes = inv_item->which_meshes;
    inv_item->current_frame = 0;
    inv_item->goal_frame = inv_item->current_frame;
    inv_item->pt_xrot = 0;
    inv_item->x_rot = 0;
    inv_item->y_rot = 0;
    inv_item->ytrans = 0;
    inv_item->ztrans = 0;
    inv_item->action = ACTION_USE;
    if (inv_item->object_id == O_PASSPORT_OPTION) {
        inv_item->object_id = O_PASSPORT_CLOSED;
    }
}

void Inv_Ring_GetView(RING_INFO *ring, XYZ_32 *view_pos, XYZ_16 *view_rot)
{
    PHD_ANGLE angles[2];

    Math_GetVectorAngles(
        -ring->camera.pos.x, CAMERA_YOFFSET - ring->camera.pos.y,
        ring->radius - ring->camera.pos.z, angles);
    view_pos->x = ring->camera.pos.x;
    view_pos->y = ring->camera.pos.y;
    view_pos->z = ring->camera.pos.z;
    view_rot->x = angles[1] + ring->camera_pitch;
    view_rot->y = angles[0];
    view_rot->z = 0;
}

void Inv_Ring_Light(RING_INFO *ring)
{
    PHD_ANGLE angles[2];
    g_LsDivider = 0x6000;
    Math_GetVectorAngles(ring->light.x, ring->light.y, ring->light.z, angles);
    Output_RotateLight(angles[1], angles[0]);
}

void Inv_Ring_CalcAdders(RING_INFO *ring, int16_t rotation_duration)
{
    ring->angle_adder = 0x10000 / ring->number_of_objects;
    ring->rot_adder_l = ring->angle_adder / rotation_duration;
    ring->rot_adder_r = -ring->rot_adder_l;
}

void Inv_Ring_DoMotions(RING_INFO *ring)
{
    IMOTION_INFO *imo = ring->imo;

    if (imo->count) {
        ring->radius += imo->radius_rate;
        ring->camera.pos.y += imo->camera_yrate;
        ring->ringpos.rot.y += imo->rotate_rate;
        ring->camera_pitch += imo->camera_pitch_rate;

        INVENTORY_ITEM *inv_item = ring->list[ring->current_object];
        inv_item->pt_xrot += imo->item_ptxrot_rate;
        inv_item->x_rot += imo->item_xrot_rate;
        inv_item->ytrans += imo->item_ytrans_rate;
        inv_item->ztrans += imo->item_ztrans_rate;

        imo->count--;
        if (!imo->count) {
            imo->status = imo->status_target;
            if (imo->radius_rate) {
                imo->radius_rate = 0;
                ring->radius = imo->radius_target;
            }
            if (imo->camera_yrate) {
                imo->camera_yrate = 0;
                ring->camera.pos.y = imo->camera_ytarget;
            }
            if (imo->rotate_rate) {
                imo->rotate_rate = 0;
                ring->ringpos.rot.y = imo->rotate_target;
            }
            if (imo->item_ptxrot_rate) {
                imo->item_ptxrot_rate = 0;
                inv_item->pt_xrot = imo->item_ptxrot_target;
            }
            if (imo->item_xrot_rate) {
                imo->item_xrot_rate = 0;
                inv_item->x_rot = imo->item_xrot_target;
            }
            if (imo->item_ytrans_rate) {
                imo->item_ytrans_rate = 0;
                inv_item->ytrans = imo->item_ytrans_target;
            }
            if (imo->item_ztrans_rate) {
                imo->item_ztrans_rate = 0;
                inv_item->ztrans = imo->item_ztrans_target;
            }
            if (imo->camera_pitch_rate) {
                imo->camera_pitch_rate = 0;
                ring->camera_pitch = imo->camera_pitch_target;
            }
        }
    }

    if (ring->rotating) {
        ring->ringpos.rot.y += ring->rot_adder;
        ring->rot_count--;
        if (!ring->rot_count) {
            ring->current_object = ring->target_object;
            ring->ringpos.rot.y =
                0xC000 - (ring->current_object * ring->angle_adder);
            ring->rotating = 0;
        }
    }
}

void Inv_Ring_RotateLeft(RING_INFO *ring)
{
    ring->rotating = 1;
    ring->target_object = ring->current_object - 1;
    if (ring->target_object < 0) {
        ring->target_object = ring->number_of_objects - 1;
    }
    ring->rot_count = ROTATE_DURATION;
    ring->rot_adder = ring->rot_adder_l;
}

void Inv_Ring_RotateRight(RING_INFO *ring)
{
    ring->rotating = 1;
    ring->target_object = ring->current_object + 1;
    if (ring->target_object >= ring->number_of_objects) {
        ring->target_object = 0;
    }
    ring->rot_count = ROTATE_DURATION;
    ring->rot_adder = ring->rot_adder_r;
}

void Inv_Ring_MotionInit(
    RING_INFO *ring, int16_t frames, int16_t status, int16_t status_target)
{
    ring->imo->status_target = status_target;
    ring->imo->count = frames;
    ring->imo->status = status;
    ring->imo->radius_target = 0;
    ring->imo->radius_rate = 0;
    ring->imo->camera_ytarget = 0;
    ring->imo->camera_yrate = 0;
    ring->imo->camera_pitch_target = 0;
    ring->imo->camera_pitch_rate = 0;
    ring->imo->rotate_target = 0;
    ring->imo->rotate_rate = 0;
    ring->imo->item_ptxrot_target = 0;
    ring->imo->item_ptxrot_rate = 0;
    ring->imo->item_xrot_target = 0;
    ring->imo->item_xrot_rate = 0;
    ring->imo->item_ytrans_target = 0;
    ring->imo->item_ytrans_rate = 0;
    ring->imo->item_ztrans_target = 0;
    ring->imo->item_ztrans_rate = 0;
    ring->imo->misc = 0;
}

void Inv_Ring_MotionSetup(
    RING_INFO *ring, int16_t status, int16_t status_target, int16_t frames)
{
    IMOTION_INFO *imo = ring->imo;
    imo->count = frames;
    imo->status = status;
    imo->status_target = status_target;
    imo->radius_rate = 0;
    imo->camera_yrate = 0;
}

void Inv_Ring_MotionRadius(RING_INFO *ring, int16_t target)
{
    IMOTION_INFO *imo = ring->imo;
    imo->radius_target = target;
    imo->radius_rate = (target - ring->radius) / imo->count;
}

void Inv_Ring_MotionRotation(RING_INFO *ring, int16_t rotation, int16_t target)
{
    IMOTION_INFO *imo = ring->imo;
    imo->rotate_target = target;
    imo->rotate_rate = rotation / imo->count;
}

void Inv_Ring_MotionCameraPos(RING_INFO *ring, int16_t target)
{
    IMOTION_INFO *imo = ring->imo;
    imo->camera_ytarget = target;
    imo->camera_yrate = (target - ring->camera.pos.y) / imo->count;
}

void Inv_Ring_MotionCameraPitch(RING_INFO *ring, int16_t target)
{
    IMOTION_INFO *imo = ring->imo;
    imo->camera_pitch_target = target;
    imo->camera_pitch_rate = target / imo->count;
}

void Inv_Ring_MotionItemSelect(RING_INFO *ring, INVENTORY_ITEM *inv_item)
{
    IMOTION_INFO *imo = ring->imo;
    imo->item_ptxrot_target = inv_item->pt_xrot_sel;
    imo->item_ptxrot_rate = inv_item->pt_xrot_sel / imo->count;
    imo->item_xrot_target = inv_item->x_rot_sel;
    imo->item_xrot_rate = inv_item->x_rot_sel / imo->count;
    imo->item_ytrans_target = inv_item->ytrans_sel;
    imo->item_ytrans_rate = inv_item->ytrans_sel / imo->count;
    imo->item_ztrans_target = inv_item->ztrans_sel;
    imo->item_ztrans_rate = inv_item->ztrans_sel / imo->count;
}

void Inv_Ring_MotionItemDeselect(RING_INFO *ring, INVENTORY_ITEM *inv_item)
{
    IMOTION_INFO *imo = ring->imo;
    imo->item_ptxrot_target = 0;
    imo->item_ptxrot_rate = -inv_item->pt_xrot_sel / imo->count;
    imo->item_xrot_target = 0;
    imo->item_xrot_rate = -inv_item->x_rot_sel / imo->count;
    imo->item_ytrans_target = 0;
    imo->item_ytrans_rate = -inv_item->ytrans_sel / imo->count;
    imo->item_ztrans_target = 0;
    imo->item_ztrans_rate = -inv_item->ztrans_sel / imo->count;
}
