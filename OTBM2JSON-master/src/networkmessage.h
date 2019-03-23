////////////////////////////////////////////////////////////////////////////////
// Survival Server - An MMPORPG (Massive MultiPlayer Online Role Playing Game)//
////////////////////////////////////////////////////////////////////////////////
// Developed by Dark-bart.                                                    //
////////////////////////////////////////////////////////////////////////////////

#ifndef __NETWORK_MESSAGE_H__
#define __NETWORK_MESSAGE_H__

#include "definitions.h"


#define NETWORKMESSAGE_MAXSIZE 16384


#define NM_ME_DRAW_BLOOD          0
#define NM_ME_LOOSE_ENERGY        1
#define NM_ME_PUFF                2
#define NM_ME_BLOCKHIT            3
#define NM_ME_EXPLOSION_AREA      4
#define NM_ME_EXPLOSION_DAMAGE    5
#define NM_ME_FIRE_AREA           6
#define NM_ME_YELLOW_RINGS        7
#define NM_ME_POISEN_RINGS        8
#define NM_ME_HIT_AREA            9
#define NM_ME_ENERGY_AREA        10
#define NM_ME_ENERGY_DAMAGE      11

#define NM_ME_MAGIC_ENERGIE      12
#define NM_ME_MAGIC_BLOOD        13
#define NM_ME_MAGIC_POISEN       14

#define NM_ME_HITBY_FIRE         15
#define NM_ME_POISEN             16
#define NM_ME_MORT_AREA          17
#define NM_ME_SOUND              18

#define NM_ANI_BOLT              1
#define NM_ANI_ARROW             2
#define NM_ANI_FIRE              3
#define NM_ANI_ENERGY            4
#define NM_ANI_POISONARROW       5
#define NM_ANI_BURSTARROW        6
#define NM_ANI_THROWINGSTAR      7
#define NM_ANI_THROWINGKNIFE     8
#define NM_ANI_SMALLSTONE        9
#define NM_ANI_SUDDENDEATH       10
#define NM_ANI_LARGEROCK         11
#define NM_ANI_SNOWBALL          12
#define NM_ANI_POWERBOLT         13

enum MessageClasses {
      MSG_SMALLINFO = 0x14,
	  MSG_INFO      = 0x13,
	  MSG_EVENT     = 0x11,
	  MSG_STATUS    = 0x12,
	  MSG_ADVANCE   = 0x10,
};

enum Icons {
      ICON_POISON = 1,
      ICON_BURN = 2, 
      ICON_ENERGY =  4, 
      ICON_DRUNK = 8, 
      ICON_MANASHIELD = 16, 
      ICON_PARALIZE = 32, 
      ICON_HASTE = 64, 
      ICON_SWORDS = 128
};

class Creature;
class Player;
class Item;
class Position;

class NetworkMessage
{
public:
  NetworkMessage();
  virtual ~NetworkMessage();


  // Resets the internal buffer to an empty message
  void Reset();

  // Socket functions
  bool ReadFromSocket(SOCKET socket);
  bool WriteToSocket(SOCKET socket);


  // Functions To Read Message
  unsigned char  GetByte();
  unsigned short GetU16();
  unsigned int   GetU32();
  std::string    GetString();
  std::string	 GetRaw();
  Position       GetPosition();

  //Skipt Bytes
  void SkipBytes(int count);

  // Functions to Message
  void AddByte(unsigned char  value);
  void AddU16 (unsigned short value);
  void AddU32 (unsigned int   value);
  void AddString(const std::string &value);
  void AddString(const char* value);
  void AddPosition(const Position &pos);
  
  // Other Functions
  void AddItem(const Item *item);
  void AddCreature(const Creature *creature, bool known, unsigned int remove);
  void AddTextMessage(MessageClasses mclass, const char* message);
  void AddAnimatedText(Position &pos, unsigned char color, std::string text);
  void AddMagicEffect(const Position &pos, unsigned char type);
  void AddLight(const Creature *player);
  void AddDistanceShoot(const Position &from, const Position &to, unsigned char type);
  void AddCreatureSpeak(const Creature *creature, unsigned char type, std::string text, unsigned short channelId);
  void AddCreatureHealth(Creature *creature);
  void AddPlayerInventoryItem(Player *player, int item);
  void AddPlayerSkills(Player *player);
  void AddPlayerStats(Player *player);

  int getMessageLength(){
      return m_MsgSize;
  }

protected:
  int m_MsgSize;
  int m_ReadPos;
  unsigned char m_MsgBuf[NETWORKMESSAGE_MAXSIZE];
};


#endif // #ifndef __NETWORK_MESSAGE_H__
