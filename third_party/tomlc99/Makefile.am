EXTRA_DIST = \
    src/toml.c \
    src/toml.h \
    src/LICENSE

# See src/Makefile
# '-x c' forces gcc to be used if we are using g++ for CI testing
AM_CFLAGS = -x c -std=c99 -std=c99 -Wall -Wextra -fpic

module_LTLIBRARIES  = libtoml.la

libtoml_la_SOURCES = toml.c toml.h

libtoml_la_LDFLAGS = -version-info 1:0

include_headers = toml.h

toml.h : src/toml.h
	ln $< .

toml.c : src/toml.c toml.h
	ln $< .

LICENSE : src/LICENSE
	ln $< .

clean::
	rm -f toml.h toml.c LICENSE
