let Syslog = require('../../build/Release/syslog')

const option = {
    LOG_PID     :      0x01,    /* log the pid with each message */
    LOG_CONS    :      0x02,    /* log on the console if errors in sending */
    LOG_ODELAY  :      0x04,    /* delay open until first syslog() (default) */
    LOG_NDELAY  :      0x08,   /* don't delay open */
    LOG_NOWAIT  :      0x10,    /* don't wait for console forks: DEPRECATED */
    LOG_PERROR  :      0x20    /* log to stderr as well */
}

const facility = {
    LOG_KERN        : (0<<3) , /* kernel messages */
    LOG_USER        : (1<<3) , /* random user-level messages */
    LOG_MAIL        : (2<<3) , /* mail system */
    LOG_DAEMON      : (3<<3) , /* system daemons */
    LOG_AUTH        : (4<<3) , /* authorization messages */
    LOG_SYSLOG      : (5<<3) , /* messages generated internally by syslogd */
    LOG_LPR         : (6<<3) , /* line printer subsystem */
    LOG_NEWS        : (7<<3) , /* network news subsystem */
    LOG_UUCP        : (8<<3) , /* UUCP subsystem */
    LOG_CRON        : (9<<3) , /* clock daemon */
    LOG_AUTHPRIV    : (10<<3), /* authorization messages (private) */
    LOG_FTP         : (11<<3), /* ftp daemon */
    LOG_NETINFO     : (12<<3), /* NetInfo */
    LOG_REMOTEAUTH  : (13<<3), /* remote authentication/authorization */
    LOG_INSTALL     : (14<<3), /* installer subsystem */
    LOG_RAS         : (15<<3), /* Remote Access Service (VPN / PPP) */
    LOG_LOCAL0      : (16<<3), /* reserved for local use */
    LOG_LOCAL1      : (17<<3), /* reserved for local use */
    LOG_LOCAL2      : (18<<3), /* reserved for local use */
    LOG_LOCAL3      : (19<<3), /* reserved for local use */
    LOG_LOCAL4      : (20<<3), /* reserved for local use */
    LOG_LOCAL5      : (21<<3), /* reserved for local use */
    LOG_LOCAL6      : (22<<3), /* reserved for local use */
    LOG_LOCAL7      : (23<<3) /* reserved for local use */
}

const priority = {
    LOG_EMERG       : 0,       /* system is unusable */
    LOG_ALERT       : 1,       /* action must be taken immediately */
    LOG_CRIT        : 2,       /* critical conditions */
    LOG_ERR         : 3,       /* error conditions */
    LOG_WARNING     : 4,       /* warning conditions */
    LOG_NOTICE      : 5,       /* normal but significant condition */
    LOG_INFO        : 6,       /* informational */
    LOG_DEBUG       : 7       /* debug-level messages */
}
/**
 * 
 * @param {string} ident  - idents指向的字符串可以是想要打出的任意字符，它所表示的字符串将固定地加在每行日志的前面以标识这个日志，该标志通常设置为程序的名称
 * @param {number} option - option参数所指定的标志用来控制openlog()操作和syslog()的后续调用
 * @param {number} facility - facility参数是用来指定记录消息程序的类型。
 * @param {number} priority - 指定日志等级。
 * @param {string} format - 日志的内容。
 */
function syslog (ident, option, facility, priority, format) {
    // if(isNaN(option) || isNaN(facility) || isNaN(priority) || typeof ident !== 'string' || typeof format !== 'string') {
    //     throw Error('参数格式错误')
    // }
    Syslog.syslog(ident, option, facility, priority, format);
}

module.exports = {
    syslog,
    option,
    facility,
    priority
}