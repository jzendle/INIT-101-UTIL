/*
 * File:   logTest.c
 * Author: jzendle
 *
 * Created on Oct 11, 2013, 8:18:22 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>

#include "../Logger.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void test1() {
    
       
    info("this is a test\n");
    
    infov("print %s\n", "this");
    
    CU_ASSERT(2 * 2 == 4);
}

void test2() {
    
       
    err("this is a problem\n");
    
    errv("print %s\n", "error");
    
    CU_ASSERT(2 * 2 == 4);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("logTest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "test2", test2)) ||
            (NULL == CU_add_test(pSuite, "test1", test1))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
