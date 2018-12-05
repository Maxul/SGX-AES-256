/*
 * App.cpp
 *
 * Copyright (C) 2018 - Maxul
 *
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "App.h"
#include "Enclave_u.h"
#include "sgx_uae_service.h"
#include "sgx_urts.h"

#include "sgx_utils.h"

using namespace std;

/* OCall functions */
void ocall_print_string(const char *str)
{
    /* Proxy/Bridge will check the length and null-terminate
     * the input string to prevent buffer overflow.
     */
    printf("%s", str);
}

/* Application entry */
int SGX_CDECL main(int argc, char *argv[])
{
	sgx_enclave_id_t eid = 0;
	sgx_launch_token_t token = {0};
	sgx_status_t ret = SGX_ERROR_UNEXPECTED;
	int updated = 0;
	const char *enclave_filename = "enclave.signed.so";
	ret = sgx_create_enclave(
		enclave_filename,
		SGX_DEBUG_FLAG,
		&token, 
		&updated, 
		&eid, 
		NULL
	);
	assert(ret == SGX_SUCCESS);
	
	int r;
	test_main(eid, &r);

	sgx_destroy_enclave(eid);
	return 0;
}
