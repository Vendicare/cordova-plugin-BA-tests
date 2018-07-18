#!/bin/sh

#  remove_simulator_archs.sh
#  MobbIDSDK_Face
#
#  Created by Maria Luz Mateo Moreno on 29/12/2017.
#  Copyright © 2017 Mobbeel Solutions, SLL. All rights reserved.

cd "$(dirname "$0")"

FRAMEWORK_PATH="$(basename "$(pwd)")"
FRAMEWORK_BIN="${FRAMEWORK_PATH%.framework}"
ALL_ARCHS=$(lipo -info "${FRAMEWORK_BIN}" | rev | cut -d: -f1 | rev)

echo "Remove simulator architectures from ${FRAMEWORK_BIN}"

for ARCH in ${ALL_ARCHS}; do
if ! [[ "${VALID_ARCHS}" == *"${ARCH}"* ]]; then
echo "Removing ${ARCH}..."
lipo -remove "${ARCH}" -output "${FRAMEWORK_BIN}" "${FRAMEWORK_BIN}"
fi
done

if [ -d BCSymbolMaps ]; then
if [ "${ACTION}" == "install" ]; then
mv BCSymbolMaps/*.bcsymbolmap "${CONFIGURATION_BUILD_DIR}"
fi
rm -rf BCSymbolMaps
fi
