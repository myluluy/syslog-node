
#include <string>
#include <node.h>
#include <uv.h>
#include <syslog.h>
 
 
using v8::FunctionCallbackInfo;
using v8::Function;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Array;
struct  reqData {
  uv_work_t req;
  char* ident;
  int option;
  int facility;
  int priority;
  char* format;
  v8::Persistent<Function> callback;
};

int GetOption( std::string option) {
  int _option;
  if(option == "LOG_CONS"){
    _option = LOG_CONS;
  }
  if(option == "LOG_NDELAY"){
    _option = LOG_NDELAY;
  }
  if(option == "LOG_PERROR"){
    _option = LOG_PERROR;
  }
  if(option == "LOG_PID"){
    _option = LOG_PID;
  }
  return _option;
}

int GetFacility ( std::string facility) {
  int _facility;
  if(facility == "LOG_AUTH"){
    _facility = LOG_AUTH;
  }
  if(facility == "LOG_AUTHPRIV") {
    _facility = LOG_AUTHPRIV;
  }
  if(facility == "LOG_CRON") {
    _facility = LOG_CRON;
  }
  if(facility == "LOG_DAEMON"){
    _facility = LOG_DAEMON;
  }
  if(facility ==  "LOG_KERN"){
    _facility = LOG_KERN;
  }
  if(facility == "LOG_LOCAL0"){
    _facility = LOG_LOCAL0;
  }
  if(facility == "LOG_LOCAL1"){
    _facility = LOG_LOCAL1;
  }

  if(facility == "LOG_LOCAL2"){
    _facility = LOG_LOCAL2;
  }

  if(facility == "LOG_LOCAL3"){
    _facility = LOG_LOCAL3;
  }

  if(facility == "LOG_LOCAL4"){
    _facility = LOG_LOCAL4;
  }

  if(facility == "LOG_LOCAL5"){
    _facility = LOG_LOCAL5;
  }

  if(facility == "LOG_LOCAL6"){
    _facility = LOG_LOCAL6;
  }

  if(facility == "LOG_LOCAL7"){
    _facility = LOG_LOCAL7;
  }
  if(facility == "LOG_LPR"){
    _facility = LOG_LPR;
  }
  if(facility == "LOG_MAIL"){
    _facility = LOG_MAIL;
  }
  if(facility == "LOG_NEWS") {
    _facility = LOG_NEWS;
  }
  if(facility == "LOG_SYSLOG"){
    _facility = LOG_SYSLOG;
  }
  if(facility == "LOG_USER"){
    _facility = LOG_USER;
  }
  if(facility == "LOG_UUCP") {
    _facility = LOG_UUCP;
  }
  return _facility;
}

int GetPriority ( std::string priority) {
  int _priority;
  if(priority == "LOG_EMERG"){
    _priority = LOG_EMERG;
  }
  if (priority == "LOG_ALERT") {
    _priority = LOG_ALERT;
  }
  if(priority == "LOG_CRIT") {
    _priority = LOG_CRIT;
  }
  if(priority == "LOG_ERR") {
    _priority = LOG_ERR;
  }
  if(priority == "LOG_WARNING") {
    _priority = LOG_WARNING;
  }
  if(priority == "LOG_NOTICE") {
    _priority = LOG_NOTICE;
  }
  if(priority == "LOG_INFO") {
      _priority = LOG_INFO;
  }
  if(priority == "LOG_DEBUG") {
      _priority = LOG_DEBUG;
  }
  return _priority;
}

void Syslog( char* ident, int option, int facility,  int priority, char* format) {
  
  openlog(ident, option, facility);
  syslog(priority, format);
  closelog();
  // args.GetReturnValue().Set(String::NewFromUtf8(isolate, cFormat));

}
// void uv_syslog(uv_work_t *req) {
//   // Syslog(req->data);
//   reqData *request = static_cast<reqData *>(req->data);
//   Syslog(request->ident, request->option, request->facility, request->priority, request->format);
// }
// void uv_syslog_after(uv_work_t *req, int status) {
//   Isolate* isolate = Isolate::GetCurrent();
// 	v8::HandleScope scope(isolate);
//   reqData *request = static_cast<reqData *>(req->data);
//   const unsigned argc = 1;
//   Local<Array> res = Array::New(isolate);
//   Local<Value> argv[argc] = {res};
//   Local<Function> cb = Local<Function>::New(isolate, request->callback);
//   cb->Call(isolate->GetCurrentContext()->Global(), argc, argv);
//   delete request;
// 
// }
void AsyncSyslog(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  v8::HandleScope scope(isolate);
  v8::String::Utf8Value v8Ident(args[0]->ToString());
  v8::String::Utf8Value v8Option(args[1]->ToString());
  v8::String::Utf8Value v8Facility(args[2]->ToString());
  v8::String::Utf8Value v8Priority(args[3]->ToString());
  v8::String::Utf8Value v8Format(args[4]->ToString());
  Local<Function> cb = Local<Function>::Cast(args[5]);
  char *cIdent;
  char *cFormat;
  cIdent =  *v8Ident;
  std::string cOption(*v8Option);
  std::string cFacility(*v8Facility);
  std::string cPriority(*v8Priority);
  cFormat = *v8Format;
  int option = GetOption(cOption);
  int facility = GetFacility(cFacility);
  int priority = GetPriority(cPriority);
  reqData* request = new reqData;
  request->req.data = request;
  request->ident = cIdent;
  request->option = option;
  request->facility = facility;
  request->priority = priority;
  request->format = cFormat;
  request->callback.Reset(isolate, cb);
  // uv_work_t* req = new uv_work_t();
  //uv_queue_work(uv_default_loop(), &request->req, (uv_work_cb)uv_syslog, uv_syslog_after);
  Syslog(request->ident, request->option, request->facility, request->priority, request->format);
}

void init(Local<Object> exports) {
  // NODE_SET_METHOD(exports, "syslogAsync", Syslog);
  NODE_SET_METHOD(exports, "syslog", AsyncSyslog);
}
 
NODE_MODULE(returnValue, init);