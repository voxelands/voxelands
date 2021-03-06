/************************************************************************
* Minetest-c55
* Copyright (C) 2010 celeron55, Perttu Ahola <celeron55@gmail.com>
*
* mineral.cpp
* voxelands - 3d voxel world sandbox game
* Copyright (C) Lisa 'darkrose' Milne 2015 <lisa@ltmnet.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>
*
* License updated from GPLv2 or later to GPLv3 or later by Lisa Milne
* for Voxelands.
************************************************************************/

#include "mineral.h"
#include "enchantment.h"
#include "intl.h"

struct MineralFeatures g_mineral_features[MINERAL_MAX+1];

MineralFeatures & mineral_features(u8 i)
{
    return g_mineral_features[i];
}

CraftItem *getDiggedMineralItem(u8 mineral, Player *player, InventoryItem *tool)
{
    MineralFeatures m = mineral_features(mineral);
    if (m.dug_item == CONTENT_IGNORE)
        return NULL;

    if (content_craftitem_features(m.dug_item)->content == CONTENT_IGNORE)
        return NULL;

    if (!tool && m.min_level > 0)
        return NULL;

    ToolItemFeatures *t = &content_toolitem_features(tool->getContent());
    if (t->content == CONTENT_IGNORE && m.min_level > 0)
        return NULL;

    if (t->diginfo.level < m.min_level)
        return NULL;

    u16 count = m.dug_count_min;
    u16 count_max = t->diginfo.level;
    u16 data = tool->getData();

    if (data != 0) {
        EnchantmentInfo info;
        while (enchantment_get(&data,&info)) {
            switch (info.type) {
            case ENCHANTMENT_MORE: // amplius increases the amount given
                count += (info.level+1)/2;
                count_max += info.level;
                break;
            case ENCHANTMENT_DONTBREAK: // gives no mineral
                return NULL;
                break;
            default:;
            }
        }
    }

    if (count_max > count) {
        count = myrand_range(m.dug_count_min,count_max);
    }

    if (count > m.dug_count_max)
        count = m.dug_count_max;

    return new CraftItem(m.dug_item, count, 0);
}

void init_mineral()
{
    u8 i;
    MineralFeatures *f = NULL;

    i = MINERAL_COAL;
    f = &mineral_features(i);
    f->description = gettext("Coal");
    f->texture = "mineral_coal.png";
    f->dug_item = CONTENT_CRAFTITEM_COAL;

    // Flint from gravel for level 2 tools

    i = MINERAL_COPPER;
    f = &mineral_features(i);
    f->description = gettext("Copper");
    f->texture = "mineral_copper.png";
    f->dug_item = CONTENT_CRAFTITEM_COPPER;
    f->dug_count_max = 4;
    f->min_level = 2;

    i = MINERAL_TIN;
    f = &mineral_features(i);
    f->description = gettext("Tin");
    f->texture = "mineral_tin.png";
    f->dug_item = CONTENT_CRAFTITEM_TIN;
    f->min_level = 2;

    // bronze for level 3 tools

    i = MINERAL_IRON;
    f = &mineral_features(i);
    f->description = gettext("Iron");
    f->texture = "mineral_iron.png";
    f->dug_item = CONTENT_CRAFTITEM_IRON;
    f->min_level = 3;

    i = MINERAL_MITHRIL;
    f = &mineral_features(i);
    f->description = gettext("Mithril");
    f->texture = "mineral_mithril.png";
    f->dug_item = CONTENT_CRAFTITEM_MITHRIL_RAW;
    f->min_level = 4;

    i = MINERAL_SALT;
    f = &mineral_features(i);
    f->description = gettext("Salt");
    f->texture = "mineral_salt.png";
    f->dug_item = CONTENT_CRAFTITEM_SALT;
    f->min_level = 1;
    f->dug_count_max = 2;

    i = MINERAL_SILVER;
    f = &mineral_features(i);
    f->description = gettext("Silver");
    f->texture = "mineral_silver.png";
    f->dug_item = CONTENT_CRAFTITEM_SILVER;
    f->min_level = 3;

    i = MINERAL_GOLD;
    f = &mineral_features(i);
    f->description = gettext("Gold");
    f->texture = "mineral_gold.png";
    f->dug_item = CONTENT_CRAFTITEM_GOLD;
    f->min_level = 3;

    i = MINERAL_QUARTZ;
    f = &mineral_features(i);
    f->description = gettext("Quartz");
    f->texture = "mineral_quartz.png";
    f->dug_item = CONTENT_CRAFTITEM_QUARTZ;
    f->min_level = 3;

    i = MINERAL_RUBY;
    f = &mineral_features(i);
    f->description = gettext("Ruby");
    f->texture = "mineral_ruby.png";
    f->dug_item = CONTENT_CRAFTITEM_RUBY;
    f->min_level = 3;
    f->dug_count_max = 2;

    i = MINERAL_TURQUOISE;
    f = &mineral_features(i);
    f->description = gettext("Turquoise");
    f->texture = "mineral_turquoise.png";
    f->dug_item = CONTENT_CRAFTITEM_TURQUOISE;
    f->min_level = 3;
    f->dug_count_max = 2;

    i = MINERAL_AMETHYST;
    f = &mineral_features(i);
    f->description = gettext("Amethyst");
    f->texture = "mineral_amethyst.png";
    f->dug_item = CONTENT_CRAFTITEM_AMETHYST;
    f->min_level = 3;
    f->dug_count_max = 2;

    i = MINERAL_SAPPHIRE;
    f = &mineral_features(i);
    f->description = gettext("Sapphire");
    f->texture = "mineral_sapphire.png";
    f->dug_item = CONTENT_CRAFTITEM_SAPPHIRE;
    f->min_level = 3;
    f->dug_count_max = 2;

    i = MINERAL_SUNSTONE;
    f = &mineral_features(i);
    f->description = gettext("Sunstone");
    f->texture = "mineral_sunstone.png";
    f->dug_item = CONTENT_CRAFTITEM_SUNSTONE;
    f->min_level = 3;
    f->dug_count_max = 2;
}
