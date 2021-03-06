BASEDIR=../../..
OUTDIR= $(BASEDIR)/output
CC=gcc
CPP=g++
LN=g++
AR=ar
CP=cp
LNK=ln

DFB_OUTDIR= $(OUTDIR)/performance
DFB_OUTDIR_RELEASE = $(DFB_OUTDIR)/release

TARGET_ARCH= x64Linux2.6gcc4.7.2

DFB_SED_OUTPUT_DIR_RELEASE= $(subst /,\\/,$(DFB_OUTDIR_RELEASE))

DFB_EXE_DIR= $(BASEDIR)/utils/performanceTests/PerformanceDFB/performanceDFB-$(TARGET_ARCH)/

DFB_TARGET_EXE= $(DFB_EXE_DIR)performanceDFB.o

DFB_CFLAGS += -c -Wall -O2 -m64 -fpic -std=c++11
DFB_LDFLAGS=-m64

DFB_LIBS= $(LIBS) -lcdr -ldfb -lboost_timer -lboost_chrono -lboost_system

DFB_LIBS_DIR= -L$(BASEDIR)/lib/$(TARGET_ARCH) -L$(BASEDIR)/../CDR/lib/$(TARGET_ARCH) -I/usr/lib64

DFB_INCLUDE_DIRS= $(INCLUDE_DIRS) -I$(BASEDIR)/include -I$(BASEDIR)/include/cpp \
		  -I$(EPROSIMADIR)/code -I$(BASEDIR)/../CDR/include  -I/usr/include

DFB_SRC_CPPFILES= $(BASEDIR)/utils/performanceTests/PerformanceDFB/main.cpp

# Project sources are copied to the current directory
DFB_SRCS= $(DFB_SRC_CFILES) $(DFB_SRC_CPPFILES)

# Source directories
DFB_SOURCES_DIRS_AUX= $(foreach srcdir, $(dir $(DFB_SRCS)), $(srcdir))
DFB_SOURCES_DIRS= $(shell echo $(DFB_SOURCES_DIRS_AUX) | tr " " "\n" | sort | uniq | tr "\n" " ")

DFB_OBJS_RELEASE = $(foreach obj,$(notdir $(addsuffix .o, $(basename $(DFB_SRCS)))), $(DFB_OUTDIR_RELEASE)/$(obj))
DFB_DEPS_RELEASE = $(foreach dep,$(notdir $(addsuffix .d, $(basename $(DFB_SRCS)))), $(DFB_OUTDIR_RELEASE)/$(dep))
DFB_EXE_RELEASE = $(foreach obj,$(notdir $(addsuffix .o, $(basename $(DFB_SRCS)))), $(DFB_OUTDIR_RELEASE)/$(obj))

OBJS+= $(DFB_OBJS_RELEASE)
DEPS+= $(DFB_DEPS_RELEASE)

all: checkDFBDirectories $(DFB_TARGET_EXE)

checkDFBDirectories:
	@mkdir -p $(OUTDIR)
	@mkdir -p $(DFB_OUTDIR)
	@mkdir -p $(DFB_OUTDIR_RELEASE)
	@mkdir -p lib
	@mkdir -p lib/$(TARGET_ARCH)
	@mkdir -p $(DFB_EXE_DIR)

$(DFB_TARGET_EXE): $(DFB_EXE_RELEASE)
	$(LN) $(DFB_LDFLAGS) -o $(DFB_TARGET_EXE) $(DFB_LIBS_DIR) $(DFB_LIBS) $(DFB_EXE_RELEASE) -pthread -lrt

vpath %.cpp $(DFB_SOURCES_DIRS)

$(DFB_OUTDIR_RELEASE)/%.o:%.cpp
	@echo Calculating dependencies \(RELEASE mode\) $<
	@$(CPP) $(DFB_CFLAGS) -MM $(DFB_INCLUDE_DIRS) $< | sed "s/^.*:/$(DFB_SED_OUTPUT_DIR_RELEASE)\/&/g" > $(@:%.o=%.d)
	@echo Compiling \(RELEASE mode\) $<
	$(CPP) $(DFB_CFLAGS) $(DFB_INCLUDE_DIRS) $< -o $@

