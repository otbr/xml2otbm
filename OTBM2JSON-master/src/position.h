////////////////////////////////////////////////////////////////////////////////
// Survival Server - An MMPORPG (Massive MultiPlayer Online Role Playing Game)//
////////////////////////////////////////////////////////////////////////////////
// Developed by Dark-bart.                                                    //
////////////////////////////////////////////////////////////////////////////////

#ifndef __SURVIVALSERV_POS_H
#define __SURVIVALSERV_POS_H

#include <stdlib.h>
#include <cmath>
#include <iostream>


enum Direction { NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3 };

class Position {
public:
  int x,y,z;


	bool operator==(const Position p)  const {
		if(p.x==x && p.y==y && p.z ==z)
			return true;
		else
			return false;
	}

	bool operator!=(const Position p)  const {
		if(p.x==x && p.y==y && p.z ==z)
			return false;
		else
			return true;
	}

	Position operator-(const Position p1){
		return Position(x-p1.x, y-p1.y,z-p1.z);
	}

	void dist(){
		x=abs(x);
		y=abs(y);
		z=abs(z);
	}

  Position() : x(223), y(223), z(7) { };

    Position(int _x, int _y, int _z)
        : x(_x), y(_y), z(_z) {};

};

std::ostream& operator<<(std::ostream&, const Position&);
std::ostream& operator<<(std::ostream&, const Direction&);

#endif
