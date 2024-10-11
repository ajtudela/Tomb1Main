// This file is autogenerated. To update it, run tools/generate_funcs.

#pragma once

#include "global/types.h"

// clang-format off
#define Output_InsertInventoryBackground ((void __cdecl (*)(const int16_t *obj_ptr))0x00401D50)
#define Diver_Harpoon ((int16_t __cdecl (*)(int32_t x, int32_t y, int32_t z, int16_t speed, PHD_ANGLE y_rot, int16_t room_num))0x00416C20)
#define Diver_GetWaterSurface ((int32_t __cdecl (*)(int32_t x, int32_t y, int32_t z, int16_t room_num))0x00416CA0)
#define Dog_Control ((void __cdecl (*)(int16_t item_num))0x00417160)
#define Tiger_Control ((void __cdecl (*)(int16_t item_num))0x00417510)
#define DinoControl ((void __cdecl (*)(int16_t item_num))0x004186A0)
#define Object_DrawSpriteItem ((void __cdecl (*)(ITEM *item))0x004199E0)
#define Object_DrawAnimatingItem ((void __cdecl (*)(ITEM *item))0x00419A70)
#define Gun_DrawFlash ((void __cdecl (*)(LARA_GUN_TYPE weapon_type, int32_t clip))0x0041BD30)
#define Output_CalculateObjectLighting ((void __cdecl (*)(const ITEM *item, const FRAME_INFO *frame))0x0041BEA0)
#define AddDynamicLight ((void __cdecl (*)(int32_t x, int32_t y, int32_t z, int32_t intensity, int32_t falloff))0x0041C0F0)
#define BigEelControl ((void __cdecl (*)(int16_t item_num))0x0041C140)
#define EelControl ((void __cdecl (*)(int16_t item_num))0x0041C2E0)
#define DoBloodSplat ((int16_t __cdecl (*)(int32_t x, int32_t y, int32_t z, int16_t speed, PHD_ANGLE direction, int16_t room_num))0x0041C5D0)
#define DoLotsOfBlood ((void __cdecl (*)(int32_t x, int32_t y, int32_t z, int16_t speed, PHD_ANGLE direction, int16_t room_num, int32_t num))0x0041C630)
#define ControlBlood1 ((void __cdecl (*)(int16_t fx_num))0x0041C6E0)
#define ControlExplosion1 ((void __cdecl (*)(int16_t fx_num))0x0041C770)
#define Richochet ((void __cdecl (*)(GAME_VECTOR *pos))0x0041C7F0)
#define ControlRichochet1 ((void __cdecl (*)(int16_t fx_num))0x0041C870)
#define CreateBubble ((void __cdecl (*)(PHD_3DPOS *pos, int16_t room_num))0x0041C8A0)
#define LaraBubbles ((void __cdecl (*)(ITEM *item))0x0041C910)
#define ControlBubble1 ((void __cdecl (*)(int16_t fx_num))0x0041C990)
#define Splash ((void __cdecl (*)(ITEM *item))0x0041CA90)
#define ControlSplash1 ((void __cdecl (*)(int16_t fx_num))0x0041CB60)
#define ControlWaterSprite ((void __cdecl (*)(int16_t fx_num))0x0041CBE0)
#define ControlSnowSprite ((void __cdecl (*)(int16_t fx_num))0x0041CC90)
#define ControlHotLiquid ((void __cdecl (*)(int16_t fx_num))0x0041CD20)
#define WaterFall ((void __cdecl (*)(int16_t fx_num))0x0041CE00)
#define finish_level_effect ((void __cdecl (*)(ITEM *item))0x0041CF40)
#define turn180_effect ((void __cdecl (*)(ITEM *item))0x0041CF50)
#define floor_shake_effect ((void __cdecl (*)(ITEM *item))0x0041CF70)
#define lara_normal_effect ((void __cdecl (*)(ITEM *item))0x0041D010)
#define BoilerFX ((void __cdecl (*)(ITEM *item))0x0041D050)
#define FloodFX ((void __cdecl (*)(ITEM *item))0x0041D070)
#define RubbleFX ((void __cdecl (*)(ITEM *item))0x0041D100)
#define ChandelierFX ((void __cdecl (*)(ITEM *item))0x0041D130)
#define ExplosionFX ((void __cdecl (*)(ITEM *item))0x0041D160)
#define PistonFX ((void __cdecl (*)(ITEM *item))0x0041D190)
#define CurtainFX ((void __cdecl (*)(ITEM *item))0x0041D1B0)
#define StatueFX ((void __cdecl (*)(ITEM *item))0x0041D1D0)
#define SetChangeFX ((void __cdecl (*)(ITEM *item))0x0041D1F0)
#define ControlDingDong ((void __cdecl (*)(int16_t item_num))0x0041D210)
#define ControlLaraAlarm ((void __cdecl (*)(int16_t item_num))0x0041D250)
#define ControlAlarmSound ((void __cdecl (*)(int16_t item_num))0x0041D290)
#define ControlBirdTweeter ((void __cdecl (*)(int16_t item_num))0x0041D300)
#define DoChimeSound ((void __cdecl (*)(ITEM *item))0x0041D360)
#define ControlClockChimes ((void __cdecl (*)(int16_t item_num))0x0041D3C0)
#define SphereOfDoomCollision ((void __cdecl (*)(int16_t item_num, ITEM *lara_item, COLL_INFO *coll))0x0041D430)
#define SphereOfDoom ((void __cdecl (*)(int16_t item_num))0x0041D560)
#define DrawSphereOfDoom ((void __cdecl (*)(ITEM *item))0x0041D650)
#define lara_hands_free ((void __cdecl (*)(ITEM *item))0x0041D780)
#define flip_map_effect ((void __cdecl (*)(ITEM *item))0x0041D790)
#define draw_right_gun ((void __cdecl (*)(ITEM *item))0x0041D7A0)
#define draw_left_gun ((void __cdecl (*)(ITEM *item))0x0041D7F0)
#define swap_meshes_with_meshswap1 ((void __cdecl (*)(ITEM *item))0x0041D840)
#define swap_meshes_with_meshswap2 ((void __cdecl (*)(ITEM *item))0x0041D8B0)
#define swap_meshes_with_meshswap3 ((void __cdecl (*)(ITEM *item))0x0041D920)
#define invisibility_on ((void __cdecl (*)(ITEM *item))0x0041D9C0)
#define invisibility_off ((void __cdecl (*)(ITEM *item))0x0041D9D0)
#define dynamic_light_on ((void __cdecl (*)(ITEM *item))0x0041D9F0)
#define dynamic_light_off ((void __cdecl (*)(ITEM *item))0x0041DA00)
#define reset_hair ((void __cdecl (*)(ITEM *item))0x0041DA10)
#define AssaultStart ((void __cdecl (*)(ITEM *item))0x0041DA20)
#define AssaultStop ((void __cdecl (*)(ITEM *item))0x0041DA50)
#define AssaultReset ((void __cdecl (*)(ITEM *item))0x0041DA70)
#define AssaultFinished ((void __cdecl (*)(ITEM *item))0x0041DA90)
#define Knife ((int16_t __cdecl (*)(int32_t x, int32_t y, int32_t z, int16_t speed, PHD_ANGLE yrot, int16_t room_num))0x0041DB50)
#define Cult2Control ((void __cdecl (*)(int16_t item_num))0x0041DBD0)
#define MonkControl ((void __cdecl (*)(int16_t item_num))0x0041E000)
#define Worker3Control ((void __cdecl (*)(int16_t item_num))0x0041E4D0)
#define DrawXianLord ((void __cdecl (*)(ITEM *item))0x0041EAE0)
#define XianDamage ((void __cdecl (*)(ITEM *item, CREATURE *xian, int32_t damage))0x0041EEE0)
#define InitialiseXianLord ((void __cdecl (*)(int16_t item_num))0x0041EF90)
#define XianLordControl ((void __cdecl (*)(int16_t item_num))0x0041EFF0)
#define WarriorSparkleTrail ((void __cdecl (*)(ITEM *item))0x0041F5D0)
#define WarriorControl ((void __cdecl (*)(int16_t item_num))0x0041F670)
#define InitialiseHair ((void __cdecl (*)(void))0x00420EA0)
#define HairControl ((void __cdecl (*)(int32_t in_cutscene))0x00420F20)
#define DrawHair ((void __cdecl (*)(void))0x00421920)
#define HarpoonBolt_Control ((void __cdecl (*)(int16_t item_num))0x0042C0F0)
#define Rocket_Control ((void __cdecl (*)(int16_t item_num))0x0042C530)
#define Flare_DoLight ((int32_t __cdecl (*)(XYZ_32 *pos, int32_t flare_age))0x0042F7A0)
#define Flare_DoInHand ((void __cdecl (*)(int32_t flare_age))0x0042F840)
#define Flare_DrawInAir ((void __cdecl (*)(ITEM *item))0x0042F920)
#define Flare_Create ((void __cdecl (*)(int32_t thrown))0x0042FA20)
#define Flare_SetArm ((void __cdecl (*)(int32_t frame))0x0042FC00)
#define Flare_Draw ((void __cdecl (*)(void))0x0042FC50)
#define Flare_Undraw ((void __cdecl (*)(void))0x0042FDC0)
#define Flare_DrawMeshes ((void __cdecl (*)(void))0x0042FFF0)
#define Flare_UndrawMeshes ((void __cdecl (*)(void))0x00430010)
#define Flare_Ready ((void __cdecl (*)(void))0x00430030)
#define Flare_Control ((void __cdecl (*)(int16_t item_num))0x00430070)
#define ControlMissile ((void __cdecl (*)(int16_t fx_num))0x00432FE0)
#define ShootAtLara ((void __cdecl (*)(FX *fx))0x004332B0)
#define BodyPart_Control ((void __cdecl (*)(int16_t fx_num))0x004336F0)
#define InitialiseMovingBlock ((void __cdecl (*)(int16_t item_num))0x004338F0)
#define MovableBlock ((void __cdecl (*)(int16_t item_num))0x00433920)
#define MovableBlockCollision ((void __cdecl (*)(int16_t item_num, ITEM *lara_item, COLL_INFO *coll))0x00433A70)
#define TestBlockMovable ((int32_t __cdecl (*)(ITEM *item, int32_t block_height))0x00433CD0)
#define TestBlockPush ((int32_t __cdecl (*)(ITEM *item, int32_t block_height, uint16_t quadrant))0x00433D20)
#define TestBlockPull ((int32_t __cdecl (*)(ITEM *item, int32_t block_height, uint16_t quadrant))0x00433E70)
#define DrawMovableBlock ((void __cdecl (*)(ITEM *item))0x00434170)
#define DrawUnclippedItem ((void __cdecl (*)(ITEM *item))0x004341A0)
#define EarthQuake ((void __cdecl (*)(int16_t item_num))0x00434210)
#define ControlCutShotgun ((void __cdecl (*)(int16_t item_num))0x004342F0)
#define InitialiseFinalLevel ((void __cdecl (*)(void))0x00434330)
#define MiniCopterControl ((void __cdecl (*)(int16_t item_num))0x00434610)
#define InitialiseDyingMonk ((void __cdecl (*)(int16_t item_num))0x004346F0)
#define DyingMonk ((void __cdecl (*)(int16_t item_num))0x00434770)
#define ControlGongBonger ((void __cdecl (*)(int16_t item_num))0x00434800)
#define DeathSlideCollision ((void __cdecl (*)(int16_t item_num, ITEM *lara_item, COLL_INFO *coll))0x004348C0)
#define ControlDeathSlide ((void __cdecl (*)(int16_t item_num))0x00434980)
#define BigBowlControl ((void __cdecl (*)(int16_t item_num))0x00434C10)
#define BellControl ((void __cdecl (*)(int16_t item_num))0x00434D00)
#define InitialiseWindow ((void __cdecl (*)(int16_t item_num))0x00434D80)
#define SmashWindow ((void __cdecl (*)(int16_t item_num))0x00434E00)
#define WindowControl ((void __cdecl (*)(int16_t item_num))0x00434ED0)
#define SmashIceControl ((void __cdecl (*)(int16_t item_num))0x00434F70)
#define ShutThatDoor ((void __cdecl (*)(DOORPOS_DATA *d))0x00435050)
#define OpenThatDoor ((void __cdecl (*)(DOORPOS_DATA *d))0x004350A0)
#define InitialiseDoor ((void __cdecl (*)(int16_t item_num))0x004350E0)
#define DoorControl ((void __cdecl (*)(int16_t item_num))0x004354C0)
#define OnDrawBridge ((int32_t __cdecl (*)(ITEM *item, int32_t x, int32_t y))0x00435590)
#define DrawBridgeFloor ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x00435650)
#define DrawBridgeCeiling ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x00435690)
#define DrawBridgeCollision ((void __cdecl (*)(int16_t item_num, ITEM *lara_item, COLL_INFO *coll))0x004356D0)
#define InitialiseLift ((void __cdecl (*)(int16_t item_num))0x00435700)
#define LiftControl ((void __cdecl (*)(int16_t item_num))0x00435740)
#define LiftFloorCeiling ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *floor, int32_t *ceiling))0x00435820)
#define LiftFloor ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x004359A0)
#define LiftCeiling ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x004359E0)
#define BridgeFlatFloor ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x00435A20)
#define BridgeFlatCeiling ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x00435A40)
#define GetOffset ((int32_t __cdecl (*)(ITEM *item, int32_t x, int32_t z))0x00435A60)
#define BridgeTilt1Floor ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x00435AA0)
#define BridgeTilt1Ceiling ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x00435AD0)
#define BridgeTilt2Floor ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x00435B10)
#define BridgeTilt2Ceiling ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x00435B40)
#define CopterControl ((void __cdecl (*)(int16_t item_num))0x00435B80)
#define GeneralControl ((void __cdecl (*)(int16_t item_num))0x00435C90)
#define DetonatorControl ((void __cdecl (*)(int16_t item_num))0x00435D70)
#define ControlGlow ((void __cdecl (*)(int16_t fx_num))0x00435E90)
#define ControlGunShot ((void __cdecl (*)(int16_t fx_num))0x00435ED0)
#define GunShot ((int16_t __cdecl (*)(int32_t x, int32_t y, int32_t z, int16_t speed, PHD_ANGLE yrot, int16_t room_num))0x00435F20)
#define GunHit ((int16_t __cdecl (*)(int32_t x, int32_t y, int32_t z, int16_t speed, PHD_ANGLE yrot, int16_t room_num))0x00435F90)
#define GunMiss ((int16_t __cdecl (*)(int32_t x, int32_t y, int32_t z, int16_t speed, PHD_ANGLE yrot, int16_t room_num))0x00436050)
#define ShotLara ((int32_t __cdecl (*)(ITEM *item, AI_INFO *info, BITE *gun, int16_t extra_rotation, int32_t damage))0x00436100)
#define InitialiseCult1 ((void __cdecl (*)(int16_t item_num))0x004362D0)
#define Cult1Control ((void __cdecl (*)(int16_t item_num))0x00436320)
#define InitialiseCult3 ((void __cdecl (*)(int16_t item_num))0x00436750)
#define Cult3Control ((void __cdecl (*)(int16_t item_num))0x004367A0)
#define Worker1Control ((void __cdecl (*)(int16_t item_num))0x00436D10)
#define Worker2Control ((void __cdecl (*)(int16_t item_num))0x00437110)
#define BanditControl ((void __cdecl (*)(int16_t item_num))0x00437570)
#define Bandit2Control ((void __cdecl (*)(int16_t item_num))0x004378B0)
#define WinstonControl ((void __cdecl (*)(int16_t item_num))0x00437CF0)
#define PickUpCollision ((void __cdecl (*)(int16_t item_num, ITEM *lara_item, COLL_INFO *coll))0x00437E70)
#define DetonatorCollision ((void __cdecl (*)(int16_t item_num, ITEM *lara_item, COLL_INFO *coll))0x00438600)
#define PickupTrigger ((int32_t __cdecl (*)(int16_t item_num))0x00438E80)
#define SecretControl ((void __cdecl (*)(int16_t item_num))0x00438EC0)
#define MouseControl ((void __cdecl (*)(int16_t item_num))0x00438EF0)
#define InitialiseStartInfo ((void __cdecl (*)(void))0x004390E0)
#define ModifyStartInfo ((void __cdecl (*)(int32_t level_num))0x00439150)
#define CreateStartInfo ((void __cdecl (*)(int32_t level_num))0x00439230)
#define CreateSaveGameInfo ((void __cdecl (*)(void))0x00439440)
#define ExtractSaveGameInfo ((void __cdecl (*)(void))0x00439970)
#define ResetSG ((void __cdecl (*)(void))0x0043A1D0)
#define WriteSG ((void __cdecl (*)(void *pointer, int32_t size))0x0043A1F0)
#define ReadSG ((void __cdecl (*)(void *pointer, int32_t size))0x0043A240)
#define InitialiseGameFlags ((void __cdecl (*)(void))0x0043A3E0)
#define InitialiseLevelFlags ((void __cdecl (*)(void))0x0043A450)
#define BaddyObjects ((void __cdecl (*)(void))0x0043A480)
#define TrapObjects ((void __cdecl (*)(void))0x0043B4C0)
#define ObjectObjects ((void __cdecl (*)(void))0x0043BAC0)
#define InitialiseObjects ((void __cdecl (*)(void))0x0043C710)
#define GetCarriedItems ((void __cdecl (*)(void))0x0043C780)
#define JellyControl ((void __cdecl (*)(int16_t item_num))0x0043C850)
#define BaracuddaControl ((void __cdecl (*)(int16_t item_num))0x0043C970)
#define SharkControl ((void __cdecl (*)(int16_t item_num))0x0043CBA0)
#define InitialiseSkidoo ((void __cdecl (*)(int16_t item_num))0x0043CE30)
#define SkidooCheckGeton ((int32_t __cdecl (*)(int16_t item_num, COLL_INFO *coll))0x0043CE70)
#define SkidooCollision ((void __cdecl (*)(int16_t item_num, ITEM *litem, COLL_INFO *coll))0x0043CF60)
#define SkidooBaddieCollision ((void __cdecl (*)(ITEM *skidoo))0x0043D060)
#define TestHeight ((int32_t __cdecl (*)(ITEM *item, int32_t z_off, int32_t x_off, XYZ_32 *pos))0x0043D260)
#define DoShift ((int32_t __cdecl (*)(ITEM *skidoo, XYZ_32 *pos, XYZ_32 *old))0x0043D320)
#define DoDynamics ((int32_t __cdecl (*)(int32_t height, int32_t fall_speed, int32_t *y))0x0043D5A0)
#define GetCollisionAnim ((int32_t __cdecl (*)(ITEM *skidoo, XYZ_32 *moved))0x0043D600)
#define DoSnowEffect ((void __cdecl (*)(ITEM *skidoo))0x0043D690)
#define SkidooDynamics ((int32_t __cdecl (*)(ITEM *skidoo))0x0043D7D0)
#define SkidooUserControl ((int32_t __cdecl (*)(ITEM *skidoo, int32_t height, int32_t *pitch))0x0043DC70)
#define SkidooCheckGetOffOK ((int32_t __cdecl (*)(int32_t direction))0x0043DE30)
#define SkidooAnimation ((void __cdecl (*)(ITEM *skidoo, int32_t collide, int32_t dead))0x0043DF40)
#define SkidooExplode ((void __cdecl (*)(ITEM *skidoo))0x0043E220)
#define SkidooCheckGetOff ((int32_t __cdecl (*)(void))0x0043E2A0)
#define SkidooGuns ((void __cdecl (*)(void))0x0043E4E0)
#define SkidooControl ((int32_t __cdecl (*)(void))0x0043E600)
#define DrawSkidoo ((void __cdecl (*)(ITEM *item))0x0043EA60)
#define InitialiseSkidman ((void __cdecl (*)(int16_t item_num))0x0043ED40)
#define SkidManControl ((void __cdecl (*)(int16_t rider_num))0x0043EDD0)
#define SkidmanPush ((void __cdecl (*)(ITEM *item, ITEM *lara_item, int32_t radius))0x0043F1D0)
#define SkidmanCollision ((void __cdecl (*)(int16_t item_num, ITEM *lara_item, COLL_INFO *coll))0x0043F2F0)
#define Music_GetRealTrack ((int32_t __cdecl (*)(int32_t track))0x0043F380)
#define Collide_TestCollision ((int32_t __cdecl (*)(ITEM *item, const ITEM *lara_item))0x0043F9B0)
#define Collide_GetSpheres ((int32_t __cdecl (*)(const ITEM *item, SPHERE *spheres, bool world_space))0x0043FAE0)
#define Collide_GetJointAbsPosition ((void __cdecl (*)(const ITEM *item, const XYZ_32 *vec, int32_t joint))0x0043FDC0)
#define BaddieBiteEffect ((void __cdecl (*)(ITEM *item, BITE *bite))0x0043FF60)
#define SpiderLeap ((void __cdecl (*)(int16_t item_num, int16_t angle))0x0043FFC0)
#define SpiderControl ((void __cdecl (*)(int16_t item_num))0x00440070)
#define BigSpiderControl ((void __cdecl (*)(int16_t item_num))0x00440290)
#define MineControl ((void __cdecl (*)(int16_t mine_num))0x00440F10)
#define ControlSpikeWall ((void __cdecl (*)(int16_t item_num))0x00441110)
#define ControlCeilingSpikes ((void __cdecl (*)(int16_t item_num))0x00441250)
#define HookControl ((void __cdecl (*)(int16_t item_num))0x00441370)
#define PropellerControl ((void __cdecl (*)(int16_t item_num))0x00441400)
#define SpinningBlade ((void __cdecl (*)(int16_t item_num))0x00441590)
#define IcicleControl ((void __cdecl (*)(int16_t item_num))0x00441710)
#define InitialiseBlade ((void __cdecl (*)(int16_t item_num))0x00441810)
#define BladeControl ((void __cdecl (*)(int16_t item_num))0x00441850)
#define InitialiseKillerStatue ((void __cdecl (*)(int16_t item_num))0x004418F0)
#define KillerStatueControl ((void __cdecl (*)(int16_t item_num))0x00441940)
#define SpringBoardControl ((void __cdecl (*)(int16_t item_num))0x00441A50)
#define InitialiseRollingBall ((void __cdecl (*)(int16_t item_num))0x00441B30)
#define RollingBallControl ((void __cdecl (*)(int16_t item_num))0x00441B70)
#define RollingBallCollision ((void __cdecl (*)(int16_t item_num, ITEM *litem, COLL_INFO *coll))0x00441EC0)
#define SpikeCollision ((void __cdecl (*)(int16_t item_num, ITEM *litem, COLL_INFO *coll))0x00442110)
#define TrapDoorControl ((void __cdecl (*)(int16_t item_num))0x00442270)
#define TrapDoorFloor ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x004422C0)
#define TrapDoorCeiling ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x00442300)
#define OnTrapDoor ((int32_t __cdecl (*)(ITEM *item, int32_t x, int32_t z))0x00442340)
#define Pendulum ((void __cdecl (*)(int16_t item_num))0x004423F0)
#define FallingBlock ((void __cdecl (*)(int16_t item_num))0x00442500)
#define FallingBlockFloor ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x00442610)
#define FallingBlockCeiling ((void __cdecl (*)(ITEM *item, int32_t x, int32_t y, int32_t z, int32_t *height))0x00442650)
#define TeethTrap ((void __cdecl (*)(int16_t item_num))0x004426A0)
#define FallingCeiling ((void __cdecl (*)(int16_t item_num))0x00442760)
#define DartEmitterControl ((void __cdecl (*)(int16_t item_num))0x00442840)
#define DartsControl ((void __cdecl (*)(int16_t item_num))0x00442980)
#define DartEffectControl ((void __cdecl (*)(int16_t fx_num))0x00442AE0)
#define GiantYetiControl ((void __cdecl (*)(int16_t item_num))0x00443050)
#define YetiControl ((void __cdecl (*)(int16_t item_num))0x00443350)
#define WinInReadJoystick ((DWORD __cdecl (*)(int32_t *x, int32_t *y))0x004472A0)
#define WinInputInit ((bool __cdecl (*)(void))0x004473B0)
#define DInputEnumDevices ((bool __cdecl (*)(JOYSTICK_LIST *joystickList))0x00447430)
#define DInputEnumDevicesCallback ((BOOL __stdcall (*)(LPCDIDEVICEINSTANCE lpddi, LPVOID pvRef))0x00447460)
#define GetJoystick ((JOYSTICK_NODE *__cdecl (*)(GUID *lpGuid))0x00447570)
#define DInputKeyboardCreate ((void __cdecl (*)(void))0x004475C0)
#define DInputKeyboardRelease ((void __cdecl (*)(void))0x00447690)
#define DInputJoystickCreate ((bool __cdecl (*)(void))0x004476C0)
#define WinInStart ((void __cdecl (*)(void))0x004477B0)
#define WinInFinish ((void __cdecl (*)(void))0x004477E0)
#define WinInRunControlPanel ((void __cdecl (*)(HWND hWnd))0x004477F0)
#define IncreaseScreenSize ((void __cdecl (*)(void))0x00447810)
#define DecreaseScreenSize ((void __cdecl (*)(void))0x00447880)
#define setup_screen_size ((void __cdecl (*)(void))0x004478F0)
#define TempVideoAdjust ((void __cdecl (*)(int32_t hires, double sizer))0x00447990)
#define TempVideoRemove ((void __cdecl (*)(void))0x004479D0)
#define S_FadeInInventory ((void __cdecl (*)(BOOL isFade))0x00447A10)
#define S_FadeOutInventory ((void __cdecl (*)(BOOL isFade))0x00447A50)
#define ReadFileSync ((BOOL __cdecl (*)(HANDLE handle, LPVOID lpBuffer, DWORD nBytesToRead, LPDWORD lpnBytesRead, LPOVERLAPPED lpOverlapped))0x004498D0)
#define AdjustTextureUVs ((void __cdecl (*)(bool reset_uv_add))0x00449E50)
#define ChangeFileNameExtension ((void __cdecl (*)(char *file_name, const char *file_ext))0x0044B110)
#define GetFullPath ((LPCTSTR __cdecl (*)(LPCTSTR file_name))0x0044B150)
#define SelectDrive ((BOOL __cdecl (*)(void))0x0044B180)
#define S_LoadLevelFile ((BOOL __cdecl (*)(LPCTSTR file_name, int32_t level_num, GAMEFLOW_LEVEL_TYPE level_type))0x0044B4B0)
#define S_UnloadLevelFile ((void __cdecl (*)(void))0x0044B4D0)
#define S_AdjustTexelCoordinates ((void __cdecl (*)(void))0x0044B500)
#define S_ReloadLevelGraphics ((BOOL __cdecl (*)(BOOL reload_palettes, BOOL reload_tex_pages))0x0044B520)
#define PlayFMV ((bool __cdecl (*)(const char *file_name))0x0044BDA0)
#define WinPlayFMV ((void __cdecl (*)(const char *file_name, bool is_playback))0x0044BE10)
#define WinStopFMV ((void __cdecl (*)(bool is_playback))0x0044C0F0)
#define IntroFMV ((bool __cdecl (*)(const char *file_name1, const char *file_name2))0x0044C140)
#define S_COLOR ((uint16_t __cdecl (*)(int32_t red, int32_t green, int32_t blue))0x0044C1D0)
#define S_DrawScreenLine ((void __cdecl (*)(int32_t x, int32_t y, int32_t z, int32_t x_len, int32_t y_len, BYTE color_idx, D3DCOLOR *gour, uint16_t flags))0x0044C200)
#define S_DrawScreenBox ((void __cdecl (*)(int32_t sx, int32_t sy, int32_t z, int32_t width, int32_t height, BYTE color_idx, const GOURAUD_OUTLINE *gour, uint16_t flags))0x0044C240)
#define S_DrawScreenFBox ((void __cdecl (*)(int32_t sx, int32_t sy, int32_t z, int32_t width, int32_t height, BYTE color_idx, const GOURAUD_FILL *gour, uint16_t flags))0x0044C360)
#define S_FinishInventory ((void __cdecl (*)(void))0x0044C390)
#define S_FadeToBlack ((void __cdecl (*)(void))0x0044C3A0)
#define S_Wait ((void __cdecl (*)(int32_t timeout, BOOL input_check))0x0044C3F0)
#define S_PlayFMV ((bool __cdecl (*)(const char *file_name))0x0044C450)
#define S_IntroFMV ((bool __cdecl (*)(const char *file_name1, const char *file_name2))0x0044C460)
#define GetValidLevelsList ((void __cdecl (*)(REQUEST_INFO *req))0x0044C9D0)
#define GetSavedGamesList ((void __cdecl (*)(REQUEST_INFO *req))0x0044CA20)
#define DisplayCredits ((void __cdecl (*)(void))0x0044CA70)
#define S_FrontEndCheck ((BOOL __cdecl (*)(void))0x0044CCB0)
#define S_SaveGame ((int32_t __cdecl (*)(const void *save_data, uint32_t save_size, int32_t slot_num))0x0044CE20)
#define S_LoadGame ((int32_t __cdecl (*)(void *save_data, uint32_t save_size, int32_t slot_num))0x0044CF40)
#define S_InitialiseSystem ((BOOL __cdecl (*)(void))0x0044D610)
#define GameBuf_Shutdown ((void __cdecl (*)(void))0x0044D670)
#define init_game_malloc ((void __cdecl (*)(void))0x0044D690)
#define game_malloc ((void *__cdecl (*)(size_t alloc_size, GAME_BUFFER buf_index))0x0044D6C0)
#define game_free ((void __cdecl (*)(size_t free_size))0x0044D740)
#define CalculateWibbleTable ((void __cdecl (*)(void))0x0044D780)
#define GetRenderHeight ((int32_t __cdecl (*)(void))0x00450AE0)
#define GetRenderWidth ((int32_t __cdecl (*)(void))0x00450AF0)
#define S_InitialisePolyList ((void __cdecl (*)(BOOL clear_back_buffer))0x00450B00)
#define S_DumpScreen ((DWORD __cdecl (*)(void))0x00450BF0)
#define S_ClearScreen ((void __cdecl (*)(void))0x00450C30)
#define S_InitialiseScreen ((void __cdecl (*)(GAMEFLOW_LEVEL_TYPE level_type))0x00450C40)
#define S_OutputPolyList ((void __cdecl (*)(void))0x00450C80)
#define S_GetObjectBounds ((int32_t __cdecl (*)(const BOUNDS_16 *bounds))0x00450CC0)
#define S_InsertBackPolygon ((void __cdecl (*)(int32_t x0, int32_t y0, int32_t x1, int32_t y1))0x00450F30)
#define S_PrintShadow ((void __cdecl (*)(int16_t radius, const BOUNDS_16 *bounds, const ITEM *item))0x00450F80)
#define S_CalculateLight ((void __cdecl (*)(int32_t x, int32_t y, int32_t z, int16_t room_num))0x00451180)
#define S_CalculateStaticLight ((void __cdecl (*)(int16_t adder))0x00451480)
#define S_CalculateStaticMeshLight ((void __cdecl (*)(int32_t x, int32_t y, int32_t z, int32_t shade_1, int32_t shade_2, ROOM *room))0x004514C0)
#define S_LightRoom ((void __cdecl (*)(ROOM *room))0x004515F0)
#define S_DrawHealthBar ((void __cdecl (*)(int32_t percent))0x00451800)
#define S_DrawAirBar ((void __cdecl (*)(int32_t percent))0x004519D0)
#define AnimateTextures ((void __cdecl (*)(int32_t ticks))0x00451BD0)
#define S_SetupBelowWater ((void __cdecl (*)(BOOL underwater))0x00451C90)
#define S_SetupAboveWater ((void __cdecl (*)(BOOL underwater))0x00451CF0)
#define S_AnimateTextures ((void __cdecl (*)(int32_t ticks))0x00451D20)
#define S_DisplayPicture ((void __cdecl (*)(const char *file_name, BOOL is_title))0x00451DE0)
#define S_SyncPictureBufferPalette ((void __cdecl (*)(void))0x00451EF0)
#define S_DontDisplayPicture ((void __cdecl (*)(void))0x00451F70)
#define ScreenDump ((void __cdecl (*)(void))0x00451F80)
#define ScreenPartialDump ((void __cdecl (*)(void))0x00451F90)
#define FadeToPal ((void __cdecl (*)(int32_t fade_value, RGB_888 *palette))0x00451FA0)
#define ScreenClear ((void __cdecl (*)(bool is_phd_win_size))0x00452170)
#define S_CopyScreenToBuffer ((void __cdecl (*)(void))0x004521A0)
#define S_CopyBufferToScreen ((void __cdecl (*)(void))0x00452250)
#define DecompPCX ((BOOL __cdecl (*)(const uint8_t *pcx, size_t pcx_size, LPBYTE pic, RGB_888 *pal))0x004522A0)
#define OpenGameRegistryKey ((bool __cdecl (*)(LPCTSTR key))0x004523C0)
#define CloseGameRegistryKey ((LONG __cdecl (*)(void))0x00452410)
#define SE_WriteAppSettings ((bool __cdecl (*)(APP_SETTINGS *settings))0x00452420)
#define SE_ReadAppSettings ((int32_t __cdecl (*)(APP_SETTINGS *settings))0x00452690)
#define SE_GraphicsTestStart ((bool __cdecl (*)(void))0x004529E0)
#define SE_GraphicsTestFinish ((void __cdecl (*)(void))0x00452AB0)
#define SE_GraphicsTestExecute ((int32_t __cdecl (*)(void))0x00452AD0)
#define SE_GraphicsTest ((int32_t __cdecl (*)(void))0x00452AE0)
#define SE_SoundTestStart ((bool __cdecl (*)(void))0x00452B40)
#define SE_SoundTestFinish ((void __cdecl (*)(void))0x00452C00)
#define SE_SoundTestExecute ((int32_t __cdecl (*)(void))0x00452C10)
#define SE_SoundTest ((int32_t __cdecl (*)(void))0x00452C50)
#define SE_PropSheetCallback ((int32_t __stdcall (*)(HWND hwndDlg, UINT uMsg, LPARAM lParam))0x00452CB0)
#define SE_NewPropSheetWndProc ((LRESULT __stdcall (*)(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam))0x00452CF0)
#define SE_ShowSetupDialog ((bool __cdecl (*)(HWND hParent, bool isDefault))0x00452D50)
#define SE_GraphicsDlgProc ((INT_PTR __stdcall (*)(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam))0x00453030)
#define SE_GraphicsDlgFullScreenModesUpdate ((void __cdecl (*)(HWND hwndDlg))0x004533F0)
#define SE_GraphicsAdapterSet ((void __cdecl (*)(HWND hwndDlg, DISPLAY_ADAPTER_NODE *adapter))0x004535E0)
#define SE_GraphicsDlgUpdate ((void __cdecl (*)(HWND hwndDlg))0x00453600)
#define SE_GraphicsDlgInit ((void __cdecl (*)(HWND hwndDlg))0x00453D40)
#define SE_SoundDlgProc ((INT_PTR __stdcall (*)(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam))0x00453EC0)
#define SE_SoundAdapterSet ((void __cdecl (*)(HWND hwndDlg, SOUND_ADAPTER_NODE *adapter))0x00454050)
#define SE_SoundDlgUpdate ((void __cdecl (*)(HWND hwndDlg))0x00454060)
#define SE_SoundDlgInit ((void __cdecl (*)(HWND hwndDlg))0x00454180)
#define SE_ControlsDlgProc ((INT_PTR __stdcall (*)(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam))0x00454240)
#define SE_ControlsJoystickSet ((void __cdecl (*)(HWND hwndDlg, JOYSTICK_NODE *joystick))0x00454350)
#define SE_ControlsDlgUpdate ((void __cdecl (*)(HWND hwndDlg))0x00454360)
#define SE_ControlsDlgInit ((void __cdecl (*)(HWND hwndDlg))0x004543D0)
#define SE_OptionsDlgProc ((INT_PTR __stdcall (*)(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam))0x00454490)
#define SE_OptionsDlgUpdate ((void __cdecl (*)(HWND hwndDlg))0x00454520)
#define SE_OptionsStrCat ((void __cdecl (*)(LPTSTR *dstString, bool isEnabled, bool *isNext, LPCTSTR srcString))0x00454760)
#define SE_AdvancedDlgProc ((INT_PTR __stdcall (*)(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam))0x004547B0)
#define SE_AdvancedDlgUpdate ((void __cdecl (*)(HWND hwndDlg))0x004548B0)
#define SE_AdvancedDlgInit ((void __cdecl (*)(HWND hwndDlg))0x00454950)
#define SE_FindSetupDialog ((HWND __cdecl (*)(void))0x00454960)
#define CheckCheatMode ((void __cdecl (*)(void))0x00454D60)
#define CopyBitmapPalette ((void __cdecl (*)(RGB_888 *src_pal, BYTE *src_bitmap, int32_t bitmap_size, RGB_888 *dest_pal))0x004557A0)
#define FindNearestPaletteEntry ((BYTE __cdecl (*)(RGB_888 *palette, int32_t red, int32_t green, int32_t blue, bool ignore_sys_palette))0x004558E0)
#define SyncSurfacePalettes ((void __cdecl (*)(void *src_data, int32_t width, int32_t height, int32_t src_pitch, RGB_888 *src_palette, void *dst_data, int32_t dst_pitch, RGB_888 *dst_palette, bool preserve_sys_palette))0x004559B0)
#define CreateTexturePalette ((int32_t __cdecl (*)(const RGB_888 *pal))0x00455A60)
#define GetFreePaletteIndex ((int32_t __cdecl (*)(void))0x00455AF0)
#define FreePalette ((void __cdecl (*)(int32_t palette_idx))0x00455B10)
#define SafeFreePalette ((void __cdecl (*)(int32_t palette_idx))0x00455B40)
#define CreateTexturePage ((int32_t __cdecl (*)(int32_t width, int32_t height, bool alpha))0x00455B90)
#define GetFreeTexturePageIndex ((int32_t __cdecl (*)(void))0x00455C00)
#define CreateTexturePageSurface ((bool __cdecl (*)(TEXPAGE_DESC *desc))0x00455C20)
#define TexturePageInit ((bool __cdecl (*)(TEXPAGE_DESC *page))0x00455CC0)
#define Create3DTexture ((LPDIRECT3DTEXTURE2 __cdecl (*)(LPDDS surface))0x00455E40)
#define SafeFreeTexturePage ((void __cdecl (*)(int32_t page_idx))0x00455E70)
#define FreeTexturePage ((void __cdecl (*)(int32_t page_idx))0x00455E90)
#define TexturePageReleaseVidMemSurface ((void __cdecl (*)(TEXPAGE_DESC *page))0x00455ED0)
#define FreeTexturePages ((void __cdecl (*)(void))0x00455F10)
#define LoadTexturePage ((bool __cdecl (*)(int32_t page_idx, bool reset))0x00455F40)
#define ReloadTextures ((bool __cdecl (*)(bool reset))0x00455FF0)
#define GetTexturePageHandle ((HWR_TEXTURE_HANDLE __cdecl (*)(int32_t page_idx))0x00456030)
#define AddTexturePage8 ((int32_t __cdecl (*)(int32_t width, int32_t height, const uint8_t *page_buf, int32_t pal_idx))0x00456070)
#define AddTexturePage16 ((int32_t __cdecl (*)(int32_t width, int32_t height, const uint8_t *page_buf))0x00456170)
#define EnumTextureFormatsCallback ((HRESULT __stdcall (*)(LPDDSDESC lpDdsd, LPVOID lpContext))0x00456310)
#define EnumerateTextureFormats ((HRESULT __cdecl (*)(void))0x00456430)
#define CleanupTextures ((void __cdecl (*)(void))0x00456460)
#define InitTextures ((bool __cdecl (*)(void))0x00456470)
#define UpdateTicks ((void __cdecl (*)(void))0x00456490)
#define TIME_Init ((bool __cdecl (*)(void))0x004564D0)
#define Sync ((DWORD __cdecl (*)(void))0x00456530)
#define UT_LoadResource ((LPVOID __cdecl (*)(LPCTSTR lpName, LPCTSTR lpType))0x00456590)
#define UT_InitAccurateTimer ((void __cdecl (*)(void))0x004565D0)
#define UT_Microseconds ((double __cdecl (*)(void))0x00456630)
#define UT_CenterWindow ((BOOL __cdecl (*)(HWND hWnd))0x00456680)
#define UT_FindArg ((LPTSTR __cdecl (*)(LPCTSTR str))0x004566F0)
#define UT_MessageBox ((int32_t __cdecl (*)(LPCTSTR lpText, HWND hWnd))0x00456720)
#define UT_ErrorBox ((int32_t __cdecl (*)(UINT uID, HWND hWnd))0x00456740)
#define GuidBinaryToString ((LPCTSTR __cdecl (*)(GUID *guid))0x00456790)
#define GuidStringToBinary ((bool __cdecl (*)(LPCTSTR lpString, GUID *guid))0x004567F0)
#define OpenRegistryKey ((BOOL __cdecl (*)(LPCTSTR lpSubKey))0x004568A0)
#define IsNewRegistryKeyCreated ((bool __cdecl (*)(void))0x004568D0)
#define CloseRegistryKey ((LONG __cdecl (*)(void))0x004568E0)
#define SetRegistryDwordValue ((LONG __cdecl (*)(LPCTSTR lpValueName, DWORD value))0x004568F0)
#define SetRegistryBoolValue ((LONG __cdecl (*)(LPCTSTR lpValueName, bool value))0x00456910)
#define SetRegistryFloatValue ((LONG __cdecl (*)(LPCTSTR lpValueName, double value))0x00456940)
#define SetRegistryBinaryValue ((LONG __cdecl (*)(LPCTSTR lpValueName, LPBYTE value, DWORD valueSize))0x00456980)
#define SetRegistryStringValue ((LONG __cdecl (*)(LPCTSTR lpValueName, LPCTSTR value, int32_t length))0x004569C0)
#define DeleteRegistryValue ((LONG __cdecl (*)(LPCTSTR lpValueName))0x00456A10)
#define GetRegistryDwordValue ((bool __cdecl (*)(LPCTSTR lpValueName, DWORD *pValue, DWORD defaultValue))0x00456A30)
#define GetRegistryBoolValue ((bool __cdecl (*)(LPCTSTR lpValueName, bool *pValue, bool defaultValue))0x00456A90)
#define GetRegistryFloatValue ((bool __cdecl (*)(LPCTSTR lpValueName, double *value, double defaultValue))0x00456B10)
#define GetRegistryBinaryValue ((bool __cdecl (*)(LPCTSTR lpValueName, LPBYTE value, DWORD valueSize, LPBYTE defaultValue))0x00456B70)
#define GetRegistryStringValue ((bool __cdecl (*)(LPCTSTR lpValueName, LPTSTR value, DWORD maxSize, LPCTSTR defaultValue))0x00456BF0)
#define GetRegistryGuidValue ((bool __cdecl (*)(LPCTSTR lpValueName, GUID *value, GUID *defaultValue))0x00456C90)
#define SE_ReleaseBitmapResource ((void __thiscall (*)(BITMAP_RESOURCE *bmpRsrc))0x00456D30)
#define SE_LoadBitmapResource ((void __thiscall (*)(BITMAP_RESOURCE *bmpRsrc, LPCTSTR lpName))0x00456D70)
#define SE_DrawBitmap ((void __thiscall (*)(BITMAP_RESOURCE *bmpRsrc, HDC hdc, int32_t x, int32_t y))0x00456E40)
#define SE_UpdateBitmapPalette ((void __thiscall (*)(BITMAP_RESOURCE *bmpRsrc, HWND hWnd, HWND hSender))0x00456EB0)
#define SE_ChangeBitmapPalette ((void __thiscall (*)(BITMAP_RESOURCE *bmpRsrc, HWND hWnd))0x00456ED0)
#define SE_RegisterSetupWindowClass ((bool __cdecl (*)(void))0x00456F30)
#define SE_SetupWindowProc ((LRESULT __stdcall (*)(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam))0x00456FA0)
#define SE_PassMessageToImage ((void __cdecl (*)(HWND hWnd, UINT uMsg, WPARAM wParam))0x004571E0)
#define UT_MemBlt ((void __cdecl (*)(BYTE *dstBuf, DWORD dstX, DWORD dstY, DWORD width, DWORD height, DWORD dstPitch, BYTE *srcBuf, DWORD srcX, DWORD srcY, DWORD srcPitch))0x00457210)
// clang-format on
