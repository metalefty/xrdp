/* vim: set expandtab tabstop=4 shiftwidth=4 : */
/**
 * xrdp: A Remote Desktop Protocol server.
 *
 * Copyright (C) Koichiro Iwao 2017
 * Copyright (C) HAW International, Inc. 2017
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if !defined(SERIAL_H)
#define SERIAL_H

#include "arch.h"
#include "parse.h"

int load_fuse_config(void);
int serial_init(void);
int serial_create_device(tui32 device_id, const char *name);

#endif
