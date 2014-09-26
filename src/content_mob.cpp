/************************************************************************
* Minetest-c55
* Copyright (C) 2010 celeron55, Perttu Ahola <celeron55@gmail.com>
*
* content_mob.cpp
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

#include "serverobject.h"
#include "content_sao.h"
#include "content_mob.h"
#include "main.h"
#include "settings.h"
#include "environment.h"
#include "map.h"

std::map<content_t,struct MobFeatures> g_content_mob_features;

MobFeatures & content_mob_features(content_t i)
{
	if ((i&CONTENT_MOB_MASK) != CONTENT_MOB_MASK)
		return g_content_mob_features[CONTENT_IGNORE];

	std::map<content_t,struct MobFeatures>::iterator it = g_content_mob_features.find(i);
	if (it == g_content_mob_features.end())
		return g_content_mob_features[CONTENT_IGNORE];
	return it->second;
}

#ifndef SERVER
void MobFeatures::setTexture(std::string name)
{
	if (g_texturesource)
		texture = g_texturesource->getTextureRaw(name);
}
void MobFeatures::setBoxTexture(u16 i, std::string name, u8 alpha)
{
	if (g_texturesource)
		tiles[i].texture = g_texturesource->getTexture(name);

	if (alpha != 255) {
		tiles[i].alpha = alpha;
		tiles[i].material_type = MATERIAL_ALPHA_VERTEX;
	}
}
#endif
void MobFeatures::getAnimationFrames(MobAnimation type, int *start, int *end)
{
	*start = 0;
	*end = 0;
	switch (type) {
	case MA_STAND:
		*start = animations[MA_STAND_START];
		*end = animations[MA_STAND_END];
		break;
	case MA_MOVE:
		*start = animations[MA_MOVE_START];
		*end = animations[MA_MOVE_END];
		break;
	case MA_ATTACK:
		*start = animations[MA_ATTACK_START];
		*end = animations[MA_ATTACK_END];
		break;
	default:;
	}
	if (type != MA_STAND && start == end) {
		*start = animations[MA_STAND_START];
		*end = animations[MA_STAND_END];
	}
}
void MobFeatures::setAnimationFrames(MobAnimation type, int start, int end)
{
	switch (type) {
	case MA_STAND:
		animations[MA_STAND_START] = start;
		animations[MA_STAND_END] = end;
		break;
	case MA_MOVE:
		animations[MA_MOVE_START] = start;
		animations[MA_MOVE_END] = end;
		break;
	case MA_ATTACK:
		animations[MA_ATTACK_START] = start;
		animations[MA_ATTACK_END] = end;
		break;
	default:;
	}
}

#define PP(x) "("<<(x).X<<","<<(x).Y<<","<<(x).Z<<")"

bool content_mob_spawn(ServerEnvironment *env, v3s16 pos)
{
	assert(env);
	Map *map = &env->getMap();

	std::vector<content_t> can;
	MapNode n = map->getNodeNoEx(pos);
	MapNode a1 = map->getNodeNoEx(pos+v3s16(0,1,0));
	MapNode a2 = map->getNodeNoEx(pos+v3s16(0,2,0));
	content_t c0 = n.getContent();
	content_t c1 = a1.getContent();
	content_t c2 = a2.getContent();
	u8 light = n.getLightBlend(env->getDayNightRatio());
	u8 level = mobLevelI(g_settings->get("max_mob_level"));

	if (c0 == CONTENT_IGNORE || c1 == CONTENT_IGNORE || c2 == CONTENT_IGNORE)
		return false;

	for (std::map<content_t,struct MobFeatures>::iterator i = g_content_mob_features.begin(); i != g_content_mob_features.end(); i++) {
		MobFeatures m = i->second;
		if (m.spawn_in == CONTENT_IGNORE && m.spawn_on == CONTENT_IGNORE)
			continue;
		if (m.spawn_in != CONTENT_IGNORE) {
			if (m.spawn_in != c1)
				continue;
			if (m.spawn_in != c2)
				continue;
		}
		if (m.spawn_on != CONTENT_IGNORE) {
			if (m.spawn_on != c0)
				continue;
		}
		if (m.spawn_min_light > light)
			continue;
		if (m.spawn_max_light < light)
			continue;
		if (m.level > level)
			continue;
		can.push_back(i->first);
	}

	if (can.size() == 0)
		return false;

	MobFeatures m;
	u32 index = 0;

	if (can.size() > 1)
		index = myrand_range(0,can.size()-1);

	m = g_content_mob_features[can[index]];

	if (m.content == CONTENT_IGNORE)
		return false;

	v3f p = intToFloat(pos+v3s16(0,1,0), BS);
	actionstream<<"A mob of type "<<m.content<<" spawns at "<<PP(floatToInt(p,BS))<<std::endl;
	ServerActiveObject *obj = new MobSAO(env, 0, p, m.content);
	u16 id = env->addActiveObject(obj);
	if (id)
		return true;
	actionstream<<"A mob of type "<<m.content<<" didn't spawn at "<<PP(floatToInt(p,BS))<<std::endl;

	return false;
}

void content_mob_init()
{
	g_content_mob_features.clear();

	content_t i;
	MobFeatures *f = NULL;

	i = CONTENT_MOB_RAT;
	f = &g_content_mob_features[i];
	f->content = i;
	f->level = MOB_PASSIVE;
	f->model = "rat.x";
	f->setTexture("mob_rat.png");
	f->setAnimationFrames(MA_STAND,0,79);
	f->punch_action = MPA_PICKUP;
	f->motion = MM_WANDER;
	f->spawn_on = CONTENT_GRASS;
	f->spawn_in = CONTENT_AIR;
	f->setCollisionBox(aabb3f(-BS/3.,0.0,-BS/3., BS/3.,BS/2.,BS/3.));

	i = CONTENT_MOB_FIREFLY;
	f = &g_content_mob_features[i];
	//f->content = i;
	f->level = MOB_PASSIVE;
	f->setTexture("mob_firefly.png");
	f->punch_action = MPA_PICKUP;
	f->motion = MM_WANDER;
	f->glow_light = LIGHT_MAX-1;
	f->spawn_on = CONTENT_JUNGLETREE;
	f->spawn_in = CONTENT_AIR;
	f->setCollisionBox(aabb3f(-BS/3.,0.0,-BS/3., BS/3.,BS/2.,BS/3.));

	i = CONTENT_MOB_OERKKI;
	f = &g_content_mob_features[i];
	//f->content = i;
	f->level = MOB_AGGRESSIVE;
	f->model = "oerkki.x";
	f->setTexture("mob_oerkki.png");
	f->setAnimationFrames(MA_STAND,24,36);
	f->setAnimationFrames(MA_ATTACK,37,49);
	f->punch_action = MPA_HARM;
	f->motion = MM_SEEKER;
	f->setCollisionBox(aabb3f(-BS/3.,0.0,-BS/3., BS/3.,BS*2.,BS/3.));

	i = CONTENT_MOB_DUNGEON_MASTER;
	f = &g_content_mob_features[i];
	//f->content = i;
	f->level = MOB_DESTRUCTIVE;
	f->model = "dungeon_master.x";
	f->setTexture("mob_dungeon_master.png");
	f->punch_action = MPA_HARM;
	f->motion = MM_SENTRY;
	f->attack_throw_object = CONTENT_MOB_FIREBALL;
	f->attack_glow_light = LIGHT_MAX-1;
	f->setCollisionBox(aabb3f(-0.4*BS,-0.4*BS,-0.4*BS, 0.4*BS,0.8*BS,0.4*BS));

	i = CONTENT_MOB_FIREBALL;
	f = &g_content_mob_features[i];
	//f->content = i;
	f->level = MOB_DESTRUCTIVE;
	f->setTexture("mob_fireball.png");
	f->punch_action = MPA_IGNORE;
	f->motion = MM_CONSTANT;
	f->motion_type = MMT_FLY;
	f->glow_light = LIGHT_MAX-1;
	f->setCollisionBox(aabb3f(-BS/3.,0.0,-BS/3., BS/3.,BS/2.,BS/3.));

	i = CONTENT_MOB_DEER;
	f = &g_content_mob_features[i];
	//f->content = i;
	i = CONTENT_MOB_SHEEP;
	f = &g_content_mob_features[i];
	//f->content = i;
	i = CONTENT_MOB_FISH;
	f = &g_content_mob_features[i];
	//f->content = i;
	i = CONTENT_MOB_SHARK;
	f = &g_content_mob_features[i];
	//f->content = i;
	i = CONTENT_MOB_WOLF;
	f = &g_content_mob_features[i];
	//f->content = i;

}
