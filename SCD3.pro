#-------------------------------------------------
#
# Project created by QtCreator 2018-12-13T19:49:36
#
#-------------------------------------------------

QT       += core gui
QT       += serialport
QT       += serialbus
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

# 指定编译程序名字
TARGET = SCD
# 程序类型为可执行程序
TEMPLATE = app
# 程序类型为静态库文件
# TEMPLATE = lib

# 指定自动生成的头文件位置
UI_DIR=./../SCD3/

# openssl
LIBS += -L./../SCD3/libs/ -llibcrypto

# 控制台程序
CONFIG += console
CONFIG += c++17
# CONFIG += staticlib
# DESTDIR 运行路径
# INCLUDEPATH 头文件路径
# LIBS += -L../../lib -lXXX


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# 使用opengl加速
DEFINES += QCUSTOMPLOT_USE_OPENGL

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RC_ICONS = logo.ico

SOURCES += \
        authwin.cpp \
        graphset.cpp \
        highlighter.cpp \
        inform.cpp \
        lua5_4/lapi.c \
        lua5_4/lauxlib.c \
        lua5_4/lbaselib.c \
        lua5_4/lcode.c \
        lua5_4/lcorolib.c \
        lua5_4/lctype.c \
        lua5_4/ldblib.c \
        lua5_4/ldebug.c \
        lua5_4/ldo.c \
        lua5_4/ldump.c \
        lua5_4/lfunc.c \
        lua5_4/lgc.c \
        lua5_4/linit.c \
        lua5_4/liolib.c \
        lua5_4/llex.c \
        lua5_4/lmathlib.c \
        lua5_4/lmem.c \
        lua5_4/loadlib.c \
        lua5_4/lobject.c \
        lua5_4/lopcodes.c \
        lua5_4/loslib.c \
        lua5_4/lparser.c \
        lua5_4/lstate.c \
        lua5_4/lstring.c \
        lua5_4/lstrlib.c \
        lua5_4/ltable.c \
        lua5_4/ltablib.c \
        lua5_4/ltm.c \
        lua5_4/lua.c \
        lua5_4/luac.c \
        lua5_4/lundump.c \
        lua5_4/lutf8lib.c \
        lua5_4/lvm.c \
        lua5_4/lzio.c \
        luaform.cpp \
        luascript.cpp \
        main.cpp \
        mainwindow.cpp \
        mainwinsig1.cpp \
        mainwinsig2.cpp \
        mainwinsig3.cpp \
        mainwinsig4.cpp \
        openssl/applink.c \
        qcp2_1/axis/axis.cpp \
        qcp2_1/axis/axisticker.cpp \
        qcp2_1/axis/axistickerdatetime.cpp \
        qcp2_1/axis/axistickerfixed.cpp \
        qcp2_1/axis/axistickerlog.cpp \
        qcp2_1/axis/axistickerpi.cpp \
        qcp2_1/axis/axistickertext.cpp \
        qcp2_1/axis/axistickertime.cpp \
        qcp2_1/axis/labelpainter.cpp \
        qcp2_1/axis/range.cpp \
        qcp2_1/colorgradient.cpp \
        qcp2_1/core.cpp \
        qcp2_1/item.cpp \
        qcp2_1/items/item-bracket.cpp \
        qcp2_1/items/item-curve.cpp \
        qcp2_1/items/item-ellipse.cpp \
        qcp2_1/items/item-line.cpp \
        qcp2_1/items/item-pixmap.cpp \
        qcp2_1/items/item-rect.cpp \
        qcp2_1/items/item-straightline.cpp \
        qcp2_1/items/item-text.cpp \
        qcp2_1/items/item-tracer.cpp \
        qcp2_1/layer.cpp \
        qcp2_1/layout.cpp \
        qcp2_1/layoutelements/layoutelement-axisrect.cpp \
        qcp2_1/layoutelements/layoutelement-colorscale.cpp \
        qcp2_1/layoutelements/layoutelement-legend.cpp \
        qcp2_1/layoutelements/layoutelement-textelement.cpp \
        qcp2_1/lineending.cpp \
        qcp2_1/paintbuffer.cpp \
        qcp2_1/painter.cpp \
        qcp2_1/plottable.cpp \
        qcp2_1/plottables/plottable-bars.cpp \
        qcp2_1/plottables/plottable-colormap.cpp \
        qcp2_1/plottables/plottable-curve.cpp \
        qcp2_1/plottables/plottable-errorbar.cpp \
        qcp2_1/plottables/plottable-financial.cpp \
        qcp2_1/plottables/plottable-graph.cpp \
        qcp2_1/plottables/plottable-statisticalbox.cpp \
        qcp2_1/polar/layoutelement-angularaxis.cpp \
        qcp2_1/polar/polargraph.cpp \
        qcp2_1/polar/polargrid.cpp \
        qcp2_1/polar/radialaxis.cpp \
        qcp2_1/scatterstyle.cpp \
        qcp2_1/selection.cpp \
        qcp2_1/selectiondecorator-bracket.cpp \
        qcp2_1/selectionrect.cpp \
        qcp2_1/vector2d.cpp \
        resboxctrl.cpp \
        scopeform.cpp \
        tyjplot.cpp \
        tyjscrollbar.cpp \
        winauthoriation.cpp

HEADERS += \
        authwin.h \
        graphset.h \
        highlighter.h \
        inform.h \
        lua5_4/lapi.h \
        lua5_4/lauxlib.h \
        lua5_4/lcode.h \
        lua5_4/lctype.h \
        lua5_4/ldebug.h \
        lua5_4/ldo.h \
        lua5_4/lfunc.h \
        lua5_4/lgc.h \
        lua5_4/ljumptab.h \
        lua5_4/llex.h \
        lua5_4/llimits.h \
        lua5_4/lmem.h \
        lua5_4/lobject.h \
        lua5_4/lopcodes.h \
        lua5_4/lopnames.h \
        lua5_4/lparser.h \
        lua5_4/lprefix.h \
        lua5_4/lstate.h \
        lua5_4/lstring.h \
        lua5_4/ltable.h \
        lua5_4/ltm.h \
        lua5_4/lua.h \
        lua5_4/lua.hpp \
        lua5_4/luaconf.h \
        lua5_4/lualib.h \
        lua5_4/lundump.h \
        lua5_4/lvm.h \
        lua5_4/lzio.h \
        luaform.h \
        luascript.h \
        main.h \
        mainwindow.h \
        openssl/__DECC_INCLUDE_EPILOGUE.H \
        openssl/__DECC_INCLUDE_PROLOGUE.H \
        openssl/aes.h \
        openssl/asn1.h \
        openssl/asn1_mac.h \
        openssl/asn1err.h \
        openssl/asn1t.h \
        openssl/async.h \
        openssl/asyncerr.h \
        openssl/bio.h \
        openssl/bioerr.h \
        openssl/blowfish.h \
        openssl/bn.h \
        openssl/bnerr.h \
        openssl/buffer.h \
        openssl/buffererr.h \
        openssl/camellia.h \
        openssl/cast.h \
        openssl/cmac.h \
        openssl/cms.h \
        openssl/cmserr.h \
        openssl/comp.h \
        openssl/comperr.h \
        openssl/conf.h \
        openssl/conf_api.h \
        openssl/conferr.h \
        openssl/crypto.h \
        openssl/cryptoerr.h \
        openssl/ct.h \
        openssl/cterr.h \
        openssl/des.h \
        openssl/dh.h \
        openssl/dherr.h \
        openssl/dsa.h \
        openssl/dsaerr.h \
        openssl/dtls1.h \
        openssl/e_os2.h \
        openssl/ebcdic.h \
        openssl/ec.h \
        openssl/ecdh.h \
        openssl/ecdsa.h \
        openssl/ecerr.h \
        openssl/engine.h \
        openssl/engineerr.h \
        openssl/err.h \
        openssl/evp.h \
        openssl/evperr.h \
        openssl/hmac.h \
        openssl/idea.h \
        openssl/kdf.h \
        openssl/kdferr.h \
        openssl/lhash.h \
        openssl/md2.h \
        openssl/md4.h \
        openssl/md5.h \
        openssl/mdc2.h \
        openssl/modes.h \
        openssl/obj_mac.h \
        openssl/objects.h \
        openssl/objectserr.h \
        openssl/ocsp.h \
        openssl/ocsperr.h \
        openssl/opensslconf.h \
        openssl/opensslv.h \
        openssl/ossl_typ.h \
        openssl/pem.h \
        openssl/pem2.h \
        openssl/pemerr.h \
        openssl/pkcs12.h \
        openssl/pkcs12err.h \
        openssl/pkcs7.h \
        openssl/pkcs7err.h \
        openssl/rand.h \
        openssl/rand_drbg.h \
        openssl/randerr.h \
        openssl/rc2.h \
        openssl/rc4.h \
        openssl/rc5.h \
        openssl/ripemd.h \
        openssl/rsa.h \
        openssl/rsaerr.h \
        openssl/safestack.h \
        openssl/seed.h \
        openssl/sha.h \
        openssl/srp.h \
        openssl/srtp.h \
        openssl/ssl.h \
        openssl/ssl2.h \
        openssl/ssl3.h \
        openssl/sslerr.h \
        openssl/stack.h \
        openssl/store.h \
        openssl/storeerr.h \
        openssl/symhacks.h \
        openssl/tls1.h \
        openssl/ts.h \
        openssl/tserr.h \
        openssl/txt_db.h \
        openssl/ui.h \
        openssl/uierr.h \
        openssl/whrlpool.h \
        openssl/x509.h \
        openssl/x509_vfy.h \
        openssl/x509err.h \
        openssl/x509v3.h \
        openssl/x509v3err.h \
        qcp2_1/axis/axis.h \
        qcp2_1/axis/axisticker.h \
        qcp2_1/axis/axistickerdatetime.h \
        qcp2_1/axis/axistickerfixed.h \
        qcp2_1/axis/axistickerlog.h \
        qcp2_1/axis/axistickerpi.h \
        qcp2_1/axis/axistickertext.h \
        qcp2_1/axis/axistickertime.h \
        qcp2_1/axis/labelpainter.h \
        qcp2_1/axis/range.h \
        qcp2_1/colorgradient.h \
        qcp2_1/core.h \
        qcp2_1/datacontainer.h \
        qcp2_1/global.h \
        qcp2_1/item.h \
        qcp2_1/items/item-bracket.h \
        qcp2_1/items/item-curve.h \
        qcp2_1/items/item-ellipse.h \
        qcp2_1/items/item-line.h \
        qcp2_1/items/item-pixmap.h \
        qcp2_1/items/item-rect.h \
        qcp2_1/items/item-straightline.h \
        qcp2_1/items/item-text.h \
        qcp2_1/items/item-tracer.h \
        qcp2_1/layer.h \
        qcp2_1/layout.h \
        qcp2_1/layoutelements/layoutelement-axisrect.h \
        qcp2_1/layoutelements/layoutelement-colorscale.h \
        qcp2_1/layoutelements/layoutelement-legend.h \
        qcp2_1/layoutelements/layoutelement-textelement.h \
        qcp2_1/lineending.h \
        qcp2_1/paintbuffer.h \
        qcp2_1/painter.h \
        qcp2_1/plottable.h \
        qcp2_1/plottable1d.h \
        qcp2_1/plottables/plottable-bars.h \
        qcp2_1/plottables/plottable-colormap.h \
        qcp2_1/plottables/plottable-curve.h \
        qcp2_1/plottables/plottable-errorbar.h \
        qcp2_1/plottables/plottable-financial.h \
        qcp2_1/plottables/plottable-graph.h \
        qcp2_1/plottables/plottable-statisticalbox.h \
        qcp2_1/polar/layoutelement-angularaxis.h \
        qcp2_1/polar/polargraph.h \
        qcp2_1/polar/polargrid.h \
        qcp2_1/polar/radialaxis.h \
        qcp2_1/qcp.h \
        qcp2_1/scatterstyle.h \
        qcp2_1/selection.h \
        qcp2_1/selectiondecorator-bracket.h \
        qcp2_1/selectionrect.h \
        qcp2_1/vector2d.h \
        resboxctrl.h \
        scopeform.h \
        tyjplot.h \
        tyjscrollbar.h \
        winauthoriation.h

FORMS += \
        authwin.ui \
        graphset.ui \
        inform.ui \
        luaform.ui \
        mainwindow.ui \
        resboxctrl.ui \
        scopeform.ui

win32-msvc*: {undefined

QMAKE_CFLAGS *= /utf-8
QMAKE_CXXFLAGS *= /utf-8

INCLUDEPATH += ./../SCD3/freeglut_msvc/include/GL
LIBS += -L./../SCD3/freeglut_msvc/lib/x64 -lfreeglut -L./../SCD3/freeglut_msvc/bin/x64 -lOpenGL32

}

!win32-msvc*: {undefined

INCLUDEPATH += ./../SCD3/freeglut_mingw/include/GL
LIBS += -L./../SCD3/freeglut_mingw/lib/x64 -lfreeglut -L./../SCD3/freeglut_mingw/bin/x64 -lOpenGL32
}

RESOURCES += \
    rc_tyj.qrc
