#include "main.h"
#include <cstdlib>

#include "content_mapnode.h"
#include "mapnode.h"
#include "content_nodemeta.h"
#include "content_craftitem.h"
#include "content_toolitem.h"
#include "content_craft.h"
#include "content_list.h"
#include "content_nodebox.h"
#ifndef SERVER
#include "tile.h"
#endif

void content_nodedef_knob(content_t nodeid, content_t source_node, ContentMaterialType material_type, const char* texture, char* desc)
{
	ContentFeatures *features = &content_features(nodeid);
	features->description = desc;
	features->setAllTextures(texture);
	features->param_type = CPT_LIGHT;
	features->param2_type = CPT_FACEDIR_WALLMOUNT;
	features->draw_type = CDT_NODEBOX;
	features->is_ground_content = false;
	features->light_propagates = true;
	features->dug_item = std::string("MaterialItem2 ")+itos(nodeid)+" 1";
	features->type = CMT_STONE;
	features->dig_time = 0.8;
	features->climbable = true;
	features->suffocation_per_second = 0;
	if (material_type == CMT_WOOD) {
		content_t recipe[9] = {
			CONTENT_IGNORE, CONTENT_IGNORE, CONTENT_IGNORE,
			source_node   , source_node   , CONTENT_IGNORE,
			CONTENT_IGNORE, CONTENT_IGNORE, CONTENT_IGNORE
		};

		crafting::setRecipe(recipe, nodeid, 2);
	}else{
		crafting::set1To4Recipe(source_node,nodeid);
	}
	content_nodebox_knob(features);
	features->setInventoryTextureNodeBox(nodeid,texture,texture,texture);
	content_list_add("craftguide",nodeid,1,0);
	content_list_add("creative",nodeid,1,0);
}

