/*
 * Copyright (C) 2017-2018 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "runtime/os_interface/os_library.h"
#include "common/gtsysinfo.h"
#include "igfxfmid.h"

namespace Os {
///////////////////////////////////////////////////////////////////////////////
// These options determine the Linux specific behavior for
// the runtime unit tests
///////////////////////////////////////////////////////////////////////////////
#if defined(__linux__)
const char *frontEndDllName = "libmock_igdfcl.so";
const char *igcDllName = "libmock_igc.so";
const char *libvaDllName = nullptr;
const char *testDllName = "libtest_dynamic_lib.so";
const char *gmmDllName = "libmock_gmm.so";
const char *gmmEntryName = "openMockGmm";
#endif
const char *sysFsPciPath = "./test_files";
} // namespace Os

OCLRT::OsLibrary *setAdapterInfo(const PLATFORM *platform, const GT_SYSTEM_INFO *gtSystemInfo) {
    return nullptr;
}
