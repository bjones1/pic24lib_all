#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-app_semaphore2.mk)" "nbproject/Makefile-local-app_semaphore2.mk"
include nbproject/Makefile-local-app_semaphore2.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=app_semaphore2
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/app_flashled.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/app_flashled.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../esos/src/esos.c ../../esos/src/esos_comm.c ../../esos/src/pic24/esos_pic24_irq.c ../../esos/src/pic24/esos_pic24_rs232.c ../../esos/src/pic24/esos_pic24_tick.c ../../esos/src/pic24/esos_pic24_i2c.c ../../esos/src/pic24/esos_pic24_spi.c ../app_semaphore2.c ../../lib/common/pic24_clockfreq.c ../../lib/common/pic24_configbits.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1022787335/esos.o ${OBJECTDIR}/_ext/1022787335/esos_comm.o ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o ${OBJECTDIR}/_ext/1472/app_semaphore2.o ${OBJECTDIR}/_ext/1047321003/pic24_clockfreq.o ${OBJECTDIR}/_ext/1047321003/pic24_configbits.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1022787335/esos.o.d ${OBJECTDIR}/_ext/1022787335/esos_comm.o.d ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d ${OBJECTDIR}/_ext/1472/app_semaphore2.o.d ${OBJECTDIR}/_ext/1047321003/pic24_clockfreq.o.d ${OBJECTDIR}/_ext/1047321003/pic24_configbits.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1022787335/esos.o ${OBJECTDIR}/_ext/1022787335/esos_comm.o ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o ${OBJECTDIR}/_ext/1472/app_semaphore2.o ${OBJECTDIR}/_ext/1047321003/pic24_clockfreq.o ${OBJECTDIR}/_ext/1047321003/pic24_configbits.o

# Source Files
SOURCEFILES=../../esos/src/esos.c ../../esos/src/esos_comm.c ../../esos/src/pic24/esos_pic24_irq.c ../../esos/src/pic24/esos_pic24_rs232.c ../../esos/src/pic24/esos_pic24_tick.c ../../esos/src/pic24/esos_pic24_i2c.c ../../esos/src/pic24/esos_pic24_spi.c ../app_semaphore2.c ../../lib/common/pic24_clockfreq.c ../../lib/common/pic24_configbits.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
	${MAKE} ${MAKE_OPTIONS} -f nbproject/Makefile-app_semaphore2.mk dist/${CND_CONF}/${IMAGE_TYPE}/app_flashled.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24HJ32GP202
MP_LINKER_FILE_OPTION=,--script=p24HJ32GP202.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1022787335/esos.o: ../../esos/src/esos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1022787335 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/esos.c  -o ${OBJECTDIR}/_ext/1022787335/esos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1022787335/esos.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022787335/esos.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1022787335/esos_comm.o: ../../esos/src/esos_comm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1022787335 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_comm.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/esos_comm.c  -o ${OBJECTDIR}/_ext/1022787335/esos_comm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1022787335/esos_comm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022787335/esos_comm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o: ../../esos/src/pic24/esos_pic24_irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/750133316 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_irq.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o: ../../esos/src/pic24/esos_pic24_rs232.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/750133316 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_rs232.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o: ../../esos/src/pic24/esos_pic24_tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/750133316 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_tick.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o: ../../esos/src/pic24/esos_pic24_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/750133316 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_i2c.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o: ../../esos/src/pic24/esos_pic24_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/750133316 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_spi.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/app_semaphore2.o: ../app_semaphore2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/app_semaphore2.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../app_semaphore2.c  -o ${OBJECTDIR}/_ext/1472/app_semaphore2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/app_semaphore2.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/app_semaphore2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1047321003/pic24_clockfreq.o: ../../lib/common/pic24_clockfreq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1047321003 
	@${RM} ${OBJECTDIR}/_ext/1047321003/pic24_clockfreq.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/common/pic24_clockfreq.c  -o ${OBJECTDIR}/_ext/1047321003/pic24_clockfreq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1047321003/pic24_clockfreq.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1047321003/pic24_clockfreq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1047321003/pic24_configbits.o: ../../lib/common/pic24_configbits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1047321003 
	@${RM} ${OBJECTDIR}/_ext/1047321003/pic24_configbits.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/common/pic24_configbits.c  -o ${OBJECTDIR}/_ext/1047321003/pic24_configbits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1047321003/pic24_configbits.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1047321003/pic24_configbits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/1022787335/esos.o: ../../esos/src/esos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1022787335 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/esos.c  -o ${OBJECTDIR}/_ext/1022787335/esos.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1022787335/esos.o.d"      -g -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022787335/esos.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1022787335/esos_comm.o: ../../esos/src/esos_comm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1022787335 
	@${RM} ${OBJECTDIR}/_ext/1022787335/esos_comm.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/esos_comm.c  -o ${OBJECTDIR}/_ext/1022787335/esos_comm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1022787335/esos_comm.o.d"      -g -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1022787335/esos_comm.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o: ../../esos/src/pic24/esos_pic24_irq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/750133316 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_irq.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d"      -g -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_irq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o: ../../esos/src/pic24/esos_pic24_rs232.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/750133316 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_rs232.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d"      -g -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_rs232.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o: ../../esos/src/pic24/esos_pic24_tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/750133316 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_tick.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d"      -g -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_tick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o: ../../esos/src/pic24/esos_pic24_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/750133316 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_i2c.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d"      -g -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o: ../../esos/src/pic24/esos_pic24_spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/750133316 
	@${RM} ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../esos/src/pic24/esos_pic24_spi.c  -o ${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d"      -g -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/750133316/esos_pic24_spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/app_semaphore2.o: ../app_semaphore2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/app_semaphore2.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../app_semaphore2.c  -o ${OBJECTDIR}/_ext/1472/app_semaphore2.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/app_semaphore2.o.d"      -g -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/app_semaphore2.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1047321003/pic24_clockfreq.o: ../../lib/common/pic24_clockfreq.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1047321003 
	@${RM} ${OBJECTDIR}/_ext/1047321003/pic24_clockfreq.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/common/pic24_clockfreq.c  -o ${OBJECTDIR}/_ext/1047321003/pic24_clockfreq.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1047321003/pic24_clockfreq.o.d"      -g -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1047321003/pic24_clockfreq.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1047321003/pic24_configbits.o: ../../lib/common/pic24_configbits.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1047321003 
	@${RM} ${OBJECTDIR}/_ext/1047321003/pic24_configbits.o.d 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../../lib/common/pic24_configbits.c  -o ${OBJECTDIR}/_ext/1047321003/pic24_configbits.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1047321003/pic24_configbits.o.d"      -g -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -O0 -I"../../lib/include" -I"../../esos/include" -I"../../esos/include/pic24" -I"../../esos/include/pc" -msmart-io=1 -Wall -msfr-warn=off
	@${FIXDEPS} "${OBJECTDIR}/_ext/1047321003/pic24_configbits.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/app_flashled.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/app_flashled.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -Wl,--defsym=__MPLAB_BUILD=1,--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/app_flashled.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/app_flashled.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=coff -DBUILT_ON_ESOS -D_NOASSERT -Wl,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/app_flashled.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=coff 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/app_semaphore2
	${RM} -r dist/app_semaphore2

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif