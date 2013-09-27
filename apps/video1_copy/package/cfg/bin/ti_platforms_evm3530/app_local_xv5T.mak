#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = gnu.targets.arm.GCArmv5T{1,0,4.3,2
#
ifneq (clean,$(MAKECMDGOALS))
-include package/cfg/bin/ti_platforms_evm3530/app_local/main_native.ov5T.dep
endif

package/cfg/bin/ti_platforms_evm3530/app_local/main_native.ov5T: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local/main_native.ov5T: main_native.c package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-g++ -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing -I/home/jack/new/arm/4.3.2/arm-none-linux-gnueabi/include/opencv   -I/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/include/qtopia/QtGui/ -I/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/include/qtopia  -L/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/lib -march=armv5t -Dfar=   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/video1_copy/package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.h'  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_2 -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local/main_native.ov5T:LD_LIBRARY_PATH=

package/cfg/bin/ti_platforms_evm3530/app_local/main_native.sv5T: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local/main_native.sv5T: main_native.c package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T -S $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-g++ -c -MD -MF $@.dep -x c -S -fPIC -Wunused -Wall -fno-strict-aliasing -I/home/jack/new/arm/4.3.2/arm-none-linux-gnueabi/include/opencv   -I/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/include/qtopia/QtGui/ -I/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/include/qtopia  -L/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/lib -march=armv5t -Dfar=   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/video1_copy/package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.h'  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_2 -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local/main_native.sv5T:LD_LIBRARY_PATH=

ifneq (clean,$(MAKECMDGOALS))
-include package/cfg/bin/ti_platforms_evm3530/app_local/app.ov5T.dep
endif

package/cfg/bin/ti_platforms_evm3530/app_local/app.ov5T: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local/app.ov5T: app.c package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-g++ -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing -I/home/jack/new/arm/4.3.2/arm-none-linux-gnueabi/include/opencv   -I/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/include/qtopia/QtGui/ -I/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/include/qtopia  -L/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/lib -march=armv5t -Dfar=   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/video1_copy/package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.h'  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_2 -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local/app.ov5T:LD_LIBRARY_PATH=

package/cfg/bin/ti_platforms_evm3530/app_local/app.sv5T: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local/app.sv5T: app.c package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T -S $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-g++ -c -MD -MF $@.dep -x c -S -fPIC -Wunused -Wall -fno-strict-aliasing -I/home/jack/new/arm/4.3.2/arm-none-linux-gnueabi/include/opencv   -I/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/include/qtopia/QtGui/ -I/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/include/qtopia  -L/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/lib -march=armv5t -Dfar=   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/video1_copy/package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.h'  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_2 -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local/app.sv5T:LD_LIBRARY_PATH=

ifneq (clean,$(MAKECMDGOALS))
-include package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.ov5T.dep
endif

package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.ov5T: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.ov5T: package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.c package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-g++ -c -MD -MF $@.dep -x c  -fPIC -Wunused -Wall -fno-strict-aliasing -I/home/jack/new/arm/4.3.2/arm-none-linux-gnueabi/include/opencv   -I/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/include/qtopia/QtGui/ -I/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/include/qtopia  -L/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/lib -march=armv5t -Dfar=   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/video1_copy/package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.h'  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_2 -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.ov5T:LD_LIBRARY_PATH=

package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.sv5T: | .interfaces
package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.sv5T: package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.c package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) clv5T -S $< ...
	$(gnu.targets.arm.GCArmv5T.rootDir)/bin/arm-none-linux-gnueabi-g++ -c -MD -MF $@.dep -x c -S -fPIC -Wunused -Wall -fno-strict-aliasing -I/home/jack/new/arm/4.3.2/arm-none-linux-gnueabi/include/opencv   -I/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/include/qtopia/QtGui/ -I/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/include/qtopia  -L/home/jack/ti-dvsdk_dm3730-evm_4_01_00_09/linux-devkit/arm-none-linux-gnueabi/usr/lib -march=armv5t -Dfar=   -Dxdc_cfg__header__='ti/sdo/ce/examples/apps/video1_copy/package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.h'  -Dxdc_target_name__=GCArmv5T -Dxdc_target_types__=gnu/targets/arm/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_4_3_2 -O2   $(XDCINCS)  -o $@ $<
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.sv5T:LD_LIBRARY_PATH=

clean,v5T ::
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local/main_native.ov5T
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local/app.ov5T
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.ov5T
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local/main_native.sv5T
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local/app.sv5T
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.sv5T

bin/ti_platforms_evm3530/app_local.xv5T: package/cfg/bin/ti_platforms_evm3530/app_local/main_native.ov5T package/cfg/bin/ti_platforms_evm3530/app_local/app.ov5T package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.ov5T package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.mak

clean::
	-$(RM) package/cfg/bin/ti_platforms_evm3530/app_local_xv5T.mak
