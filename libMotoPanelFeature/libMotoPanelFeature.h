#include <display/drm/sde_drm.h>

#define DRM_IOCTL_PATH "/dev/dri/card0"

enum hbm_state {
	HBM_OFF_STATE = 0,
	HBM_ON_STATE,
	HBM_FOD_ON_STATE,
	HBM_STATE_NUM
};

enum dc_state {
	DC_OFF_STATE = 0,
	DC_ON_STATE,
	DC_STATE_NUM,
};

/*
 * En/Disable HBM of the panel
 */
int setHbmState(bool enabled);

/*
 * En/Disable LHBM of the panel for the FOD
 */
int setFodHbmState(bool enabled);

/*
 * En/Disable DC of the panel
 */
int setDCState(bool enabled);

