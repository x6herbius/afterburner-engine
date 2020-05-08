#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _SurfaceProp SurfaceProp;

// These functions are a C-ified interface to the footstep resources.
int PMRes_GetStepSoundIdForSurface(SurfaceProp surfaceProp);
int PMRes_GetStepSoundIdForWater(int deepWater);
int PMRes_GetSwimSoundId(void);
float PMRes_GetStepSoundVolumeMultiplierForSurface(SurfaceProp surfaceProp, int walking);
const char* PMRes_GetStepSoundPath(int stepSoundId, int isLeftFoot);

#ifdef __cplusplus
}
#endif
