let syslog = require('../build/Release/syslog')
let n = Date.now();
console.log(syslog);
syslog.syslog('test tag', syslog.option().LOG_PID, syslog.facility().LOG_USER, syslog.priority().LOG_ERR, 'test message');
// for(let i = 0; i< 1000; i++) {
//   syslog('test tag', 'LOG_PID', 'LOG_LOCAL5', 'LOG_ERR', 'test message', (res)=> {
//   })
// }
// console.log(Date.now() - n)
// let m = Date.now();
// for(let i = 0; i< 1000; i++) {
//     console.log('====')
// }
// console.log(Date.now() - m)