#include <stdint.h>
#include <allegro5/allegro.h>
#include "Tile.hpp"

int Tile::compareColor(const ALLEGRO_COLOR& lhs, const ALLEGRO_COLOR& rhs) const 
{
	uint8_t r_lhs = 0;
	uint8_t g_lhs = 0;
	uint8_t b_lhs = 0;
	uint8_t r_rhs = 0;
	uint8_t g_rhs = 0;
	uint8_t b_rhs = 0;
	al_unmap_rgb(lhs, &r_lhs, &g_lhs, &b_lhs);
	al_unmap_rgb(rhs, &r_rhs, &g_rhs, &b_rhs);

	if( r_lhs < r_rhs )
	{
		return -1;
	}
	else if ( r_lhs == r_rhs)
	{ 
		if ( g_lhs < g_rhs )
		{
			return -1;
		}
		else if( g_lhs == g_rhs )
		{
			if (b_lhs < b_rhs)
			{
				return -1;
			}
			else if (b_lhs == b_rhs)
			{
				return 0;
			}
		}
	}
	return 1;
}

bool Tile::operator<(Tile const& rhs) const
{
	int result;
	if (index < rhs.index)
	{
		return true;
	}
	else if ( index == rhs.index)
	{
		result = compareColor(fore, rhs.fore); 
		if( result == -1 )
		{
			return true;
		}
		else if( result == 0 )
		{
			result = compareColor(back, rhs.back);
			if (result == -1)
			{
				return true;
			}
		}
	}
	return false;
}