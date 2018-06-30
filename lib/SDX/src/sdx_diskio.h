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
#ifndef _SDX_DISKIO_H_
#define _SDX_DISKIO_H_

#include "Arduino.h"
#include "SPI.h"
#include "sdx_defines.h"
#include <IOHAL.h>

uint8_t sdcardx_init(uint8_t cs, SPIClass * spi, int hz, IOHAL* io);
uint8_t sdcardx_uninit(uint8_t pdrv);

bool sdcardx_mount(uint8_t pdrv, const char* path);
uint8_t sdcardx_unmount(uint8_t pdrv);

sdcard_type_t sdcardx_type(uint8_t pdrv);
uint32_t sdcardx_num_sectors(uint8_t pdrv);
uint32_t sdcardx_sector_size(uint8_t pdrv);

#endif /* _SD_DISKIO_H_ */
