
#include "stdio.h"
#include <node.h>
// #include <uv.h>
using v8::FunctionCallbackInfo;
using v8::Function;
using v8::Isolate;
using v8::Local;
using v8::MaybeLocal;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Number;
struct  reqData {
  // uv_work_t req;
  char* ident;
  int option;
  int facility;
  int priority;
  char* format;
  // v8::Persistent<Function> callback;
};

// uv_loop_t *loop;

void Syslog( char* ident, int option, int facility,  int priority, char* format) {
  printf("%s", format);
}

// void Openlog(char* ident, int option, int facility) {
//   openlog(ident, option, facility);
// }
// void Closelog() {
//   closelog();
// }
 // void uv_syslog(uv_work_t *req) {
 //   reqData *request = static_cast<reqData *>(req->data);
 //   Syslog(request->ident, request->option, request->facility, request->priority, request->format);

 // }
 // void uv_syslog_after(uv_work_t *req, int status) {
 //   Isolate* isolate = Isolate::GetCurrent();
 // 	 v8::HandleScope scope(isolate);
 //   reqData *request = static_cast<reqData *>(req->data);
 //   const unsigned argc = 1;
 //   Local<Array> res = Array::New(isolate);
 //   Local<Value> argv[argc] = {res};
 //   Local<Function> cb = Local<Function>::New(isolate, request->callback);
 //   cb->Call(isolate->GetCurrentContext()->Global(), argc, argv);
 //   delete request;
 
 // }
void WriteSyslog(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  Local<v8::Context> context = isolate->GetCurrentContext();
  v8::HandleScope scope(isolate);
  v8::String::Utf8Value v8Ident(isolate, args[0]);
  Local<Number> v8Option = Local<Number>::Cast(args[1]);
  Local<Number> v8Facility = Local<Number>::Cast(args[2]);
  Local<Number> v8Priority = Local<Number>::Cast(args[3]);
  v8::String::Utf8Value v8Format(isolate,args[4]);
  // Local<Function> cb = Local<Function>::Cast(args[5]);
  char *cIdent;
  char *cFormat;
  cIdent =  *v8Ident;
  cFormat = *v8Format;
  double option = v8Option->NumberValue(context).FromMaybe(0);
  double facility = v8Facility->NumberValue(context).FromMaybe(0);
  double priority = v8Priority->NumberValue(context).FromMaybe(0);
  reqData* request = new reqData;
  // request->req.data = request;
  request->ident = cIdent;
  request->option = option;
  request->facility = facility;
  request->priority = priority;
  request->format = cFormat;
  // request->callback.Reset(isolate, cb);
  // uv_work_t* req = new uv_work_t();
  
  // loop = uv_default_loop();
  // uv_queue_work(loop, &request->req, uv_syslog, uv_syslog_after);
  Syslog(request->ident, request->option, request->facility, request->priority, request->format);
  delete request;
  // uv_run(loop, UV_RUN_DEFAULT);
  // uv_loop_close(loop);
}

void Option (const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<v8::Object> obj = v8::Object::New(isolate);
    args.GetReturnValue().Set(obj);
}

void Facility (const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<v8::Object> obj = v8::Object::New(isolate);
    args.GetReturnValue().Set(obj);
}
void Priority (const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<v8::Object> obj = v8::Object::New(isolate);
    args.GetReturnValue().Set(obj); 
}

void init(Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "option", Option);
  NODE_SET_METHOD(exports, "facility", Facility);
  NODE_SET_METHOD(exports, "priority", Priority);
  NODE_SET_METHOD(exports, "syslog", WriteSyslog);
}
 
NODE_MODULE(Syslog, init);