// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef _SDX_H_
#define _SDX_H_

#include "FS.h"
#include "SPI.h"
#include "sd_defines.h"
#include <IOHAL.h>

namespace fsx
{

class SDFSX : public FS
{
protected:
    uint8_t _pdrv;

public:
    SDFSX(fs::FSImplPtr impl);
    bool begin(IOHAL* io, uint8_t ssPin=SS, SPIClass &spi=SPI, uint32_t frequency=4000000, const char * mountpoint="/sd");
    void end();
    sdcard_type_t cardType();
    uint64_t cardSize();
    uint64_t totalBytes();
    uint64_t usedBytes();
};

}

extern fsx::SDFSX SDX;

using namespace fs;
typedef fs::File        SDFile;
typedef fsx::SDFSX        SDFileSystemClass;
#define SDFileSystem    SDX

#endif /* _SD_H_ */
