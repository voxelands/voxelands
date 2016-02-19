/************************************************************************
* content_clothesitem.h
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

#ifndef CONTENT_CLOTHESITEM_HEADER
#define CONTENT_CLOTHESITEM_HEADER

#include "mapnode.h"
#include <map>

#define CONTENT_CLOTHESITEM_MASK 0x1000

enum ClothesType {
	CT_NONE, // used only when checking against an item that isn't clothes
	CT_PANTS,
	CT_SHIRT,
	CT_HAT,
	CT_BOOTS,
	CT_JACKET,
	CT_BELT,
	CT_DECORATIVE,
	CT_MEDALLION
};

struct ClothesItemFeatures {
	content_t content;
	// used for inventory / wielding etc
	std::string texture;
	// overlaid on the player texture so it can be seen as worn
	std::string overlay_texture;
	// tooltip used in inventory
	std::wstring description;
	// the type of this clothing
	ClothesType type;
	// the strength as armour
	f32 armour;
	// the effectiveness against the cold zone
	f32 warmth;
	// the effectiveness against vacuum / space
	f32 vacuum;
	// the effectiveness against suffocation
	f32 suffocate;
	// this determines how fast the item wears out from use
	u8 durability;
	// for medallions, how much the affect durability of other items
	f32 effect;

	ClothesItemFeatures():
		content(CONTENT_IGNORE),
		texture("unknown_item.png"),
		overlay_texture(""),
		description(L""),
		type(CT_NONE),
		armour(0.),
		warmth(0.),
		vacuum(0.),
		suffocate(0.),
		durability(5),
		effect(1.)
	{}
};

extern std::map<content_t,struct ClothesItemFeatures> g_content_clothesitem_features;
// For getting the default properties, set id=CONTENT_IGNORE
void content_clothesitem_init();
ClothesItemFeatures & content_clothesitem_features(content_t i);

// fur was the first clothing added, they keep their original ids but are
// actually defined below along with the other (newer) fur item. also
// kept here as a reminder of their ids in case someone tries to reuse them
//#define CONTENT_CLOTHESITEM_FUR_PANTS (CONTENT_CLOTHESITEM_MASK | 0x01)
//#define CONTENT_CLOTHESITEM_FUR_JACKET (CONTENT_CLOTHESITEM_MASK | 0x02)
//#define CONTENT_CLOTHESITEM_FUR_HAT (CONTENT_CLOTHESITEM_MASK | 0x03)
//#define CONTENT_CLOTHESITEM_FUR_BOOTS (CONTENT_CLOTHESITEM_MASK | 0x04)
// space suit
#define CONTENT_CLOTHESITEM_SPACESUIT_PANTS (CONTENT_CLOTHESITEM_MASK | 0x05)
#define CONTENT_CLOTHESITEM_SPACESUIT_SHIRT (CONTENT_CLOTHESITEM_MASK | 0x06)
#define CONTENT_CLOTHESITEM_SPACESUIT_HELMET (CONTENT_CLOTHESITEM_MASK | 0x07)
#define CONTENT_CLOTHESITEM_SPACESUIT_BOOTS (CONTENT_CLOTHESITEM_MASK | 0x08)
// cotton t-shirts
#define CONTENT_CLOTHESITEM_COTTON_TSHIRT (CONTENT_CLOTHESITEM_MASK | 0x09)
#define CONTENT_CLOTHESITEM_COTTON_TSHIRT_BLUE (CONTENT_CLOTHESITEM_MASK | 0x0A)
#define CONTENT_CLOTHESITEM_COTTON_TSHIRT_GREEN (CONTENT_CLOTHESITEM_MASK | 0x0B)
#define CONTENT_CLOTHESITEM_COTTON_TSHIRT_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x0C)
#define CONTENT_CLOTHESITEM_COTTON_TSHIRT_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x0D)
#define CONTENT_CLOTHESITEM_COTTON_TSHIRT_RED (CONTENT_CLOTHESITEM_MASK | 0x0E)
#define CONTENT_CLOTHESITEM_COTTON_TSHIRT_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x0F)
#define CONTENT_CLOTHESITEM_COTTON_TSHIRT_BLACK (CONTENT_CLOTHESITEM_MASK | 0x10)
// cotton shirts
#define CONTENT_CLOTHESITEM_COTTON_SHIRT (CONTENT_CLOTHESITEM_MASK | 0x11)
#define CONTENT_CLOTHESITEM_COTTON_SHIRT_BLUE (CONTENT_CLOTHESITEM_MASK | 0x12)
#define CONTENT_CLOTHESITEM_COTTON_SHIRT_GREEN (CONTENT_CLOTHESITEM_MASK | 0x13)
#define CONTENT_CLOTHESITEM_COTTON_SHIRT_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x14)
#define CONTENT_CLOTHESITEM_COTTON_SHIRT_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x15)
#define CONTENT_CLOTHESITEM_COTTON_SHIRT_RED (CONTENT_CLOTHESITEM_MASK | 0x16)
#define CONTENT_CLOTHESITEM_COTTON_SHIRT_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x17)
#define CONTENT_CLOTHESITEM_COTTON_SHIRT_BLACK (CONTENT_CLOTHESITEM_MASK | 0x18)
// free 0x19-0x20
// cotton shorts
#define CONTENT_CLOTHESITEM_COTTON_SHORTS (CONTENT_CLOTHESITEM_MASK | 0x21)
#define CONTENT_CLOTHESITEM_COTTON_SHORTS_BLUE (CONTENT_CLOTHESITEM_MASK | 0x22)
#define CONTENT_CLOTHESITEM_COTTON_SHORTS_GREEN (CONTENT_CLOTHESITEM_MASK | 0x23)
#define CONTENT_CLOTHESITEM_COTTON_SHORTS_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x24)
#define CONTENT_CLOTHESITEM_COTTON_SHORTS_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x25)
#define CONTENT_CLOTHESITEM_COTTON_SHORTS_RED (CONTENT_CLOTHESITEM_MASK | 0x26)
#define CONTENT_CLOTHESITEM_COTTON_SHORTS_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x27)
#define CONTENT_CLOTHESITEM_COTTON_SHORTS_BLACK (CONTENT_CLOTHESITEM_MASK | 0x28)
// cotton hats
#define CONTENT_CLOTHESITEM_COTTON_HAT (CONTENT_CLOTHESITEM_MASK | 0x29)
#define CONTENT_CLOTHESITEM_COTTON_HAT_BLUE (CONTENT_CLOTHESITEM_MASK | 0x2A)
#define CONTENT_CLOTHESITEM_COTTON_HAT_GREEN (CONTENT_CLOTHESITEM_MASK | 0x2B)
#define CONTENT_CLOTHESITEM_COTTON_HAT_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x2C)
#define CONTENT_CLOTHESITEM_COTTON_HAT_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x2D)
#define CONTENT_CLOTHESITEM_COTTON_HAT_RED (CONTENT_CLOTHESITEM_MASK | 0x2E)
#define CONTENT_CLOTHESITEM_COTTON_HAT_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x2F)
#define CONTENT_CLOTHESITEM_COTTON_HAT_BLACK (CONTENT_CLOTHESITEM_MASK | 0x30)
// cotton ties
#define CONTENT_CLOTHESITEM_COTTON_TIE (CONTENT_CLOTHESITEM_MASK | 0x31)
#define CONTENT_CLOTHESITEM_COTTON_TIE_BLUE (CONTENT_CLOTHESITEM_MASK | 0x32)
#define CONTENT_CLOTHESITEM_COTTON_TIE_GREEN (CONTENT_CLOTHESITEM_MASK | 0x33)
#define CONTENT_CLOTHESITEM_COTTON_TIE_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x34)
#define CONTENT_CLOTHESITEM_COTTON_TIE_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x35)
#define CONTENT_CLOTHESITEM_COTTON_TIE_RED (CONTENT_CLOTHESITEM_MASK | 0x36)
#define CONTENT_CLOTHESITEM_COTTON_TIE_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x37)
#define CONTENT_CLOTHESITEM_COTTON_TIE_BLACK (CONTENT_CLOTHESITEM_MASK | 0x38)
// canvas shirt - jacket?
#define CONTENT_CLOTHESITEM_CANVAS_SHIRT (CONTENT_CLOTHESITEM_MASK | 0x39)
#define CONTENT_CLOTHESITEM_CANVAS_SHIRT_BLUE (CONTENT_CLOTHESITEM_MASK | 0x3A)
#define CONTENT_CLOTHESITEM_CANVAS_SHIRT_GREEN (CONTENT_CLOTHESITEM_MASK | 0x3B)
#define CONTENT_CLOTHESITEM_CANVAS_SHIRT_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x3C)
#define CONTENT_CLOTHESITEM_CANVAS_SHIRT_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x3D)
#define CONTENT_CLOTHESITEM_CANVAS_SHIRT_RED (CONTENT_CLOTHESITEM_MASK | 0x3E)
#define CONTENT_CLOTHESITEM_CANVAS_SHIRT_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x3F)
#define CONTENT_CLOTHESITEM_CANVAS_SHIRT_BLACK (CONTENT_CLOTHESITEM_MASK | 0x40)
// canvas pants / jeans
#define CONTENT_CLOTHESITEM_CANVAS_PANTS (CONTENT_CLOTHESITEM_MASK | 0x41)
#define CONTENT_CLOTHESITEM_CANVAS_PANTS_BLUE (CONTENT_CLOTHESITEM_MASK | 0x42)
#define CONTENT_CLOTHESITEM_CANVAS_PANTS_GREEN (CONTENT_CLOTHESITEM_MASK | 0x43)
#define CONTENT_CLOTHESITEM_CANVAS_PANTS_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x44)
#define CONTENT_CLOTHESITEM_CANVAS_PANTS_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x45)
#define CONTENT_CLOTHESITEM_CANVAS_PANTS_RED (CONTENT_CLOTHESITEM_MASK | 0x46)
#define CONTENT_CLOTHESITEM_CANVAS_PANTS_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x47)
#define CONTENT_CLOTHESITEM_CANVAS_PANTS_BLACK (CONTENT_CLOTHESITEM_MASK | 0x48)
// canvas shoes
#define CONTENT_CLOTHESITEM_CANVAS_SHOES (CONTENT_CLOTHESITEM_MASK | 0x49)
#define CONTENT_CLOTHESITEM_CANVAS_SHOES_BLUE (CONTENT_CLOTHESITEM_MASK | 0x4A)
#define CONTENT_CLOTHESITEM_CANVAS_SHOES_GREEN (CONTENT_CLOTHESITEM_MASK | 0x4B)
#define CONTENT_CLOTHESITEM_CANVAS_SHOES_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x4C)
#define CONTENT_CLOTHESITEM_CANVAS_SHOES_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x4D)
#define CONTENT_CLOTHESITEM_CANVAS_SHOES_RED (CONTENT_CLOTHESITEM_MASK | 0x4E)
#define CONTENT_CLOTHESITEM_CANVAS_SHOES_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x4F)
#define CONTENT_CLOTHESITEM_CANVAS_SHOES_BLACK (CONTENT_CLOTHESITEM_MASK | 0x50)
// canvas belt
#define CONTENT_CLOTHESITEM_CANVAS_BELT (CONTENT_CLOTHESITEM_MASK | 0x51)
#define CONTENT_CLOTHESITEM_CANVAS_BELT_BLUE (CONTENT_CLOTHESITEM_MASK | 0x52)
#define CONTENT_CLOTHESITEM_CANVAS_BELT_GREEN (CONTENT_CLOTHESITEM_MASK | 0x53)
#define CONTENT_CLOTHESITEM_CANVAS_BELT_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x54)
#define CONTENT_CLOTHESITEM_CANVAS_BELT_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x55)
#define CONTENT_CLOTHESITEM_CANVAS_BELT_RED (CONTENT_CLOTHESITEM_MASK | 0x56)
#define CONTENT_CLOTHESITEM_CANVAS_BELT_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x57)
#define CONTENT_CLOTHESITEM_CANVAS_BELT_BLACK (CONTENT_CLOTHESITEM_MASK | 0x58)
// leather jackets
#define CONTENT_CLOTHESITEM_LEATHER_JACKET (CONTENT_CLOTHESITEM_MASK | 0x59)
#define CONTENT_CLOTHESITEM_LEATHER_JACKET_WHITE (CONTENT_CLOTHESITEM_MASK | 0x5A)
#define CONTENT_CLOTHESITEM_LEATHER_JACKET_BLUE (CONTENT_CLOTHESITEM_MASK | 0x5B)
#define CONTENT_CLOTHESITEM_LEATHER_JACKET_GREEN (CONTENT_CLOTHESITEM_MASK | 0x5C)
#define CONTENT_CLOTHESITEM_LEATHER_JACKET_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x5D)
#define CONTENT_CLOTHESITEM_LEATHER_JACKET_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x5E)
#define CONTENT_CLOTHESITEM_LEATHER_JACKET_RED (CONTENT_CLOTHESITEM_MASK | 0x5F)
#define CONTENT_CLOTHESITEM_LEATHER_JACKET_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x60)
#define CONTENT_CLOTHESITEM_LEATHER_JACKET_BLACK (CONTENT_CLOTHESITEM_MASK | 0x61)
// leather pants
#define CONTENT_CLOTHESITEM_LEATHER_PANTS (CONTENT_CLOTHESITEM_MASK | 0x62)
#define CONTENT_CLOTHESITEM_LEATHER_PANTS_WHITE (CONTENT_CLOTHESITEM_MASK | 0x63)
#define CONTENT_CLOTHESITEM_LEATHER_PANTS_BLUE (CONTENT_CLOTHESITEM_MASK | 0x64)
#define CONTENT_CLOTHESITEM_LEATHER_PANTS_GREEN (CONTENT_CLOTHESITEM_MASK | 0x65)
#define CONTENT_CLOTHESITEM_LEATHER_PANTS_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x66)
#define CONTENT_CLOTHESITEM_LEATHER_PANTS_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x67)
#define CONTENT_CLOTHESITEM_LEATHER_PANTS_RED (CONTENT_CLOTHESITEM_MASK | 0x68)
#define CONTENT_CLOTHESITEM_LEATHER_PANTS_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x69)
#define CONTENT_CLOTHESITEM_LEATHER_PANTS_BLACK (CONTENT_CLOTHESITEM_MASK | 0x6A)
// leather hats
#define CONTENT_CLOTHESITEM_LEATHER_HAT (CONTENT_CLOTHESITEM_MASK | 0x6B)
#define CONTENT_CLOTHESITEM_LEATHER_HAT_WHITE (CONTENT_CLOTHESITEM_MASK | 0x6C)
#define CONTENT_CLOTHESITEM_LEATHER_HAT_BLUE (CONTENT_CLOTHESITEM_MASK | 0x6D)
#define CONTENT_CLOTHESITEM_LEATHER_HAT_GREEN (CONTENT_CLOTHESITEM_MASK | 0x6E)
#define CONTENT_CLOTHESITEM_LEATHER_HAT_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x6F)
#define CONTENT_CLOTHESITEM_LEATHER_HAT_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x70)
#define CONTENT_CLOTHESITEM_LEATHER_HAT_RED (CONTENT_CLOTHESITEM_MASK | 0x71)
#define CONTENT_CLOTHESITEM_LEATHER_HAT_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x72)
#define CONTENT_CLOTHESITEM_LEATHER_HAT_BLACK (CONTENT_CLOTHESITEM_MASK | 0x73)
// leather helmets
#define CONTENT_CLOTHESITEM_LEATHER_HELMET (CONTENT_CLOTHESITEM_MASK | 0x74)
#define CONTENT_CLOTHESITEM_LEATHER_HELMET_WHITE (CONTENT_CLOTHESITEM_MASK | 0x75)
#define CONTENT_CLOTHESITEM_LEATHER_HELMET_BLUE (CONTENT_CLOTHESITEM_MASK | 0x76)
#define CONTENT_CLOTHESITEM_LEATHER_HELMET_GREEN (CONTENT_CLOTHESITEM_MASK | 0x77)
#define CONTENT_CLOTHESITEM_LEATHER_HELMET_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x78)
#define CONTENT_CLOTHESITEM_LEATHER_HELMET_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x79)
#define CONTENT_CLOTHESITEM_LEATHER_HELMET_RED (CONTENT_CLOTHESITEM_MASK | 0x7A)
#define CONTENT_CLOTHESITEM_LEATHER_HELMET_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x7B)
#define CONTENT_CLOTHESITEM_LEATHER_HELMET_BLACK (CONTENT_CLOTHESITEM_MASK | 0x7C)
// leather shoes
#define CONTENT_CLOTHESITEM_LEATHER_SHOES (CONTENT_CLOTHESITEM_MASK | 0x7D)
#define CONTENT_CLOTHESITEM_LEATHER_SHOES_WHITE (CONTENT_CLOTHESITEM_MASK | 0x7E)
#define CONTENT_CLOTHESITEM_LEATHER_SHOES_BLUE (CONTENT_CLOTHESITEM_MASK | 0x7F)
#define CONTENT_CLOTHESITEM_LEATHER_SHOES_GREEN (CONTENT_CLOTHESITEM_MASK | 0x80)
#define CONTENT_CLOTHESITEM_LEATHER_SHOES_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x81)
#define CONTENT_CLOTHESITEM_LEATHER_SHOES_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x82)
#define CONTENT_CLOTHESITEM_LEATHER_SHOES_RED (CONTENT_CLOTHESITEM_MASK | 0x83)
#define CONTENT_CLOTHESITEM_LEATHER_SHOES_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x84)
#define CONTENT_CLOTHESITEM_LEATHER_SHOES_BLACK (CONTENT_CLOTHESITEM_MASK | 0x85)
// leather boots
#define CONTENT_CLOTHESITEM_LEATHER_BOOTS (CONTENT_CLOTHESITEM_MASK | 0x86)
#define CONTENT_CLOTHESITEM_LEATHER_BOOTS_WHITE (CONTENT_CLOTHESITEM_MASK | 0x87)
#define CONTENT_CLOTHESITEM_LEATHER_BOOTS_BLUE (CONTENT_CLOTHESITEM_MASK | 0x88)
#define CONTENT_CLOTHESITEM_LEATHER_BOOTS_GREEN (CONTENT_CLOTHESITEM_MASK | 0x89)
#define CONTENT_CLOTHESITEM_LEATHER_BOOTS_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x8A)
#define CONTENT_CLOTHESITEM_LEATHER_BOOTS_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x8B)
#define CONTENT_CLOTHESITEM_LEATHER_BOOTS_RED (CONTENT_CLOTHESITEM_MASK | 0x8C)
#define CONTENT_CLOTHESITEM_LEATHER_BOOTS_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x8D)
#define CONTENT_CLOTHESITEM_LEATHER_BOOTS_BLACK (CONTENT_CLOTHESITEM_MASK | 0x8E)
// leather belt
#define CONTENT_CLOTHESITEM_LEATHER_BELT (CONTENT_CLOTHESITEM_MASK | 0x8F)
#define CONTENT_CLOTHESITEM_LEATHER_BELT_WHITE (CONTENT_CLOTHESITEM_MASK | 0x90)
#define CONTENT_CLOTHESITEM_LEATHER_BELT_BLUE (CONTENT_CLOTHESITEM_MASK | 0x91)
#define CONTENT_CLOTHESITEM_LEATHER_BELT_GREEN (CONTENT_CLOTHESITEM_MASK | 0x92)
#define CONTENT_CLOTHESITEM_LEATHER_BELT_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x93)
#define CONTENT_CLOTHESITEM_LEATHER_BELT_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x94)
#define CONTENT_CLOTHESITEM_LEATHER_BELT_RED (CONTENT_CLOTHESITEM_MASK | 0x95)
#define CONTENT_CLOTHESITEM_LEATHER_BELT_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x96)
#define CONTENT_CLOTHESITEM_LEATHER_BELT_BLACK (CONTENT_CLOTHESITEM_MASK | 0x97)
// fur shirts
#define CONTENT_CLOTHESITEM_FUR_JACKET (CONTENT_CLOTHESITEM_MASK | 0x02)
#define CONTENT_CLOTHESITEM_FUR_JACKET_WHITE (CONTENT_CLOTHESITEM_MASK | 0x98)
#define CONTENT_CLOTHESITEM_FUR_JACKET_BLUE (CONTENT_CLOTHESITEM_MASK | 0x99)
#define CONTENT_CLOTHESITEM_FUR_JACKET_GREEN (CONTENT_CLOTHESITEM_MASK | 0x9A)
#define CONTENT_CLOTHESITEM_FUR_JACKET_ORANGE (CONTENT_CLOTHESITEM_MASK | 0x9B)
#define CONTENT_CLOTHESITEM_FUR_JACKET_PURPLE (CONTENT_CLOTHESITEM_MASK | 0x9C)
#define CONTENT_CLOTHESITEM_FUR_JACKET_RED (CONTENT_CLOTHESITEM_MASK | 0x9D)
#define CONTENT_CLOTHESITEM_FUR_JACKET_YELLOW (CONTENT_CLOTHESITEM_MASK | 0x9E)
#define CONTENT_CLOTHESITEM_FUR_JACKET_BLACK (CONTENT_CLOTHESITEM_MASK | 0x9F)
// fur pants
#define CONTENT_CLOTHESITEM_FUR_PANTS (CONTENT_CLOTHESITEM_MASK | 0x01)
#define CONTENT_CLOTHESITEM_FUR_PANTS_WHITE (CONTENT_CLOTHESITEM_MASK | 0xA0)
#define CONTENT_CLOTHESITEM_FUR_PANTS_BLUE (CONTENT_CLOTHESITEM_MASK | 0xA1)
#define CONTENT_CLOTHESITEM_FUR_PANTS_GREEN (CONTENT_CLOTHESITEM_MASK | 0xA2)
#define CONTENT_CLOTHESITEM_FUR_PANTS_ORANGE (CONTENT_CLOTHESITEM_MASK | 0xA3)
#define CONTENT_CLOTHESITEM_FUR_PANTS_PURPLE (CONTENT_CLOTHESITEM_MASK | 0xA4)
#define CONTENT_CLOTHESITEM_FUR_PANTS_RED (CONTENT_CLOTHESITEM_MASK | 0xA5)
#define CONTENT_CLOTHESITEM_FUR_PANTS_YELLOW (CONTENT_CLOTHESITEM_MASK | 0xA6)
#define CONTENT_CLOTHESITEM_FUR_PANTS_BLACK (CONTENT_CLOTHESITEM_MASK | 0xA7)
// fur hats
#define CONTENT_CLOTHESITEM_FUR_HAT (CONTENT_CLOTHESITEM_MASK | 0x03)
#define CONTENT_CLOTHESITEM_FUR_HAT_WHITE (CONTENT_CLOTHESITEM_MASK | 0xA8)
#define CONTENT_CLOTHESITEM_FUR_HAT_BLUE (CONTENT_CLOTHESITEM_MASK | 0xA9)
#define CONTENT_CLOTHESITEM_FUR_HAT_GREEN (CONTENT_CLOTHESITEM_MASK | 0xAA)
#define CONTENT_CLOTHESITEM_FUR_HAT_ORANGE (CONTENT_CLOTHESITEM_MASK | 0xAB)
#define CONTENT_CLOTHESITEM_FUR_HAT_PURPLE (CONTENT_CLOTHESITEM_MASK | 0xAC)
#define CONTENT_CLOTHESITEM_FUR_HAT_RED (CONTENT_CLOTHESITEM_MASK | 0xAD)
#define CONTENT_CLOTHESITEM_FUR_HAT_YELLOW (CONTENT_CLOTHESITEM_MASK | 0xAE)
#define CONTENT_CLOTHESITEM_FUR_HAT_BLACK (CONTENT_CLOTHESITEM_MASK | 0xAF)
// fur shoes
#define CONTENT_CLOTHESITEM_FUR_SHOES (CONTENT_CLOTHESITEM_MASK | 0xB0)
#define CONTENT_CLOTHESITEM_FUR_SHOES_WHITE (CONTENT_CLOTHESITEM_MASK | 0xB1)
#define CONTENT_CLOTHESITEM_FUR_SHOES_BLUE (CONTENT_CLOTHESITEM_MASK | 0xB2)
#define CONTENT_CLOTHESITEM_FUR_SHOES_GREEN (CONTENT_CLOTHESITEM_MASK | 0xB3)
#define CONTENT_CLOTHESITEM_FUR_SHOES_ORANGE (CONTENT_CLOTHESITEM_MASK | 0xB4)
#define CONTENT_CLOTHESITEM_FUR_SHOES_PURPLE (CONTENT_CLOTHESITEM_MASK | 0xB5)
#define CONTENT_CLOTHESITEM_FUR_SHOES_RED (CONTENT_CLOTHESITEM_MASK | 0xB6)
#define CONTENT_CLOTHESITEM_FUR_SHOES_YELLOW (CONTENT_CLOTHESITEM_MASK | 0xB7)
#define CONTENT_CLOTHESITEM_FUR_SHOES_BLACK (CONTENT_CLOTHESITEM_MASK | 0xB8)
// fur boots
#define CONTENT_CLOTHESITEM_FUR_BOOTS (CONTENT_CLOTHESITEM_MASK | 0x04)
#define CONTENT_CLOTHESITEM_FUR_BOOTS_WHITE (CONTENT_CLOTHESITEM_MASK | 0xB9)
#define CONTENT_CLOTHESITEM_FUR_BOOTS_BLUE (CONTENT_CLOTHESITEM_MASK | 0xBA)
#define CONTENT_CLOTHESITEM_FUR_BOOTS_GREEN (CONTENT_CLOTHESITEM_MASK | 0xBB)
#define CONTENT_CLOTHESITEM_FUR_BOOTS_ORANGE (CONTENT_CLOTHESITEM_MASK | 0xBC)
#define CONTENT_CLOTHESITEM_FUR_BOOTS_PURPLE (CONTENT_CLOTHESITEM_MASK | 0xBD)
#define CONTENT_CLOTHESITEM_FUR_BOOTS_RED (CONTENT_CLOTHESITEM_MASK | 0xBE)
#define CONTENT_CLOTHESITEM_FUR_BOOTS_YELLOW (CONTENT_CLOTHESITEM_MASK | 0xBF)
#define CONTENT_CLOTHESITEM_FUR_BOOTS_BLACK (CONTENT_CLOTHESITEM_MASK | 0xC0)
// necklaces / medallions
#define CONTENT_CLOTHESITEM_LEATHER_NECKLACE (CONTENT_CLOTHESITEM_MASK | 0xC1)
#define CONTENT_CLOTHESITEM_GOLD_MEDALLION (CONTENT_CLOTHESITEM_MASK | 0xC2)
#define CONTENT_CLOTHESITEM_COPPER_MEDALLION (CONTENT_CLOTHESITEM_MASK | 0xC3)
#define CONTENT_CLOTHESITEM_SILVER_MEDALLION (CONTENT_CLOTHESITEM_MASK | 0xC4)
#define CONTENT_CLOTHESITEM_TIN_MEDALLION (CONTENT_CLOTHESITEM_MASK | 0xC5)
#define CONTENT_CLOTHESITEM_IRON_MEDALLION (CONTENT_CLOTHESITEM_MASK | 0xC6)
#define CONTENT_CLOTHESITEM_QUARTZ_MEDALLION (CONTENT_CLOTHESITEM_MASK | 0xC7)
// armour
#define CONTENT_CLOTHESITEM_STEEL_HELMET (CONTENT_CLOTHESITEM_MASK | 0xC8)
#define CONTENT_CLOTHESITEM_STEEL_SHIRT (CONTENT_CLOTHESITEM_MASK | 0xC9)
#define CONTENT_CLOTHESITEM_STEEL_PANTS (CONTENT_CLOTHESITEM_MASK | 0xCA)
#define CONTENT_CLOTHESITEM_STEEL_BOOTS (CONTENT_CLOTHESITEM_MASK | 0xCB)
#define CONTENT_CLOTHESITEM_COPPER_HELMET (CONTENT_CLOTHESITEM_MASK | 0xCC)
#define CONTENT_CLOTHESITEM_COPPER_SHIRT (CONTENT_CLOTHESITEM_MASK | 0xCD)
#define CONTENT_CLOTHESITEM_COPPER_PANTS (CONTENT_CLOTHESITEM_MASK | 0xCE)
#define CONTENT_CLOTHESITEM_COPPER_BOOTS (CONTENT_CLOTHESITEM_MASK | 0xCF)

#endif
