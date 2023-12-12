function CodeDefine() { 
this.def = new Array();
this.def["IsrOverrun"] = {file: "ert_main_c.html",line:21,type:"var"};
this.def["OverrunFlag"] = {file: "ert_main_c.html",line:22,type:"var"};
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:23,type:"fcn"};
this.def["stopRequested"] = {file: "ert_main_c.html",line:40,type:"var"};
this.def["main"] = {file: "ert_main_c.html",line:41,type:"fcn"};
this.def["rtDW"] = {file: "test_c.html",line:21,type:"var"};
this.def["rtM_"] = {file: "test_c.html",line:24,type:"var"};
this.def["rtM"] = {file: "test_c.html",line:25,type:"var"};
this.def["test_step"] = {file: "test_c.html",line:28,type:"fcn"};
this.def["test_initialize"] = {file: "test_c.html",line:49,type:"fcn"};
this.def["RT_MODEL"] = {file: "test_h.html",line:45,type:"type"};
this.def["DW"] = {file: "test_h.html",line:51,type:"type"};
this.def["errorStatus"] = {file: "test_h.html",line:55,type:"var"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:59,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["int64_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["uint64_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:73,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:74,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:75,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:76,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:77,type:"type"};
this.def["ulonglong_T"] = {file: "rtwtypes_h.html",line:78,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:79,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:80,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:81,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:102,type:"type"};
this.def["disableWatchdog"] = {file: "MW_c28xx_csl_c.html",line:6,type:"fcn"};
this.def["enable_interrupts"] = {file: "MW_c28xx_csl_c.html",line:14,type:"fcn"};
this.def["init_board"] = {file: "MW_c28xx_csl_c.html",line:21,type:"fcn"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["test_c.html"] = "../test.c";
	this.html2Root["test_c.html"] = "test_c.html";
	this.html2SrcPath["test_h.html"] = "../test.h";
	this.html2Root["test_h.html"] = "test_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["rtmodel_h.html"] = "../rtmodel.h";
	this.html2Root["rtmodel_h.html"] = "rtmodel_h.html";
	this.html2SrcPath["MW_c28xx_csl_c.html"] = "../MW_c28xx_csl.c";
	this.html2Root["MW_c28xx_csl_c.html"] = "MW_c28xx_csl_c.html";
	this.html2SrcPath["MW_c28xx_pie_h.html"] = "../MW_c28xx_pie.h";
	this.html2Root["MW_c28xx_pie_h.html"] = "MW_c28xx_pie_h.html";
	this.html2SrcPath["MW_target_hardware_resources_h.html"] = "../MW_target_hardware_resources.h";
	this.html2Root["MW_target_hardware_resources_h.html"] = "MW_target_hardware_resources_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","test_c.html","test_h.html","rtwtypes_h.html","rtmodel_h.html","MW_c28xx_csl_c.html","MW_c28xx_pie_h.html","MW_target_hardware_resources_h.html"];
