#include "game/demo.h"

#include "decomp/decomp.h"
#include "game/game.h"
#include "game/gameflow.h"
#include "game/input.h"
#include "game/items.h"
#include "game/lara/cheat.h"
#include "game/random.h"
#include "game/room.h"
#include "game/shell.h"
#include "game/text.h"
#include "global/funcs.h"
#include "global/vars.h"

static struct {
    bool bonus_flag;
} m_OldConfig;

static int32_t m_DemoLevel = 0;
static int32_t m_DemoLevel2 = 0;
static INPUT_STATE m_OldDemoInputDB = { 0 };

static void M_PrepareConfig(void);
static void M_RestoreConfig(void);

static void M_PrepareConfig(void)
{
    m_OldConfig.bonus_flag = g_SaveGame.bonus_flag;
    g_SaveGame.bonus_flag = false;
}

static void M_RestoreConfig(void)
{
    g_SaveGame.bonus_flag = m_OldConfig.bonus_flag;
}

int32_t __cdecl Demo_Control(int32_t level_num)
{
    if (level_num < 0 && !g_GameFlow.num_demos) {
        return GFD_EXIT_TO_TITLE;
    }

    if (level_num < 0) {
        if (m_DemoLevel >= g_GameFlow.num_demos) {
            m_DemoLevel = 0;
        }
        level_num = g_GF_ValidDemos[m_DemoLevel];
        m_DemoLevel++;
    } else {
        m_DemoLevel = level_num;
    }

    return GF_DoLevelSequence(level_num, GFL_DEMO);
}

int32_t __cdecl Demo_Start(int32_t level_num)
{
    if (level_num < 0 && !g_GameFlow.num_demos) {
        return GFD_EXIT_TO_TITLE;
    }

    M_PrepareConfig();

    if (level_num >= 0) {
        m_DemoLevel2 = level_num;
    } else {
        if (m_DemoLevel2 >= g_GameFlow.num_demos) {
            m_DemoLevel2 = 0;
        }
        level_num = g_GF_ValidDemos[m_DemoLevel2];
        m_DemoLevel2++;
    }

    START_INFO *const s = &g_SaveGame.start[level_num];
    START_INFO start = *s;
    s->available = 1;
    s->has_pistols = 1;
    s->pistol_ammo = 1000;
    s->gun_status = LGS_ARMLESS;
    s->gun_type = LGT_PISTOLS;
    Random_SeedDraw(0xD371F947);
    Random_SeedControl(0xD371F947);

    g_IsTitleLoaded = false;
    if (!Level_Initialise(level_num, GFL_DEMO)) {
        return GFD_EXIT_GAME;
    }

    g_LevelComplete = false;
    if (!g_IsDemoLoaded) {
        Shell_ExitSystemFmt(
            "Level '%s' has no demo data!", g_GF_LevelFileNames[level_num]);
    }

    Demo_LoadLaraPos();
    Lara_Cheat_GetStuff();
    Random_SeedDraw(0xD371F947);
    Random_SeedControl(0xD371F947);

    TEXTSTRING *const text = Text_Create(
        0, g_DumpHeight / 2 - 16, g_GF_PCStrings[GF_S_PC_DEMO_MODE]);

    Text_Flash(text, true, 20);
    Text_CentreV(text, true);
    Text_CentreH(text, true);

    m_OldDemoInputDB = (INPUT_STATE) { 0 };
    g_Inv_DemoMode = true;
    GAME_FLOW_DIR dir = Game_Loop(true);
    g_Inv_DemoMode = false;

    Text_Remove(text);

    M_RestoreConfig();

    *s = start;
    S_FadeToBlack();
    if (dir == GFD_OVERRIDE) {
        dir = g_GF_OverrideDir;
        g_GF_OverrideDir = (GAME_FLOW_DIR)-1;
    }
    return dir;
}

void __cdecl Demo_LoadLaraPos(void)
{
    g_LaraItem->pos.x = g_DemoPtr[0];
    g_LaraItem->pos.y = g_DemoPtr[1];
    g_LaraItem->pos.z = g_DemoPtr[2];
    g_LaraItem->rot.x = g_DemoPtr[3];
    g_LaraItem->rot.y = g_DemoPtr[4];
    g_LaraItem->rot.z = g_DemoPtr[5];
    int16_t room_num = g_DemoPtr[6];
    if (g_LaraItem->room_num != room_num) {
        Item_NewRoom(g_Lara.item_num, room_num);
    }

    const SECTOR *const sector = Room_GetSector(
        g_LaraItem->pos.x, g_LaraItem->pos.y, g_LaraItem->pos.z, &room_num);
    g_LaraItem->floor = Room_GetHeight(
        sector, g_LaraItem->pos.x, g_LaraItem->pos.y, g_LaraItem->pos.z);
    g_Lara.last_gun_type = g_DemoPtr[7];

    g_DemoCount += 8;
}

bool __cdecl Demo_GetInput(void)
{
    if (g_DemoCount >= MAX_DEMO_SIZE) {
        return false;
    }

    union {
        uint32_t any;
        struct {
            // clang-format off
            uint32_t forward:      1;
            uint32_t back:         1;
            uint32_t left:         1;
            uint32_t right:        1;
            uint32_t jump:         1;
            uint32_t draw:         1;
            uint32_t action:       1;
            uint32_t slow:         1;
            uint32_t option:       1;
            uint32_t look:         1;
            uint32_t step_left:    1;
            uint32_t step_right:   1;
            uint32_t roll:         1;
            uint32_t _pad:         6;
            uint32_t use_flare:    1;
            uint32_t menu_confirm: 1;
            uint32_t menu_back:    1;
            uint32_t save:         1;
            uint32_t load:         1;
            // clang-format on
        };
    } demo_input = { .any = g_DemoPtr[g_DemoCount] };

    if ((int32_t)demo_input.any == -1) {
        return false;
    }

    g_Input = (INPUT_STATE) {
        0,
        // clang-format off
        .forward      = demo_input.forward,
        .back         = demo_input.back,
        .left         = demo_input.left,
        .right        = demo_input.right,
        .jump         = demo_input.jump,
        .draw         = demo_input.draw,
        .action       = demo_input.action,
        .slow         = demo_input.slow,
        .option       = demo_input.option,
        .look         = demo_input.look,
        .step_left    = demo_input.step_left,
        .step_right   = demo_input.step_right,
        .roll         = demo_input.roll,
        .use_flare        = demo_input.use_flare,
        .menu_confirm = demo_input.menu_confirm,
        .menu_back    = demo_input.menu_back,
        .save         = demo_input.save,
        .load         = demo_input.load,
        // clang-format on
    };

    g_InputDB.any = g_Input.any & ~m_OldDemoInputDB.any;
    m_OldDemoInputDB = g_Input;
    g_DemoCount++;
    return true;
}
