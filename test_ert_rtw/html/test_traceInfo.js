function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "test"};
	this.sidHashMap["test"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/Digital Output"] = {sid: "test:2"};
	this.sidHashMap["test:2"] = {rtwname: "<Root>/Digital Output"};
	this.rtwnameHashMap["<Root>/Pulse Generator"] = {sid: "test:1"};
	this.sidHashMap["test:1"] = {rtwname: "<Root>/Pulse Generator"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
