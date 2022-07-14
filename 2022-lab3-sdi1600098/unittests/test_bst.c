#include "acutest.h"  // library for unit-tests

#include <stdio.h>
#include <stdlib.h>

#include "Item.h"
#include "ST.h"

/* reference: https://stackoverflow.com/questions/13445845/easiest-to-use-int-array-sorting-function-in-c */
int compare(const void* a, const void* b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    
    if (int_a == int_b) {
        return 0;
    } else {
        return (int_a < int_b) ? -1:1;
    }
}

/* 
   tests STinit
 */
void test_create(void) {
    int maxN = 10;
    // initialize bst
    STinit(maxN);
    // check that the bst is empty
    TEST_ASSERT(STcount() == 0);
}

/*
   tests STinsert with sequential input
 */
void test_insert_seq(void) {
    int maxN = 1000;
    
    // initialize bst
    STinit(maxN);

    // insert maxN sequential values
    for (int N=0; N<maxN; ++N) {
        STinsert(N);
    }
    // check that the bst contains maxN items
    TEST_ASSERT(STcount() == maxN);

    // search for the inserted values
    for (int N=0; N<maxN; ++N) {
        TEST_ASSERT(STsearch(N) == N);
    }
    // Key(maxN) value should not exist in the
    // bst
    TEST_ASSERT(STsearch(maxN) == NULLitem);

    // check whether the keys are inserted
    // in the correct order
    for (int N=0; N<maxN; ++N) {
        TEST_ASSERT(STselect(N) == N);
    }
}

/*
   tests STinsert with random input
 */
void test_insert_rand(void) {
    int maxN = 1000;
    int rand_ints[maxN];

    // initialize bst
    STinit(maxN);

    // insert maxN random values
    for (int N=0; N<maxN; ++N) {
        // Itemrand() returns only positive values
        Key rand_key = ITEMrand();
        rand_ints[N] = rand_key;
        STinsert(rand_key);
    }
    // check that the bst contains maxN items
    TEST_ASSERT(STcount() == maxN);

    // search for the inserted values
    for (int N=0; N<maxN; ++N) {
        Key curr_key = rand_ints[N];
        TEST_ASSERT(STsearch(curr_key) == curr_key);
    }
    // Itemrand() returns only positive values
    // Key(-10) should not exist in the bst
    TEST_ASSERT(STsearch(-10) == NULLitem);

    // sort array values
    qsort(rand_ints, maxN, sizeof(int), compare);
    // check whether the keys are inserted
    // in the correct order                                           
    for (int N=0; N<maxN; ++N) {
        Key curr_key = rand_ints[N];
        TEST_ASSERT(STselect(N) == curr_key);
    }
}

/*
   tests STdelete with random input
 */
void test_delete(void) {
    int maxN = 1000;
    int rand_ints[maxN];
    
    // initialize bst
    STinit(maxN);

    // insert maxN random values
    for (int N=0; N<maxN; ++N) {
        Key rand_key = ITEMrand();
        rand_ints[N] = rand_key;
        STinsert(rand_key);
    }

    // delete half of the inserted values
    for (int N=0; N<maxN/2; ++N) {
        STdelete(rand_ints[N]);
    }

    for (int N=0; N<maxN; ++N) {
        Key curr_key = rand_ints[N];
        if (N < maxN/2) {
            // value is deleed; it should not exist in bst
            TEST_ASSERT(STsearch(curr_key) == NULLitem);
        } else {
            // value is not deleed; it should be present in bst
            TEST_ASSERT(STsearch(curr_key) == curr_key);
        }
    }
}

TEST_LIST = {
	{ "bst_create", test_create },
    { "bst_insert_1", test_insert_seq },
    { "bst_insert_2", test_insert_rand },
    { "bst_delete", test_delete },
	{ NULL, NULL }  // terminating test list with NULLs
};
