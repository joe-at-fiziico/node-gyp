#include <nan.h>
#include "sync.h"

// external library
#include "qos.h"

// Simple synchronous access to the `Estimate()` function
NAN_METHOD(CalculateSync) {
  // expect a number as the first argument
  int points = info[0]->Uint32Value();
  double est = Estimate(points);

  info.GetReturnValue().Set(est);
}
