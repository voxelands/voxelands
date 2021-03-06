/************************************************************************
* Minetest-c55
* Copyright (C) 2010 celeron55, Perttu Ahola <celeron55@gmail.com>
*
* content_mapnode_furniture.cpp
* Copyright (C) Lisa 'darkrose' Milne 2014 <lisa@ltmnet.com>
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
************************************************************************/

#include "content_mapnode.h"
#include "content_nodebox.h"
#include "content_list.h"
#include "content_craft.h"
#include "content_nodemeta.h"
#include "intl.h"
#include "content_burntimes.h"

void content_mapnode_furniture(bool repeat)
{
	content_t i;
	ContentFeatures *f = NULL;

	i = CONTENT_BOOKSHELF;
	f = &content_features(i);
	f->description = gettext("Book Shelf");
	f->setAllTextures("wood.png");
	f->setAllMetaTextures("bookshelf_book.png");
	f->setMetaTexture(0, "bookshelf_book_top.png");
	f->rotate_tile_with_nodebox = true;
	//f->setInventoryTextureCube("wood.png", "bookshelf.png", "bookshelf.png");
	f->draw_type = CDT_NODEBOX_META;
	f->param_type = CPT_FACEDIR_SIMPLE;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_BOOKSHELF)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BOOKSHELF;
	f->type = CMT_WOOD;
	f->dig_time = 0.75;
	content_nodebox_bookshelf(f);
	f->setInventoryTextureNodeBox(i,"wood.png", "wood.png", "wood.png");
	if (f->initial_metadata == NULL)
		f->initial_metadata = new BookShelfNodeMetadata();
	{
		u16 r[9] = {
			CONTENT_WOOD,	CONTENT_WOOD,	CONTENT_WOOD,
			CONTENT_IGNORE, CONTENT_IGNORE, CONTENT_IGNORE,
			CONTENT_WOOD,	CONTENT_WOOD,	CONTENT_WOOD
		};
		crafting::setRecipe(r,CONTENT_BOOKSHELF,1);
	}
	f->pressure_type = CST_SOLID;
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_BOOKSHELF_JUNGLE;
	f = &content_features(i);
	f->description = gettext("Junglewood Book Shelf");
	f->setAllTextures("junglewood.png");
	f->setAllMetaTextures("bookshelf_book.png");
	f->setMetaTexture(0, "bookshelf_book_top.png");
	f->rotate_tile_with_nodebox = true;
	//f->setInventoryTextureCube("wood.png", "bookshelf.png", "bookshelf.png");
	f->draw_type = CDT_NODEBOX_META;
	f->param_type = CPT_FACEDIR_SIMPLE;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BOOKSHELF;
	f->type = CMT_WOOD;
	f->dig_time = 0.75;
	content_nodebox_bookshelf(f);
	f->setInventoryTextureNodeBox(i,"junglewood.png", "junglewood.png", "junglewood.png");
	if (f->initial_metadata == NULL)
		f->initial_metadata = new BookShelfNodeMetadata();
	{
		u16 r[9] = {
			CONTENT_JUNGLEWOOD,	CONTENT_JUNGLEWOOD,	CONTENT_JUNGLEWOOD,
			CONTENT_IGNORE,		CONTENT_IGNORE,		CONTENT_IGNORE,
			CONTENT_JUNGLEWOOD,	CONTENT_JUNGLEWOOD,	CONTENT_JUNGLEWOOD
		};
		crafting::setRecipe(r,CONTENT_BOOKSHELF_JUNGLE,1);
	}
	f->pressure_type = CST_SOLID;
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_BOOKSHELF_PINE;
	f = &content_features(i);
	f->description = gettext("Pine Book Shelf");
	f->setAllTextures("pine.png");
	f->setAllMetaTextures("bookshelf_book.png");
	f->setMetaTexture(0, "bookshelf_book_top.png");
	f->rotate_tile_with_nodebox = true;
	//f->setInventoryTextureCube("wood.png", "bookshelf.png", "bookshelf.png");
	f->draw_type = CDT_NODEBOX_META;
	f->param_type = CPT_FACEDIR_SIMPLE;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BOOKSHELF;
	f->type = CMT_WOOD;
	f->dig_time = 0.75;
	content_nodebox_bookshelf(f);
	f->setInventoryTextureNodeBox(i,"pine.png", "pine.png", "pine.png");
	if (f->initial_metadata == NULL)
		f->initial_metadata = new BookShelfNodeMetadata();
	{
		u16 r[9] = {
			CONTENT_WOOD_PINE,	CONTENT_WOOD_PINE,	CONTENT_WOOD_PINE,
			CONTENT_IGNORE,		CONTENT_IGNORE,		CONTENT_IGNORE,
			CONTENT_WOOD_PINE,	CONTENT_WOOD_PINE,	CONTENT_WOOD_PINE
		};
		crafting::setRecipe(r,CONTENT_BOOKSHELF_PINE,1);
	}
	f->pressure_type = CST_SOLID;
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_BOOKSHELF_APPLE;
	f = &content_features(i);
	f->description = gettext("Applewood Book Shelf");
	f->setAllTextures("applewood.png");
	f->setAllMetaTextures("bookshelf_book.png");
	f->setMetaTexture(0, "bookshelf_book_top.png");
	f->rotate_tile_with_nodebox = true;
	//f->setInventoryTextureCube("wood.png", "bookshelf.png", "bookshelf.png");
	f->draw_type = CDT_NODEBOX_META;
	f->param_type = CPT_FACEDIR_SIMPLE;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BOOKSHELF;
	f->type = CMT_WOOD;
	f->dig_time = 0.75;
	content_nodebox_bookshelf(f);
	f->setInventoryTextureNodeBox(i,"applewood.png", "applewood.png", "applewood.png");
	if (f->initial_metadata == NULL)
		f->initial_metadata = new BookShelfNodeMetadata();
	{
		u16 r[9] = {
			CONTENT_APPLEWOOD,	CONTENT_APPLEWOOD,	CONTENT_APPLEWOOD,
			CONTENT_IGNORE,		CONTENT_IGNORE,		CONTENT_IGNORE,
			CONTENT_APPLEWOOD,	CONTENT_APPLEWOOD,	CONTENT_APPLEWOOD
		};
		crafting::setRecipe(r,CONTENT_BOOKSHELF_APPLE,1);
	}
	f->pressure_type = CST_SOLID;
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CENTRE;
	f = &content_features(i);
	f->description = gettext("Couch");
	f->setAllTextures("cotton.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDL;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_centre(f);
	f->setInventoryTextureNodeBox(i,"cotton.png", "cotton.png", "cotton.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDL;
	f = &content_features(i);
	f->description = gettext("Couch");
	f->setAllTextures("cotton.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDR;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_left(f);
	f->setInventoryTextureNodeBox(i,"cotton.png", "cotton.png", "cotton.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDR;
	f = &content_features(i);
	f->description = gettext("Couch");
	f->setAllTextures("cotton.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_INNER;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_right(f);
	f->setInventoryTextureNodeBox(i,"cotton.png", "cotton.png", "cotton.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_INNER;
	f = &content_features(i);
	f->description = gettext("Couch");
	f->setAllTextures("cotton.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_OUTER;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_inner(f);
	f->setInventoryTextureNodeBox(i,"cotton.png", "cotton.png", "cotton.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_OUTER;
	f = &content_features(i);
	f->description = gettext("Couch");
	f->setAllTextures("cotton.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CHAIR;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_outer(f);
	f->setInventoryTextureNodeBox(i,"cotton.png", "cotton.png", "cotton.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CHAIR;
	f = &content_features(i);
	f->description = gettext("Couch");
	f->setAllTextures("cotton.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CENTRE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_chair(f);
	f->setInventoryTextureNodeBox(i,"cotton.png", "cotton.png", "cotton.png");
	crafting::setVRecipe(CONTENT_COTTON,CONTENT_COUCH_CHAIR,2);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR_BLUE,CONTENT_CRAFTITEM_STARCH,CONTENT_COUCH_CHAIR);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR_GREEN,CONTENT_CRAFTITEM_STARCH,CONTENT_COUCH_CHAIR);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR_ORANGE,CONTENT_CRAFTITEM_STARCH,CONTENT_COUCH_CHAIR);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR_PURPLE,CONTENT_CRAFTITEM_STARCH,CONTENT_COUCH_CHAIR);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR_RED,CONTENT_CRAFTITEM_STARCH,CONTENT_COUCH_CHAIR);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR_YELLOW,CONTENT_CRAFTITEM_STARCH,CONTENT_COUCH_CHAIR);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR_BLACK,CONTENT_CRAFTITEM_STARCH,CONTENT_COUCH_CHAIR);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CENTRE_BLUE;
	f = &content_features(i);
	f->description = gettext("Blue Couch");
	f->setAllTextures("cotton_blue.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_BLUE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDL_BLUE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_centre(f);
	f->setInventoryTextureNodeBox(i,"cotton_blue.png", "cotton_blue.png", "cotton_blue.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDL_BLUE;
	f = &content_features(i);
	f->description = gettext("Blue Couch");
	f->setAllTextures("cotton_blue.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_BLUE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDR_BLUE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_left(f);
	f->setInventoryTextureNodeBox(i,"cotton_blue.png", "cotton_blue.png", "cotton_blue.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDR_BLUE;
	f = &content_features(i);
	f->description = gettext("Blue Couch");
	f->setAllTextures("cotton_blue.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_BLUE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_INNER_BLUE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_right(f);
	f->setInventoryTextureNodeBox(i,"cotton_blue.png", "cotton_blue.png", "cotton_blue.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_INNER_BLUE;
	f = &content_features(i);
	f->description = gettext("Blue Couch");
	f->setAllTextures("cotton_blue.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_BLUE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_OUTER_BLUE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_inner(f);
	f->setInventoryTextureNodeBox(i,"cotton_blue.png", "cotton_blue.png", "cotton_blue.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_OUTER_BLUE;
	f = &content_features(i);
	f->description = gettext("Blue Couch");
	f->setAllTextures("cotton_blue.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_BLUE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CHAIR_BLUE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_outer(f);
	f->setInventoryTextureNodeBox(i,"cotton_blue.png", "cotton_blue.png", "cotton_blue.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CHAIR_BLUE;
	f = &content_features(i);
	f->description = gettext("Blue Couch");
	f->setAllTextures("cotton_blue.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_BLUE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CENTRE_BLUE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_chair(f);
	f->setInventoryTextureNodeBox(i,"cotton_blue.png", "cotton_blue.png", "cotton_blue.png");
	crafting::setVRecipe(CONTENT_COTTON_BLUE,CONTENT_COUCH_CHAIR_BLUE,2);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR,CONTENT_CRAFTITEM_DYE_BLUE,CONTENT_COUCH_CHAIR_BLUE);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CENTRE_GREEN;
	f = &content_features(i);
	f->description = gettext("Green Couch");
	f->setAllTextures("cotton_green.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_GREEN)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDL_GREEN;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_centre(f);
	f->setInventoryTextureNodeBox(i,"cotton_green.png", "cotton_green.png", "cotton_green.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDL_GREEN;
	f = &content_features(i);
	f->description = gettext("Green Couch");
	f->setAllTextures("cotton_green.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_GREEN)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDR_GREEN;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_left(f);
	f->setInventoryTextureNodeBox(i,"cotton_green.png", "cotton_green.png", "cotton_green.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDR_GREEN;
	f = &content_features(i);
	f->description = gettext("Green Couch");
	f->setAllTextures("cotton_green.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_GREEN)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_INNER_GREEN;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_right(f);
	f->setInventoryTextureNodeBox(i,"cotton_green.png", "cotton_green.png", "cotton_green.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_INNER_GREEN;
	f = &content_features(i);
	f->description = gettext("Green Couch");
	f->setAllTextures("cotton_green.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_GREEN)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_OUTER_GREEN;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_inner(f);
	f->setInventoryTextureNodeBox(i,"cotton_green.png", "cotton_green.png", "cotton_green.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_OUTER_GREEN;
	f = &content_features(i);
	f->description = gettext("Green Couch");
	f->setAllTextures("cotton_green.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_GREEN)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CHAIR_GREEN;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_outer(f);
	f->setInventoryTextureNodeBox(i,"cotton_green.png", "cotton_green.png", "cotton_green.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CHAIR_GREEN;
	f = &content_features(i);
	f->description = gettext("Green Couch");
	f->setAllTextures("cotton_green.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_GREEN)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CENTRE_GREEN;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_chair(f);
	f->setInventoryTextureNodeBox(i,"cotton_green.png", "cotton_green.png", "cotton_green.png");
	crafting::setVRecipe(CONTENT_COTTON_GREEN,CONTENT_COUCH_CHAIR_GREEN,2);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR,CONTENT_CRAFTITEM_DYE_GREEN,CONTENT_COUCH_CHAIR_GREEN);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CENTRE_ORANGE;
	f = &content_features(i);
	f->description = gettext("Orange Couch");
	f->setAllTextures("cotton_orange.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_ORANGE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDL_ORANGE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_centre(f);
	f->setInventoryTextureNodeBox(i,"cotton_orange.png", "cotton_orange.png", "cotton_orange.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDL_ORANGE;
	f = &content_features(i);
	f->description = gettext("Orange Couch");
	f->setAllTextures("cotton_orange.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_ORANGE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDR_ORANGE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_left(f);
	f->setInventoryTextureNodeBox(i,"cotton_orange.png", "cotton_orange.png", "cotton_orange.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDR_ORANGE;
	f = &content_features(i);
	f->description = gettext("Orange Couch");
	f->setAllTextures("cotton_orange.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_ORANGE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_INNER_ORANGE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_right(f);
	f->setInventoryTextureNodeBox(i,"cotton_orange.png", "cotton_orange.png", "cotton_orange.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_INNER_ORANGE;
	f = &content_features(i);
	f->description = gettext("Orange Couch");
	f->setAllTextures("cotton_orange.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_ORANGE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_OUTER_ORANGE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_inner(f);
	f->setInventoryTextureNodeBox(i,"cotton_orange.png", "cotton_orange.png", "cotton_orange.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_OUTER_ORANGE;
	f = &content_features(i);
	f->description = gettext("Orange Couch");
	f->setAllTextures("cotton_orange.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_ORANGE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CHAIR_ORANGE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_outer(f);
	f->setInventoryTextureNodeBox(i,"cotton_orange.png", "cotton_orange.png", "cotton_orange.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CHAIR_ORANGE;
	f = &content_features(i);
	f->description = gettext("Orange Couch");
	f->setAllTextures("cotton_orange.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_ORANGE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CENTRE_ORANGE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_chair(f);
	f->setInventoryTextureNodeBox(i,"cotton_orange.png", "cotton_orange.png", "cotton_orange.png");
	crafting::setVRecipe(CONTENT_COTTON_ORANGE,CONTENT_COUCH_CHAIR_ORANGE,2);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR,CONTENT_CRAFTITEM_DYE_ORANGE,CONTENT_COUCH_CHAIR_ORANGE);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CENTRE_PURPLE;
	f = &content_features(i);
	f->description = gettext("Purple Couch");
	f->setAllTextures("cotton_purple.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_PURPLE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDL_PURPLE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_centre(f);
	f->setInventoryTextureNodeBox(i,"cotton_purple.png", "cotton_purple.png", "cotton_purple.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDL_PURPLE;
	f = &content_features(i);
	f->description = gettext("Purple Couch");
	f->setAllTextures("cotton_purple.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_PURPLE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDR_PURPLE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_left(f);
	f->setInventoryTextureNodeBox(i,"cotton_purple.png", "cotton_purple.png", "cotton_purple.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDR_PURPLE;
	f = &content_features(i);
	f->description = gettext("Purple Couch");
	f->setAllTextures("cotton_purple.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_PURPLE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_INNER_PURPLE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_right(f);
	f->setInventoryTextureNodeBox(i,"cotton_purple.png", "cotton_purple.png", "cotton_purple.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_INNER_PURPLE;
	f = &content_features(i);
	f->description = gettext("Purple Couch");
	f->setAllTextures("cotton_purple.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_PURPLE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_OUTER_PURPLE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_inner(f);
	f->setInventoryTextureNodeBox(i,"cotton_purple.png", "cotton_purple.png", "cotton_purple.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_OUTER_PURPLE;
	f = &content_features(i);
	f->description = gettext("Purple Couch");
	f->setAllTextures("cotton_purple.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_PURPLE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CHAIR_PURPLE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_outer(f);
	f->setInventoryTextureNodeBox(i,"cotton_purple.png", "cotton_purple.png", "cotton_purple.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CHAIR_PURPLE;
	f = &content_features(i);
	f->description = gettext("Purple Couch");
	f->setAllTextures("cotton_purple.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_PURPLE)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CENTRE_PURPLE;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_chair(f);
	f->setInventoryTextureNodeBox(i,"cotton_purple.png", "cotton_purple.png", "cotton_purple.png");
	crafting::setVRecipe(CONTENT_COTTON_PURPLE,CONTENT_COUCH_CHAIR_PURPLE,2);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR,CONTENT_CRAFTITEM_DYE_PURPLE,CONTENT_COUCH_CHAIR_PURPLE);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CENTRE_RED;
	f = &content_features(i);
	f->description = gettext("Red Couch");
	f->setAllTextures("cotton_red.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_RED)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDL_RED;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_centre(f);
	f->setInventoryTextureNodeBox(i,"cotton_red.png", "cotton_red.png", "cotton_red.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDL_RED;
	f = &content_features(i);
	f->description = gettext("Red Couch");
	f->setAllTextures("cotton_red.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_RED)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDR_RED;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_left(f);
	f->setInventoryTextureNodeBox(i,"cotton_red.png", "cotton_red.png", "cotton_red.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDR_RED;
	f = &content_features(i);
	f->description = gettext("Red Couch");
	f->setAllTextures("cotton_red.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_RED)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_INNER_RED;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_right(f);
	f->setInventoryTextureNodeBox(i,"cotton_red.png", "cotton_red.png", "cotton_red.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_INNER_RED;
	f = &content_features(i);
	f->description = gettext("Red Couch");
	f->setAllTextures("cotton_red.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_RED)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_OUTER_RED;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_inner(f);
	f->setInventoryTextureNodeBox(i,"cotton_red.png", "cotton_red.png", "cotton_red.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_OUTER_RED;
	f = &content_features(i);
	f->description = gettext("Red Couch");
	f->setAllTextures("cotton_red.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_RED)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CHAIR_RED;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_outer(f);
	f->setInventoryTextureNodeBox(i,"cotton_red.png", "cotton_red.png", "cotton_red.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CHAIR_RED;
	f = &content_features(i);
	f->description = gettext("Red Couch");
	f->setAllTextures("cotton_red.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_RED)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CENTRE_RED;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_chair(f);
	f->setInventoryTextureNodeBox(i,"cotton_red.png", "cotton_red.png", "cotton_red.png");
	crafting::setVRecipe(CONTENT_COTTON_RED,CONTENT_COUCH_CHAIR_RED,2);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR,CONTENT_CRAFTITEM_DYE_RED,CONTENT_COUCH_CHAIR_RED);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CENTRE_YELLOW;
	f = &content_features(i);
	f->description = gettext("Yellow Couch");
	f->setAllTextures("cotton_yellow.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_YELLOW)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDL_YELLOW;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_centre(f);
	f->setInventoryTextureNodeBox(i,"cotton_yellow.png", "cotton_yellow.png", "cotton_yellow.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDL_YELLOW;
	f = &content_features(i);
	f->description = gettext("Yellow Couch");
	f->setAllTextures("cotton_yellow.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_YELLOW)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDR_YELLOW;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_left(f);
	f->setInventoryTextureNodeBox(i,"cotton_yellow.png", "cotton_yellow.png", "cotton_yellow.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDR_YELLOW;
	f = &content_features(i);
	f->description = gettext("Yellow Couch");
	f->setAllTextures("cotton_yellow.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_YELLOW)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_INNER_YELLOW;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_right(f);
	f->setInventoryTextureNodeBox(i,"cotton_yellow.png", "cotton_yellow.png", "cotton_yellow.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_INNER_YELLOW;
	f = &content_features(i);
	f->description = gettext("Yellow Couch");
	f->setAllTextures("cotton_yellow.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_YELLOW)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_OUTER_YELLOW;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_inner(f);
	f->setInventoryTextureNodeBox(i,"cotton_yellow.png", "cotton_yellow.png", "cotton_yellow.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_OUTER_YELLOW;
	f = &content_features(i);
	f->description = gettext("Yellow Couch");
	f->setAllTextures("cotton_yellow.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_YELLOW)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CHAIR_YELLOW;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_outer(f);
	f->setInventoryTextureNodeBox(i,"cotton_yellow.png", "cotton_yellow.png", "cotton_yellow.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CHAIR_YELLOW;
	f = &content_features(i);
	f->description = gettext("Yellow Couch");
	f->setAllTextures("cotton_yellow.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_YELLOW)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CENTRE_YELLOW;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_chair(f);
	f->setInventoryTextureNodeBox(i,"cotton_yellow.png", "cotton_yellow.png", "cotton_yellow.png");
	crafting::setVRecipe(CONTENT_COTTON_YELLOW,CONTENT_COUCH_CHAIR_YELLOW,2);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR,CONTENT_CRAFTITEM_DYE_YELLOW,CONTENT_COUCH_CHAIR_YELLOW);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CENTRE_BLACK;
	f = &content_features(i);
	f->description = gettext("Black Couch");
	f->setAllTextures("cotton_black.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_BLACK)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDL_BLACK;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_centre(f);
	f->setInventoryTextureNodeBox(i,"cotton_black.png", "cotton_black.png", "cotton_black.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDL_BLACK;
	f = &content_features(i);
	f->description = gettext("Black Couch");
	f->setAllTextures("cotton_black.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_BLACK)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_ENDR_BLACK;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_left(f);
	f->setInventoryTextureNodeBox(i,"cotton_black.png", "cotton_black.png", "cotton_black.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_ENDR_BLACK;
	f = &content_features(i);
	f->description = gettext("Black Couch");
	f->setAllTextures("cotton_black.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_BLACK)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_INNER_BLACK;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_right(f);
	f->setInventoryTextureNodeBox(i,"cotton_black.png", "cotton_black.png", "cotton_black.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_INNER_BLACK;
	f = &content_features(i);
	f->description = gettext("Black Couch");
	f->setAllTextures("cotton_black.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_BLACK)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_OUTER_BLACK;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_inner(f);
	f->setInventoryTextureNodeBox(i,"cotton_black.png", "cotton_black.png", "cotton_black.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_OUTER_BLACK;
	f = &content_features(i);
	f->description = gettext("Black Couch");
	f->setAllTextures("cotton_black.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_BLACK)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CHAIR_BLACK;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_outer(f);
	f->setInventoryTextureNodeBox(i,"cotton_black.png", "cotton_black.png", "cotton_black.png");
	f->suffocation_per_second = 0;

	i = CONTENT_COUCH_CHAIR_BLACK;
	f = &content_features(i);
	f->description = gettext("Black Couch");
	f->setAllTextures("cotton_black.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->is_ground_content = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_COUCH_CHAIR_BLACK)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_COUCH;
	f->type = CMT_DIRT;
	f->dig_time = 1.0;
	f->onpunch_replace_node = CONTENT_COUCH_CENTRE_BLACK;
	f->onpunch_replace_respects_borderstone = true;
	content_nodebox_couch_chair(f);
	f->setInventoryTextureNodeBox(i,"cotton_black.png", "cotton_black.png", "cotton_black.png");
	crafting::setVRecipe(CONTENT_COTTON_BLACK,CONTENT_COUCH_CHAIR_BLACK,2);
	crafting::set1Any2Recipe(CONTENT_COUCH_CHAIR,CONTENT_CRAFTITEM_DYE_BLACK,CONTENT_COUCH_CHAIR_BLACK);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_CHAIR;
	f = &content_features(i);
	f->description = gettext("Chair");
	f->setAllTextures("pine.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->air_equivalent = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_CHAIR;
	content_nodebox_chair(f);
	f->onpunch_replace_node = CONTENT_CHAIR_CENTRE;
	f->onpunch_replace_respects_borderstone = true;
	f->setInventoryTextureNodeBox(i,"pine.png", "pine.png", "pine.png");
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_CRUSHABLE;
	{
		u16 r[9] = {
			CONTENT_CRAFTITEM_PINE_PLANK,	CONTENT_IGNORE,			CONTENT_IGNORE,
			CONTENT_WOOD_PINE,		CONTENT_WOOD_PINE,		CONTENT_IGNORE,
			CONTENT_CRAFTITEM_PINE_PLANK,	CONTENT_CRAFTITEM_PINE_PLANK,	CONTENT_IGNORE
		};
		crafting::setRecipe(r,CONTENT_CHAIR,2);
	}
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_CHAIR_CENTRE;
	f = &content_features(i);
	f->description = gettext("Chair");
	f->setAllTextures("pine.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->air_equivalent = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_CHAIR)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_CHAIR;
	content_nodebox_chair_centre(f);
	f->onpunch_replace_node = CONTENT_CHAIR_ENDL;
	f->onpunch_replace_respects_borderstone = true;
	f->setInventoryTextureNodeBox(i,"pine.png", "pine.png", "pine.png");
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_CRUSHABLE;
	f->suffocation_per_second = 0;

	i = CONTENT_CHAIR_ENDL;
	f = &content_features(i);
	f->description = gettext("Chair");
	f->setAllTextures("pine.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->air_equivalent = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_CHAIR)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_CHAIR;
	content_nodebox_chair_endl(f);
	f->onpunch_replace_node = CONTENT_CHAIR_ENDR;
	f->onpunch_replace_respects_borderstone = true;
	f->setInventoryTextureNodeBox(i,"pine.png", "pine.png", "pine.png");
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_CRUSHABLE;
	f->suffocation_per_second = 0;

	i = CONTENT_CHAIR_ENDR;
	f = &content_features(i);
	f->description = gettext("Chair");
	f->setAllTextures("pine.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->air_equivalent = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_CHAIR)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_CHAIR;
	content_nodebox_chair_endr(f);
	f->onpunch_replace_node = CONTENT_CHAIR_INNER;
	f->onpunch_replace_respects_borderstone = true;
	f->setInventoryTextureNodeBox(i,"pine.png", "pine.png", "pine.png");
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_CRUSHABLE;
	f->suffocation_per_second = 0;

	i = CONTENT_CHAIR_INNER;
	f = &content_features(i);
	f->description = gettext("Chair");
	f->setAllTextures("pine.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->air_equivalent = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_CHAIR)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_CHAIR;
	content_nodebox_chair_inner(f);
	f->onpunch_replace_node = CONTENT_CHAIR_OUTER;
	f->onpunch_replace_respects_borderstone = true;
	f->setInventoryTextureNodeBox(i,"pine.png", "pine.png", "pine.png");
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_CRUSHABLE;
	f->suffocation_per_second = 0;

	i = CONTENT_CHAIR_OUTER;
	f = &content_features(i);
	f->description = gettext("Chair");
	f->setAllTextures("pine.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->air_equivalent = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_CHAIR)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_CHAIR;
	content_nodebox_chair_outer(f);
	f->onpunch_replace_node = CONTENT_CHAIR;
	f->onpunch_replace_respects_borderstone = true;
	f->setInventoryTextureNodeBox(i,"pine.png", "pine.png", "pine.png");
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_CRUSHABLE;
	f->suffocation_per_second = 0;

	i = CONTENT_TABLE;
	f = &content_features(i);
	f->description = gettext("Table");
	f->setAllTextures("pine.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->air_equivalent = true;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_TABLE;
	content_nodebox_table(f);
	f->setInventoryTextureNodeBox(i,"pine.png", "pine.png", "pine.png");
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_CRUSHABLE;
	{
		u16 r[9] = {
			CONTENT_WOOD_PINE,		CONTENT_WOOD_PINE,		CONTENT_WOOD_PINE,
			CONTENT_CRAFTITEM_PINE_PLANK,	CONTENT_IGNORE,			CONTENT_CRAFTITEM_PINE_PLANK,
			CONTENT_IGNORE,			CONTENT_IGNORE,			CONTENT_IGNORE,
		};
		crafting::setRecipe(r,CONTENT_TABLE,1);
	}
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_BED_HEAD;
	f = &content_features(i);
	f->description = gettext("Bed");
	f->setTexture(0,"cotton.png^bed_head.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton.png^bed_side_head.png");
	f->setTexture(3,"cotton.png^bed_side_head.png^[transformFX");
	f->setTexture(4,"cotton.png^bed_end.png");
	f->setTexture(5,"cotton.png^bed_end.png");
	f->setInventoryTexture("bed_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->onact_also_affects = v3s16(0,0,1);
	content_nodebox_bed_head(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	crafting::setBedRecipe(CONTENT_COTTON,CONTENT_BED_HEAD);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;
	if (f->initial_metadata == NULL)
		f->initial_metadata = new BedNodeMetadata();

	i = CONTENT_BED_FOOT;
	f = &content_features(i);
	f->description = gettext("Bed");
	f->setTexture(0,"cotton.png^bed_top.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton.png^bed_side.png^[transformFX");
	f->setTexture(3,"cotton.png^bed_side.png");
	f->setTexture(4,"cotton.png^bed_end.png");
	f->setTexture(5,"cotton.png^bed_end.png");
	f->setInventoryTexture("bed_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_BED_HEAD)+" 1";
	f->onact_also_affects = v3s16(0,0,-1);
	content_nodebox_bed_foot(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	f->suffocation_per_second = 0;

	i = CONTENT_BED_BLUE_HEAD;
	f = &content_features(i);
	f->description = gettext("Blue Bed");
	f->setTexture(0,"cotton_blue.png^bed_head.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton_blue.png^bed_side_head.png");
	f->setTexture(3,"cotton_blue.png^bed_side_head.png^[transformFX");
	f->setTexture(4,"cotton_blue.png^bed_end.png");
	f->setTexture(5,"cotton_blue.png^bed_end.png");
	f->setInventoryTexture("bed_blue_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->onact_also_affects = v3s16(0,0,1);
	content_nodebox_bed_head(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	crafting::setBedRecipe(CONTENT_COTTON_BLUE,CONTENT_BED_BLUE_HEAD);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;
	if (f->initial_metadata == NULL)
		f->initial_metadata = new BedNodeMetadata();

	i = CONTENT_BED_BLUE_FOOT;
	f = &content_features(i);
	f->description = gettext("Blue Bed");
	f->setTexture(0,"cotton_blue.png^bed_top.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton_blue.png^bed_side.png^[transformFX");
	f->setTexture(3,"cotton_blue.png^bed_side.png");
	f->setTexture(4,"cotton_blue.png^bed_end.png");
	f->setTexture(5,"cotton_blue.png^bed_end.png");
	f->setInventoryTexture("bed_blue_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_BED_BLUE_HEAD)+" 1";
	f->onact_also_affects = v3s16(0,0,-1);
	content_nodebox_bed_foot(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	f->suffocation_per_second = 0;

	i = CONTENT_BED_GREEN_HEAD;
	f = &content_features(i);
	f->description = gettext("Green Bed");
	f->setTexture(0,"cotton_green.png^bed_head.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton_green.png^bed_side_head.png");
	f->setTexture(3,"cotton_green.png^bed_side_head.png^[transformFX");
	f->setTexture(4,"cotton_green.png^bed_end.png");
	f->setTexture(5,"cotton_green.png^bed_end.png");
	f->setInventoryTexture("bed_green_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->onact_also_affects = v3s16(0,0,1);
	content_nodebox_bed_head(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	crafting::setBedRecipe(CONTENT_COTTON_GREEN,CONTENT_BED_GREEN_HEAD);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;
	if (f->initial_metadata == NULL)
		f->initial_metadata = new BedNodeMetadata();

	i = CONTENT_BED_GREEN_FOOT;
	f = &content_features(i);
	f->description = gettext("Green Bed");
	f->setTexture(0,"cotton_green.png^bed_top.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton_green.png^bed_side.png^[transformFX");
	f->setTexture(3,"cotton_green.png^bed_side.png");
	f->setTexture(4,"cotton_green.png^bed_end.png");
	f->setTexture(5,"cotton_green.png^bed_end.png");
	f->setInventoryTexture("bed_green_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_BED_GREEN_HEAD)+" 1";
	f->onact_also_affects = v3s16(0,0,-1);
	content_nodebox_bed_foot(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	f->suffocation_per_second = 0;

	i = CONTENT_BED_ORANGE_HEAD;
	f = &content_features(i);
	f->description = gettext("Orange Bed");
	f->setTexture(0,"cotton_orange.png^bed_head.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton_orange.png^bed_side_head.png");
	f->setTexture(3,"cotton_orange.png^bed_side_head.png^[transformFX");
	f->setTexture(4,"cotton_orange.png^bed_end.png");
	f->setTexture(5,"cotton_orange.png^bed_end.png");
	f->setInventoryTexture("bed_orange_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->onact_also_affects = v3s16(0,0,1);
	content_nodebox_bed_head(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	crafting::setBedRecipe(CONTENT_COTTON_ORANGE,CONTENT_BED_ORANGE_HEAD);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;
	if (f->initial_metadata == NULL)
		f->initial_metadata = new BedNodeMetadata();

	i = CONTENT_BED_ORANGE_FOOT;
	f = &content_features(i);
	f->description = gettext("Orange Bed");
	f->setTexture(0,"cotton_orange.png^bed_top.png");
	f->setTexture(1,"cotton_orange.png^bed_bottom.png");
	f->setTexture(2,"cotton_orange.png^bed_side.png^[transformFX");
	f->setTexture(3,"cotton_orange.png^bed_side.png");
	f->setTexture(4,"cotton_orange.png^bed_end.png");
	f->setTexture(5,"cotton_orange.png^bed_end.png");
	f->setInventoryTexture("bed_orange_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_BED_ORANGE_HEAD)+" 1";
	f->onact_also_affects = v3s16(0,0,-1);
	content_nodebox_bed_foot(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	f->suffocation_per_second = 0;

	i = CONTENT_BED_PURPLE_HEAD;
	f = &content_features(i);
	f->description = gettext("Purple Bed");
	f->setTexture(0,"cotton_purple.png^bed_head.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton_purple.png^bed_side_head.png");
	f->setTexture(3,"cotton_purple.png^bed_side_head.png^[transformFX");
	f->setTexture(4,"cotton_purple.png^bed_end.png");
	f->setTexture(5,"cotton_purple.png^bed_end.png");
	f->setInventoryTexture("bed_purple_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->onact_also_affects = v3s16(0,0,1);
	content_nodebox_bed_head(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	crafting::setBedRecipe(CONTENT_COTTON_PURPLE,CONTENT_BED_PURPLE_HEAD);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;
	if (f->initial_metadata == NULL)
		f->initial_metadata = new BedNodeMetadata();

	i = CONTENT_BED_PURPLE_FOOT;
	f = &content_features(i);
	f->description = gettext("Purple Bed");
	f->setTexture(0,"cotton_purple.png^bed_top.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton_purple.png^bed_side.png^[transformFX");
	f->setTexture(3,"cotton_purple.png^bed_side.png");
	f->setTexture(4,"cotton_purple.png^bed_end.png");
	f->setTexture(5,"cotton_purple.png^bed_end.png");
	f->setInventoryTexture("bed_purple_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_BED_PURPLE_HEAD)+" 1";
	f->onact_also_affects = v3s16(0,0,-1);
	content_nodebox_bed_foot(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	f->suffocation_per_second = 0;

	i = CONTENT_BED_RED_HEAD;
	f = &content_features(i);
	f->description = gettext("Red Bed");
	f->setTexture(0,"cotton_red.png^bed_head.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton_red.png^bed_side_head.png");
	f->setTexture(3,"cotton_red.png^bed_side_head.png^[transformFX");
	f->setTexture(4,"cotton_red.png^bed_end.png");
	f->setTexture(5,"cotton_red.png^bed_end.png");
	f->setInventoryTexture("bed_red_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->onact_also_affects = v3s16(0,0,1);
	content_nodebox_bed_head(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	crafting::setBedRecipe(CONTENT_COTTON_RED,CONTENT_BED_RED_HEAD);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;
	if (f->initial_metadata == NULL)
		f->initial_metadata = new BedNodeMetadata();

	i = CONTENT_BED_RED_FOOT;
	f = &content_features(i);
	f->description = gettext("Red Bed");
	f->setTexture(0,"cotton_red.png^bed_top.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton_red.png^bed_side.png^[transformFX");
	f->setTexture(3,"cotton_red.png^bed_side.png");
	f->setTexture(4,"cotton_red.png^bed_end.png");
	f->setTexture(5,"cotton_red.png^bed_end.png");
	f->setInventoryTexture("bed_red_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_BED_RED_HEAD)+" 1";
	f->onact_also_affects = v3s16(0,0,-1);
	content_nodebox_bed_foot(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	f->suffocation_per_second = 0;

	i = CONTENT_BED_YELLOW_HEAD;
	f = &content_features(i);
	f->description = gettext("Yellow Bed");
	f->setTexture(0,"cotton_yellow.png^bed_head.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton_yellow.png^bed_side_head.png");
	f->setTexture(3,"cotton_yellow.png^bed_side_head.png^[transformFX");
	f->setTexture(4,"cotton_yellow.png^bed_end.png");
	f->setTexture(5,"cotton_yellow.png^bed_end.png");
	f->setInventoryTexture("bed_yellow_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->onact_also_affects = v3s16(0,0,1);
	content_nodebox_bed_head(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	crafting::setBedRecipe(CONTENT_COTTON_YELLOW,CONTENT_BED_YELLOW_HEAD);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;
	if (f->initial_metadata == NULL)
		f->initial_metadata = new BedNodeMetadata();

	i = CONTENT_BED_YELLOW_FOOT;
	f = &content_features(i);
	f->description = gettext("Yellow Bed");
	f->setTexture(0,"cotton_yellow.png^bed_top.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton_yellow.png^bed_side.png^[transformFX");
	f->setTexture(3,"cotton_yellow.png^bed_side.png");
	f->setTexture(4,"cotton_yellow.png^bed_end.png");
	f->setTexture(5,"cotton_yellow.png^bed_end.png");
	f->setInventoryTexture("bed_yellow_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_BED_YELLOW_HEAD)+" 1";
	f->onact_also_affects = v3s16(0,0,-1);
	content_nodebox_bed_foot(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	f->suffocation_per_second = 0;

	i = CONTENT_BED_BLACK_HEAD;
	f = &content_features(i);
	f->description = gettext("Black Bed");
	f->setTexture(0,"cotton_black.png^bed_head.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton_black.png^bed_side_head.png");
	f->setTexture(3,"cotton_black.png^bed_side_head.png^[transformFX");
	f->setTexture(4,"cotton_black.png^bed_end.png");
	f->setTexture(5,"cotton_black.png^bed_end.png");
	f->setInventoryTexture("bed_black_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->onact_also_affects = v3s16(0,0,1);
	content_nodebox_bed_head(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	crafting::setBedRecipe(CONTENT_COTTON_BLACK,CONTENT_BED_BLACK_HEAD);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;
	if (f->initial_metadata == NULL)
		f->initial_metadata = new BedNodeMetadata();

	i = CONTENT_BED_BLACK_FOOT;
	f = &content_features(i);
	f->description = gettext("Black Bed");
	f->setTexture(0,"cotton_black.png^bed_top.png");
	f->setTexture(1,"bed_bottom.png");
	f->setTexture(2,"cotton_black.png^bed_side.png^[transformFX");
	f->setTexture(3,"cotton_black.png^bed_side.png");
	f->setTexture(4,"cotton_black.png^bed_end.png");
	f->setTexture(5,"cotton_black.png^bed_end.png");
	f->setInventoryTexture("bed_black_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_BED_BLACK_HEAD)+" 1";
	f->onact_also_affects = v3s16(0,0,-1);
	content_nodebox_bed_foot(f);
	f->type = CMT_WOOD;
	f->dig_time = 0.25;
	f->pressure_type = CST_SOLID;
	f->suffocation_per_second = 0;

	i = CONTENT_BED_CAMP_HEAD;
	f = &content_features(i);
	f->description = gettext("Camp Bed");
	f->setAllTextures("hay_bale.png");
	f->setTexture(0,"bed_camp_top.png");
	f->setInventoryTexture("bed_camp_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_CAMP_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->onact_also_affects = v3s16(0,0,1);
	content_nodebox_slab(f);
	f->type = CMT_PLANT;
	f->dig_time = 0.25;
	f->pressure_type = CST_CRUSHABLE;
	{
		content_t r[9] = {
			CONTENT_CRAFTITEM_FUR,	CONTENT_CRAFTITEM_FUR,	CONTENT_IGNORE,
			CONTENT_HAY,		CONTENT_HAY,		CONTENT_IGNORE,
			CONTENT_IGNORE,		CONTENT_IGNORE,		CONTENT_IGNORE
		};
		crafting::setRecipe(r,CONTENT_BED_CAMP_HEAD,1);
	}
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;
	if (f->initial_metadata == NULL)
		f->initial_metadata = new CampBedNodeMetadata();

	i = CONTENT_BED_CAMP_FOOT;
	f = &content_features(i);
	f->description = gettext("Camp Bed");
	f->setAllTextures("hay_bale.png");
	f->setTexture(0,"bed_camp_top.png");
	f->setInventoryTexture("bed_camp_inv.png");
	f->wield_nodebox = false;
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->rotate_tile_with_nodebox = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_CAMP_BED;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_BED_CAMP_HEAD)+" 1";
	f->onact_also_affects = v3s16(0,0,-1);
	content_nodebox_slab(f);
	f->type = CMT_PLANT;
	f->dig_time = 0.25;
	f->pressure_type = CST_CRUSHABLE;
	f->suffocation_per_second = 0;

	// Paintings
	i = CONTENT_PAINTING_WHITE;
	f = &content_features(i);
	f->description = gettext("Colorful Painting");
	f->setAllTextures("painting.png");
	f->setTexture(4, "painting.png");
	f->setTexture(5, "painting_white.png");
	f->setInventoryTexture("painting_white.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_WALLMOUNT;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->walkable = false;
	f->air_equivalent = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_PAINTING;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_PAINTING_WHITE)+" 1";
	f->type = CMT_WOOD;
	content_nodebox_painting(f);
	f->dig_time = 0.1;
	f->pressure_type = CST_CRUSHABLE;
	{
		u16 r[9] = {
			CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,
			CONTENT_CRAFTITEM_STRING, CONTENT_CRAFTITEM_DYE_WHITE, CONTENT_CRAFTITEM_STRING,
			CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK
		};
		crafting::setRecipe(r,CONTENT_PAINTING_WHITE,1);
	}
	crafting::set1Any2Recipe(CONTENT_PAINTING_CANVAS,CONTENT_CRAFTITEM_DYE_WHITE,CONTENT_PAINTING_WHITE);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_PAINTING_RED;
	f = &content_features(i);
	f->description = gettext("Red Rose Painting");
	f->setAllTextures("painting.png");
	f->setTexture(4, "painting.png");
	f->setTexture(5, "painting_red.png");
	f->setInventoryTexture("painting_red.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_WALLMOUNT;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->walkable = false;
	f->air_equivalent = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_PAINTING;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_PAINTING_RED)+" 1";
	f->type = CMT_WOOD;
	content_nodebox_painting(f);
	f->dig_time = 0.1;
	f->pressure_type = CST_CRUSHABLE;
	{
		u16 r[9] = {
			CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,
			CONTENT_CRAFTITEM_STRING, CONTENT_CRAFTITEM_DYE_RED, CONTENT_CRAFTITEM_STRING,
			CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK
		};
		crafting::setRecipe(r,CONTENT_PAINTING_RED,1);
	}
	crafting::set1Any2Recipe(CONTENT_PAINTING_CANVAS,CONTENT_CRAFTITEM_DYE_RED,CONTENT_PAINTING_RED);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_PAINTING_GREEN;
	f = &content_features(i);
	f->description = gettext("Field Painting");
	f->setAllTextures("painting.png");
	f->setTexture(4, "painting.png");
	f->setTexture(5, "painting_green.png");
	f->setInventoryTexture("painting_green.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_WALLMOUNT;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->walkable = false;
	f->air_equivalent = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_PAINTING;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_PAINTING_GREEN)+" 1";
	f->type = CMT_WOOD;
	content_nodebox_painting(f);
	f->dig_time = 0.1;
	f->pressure_type = CST_CRUSHABLE;
	{
		u16 r[9] = {
			CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,
			CONTENT_CRAFTITEM_STRING, CONTENT_CRAFTITEM_DYE_GREEN, CONTENT_CRAFTITEM_STRING,
			CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK
		};
		crafting::setRecipe(r,CONTENT_PAINTING_GREEN,1);
	}
	crafting::set1Any2Recipe(CONTENT_PAINTING_CANVAS,CONTENT_CRAFTITEM_DYE_GREEN,CONTENT_PAINTING_GREEN);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_PAINTING_BLUE;
	f = &content_features(i);
	f->description = gettext("Blue Flower Painting");
	f->setAllTextures("painting.png");
	f->setTexture(4, "painting.png");
	f->setTexture(5, "painting_blue.png");
	f->setInventoryTexture("painting_blue.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_WALLMOUNT;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->walkable = false;
	f->air_equivalent = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_PAINTING;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_PAINTING_BLUE)+" 1";
	f->type = CMT_WOOD;
	content_nodebox_painting(f);
	f->dig_time = 0.1;
	f->pressure_type = CST_CRUSHABLE;
	{
		u16 r[9] = {
			CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,
			CONTENT_CRAFTITEM_STRING, CONTENT_CRAFTITEM_DYE_BLUE, CONTENT_CRAFTITEM_STRING,
			CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK
		};
		crafting::setRecipe(r,CONTENT_PAINTING_BLUE,1);
	}
	crafting::set1Any2Recipe(CONTENT_PAINTING_CANVAS,CONTENT_CRAFTITEM_DYE_BLUE,CONTENT_PAINTING_BLUE);
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_PAINTING_CANVAS;
	f = &content_features(i);
	f->description = gettext("Painting Canvas");
	f->setAllTextures("painting.png");
	f->setTexture(4, "painting.png");
	f->setTexture(5, "painting_canvas.png");
	f->setInventoryTexture("painting_canvas.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_WALLMOUNT;
	f->draw_type = CDT_NODEBOX;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->walkable = false;
	f->air_equivalent = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_PAINTING;
	f->dug_item = std::string("MaterialItem2 ")+itos(CONTENT_PAINTING_CANVAS)+" 1";
	f->type = CMT_WOOD;
	content_nodebox_painting(f);
	f->dig_time = 0.1;
	f->pressure_type = CST_CRUSHABLE;
	crafting::set1Any2Recipe(CONTENT_PAINTING_WHITE,CONTENT_CRAFTITEM_STARCH,CONTENT_PAINTING_CANVAS);
	crafting::set1Any2Recipe(CONTENT_PAINTING_RED,CONTENT_CRAFTITEM_STARCH,CONTENT_PAINTING_CANVAS);
	crafting::set1Any2Recipe(CONTENT_PAINTING_GREEN,CONTENT_CRAFTITEM_STARCH,CONTENT_PAINTING_CANVAS);
	crafting::set1Any2Recipe(CONTENT_PAINTING_BLUE,CONTENT_CRAFTITEM_STARCH,CONTENT_PAINTING_CANVAS);
	{
		u16 r[9] = {
			CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,
			CONTENT_CRAFTITEM_STRING, CONTENT_IGNORE, CONTENT_CRAFTITEM_STRING,
			CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK,	CONTENT_CRAFTITEM_STICK
		};
		crafting::setRecipe(r,CONTENT_PAINTING_CANVAS,1);
	}
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;

	i = CONTENT_CLOCK;
	f = &content_features(i);
	f->description = gettext("Clock");
	f->setAllTextures("clock.png");
	f->setTexture(5, "clock_front.png");
	f->setAllMetaTextures("clock_numbers.png");
	f->param_type = CPT_LIGHT;
	f->param2_type = CPT_FACEDIR_SIMPLE;
	f->draw_type = CDT_NODEBOX_META;
	f->light_propagates = true;
	f->sunlight_propagates = true;
	f->walkable = false;
	f->air_equivalent = true;
	f->flammable = 1; // can be replaced by fire if the node under it is set on fire
	f->fuel_time = BT_CLOCK;
	f->dug_item = std::string("MaterialItem2 ")+itos(i)+" 1";
	f->type = CMT_WOOD;
	f->dig_time = 0.1;
	content_nodebox_clock(f);
	f->setInventoryTextureNodeBox(i,"clock.png","clock_front.png","clock.png");
	f->pressure_type = CST_CRUSHABLE;
	if (f->initial_metadata == NULL)
		f->initial_metadata = new ClockNodeMetadata();
	{
		u16 r[9] = {
			CONTENT_CRAFTITEM_PINE_PLANK,	CONTENT_CRAFTITEM_PINE_PLANK,	CONTENT_CRAFTITEM_PINE_PLANK,
			CONTENT_CRAFTITEM_PINE_PLANK,	CONTENT_CRAFTITEM_MITHRILDUST,	CONTENT_CRAFTITEM_PINE_PLANK,
			CONTENT_CRAFTITEM_PINE_PLANK,	CONTENT_CRAFTITEM_PINE_PLANK,	CONTENT_CRAFTITEM_PINE_PLANK
		};
		crafting::setRecipe(r,CONTENT_CLOCK,1);
	}
	content_list_add("craftguide",i,1,0);
	content_list_add("creative",i,1,0);
	f->suffocation_per_second = 0;
}
