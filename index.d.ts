declare module '@myluluy/node-syslog' {
  function syslog(
    ident: string,
    option: number,
    facility: number,
    priority: number,
    format: string
  ): void;
  interface facility {
    LOG_KERN: number;
    LOG_USER: number;
    LOG_MAIL: number;
    LOG_DAEMON: number;
    LOG_AUTH: number;
    LOG_SYSLOG: number;
    LOG_LPR: number;
    LOG_NEWS: number;
    LOG_UUCP: number;
    LOG_CRON: number;
    LOG_AUTHPRIV: number;
    LOG_FTP: number;
    LOG_LOCAL0: number;
    LOG_LOCAL1: number;
    LOG_LOCAL2: number;
    LOG_LOCAL3: number;
    LOG_LOCAL4: number;
    LOG_LOCAL5: number;
    LOG_LOCAL6: number;
    LOG_LOCAL7: number;
  }
  interface options {
    LOG_PID: number;
    LOG_CONS: number;
    LOG_ODELAY: number;
    LOG_NDELAY: number;
    LOG_NOWAIT: number;
    LOG_PERROR: number;
  }
  interface priority {
    LOG_EMERG: number;
    LOG_ALERT: number;
    LOG_CRIT: number;
    LOG_ERR: number;
    LOG_WARNING: number;
    LOG_NOTICE: number;
    LOG_INFO: number;
    LOG_DEBUG: number;
  }
  let facility: facility;
  let options: options;
  let priority: priority;
}
