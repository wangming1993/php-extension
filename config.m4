PHP_ARG_ENABLE(mike, Whether to enable Mike extension, [ --enable-mike Enable Mike Extension])

if test "$PHP_MIKE" != "no"; then
    PHP_SUBST(MIKE_SHARED_LIBADD)
    PHP_NEW_EXTENSION(mike, php_mike.c, $ext_shared)
fi
