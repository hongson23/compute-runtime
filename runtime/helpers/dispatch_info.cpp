/*
 * Copyright (C) 2017-2018 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "runtime/helpers/dispatch_info.h"
#include "runtime/kernel/kernel.h"

namespace OCLRT {
bool DispatchInfo::usesSlm() const {
    return (kernel == nullptr) ? false : kernel->slmTotalSize > 0;
}

bool DispatchInfo::usesStatelessPrintfSurface() const {
    return (kernel == nullptr) ? false : (kernel->getKernelInfo().patchInfo.pAllocateStatelessPrintfSurface != nullptr);
}

uint32_t DispatchInfo::getRequiredScratchSize() const {
    return (kernel == nullptr) ? 0 : kernel->getScratchSize();
}

Kernel *MultiDispatchInfo::peekMainKernel() const {
    if (dispatchInfos.size() == 0) {
        return nullptr;
    }
    return mainKernel ? mainKernel : dispatchInfos.begin()->getKernel();
}

Kernel *MultiDispatchInfo::peekParentKernel() const {
    return (mainKernel && mainKernel->isParentKernel) ? mainKernel : nullptr;
}
} // namespace OCLRT
