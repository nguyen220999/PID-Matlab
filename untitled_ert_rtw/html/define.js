function CodeDefine() { 
this.def = new Array();
this.def["IsrOverrun"] = {file: "ert_main_c.html",line:19,type:"var"};
this.def["OverrunFlag"] = {file: "ert_main_c.html",line:20,type:"var"};
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:21,type:"fcn"};
this.def["stopRequested"] = {file: "ert_main_c.html",line:38,type:"var"};
this.def["main"] = {file: "ert_main_c.html",line:39,type:"fcn"};
this.def["untitled_B"] = {file: "untitled_c.html",line:20,type:"var"};
this.def["untitled_DW"] = {file: "untitled_c.html",line:23,type:"var"};
this.def["untitled_M_"] = {file: "untitled_c.html",line:26,type:"var"};
this.def["untitled_M"] = {file: "untitled_c.html",line:27,type:"var"};
this.def["untitled_step"] = {file: "untitled_c.html",line:30,type:"fcn"};
this.def["untitled_initialize"] = {file: "untitled_c.html",line:52,type:"fcn"};
this.def["untitled_terminate"] = {file: "untitled_c.html",line:78,type:"fcn"};
this.def["B_untitled_T"] = {file: "untitled_h.html",line:44,type:"type"};
this.def["DW_untitled_T"] = {file: "untitled_h.html",line:49,type:"type"};
this.def["PulseGenerator_Amp"] = {file: "untitled_h.html",line:53,type:"var"};
this.def["P_untitled_T"] = {file: "untitled_types_h.html",line:21,type:"type"};
this.def["RT_MODEL_untitled_T"] = {file: "untitled_types_h.html",line:24,type:"type"};
this.def["untitled_P"] = {file: "untitled_data_c.html",line:20,type:"var"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:59,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};
this.def["int64_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};
this.def["uint64_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:73,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:74,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:75,type:"type"};
this.def["ulonglong_T"] = {file: "rtwtypes_h.html",line:76,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:77,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:78,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:79,type:"type"};
this.def["creal32_T"] = {file: "rtwtypes_h.html",line:89,type:"type"};
this.def["creal64_T"] = {file: "rtwtypes_h.html",line:94,type:"type"};
this.def["creal_T"] = {file: "rtwtypes_h.html",line:99,type:"type"};
this.def["cint8_T"] = {file: "rtwtypes_h.html",line:106,type:"type"};
this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:113,type:"type"};
this.def["cint16_T"] = {file: "rtwtypes_h.html",line:120,type:"type"};
this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:127,type:"type"};
this.def["cint32_T"] = {file: "rtwtypes_h.html",line:134,type:"type"};
this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:141,type:"type"};
this.def["cint64_T"] = {file: "rtwtypes_h.html",line:148,type:"type"};
this.def["cuint64_T"] = {file: "rtwtypes_h.html",line:155,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:176,type:"type"};
this.def["disableWatchdog"] = {file: "MW_c28xx_csl_c.html",line:7,type:"fcn"};
this.def["enable_interrupts"] = {file: "MW_c28xx_csl_c.html",line:15,type:"fcn"};
this.def["init_board"] = {file: "MW_c28xx_csl_c.html",line:22,type:"fcn"};
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
	this.html2SrcPath["untitled_c.html"] = "../untitled.c";
	this.html2Root["untitled_c.html"] = "untitled_c.html";
	this.html2SrcPath["untitled_h.html"] = "../untitled.h";
	this.html2Root["untitled_h.html"] = "untitled_h.html";
	this.html2SrcPath["untitled_private_h.html"] = "../untitled_private.h";
	this.html2Root["untitled_private_h.html"] = "untitled_private_h.html";
	this.html2SrcPath["untitled_types_h.html"] = "../untitled_types.h";
	this.html2Root["untitled_types_h.html"] = "untitled_types_h.html";
	this.html2SrcPath["untitled_data_c.html"] = "../untitled_data.c";
	this.html2Root["untitled_data_c.html"] = "untitled_data_c.html";
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
"ert_main_c.html","untitled_c.html","untitled_h.html","untitled_private_h.html","untitled_types_h.html","untitled_data_c.html","rtwtypes_h.html","rtmodel_h.html","MW_c28xx_csl_c.html","MW_c28xx_pie_h.html","MW_target_hardware_resources_h.html"];
