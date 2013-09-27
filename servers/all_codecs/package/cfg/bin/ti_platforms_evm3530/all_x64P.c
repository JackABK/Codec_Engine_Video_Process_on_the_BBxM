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
xdc__META(__ASM__, "@(#)__ASM__ = /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/servers/all_codecs/package/cfg/bin/ti_platforms_evm3530/all_x64P");

/*
 *  ======== __ISA__ ========
 *  Define the ISA of this executable.  This symbol is used by platform
 *  specific "exec" commands that support more than one ISA; e.g., gdb
 */
xdc__META(__ISA__, "@(#)__ISA__ = 64P");

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
xdc__META(__TARG__, "@(#)__TARG__ = ti.targets.C64P");

/*
 *  ======== __TRDR__ ========
 *  Define the name of the class that can read/parse this executable.
 */
xdc__META(__TRDR__, "@(#)__TRDR__ = ti.targets.omf.cof.Coff");


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

Bool Memory_skipVirtualAddressTranslation = FALSE;


/* List of all packages and their versions and paths, for diagnostics */
String Global_buildInfo[] = {
    "    package ti.xdais.dm.examples.auddec_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/auddec_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.viddec2_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/viddec2_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.videnc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/videnc1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.imgdec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/imgdec1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.imgenc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/imgenc1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.sphenc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/sphenc1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.sphdec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/sphdec1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.auddec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/auddec1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.audenc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/audenc1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.g711 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/g711/) [1, 0, 0]",
    "    package ti.xdais.dm.examples.vidtranscode_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/vidtranscode_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.vidanalytics_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/vidanalytics_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.universal_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/universal_copy/) [1, 0, 0]",
    "    package ti.xdais.dm.examples.viddec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/viddec1_copy/) [2, 0, 0]",
    "    package ti.xdais.dm.examples.viddec2split_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/xdais/dm/examples/viddec2split_copy/) [1, 0, 0]",
    "    package ti.xdais (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdais_6_26_00_02/packages/ti/xdais/) [1, 2.0, 1]",
    "    package ti.sdo.fc.ires (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/ires/) [1, 0, 0]",
    "    package ti.sdo.fc.global (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/global/) [1, 0, 0]",
    "    package ti.sdo.fc.ires.nullresource (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/ires/nullresource/) [1, 0, 0]",
    "    package ti.sdo.utils.trace (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/utils/trace/) [1, 0, 0]",
    "    package ti.rtdx (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dspbios_5_41_03_17/packages/ti/rtdx/) [2, 0, 0, 5]",
    "    package ti.psl (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dspbios_5_41_03_17/packages/ti/psl/) [5, 0, 0, 0]",
    "    package ti.pmi (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dspbios_5_41_03_17/packages/ti/pmi/) [1, 0, 0, 0]",
    "    package ti.pscl (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dspbios_5_41_03_17/packages/ti/pscl/) [1, 0, 0, 0]",
    "    package ti.bios (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dspbios_5_41_03_17/packages/ti/bios/) [5, 2, 5, 28]",
    "    package ti.sdo.fc.dskt2 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/dskt2/) [1, 0, 4]",
    "    package ti.sdo.fc.dman3 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/dman3/) [1, 0, 4]",
    "    package ti.sdo.fc.rman (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/rman/) [2, 0, 0]",
    "    package ti.sdo.ce.global (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/global/) [1, 0, 0]",
    "    package ti.xdais.dm (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdais_6_26_00_02/packages/ti/xdais/dm/) [1, 0, 5]",
    "    package ti.sdo.ce.utils.xdm (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/utils/xdm/) [1, 0, 2]",
    "    package ti.sdo.ce.node (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/node/) [1, 0, 0]",
    "    package ti.sdo.ce.ipc.dsplink.dsp (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/ipc/dsplink/dsp/) [2, 0, 1]",
    "    package ti.sdo.fc.memutils (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/memutils/) [1, 0, 0]",
    "    package ti.sdo.fc.acpy3 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/framework-components_2_25_03_07/packages/ti/sdo/fc/acpy3/) [1, 0, 4]",
    "    package dsplink.dsp (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/dsplink_1_65_00_02/dsplink/dsp/) [1, 4, 0]",
    "    package ti.bios.utils (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/biosutils_1_02_02/packages/ti/bios/utils/) [2, 0, 2, 02]",
    "    package ti.catalog.c6000 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/catalog/c6000/) [1, 0, 0, 0]",
    "    package ti.catalog (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/catalog/) [1, 0, 0]",
    "    package ti.catalog.arm (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/catalog/arm/) [1, 0, 1, 0]",
    "    package ti.platforms.evm3530 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/platforms/evm3530/) [1, 0, 0]",
    "    package ti.sdo.ce.osal (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/osal/) [2, 0, 2]",
    "    package ti.sdo.ce.osal.bios (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/osal/bios/) [2, 0, 1]",
    "    package ti.sdo.ce.ipc (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/ipc/) [2, 0, 1]",
    "    package ti.sdo.ce.ipc.bios (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/ipc/bios/) [2, 0, 1]",
    "    package ti.sdo.ce.alg (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/alg/) [1, 0, 1]",
    "    package ti.sdo.ce (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/) [1, 0, 6]",
    "    package ti.sdo.ce.bioslog (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/bioslog/) [1, 0, 1]",
    "    package ti.sdo.ce.video (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/video/) [1, 0, 3]",
    "    package ti.sdo.ce.examples.codecs.viddec_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/viddec_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.videnc_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/videnc_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.speech (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/speech/) [1, 0, 2]",
    "    package ti.sdo.ce.examples.codecs.sphenc_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/sphenc_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.sphdec_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/sphdec_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.image (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/image/) [1, 0, 3]",
    "    package ti.sdo.ce.examples.codecs.imgdec_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/imgdec_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.imgenc_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/imgenc_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.audio (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/audio/) [1, 0, 2]",
    "    package ti.sdo.ce.examples.codecs.auddec_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/auddec_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.audenc_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/audenc_copy/) [1, 0, 0]",
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
    "    package ti.sdo.ce.examples.codecs.sphenc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/sphenc1_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.sphdec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/sphdec1_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.audio1 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/audio1/) [1, 0, 1]",
    "    package ti.sdo.ce.examples.codecs.auddec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/auddec1_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.audenc1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/audenc1_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.g711 (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/g711/) [1, 0, 0]",
    "    package ti.sdo.ce.vidtranscode (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/vidtranscode/) [1, 0, 1]",
    "    package ti.sdo.ce.examples.codecs.vidtranscode_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/vidtranscode_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.vidanalytics (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/vidanalytics/) [1, 0, 1]",
    "    package ti.sdo.ce.examples.codecs.vidanalytics_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/vidanalytics_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.universal (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/universal/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.universal_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/universal_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.viddec1_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/viddec1_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.video2.split (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/packages/ti/sdo/ce/video2/split/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.codecs.viddec2split_copy (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/codecs/viddec2split_copy/) [1, 0, 0]",
    "    package ti.sdo.ce.examples.servers.all_codecs (/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/servers/all_codecs/) [1, 0, 0]",
    NULL
};

/*
 * ======== ti.sdo.ce.bioslog.LogServer TEMPLATE ========
 */


    
#include <ti/sdo/ce/bioslog/LogServer.h>
#include <ti/sdo/ce/osal/Global.h>

Int LogServer_stackSize = 2048;

/*
 *  ======== LogServer_initGenerated() ========
 */
Void LogServer_initGenerated()
{
    LogServer_init();
    
    /* this causes activation of TRC bits */
    Global_setSpecialTrace("ti.bios");
}


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
extern IALG_Fxns VIDDECCOPY_TI_VIDDECCOPY;
extern IALG_Fxns VIDENCCOPY_TI_VIDENCCOPY;
extern IALG_Fxns IMGDECCOPY_TI_IMGDECCOPY;
extern IALG_Fxns IMGENCCOPY_TI_IMGENCCOPY;
extern IALG_Fxns AUDDECCOPY_TI_IAUDDECCOPY;
extern IALG_Fxns AUDENCCOPY_TI_AUDENCCOPY;
extern IALG_Fxns SPHENCCOPY_TI_SPHENCCOPY;
extern IALG_Fxns SPHDECCOPY_TI_SPHDECCOPY;
extern IALG_Fxns SCALE_TI_SCALE;
extern IALG_Fxns VIDDEC2COPY_TI_IVIDDEC2COPY;
extern IALG_Fxns VIDENC1COPY_TI_IVIDENC1COPY;
extern IALG_Fxns IMGDEC1COPY_TI_IIMGDEC1COPY;
extern IALG_Fxns IMGENC1COPY_TI_IIMGENC1COPY;
extern IALG_Fxns SPHDEC1COPY_TI_ISPHDEC1COPY;
extern IALG_Fxns SPHENC1COPY_TI_ISPHENC1COPY;
extern IALG_Fxns AUDDEC1COPY_TI_IAUDDEC1COPY;
extern IALG_Fxns AUDENC1COPY_TI_IAUDENC1COPY;
extern IALG_Fxns G711ENC_SUN_IG711ENC;
extern IALG_Fxns G711DEC_SUN_IG711DEC;
extern IALG_Fxns VIDTRANSCODECOPY_TI_IVIDTRANSCODECOPY;
extern IALG_Fxns VIDANALYTICSCOPY_TI_IVIDANALYTICSCOPY;
extern IALG_Fxns VIDDEC1COPY_TI_IVIDDEC1COPY;
extern IALG_Fxns VIDDEC2BACKCOPY_TI_IVIDDEC2BACKCOPY;
extern IALG_Fxns UNIVERSALCOPY_TI_IUNIVERSALCOPY;

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
        &VIDDECCOPY_TI_VIDDECCOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDDECCOPY_TI_VIDDECCOPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &VIDENCCOPY_TI_VIDENCCOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDENCCOPY_TI_VIDENCCOPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &IMGDECCOPY_TI_IMGDECCOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_IMGDECCOPY_TI_IMGDECCOPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &IMGENCCOPY_TI_IMGENCCOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_IMGENCCOPY_TI_IMGENCCOPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &AUDDECCOPY_TI_IAUDDECCOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_AUDDECCOPY_TI_IAUDDECCOPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &AUDENCCOPY_TI_AUDENCCOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_AUDENCCOPY_TI_AUDENCCOPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &SPHENCCOPY_TI_SPHENCCOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_SPHENCCOPY_TI_SPHENCCOPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &SPHDECCOPY_TI_SPHDECCOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_SPHDECCOPY_TI_SPHDECCOPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &SCALE_TI_SCALE,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_SCALE_TI_SCALE,              /* typeTab */
        TRUE,          /* isLocal */
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
        &VIDDEC2COPY_TI_IVIDDEC2COPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDDEC2COPY_TI_IVIDDEC2COPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &VIDENC1COPY_TI_IVIDENC1COPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDENC1COPY_TI_IVIDENC1COPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &IMGDEC1COPY_TI_IIMGDEC1COPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_IMGDEC1COPY_TI_IIMGDEC1COPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &IMGENC1COPY_TI_IIMGENC1COPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_IMGENC1COPY_TI_IIMGENC1COPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &SPHDEC1COPY_TI_ISPHDEC1COPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_SPHDEC1COPY_TI_ISPHDEC1COPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &SPHENC1COPY_TI_ISPHENC1COPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_SPHENC1COPY_TI_ISPHENC1COPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &AUDDEC1COPY_TI_IAUDDEC1COPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_AUDDEC1COPY_TI_IAUDDEC1COPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &AUDENC1COPY_TI_IAUDENC1COPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_AUDENC1COPY_TI_IAUDENC1COPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &G711ENC_SUN_IG711ENC,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_G711ENC_SUN_IG711ENC,              /* typeTab */
        TRUE,          /* isLocal */
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
        &G711DEC_SUN_IG711DEC,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_G711DEC_SUN_IG711DEC,              /* typeTab */
        TRUE,          /* isLocal */
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
        &VIDTRANSCODECOPY_TI_IVIDTRANSCODECOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDTRANSCODECOPY_TI_IVIDTRANSCODECOPY,              /* typeTab */
        TRUE,          /* isLocal */
        3,        /* groupId */
        1,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.vidtranscode.IVIDTRANSCODE",
    },
    {
        "vidanalytics_copy",       /* name */
        {3849663438U},   /* uuid */
        &VIDANALYTICSCOPY_TI_IVIDANALYTICSCOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDANALYTICSCOPY_TI_IVIDANALYTICSCOPY,              /* typeTab */
        TRUE,          /* isLocal */
        3,        /* groupId */
        1,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.vidanalytics.IVIDANALYTICS",
    },
    {
        "viddec1_copy",       /* name */
        {518690387U},   /* uuid */
        &VIDDEC1COPY_TI_IVIDDEC1COPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDDEC1COPY_TI_IVIDDEC1COPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &VIDDEC2BACKCOPY_TI_IVIDDEC2BACKCOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_VIDDEC2BACKCOPY_TI_IVIDDEC2BACKCOPY,              /* typeTab */
        TRUE,          /* isLocal */
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
        &UNIVERSALCOPY_TI_IUNIVERSALCOPY,             /* fxns */
        NULL,        /* idma3Fxns */
        typeTab_UNIVERSALCOPY_TI_IUNIVERSALCOPY,              /* typeTab */
        TRUE,          /* isLocal */
        3,        /* groupId */
        1,      /* protocol */
        NULL,         /* iresFxns */
        NULL,               /* stub/skel config params  */
        Engine_USECACHEDMEM_DEFAULT,    /* memType */
        "ti.sdo.ce.universal.IUNIVERSAL",
    },
    {NULL},
};

/* table of all engines available in this application */
static Engine_Desc engineTab[] = {
    {"local",	/* engine name */
      engineAlgs0,	/* alg table */
      NULL,		/* (optional) server name */
      NULL,        /* (optional) Link config ID */
      24 /* number of algs in alg table */
    },
    {NULL, NULL, NULL, 0}	/* NULL-terminate the engine table */
};

Engine_Config Engine_config = {
    engineTab,		    /* table of all engines */
    "local"   /* local RMS engine name */
};

Bool ti_sdo_ce_Engine_noCommName = FALSE;

/*
 * ======== ti.sdo.ce.Server TEMPLATE ========
 */

/*
 *  ======== Server Configuration ========
 *  Do not modify following; it is automatically generated from the template
 *  Server.xdt in the ti.sdo.ce package and will be overwritten next time the
 *  executable is configured
 */
#include <ti/sdo/ce/node/node.h>
#include <ti/sdo/ce/rms.h>

Int ti_sdo_ce_Server_skelCachingPolicy = 0;

static NODE_Attrs nodeAttrs0 = {
    2, 10024, 0
};
extern SKEL_Fxns VIDDEC_SKEL;

static NODE_Attrs nodeAttrs1 = {
    2, 10024, 0
};
extern SKEL_Fxns VIDENC_SKEL;

static NODE_Attrs nodeAttrs2 = {
    3, 10024, 0
};
extern SKEL_Fxns IMGDEC_SKEL;

static NODE_Attrs nodeAttrs3 = {
    3, 10024, 0
};
extern SKEL_Fxns IMGENC_SKEL;

static NODE_Attrs nodeAttrs4 = {
    4, 10024, 0
};
extern SKEL_Fxns AUDDEC_SKEL;

static NODE_Attrs nodeAttrs5 = {
    4, 10024, 0
};
extern SKEL_Fxns AUDENC_SKEL;

static NODE_Attrs nodeAttrs6 = {
    4, 10024, 0
};
extern SKEL_Fxns SPHENC_SKEL;

static NODE_Attrs nodeAttrs7 = {
    4, 10024, 0
};
extern SKEL_Fxns SPHDEC_SKEL;

static NODE_Attrs nodeAttrs8 = {
    2, 10024, 0
};
extern SKEL_Fxns SCALE_SKEL;

static NODE_Attrs nodeAttrs9 = {
    2, 11096, 0
};
extern SKEL_Fxns VIDDEC2_SKEL;

static NODE_Attrs nodeAttrs10 = {
    2, 11096, 0
};
extern SKEL_Fxns VIDENC1_SKEL;

static NODE_Attrs nodeAttrs11 = {
    3, 11048, 0
};
extern SKEL_Fxns IMGDEC1_SKEL;

static NODE_Attrs nodeAttrs12 = {
    3, 11048, 0
};
extern SKEL_Fxns IMGENC1_SKEL;

static NODE_Attrs nodeAttrs13 = {
    4, 10024, 0
};
extern SKEL_Fxns SPHDEC1_SKEL;

static NODE_Attrs nodeAttrs14 = {
    4, 10024, 0
};
extern SKEL_Fxns SPHENC1_SKEL;

static NODE_Attrs nodeAttrs15 = {
    4, 10024, 0
};
extern SKEL_Fxns AUDDEC1_SKEL;

static NODE_Attrs nodeAttrs16 = {
    4, 10024, 0
};
extern SKEL_Fxns AUDENC1_SKEL;

static NODE_Attrs nodeAttrs17 = {
    4, 9512, 0
};
extern SKEL_Fxns SPHENC1_SKEL;

static NODE_Attrs nodeAttrs18 = {
    4, 9512, 0
};
extern SKEL_Fxns SPHDEC1_SKEL;

static NODE_Attrs nodeAttrs19 = {
    2, 10024, 0
};
extern SKEL_Fxns VIDTRANSCODE_SKEL;

static NODE_Attrs nodeAttrs20 = {
    2, 10024, 0
};
extern SKEL_Fxns VIDANALYTICS_SKEL;

static NODE_Attrs nodeAttrs21 = {
    2, 11096, 0
};
extern SKEL_Fxns VIDDEC1_SKEL;

static NODE_Attrs nodeAttrs22 = {
    2, 9512, 0
};
extern SKEL_Fxns VIDDEC2BACK_SKEL;

static NODE_Attrs nodeAttrs23 = {
    2, 10024, 0
};
extern SKEL_Fxns UNIVERSAL_SKEL;


/*  table of all "codec server" nodes available in this server */
NODE_Desc RMS_nodeTab[] = {
    {
        "viddec_copy",			/* Name */
        {799937622U},			/* uuid */
        &VIDDEC_SKEL,			/* skel fxns */
        &nodeAttrs0,			/* params */
        3,						/* protocol */
        "VIDDEC_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.video.IVIDDEC"},			/* typeTab string */
    {
        "videnc_copy",			/* Name */
        {781443160U},			/* uuid */
        &VIDENC_SKEL,			/* skel fxns */
        &nodeAttrs1,			/* params */
        3,						/* protocol */
        "VIDENC_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.video.IVIDENC"},			/* typeTab string */
    {
        "imgdec_copy",			/* Name */
        {1913386179U},			/* uuid */
        &IMGDEC_SKEL,			/* skel fxns */
        &nodeAttrs2,			/* params */
        3,						/* protocol */
        "IMGDEC_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.image.IIMGDEC"},			/* typeTab string */
    {
        "imgenc_copy",			/* Name */
        {1932918989U},			/* uuid */
        &IMGENC_SKEL,			/* skel fxns */
        &nodeAttrs3,			/* params */
        3,						/* protocol */
        "IMGENC_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.image.IIMGENC"},			/* typeTab string */
    {
        "auddec_copy",			/* Name */
        {2922333659U},			/* uuid */
        &AUDDEC_SKEL,			/* skel fxns */
        &nodeAttrs4,			/* params */
        3,						/* protocol */
        "AUDDEC_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.audio.IAUDDEC"},			/* typeTab string */
    {
        "audenc_copy",			/* Name */
        {2937237973U},			/* uuid */
        &AUDENC_SKEL,			/* skel fxns */
        &nodeAttrs5,			/* params */
        3,						/* protocol */
        "AUDENC_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.audio.IAUDENC"},			/* typeTab string */
    {
        "sphenc_copy",			/* Name */
        {3388168999U},			/* uuid */
        &SPHENC_SKEL,			/* skel fxns */
        &nodeAttrs6,			/* params */
        3,						/* protocol */
        "SPHENC_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.speech.ISPHENC"},			/* typeTab string */
    {
        "sphdec_copy",			/* Name */
        {3368988457U},			/* uuid */
        &SPHDEC_SKEL,			/* skel fxns */
        &nodeAttrs7,			/* params */
        3,						/* protocol */
        "SPHDEC_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.speech.ISPHDEC"},			/* typeTab string */
    {
        "scale",			/* Name */
        {3440692885U},			/* uuid */
        &SCALE_SKEL,			/* skel fxns */
        &nodeAttrs8,			/* params */
        1,						/* protocol */
        "SCALE_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.examples.extensions.scale.ISCALE"},			/* typeTab string */
    {
        "viddec2_copy",			/* Name */
        {992502356U},			/* uuid */
        &VIDDEC2_SKEL,			/* skel fxns */
        &nodeAttrs9,			/* params */
        0,						/* protocol */
        "VIDDEC2_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.video2.IVIDDEC2"},			/* typeTab string */
    {
        "videnc1_copy",			/* Name */
        {490696979U},			/* uuid */
        &VIDENC1_SKEL,			/* skel fxns */
        &nodeAttrs10,			/* params */
        0,						/* protocol */
        "VIDENC1_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.video1.IVIDENC1"},			/* typeTab string */
    {
        "imgdec1_copy",			/* Name */
        {2653406028U},			/* uuid */
        &IMGDEC1_SKEL,			/* skel fxns */
        &nodeAttrs11,			/* params */
        1,						/* protocol */
        "IMGDEC1_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.image1.IIMGDEC1"},			/* typeTab string */
    {
        "imgenc1_copy",			/* Name */
        {2649891852U},			/* uuid */
        &IMGENC1_SKEL,			/* skel fxns */
        &nodeAttrs12,			/* params */
        1,						/* protocol */
        "IMGENC1_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.image1.IIMGENC1"},			/* typeTab string */
    {
        "sphdec1_copy",			/* Name */
        {996074855U},			/* uuid */
        &SPHDEC1_SKEL,			/* skel fxns */
        &nodeAttrs13,			/* params */
        0,						/* protocol */
        "SPHDEC1_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.speech1.ISPHDEC1"},			/* typeTab string */
    {
        "sphenc1_copy",			/* Name */
        {948634151U},			/* uuid */
        &SPHENC1_SKEL,			/* skel fxns */
        &nodeAttrs14,			/* params */
        0,						/* protocol */
        "SPHENC1_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.speech1.ISPHENC1"},			/* typeTab string */
    {
        "auddec1_copy",			/* Name */
        {2426520118U},			/* uuid */
        &AUDDEC1_SKEL,			/* skel fxns */
        &nodeAttrs15,			/* params */
        1,						/* protocol */
        "AUDDEC1_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.audio1.IAUDDEC1"},			/* typeTab string */
    {
        "audenc1_copy",			/* Name */
        {2473862518U},			/* uuid */
        &AUDENC1_SKEL,			/* skel fxns */
        &nodeAttrs16,			/* params */
        1,						/* protocol */
        "AUDENC1_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.audio1.IAUDENC1"},			/* typeTab string */
    {
        "g711enc",			/* Name */
        {3048083571U},			/* uuid */
        &SPHENC1_SKEL,			/* skel fxns */
        &nodeAttrs17,			/* params */
        0,						/* protocol */
        "SPHENC1_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.speech1.ISPHENC1"},			/* typeTab string */
    {
        "g711dec",			/* Name */
        {1469621135U},			/* uuid */
        &SPHDEC1_SKEL,			/* skel fxns */
        &nodeAttrs18,			/* params */
        0,						/* protocol */
        "SPHDEC1_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.speech1.ISPHDEC1"},			/* typeTab string */
    {
        "vidtranscode_copy",			/* Name */
        {1024783961U},			/* uuid */
        &VIDTRANSCODE_SKEL,			/* skel fxns */
        &nodeAttrs19,			/* params */
        1,						/* protocol */
        "VIDTRANSCODE_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.vidtranscode.IVIDTRANSCODE"},			/* typeTab string */
    {
        "vidanalytics_copy",			/* Name */
        {3849663438U},			/* uuid */
        &VIDANALYTICS_SKEL,			/* skel fxns */
        &nodeAttrs20,			/* params */
        1,						/* protocol */
        "VIDANALYTICS_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.vidanalytics.IVIDANALYTICS"},			/* typeTab string */
    {
        "viddec1_copy",			/* Name */
        {518690387U},			/* uuid */
        &VIDDEC1_SKEL,			/* skel fxns */
        &nodeAttrs21,			/* params */
        0,						/* protocol */
        "VIDDEC1_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.video1.IVIDDEC1"},			/* typeTab string */
    {
        "viddec2back_copy",			/* Name */
        {2765924915U},			/* uuid */
        &VIDDEC2BACK_SKEL,			/* skel fxns */
        &nodeAttrs22,			/* params */
        0,						/* protocol */
        "VIDDEC2BACK_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.video2.split.IVIDDEC2BACK"},			/* typeTab string */
    {
        "universal_copy",			/* Name */
        {2235569266U},			/* uuid */
        &UNIVERSAL_SKEL,			/* skel fxns */
        &nodeAttrs23,			/* params */
        1,						/* protocol */
        "UNIVERSAL_STUBS",			/* Name of stub fxns */
        "ti.sdo.ce.universal.IUNIVERSAL"},			/* typeTab string */
    {NULL}  /* NULL terminate RMS_nodeTab[] */
};


RMS_Config RMS_config = {
    1,          /* RMS server's priority */
    4096,         /* RMS server's stack size */
    0,        /* RMS server's stack memory seg */
};

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

/* This symbol is referenced by Server_init() */
Int Global_useLinkArbiter = FALSE;

/*
 *  ======== CERuntime_init ========
 */
Void CERuntime_init(Void)
{
    extern Void IPC_generatedInit();

    GT_init();



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

    RMS_init();
    Global_atexit((Fxn)RMS_exit);
    Engine_init();
    Server_init();

    /* init code contribution from ti.sdo.ce.bioslog */
    {
        extern Void LogServer_initGenerated();
        LogServer_initGenerated();
    }


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
 * ======== ti.sdo.fc.dskt2.DSKT2 TEMPLATE ========
 */

/* C code contribution from ti/sdo/fc/DSKT2.xdt */

#include <xdc/std.h>
#include <ti/sdo/fc/dskt2/dskt2.h>

extern Void BCACHE_wbInv();

DSKT2_CacheWBInvFxn DSKT2_cacheWBInvFxn = (DSKT2_CacheWBInvFxn)BCACHE_wbInv;

Uns _DSKT2_ALLOW_EXTERNAL_SCRATCH = 0;

#if 20 > DSKT2_NUM_SCRATCH_GROUPS
#error too many values in DARAM_SCRATCH_SIZES array, please fix your .cfg
#endif

#if 20 > DSKT2_NUM_SCRATCH_GROUPS
#error too many values in SARAM_SCRATCH_SIZES array, please fix your .cfg
#endif

Uns _DSKT2_DARAM_SCRATCH_SIZES[ DSKT2_NUM_SCRATCH_GROUPS ] = {
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
    0
};

Uns _DSKT2_SARAM_SCRATCH_SIZES[ DSKT2_NUM_SCRATCH_GROUPS ] = {
    32768,
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
    0
};


/*
 * ======== ti.sdo.fc.dman3.DMAN3 TEMPLATE ========
 */


/* C code contribution from ti/sdo/fc/dman3/DMAN3.xdt */

#include <ti/sdo/fc/dman3/dman3.h>
#include <ti/sdo/fc/acpy3/acpy3.h>

#if 20 > DMAN3_MAXGROUPS
#error DMAN3 internal assertion:  const DMAN3.MAXGROUPS larger than header const
#endif

__FAR__ Uns DMAN3_QDMA_CHANNELS[8] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7
};

__FAR__ Uns DMAN3_QDMA_QUEUE_MAP[8] = {
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1
};

__FAR__ Uns DMAN3_QUEUE_TC_MAP[8] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7
};

__FAR__ Uns DMAN3_QUEUE_PRIORITIES[8] = {
    3,
    7,
    0,
    0,
    0,
    0,
    0,
    0
};

extern Void  _DMAN3_initInternal();
extern Void  _DMAN3_initImpl(Void);
/* declaration of user-supplied DMAN3.scratchAllocFxn */
extern Bool DSKT2_allocScratch(IALG_Handle alg, Int mutexId,
            IALG_MemRec *memTab, Int numRecs);

/* declaration of user-supplied DMAN3.scratchFreeFxn */
extern Void DSKT2_freeScratch(Int mutexId, Void *addr, Uns size);


/*
 *  ======== DMAN3_init  ========
 */
Void DMAN3_init(Void)
{
    extern __FAR__ DMAN3_Params DMAN3_PARAMS;

    /* BIOS heap labels */
    extern __FAR__ Int L1DHEAP;
    extern __FAR__ Int DDRALGHEAP;

    DMAN3_PARAMS.heapInternal = L1DHEAP;
    DMAN3_PARAMS.heapExternal = DDRALGHEAP;
    _DMAN3_initImpl();
}


/*
 *  ======== DMAN3_CE_init  ========
 *  Supplied to support legacy Codec Engine Frameworks. To be deprecated in the future.
 */
Void DMAN3_CE_init()
{
    DMAN3_init();
    ACPY3_init();
}

/*
 *  ======== DMAN3_CE_exit  ========
 *  Supplied to support legacy Codec Engine Frameworks. To be deprecated in the future.
 */
Void DMAN3_CE_exit()
{
    DMAN3_exit();
    ACPY3_exit();
}

/*
 *  ======== DMAN3_PARAMS ========
 *  Default module configuration structure for DMAN3 implementation.
 *  It is set at design time by the system integrator to adjust the behaviour
 *  of the module to be optimal for its execution environment.
 */
DMAN3_Params DMAN3_PARAMS = {

    /* qdmaPaRamBase: Physical base address for PARAM0 */
    (Uns *)0x1c04000,

    /* The maxPaRamEntries:  Total number of PARAM Table entries on the
     * hardware (eg, for IVA2 this is 128, for Himalaya, this is 256).
     */
    128,

    /*
     * paRamBaseIndex: (0>value>255) represents the first PARAM TABLE ENTRY
     * NUMBER that is assigned by configuration for exclusive DMAN3 allocation.
     */
    80,

    /*
     * numPaRamEntries:  number of PARAM Table entries starting at
     * DMAN3_PARAM_BASE_INDEX assigned by configuration for exclusive DMAN3
     * allocation.
     */
    48,


    /* maxQdmaChannels:  contains the total number of Physical QDMA channels
     * available on the hardware (eg, 8 for DaVinci, 4 for IVA2).
     */
    8,

    /*
     * numQdmaChannels: contains the number of Physical QDMA channels
     * that are assigned to DMAN3 via configuration.
     * qdmaChannels: array containing list of DMAN3_NUM_QDMA_CHANNELS
     * many Physical QDMA channels assigned to DMAN3 via configuration.
     */
    8,

    DMAN3_QDMA_CHANNELS,

    /*
     * tccAllocationMaskH and tccAllocationMaskL:  are 32-bit bitmasks
     * representing configuration provided list of TCCs for exclusive DMAN3
     * allocation.
     *
     * For example, for TCC's in the range 0-31 the Low Mask (tccAllocationMaskL)
     * is configured so that a '1' in bit position 'i' indicates the TCC 'i' is
     * assigned to DMAN3
     */
    0xffffffff,
    0x0,

     /*
      * heapInternal: BIOS Heap ID for dynamic allocation of DMAN3 objects
      * must be allocated in L1D Internal RAM.
      * heapExternal: BIOS Heap ID for dyn allocation of private DMAN3
      * data structures.
      *
      * A value of -1 indicates that the heap is NOT DEFINED.
      */
    -1, //L1DHEAP,
    0,  //DDRALGHEAP,

    /* numTccGroup[DMAN3_MAXGROUPS] */
    {
    32,
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
    0
    },

    /* numPaRamGroup[DMAN3_MAXGROUPS] */
    {
    48,
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
    0
    },

    /* idma3Internal */
    0,

    /* scratchAllocFxn */
    DSKT2_allocScratch,

    /* scratchFreeFxn */
    DSKT2_freeScratch,

    /* nullPaRamIndex */
    0,

    /* maxTcs */
    8,

    DMAN3_QDMA_QUEUE_MAP,

    DMAN3_QUEUE_TC_MAP,

    DMAN3_QUEUE_PRIORITIES,

    /* allowUnshared */
    1,
};


/*
 * ======== ti.sdo.fc.rman.RMAN TEMPLATE ========
 */

/* C code contribution from ti/sdo/fc/rman/RMAN.xdt */
 
#include <ti/sdo/fc/rman/rman.h>


#include <ti/xdais/ialg.h>
#include <ti/xdais/ires.h>
extern Bool DSKT2_allocPersistent(IALG_MemRec *memTab, Int numRecs);

extern Void DSKT2_freePersistent(IALG_MemRec *memTab, Int numRecs);

extern Void RMAN_yield(IRES_YieldResourceType resourceType,
        IRES_YieldContextHandle algYieldContext, IRES_YieldArgs yieldArgs);
  


/* Table of user-configured size to store the registration entries */ 
__FAR__ IRESMAN_Fxns * RMAN_TABLE[11];

/* Table of user-configured size to store the freed entries */ 
__FAR__ short RMAN_FREE_ENTRIES[11];

/*
 * Number of entries statically configured for the Resource Registry table
 */
__FAR__ short RMAN_numRegistryEntries  = 0;
 
/*
 * Static configuration entries for the table
 */
__FAR__ IRESMAN_Fxns ** RMAN_registryEntries = NULL;
 
/*
 * Initialization arguments for the entries to be registered
 */
__FAR__ IRESMAN_Params ** RMAN_registryResmanArgs = NULL;

/*
 *   ========== RMAN_PARAMS ===========
 *   Module configuration for RMAN implementation
 *   It is set at design time by system integrator to adjust the behavior of 
 *   module to be optimal for its execution environment
 */
RMAN_Params RMAN_PARAMS = {
 
    /* size of the registry table */ 
    11,

    /* persistentAllocFxn */
    DSKT2_allocPersistent,
 
    /* persistentFreeFxn */
    DSKT2_freePersistent,
  
    /* yieldFxn */
    RMAN_yield,

    /* flag indicating if yield to same priority is allowed */
    FALSE,
};



static __FAR__ IRESMAN_Fxns * _entries[0 + 1];
static __FAR__ IRESMAN_Params * _params[0 + 1];

IRES_Status RMAN_autoRegister()
{
    /* Populate the RMAN_registryEntries etc tables, to be able to do 
       static registration of these arguments */ 
    IRES_Status status = IRES_OK;
    
    RMAN_numRegistryEntries = 0;


    RMAN_registryEntries = (IRESMAN_Fxns **)(&_entries);
    RMAN_registryResmanArgs = (IRESMAN_Params **)(&_params);

    return (status);
}

/*
 * ======== ti.sdo.fc.global.Settings TEMPLATE ========
 */

Bool ti_sdo_fc_multiProcess = TRUE;

/*
 * ======== ti.sdo.utils.trace.GT TEMPLATE ========
 */




/*
 * C code contribution from ti/sdo/utils/GT.xdt 
 */
#include <xdc/std.h>
#include <ti/sdo/utils/trace/gt.h>

extern Void GTConfig_sysPrintf(String fmt, ...); 
extern Ptr GTConfig_biosMemAlloc(Int size);
 
extern Int GTConfig_tskId(void);
extern void GTConfig_sysPrintfError(String fmt, ...);
extern void GTConfig_biosMemFree(Ptr, Int);
extern UInt32 GTConfig_getTime(void);
extern Int GTConfig_semPend(void);
extern Int GTConfig_semPost(void);
extern Int GTConfig_biosInit(void);

GT_Config _ti_sdo_utils_trace_GT_params = {
    GTConfig_sysPrintf,
    NULL,
    GTConfig_tskId,
    GTConfig_sysPrintfError,
    GTConfig_biosMemAlloc,
    GTConfig_biosMemFree,
    GTConfig_getTime,
    GTConfig_semPend,
    GTConfig_semPost,
    GTConfig_biosInit    
};

GT_Config *GT = &_ti_sdo_utils_trace_GT_params;

/*
 * ======== ti.sdo.ce.node.NODE TEMPLATE ========
 */

/*
 *  ======== NODE Configuration ========
 *  Do not modify following; it is automatically generated from the template
 *  NODE.xdt in the ti.sdo.ce.node package and will be overwritten next time the
 *  executable is configured
 */
#include <ti/sdo/ce/node/node.h>

NODE_Config NODE_config = {
    0,       /* allocate node instances from this MEM seg id */
    0,   /* Segment to allocate message frames */
    0, /* if >0, size NODE must use with MSGQ_alloc */
};
NODE_Config *NODE = &NODE_config;

/*
 * ======== ti.sdo.ce.ipc.dsplink.dsp.Settings TEMPLATE ========
 */


/*
 * ======== ti.sdo.ce.ipc.bios.Ipc TEMPLATE ========
 */


/* IPC_generatedInit() function, called by CERuntime_init() */

Void IPC_generatedInit()
{
    extern Void DSPLINK_init();

    /* call Link's init function */
    DSPLINK_init();
}

/* configuration for interprocessor communication */

/* size of the communication message */
UInt32 Comm_MSGSIZE = 4096;


/* MSGQ and POOL configuration on the DSP when DSPLINK is used */

#include <ti/bios/include/std.h>
#include <ti/bios/include/msgq.h>
#include <ti/bios/include/pool.h>

/*
 * MSGQ configuration
 * ==================
 */
/* number of message queues and storage for them */
#define Global_NUMMSGQUEUES 64

static MSGQ_Obj Global_msgQueues[Global_NUMMSGQUEUES];

/* transport params */
typedef struct Global_ZCPYMQT_Params_tag {
    UInt32 poolId;
} Global_ZCPYMQT_Params;

static Global_ZCPYMQT_Params Global_mqtParams = {
    0   /* pool id; index into POOL_config.allocators[] */
};

/* processor IDs defined by DSPLINK */
#define Global_MAX_PROCESSORS 2
#define Global_ID_GPP         1

/* MSGQ transport functions defined by DSPLINK */
extern Void               ZCPYMQT_init();
extern MSGQ_TransportFxns ZCPYMQT_FXNS;

/* MSGQ transport objects */
static MSGQ_TransportObj Global_transports[Global_MAX_PROCESSORS] =
{
     MSGQ_NOTRANSPORT,     /* Represents the local processor */
     {
        ZCPYMQT_init,      /* Init Function                 */
        &ZCPYMQT_FXNS,     /* Transport interface functions */
        &Global_mqtParams, /* Transport params              */
        NULL,              /* Filled in by transport        */
        Global_ID_GPP      /* remote processor Id           */
     }
};

/* MSGQ object configuration */
MSGQ_Config MSGQ_config = {
    Global_msgQueues,      /* storage for message queue handles */
    Global_transports,     /* indexed array of transports */
    Global_NUMMSGQUEUES,   /* number of message queue handles (above) */
    Global_MAX_PROCESSORS, /* number of processors */
    0,                     /* startUnitialized ??? */
    MSGQ_INVALIDMSGQ,      /* errorQueue to recieve async transport errors */
    POOL_INVALIDID         /* errorPoolId to alloc error messges from */
};

 /*
 * POOL configuration
 * ==================
 */

/* number of pools */
#define Global_NUMALLOCATORS 1

/* SMAPOOL params */
typedef struct Global_SMAPOOL_Params_tag {
    Uint16     poolId ;
    Bool       exactMatchReq ;
} Global_SMAPOOL_Params ;

static Global_SMAPOOL_Params Global_smaPoolParams =
{
    0, /* Pool ID */
    TRUE
} ;

/* DSPLINK's SMAPOOL declarations */
extern Void SMAPOOL_init();
extern POOL_Fxns SMAPOOL_FXNS;

/* pools themselves */
static POOL_Obj Global_pools[Global_NUMALLOCATORS] =
{
    {
        &SMAPOOL_init,              /* Init Function                      */
        &SMAPOOL_FXNS,              /* Pool interface functions           */
        &Global_smaPoolParams,      /* Pool params                        */
        NULL                        /* Pool object: Set within pool impl. */
    }
};

/* POOL object configuration */
POOL_Config POOL_config = {
    Global_pools,
    Global_NUMALLOCATORS
};




/*
 * ======== ti.sdo.ce.alg.Settings TEMPLATE ========
 */

unsigned int ti_sdo_ce_alg_ALG_useHeap = FALSE;
unsigned int ti_sdo_ce_alg_ALG_useCache = FALSE;

unsigned int ti_sdo_ce_alg_ALG_maxGroups = 20; 

UInt32 ti_sdo_ce_alg_ipcKey = 0x4f474c41;

int _ALG_groupUsed[20] = {
     1,
     1,
     1,
     1,
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



/*
 * ======== ti.sdo.ce.osal.bios.Settings TEMPLATE ========
 */


/*
 * ======== Socrates logging configuration ========
 */
#include <ti/sdo/ce/osal/Log.h>
#include <ti/bios/include/log.h>

extern far LOG_Obj ti_sdo_ce_osal_LOG_Buffer;
far Log_Handle ti_sdo_ce_dvtLog = (Log_Handle)&ti_sdo_ce_osal_LOG_Buffer;


/* Number of BIOS heaps */
Int Memory_numHeaps = 3;

/* Array containing the names of the BIOS heaps. */
String Memory_heapNames[3];

/*
 *  These arrays will contain the original base address and size of each heap.
 */
Uint32 Memory_heapBases[3];
Uint32 Memory_heapSizes[3];

/*
 *  BIOS heap segments.
 */
extern Int DDR2;
extern Int L1DSRAM;
extern Int DDRALGHEAP;

/*
 *  ======== ti_sdo_ce_osal_bios_init ========
 *  Generated init function for BIOS OSAL.
 */
Void ti_sdo_ce_osal_bios_init()
{
    Memory_heapNames[DDR2] = "DDR2";
    Memory_heapNames[L1DSRAM] = "L1DSRAM";
    Memory_heapNames[DDRALGHEAP] = "DDRALGHEAP";
}

/*
 *  Definition of the globally visible character buffer holding all trace
 *  data
 */
Char Global_traceBuffer[32768];
Int  Global_traceBufferSize = 32768;


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

