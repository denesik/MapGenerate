#############################################################################
# Makefile for building: MapGenerate
# Generated by qmake (3.0) (Qt 5.4.0)
# Project:  MapGenerate.pro
# Template: app
# Command: /home/denesik/Qt/5.4/gcc_64/bin/qmake -spec linux-g++ CONFIG+=debug -o Makefile MapGenerate.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -g -Wall -W -fPIE $(DEFINES)
CXXFLAGS      = -pipe -std=c++11 -g -Wall -W -fPIE $(DEFINES)
INCPATH       = -I../../../Qt/5.4/gcc_64/mkspecs/linux-g++ -I.
QMAKE         = /home/denesik/Qt/5.4/gcc_64/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = MapGenerate1.0.0
DISTDIR = /home/denesik/dev/sge/MapGenerate/.tmp/MapGenerate1.0.0
LINK          = g++
LFLAGS        = -Wl,-rpath,/home/denesik/Qt/5.4/gcc_64
LIBS          = $(SUBLIBS)  
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		voronoi/geometry.cpp \
		voronoi/Voronoi.cpp \
		lodepng/lodepng.cpp \
		Triangle.cpp 
OBJECTS       = main.o \
		geometry.o \
		Voronoi.o \
		lodepng.o \
		Triangle.o
DIST          = ../../../Qt/5.4/gcc_64/mkspecs/features/spec_pre.prf \
		../../../Qt/5.4/gcc_64/mkspecs/common/shell-unix.conf \
		../../../Qt/5.4/gcc_64/mkspecs/common/unix.conf \
		../../../Qt/5.4/gcc_64/mkspecs/common/linux.conf \
		../../../Qt/5.4/gcc_64/mkspecs/common/gcc-base.conf \
		../../../Qt/5.4/gcc_64/mkspecs/common/gcc-base-unix.conf \
		../../../Qt/5.4/gcc_64/mkspecs/common/g++-base.conf \
		../../../Qt/5.4/gcc_64/mkspecs/common/g++-unix.conf \
		../../../Qt/5.4/gcc_64/mkspecs/qconfig.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_core.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_declarative.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_enginio.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_help.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_location.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_location_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_network.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_script.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webchannel.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webkit.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/features/qt_functions.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/qt_config.prf \
		../../../Qt/5.4/gcc_64/mkspecs/linux-g++/qmake.conf \
		../../../Qt/5.4/gcc_64/mkspecs/features/spec_post.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/exclusive_builds.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/default_pre.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/resolve_config.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/default_post.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/warn_on.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/testcase_targets.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/exceptions.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/yacc.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/lex.prf \
		MapGenerate.pro voronoi/geometry.h \
		voronoi/Lloyd.h \
		voronoi/Voronoi.h \
		lodepng/lodepng.h \
		Triangle.h main.cpp \
		voronoi/geometry.cpp \
		voronoi/Voronoi.cpp \
		lodepng/lodepng.cpp \
		Triangle.cpp
QMAKE_TARGET  = MapGenerate
DESTDIR       = #avoid trailing-slash linebreak
TARGET        = MapGenerate


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: MapGenerate.pro ../../../Qt/5.4/gcc_64/mkspecs/linux-g++/qmake.conf ../../../Qt/5.4/gcc_64/mkspecs/features/spec_pre.prf \
		../../../Qt/5.4/gcc_64/mkspecs/common/shell-unix.conf \
		../../../Qt/5.4/gcc_64/mkspecs/common/unix.conf \
		../../../Qt/5.4/gcc_64/mkspecs/common/linux.conf \
		../../../Qt/5.4/gcc_64/mkspecs/common/gcc-base.conf \
		../../../Qt/5.4/gcc_64/mkspecs/common/gcc-base-unix.conf \
		../../../Qt/5.4/gcc_64/mkspecs/common/g++-base.conf \
		../../../Qt/5.4/gcc_64/mkspecs/common/g++-unix.conf \
		../../../Qt/5.4/gcc_64/mkspecs/qconfig.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_core.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_declarative.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_enginio.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_help.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_location.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_location_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_network.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_script.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webchannel.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webkit.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../../Qt/5.4/gcc_64/mkspecs/features/qt_functions.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/qt_config.prf \
		../../../Qt/5.4/gcc_64/mkspecs/linux-g++/qmake.conf \
		../../../Qt/5.4/gcc_64/mkspecs/features/spec_post.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/exclusive_builds.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/default_pre.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/resolve_config.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/default_post.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/warn_on.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/testcase_targets.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/exceptions.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/yacc.prf \
		../../../Qt/5.4/gcc_64/mkspecs/features/lex.prf \
		MapGenerate.pro
	$(QMAKE) -spec linux-g++ CONFIG+=debug -o Makefile MapGenerate.pro
../../../Qt/5.4/gcc_64/mkspecs/features/spec_pre.prf:
../../../Qt/5.4/gcc_64/mkspecs/common/shell-unix.conf:
../../../Qt/5.4/gcc_64/mkspecs/common/unix.conf:
../../../Qt/5.4/gcc_64/mkspecs/common/linux.conf:
../../../Qt/5.4/gcc_64/mkspecs/common/gcc-base.conf:
../../../Qt/5.4/gcc_64/mkspecs/common/gcc-base-unix.conf:
../../../Qt/5.4/gcc_64/mkspecs/common/g++-base.conf:
../../../Qt/5.4/gcc_64/mkspecs/common/g++-unix.conf:
../../../Qt/5.4/gcc_64/mkspecs/qconfig.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_clucene_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_concurrent.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_core.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_core_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_dbus.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_declarative.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_declarative_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_designer.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_designer_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_enginio.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_enginio_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_gui.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_gui_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_help.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_help_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_location.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_location_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_multimedia.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_network.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_network_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_nfc.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_opengl.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_platformsupport_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_positioning.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_printsupport.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qml.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qml_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qmltest.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quick.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quick_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_script.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_script_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_scripttools.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_sensors.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_serialport.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_sql.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_sql_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_svg.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_svg_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_testlib.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_uitools.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webchannel.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webkit.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webkit_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webkitwidgets.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_websockets.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_widgets.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_x11extras.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_xml.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_xml_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../../Qt/5.4/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../../Qt/5.4/gcc_64/mkspecs/features/qt_functions.prf:
../../../Qt/5.4/gcc_64/mkspecs/features/qt_config.prf:
../../../Qt/5.4/gcc_64/mkspecs/linux-g++/qmake.conf:
../../../Qt/5.4/gcc_64/mkspecs/features/spec_post.prf:
../../../Qt/5.4/gcc_64/mkspecs/features/exclusive_builds.prf:
../../../Qt/5.4/gcc_64/mkspecs/features/default_pre.prf:
../../../Qt/5.4/gcc_64/mkspecs/features/resolve_config.prf:
../../../Qt/5.4/gcc_64/mkspecs/features/default_post.prf:
../../../Qt/5.4/gcc_64/mkspecs/features/warn_on.prf:
../../../Qt/5.4/gcc_64/mkspecs/features/testcase_targets.prf:
../../../Qt/5.4/gcc_64/mkspecs/features/exceptions.prf:
../../../Qt/5.4/gcc_64/mkspecs/features/yacc.prf:
../../../Qt/5.4/gcc_64/mkspecs/features/lex.prf:
MapGenerate.pro:
qmake: FORCE
	@$(QMAKE) -spec linux-g++ CONFIG+=debug -o Makefile MapGenerate.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


####### Sub-libraries

check: first

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

main.o: main.cpp voronoi/Lloyd.h \
		voronoi/Voronoi.h \
		voronoi/geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

geometry.o: voronoi/geometry.cpp voronoi/geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o geometry.o voronoi/geometry.cpp

Voronoi.o: voronoi/Voronoi.cpp voronoi/Voronoi.h \
		voronoi/geometry.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Voronoi.o voronoi/Voronoi.cpp

lodepng.o: lodepng/lodepng.cpp lodepng/lodepng.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o lodepng.o lodepng/lodepng.cpp

Triangle.o: Triangle.cpp Triangle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Triangle.o Triangle.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
