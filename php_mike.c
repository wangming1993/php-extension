#include <php.h>
#include "php_mike.h"

zend_function_entry mike_functions[] = {
    PHP_FE(mike, NULL)
    /*
    PHP_FE(mike_age, NULL)
    PHP_FE(mike_name, NULL)
    PHP_FE(mike_love, NULL)
    PHP_FE(mike_talk, NULL)
    PHP_FE(mike_say, NULL)
    PHP_FE(mike_default, NULL)
*/    {NULL, NULL, NULL}
};


//然后，定义一个zend_function_entry
static zend_function_entry myclass_method[]=
{
    PHP_ME(myclass, public_method, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(myclass, static_method, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    //ZEND_ME(myclass,    __construct,    NULL,   ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_FE_END
};

zend_module_entry mike_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_MIKE_EXTENSION,  //扩展名称
    mike_functions,/* Functions */
    PHP_MINIT(mike), /* MINIT */
    NULL, /* MSHUTDOWN */
    NULL, /* RINIT */
    NULL, /* RSHUTDOWN */
    NULL, /* MINFO */
    PHP_MIKE_VERSION,
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(mike);

PHP_FUNCTION(mike) {
    php_printf("This is mike's first PHP extension! \n");
}
/*
PHP_FUNCTION(mike_age) {
    ZVAL_LONG(return_value, 23);
    return;
}

PHP_FUNCTION(mike_name) {
    RETVAL_LONG(23);
    return;
}

PHP_FUNCTION(mike_love) {
    RETURN_STRING("XIAO", 3)
}

PHP_FUNCTION(mike_talk) {
    char *topic;
    int length;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &topic, &length) == FAILURE)
    {
        RETURN_NULL();
    }
    RETURN_STRING(topic, 1);
}

PHP_FUNCTION(mike_say) {
    char *name;
    int length;
    long age;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sl", &name, &length, &age) == FAILURE) {
        php_printf("Parse error");
    }
    PHPWRITE(name, length);
}

PHP_FUNCTION(mike_default) {
    char *name;
    int length;
    long age = 23;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l", &name, &length, &age) == FAILURE) {
        php_printf("Parse error");
    }
    PHPWRITE(name, length);
    RETVAL_LONG(age);
}
*/




//最后，在MINIT阶段register internal class的时候将它作为一个参数传递进去
PHP_MINIT_FUNCTION(mike)
{
    zend_class_entry ce;
    zend_class_entry *mongo_ce_MongoClient;

    //这里使用了myclass_method这个zend_function_entry
    INIT_CLASS_ENTRY(ce,"myclass",myclass_method);

    mongo_ce_MongoClient = zend_register_internal_class(&ce TSRMLS_CC);

    zend_declare_class_constant_string(mongo_ce_MongoClient, "VERSION", strlen("VERSION"), "1.0" TSRMLS_CC);
    zend_declare_property_bool(mongo_ce_MongoClient, "connected", strlen("connected"), 1, ZEND_ACC_PUBLIC TSRMLS_CC);

    return SUCCESS;
}

PHP_METHOD(myclass, public_method)
{
    php_printf("我是public类型的方法\n");
}

PHP_METHOD(myclass, static_method)
{
    php_printf("我是static类型的方法\n");
}
