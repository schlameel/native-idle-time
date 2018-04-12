////////////////////////////////////////////////////////////////
// native-idle-time_linux.cc
//   @fileOverview Linux specific code to get user idle time
//   @author Schlameel
//   @copyright Schlameel
//   @version 1.0.0
//   @license MIT
////////////////////////////////////////////////////////////////

#include <X11/extensions/scrnsaver.h>

// Returns the X windows user idle time in milliseconds
int32_t native_idle_millis() {
  static Display *dpy = XOpenDisplay(NULL);
  static XScreenSaverInfo *info = XScreenSaverAllocInfo();

  if (!dpy) {
    return -1;
  }

  XScreenSaverQueryInfo(dpy, DefaultRootWindow(dpy), info);

  return (int32_t)info->idle;
}
