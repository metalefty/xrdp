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

#if defined(HAVE_CONFIG_H)
#include <config_ac.h>
#endif

#include "os_calls.h"
#include "chansrv.h"
#include "log.h"
#include "list.h"
#include "file.h"

static char g_fuse_mount_name[256] = "xrdp_client";
static char g_fuse_root_path[256]  = "";

/*****************************************************************************/
int
load_fuse_config(void)
{
    int index;
    char cfg_file[256];
    struct list *items;
    struct list *values;
    char *item;
    char *value;

    items = list_create();
    items->auto_free = 1;
    values = list_create();
    values->auto_free = 1;
    g_snprintf(cfg_file, 255, "%s/sesman.ini", XRDP_CFG_PATH);
    file_by_name_read_section(cfg_file, "Chansrv", items, values);
    for (index = 0; index < items->count; index++)
    {
        item = (char *)list_get_item(items, index);
        value = (char *)list_get_item(values, index);
        if (g_strcasecmp(item, "FuseMountName") == 0)
        {
            g_strncpy(g_fuse_mount_name, value, 255);
        }
    }
    list_delete(items);
    list_delete(values);
    return 0;
}

/*****************************************************************************/
int
serial_init(void)
{
    load_fuse_config();
    g_snprintf(g_fuse_root_path, 255, "%s/%s", g_getenv("HOME"), g_fuse_mount_name);

    return 0;
}

/*****************************************************************************/
/* returns -1 if error */
int
serial_create_device(tui32 device_id, const char *name)
{
    char *serial_device_full_path;

    if (name == NULL || g_strlen(name) == 0)
    {
        return -1;
    }
    g_snprintf(serial_device_full_path, "%s/%s", g_fuse_root_path, name);


    return 0;
}

