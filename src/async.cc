#include <nan.h>
#include "async.h"

// external library
#include "qos.h"

using v8::Function;
using v8::Local;
using v8::Number;
using v8::Value;
using Nan::AsyncQueueWorker;
using Nan::AsyncWorker;
using Nan::Callback;
using Nan::HandleScope;
using Nan::New;
using Nan::Null;
using Nan::To;

class PiWorker : public AsyncWorker {
 public:
  PiWorker(Callback *callback, int points)
    : AsyncWorker(callback), points(points), estimate(0) {}
  ~PiWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access V8, or V8 data structures
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute () {
    estimate = Estimate(points);
  }

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use V8 again
  void HandleOKCallback () {
    HandleScope scope;

    Local<Value> argv[] = {
        Null()
      , New<Number>(estimate)
    };

    callback->Call(2, argv);
  }

 private:
  int points;
  double estimate;
};

// Asynchronous access to the `Estimate()` function
NAN_METHOD(CalculateAsync) {
  int points = To<int>(info[0]).FromJust();
  Callback *callback = new Callback(info[1].As<Function>());

  AsyncQueueWorker(new PiWorker(callback, points));
}
