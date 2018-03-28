AM_CPPFLAGS = \
  -DXRDP_CFG_PATH=\"${sysconfdir}/xrdp\" \
  -DXRDP_SBIN_PATH=\"${sbindir}\" \
  -DXRDP_SHARE_PATH=\"${datadir}/xrdp\" \
  -DXRDP_PID_PATH=\"${localstatedir}/run\" \
  -I$(top_srcdir)/common \
  $(FREERDP_CFLAGS)

if XRDP_DEBUG
AM_CPPFLAGS += -DXRDP_DEBUG
endif

module_LTLIBRARIES = \
  libxrdpneutrinordp.la

libxrdpfreerdp2_la_SOURCES = \
  xrdp-color.c \
  xrdp-color.h \
  xrdp-freerdp2.c \
  xrdp-freerdp2.h

libxrdpfreerdp2_la_LIBADD = \
  $(top_builddir)/common/libcommon.la \
  $(FREERDP_LIBS)

libxrdpfreerdp2_la_LDFLAGS = -avoid-version -module
