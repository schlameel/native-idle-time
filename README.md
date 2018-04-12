# native-idle-time
#### Cross platform NodeJS addon to get user idle time.

native-idle-time queries the native windowing system (Windows, X, macOS) for
the user's idle time, providing the number of milliseconds the user has been
idle.  The idle time is the same that is used to launch screensavers.

## Install
```bash
npm install native-idle-time
```

## Usage
```javascript
const idleTime = require('native-idle-time')

setTimeout(() => {
  var millis = idleTime.getMillis()
  console.log(`User idle time: ${millis}ms`)
}, 1000)
```

## License
[MIT](https://opensource.org/licenses/MIT)
