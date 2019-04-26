let Syslog = require('../')
Syslog.syslog('xx-xx', Syslog.option.LOG_PID, Syslog.facility.LOG_USER, Syslog.priority.LOG_NOTICE, 'log message111')
