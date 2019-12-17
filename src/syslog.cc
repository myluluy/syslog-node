
#include <node.h>
// #include <uv.h>
#include <syslog.h>
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
  openlog(ident, option, facility);
  syslog(priority, "%s", format);
  closelog();

}

void JsOpenlog(const FunctionCallbackInfo<Value>& args) {
  
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
    obj->Set(String::NewFromUtf8(isolate, "LOG_PID"), v8::Number::New(isolate, LOG_PID));
    obj->Set(String::NewFromUtf8(isolate, "LOG_CONS"), v8::Number::New(isolate, LOG_CONS));
    obj->Set(String::NewFromUtf8(isolate, "LOG_ODELAY"), v8::Number::New(isolate, LOG_ODELAY));
    obj->Set(String::NewFromUtf8(isolate, "LOG_NDELAY"), v8::Number::New(isolate, LOG_NDELAY));
    obj->Set(String::NewFromUtf8(isolate, "LOG_NOWAIT"), v8::Number::New(isolate, LOG_NOWAIT));
    obj->Set(String::NewFromUtf8(isolate, "LOG_PERROR"), v8::Number::New(isolate, LOG_PERROR));
    args.GetReturnValue().Set(obj);
}

void Facility (const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<v8::Object> obj = v8::Object::New(isolate);
    obj->Set(String::NewFromUtf8(isolate, "LOG_KERN"), v8::Number::New(isolate, LOG_KERN));
    obj->Set(String::NewFromUtf8(isolate, "LOG_USER"), v8::Number::New(isolate, LOG_USER));
    obj->Set(String::NewFromUtf8(isolate, "LOG_MAIL"), v8::Number::New(isolate, LOG_MAIL));
    obj->Set(String::NewFromUtf8(isolate, "LOG_DAEMON"), v8::Number::New(isolate, LOG_DAEMON));
    obj->Set(String::NewFromUtf8(isolate, "LOG_AUTH"), v8::Number::New(isolate, LOG_AUTH));
    obj->Set(String::NewFromUtf8(isolate, "LOG_SYSLOG"), v8::Number::New(isolate, LOG_SYSLOG));
    obj->Set(String::NewFromUtf8(isolate, "LOG_LPR"), v8::Number::New(isolate, LOG_LPR));
    obj->Set(String::NewFromUtf8(isolate, "LOG_NEWS"), v8::Number::New(isolate, LOG_NEWS));
    obj->Set(String::NewFromUtf8(isolate, "LOG_UUCP"), v8::Number::New(isolate, LOG_UUCP));
    obj->Set(String::NewFromUtf8(isolate, "LOG_CRON"), v8::Number::New(isolate, LOG_CRON));
    obj->Set(String::NewFromUtf8(isolate, "LOG_AUTHPRIV"), v8::Number::New(isolate, LOG_AUTHPRIV));
    obj->Set(String::NewFromUtf8(isolate, "LOG_FTP"), v8::Number::New(isolate, LOG_FTP));
    // obj->Set(String::NewFromUtf8(isolate, "LOG_NETINFO"), v8::Number::New(isolate, LOG_NETINFO));
    // obj->Set(String::NewFromUtf8(isolate, "LOG_REMOTEAUTH"), v8::Number::New(isolate, LOG_REMOTEAUTH));
    // obj->Set(String::NewFromUtf8(isolate, "LOG_INSTALL"), v8::Number::New(isolate, LOG_INSTALL));
    // obj->Set(String::NewFromUtf8(isolate, "LOG_RAS"), v8::Number::New(isolate, LOG_RAS));
    obj->Set(String::NewFromUtf8(isolate, "LOG_LOCAL0"), v8::Number::New(isolate, LOG_LOCAL0));
    obj->Set(String::NewFromUtf8(isolate, "LOG_LOCAL1"), v8::Number::New(isolate, LOG_LOCAL1));
    obj->Set(String::NewFromUtf8(isolate, "LOG_LOCAL2"), v8::Number::New(isolate, LOG_LOCAL2));
    obj->Set(String::NewFromUtf8(isolate, "LOG_LOCAL3"), v8::Number::New(isolate, LOG_LOCAL3));
    obj->Set(String::NewFromUtf8(isolate, "LOG_LOCAL4"), v8::Number::New(isolate, LOG_LOCAL4));
    obj->Set(String::NewFromUtf8(isolate, "LOG_LOCAL5"), v8::Number::New(isolate, LOG_LOCAL5));
    obj->Set(String::NewFromUtf8(isolate, "LOG_LOCAL6"), v8::Number::New(isolate, LOG_LOCAL6));
    obj->Set(String::NewFromUtf8(isolate, "LOG_LOCAL7"), v8::Number::New(isolate, LOG_LOCAL7));
    // obj->Set(String::NewFromUtf8(isolate, "LOG_LAUNCHD"), v8::Number::New(isolate, LOG_LAUNCHD));
    // obj->Set(String::NewFromUtf8(isolate, "LOG_NFACILITIES"), v8::Number::New(isolate, LOG_NFACILITIES));
    // obj->Set(String::NewFromUtf8(isolate, "LOG_FACMASK"), v8::Number::New(isolate, LOG_FACMASK));
    args.GetReturnValue().Set(obj);
}
void Priority (const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    Local<v8::Object> obj = v8::Object::New(isolate);
    obj->Set(String::NewFromUtf8(isolate, "LOG_EMERG"), v8::Number::New(isolate, LOG_EMERG));
    obj->Set(String::NewFromUtf8(isolate, "LOG_ALERT"), v8::Number::New(isolate, LOG_ALERT));
    obj->Set(String::NewFromUtf8(isolate, "LOG_CRIT"), v8::Number::New(isolate, LOG_CRIT));
    obj->Set(String::NewFromUtf8(isolate, "LOG_ERR"), v8::Number::New(isolate, LOG_ERR));
    obj->Set(String::NewFromUtf8(isolate, "LOG_WARNING"), v8::Number::New(isolate, LOG_WARNING));
    obj->Set(String::NewFromUtf8(isolate, "LOG_NOTICE"), v8::Number::New(isolate, LOG_NOTICE));
    obj->Set(String::NewFromUtf8(isolate, "LOG_INFO"), v8::Number::New(isolate, LOG_INFO));
    obj->Set(String::NewFromUtf8(isolate, "LOG_DEBUG"), v8::Number::New(isolate, LOG_DEBUG));
    args.GetReturnValue().Set(obj); 
}

void init(Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "option", Option);
  NODE_SET_METHOD(exports, "facility", Facility);
  NODE_SET_METHOD(exports, "priority", Priority);
  NODE_SET_METHOD(exports, "syslog", WriteSyslog);
}
 
NODE_MODULE(Syslog, init);