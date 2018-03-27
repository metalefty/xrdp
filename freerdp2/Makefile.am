EXTRA_DIST = xrdp-freerdp.h
EXTRA_DEFINES =

if XRDP_DEBUG
EXTRA_DEFINES += -DXRDP_DEBUG
else
EXTRA_DEFINES += -DXRDP_NODEBUG
endif

AM_CPPFLAGS = \
  -DXRDP_CFG_PATH=\"${sysconfdir}/xrdp\" \
  -DXRDP_SBIN_PATH=\"${sbindir}\" \
  -DXRDP_SHARE_PATH=\"${datadir}/xrdp\" \
  -DXRDP_PID_PATH=\"${localstatedir}/run\" \
  $(EXTRA_DEFINES) \
  -I$(top_srcdir)/common \
  -I/usr/local/include \
  $(FREERDP_CFLAGS)

lib_LTLIBRARIES = \
  libxrdpfreerdp2.la

libxrdpfreerdp2_la_SOURCES = xrdp-freerdp.c xrdp-color.c

libxrdpfreerdp2_la_LIBADD = \
  $(top_builddir)/common/libcommon.la \
  $(FREERDP_LIBS)
