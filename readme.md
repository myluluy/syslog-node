# syslognode

通过调用syslog发送系统日志

## 安装 
```bash
$ npm install @myluluy/syslognode
```
## API
Syslog.syslog(ident, option, facility, priority, format`)

## 参数
 * @param {string} ident  - idents指向的字符串可以是想要打出的任意字符，它所表示的字符串将固定地加在每行日志的前面以标识这个日志，该标志通常设置为程序的名称
 * @param {number} option - option参数所指定的标志用来控制openlog()操作和syslog()的后续调用
 * @param {number} facility - facility参数是用来指定记录消息程序的类型。
 * @param {number} priority - 指定日志等级。
 * @param {string} format - 日志的内容。

## 使用
```js
    let Syslog = require('@myluluy/syslognode')
    Syslog.syslog('xx-xx', Syslog.option.LOG_PID, Syslog.facility.LOG_USER, Syslog.priority.LOG_NOTICE, 'log message')
});

```

## License
MIT license
