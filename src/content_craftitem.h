/************************************************************************
* content_craftitem.h
* voxelands - 3d voxel world sandbox game
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
*
* License updated from GPLv2 or later to GPLv3 or later by Lisa Milne
* for Voxelands.
************************************************************************/

#ifndef CONTENT_CRAFTITEM_HEADER
#define CONTENT_CRAFTITEM_HEADER

#include "mapnode.h"

#define CONTENT_CRAFTITEM_MASK 0x8000

struct CraftItemFeatures {
	content_t content;
	std::string texture;
	// if additional overlays are used, the texture name is made from
	// <overlay_base>_<overlay>.png
	std::string overlay_base;
	// the old 'subname'
	std::string name;
	// tooltip used in inventory
	char* description;
	// the result of cooking this item
	content_t cook_result;
	// what type of cooking device this item needs
	CookType cook_type;
	// the result of crushing this item
	content_t crush_result;
	// what type of crushing device this item needs
	CrushType crush_type;
	// the fuel value of this item
	float fuel_time;
	// whether the item can be stacked in inventory
	bool stackable;
	// whether the item can be eaten/drank, must be true for *_effect to work
	bool consumable;
		// if an item has both hunger and health effects, it will
		// not affect health unless hunger is full
		// number of hunger points this will refill
		s16 hunger_effect;
		// number of health points this will refill
		s16 health_effect;
		// number of seconds will protect player against cold damage
		s16 cold_effect;
		// will refill energy at double full speed for this many seconds
		s16 energy_effect;
	// the number dropped on right click, -1 for all
	s16 drop_count;
	// if this teleports the player home, -2 = no, -1 = default home
	// 0-7 for specific flag colours
	s8 teleports;
	// the data value of this item
	ContentParamType param_type;
	// used by mobs that are picked up
	content_t drop_item;
	// used by snowballs and such... things that are thrown
	content_t thrown_item;
	// used by arrows and such... things that are shot by a tool
	content_t shot_item;
	// when the item is Used, it should be replaced with this
	content_t onuse_replace_item;
	// if the item can be enchanted, it gives this
	content_t enchanted_item;
	// sound played when item is used
	std::string sound_use;
};

void content_craftitem_init();
CraftItemFeatures *content_craftitem_features(content_t i);

#define CONTENT_CRAFTITEM_PAPER (CONTENT_CRAFTITEM_MASK | 0x01)
#define CONTENT_CRAFTITEM_PADLOCK (CONTENT_CRAFTITEM_MASK | 0x02)
#define CONTENT_CRAFTITEM_CHARCOAL (CONTENT_CRAFTITEM_MASK | 0x03)
#define CONTENT_CRAFTITEM_COAL (CONTENT_CRAFTITEM_MASK | 0x04)
#define CONTENT_CRAFTITEM_IRON (CONTENT_CRAFTITEM_MASK | 0x05)
#define CONTENT_CRAFTITEM_CLAY (CONTENT_CRAFTITEM_MASK | 0x06)
#define CONTENT_CRAFTITEM_TIN (CONTENT_CRAFTITEM_MASK | 0x07)
#define CONTENT_CRAFTITEM_COPPER (CONTENT_CRAFTITEM_MASK | 0x08)
#define CONTENT_CRAFTITEM_SILVER (CONTENT_CRAFTITEM_MASK | 0x09)
#define CONTENT_CRAFTITEM_GOLD (CONTENT_CRAFTITEM_MASK | 0x0A)
#define CONTENT_CRAFTITEM_QUARTZ (CONTENT_CRAFTITEM_MASK | 0x0B)
#define CONTENT_CRAFTITEM_TIN_INGOT (CONTENT_CRAFTITEM_MASK | 0x0C)
#define CONTENT_CRAFTITEM_COPPER_INGOT (CONTENT_CRAFTITEM_MASK | 0x0D)
#define CONTENT_CRAFTITEM_SILVER_INGOT (CONTENT_CRAFTITEM_MASK | 0x0E)
#define CONTENT_CRAFTITEM_GOLD_INGOT (CONTENT_CRAFTITEM_MASK | 0x0F)
#define CONTENT_CRAFTITEM_FLINT (CONTENT_CRAFTITEM_MASK | 0x10)
#define CONTENT_CRAFTITEM_IRON_INGOT (CONTENT_CRAFTITEM_MASK | 0x11)
#define CONTENT_CRAFTITEM_CLAY_BRICK (CONTENT_CRAFTITEM_MASK | 0x12)
#define CONTENT_CRAFTITEM_RAT (CONTENT_CRAFTITEM_MASK | 0x13)
#define CONTENT_CRAFTITEM_COOKED_RAT (CONTENT_CRAFTITEM_MASK | 0x14)
#define CONTENT_CRAFTITEM_APPLE_PLANK (CONTENT_CRAFTITEM_MASK | 0x15)
#define CONTENT_CRAFTITEM_FIREFLY (CONTENT_CRAFTITEM_MASK | 0x16)
#define CONTENT_CRAFTITEM_APPLE (CONTENT_CRAFTITEM_MASK | 0x17)
#define CONTENT_CRAFTITEM_APPLE_IRON (CONTENT_CRAFTITEM_MASK | 0x18)
#define CONTENT_CRAFTITEM_DYE_BLUE (CONTENT_CRAFTITEM_MASK | 0x19)
#define CONTENT_CRAFTITEM_DYE_GREEN (CONTENT_CRAFTITEM_MASK | 0x1A)
#define CONTENT_CRAFTITEM_DYE_ORANGE (CONTENT_CRAFTITEM_MASK | 0x1B)
#define CONTENT_CRAFTITEM_DYE_PURPLE (CONTENT_CRAFTITEM_MASK | 0x1C)
#define CONTENT_CRAFTITEM_DYE_RED (CONTENT_CRAFTITEM_MASK | 0x1D)
#define CONTENT_CRAFTITEM_DYE_YELLOW (CONTENT_CRAFTITEM_MASK | 0x1E)
#define CONTENT_CRAFTITEM_DYE_WHITE (CONTENT_CRAFTITEM_MASK | 0x1F)
#define CONTENT_CRAFTITEM_DYE_BLACK (CONTENT_CRAFTITEM_MASK | 0x20)
#define CONTENT_CRAFTITEM_QUARTZ_DUST (CONTENT_CRAFTITEM_MASK | 0x21)
#define CONTENT_CRAFTITEM_SALTPETER (CONTENT_CRAFTITEM_MASK | 0x22)
#define CONTENT_CRAFTITEM_GUNPOWDER (CONTENT_CRAFTITEM_MASK | 0x23)
#define CONTENT_CRAFTITEM_SNOW_BALL (CONTENT_CRAFTITEM_MASK | 0x24)
#define CONTENT_CRAFTITEM_STICK (CONTENT_CRAFTITEM_MASK | 0x25)
#define CONTENT_CRAFTITEM_PINE_PLANK (CONTENT_CRAFTITEM_MASK | 0x26)
#define CONTENT_CRAFTITEM_WOOD_PLANK (CONTENT_CRAFTITEM_MASK | 0x27)
#define CONTENT_CRAFTITEM_JUNGLE_PLANK (CONTENT_CRAFTITEM_MASK | 0x28)
#define CONTENT_CRAFTITEM_TNT (CONTENT_CRAFTITEM_MASK | 0x29)
#define CONTENT_CRAFTITEM_ASH (CONTENT_CRAFTITEM_MASK | 0x2A)
#define CONTENT_CRAFTITEM_APPLE_BLOSSOM (CONTENT_CRAFTITEM_MASK | 0x2B)
#define CONTENT_CRAFTITEM_CACTUS_FRUIT (CONTENT_CRAFTITEM_MASK | 0x2C)
#define CONTENT_CRAFTITEM_MUSH (CONTENT_CRAFTITEM_MASK | 0x2E)
#define CONTENT_CRAFTITEM_PUMPKINSLICE (CONTENT_CRAFTITEM_MASK | 0x2F)
#define CONTENT_CRAFTITEM_PUMPKIN_PIE_SLICE (CONTENT_CRAFTITEM_MASK | 0x32)
#define CONTENT_CRAFTITEM_APPLE_PIE_SLICE (CONTENT_CRAFTITEM_MASK | 0x33)
#define CONTENT_CRAFTITEM_MELONSLICE (CONTENT_CRAFTITEM_MASK | 0x34)
#define CONTENT_CRAFTITEM_WHEAT (CONTENT_CRAFTITEM_MASK | 0x35)
#define CONTENT_CRAFTITEM_FLOUR (CONTENT_CRAFTITEM_MASK | 0x36)
#define CONTENT_CRAFTITEM_DOUGH (CONTENT_CRAFTITEM_MASK | 0x37)
#define CONTENT_CRAFTITEM_BREAD (CONTENT_CRAFTITEM_MASK | 0x38)
#define CONTENT_CRAFTITEM_POTATO (CONTENT_CRAFTITEM_MASK | 0x39)
#define CONTENT_CRAFTITEM_STARCH (CONTENT_CRAFTITEM_MASK | 0x3A)
#define CONTENT_CRAFTITEM_ROASTPOTATO (CONTENT_CRAFTITEM_MASK | 0x3B)
#define CONTENT_CRAFTITEM_CARROT (CONTENT_CRAFTITEM_MASK | 0x3C)
#define CONTENT_CRAFTITEM_CARROT_CAKE_RAW (CONTENT_CRAFTITEM_MASK | 0x3D)
#define CONTENT_CRAFTITEM_CARROT_CAKE (CONTENT_CRAFTITEM_MASK | 0x3CE)
#define CONTENT_CRAFTITEM_BEETROOT (CONTENT_CRAFTITEM_MASK | 0x3F)
#define CONTENT_CRAFTITEM_GRAPE (CONTENT_CRAFTITEM_MASK | 0x40)
#define CONTENT_CRAFTITEM_STRING (CONTENT_CRAFTITEM_MASK | 0x41)
#define CONTENT_CRAFTITEM_MITHRILDUST (CONTENT_CRAFTITEM_MASK | 0x42)
#define CONTENT_CRAFTITEM_RESIN (CONTENT_CRAFTITEM_MASK | 0x43)
#define CONTENT_CRAFTITEM_OERKKI_DUST (CONTENT_CRAFTITEM_MASK | 0x44)
#define CONTENT_CRAFTITEM_FISH (CONTENT_CRAFTITEM_MASK | 0x45)
#define CONTENT_CRAFTITEM_COOKED_FISH (CONTENT_CRAFTITEM_MASK | 0x46)
#define CONTENT_CRAFTITEM_MEAT (CONTENT_CRAFTITEM_MASK | 0x47)
#define CONTENT_CRAFTITEM_COOKED_MEAT (CONTENT_CRAFTITEM_MASK | 0x48)
#define CONTENT_CRAFTITEM_COTTON_SHEET (CONTENT_CRAFTITEM_MASK | 0x49)
#define CONTENT_CRAFTITEM_COTTON_SHEET_BLUE (CONTENT_CRAFTITEM_MASK | 0x4A)
#define CONTENT_CRAFTITEM_COTTON_SHEET_GREEN (CONTENT_CRAFTITEM_MASK | 0x4B)
#define CONTENT_CRAFTITEM_COTTON_SHEET_ORANGE (CONTENT_CRAFTITEM_MASK | 0x4C)
#define CONTENT_CRAFTITEM_COTTON_SHEET_PURPLE (CONTENT_CRAFTITEM_MASK | 0x4D)
#define CONTENT_CRAFTITEM_COTTON_SHEET_RED (CONTENT_CRAFTITEM_MASK | 0x4E)
#define CONTENT_CRAFTITEM_COTTON_SHEET_YELLOW (CONTENT_CRAFTITEM_MASK | 0x4F)
#define CONTENT_CRAFTITEM_COTTON_SHEET_BLACK (CONTENT_CRAFTITEM_MASK | 0x50)
#define CONTENT_CRAFTITEM_CANVAS_SHEET (CONTENT_CRAFTITEM_MASK | 0x51)
#define CONTENT_CRAFTITEM_CANVAS_SHEET_BLUE (CONTENT_CRAFTITEM_MASK | 0x52)
#define CONTENT_CRAFTITEM_CANVAS_SHEET_GREEN (CONTENT_CRAFTITEM_MASK | 0x53)
#define CONTENT_CRAFTITEM_CANVAS_SHEET_ORANGE (CONTENT_CRAFTITEM_MASK | 0x54)
#define CONTENT_CRAFTITEM_CANVAS_SHEET_PURPLE (CONTENT_CRAFTITEM_MASK | 0x55)
#define CONTENT_CRAFTITEM_CANVAS_SHEET_RED (CONTENT_CRAFTITEM_MASK | 0x56)
#define CONTENT_CRAFTITEM_CANVAS_SHEET_YELLOW (CONTENT_CRAFTITEM_MASK | 0x57)
#define CONTENT_CRAFTITEM_CANVAS_SHEET_BLACK (CONTENT_CRAFTITEM_MASK | 0x58)
#define CONTENT_CRAFTITEM_FUR (CONTENT_CRAFTITEM_MASK | 0x59)
#define CONTENT_CRAFTITEM_FUR_WHITE (CONTENT_CRAFTITEM_MASK | 0x5A)
#define CONTENT_CRAFTITEM_FUR_BLUE (CONTENT_CRAFTITEM_MASK | 0x5B)
#define CONTENT_CRAFTITEM_FUR_GREEN (CONTENT_CRAFTITEM_MASK | 0x5C)
#define CONTENT_CRAFTITEM_FUR_ORANGE (CONTENT_CRAFTITEM_MASK | 0x5D)
#define CONTENT_CRAFTITEM_FUR_PURPLE (CONTENT_CRAFTITEM_MASK | 0x5E)
#define CONTENT_CRAFTITEM_FUR_RED (CONTENT_CRAFTITEM_MASK | 0x5F)
#define CONTENT_CRAFTITEM_FUR_YELLOW (CONTENT_CRAFTITEM_MASK | 0x60)
#define CONTENT_CRAFTITEM_FUR_BLACK (CONTENT_CRAFTITEM_MASK | 0x61)
#define CONTENT_CRAFTITEM_LEATHER (CONTENT_CRAFTITEM_MASK | 0x62)
#define CONTENT_CRAFTITEM_LEATHER_WHITE (CONTENT_CRAFTITEM_MASK | 0x63)
#define CONTENT_CRAFTITEM_LEATHER_BLUE (CONTENT_CRAFTITEM_MASK | 0x64)
#define CONTENT_CRAFTITEM_LEATHER_GREEN (CONTENT_CRAFTITEM_MASK | 0x65)
#define CONTENT_CRAFTITEM_LEATHER_ORANGE (CONTENT_CRAFTITEM_MASK | 0x66)
#define CONTENT_CRAFTITEM_LEATHER_PURPLE (CONTENT_CRAFTITEM_MASK | 0x67)
#define CONTENT_CRAFTITEM_LEATHER_RED (CONTENT_CRAFTITEM_MASK | 0x68)
#define CONTENT_CRAFTITEM_LEATHER_YELLOW (CONTENT_CRAFTITEM_MASK | 0x69)
#define CONTENT_CRAFTITEM_LEATHER_BLACK (CONTENT_CRAFTITEM_MASK | 0x6A)
#define CONTENT_CRAFTITEM_ARROW (CONTENT_CRAFTITEM_MASK | 0x6B)
#define CONTENT_CRAFTITEM_FERTILIZER (CONTENT_CRAFTITEM_MASK | 0x6C)
#define CONTENT_CRAFTITEM_OERKKI_DUST_WHITE (CONTENT_CRAFTITEM_MASK | 0x6D)
#define CONTENT_CRAFTITEM_OERKKI_DUST_BLUE (CONTENT_CRAFTITEM_MASK | 0x6E)
#define CONTENT_CRAFTITEM_OERKKI_DUST_GREEN (CONTENT_CRAFTITEM_MASK | 0x6F)
#define CONTENT_CRAFTITEM_OERKKI_DUST_ORANGE (CONTENT_CRAFTITEM_MASK | 0x70)
#define CONTENT_CRAFTITEM_OERKKI_DUST_PURPLE (CONTENT_CRAFTITEM_MASK | 0x71)
#define CONTENT_CRAFTITEM_OERKKI_DUST_RED (CONTENT_CRAFTITEM_MASK | 0x72)
#define CONTENT_CRAFTITEM_OERKKI_DUST_YELLOW (CONTENT_CRAFTITEM_MASK | 0x73)
#define CONTENT_CRAFTITEM_OERKKI_DUST_BLACK (CONTENT_CRAFTITEM_MASK | 0x74)
#define CONTENT_CRAFTITEM_GLASS_BOTTLE (CONTENT_CRAFTITEM_MASK | 0x75)
#define CONTENT_CRAFTITEM_GRAPE_JUICE (CONTENT_CRAFTITEM_MASK | 0x76)
#define CONTENT_CRAFTITEM_APPLE_JUICE (CONTENT_CRAFTITEM_MASK | 0x77)
#define CONTENT_CRAFTITEM_TEA_LEAVES (CONTENT_CRAFTITEM_MASK | 0x78)
#define CONTENT_CRAFTITEM_TEA (CONTENT_CRAFTITEM_MASK | 0x79)
#define CONTENT_CRAFTITEM_COFFEE_BEANS (CONTENT_CRAFTITEM_MASK | 0x7A)
#define CONTENT_CRAFTITEM_COFFEE (CONTENT_CRAFTITEM_MASK | 0x7B)
#define CONTENT_CRAFTITEM_IRON_BOTTLE (CONTENT_CRAFTITEM_MASK | 0x7C)
#define CONTENT_CRAFTITEM_IRON_BOTTLE_WATER (CONTENT_CRAFTITEM_MASK | 0x7D)
#define CONTENT_CRAFTITEM_GLASS_BOTTLE_WATER (CONTENT_CRAFTITEM_MASK | 0x7E)
#define CONTENT_CRAFTITEM_MITHRIL_RAW (CONTENT_CRAFTITEM_MASK | 0x7F)
#define CONTENT_CRAFTITEM_MITHRIL_UNBOUND (CONTENT_CRAFTITEM_MASK | 0x80)
#define CONTENT_CRAFTITEM_MITHRIL (CONTENT_CRAFTITEM_MASK | 0x81)
#define CONTENT_CRAFTITEM_RUBY (CONTENT_CRAFTITEM_MASK | 0x82)
#define CONTENT_CRAFTITEM_TURQUOISE (CONTENT_CRAFTITEM_MASK | 0x83)
#define CONTENT_CRAFTITEM_AMETHYST (CONTENT_CRAFTITEM_MASK | 0x84)
#define CONTENT_CRAFTITEM_SAPPHIRE (CONTENT_CRAFTITEM_MASK | 0x85)
#define CONTENT_CRAFTITEM_SUNSTONE (CONTENT_CRAFTITEM_MASK | 0x86)
#define CONTENT_CRAFTITEM_SALT (CONTENT_CRAFTITEM_MASK | 0x87)
#define CONTENT_CRAFTITEM_OERKKI_DUST_SPACE (CONTENT_CRAFTITEM_MASK | 0x88)
#define CONTENT_CRAFTITEM_BLUEBERRY (CONTENT_CRAFTITEM_MASK | 0x89)
#define CONTENT_CRAFTITEM_RASPBERRY (CONTENT_CRAFTITEM_MASK | 0x8A)
#define CONTENT_CRAFTITEM_UPGRADE_STORAGE (CONTENT_CRAFTITEM_MASK | 0x8B)
#define CONTENT_CRAFTITEM_UPGRADE_EXO (CONTENT_CRAFTITEM_MASK | 0x8C)

#endif
