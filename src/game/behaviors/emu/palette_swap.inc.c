#include "levels/bitdw/header.h"
#include "levels/bowser_1/header.h"

// This accounts for both the first and second u8 entries
#define COLOR_INDEX(_x) _x*2, _x*2+1

// Color count is actually color count*2, since u16 is stored as two u8
#define COLOR_COUNT 12

u8* vein_rock;

u8 swapSlots[COLOR_COUNT];

/*******Labeled indecies***********
    COLOR_INDEX(5), //some gray 5
    *COLOR_INDEX(6), //orange 6
    COLOR_INDEX(8), // some gray 8
    COLOR_INDEX(9), //yellow 9
    COLOR_INDEX(11),//blue 11
    *COLOR_INDEX(10), //green 10
    *COLOR_INDEX(9), //light orange 9
    COLOR_INDEX(4), //red 4
*/
u8 indices[] = {
    COLOR_INDEX(4),
    COLOR_INDEX(6),
    COLOR_INDEX(8),
    COLOR_INDEX(9),
    COLOR_INDEX(10),
    COLOR_INDEX(11),
};
void palette_swap_init(void){
    if( gMarioState->pos[0] == 0.0 &&
        gMarioState->pos[1] == 0.0 &&
        gMarioState->pos[2] == 0.0 ){
    set_mario_action(gMarioState, ACT_FREEFALL, 0);
    gMarioState->pos[0] = 9566;
    gMarioState->pos[1] = -8006;
    gMarioState->pos[2] = 8940;
        }
        if (gSpeedrun.active) gSpeedrun.enabled = TRUE;
}
void palette_swap(void){
    if (gCurrLevelNum == LEVEL_BITDW){
        if (o->oTimer == 0) {
            vein_rock = segmented_to_virtual(bitdw_dl_scrolling_texture_ci4_pal_rgba16);
        }
    }
     else if (gCurrLevelNum == LEVEL_BOWSER_1){
        if (o->oTimer == 0) {
            vein_rock = segmented_to_virtual(bowser_1_dl_scrolling_texture_ci4_pal_rgba16);
        }
    }
    if (o->oTimer % 6 == 0) {
        s32 i;
        s32 index;
        
        for (i = 0; i < COLOR_COUNT; i++) {
            index = (i+2)%COLOR_COUNT;
            swapSlots[index] = vein_rock[indices[i]];
        }

        for(i = 0; i < COLOR_COUNT; i++) {
            vein_rock[indices[i]] = swapSlots[i];
        }
    }
}
