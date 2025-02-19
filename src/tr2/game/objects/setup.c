#include "game/objects/setup.h"

#include "game/lara/control.h"
#include "game/objects/common.h"
#include "game/objects/creatures/bandit.h"
#include "game/objects/creatures/barracuda.h"
#include "game/objects/creatures/bartoli.h"
#include "game/objects/creatures/big_eel.h"
#include "game/objects/creatures/big_spider.h"
#include "game/objects/creatures/bird.h"
#include "game/objects/creatures/cultist.h"
#include "game/objects/creatures/diver.h"
#include "game/objects/creatures/dog.h"
#include "game/objects/creatures/dragon.h"
#include "game/objects/creatures/eel.h"
#include "game/objects/creatures/giant_yeti.h"
#include "game/objects/creatures/jelly.h"
#include "game/objects/creatures/monk.h"
#include "game/objects/creatures/mouse.h"
#include "game/objects/creatures/shark.h"
#include "game/objects/creatures/skidoo_driver.h"
#include "game/objects/creatures/spider.h"
#include "game/objects/creatures/tiger.h"
#include "game/objects/creatures/trex.h"
#include "game/objects/creatures/winston.h"
#include "game/objects/creatures/worker.h"
#include "game/objects/creatures/xian_knight.h"
#include "game/objects/creatures/xian_spearman.h"
#include "game/objects/creatures/yeti.h"
#include "game/objects/effects/blood.h"
#include "game/objects/effects/body_part.h"
#include "game/objects/effects/bubble.h"
#include "game/objects/effects/explosion.h"
#include "game/objects/effects/glow.h"
#include "game/objects/effects/gun_flash.h"
#include "game/objects/effects/missile_flame.h"
#include "game/objects/effects/missile_harpoon.h"
#include "game/objects/effects/missile_knife.h"
#include "game/objects/effects/ricochet.h"
#include "game/objects/effects/snow_sprite.h"
#include "game/objects/effects/splash.h"
#include "game/objects/effects/twinkle.h"
#include "game/objects/effects/water_sprite.h"
#include "game/objects/effects/waterfall.h"
#include "game/objects/general/alarm_sound.h"
#include "game/objects/general/bell.h"
#include "game/objects/general/big_bowl.h"
#include "game/objects/general/bird_tweeter.h"
#include "game/objects/general/bridge_flat.h"
#include "game/objects/general/bridge_tilt_1.h"
#include "game/objects/general/bridge_tilt_2.h"
#include "game/objects/general/camera_target.h"
#include "game/objects/general/clock_chimes.h"
#include "game/objects/general/cutscene_player.h"
#include "game/objects/general/detonator.h"
#include "game/objects/general/ding_dong.h"
#include "game/objects/general/door.h"
#include "game/objects/general/drawbridge.h"
#include "game/objects/general/earthquake.h"
#include "game/objects/general/final_cutscene.h"
#include "game/objects/general/final_level_counter.h"
#include "game/objects/general/flare_item.h"
#include "game/objects/general/gong_bonger.h"
#include "game/objects/general/grenade.h"
#include "game/objects/general/harpoon_bolt.h"
#include "game/objects/general/hot_liquid.h"
#include "game/objects/general/keyhole.h"
#include "game/objects/general/lara_alarm.h"
#include "game/objects/general/lift.h"
#include "game/objects/general/pickup.h"
#include "game/objects/general/puzzle_hole.h"
#include "game/objects/general/secret.h"
#include "game/objects/general/sphere_of_doom.h"
#include "game/objects/general/switch.h"
#include "game/objects/general/trapdoor.h"
#include "game/objects/general/window.h"
#include "game/objects/vehicles/boat.h"
#include "game/objects/vehicles/skidoo_armed.h"
#include "game/objects/vehicles/skidoo_fast.h"
#include "global/funcs.h"
#include "global/types.h"
#include "global/vars.h"

#define DEFAULT_RADIUS 10

static void M_SetupLara(void);
static void M_SetupLaraExtra(void);

static void M_SetupLara(void)
{
    OBJECT *const obj = &g_Objects[O_LARA];
    obj->initialise = Lara_InitialiseLoad;

    obj->shadow_size = (UNIT_SHADOW / 16) * 10;
    obj->hit_points = LARA_MAX_HITPOINTS;
    obj->draw_routine = Object_DrawDummyItem;

    obj->save_position = 1;
    obj->save_hitpoints = 1;
    obj->save_flags = 1;
    obj->save_anim = 1;
}

static void M_SetupLaraExtra(void)
{
    OBJECT *const obj = &g_Objects[O_LARA_EXTRA];
    obj->control = Lara_ControlExtra;
}

void __cdecl Object_SetupBaddyObjects(void)
{
    M_SetupLara();
    M_SetupLaraExtra();

    Dog_Setup();
    Mouse_Setup();
    Cultist1_Setup();
    Cultist1A_Setup();
    Cultist1B_Setup();
    Cultist2_Setup();
    Cultist3_Setup();
    Shark_Setup();
    Tiger_Setup();
    Barracuda_Setup();
    Spider_Setup();
    BigSpider_Setup();
    Yeti_Setup();
    Jelly_Setup();
    Diver_Setup();
    Worker1_Setup();
    Worker2_Setup();
    Worker3_Setup();
    Worker4_Setup();
    Worker5_Setup();
    Monk1_Setup();
    Monk2_Setup();
    Bird_SetupEagle();
    Bird_SetupCrow();
    SkidooDriver_Setup();
    Bartoli_Setup();
    Dragon_SetupFront();
    Dragon_SetupBack();
    Bandit1_Setup();
    Bandit2_Setup();
    Bandit2B_Setup();
    BigEel_Setup();
    Eel_Setup();
    XianKnight_Setup();
    XianSpearman_Setup();
    GiantYeti_Setup();
    TRex_Setup();
    Winston_Setup();
}

void __cdecl Object_SetupGeneralObjects(void)
{
    Boat_Setup();
    SkidooArmed_Setup();
    SkidooFast_Setup();

    // misc interactive objects
    Bell_Setup();
    BigBowl_Setup();
    Detonator1_Setup();
    Detonator2_Setup();
    FlareItem_Setup();
    Lift_Setup();

    // misc non-interactive objects
    AlarmSound_Setup();
    BirdTweeter_Setup(Object_GetObject(O_BIRD_TWEETER_1));
    BirdTweeter_Setup(Object_GetObject(O_BIRD_TWEETER_2));
    CameraTarget_Setup();
    ClockChimes_Setup();
    DingDong_Setup();
    Earthquake_Setup();
    FinalCutscene_Setup();
    FinalLevelCounter_Setup();
    GongBonger_Setup();
    HotLiquid_Setup();
    LaraAlarm_Setup();

    // projectiles
    Grenade_Setup();
    HarpoonBolt_Setup();
    MissileFlame_Setup();
    MissileHarpoon_Setup();
    MissileKnife_Setup();
    SphereOfDoom_Setup(Object_GetObject(O_SPHERE_OF_DOOM_1), true);
    SphereOfDoom_Setup(Object_GetObject(O_SPHERE_OF_DOOM_2), true);
    SphereOfDoom_Setup(Object_GetObject(O_SPHERE_OF_DOOM_3), false);

    // effects
    Blood_Setup();
    BodyPart_Setup();
    Bubble_Setup();
    Explosion_Setup();
    Glow_Setup();
    Splash_Setup();
    Twinkle_Setup();
    GunFlash_Setup();
    Ricochet_Setup();
    SnowSprite_Setup();
    WaterSprite_Setup();
    Waterfall_Setup();

    // geometry objects
    BridgeFlat_Setup();
    BridgeTilt1_Setup();
    BridgeTilt2_Setup();
    Drawbridge_Setup();
    Window_1_Setup();
    Window_2_Setup();

    // doors
    Door_Setup(Object_GetObject(O_DOOR_TYPE_1));
    Door_Setup(Object_GetObject(O_DOOR_TYPE_2));
    Door_Setup(Object_GetObject(O_DOOR_TYPE_3));
    Door_Setup(Object_GetObject(O_DOOR_TYPE_4));
    Door_Setup(Object_GetObject(O_DOOR_TYPE_5));
    Door_Setup(Object_GetObject(O_DOOR_TYPE_6));
    Door_Setup(Object_GetObject(O_DOOR_TYPE_7));
    Door_Setup(Object_GetObject(O_DOOR_TYPE_8));
    Trapdoor_Setup(Object_GetObject(O_TRAPDOOR_TYPE_1));
    Trapdoor_Setup(Object_GetObject(O_TRAPDOOR_TYPE_2));

    // keys and puzzles
    Keyhole_Setup(Object_GetObject(O_KEY_HOLE_1));
    Keyhole_Setup(Object_GetObject(O_KEY_HOLE_2));
    Keyhole_Setup(Object_GetObject(O_KEY_HOLE_3));
    Keyhole_Setup(Object_GetObject(O_KEY_HOLE_4));
    PuzzleHole_Setup(Object_GetObject(O_PUZZLE_DONE_1), true);
    PuzzleHole_Setup(Object_GetObject(O_PUZZLE_DONE_2), true);
    PuzzleHole_Setup(Object_GetObject(O_PUZZLE_DONE_3), true);
    PuzzleHole_Setup(Object_GetObject(O_PUZZLE_DONE_4), true);
    PuzzleHole_Setup(Object_GetObject(O_PUZZLE_HOLE_1), false);
    PuzzleHole_Setup(Object_GetObject(O_PUZZLE_HOLE_2), false);
    PuzzleHole_Setup(Object_GetObject(O_PUZZLE_HOLE_3), false);
    PuzzleHole_Setup(Object_GetObject(O_PUZZLE_HOLE_4), false);

    // switches
    Switch_Setup(Object_GetObject(O_SWITCH_TYPE_AIRLOCK), false);
    Switch_Setup(Object_GetObject(O_SWITCH_TYPE_BUTTON), false);
    Switch_Setup(Object_GetObject(O_SWITCH_TYPE_NORMAL), false);
    Switch_Setup(Object_GetObject(O_SWITCH_TYPE_SMALL), false);
    Switch_Setup(Object_GetObject(O_SWITCH_TYPE_UW), true);

    // cutscene players
    CutscenePlayer_Setup(Object_GetObject(O_PLAYER_1));
    CutscenePlayer_Setup(Object_GetObject(O_PLAYER_2));
    CutscenePlayer_Setup(Object_GetObject(O_PLAYER_3));
    CutscenePlayer_Setup(Object_GetObject(O_PLAYER_4));
    CutscenePlayer_Setup(Object_GetObject(O_PLAYER_5));
    CutscenePlayer_Setup(Object_GetObject(O_PLAYER_6));
    CutscenePlayer_Setup(Object_GetObject(O_PLAYER_7));
    CutscenePlayer_Setup(Object_GetObject(O_PLAYER_8));
    CutscenePlayer_Setup(Object_GetObject(O_PLAYER_9));
    CutscenePlayer_Setup(Object_GetObject(O_PLAYER_10));

    // pickups
    Pickup_Setup(Object_GetObject(O_FLARES_ITEM));
    Pickup_Setup(Object_GetObject(O_GRENADE_AMMO_ITEM));
    Pickup_Setup(Object_GetObject(O_GRENADE_ITEM));
    Pickup_Setup(Object_GetObject(O_HARPOON_AMMO_ITEM));
    Pickup_Setup(Object_GetObject(O_HARPOON_ITEM));
    Pickup_Setup(Object_GetObject(O_KEY_ITEM_1));
    Pickup_Setup(Object_GetObject(O_KEY_ITEM_2));
    Pickup_Setup(Object_GetObject(O_KEY_ITEM_3));
    Pickup_Setup(Object_GetObject(O_KEY_ITEM_4));
    Pickup_Setup(Object_GetObject(O_LARGE_MEDIPACK_ITEM));
    Pickup_Setup(Object_GetObject(O_M16_AMMO_ITEM));
    Pickup_Setup(Object_GetObject(O_M16_ITEM));
    Pickup_Setup(Object_GetObject(O_MAGNUM_AMMO_ITEM));
    Pickup_Setup(Object_GetObject(O_MAGNUM_ITEM));
    Pickup_Setup(Object_GetObject(O_PICKUP_ITEM_1));
    Pickup_Setup(Object_GetObject(O_PICKUP_ITEM_2));
    Pickup_Setup(Object_GetObject(O_PISTOL_AMMO_ITEM));
    Pickup_Setup(Object_GetObject(O_PISTOL_ITEM));
    Pickup_Setup(Object_GetObject(O_PUZZLE_ITEM_1));
    Pickup_Setup(Object_GetObject(O_PUZZLE_ITEM_2));
    Pickup_Setup(Object_GetObject(O_PUZZLE_ITEM_3));
    Pickup_Setup(Object_GetObject(O_PUZZLE_ITEM_4));
    Pickup_Setup(Object_GetObject(O_SECRET_1));
    Pickup_Setup(Object_GetObject(O_SECRET_3));
    Pickup_Setup(Object_GetObject(O_SHOTGUN_AMMO_ITEM));
    Pickup_Setup(Object_GetObject(O_SHOTGUN_ITEM));
    Pickup_Setup(Object_GetObject(O_SMALL_MEDIPACK_ITEM));
    Pickup_Setup(Object_GetObject(O_UZI_AMMO_ITEM));
    Pickup_Setup(Object_GetObject(O_UZI_ITEM));

    Secret2_Setup();
}

void __cdecl Object_SetupAllObjects(void)
{
    for (int32_t i = 0; i < O_NUMBER_OF; i++) {
        OBJECT *const object = Object_GetObject(i);
        object->initialise = NULL;
        object->control = NULL;
        object->floor = NULL;
        object->ceiling = NULL;
        object->draw_routine = Object_DrawAnimatingItem;
        object->collision = NULL;
        object->hit_points = DONT_TARGET;
        object->pivot_length = 0;
        object->radius = DEFAULT_RADIUS;
        object->shadow_size = 0;

        object->save_position = 0;
        object->save_hitpoints = 0;
        object->save_flags = 0;
        object->save_anim = 0;
        object->intelligent = 0;
        object->water_creature = 0;
    }

    Object_SetupBaddyObjects();
    Object_SetupTrapObjects();
    Object_SetupGeneralObjects();

    InitialiseHair();
}
