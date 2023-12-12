function TraceInfoFlag() {
    this.traceFlag = new Array();
    this.traceFlag["test.c:31c49"]=1;
    this.traceFlag["test.c:31c55"]=1;
    this.traceFlag["test.c:31c81"]=1;
    this.traceFlag["test.c:33c29"]=1;
    this.traceFlag["test.c:36c26"]=1;
    this.traceFlag["test.c:44c40"]=1;
    this.traceFlag["test.c:65c26"]=1;
    this.traceFlag["test.c:66c26"]=1;
}
top.TraceInfoFlag.instance = new TraceInfoFlag();
function TraceInfoLineFlag() {
    this.lineTraceFlag = new Array();
    this.lineTraceFlag["test.c:31"]=1;
    this.lineTraceFlag["test.c:32"]=1;
    this.lineTraceFlag["test.c:33"]=1;
    this.lineTraceFlag["test.c:34"]=1;
    this.lineTraceFlag["test.c:36"]=1;
    this.lineTraceFlag["test.c:42"]=1;
    this.lineTraceFlag["test.c:43"]=1;
    this.lineTraceFlag["test.c:44"]=1;
    this.lineTraceFlag["test.c:45"]=1;
    this.lineTraceFlag["test.c:61"]=1;
    this.lineTraceFlag["test.c:64"]=1;
    this.lineTraceFlag["test.c:65"]=1;
    this.lineTraceFlag["test.c:66"]=1;
    this.lineTraceFlag["test.c:67"]=1;
}
top.TraceInfoLineFlag.instance = new TraceInfoLineFlag();
