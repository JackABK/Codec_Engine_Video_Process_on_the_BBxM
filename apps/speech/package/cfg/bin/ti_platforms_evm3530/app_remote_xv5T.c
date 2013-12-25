/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-u17
 */

#define __nested__
#define __config__

#include <xdc/std.h>

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     MODULE INCLUDES
 *     
 *     <module-name> INTERNALS
 *     <module-name> INHERITS
 *     <module-name> VTABLE
 *     <module-name> PATCH TABLE
 *     <module-name> DECLARATIONS
 *     <module-name> OBJECT OFFSETS
 *     <module-name> TEMPLATES
 *     <module-name> INITIALIZERS
 *     <module-name> FUNCTION STUBS
 *     <module-name> PROXY BODY
 *     <module-name> OBJECT DESCRIPTOR
 *     <module-name> SYSTEM FUNCTIONS
 *     <module-name> PRAGMAS
 *     
 *     INITIALIZATION ENTRY POINT
 *     PROGRAM GLOBALS
 *     CLINK DIRECTIVES
 */


/*
 * ======== MODULE INCLUDES ========
 */



/*
 * ======== xdc.cfg.Program TEMPLATE ========
 */

/*
 *  ======== __ASM__ ========
 *  Define absolute path to program's assembly directory
 */
xdc__META(__ASM__, "@(#)__ASM__ = /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/apps/speech/package/cfg/bin/ti_platforms_evm3530/app_remote_xv5T");

/*
 *  ======== __ISA__ ========
 *  Define the ISA of this executable.  This symbol is used by platform
 *  specific "exec" commands that support more than one ISA; e.g., gdb
 */
xdc__META(__ISA__, "@(#)__ISA__ = v5T");

/*
 *  ======== __PLAT__ ========
 *  Define the name of the platform that can run this executable.  This
 *  symbol is used by platform independent "exec" commands
 */
xdc__META(__PLAT__, "@(#)__PLAT__ = ti.platforms.evm3530");

/*
 *  ======== __TARG__ ========
 *  Define the name of the target used to build this executable.
 */
xdc__META(__TARG__, "@(#)__TARG__ = gnu.targets.arm.GCArmv5T");


/*
 * ======== ti.sdo.ce.ipc.Settings TEMPLATE ========
 */


/*
 * ======== ti.sdo.ce.osal.Global TEMPLATE ========
 */



/*
 *  ======== Global Configuration ========
 *  Do not modify the following; it is automatically generated from the template
 *  Server.xdt in the ti.sdo.ce package and will be overwritten next time the
 *  executable is configured
 */
#include <ti/sdo/ce/osal/Log.h>

Log_Handle ti_sdo_ce_dvtLog = NULL; 

Bool Memory_skipVirtualAddressTranslation = FALSE;


/* List of all packages and their versions and paths, for diagnostics */
String Global_buildInfo[] = {
    "    package ti.xdais.dm.examples.auddec_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/auddec_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.viddec2_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/viddec2_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.videnc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/videnc1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.imgdec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/imgdec1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.imgenc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/imgenc1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.sphdec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/sphdec1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.sphenc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/sphenc1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.auddec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/auddec1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.audenc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/audenc1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.g711 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/g711/) [1, 0, 0]",
    "    package ti.xdais.dm.examples.vidtranscode_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/vidtranscode_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.vidanalytics_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/vidanalytics_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.viddec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/viddec1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.viddec2split_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/viddec2split_copy/) [1, 0, 0]",
    "    package ti.xdais.dm.examples.universal_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/universal_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.global (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/global/) [1, 0, 0]",
    "    package dsplink.gpp (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dsplink_1_65_00_02/dsplink/gpp/) [5, 0, 0]",
    "    package ti.sdo.linuxutils.cmem (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linuxutils_2_25_05_11/packages/ti/sdo/linuxutils/cmem/) [2, 2, 0]",
    "    package ti.bios.power (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/local-power-manager_1_24_02_09/packages/ti/bios/power/) [1, 1, 1]",
    "    package gnu.targets (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/) [1, 0, 1]",
    "    package gnu.targets.arm (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/arm/) [1, 0, 0, 0]",
    "    package ti.sdo.utils.trace (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/utils/trace/) [1, 0, 0]",
    "    package ti.xdais.dm (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdais_6_26_00_02/packages/ti/xdais/dm/) [1, 0, 5]",
    "    package ti.sdo.ce.utils.xdm (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/utils/xdm/) [1, 0, 2]",
    "    package ti.xdais (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdais_6_26_00_02/packages/ti/xdais/) [1, 2.0, 1]",
    "    package ti.sdo.ce.node (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/node/) [1, 0, 0]",
    "    package ti.sdo.fc.global (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/global/) [1, 0, 0]",
    "    package ti.sdo.fc.memutils (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/memutils/) [1, 0, 0]",
    "    package ti.sdo.fc.utils (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/utils/) [1, 0, 2]",
    "    package ti.sdo.fc.dman3 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/dman3/) [1, 0, 4]",
    "    package ti.sdo.fc.acpy3 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/acpy3/) [1, 0, 4]",
    "    package ti.catalog.arm (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/catalog/arm/) [1, 0, 1, 0]",
    "    package ti.catalog (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/catalog/) [1, 0, 0]",
    "    package ti.catalog.c6000 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/catalog/c6000/) [1, 0, 0, 0]",
    "    package ti.platforms.evm3530 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/platforms/evm3530/) [1, 0, 0]",
    "    package ti.sdo.ce.osal (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/osal/) [2, 0, 2]",
    "    package ti.sdo.ce.osal.linux (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/osal/linux/) [2, 0, 1]",
    "    package ti.sdo.ce.ipc (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/ipc/) [2, 0, 1]",
    "    package ti.sdo.ce.ipc.dsplink (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/ipc/dsplink/) [2, 0, 1]",
    "    package ti.sdo.ce.alg (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/alg/) [1, 0, 1]",
    "    package ti.sdo.ce (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/) [1, 0, 6]",
    "    package ti.sdo.ce.video (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/video/) [1, 0, 3]",
    "    package ti.sdo.ce.examples.codecs.viddec_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/viddec_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.videnc_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/videnc_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.image (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/image/) [1, 0, 3]",
    "    package ti.sdo.ce.examples.codecs.imgdec_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/imgdec_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.imgenc_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/imgenc_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.audio (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/audio/) [1, 0, 2]",
    "    package ti.sdo.ce.examples.codecs.auddec_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/auddec_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.audenc_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/audenc_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.speech (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/speech/) [1, 0, 2]",
    "    package ti.sdo.ce.examples.codecs.sphenc_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/sphenc_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.sphdec_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/sphdec_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.extensions.scale (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/extensions/scale/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.scale (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/scale/) [1, 0, 0]",
    "    package ti.sdo.ce.video2 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/video2/) [1, 0, 2]",
    "    package ti.sdo.ce.examples.codecs.viddec2_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/viddec2_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.video1 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/video1/) [1, 0, 2]",
    "    package ti.sdo.ce.examples.codecs.videnc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/videnc1_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.image1 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/image1/) [1, 0, 1]",
    "    package ti.sdo.ce.examples.codecs.imgdec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/imgdec1_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.imgenc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/imgenc1_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.speech1 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/speech1/) [1, 0, 1]",
    "    package ti.sdo.ce.examples.codecs.sphdec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/sphdec1_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.sphenc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/sphenc1_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.audio1 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/audio1/) [1, 0, 1]",
    "    package ti.sdo.ce.examples.codecs.auddec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/auddec1_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.audenc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/audenc1_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.g711 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/g711/) [1, 0, 0]",
    "    package ti.sdo.ce.vidtranscode (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/vidtranscode/) [1, 0, 1]",
    "    package ti.sdo.ce.examples.codecs.vidtranscode_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/vidtranscode_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.vidanalytics (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/vidanalytics/) [1, 0, 1]",
    "    package ti.sdo.ce.examples.codecs.vidanalytics_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/vidanalytics_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.viddec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/viddec1_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.video2.split (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/video2/split/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.viddec2split_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/viddec2split_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.universal (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/universal/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.universal_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/universal_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.apps.speech (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/apps/speech/) [1, 0, 0]",
    NULL
};

/*
 * ======== ti.sdo.ce.Engine TEMPLATE ========
 */

/*
 *  ======== Engine Configuration ========
 *  Do not modify following; it is automatically generated from the template
 *  Engine.xdt in the ti.sdo.ce package and will be overwritten next time the
 *  executable is configured
 */
#include <ti/sdo/ce/Engine.h>
#include <ti/xdais/ialg.h>

#include <ti/xdais/idma3.h>

#include <ti/xdais/ires.h>

/* type tables for algorithms */
extern IALG_Fxns VIDDEC2BACKCOPY_TI_IVIDDEC2BACKCOPY;
static String typeTab_VIDDEC2BACKCOPY_TI_IVIDDEC2BACKCOPY[] = {
    "ti.sdo.ce.video2.split.IVIDDEC2BACK",
    NULL
};

extern IALG_Fxns AUDDECCOPY_TI_IAUDDECCOPY;
static String typeTab_AUDDECCOPY_TI_IAUDDECCOPY[] = {
    "ti.sdo.ce.audio.IAUDDEC",
    NULL
};

extern IALG_Fxns VIDENCCOPY_TI_VIDENCCOPY;
static String typeTab_VIDENCCOPY_TI_VIDENCCOPY[] = {
    "ti.sdo.ce.video.IVIDENC",
    NULL
};

extern IALG_Fxns VIDENC1COPY_TI_IVIDENC1COPY;
static String typeTab_VIDENC1COPY_TI_IVIDENC1COPY[] = {
    "ti.sdo.ce.video1.IVIDENC1",
    NULL
};

extern IALG_Fxns IMGDECCOPY_TI_IMGDECCOPY;
static String typeTab_IMGDECCOPY_TI_IMGDECCOPY[] = {
    "ti.sdo.ce.image.IIMGDEC",
    NULL
};

extern IALG_Fxns VIDDEC2COPY_TI_IVIDDEC2COPY;
static String typeTab_VIDDEC2COPY_TI_IVIDDEC2COPY[] = {
    "ti.sdo.ce.video2.IVIDDEC2",
    NULL
};

extern IALG_Fxns AUDENCCOPY_TI_AUDENCCOPY;
static String typeTab_AUDENCCOPY_TI_AUDENCCOPY[] = {
    "ti.sdo.ce.audio.IAUDENC",
    NULL
};

extern IALG_Fxns IMGDEC1COPY_TI_IIMGDEC1COPY;
static String typeTab_IMGDEC1COPY_TI_IIMGDEC1COPY[] = {
    "ti.sdo.ce.image1.IIMGDEC1",
    NULL
};

extern IALG_Fxns AUDDEC1COPY_TI_IAUDDEC1COPY;
static String typeTab_AUDDEC1COPY_TI_IAUDDEC1COPY[] = {
    "ti.sdo.ce.audio1.IAUDDEC1",
    NULL
};

extern IALG_Fxns UNIVERSALCOPY_TI_IUNIVERSALCOPY;
static String typeTab_UNIVERSALCOPY_TI_IUNIVERSALCOPY[] = {
    "ti.sdo.ce.universal.IUNIVERSAL",
    NULL
};

extern IALG_Fxns SCALE_TI_SCALE;
static String typeTab_SCALE_TI_SCALE[] = {
    "ti.sdo.ce.examples.extensions.scale.ISCALE",
    NULL
};

extern IALG_Fxns G711DEC_SUN_IG711DEC;
static String typeTab_G711DEC_SUN_IG711DEC[] = {
    "ti.sdo.ce.speech1.ISPHDEC1",
    NULL
};

extern IALG_Fxns G711ENC_SUN_IG711ENC;
static String typeTab_G711ENC_SUN_IG711ENC[] = {
    "ti.sdo.ce.speech1.ISPHENC1",
    NULL
};

extern IALG_Fxns SPHDECCOPY_TI_SPHDECCOPY;
static String typeTab_SPHDECCOPY_TI_SPHDECCOPY[] = {
    "ti.sdo.ce.speech.ISPHDEC",
    NULL
};

extern IALG_Fxns IMGENC1COPY_TI_IIMGENC1COPY;
static String typeTab_IMGENC1COPY_TI_IIMGENC1COPY[] = {
    "ti.sdo.ce.image1.IIMGENC1",
    NULL
};

extern IALG_Fxns AUDENC1COPY_TI_IAUDENC1COPY;
static String typeTab_AUDENC1COPY_TI_IAUDENC1COPY[] = {
    "ti.sdo.ce.audio1.IAUDENC1",
    NULL
};

extern IALG_Fxns IMGENCCOPY_TI_IMGENCCOPY;
static String typeTab_IMGENCCOPY_TI_IMGENCCOPY[] = {
    "ti.sdo.ce.image.IIMGENC",
    NULL
};

extern IALG_Fxns SPHDEC1COPY_TI_ISPHDEC1COPY;
static String typeTab_SPHDEC1COPY_TI_ISPHDEC1COPY[] = {
    "ti.sdo.ce.speech1.ISPHDEC1",
    NULL
};

extern IALG_Fxns VIDDECCOPY_TI_VIDDECCOPY;
static String typeTab_VIDDECCOPY_TI_VIDDECCOPY[] = {
    "ti.sdo.ce.video.IVIDDEC",
    NULL
};

extern IALG_Fxns VIDANALYTICSCOPY_TI_IVIDANALYTICSCOPY;
static String typeTab_VIDANALYTICSCOPY_TI_IVIDANALYTICSCOPY[] = {
    "ti.sdo.ce.vidanalytics.IVIDANALYTICS",
    NULL
};

extern IALG_Fxns VIDTRANSCODECOPY_TI_IVIDTRANSCODECOPY;
static String typeTab_VIDTRANSCODECOPY_TI_IVIDTRANSCODECOPY[] = {
    "ti.sdo.ce.vidtranscode.IVIDTRANSCODE",
    NULL
};

extern IALG_Fxns SPHENCCOPY_TI_SPHENCCOPY;
static String typeTab_SPHENCCOPY_TI_SPHENCCOPY[] = {
    "ti.sdo.ce.speech.ISPHENC",
    NULL
};

extern IALG_Fxns SPHENC1COPY_TI_ISPHENC1COPY;
static String typeTab_SPHENC1COPY_TI_ISPHENC1COPY[] = {
    "ti.sdo.ce.speech1.ISPHENC1",
    NULL
};

extern IALG_Fxns VIDDEC1COPY_TI_IVIDDEC1COPY;
static String typeTab_VIDDEC1COPY_TI_IVIDDEC1COPY[] = {
    "ti.sdo.ce.video1.IVIDDEC1",
    NULL
};


/* tables of engine algorithms */
extern IALG_Fxns VIDDEC_STUBS;
extern IALG_Fxns VIDENC_STUBS;
extern IALG_Fxns IMGDEC_STUBS;
extern IALG_Fxns IMGENC_STUBS;
extern IALG_Fxns AUDDEC_STUBS;
extern IALG_Fxns AUDENC_STUBS;
extern IALG_Fxns SPHENC_STUBS;
extern IALG_Fxns SPHDEC_STUBS;
extern IALG_Fxns SCALE_STUBS;
extern IALG_Fxns VIDDEC2_STUBS;
extern IALG_Fxns VIDENC1_STUBS;
extern IALG_Fxns IMGDEC1_STUBS;
extern IALG_Fxns IMGENC1_STUBS;
extern IALG_Fxns SPHDEC1_STUBS;
extern IALG_Fxns SPHENC1_STUBS;
extern IALG_Fxns AUDDEC1_STUBS;
extern IALG_Fxns AUDENC1_STUBS;
extern IALG_Fxns SPHENC1_STUBS;
extern IALG_Fxns SPHDEC1_STUBS;
extern IALG_Fxns VIDTRANSCODE_STUBS;
extern IALG_Fxns VIDANALYTICS_STUBS;
extern IALG_Fxns VIDDEC1_STUBS;
extern IALG_Fxns VIDDEC2BACK_STUBS;
extern IALG_Fxns UNIVERSAL_STUBS;

/* algorithm-specific stub/skeleton config data objects */
extern struct ti_sdo_ce_examples_codecs_viddec_copy_VIDDEC_COPY_CodecClassConfig ti_sdo_ce_examples_codecs_viddec_copy_VIDDEC_COPY_codecClassConfig;
extern struct ti_sdo_ce_examples_codecs_videnc_copy_VIDENC_COPY_CodecClassConfig ti_sdo_ce_examples_codecs_videnc_copy_VIDENC_COPY_codecClassConfig;
extern struct ti_sdo_ce_examples_codecs_imgdec_copy_IMGDEC_COPY_CodecClassConfig ti_sdo_ce_examples_codecs_imgdec_copy_IMGDEC_COPY_codecClassConfig;
extern struct ti_sdo_ce_examples_codecs_imgenc_copy_IMGENC_COPY_CodecClassConfig ti_sdo_ce_examples_codecs_imgenc_copy_IMGENC_COPY_codecClassConfig;
extern struct ti_sdo_ce_examples_codecs_viddec2_copy_VIDDEC2_COPY_CodecClassConfig ti_sdo_ce_examples_codecs_viddec2_copy_VIDDEC2_COPY_codecClassConfig;
extern struct ti_sdo_ce_examples_codecs_videnc1_copy_VIDENC1_COPY_CodecClassConfig ti_sdo_ce_examples_codecs_videnc1_copy_VIDENC1_COPY_codecClassConfig;
extern struct ti_sdo_ce_examples_codecs_imgdec1_copy_IMGDEC1_COPY_CodecClassConfig ti_sdo_ce_examples_codecs_imgdec1_copy_IMGDEC1_COPY_codecClassConfig;
extern struct ti_sdo_ce_examples_codecs_imgenc1_copy_IMGENC1_COPY_CodecClassConfig ti_sdo_ce_examples_codecs_imgenc1_copy_IMGENC1_COPY_codecClassConfig;
extern struct ti_sdo_ce_examples_codecs_viddec1_copy_VIDDEC1_COPY_CodecClassConfig ti_sdo_ce_examples_codecs_viddec1_copy_VIDDEC1_COPY_codecClassConfig;
extern struct ti_sdo_ce_examples_codecs_viddec2split_copy_VIDDEC2BACK_COPY_CodecClassConfig ti_sdo_ce_examples_codecs_viddec2split_copy_VIDDEC2BACK_COPY_codecClassConfig;

static Engine_AlgDesc engineAlgs0[] = {
    {
        "viddec_copy",       /* name */
        {799937622U},   /* uuid */
        &VIDDEC_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDDECCOPY_TI_VIDDECCOPY,              /* typeTab */
        FALSE,          /* isLocal */
        0,        /* groupId */
        3,      /* protocol */
        NULL,         /* iresFxns */
        &ti_sdo_ce_examples_codecs_viddec_copy_VIDDEC_COPY_codecClassConfig, /* stub/skel config params */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.video.IVIDDEC",
    },
    {
        "videnc_copy",       /* name */
        {781443160U},   /* uuid */
        &VIDENC_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDENCCOPY_TI_VIDENCCOPY,              /* typeTab */
        FALSE,          /* isLocal */
        0,        /* groupId */
        3,      /* protocol */
        NULL,         /* iresFxns */
        &ti_sdo_ce_examples_codecs_videnc_copy_VIDENC_COPY_codecClassConfig, /* stub/skel config params */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.video.IVIDENC",
    },
    {
        "imgdec_copy",       /* name */
        {1913386179U},   /* uuid */
        &IMGDEC_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_IMGDECCOPY_TI_IMGDECCOPY,              /* typeTab */
        FALSE,          /* isLocal */
        1,        /* groupId */
        3,      /* protocol */
        NULL,         /* iresFxns */
        &ti_sdo_ce_examples_codecs_imgdec_copy_IMGDEC_COPY_codecClassConfig, /* stub/skel config params */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.image.IIMGDEC",
    },
    {
        "imgenc_copy",       /* name */
        {1932918989U},   /* uuid */
        &IMGENC_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_IMGENCCOPY_TI_IMGENCCOPY,              /* typeTab */
        FALSE,          /* isLocal */
        1,        /* groupId */
        3,      /* protocol */
        NULL,         /* iresFxns */
        &ti_sdo_ce_examples_codecs_imgenc_copy_IMGENC_COPY_codecClassConfig, /* stub/skel config params */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.image.IIMGENC",
    },
    {
        "auddec_copy",       /* name */
        {2922333659U},   /* uuid */
        &AUDDEC_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_AUDDECCOPY_TI_IAUDDECCOPY,              /* typeTab */
        FALSE,          /* isLocal */
        2,        /* groupId */
        3,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.audio.IAUDDEC",
    },
    {
        "audenc_copy",       /* name */
        {2937237973U},   /* uuid */
        &AUDENC_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_AUDENCCOPY_TI_AUDENCCOPY,              /* typeTab */
        FALSE,          /* isLocal */
        2,        /* groupId */
        3,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.audio.IAUDENC",
    },
    {
        "sphenc_copy",       /* name */
        {3388168999U},   /* uuid */
        &SPHENC_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_SPHENCCOPY_TI_SPHENCCOPY,              /* typeTab */
        FALSE,          /* isLocal */
        2,        /* groupId */
        3,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.speech.ISPHENC",
    },
    {
        "sphdec_copy",       /* name */
        {3368988457U},   /* uuid */
        &SPHDEC_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_SPHDECCOPY_TI_SPHDECCOPY,              /* typeTab */
        FALSE,          /* isLocal */
        2,        /* groupId */
        3,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.speech.ISPHDEC",
    },
    {
        "scale",       /* name */
        {3440692885U},   /* uuid */
        &SCALE_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_SCALE_TI_SCALE,              /* typeTab */
        FALSE,          /* isLocal */
        3,        /* groupId */
        1,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.examples.extensions.scale.ISCALE",
    },
    {
        "viddec2_copy",       /* name */
        {992502356U},   /* uuid */
        &VIDDEC2_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDDEC2COPY_TI_IVIDDEC2COPY,              /* typeTab */
        FALSE,          /* isLocal */
        0,        /* groupId */
        0,      /* protocol */
        NULL,         /* iresFxns */
        &ti_sdo_ce_examples_codecs_viddec2_copy_VIDDEC2_COPY_codecClassConfig, /* stub/skel config params */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.video2.IVIDDEC2",
    },
    {
        "videnc1_copy",       /* name */
        {490696979U},   /* uuid */
        &VIDENC1_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDENC1COPY_TI_IVIDENC1COPY,              /* typeTab */
        FALSE,          /* isLocal */
        0,        /* groupId */
        0,      /* protocol */
        NULL,         /* iresFxns */
        &ti_sdo_ce_examples_codecs_videnc1_copy_VIDENC1_COPY_codecClassConfig, /* stub/skel config params */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.video1.IVIDENC1",
    },
    {
        "imgdec1_copy",       /* name */
        {2653406028U},   /* uuid */
        &IMGDEC1_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_IMGDEC1COPY_TI_IIMGDEC1COPY,              /* typeTab */
        FALSE,          /* isLocal */
        1,        /* groupId */
        1,      /* protocol */
        NULL,         /* iresFxns */
        &ti_sdo_ce_examples_codecs_imgdec1_copy_IMGDEC1_COPY_codecClassConfig, /* stub/skel config params */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.image1.IIMGDEC1",
    },
    {
        "imgenc1_copy",       /* name */
        {2649891852U},   /* uuid */
        &IMGENC1_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_IMGENC1COPY_TI_IIMGENC1COPY,              /* typeTab */
        FALSE,          /* isLocal */
        1,        /* groupId */
        1,      /* protocol */
        NULL,         /* iresFxns */
        &ti_sdo_ce_examples_codecs_imgenc1_copy_IMGENC1_COPY_codecClassConfig, /* stub/skel config params */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.image1.IIMGENC1",
    },
    {
        "sphdec1_copy",       /* name */
        {996074855U},   /* uuid */
        &SPHDEC1_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_SPHDEC1COPY_TI_ISPHDEC1COPY,              /* typeTab */
        FALSE,          /* isLocal */
        2,        /* groupId */
        0,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.speech1.ISPHDEC1",
    },
    {
        "sphenc1_copy",       /* name */
        {948634151U},   /* uuid */
        &SPHENC1_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_SPHENC1COPY_TI_ISPHENC1COPY,              /* typeTab */
        FALSE,          /* isLocal */
        2,        /* groupId */
        0,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.speech1.ISPHENC1",
    },
    {
        "auddec1_copy",       /* name */
        {2426520118U},   /* uuid */
        &AUDDEC1_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_AUDDEC1COPY_TI_IAUDDEC1COPY,              /* typeTab */
        FALSE,          /* isLocal */
        2,        /* groupId */
        1,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.audio1.IAUDDEC1",
    },
    {
        "audenc1_copy",       /* name */
        {2473862518U},   /* uuid */
        &AUDENC1_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_AUDENC1COPY_TI_IAUDENC1COPY,              /* typeTab */
        FALSE,          /* isLocal */
        2,        /* groupId */
        1,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.audio1.IAUDENC1",
    },
    {
        "g711enc",       /* name */
        {3048083571U},   /* uuid */
        &SPHENC1_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_G711ENC_SUN_IG711ENC,              /* typeTab */
        FALSE,          /* isLocal */
        2,        /* groupId */
        0,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.speech1.ISPHENC1",
    },
    {
        "g711dec",       /* name */
        {1469621135U},   /* uuid */
        &SPHDEC1_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_G711DEC_SUN_IG711DEC,              /* typeTab */
        FALSE,          /* isLocal */
        2,        /* groupId */
        0,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.speech1.ISPHDEC1",
    },
    {
        "vidtranscode_copy",       /* name */
        {1024783961U},   /* uuid */
        &VIDTRANSCODE_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDTRANSCODECOPY_TI_IVIDTRANSCODECOPY,              /* typeTab */
        FALSE,          /* isLocal */
        4,        /* groupId */
        1,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.vidtranscode.IVIDTRANSCODE",
    },
    {
        "vidanalytics_copy",       /* name */
        {3849663438U},   /* uuid */
        &VIDANALYTICS_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDANALYTICSCOPY_TI_IVIDANALYTICSCOPY,              /* typeTab */
        FALSE,          /* isLocal */
        5,        /* groupId */
        1,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.vidanalytics.IVIDANALYTICS",
    },
    {
        "viddec1_copy",       /* name */
        {518690387U},   /* uuid */
        &VIDDEC1_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDDEC1COPY_TI_IVIDDEC1COPY,              /* typeTab */
        FALSE,          /* isLocal */
        0,        /* groupId */
        0,      /* protocol */
        NULL,         /* iresFxns */
        &ti_sdo_ce_examples_codecs_viddec1_copy_VIDDEC1_COPY_codecClassConfig, /* stub/skel config params */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.video1.IVIDDEC1",
    },
    {
        "viddec2back_copy",       /* name */
        {2765924915U},   /* uuid */
        &VIDDEC2BACK_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDDEC2BACKCOPY_TI_IVIDDEC2BACKCOPY,              /* typeTab */
        FALSE,          /* isLocal */
        0,        /* groupId */
        0,      /* protocol */
        NULL,         /* iresFxns */
        &ti_sdo_ce_examples_codecs_viddec2split_copy_VIDDEC2BACK_COPY_codecClassConfig, /* stub/skel config params */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.video2.split.IVIDDEC2BACK",
    },
    {
        "universal_copy",       /* name */
        {2235569266U},   /* uuid */
        &UNIVERSAL_STUBS,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_UNIVERSALCOPY_TI_IUNIVERSALCOPY,              /* typeTab */
        FALSE,          /* isLocal */
        6,        /* groupId */
        1,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.universal.IUNIVERSAL",
    },
    {NULL},
};
static Engine_AlgDesc engineAlgs1[] = {
    {NULL},
};

/* table of all engines available in this application */
static Engine_Desc engineTab[] = {
    {"speech",	/* engine name */
      engineAlgs0,	/* alg table */
      "all.x64P",		/* (optional) server name */
      NULL,        /* (optional) Link config ID */
      24 /* number of algs in alg table */
    },
    {"local",	/* engine name */
      engineAlgs1,	/* alg table */
      NULL,		/* (optional) server name */
      NULL,        /* (optional) Link config ID */
      0 /* number of algs in alg table */
    },
    {NULL, NULL, NULL, 0}	/* NULL-terminate the engine table */
};

Engine_Config Engine_config = {
    engineTab,		    /* table of all engines */
    "local"   /* local RMS engine name */
};

Bool ti_sdo_ce_Engine_noCommName = FALSE;

/*
 * ======== ti.sdo.ce.CERuntime TEMPLATE ========
 */


#include <ti/sdo/ce/osal/Global.h>
#include <ti/sdo/ce/ipc/Comm.h>
#include <ti/sdo/ce/osal/Memory.h>
#include <ti/sdo/ce/osal/Queue.h>
#include <ti/sdo/ce/osal/Sem.h>
#include <ti/sdo/ce/osal/SemMP.h>
#include <ti/sdo/ce/osal/Thread.h>
#include <ti/sdo/ce/ipc/Processor.h>
#include <ti/sdo/ce/alg/Algorithm.h>
#include <ti/sdo/ce/osal/Lock.h>
#include <ti/sdo/ce/osal/LockMP.h>
#include <ti/sdo/ce/Server.h>
#include <ti/sdo/ce/Engine.h>
#include <ti/sdo/ce/rms.h>
#include <ti/sdo/ce/utils/xdm/XdmUtils.h>

#include <ti/sdo/utils/trace/gt.h>


/*
 *  ======== CERuntime_init ========
 */
Void CERuntime_init(Void)
{
    extern Void IPC_generatedInit();

    GT_init();


    /* if CE_DEBUG is set, turn on tracing and DSP auto trace collection */
    if (Global_getenv("CE_DEBUG") != NULL) {
        extern Bool   Engine_alwaysCollectDspTrace;
        extern String Engine_ceDebugDspTraceMask;

        Engine_alwaysCollectDspTrace = TRUE;



        if (Global_getenv("CE_DEBUG")[0] == '1') {
            GT_set("*+67,CE-3,GT_time=0,GT_prefix=1235");
            Engine_ceDebugDspTraceMask = "*+67,GT_prefix=1235,GT_time=3";
        }
        else if (Global_getenv("CE_DEBUG")[0] == '2') {
            GT_set(
                "*+01234567,CE-3,ti.sdo.ce.osal.SemMP=67,OG=467,OM=4567,OC=67,GT_time=0,GT_prefix=1235");
            Engine_ceDebugDspTraceMask =
                "*+01234567,CR=67,ti.sdo.fc.dman3-2,ti.sdo.fc.dskt2-2,GT_prefix=1235,GT_time=3";
        } else {
            GT_set("*+01234567,CE-3,GT_time=0,GT_prefix=12345");
            Engine_ceDebugDspTraceMask = "*+01234567,GT_prefix=12345,GT_time=3";
        }
    }

    if (Global_getenv("CE_CHECK") != NULL) {
        extern Bool VISA_checked;

        /*
         * Currently just change _this_ processor's value... perhaps we should
         * enable remote processors as well?
         */
        if (Global_getenv("CE_CHECK")[0] == '1') {
            VISA_checked = TRUE;
            /* turn on all GT_7CLASS trace (errors) */
            GT_set("*+7");
        } else if (Global_getenv("CE_CHECK")[0] == '0') {
            VISA_checked = FALSE;
        } else {
            /* leave it whatever it was... maybe we should drop a warning? */
        }
    }

    /* allow user to over-ride via CE_TRACE. */
    GT_set(Global_getenv("CE_TRACE"));
    IPC_generatedInit();
    Global_init();

    Sem_init();
    SemMP_init();


    Memory_init();
    Queue_init();
    Comm_init();
    Thread_init();
    Processor_init();
    LockMP_init();  /* Must be called before DMAN3_init() */
    Algorithm_init();
    XdmUtils_init();
    Lock_init();

    Engine_init();
    Server_init();

}

/*
 *  ======== CERuntime_exit ========
 */
Void CERuntime_exit(Void)
{
    Global_exit();
}

/* for backward compatibility with xdc-m based tools */
Void ti_sdo_ce_CERuntime_init__F(Void) {
    CERuntime_init();
}

/*
 * ======== ti.sdo.ce.Settings TEMPLATE ========
 */

/*
 *  ======== ti.sdo.ce Settings Configuration ========
 *  Do not modify following; it is automatically generated from the template
 *  Settings.xdt in the ti.sdo.ce package and will be overwritten next time the
 *  executable is configured
 */
Bool VISA_checked = FALSE;

/*
 * ======== ti.sdo.ce.video.VIDENCConfig TEMPLATE ========
 */


/* this data structure has codec-specific names and values, but class-specific
 * fields -- it's indentical to struct IVIDENC_CodecClassConfig from videnc.h.
 * Its name doesn't matter, only that the address of data is captured in the
 * "codecClassConfig" field of the algorithm description
 */    
struct ti_sdo_ce_examples_codecs_videnc_copy_VIDENC_COPY_CodecClassConfig {
    Bool manageInBufsCache   [ XDM_MAX_IO_BUFFERS ];  
    Bool manageOutBufsCache  [ XDM_MAX_IO_BUFFERS ];  
    Bool manageReconBufsCache[ XDM_MAX_IO_BUFFERS ];  
} ti_sdo_ce_examples_codecs_videnc_copy_VIDENC_COPY_codecClassConfig = {
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE},
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE},
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE}
};

/*
 * ======== ti.sdo.ce.video.VIDDECConfig TEMPLATE ========
 */


/* this data structure has codec-specific names and values, but class-specific
 * fields -- it's indentical to struct IVIDENC_CodecClassConfig from videnc.h.
 * Its name doesn't matter, only that the address of data is captured in the
 * "codecClassConfig" field of the algorithm description
 */    
struct ti_sdo_ce_examples_codecs_viddec_copy_VIDDEC_COPY_CodecClassConfig {
    Bool manageInBufsCache     [ XDM_MAX_IO_BUFFERS ];  
    Bool manageOutBufsCache    [ XDM_MAX_IO_BUFFERS ];  
    Bool manageDisplayBufsCache[ XDM_MAX_IO_BUFFERS ];  
} ti_sdo_ce_examples_codecs_viddec_copy_VIDDEC_COPY_codecClassConfig = {
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE},
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE},
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE}
};

/*
 * ======== ti.sdo.ce.image.IMGDECConfig TEMPLATE ========
 */


/*
 * This data structure has codec-specific names and values, but class-specific
 * fields -- it's indentical to struct IVIDENC_CodecClassConfig from videnc.h.
 * Its name doesn't matter, only that the address of data is captured in the
 * "codecClassConfig" field of the algorithm description
 */    
struct ti_sdo_ce_examples_codecs_imgdec_copy_IMGDEC_COPY_CodecClassConfig {
    Bool manageInBufsCache   [ XDM_MAX_IO_BUFFERS ];  
    Bool manageOutBufsCache  [ XDM_MAX_IO_BUFFERS ];  
} ti_sdo_ce_examples_codecs_imgdec_copy_IMGDEC_COPY_codecClassConfig = {
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE},
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE}
};

/*
 * ======== ti.sdo.ce.image.IMGENCConfig TEMPLATE ========
 */


/* this data structure has codec-specific names and values, but class-specific
 * fields -- it's indentical to struct IVIDENC_CodecClassConfig from videnc.h.
 * Its name doesn't matter, only that the address of data is captured in the
 * "codecClassConfig" field of the algorithm description
 */    
struct ti_sdo_ce_examples_codecs_imgenc_copy_IMGENC_COPY_CodecClassConfig {
    Bool manageInBufsCache   [ XDM_MAX_IO_BUFFERS ];  
    Bool manageOutBufsCache  [ XDM_MAX_IO_BUFFERS ];  
} ti_sdo_ce_examples_codecs_imgenc_copy_IMGENC_COPY_codecClassConfig = {
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE},
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE}
};

/*
 * ======== ti.sdo.ce.video2.VIDDEC2Config TEMPLATE ========
 */


/* this data structure has codec-specific names and values, but class-specific
 * fields -- it's indentical to struct IVIDDEC2_CodecClassConfig from viddec2.h.
 * Its name doesn't matter, only that the address of data is captured in the
 * "codecClassConfig" field of the algorithm description
 */    
struct ti_sdo_ce_examples_codecs_viddec2_copy_VIDDEC2_COPY_CodecClassConfig {
    Bool manageInBufsCache     [ XDM_MAX_IO_BUFFERS ];  
    Bool manageOutBufsCache    [ XDM_MAX_IO_BUFFERS ];  
} ti_sdo_ce_examples_codecs_viddec2_copy_VIDDEC2_COPY_codecClassConfig = {
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE},
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE}
};

/*
 * ======== ti.sdo.ce.video1.VIDENC1Config TEMPLATE ========
 */


/* this data structure has codec-specific names and values, but class-specific
 * fields -- it's indentical to struct IVIDENC1_CodecClassConfig from videnc1.h.
 * Its name doesn't matter, only that the address of data is captured in the
 * "codecClassConfig" field of the algorithm description
 */    
struct ti_sdo_ce_examples_codecs_videnc1_copy_VIDENC1_COPY_CodecClassConfig {
    Bool manageInBufsCache   [ XDM_MAX_IO_BUFFERS ];  
    Bool manageOutBufsCache  [ XDM_MAX_IO_BUFFERS ];  
} ti_sdo_ce_examples_codecs_videnc1_copy_VIDENC1_COPY_codecClassConfig = {
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE},
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE}
};

/*
 * ======== ti.sdo.ce.video1.VIDDEC1Config TEMPLATE ========
 */


/* this data structure has codec-specific names and values, but class-specific
 * fields -- it's indentical to struct IVIDDEC1_CodecClassConfig from viddec1.h.
 * Its name doesn't matter, only that the address of data is captured in the
 * "codecClassConfig" field of the algorithm description
 */    
struct ti_sdo_ce_examples_codecs_viddec1_copy_VIDDEC1_COPY_CodecClassConfig {
    Bool manageInBufsCache     [ XDM_MAX_IO_BUFFERS ];  
    Bool manageOutBufsCache    [ XDM_MAX_IO_BUFFERS ];  
} ti_sdo_ce_examples_codecs_viddec1_copy_VIDDEC1_COPY_codecClassConfig = {
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE},
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE}
};

/*
 * ======== ti.sdo.ce.image1.IMGDEC1Config TEMPLATE ========
 */


/*
 * This data structure has codec-specific names and values, but class-specific
 * fields -- it's indentical to struct IIMGDEC1_CodecClassConfig from imgdec1.h.
 * Its name doesn't matter, only that the address of data is captured in the
 * "codecClassConfig" field of the algorithm description
 */    
struct ti_sdo_ce_examples_codecs_imgdec1_copy_IMGDEC1_COPY_CodecClassConfig {
    Bool manageInBufsCache   [ XDM_MAX_IO_BUFFERS ];  
    Bool manageOutBufsCache  [ XDM_MAX_IO_BUFFERS ];  
} ti_sdo_ce_examples_codecs_imgdec1_copy_IMGDEC1_COPY_codecClassConfig = {
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE},
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE}
};

/*
 * ======== ti.sdo.ce.image1.IMGENC1Config TEMPLATE ========
 */


/* this data structure has codec-specific names and values, but class-specific
 * fields -- it's indentical to struct IIMGENC1_CodecClassConfig from imgecn1.h.
 * Its name doesn't matter, only that the address of data is captured in the
 * "codecClassConfig" field of the algorithm description
 */    
struct ti_sdo_ce_examples_codecs_imgenc1_copy_IMGENC1_COPY_CodecClassConfig {
    Bool manageInBufsCache   [ XDM_MAX_IO_BUFFERS ];  
    Bool manageOutBufsCache  [ XDM_MAX_IO_BUFFERS ];  
} ti_sdo_ce_examples_codecs_imgenc1_copy_IMGENC1_COPY_codecClassConfig = {
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE},
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE}
};

/*
 * ======== ti.sdo.ce.video2.split.VIDDEC2BACKConfig TEMPLATE ========
 */


/*
 * This data structure has codec-specific names and values, but class-specific
 * fields -- it's indentical to struct IVIDDEC2BACK_CodecClassConfig from 
 * viddec2.h.
 * Its name doesn't matter, only that the address of data is captured in the
 * "codecClassConfig" field of the algorithm description
 */    
struct ti_sdo_ce_examples_codecs_viddec2split_copy_VIDDEC2BACK_COPY_CodecClassConfig {
    Bool manageInBufsCache           [XDM_MAX_CONTEXT_BUFFERS];
    Bool manageOutBufsCache          [XDM_MAX_CONTEXT_BUFFERS];
    Bool manageIntermediateBufsCache [XDM_MAX_CONTEXT_BUFFERS];
} ti_sdo_ce_examples_codecs_viddec2split_copy_VIDDEC2BACK_COPY_codecClassConfig = {
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE},
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE},
    {TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE,TRUE}
};

/*
 * ======== ti.sdo.ce.ipc.dsplink.Ipc TEMPLATE ========
 */


/* Max timeout for MSGQ_get() allowed. */
UInt32 ti_sdo_ce_ipc_dsplink_Ipc_maxTimeout = 4294967295UL;

Void IPC_generatedInit()
{
}

/* configuration for interprocessor communication */

/* size of the communication message */
UInt32 Comm_MSGSIZE = 4096;

/* number of Comm_MSGSIZE-sized messages in the system */
UInt32 Comm_NUMMSGS = 64;

/* configure number of retries Comm_locate should do before giving up */
UInt32 Comm_LOCATERETRIES = 20;


/* Arm-side DSPLINK configuration
 * ==============================
 */


#include <ti/sdo/ce/osal/Global.h>

/* Arm-side DspLink configuration tables { */


/* Arm-side DspLink memory map for server "all.x64P":
 *
 * table entry format (osal/Global.h), used by DSP/BIOS Link
 *     name of the memory section
 *     DSP virtual address (start of memory section)
 *     physical address (start of memory section)
 *     size in bytes of the memory region
 *     shared access memory
 *     synchronized
 */
static Global_ArmDspLinkConfigMemTableEntry armDspLinkConfigMemTable_all_x64P[] = {
    { "DDR2", 0x87800000, 0x87800000, 0x00600000, 1, 0 },
    { "DSPLINKMEM", 0x87E00000, 0x87E00000, 0x00100000, 1, 0 },
    { "RESET_VECTOR", 0x87F00000, 0x87F00000, 0x00001000, 1, 0 },
    { "IVAMMU", 0x5D000000, 0x5D000000, 0x00001000, 0, 0 },
    { "L4PER", 0x49000000, 0x49000000, 0x00100000, 0, 0 },
    { "IRAM", 0x107F8000, 0x5C7F8000, 0x00008000, 1, 0 },
    { "L1DSRAM", 0x10F04000, 0x5CF04000, 0x0000C000, 1, 0 },
    { "DDRALGHEAP", 0x86000000, 0x86000000, 0x01800000, 0, 0 },
    { "L4CORE", 0x48000000, 0x48000000, 0x01000000, 0, 0 },
    { "CMEM", 0x00000000, 0x00000000, 0x00000000, 0, 0 },
    { NULL, 0, 0, 0, 0, 0 }
};


/* Arm-side DspLink configuration table for server "all.x64P": */
static Global_ArmDspLinkConfig ti_sdo_ce_ipc_armDspLinkConfig_all_x64P = {
    armDspLinkConfigMemTable_all_x64P,
    BootNoPwr
};

/* List of server names for all DspLink configuration tables */
String ti_sdo_ce_ipc_armDspLinkConfigServerNames[] = {
    "all.x64P",
    NULL
};

/* List of matching-positions-by-name DspLink configuration tables for all servers */
Global_ArmDspLinkConfig *ti_sdo_ce_ipc_armDspLinkConfigs[] = {
    &ti_sdo_ce_ipc_armDspLinkConfig_all_x64P,
    NULL
};
/* } end of arm-side DspLink configuration tables. */

Int Global_useLinkArbiter = FALSE;

Int LAD_connect(String clientName, Int * id) { return 0; }
Int LAD_disconnect(Int id) { return 0; }
Int LAD_getDspStatus(Int cpuId, Int * statusInfo) { return 0; }
Int LAD_releaseDsp(Int id) { return 0; }
Int LAD_startupDsp(Int id, Int cpuId, Int linkId, String image) { return 0; }




/*
 * ======== ti.sdo.ce.osal.linux.Settings TEMPLATE ========
 */

UInt32 ti_sdo_ce_osal_linux_SemMP_ipcKey = 0x4c41534f;

UInt32 Memory_maxCbListSize = 100;


/*
 * ======== ti.bios.power.OMAP3530GPP TEMPLATE ========
 */


/* configuration parameters needed to avoid undefined references */
int PWRM_doImcopConfig = 0;
int PWRM_enableImcopAtPowerOn;

/*
 * ======== ti.sdo.utils.trace.GT TEMPLATE ========
 */




/*
 * C code contribution from ti/sdo/utils/GT.xdt 
 */
#include <xdc/std.h>
#include <ti/sdo/utils/trace/gt.h>

extern Void GTConfig_tracePrintf(String fmt, ...); 
extern Ptr GTConfig_libcMalloc(Int size);
 
extern Int GTConfig_threadId(void);
extern void GTConfig_error(String fmt, ...);
extern void GTConfig_libcFree(Ptr, Int);
extern UInt32 GTConfig_gettimeofday(void);
extern Int GTConfig_pthreadLock(void);
extern Int GTConfig_pthreadUnlock(void);
extern Int GTConfig_posixInit(void);

GT_Config _ti_sdo_utils_trace_GT_params = {
    GTConfig_tracePrintf,
    NULL,
    GTConfig_threadId,
    GTConfig_error,
    GTConfig_libcMalloc,
    GTConfig_libcFree,
    GTConfig_gettimeofday,
    GTConfig_pthreadLock,
    GTConfig_pthreadUnlock,
    GTConfig_posixInit    
};

GT_Config *GT = &_ti_sdo_utils_trace_GT_params;

/*
 * ======== ti.sdo.ce.alg.Settings TEMPLATE ========
 */

unsigned int ti_sdo_ce_alg_ALG_useHeap = FALSE;
unsigned int ti_sdo_ce_alg_ALG_useCache = FALSE;

unsigned int ti_sdo_ce_alg_ALG_maxGroups = 20; 

UInt32 ti_sdo_ce_alg_ipcKey = 0x4f474c41;

int _ALG_groupUsed[20] = {
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
};

#include <ti/sdo/ce/osal/SemMP.h>
#include <ti/xdais/ialg.h>

SemMP_Handle _ALG_sems[20];
int _ALG_groupRefCount[20] = {
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
};

IALG_Handle _Algorithm_lockOwner[20] = {
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
     NULL,
};

// No IDMA3 using algs in the system, and DMAN3 is not configured into the
// system.  Stub out these fxn calls.
Void DMAN3_CE_init()
{
}
Void DMAN3_CE_exit()
{
}

int DMAN3_grantDmaChannels(int groupId, void *algHandles, void *dmaFxns,
        int numAlgs)
{
    /* TODO:M  Should assert(false) here.  Should never be called */
    return (0);
}

int DMAN3_releaseDmaChannels(void *algHandles, void * dmaFxns, int numAlgs)
{
    /* TODO:M  Should assert(false) here.  Should never be called */
    return (0);
}

// No IRES using algs in the system, and RMAN is not configured into the
// system.  Stub out these fxn calls.
#include <ti/xdais/ires.h>   /* for IRES types */

IRES_Status RMAN_activateAllResources(IALG_Handle algHandle, IRES_Fxns *resFxns, Int scratchId)
{
    /* TODO:M  Should assert(false) here.  Should never be called */
    return (IRES_OK);
}

IRES_Status RMAN_assignResources(IALG_Handle algHandle, IRES_Fxns *resFxns, 
        Int scratchGroupId)
{
    /* TODO:M  Should assert(false) here.  Should never be called */
    return (IRES_OK);
}

IRES_Status RMAN_deactivateAllResources(IALG_Handle algHandle, 
        IRES_Fxns * resFxns, Int scratchId)
{
    /* TODO:M  Should assert(false) here.  Should never be called */
    return (IRES_OK);
}

IRES_Status RMAN_freeResources(IALG_Handle algHandle, IRES_Fxns * resFxns, 
        Int scratchGroupId)
{
    /* TODO:M  Should assert(false) here.  Should never be called */
    return (IRES_OK);
}

IRES_Status RMAN_init(void)
{
    return (IRES_OK);
}

IRES_Status RMAN_exit(void)
{
    return (IRES_OK);
}




/*
 * ======== ti.sdo.fc.global.Settings TEMPLATE ========
 */

Bool ti_sdo_fc_multiProcess = TRUE;

/*
 * ======== PROGRAM GLOBALS ========
 */


/*
 * ======== CLINK DIRECTIVES ========
 */

#ifdef __ti__
#define PRAGMA(x) _Pragma(#x)
#define xdc__clink_constant(var) \
PRAGMA(DATA_SECTION(var, ".const:" #var))  \
asm("   .sect \".const:" #var "\"\n"  \
  "   .clink\n"  \
  "   .sect \"[0].const:" #var "\"\n"  \
  "   .clink\n"  \
  "   .sect \"[1].const:" #var "\"\n"  \
  "   .clink")

#endif

