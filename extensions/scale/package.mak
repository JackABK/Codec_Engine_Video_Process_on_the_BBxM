#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
override PKGDIR = ti/sdo/ce/examples/extensions/scale
XDCINCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(XPKGPATH))))
XDCCFGDIR = package/cfg/

#
# The following dependencies ensure package.mak is rebuilt
# in the event that some included BOM script changes.
#
ifneq (clean,$(MAKECMDGOALS))
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/include/utils.tci:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/include/utils.tci
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/IPackage.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/IPackage.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/targets/MSP430_large_code.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/targets/MSP430_large_code.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/xmlgen2.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/xmlgen2.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/om2.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/om2.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/xdc.tci:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/xdc.tci
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/Script.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/Script.xs
package.mak: package.bld
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/targets/ITarget.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/targets/ITarget.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/targets/package.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/targets/package.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/config.bld:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/config.bld
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/template.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/template.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/targets/MSP430_large_data.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/targets/MSP430_large_data.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/MVArm9.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/MVArm9.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/Executable.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/Executable.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/Linux86.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/Linux86.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/ITargetFilter.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/ITargetFilter.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/services/global/Clock.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/services/global/Clock.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/UCArm9.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/UCArm9.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/arm/GCArmv6.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/arm/GCArmv6.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/Utils.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/Utils.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/arm/GCArmv7A.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/arm/GCArmv7A.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/xmlgen.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/xmlgen.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/Repository.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/Repository.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/package.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/package.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/ITarget.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/ITarget.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/PackageContents.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/PackageContents.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/BuildEnvironment.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/BuildEnvironment.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/services/global/Trace.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/services/global/Trace.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/Library.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/Library.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/_gen.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/_gen.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/ITarget.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/ITarget.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/package.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/package.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/package.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/xdc/bld/package.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/buildutils/Platforms.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/codec-engine_2_26_01_09/examples/ti/sdo/ce/examples/buildutils/Platforms.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/Mingw.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/Mingw.xs
/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/targets/MSP430.xs:
package.mak: /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/targets/MSP430.xs
endif

gnu.targets.arm.GCArmv5T.rootDir ?= /home/jack/CodeSourcery/Sourcery_G++_Lite/
gnu.targets.arm.packageBase ?= /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/gnu/targets/arm/
ti.targets.C64P.rootDir ?= /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/cgt6x_6_1_14
ti.targets.packageBase ?= /home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/xdctools_3_16_03_36/packages/ti/targets/
.PRECIOUS: $(XDCCFGDIR)/%.ov5T
.PHONY: all,v5T .dlls,v5T .executables,v5T test,v5T
all,v5T: .executables,v5T
.executables,v5T: .libraries,v5T
.executables,v5T: .dlls,v5T
.dlls,v5T: .libraries,v5T
.libraries,v5T: .interfaces
	@$(RM) $@
	@$(TOUCH) "$@"

.help::
	@$(ECHO) xdc test,v5T
	@$(ECHO) xdc .executables,v5T
	@$(ECHO) xdc .libraries,v5T
	@$(ECHO) xdc .dlls,v5T

.PRECIOUS: $(XDCCFGDIR)/%.o64P
.PHONY: all,64P .dlls,64P .executables,64P test,64P
all,64P: .executables,64P
.executables,64P: .libraries,64P
.executables,64P: .dlls,64P
.dlls,64P: .libraries,64P
.libraries,64P: .interfaces
	@$(RM) $@
	@$(TOUCH) "$@"

.help::
	@$(ECHO) xdc test,64P
	@$(ECHO) xdc .executables,64P
	@$(ECHO) xdc .libraries,64P
	@$(ECHO) xdc .dlls,64P


all: .executables 
.executables: .libraries .dlls
.libraries: .interfaces

PKGCFGS := $(wildcard package.xs) package/build.cfg
.interfaces: package/package.xdc.inc package/package.defs.h package.xdc $(PKGCFGS)

-include package/package.xdc.dep
package/%.xdc.inc package/%_ti.sdo.ce.examples.extensions.scale.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package ti.sdo.ce.examples.extensions.scale" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs $(MK_IDLOPTS) -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

ifneq (clean,$(MAKECMDGOALS))
-include package/package.cfg.dep
endif

package/package.ext.xml: package/package.cfg.xdc.inc
package/package.cfg.xdc.inc: $(XDCROOT)/packages/xdc/cfg/cfginc.js package.xdc
	@$(MSG) generating schema include file list ...
	$(CONFIG) -f $(XDCROOT)/packages/xdc/cfg/cfginc.js ti.sdo.ce.examples.extensions.scale $@

.libraries,v5T .libraries: lib/scale.av5T

-include lib/scale.av5T.mak
lib/scale.av5T: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/scale/scale.ov5T package/lib/lib/scale/package/package_ti.sdo.ce.examples.extensions.scale.ov5T package/lib/lib/scale/scale_skel.ov5T package/lib/lib/scale/scale_stubs.ov5T  into $@ ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/arm-none-linux-gnueabi/bin/ar  cr $@   package/lib/lib/scale/scale.ov5T package/lib/lib/scale/package/package_ti.sdo.ce.examples.extensions.scale.ov5T package/lib/lib/scale/scale_skel.ov5T package/lib/lib/scale/scale_stubs.ov5T 
lib/scale.av5T:LD_LIBRARY_PATH=

clean,v5T clean::
	-$(RM) lib/scale.av5T
.libraries,64P .libraries: lib/scale_debug.a64P

-include lib/scale_debug.a64P.mak
lib/scale_debug.a64P: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/scale_debug/scale.o64P package/lib/lib/scale_debug/package/package_ti.sdo.ce.examples.extensions.scale.o64P package/lib/lib/scale_debug/scale_skel.o64P package/lib/lib/scale_debug/scale_stubs.o64P  into $@ ...
	$(ti.targets.C64P.rootDir)/bin/ar6x  rq $@   package/lib/lib/scale_debug/scale.o64P package/lib/lib/scale_debug/package/package_ti.sdo.ce.examples.extensions.scale.o64P package/lib/lib/scale_debug/scale_skel.o64P package/lib/lib/scale_debug/scale_stubs.o64P 
lib/scale_debug.a64P:C_DIR=
lib/scale_debug.a64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

clean,64P clean::
	-$(RM) lib/scale_debug.a64P
.libraries,64P .libraries: lib/scale.a64P

-include lib/scale.a64P.mak
lib/scale.a64P: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/scale/scale.o64P package/lib/lib/scale/package/package_ti.sdo.ce.examples.extensions.scale.o64P package/lib/lib/scale/scale_skel.o64P package/lib/lib/scale/scale_stubs.o64P  into $@ ...
	$(ti.targets.C64P.rootDir)/bin/ar6x  rq $@   package/lib/lib/scale/scale.o64P package/lib/lib/scale/package/package_ti.sdo.ce.examples.extensions.scale.o64P package/lib/lib/scale/scale_skel.o64P package/lib/lib/scale/scale_stubs.o64P 
lib/scale.a64P:C_DIR=
lib/scale.a64P: PATH:=$(ti.targets.C64P.rootDir)/bin/:$(PATH)

clean,64P clean::
	-$(RM) lib/scale.a64P
.libraries,v5T .libraries: lib/scale_debug.av5T

-include lib/scale_debug.av5T.mak
lib/scale_debug.av5T: 
	$(RM) $@
	@$(MSG) archiving package/lib/lib/scale_debug/scale.ov5T package/lib/lib/scale_debug/package/package_ti.sdo.ce.examples.extensions.scale.ov5T package/lib/lib/scale_debug/scale_skel.ov5T package/lib/lib/scale_debug/scale_stubs.ov5T  into $@ ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/arm-none-linux-gnueabi/bin/ar  cr $@   package/lib/lib/scale_debug/scale.ov5T package/lib/lib/scale_debug/package/package_ti.sdo.ce.examples.extensions.scale.ov5T package/lib/lib/scale_debug/scale_skel.ov5T package/lib/lib/scale_debug/scale_stubs.ov5T 
lib/scale_debug.av5T:LD_LIBRARY_PATH=

clean,v5T clean::
	-$(RM) lib/scale_debug.av5T
test:;
%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@
.PHONY: package_ti.sdo.ce.examples.extensions.scale.ov5T,copy
package_ti.sdo.ce.examples.extensions.scale.ov5T,copy : package_ti.sdo.ce.examples.extensions.scale.ov5T,0,copy package_ti.sdo.ce.examples.extensions.scale.ov5T,1,copy 
	@

package_ti.sdo.ce.examples.extensions.scale.ov5T,0,copy : package/lib/lib/scale/package/package_ti.sdo.ce.examples.extensions.scale.ov5T
package_ti.sdo.ce.examples.extensions.scale.ov5T,1,copy : package/lib/lib/scale_debug/package/package_ti.sdo.ce.examples.extensions.scale.ov5T
.PHONY: scale_stubs.ov5T,copy
scale_stubs.ov5T,copy : scale_stubs.ov5T,0,copy scale_stubs.ov5T,1,copy 
	@

scale_stubs.ov5T,0,copy : package/lib/lib/scale/scale_stubs.ov5T
scale_stubs.ov5T,1,copy : package/lib/lib/scale_debug/scale_stubs.ov5T
.PHONY: package_ti.sdo.ce.examples.extensions.scale.sv5T,copy
package_ti.sdo.ce.examples.extensions.scale.sv5T,copy : package_ti.sdo.ce.examples.extensions.scale.sv5T,0,copy package_ti.sdo.ce.examples.extensions.scale.sv5T,1,copy 
	@

package_ti.sdo.ce.examples.extensions.scale.sv5T,0,copy : package/lib/lib/scale/package/package_ti.sdo.ce.examples.extensions.scale.sv5T
package_ti.sdo.ce.examples.extensions.scale.sv5T,1,copy : package/lib/lib/scale_debug/package/package_ti.sdo.ce.examples.extensions.scale.sv5T
.PHONY: scale_stubs.sv5T,copy
scale_stubs.sv5T,copy : scale_stubs.sv5T,0,copy scale_stubs.sv5T,1,copy 
	@

scale_stubs.sv5T,0,copy : package/lib/lib/scale/scale_stubs.sv5T
scale_stubs.sv5T,1,copy : package/lib/lib/scale_debug/scale_stubs.sv5T
.PHONY: scale.ov5T,copy
scale.ov5T,copy : scale.ov5T,0,copy scale.ov5T,1,copy 
	@

scale.ov5T,0,copy : package/lib/lib/scale/scale.ov5T
scale.ov5T,1,copy : package/lib/lib/scale_debug/scale.ov5T
.PHONY: scale.sv5T,copy
scale.sv5T,copy : scale.sv5T,0,copy scale.sv5T,1,copy 
	@

scale.sv5T,0,copy : package/lib/lib/scale/scale.sv5T
scale.sv5T,1,copy : package/lib/lib/scale_debug/scale.sv5T
.PHONY: scale_skel.ov5T,copy
scale_skel.ov5T,copy : scale_skel.ov5T,0,copy scale_skel.ov5T,1,copy 
	@

scale_skel.ov5T,0,copy : package/lib/lib/scale/scale_skel.ov5T
scale_skel.ov5T,1,copy : package/lib/lib/scale_debug/scale_skel.ov5T
.PHONY: scale_skel.sv5T,copy
scale_skel.sv5T,copy : scale_skel.sv5T,0,copy scale_skel.sv5T,1,copy 
	@

scale_skel.sv5T,0,copy : package/lib/lib/scale/scale_skel.sv5T
scale_skel.sv5T,1,copy : package/lib/lib/scale_debug/scale_skel.sv5T
.PHONY: package_ti.sdo.ce.examples.extensions.scale.o64P,copy
package_ti.sdo.ce.examples.extensions.scale.o64P,copy : package_ti.sdo.ce.examples.extensions.scale.o64P,0,copy package_ti.sdo.ce.examples.extensions.scale.o64P,1,copy 
	@

package_ti.sdo.ce.examples.extensions.scale.o64P,0,copy : package/lib/lib/scale/package/package_ti.sdo.ce.examples.extensions.scale.o64P
package_ti.sdo.ce.examples.extensions.scale.o64P,1,copy : package/lib/lib/scale_debug/package/package_ti.sdo.ce.examples.extensions.scale.o64P
.PHONY: scale_stubs.o64P,copy
scale_stubs.o64P,copy : scale_stubs.o64P,0,copy scale_stubs.o64P,1,copy 
	@

scale_stubs.o64P,0,copy : package/lib/lib/scale/scale_stubs.o64P
scale_stubs.o64P,1,copy : package/lib/lib/scale_debug/scale_stubs.o64P
.PHONY: package_ti.sdo.ce.examples.extensions.scale.s64P,copy
package_ti.sdo.ce.examples.extensions.scale.s64P,copy : package_ti.sdo.ce.examples.extensions.scale.s64P,0,copy package_ti.sdo.ce.examples.extensions.scale.s64P,1,copy 
	@

package_ti.sdo.ce.examples.extensions.scale.s64P,0,copy : package/lib/lib/scale/package/package_ti.sdo.ce.examples.extensions.scale.s64P
package_ti.sdo.ce.examples.extensions.scale.s64P,1,copy : package/lib/lib/scale_debug/package/package_ti.sdo.ce.examples.extensions.scale.s64P
.PHONY: scale_stubs.s64P,copy
scale_stubs.s64P,copy : scale_stubs.s64P,0,copy scale_stubs.s64P,1,copy 
	@

scale_stubs.s64P,0,copy : package/lib/lib/scale/scale_stubs.s64P
scale_stubs.s64P,1,copy : package/lib/lib/scale_debug/scale_stubs.s64P
.PHONY: scale.o64P,copy
scale.o64P,copy : scale.o64P,0,copy scale.o64P,1,copy 
	@

scale.o64P,0,copy : package/lib/lib/scale/scale.o64P
scale.o64P,1,copy : package/lib/lib/scale_debug/scale.o64P
.PHONY: scale.s64P,copy
scale.s64P,copy : scale.s64P,0,copy scale.s64P,1,copy 
	@

scale.s64P,0,copy : package/lib/lib/scale/scale.s64P
scale.s64P,1,copy : package/lib/lib/scale_debug/scale.s64P
.PHONY: scale_skel.o64P,copy
scale_skel.o64P,copy : scale_skel.o64P,0,copy scale_skel.o64P,1,copy 
	@

scale_skel.o64P,0,copy : package/lib/lib/scale/scale_skel.o64P
scale_skel.o64P,1,copy : package/lib/lib/scale_debug/scale_skel.o64P
.PHONY: scale_skel.s64P,copy
scale_skel.s64P,copy : scale_skel.s64P,0,copy scale_skel.s64P,1,copy 
	@

scale_skel.s64P,0,copy : package/lib/lib/scale/scale_skel.s64P
scale_skel.s64P,1,copy : package/lib/lib/scale_debug/scale_skel.s64P

$(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg .interfaces $(XDCROOT)/packages/xdc/cfg/Main.xs
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_XSOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,ti_sdo_ce_examples_extensions_scale
ti_sdo_ce_examples_extensions_scale.tar: lib/scale.a64P
ti_sdo_ce_examples_extensions_scale.tar: package/package.cfg.xdc.inc
ti_sdo_ce_examples_extensions_scale.tar: package/package.xdc.inc
ti_sdo_ce_examples_extensions_scale.tar: lib/scale_debug.av5T
ti_sdo_ce_examples_extensions_scale.tar: package/package.rel.dot
ti_sdo_ce_examples_extensions_scale.tar: scale.h
ti_sdo_ce_examples_extensions_scale.tar: package/package.bld.xml
ti_sdo_ce_examples_extensions_scale.tar: lib/scale_debug.a64P
ti_sdo_ce_examples_extensions_scale.tar: lib/scale.av5T
ti_sdo_ce_examples_extensions_scale.tar: package/package.ext.xml
ti_sdo_ce_examples_extensions_scale.tar: package/build.cfg
ifneq (clean,$(MAKECMDGOALS))
-include package/rel/ti_sdo_ce_examples_extensions_scale.tar.dep
endif
package/rel/ti_sdo_ce_examples_extensions_scale/ti/sdo/ce/examples/extensions/scale/package/package.rel.xml:

ti_sdo_ce_examples_extensions_scale.tar: package/rel/ti_sdo_ce_examples_extensions_scale.xdc.inc package/rel/ti_sdo_ce_examples_extensions_scale/ti/sdo/ce/examples/extensions/scale/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKRELTAR,package/rel/ti_sdo_ce_examples_extensions_scale.xdc.inc,package/rel/ti_sdo_ce_examples_extensions_scale.tar.dep)


release release,ti_sdo_ce_examples_extensions_scale: all ti_sdo_ce_examples_extensions_scale.tar
clean:: .clean
	-$(RM) ti_sdo_ce_examples_extensions_scale.tar
	-$(RM) package/rel/ti_sdo_ce_examples_extensions_scale.xdc.inc
	-$(RM) package/rel/ti_sdo_ce_examples_extensions_scale.tar.dep

clean:: .clean
	-$(RM) .libraries .libraries,*
clean:: 
	-$(RM) .dlls .dlls,*
#
# The following clean rule removes user specified
# generated files or directories.
#

ifneq (clean,$(MAKECMDGOALS))
ifeq (,$(wildcard package))
    $(shell $(MKDIR) package)
endif
ifeq (,$(wildcard package/lib))
    $(shell $(MKDIR) package/lib)
endif
ifeq (,$(wildcard package/lib/lib))
    $(shell $(MKDIR) package/lib/lib)
endif
ifeq (,$(wildcard package/lib/lib/scale_debug))
    $(shell $(MKDIR) package/lib/lib/scale_debug)
endif
ifeq (,$(wildcard package/lib/lib/scale))
    $(shell $(MKDIR) package/lib/lib/scale)
endif
ifeq (,$(wildcard package/rel))
    $(shell $(MKDIR) package/rel)
endif
ifeq (,$(wildcard lib))
    $(shell $(MKDIR) lib)
endif
ifeq (,$(wildcard package/cfg))
    $(shell $(MKDIR) package/cfg)
endif
ifeq (,$(wildcard package/external))
    $(shell $(MKDIR) package/external)
endif
ifeq (,$(wildcard package/lib/lib/scale/package))
    $(shell $(MKDIR) package/lib/lib/scale/package)
endif
ifeq (,$(wildcard package/internal))
    $(shell $(MKDIR) package/internal)
endif
ifeq (,$(wildcard package/lib/lib/scale_debug/package))
    $(shell $(MKDIR) package/lib/lib/scale_debug/package)
endif
endif
clean::
	-$(RMDIR) package


clean:: 
	-$(RM) package/ti.sdo.ce.examples.extensions.scale.pjt