/*
 * Copyright (C) 2018 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "unit_tests/fixtures/image_fixture.h"
#include "unit_tests/mocks/mock_context.h"
#include "test.h"

using namespace OCLRT;

typedef ::testing::Test gen8ImageTests;

GEN8TEST_F(gen8ImageTests, appendSurfaceStateParamsDoesNothing) {
    typedef typename FamilyType::RENDER_SURFACE_STATE RENDER_SURFACE_STATE;
    MockContext context;
    auto image = std::unique_ptr<Image>(ImageHelper<Image1dDefaults>::create(&context));
    auto surfaceStateBefore = RENDER_SURFACE_STATE::sInit();
    auto surfaceStateAfter = RENDER_SURFACE_STATE::sInit();
    auto imageHw = static_cast<ImageHw<FamilyType> *>(image.get());

    EXPECT_EQ(0, memcmp(&surfaceStateBefore, &surfaceStateAfter, sizeof(RENDER_SURFACE_STATE)));

    imageHw->appendSurfaceStateParams(&surfaceStateAfter);

    EXPECT_EQ(0, memcmp(&surfaceStateBefore, &surfaceStateAfter, sizeof(RENDER_SURFACE_STATE)));
}
