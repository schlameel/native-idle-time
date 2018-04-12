////////////////////////////////////////////////////////////////
// native-idle-time_mac.cc
//   @fileOverview Mac specific code to get user idle time
//   @author Schlameel
//   @copyright Schlameel
//   @version 1.0.0
//   @license MIT
////////////////////////////////////////////////////////////////

#include <IOKit/IOKitLib.h>

// Returns the Windows user idle time in milliseconds
int32_t native_idle_millis() {
    int64_t idle = -1;
    io_iterator_t iter = 0;
    if (IOServiceGetMatchingServices(kIOMasterPortDefault, IOServiceMatching("IOHIDSystem"), &iter) == KERN_SUCCESS) {
        io_registry_entry_t entry = IOIteratorNext(iter);
        if (entry) {
            CFMutableDictionaryRef dict = NULL;
            if (IORegistryEntryCreateCFProperties(entry, &dict, kCFAllocatorDefault, 0) == KERN_SUCCESS) {
                CFNumberRef obj = CFDictionaryGetValue(dict, CFSTR("HIDIdleTime"));
                if (obj) {
                    int64_t nanoseconds = 0;
                    if (CFNumberGetValue(obj, kCFNumberSInt64Type, &nanoseconds)) {
                        idle = (nanoseconds >> 10); // Divide by 10^6 to convert from nanoseconds to millseconds.
                    }
                }
                CFRelease(dict);
            }
            IOObjectRelease(entry);
        }
        IOObjectRelease(iter);
    }
    return (int32_t)idlesecs;
}
