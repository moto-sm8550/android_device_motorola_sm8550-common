#include <log/log.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <utils/Errors.h>
#include <unistd.h>

#include "libMotoPanelFeature.h"

#define LOG_TAG "MotoPanelFeature"

int writeToPanelIoctl(panel_param_info paramInfo) {
    int fd = open(DRM_IOCTL_PATH, O_RDWR);
    if(fd < 0) {
        ALOGE("Error opening IOCTL %s: %s", DRM_IOCTL_PATH, strerror(errno));
        return errno;
    }

    int ret = ioctl(fd, DRM_SET_PANEL_FEATURE, &paramInfo);
    if(ret < 0) {
        ALOGE("Falling back to stock DRM_SET_PANEL_FEATURE value");
        ret = ioctl(fd, 0xc008649f, &paramInfo);
    }

    close(fd);
    return ret;
}

int setHbmState(bool enabled) {
    struct panel_param_info paramInfo;
    paramInfo.param_idx = PARAM_HBM;
    paramInfo.value = (enabled ? HBM_ON_STATE : HBM_OFF_STATE);

    return writeToPanelIoctl(paramInfo);
}

int setFodHbmState(bool enabled) {
    struct panel_param_info paramInfo;
    paramInfo.param_idx = PARAM_HBM;
    paramInfo.value = (enabled ? HBM_FOD_ON_STATE : HBM_OFF_STATE);

    return writeToPanelIoctl(paramInfo);
}

int setDCState(bool enabled) {
    struct panel_param_info paramInfo;
    paramInfo.param_idx = PARAM_HBM;
    paramInfo.value = (enabled ? DC_ON_STATE : DC_OFF_STATE);

    return writeToPanelIoctl(paramInfo);
}

