#include <iostream>

#include <nan.h>
#include "sync.h"
#include "async.h"

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::String;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;

using v8::FunctionCallbackInfo;
using v8::Value;

using namespace std;


void Hello(const v8::FunctionCallbackInfo<v8::Value>& args) {
  cout << "Hello node-gyp(cout)" << endl;
}

// Expose synchronous and asynchronous access to our
// Estimate() function
NAN_MODULE_INIT(InitAll) {
  Set(target, New<String>("calculateSync").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(CalculateSync)).ToLocalChecked());

  Set(target, New<String>("calculateAsync").ToLocalChecked(),
    GetFunction(New<FunctionTemplate>(CalculateAsync)).ToLocalChecked());

  NODE_SET_METHOD(target, "hello", Hello);
}

NODE_MODULE(addon, InitAll)
