/************************************************************************
* Minetest-c55
* Copyright (C) 2010-2011 celeron55, Perttu Ahola <celeron55@gmail.com>
*
* content_sao.h
* voxelands - 3d voxel world sandbox game
* Copyright (C) Lisa 'darkrose' Milne 2013-2014 <lisa@ltmnet.com>
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

#ifndef CONTENT_SAO_HEADER
#define CONTENT_SAO_HEADER

#include "serverobject.h"
#include "mapnode.h"
#include "content_object.h"
#include "content_mob.h"

class MobSAO : public ServerActiveObject
{
public:
	MobSAO(ServerEnvironment *env, u16 id, v3f pos, content_t type);
	MobSAO(ServerEnvironment *env, u16 id, v3f pos, v3f speed, content_t type);
	virtual ~MobSAO();
	u8 getType() const
		{return ACTIVEOBJECT_TYPE_MOB;}
	static ServerActiveObject* create(ServerEnvironment *env, u16 id, v3f pos,
			const std::string &data);
	std::string getStaticData();
	std::string getClientInitializationData();
	void step(float dtime, bool send_recommended);
	InventoryItem* createPickedUpItem(content_t punch_item);
	u16 punch(content_t punch_item, v3f dir, const std::string &playername);
	bool rightClick(Player *player);
	u8 level();
	void doDamage(u16 d);
	content_t getContent() {return m_content;}
private:
	void sendPosition();

	MobMotion getMotion()
	{
		MobMotion m = content_mob_features(m_content).angry_motion;
		if (m_angry && m != MM_STATIC)
			return m;
		return content_mob_features(m_content).motion;
	}

	void stepMotionWander(float dtime);
	void stepMotionSeeker(float dtime, float offset);
	void stepMotionFlee(float dtime);
	void stepMotionSentry(float dtime);
	void stepMotionThrown(float dtime);
	void stepMotionConstant(float dtime);

	bool checkFreePosition(v3s16 p0);
	bool checkWalkablePosition(v3s16 p0);
	bool checkFreeAndWalkablePosition(v3s16 p0);
	void explodeSquare(v3s16 p0, v3s16 size);

	content_t m_content;
	v3f m_speed;
	v3f m_last_sent_position;
	v3f m_oldpos;
	v3f m_initial_pos;
	float m_yaw;
	bool m_falling;
	bool m_next_pos_exists;
	v3s16 m_next_pos_i;

	u8 m_hp;
	bool m_angry;
	u16 m_special_count;
	u16 m_tamed_chance;

	float m_disturb_timer;
	std::string m_disturbing_player;
	float m_random_disturb_timer;

	bool m_walk_around;
	float m_walk_around_timer;
	float m_shoot_reload_timer;
	bool m_shooting;
	float m_shooting_timer;
	float m_shoot_y;
	float m_last_sound;
};

#endif

