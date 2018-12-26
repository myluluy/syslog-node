let syslog = require('../build/Release/syslog').syslog
let n = Date.now();
 for(let i = 0; i< 5; i++) {
  syslog('test tag', 'LOG_PID', 'LOG_LOCAL5', 'LOG_ERR', 'test message')
}
console.log(Date.now() - n)