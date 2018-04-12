////////////////////////////////////////////////////////////////
// native-idle-time_windows.cc
//   @fileOverview Windows specific code to get system idle time
//   @author Schlameel
//   @copyright Schlameel
//   @version 1.0.0
//   @license MIT
////////////////////////////////////////////////////////////////

#ifndef _WIN32_WINNT
#define _WIN32_WINNT  0x0500
#endif
#ifndef WINVER
#define WINVER        0x0500
#endif
#include <windows.h>
#pragma comment(lib, "user32.lib")

// Returns the macOS user idle time in milliseconds
int32_t native_idle_millis() {
  int32_t tickCount;
  int32_t idleCount;
  LASTINPUTINFO lpi;
  lpi.cbSize = sizeof(LASTINPUTINFO);

  if (!GetLastInputInfo(&lpi))
  {
    return -1;
  }
  tickCount = GetTickCount();
  return tickCount - lpi.dwTime;
}
