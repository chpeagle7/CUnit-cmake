#include <stdio.h>
#include <Automated.h>
#include "Basic.h"

/* 被测试的函数，在当中故意安装了一个BUG */
static int sum(int a, int b)
{
    if (a > 4) {
        return 0;
    }
    return (a + b);
}

static int suite_init(void)
{
    return 0;
}

static int suite_clean(void)
{
    return 0;
}

static void test_sum(void)
{
    CU_ASSERT_EQUAL(sum(1, 2), 3);
    CU_ASSERT_EQUAL(sum(5, 2), 7);
}


int main() {
    CU_pSuite  pSuite = NULL;
    if(CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }
    pSuite =  CU_add_suite("suite_sum",suite_init,suite_clean);
    if(NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    CU_add_test(pSuite,"test_sum",test_sum);
    CU_list_tests_to_file();
    CU_automated_run_tests();
    CU_cleanup_registry();
    printf("Hello, World!\n");
    return 0;
}
