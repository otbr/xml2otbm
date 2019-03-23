////////////////////////////////////////////////////////////////////////////////
// Survival Server - An MMPORPG (Massive MultiPlayer Online Role Playing Game)//
////////////////////////////////////////////////////////////////////////////////
// Developed by Dark-bart.                                                    //
////////////////////////////////////////////////////////////////////////////////

#include "definitions.h"

#include <string>
#include <iostream>

#include "tile.h"

#include "creature.h"
#include "item.h"


bool Tile::isBlockingProjectile()
{
	if(ground.isBlockingProjectile() == true)
    return true;
  
  ItemVector::const_iterator iit;
  for (iit = topItems.begin(); iit != topItems.end(); ++iit)
    if ((*iit)->isBlockingProjectile())
      return true;

  for (iit = downItems.begin(); iit != downItems.end(); ++iit)
    if ((*iit)->isBlockingProjectile())
      return true;


  return false;
}

bool Tile::isBlockingWalk()
{
  if(ground.isBlockingWalk() == true)
    return true;
  
  ItemVector::iterator iit;
  for (iit = topItems.begin(); iit != topItems.end(); iit++)
    if ((*iit)->isBlockingWalk())
      return true;

  for (iit = downItems.begin(); iit != downItems.end(); iit++)
    if ((*iit)->isBlockingWalk())
      return true;


  return false;
}

bool Tile::isBlocking()
{
  if(ground.isBlocking() == true)
    return true;
  
  ItemVector::iterator iit;
  for (iit = topItems.begin(); iit != topItems.end(); iit++)
    if ((*iit)->isBlocking())
      return true;

  for (iit = downItems.begin(); iit != downItems.end(); iit++)
    if ((*iit)->isBlocking())
      return true;


  return false;
}

int Tile::getCreatureStackPos(Creature *c)
{
  CreatureVector::iterator it;
  for (it = creatures.begin(); it != creatures.end(); it++)
  {
    if ((*it) == c)
      return (int) ((it - creatures.begin()) + 1 + topItems.size()) + (splash ? 1 : 0);
  }

  return 255;
}

int Tile::getThingStackPos(Thing *thing)
{
  int n = 0;

  if (splash)
  {
    if (thing == splash)
      return 1;
    n++;
  }
  
  ItemVector::iterator iit;
  for (iit = topItems.begin(); iit != topItems.end(); iit++)
  {
    n++;
    if ((*iit) == thing)
      return n;
  }

  CreatureVector::iterator cit;
  for (cit = creatures.begin(); cit != creatures.end(); cit++)
  {
    n++;
    if ((*cit) == thing)
      return n;
  }

  for (iit = downItems.begin(); iit != downItems.end(); iit++)
  {
    n++;
    if ((*iit) == thing)
      return n;
  }

  return 255;
}

Thing* Tile::getThingByStackPos(int pos)
{
  if (pos == 0)
    return &ground;

  pos--;

  if (splash)
  {
    if (pos == 0)
      return NULL;
    pos--;
  }

  if ((unsigned) pos < topItems.size())
    return topItems[pos];

  pos -= (uint32_t)topItems.size();

  if ((unsigned) pos < creatures.size())
    return creatures[pos];

  pos -= (uint32_t)creatures.size();

  if ((unsigned) pos < downItems.size())
    return downItems[pos];

  return NULL;
}

int Tile::getThingCount()
{
  return (uint32_t) 1 + (splash ? 1 : 0) + topItems.size() +	creatures.size() + downItems.size();
}

std::string Tile::getDescription()
{
    std::string ret="You dont know why, but you cant see anything!";
	return ret;
}


bool Tile::removeThing(Thing *thing)
{
	Creature* creature = dynamic_cast<Creature*>(thing);
	if (creature) {
    CreatureVector::iterator it;
    for (it = creatures.begin(); it != creatures.end(); it++)
      if (*it == thing)
      {
        creatures.erase(it);
        return true;
      }
  }
  else if (thing == splash)
  {
    splash = NULL;
    return true;
  }
  else
  {
    ItemVector::iterator it;
    Item *item = (Item*)thing;

    if (item->isAlwaysOnTop())
    {
      for (it = topItems.begin(); it != topItems.end(); it++)
        if (*it == item)
        {
          topItems.erase(it);
          return true;
        }
    }
    else
    {
      for (it = downItems.begin(); it != downItems.end(); it++)
        if (*it == item)
        {
          downItems.erase(it);
          return true;
        }
    }
  }

  return false;
}


void Tile::addThing(Thing *thing) {
	Creature* creature = dynamic_cast<Creature*>(thing);
	if (creature) {
    creatures.insert(creatures.begin(), creature);
  }
  else
  {
    Item *item = (Item*)thing;
    if (item->isGroundTile())
    {
      ground = *item;
    }
    else if (item->isAlwaysOnTop())
    {
      topItems.insert(topItems.begin(), item);
    }
    else
    {
      downItems.insert(downItems.begin(), item);
    }
  }
}

bool Tile::isPz()
{
  return pz;
}

bool Tile::isGateLvl()
{
  return gatelvl;
}

bool Tile::isHouseDoor()
{
  return housedoor;
}

bool Tile::isTele()
{
  return tele;
}

bool Tile::isUseTele()
{
  return usetele;
}

bool Tile::isRopeTele()
{
  return ropetele;
}

void Tile::setPz()
{
  pz = true;
}

void Tile::setGateLvl()
{
  gatelvl = true;
}

void Tile::setHouseDoor()
{
  housedoor = true;
}

void Tile::setTele()
{
  tele = true;
}

void Tile::setUseTele()
{
  usetele = true;
}

void Tile::setRopeTele()
{
  ropetele = true;
}
