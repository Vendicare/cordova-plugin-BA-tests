#!/bin/sh
######################
# Options
######################

FRAMEWORK_NAME="${PROJECT_NAME}"

UNIVERSAL_LIBRARY_DIR="${BUILD_DIR}/Universal"

FRAMEWORK="${UNIVERSAL_LIBRARY_DIR}/${FRAMEWORK_NAME}.framework"

######################
# Copy framework for the releasing phase of the MobbScanSDK-iOS
######################

mkdir -p ${SRCROOT}/Build/Products/Universal
cp -r "${FRAMEWORK}" ${SRCROOT}/Build/Products/Universal
