# native-idle-time
#### Cross platform NodeJS addon to get user idle time.

native-idle-time queries the native windowing system (Windows, X, macOS) for
the user's idle time, providing the number of milliseconds the user has been
idle.  The idle time is the same that is used to launch screensavers.

## Install
```bash
npm install native-idle-time
```

### Note
```npm``` will try to install a binary version of the addon from Github.  If a
binary does not exist for your platform, ```npm``` will try to build the addon.  
Installing in Linux may require ```libxss-dev``` and npm package ```nan```. If
you are trying to build the addon and it fails with the error message:
```bash
 ../native-idle-time_linux.cc:10:38: fatal error: X11/extensions/scrnsaver.h: No such file or directory
```
then install ```libxss-dev``` with the following:
```bash
sudo apt-get install libxss-dev
```
If you get the error:
```bash
Error: Cannot find module 'nan'
```
then use ```npm``` to install ```nan``` with:
```bash
npm install nan
```

## Usage
```javascript
const idleTime = require('native-idle-time')

setTimeout(() => {
  var millis = idleTime.getMillis()
  console.log(`User idle time: ${millis}ms`)
}, 1000)
```

## API

### native_idle_time.getMillis

Example: ```let millis = native_idle_time.getMillis()```

Returns the time, in milliseconds, the system has gone without user input. If
the addon cannot determine the time (no DISPLAY, ssh session, etc.), ```-1``` is returned.

## License
[MIT](https://opensource.org/licenses/MIT)
