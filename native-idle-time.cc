////////////////////////////////////////////////////////////////
// native-idle-time.cc
//   @fileOverview Node addon code to get native user idle time in milliseconds
//   @author Schlameel
//   @copyright Schlameel
//   @version 1.0.0
//   @license MIT
////////////////////////////////////////////////////////////////

#include <nan.h>

using namespace Nan;
using namespace v8;

#include "native-idle-time.h"

NAN_METHOD(getMillis) {

  int32_t millis = native_idle_millis();
  Local<Number> retval = Nan::New(millis);
  info.GetReturnValue().Set(retval);
}

NAN_MODULE_INIT(Init) {
  Nan::Set(target, New<String>("getMillis").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(getMillis)).ToLocalChecked());
}

NODE_MODULE(native_idle_time, Init)
