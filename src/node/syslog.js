let Syslog = require('../../build/Release/syslog')
let option = Syslog.option()
let facility = Syslog.facility()
let priority = Syslog.priority()
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