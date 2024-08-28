#ifndef EQEMU_LUA_MOB_H
#define EQEMU_LUA_MOB_H
#ifdef LUA_EQEMU

#include "lua_entity.h"

class Mob;
struct Lua_HateList;
class Lua_Item;
class Lua_ItemInst;

namespace luabind {
	struct scope;
	namespace adl {
		class object;
	}
}

luabind::scope lua_register_mob();
luabind::scope lua_register_special_abilities();

class Lua_Mob : public Lua_Entity
{
	typedef Mob NativeType;
public:
	Lua_Mob() { SetLuaPtrData(nullptr); }
	Lua_Mob(Mob *d) { SetLuaPtrData(reinterpret_cast<Entity*>(d)); }
	virtual ~Lua_Mob() { }

	operator Mob*() {
		return reinterpret_cast<Mob*>(GetLuaPtrData());
	}

	const char *GetName();
	void Depop();
	void Depop(bool start_spawn_timer);
	bool BehindMob();
	bool BehindMob(Lua_Mob other);
	bool BehindMob(Lua_Mob other, float x);
	bool BehindMob(Lua_Mob other, float x, float y);
	void SetLevel(int level);
	void SetLevel(int level, bool command);
	void SendWearChange(int material_slot);
	bool IsMoving();
	bool IsFeared();
	bool IsBlind();
	void GotoBind();
	void Gate();
	bool Attack(Lua_Mob other);
	bool Attack(Lua_Mob other, int hand);
	bool Attack(Lua_Mob other, int hand, int damagePct);
	void Damage(Lua_Mob from, int damage, int spell_id, int attack_skill);
	void Damage(Lua_Mob from, int damage, int spell_id, int attack_skill, bool avoidable);
	void Damage(Lua_Mob from, int damage, int spell_id, int attack_skill, bool avoidable, int buffslot);
	void Damage(Lua_Mob from, int damage, int spell_id, int attack_skill, bool avoidable, int buffslot, bool buff_tic);
	void RangedAttack(Lua_Mob other);
	void ThrowingAttack(Lua_Mob other);
	void Heal();
	void HealDamage(uint32 amount);
	void HealDamage(uint32 amount, Lua_Mob other);
	uint32 GetLevelCon(int other);
	uint32 GetLevelCon(int my, int other);
	void SetHP(int hp);
	void DoAnim(int anim_num);
	void DoAnim(int anim_num, int type);
	void DoAnim(int anim_num, int type, bool ackreq);
	void DoAnim(int anim_num, int type, bool ackreq, int filter);
	void ChangeSize(double in_size);
	void ChangeSize(double in_size, bool no_restriction);
	void GMMove(double x, double y, double z);
	void GMMove(double x, double y, double z, double heading);
	void GMMove(double x, double y, double z, double heading, bool send_update);
	void GMMove(double x, double y, double z, double heading, bool send_update, bool set_guard);
	bool HasProcs();
	bool IsInvisible();
	bool IsInvisible(Lua_Mob other);
    void SetInvisible(int state);
	bool FindBuff(int spell_id);
    bool FindType(int type);
	bool FindType(int type, bool offensive);
	bool FindType(int type, bool offensive, int threshold);
	uint32 GetAppearance();
	int GetBuffSlotFromType(int slot);
	int GetBaseRace();
	int GetBaseGender();
	int GetDeity();
	int GetRace();
	int GetGender();
	int GetTexture();
	int GetHelmTexture();
	int GetHairColor();
	int GetBeardColor();
	int GetEyeColor1();
	int GetEyeColor2();
	int GetHairStyle();
	int GetLuclinFace();
	int GetBeard();
	int GetClass();
	int GetLevel();
	const char *GetCleanName();
	Lua_Mob GetTarget();
	void SetTarget(Lua_Mob t);
	double GetHPRatio();
	bool IsWarriorClass();
	int GetHP();
	int GetMaxHP();
	int GetItemHPBonuses();
	int GetSpellHPBonuses();
	double GetWalkspeed();
	void SetWalkspeed(double speed);
	double GetRunspeed();
	void SetRunspeed(double speed);
	int GetCasterLevel(int spell_id);
	int GetMaxMana();
	int GetMana();
	int SetMana(int mana);
	double GetManaRatio();
	int GetAC();
	int GetATK();
	int GetSTR();
	int GetSTA();
	int GetDEX();
	int GetAGI();
	int GetINT();
	int GetWIS();
	int GetCHA();
	int GetMR();
	int GetFR();
	int GetDR();
	int GetPR();
	int GetCR();
	int GetMaxSTR();
	int GetMaxSTA();
	int GetMaxDEX();
	int GetMaxAGI();
	int GetMaxINT();
	int GetMaxWIS();
	int GetMaxCHA();
	double ResistSpell(int resist_type, int spell_id, Lua_Mob caster, Lua_Mob target);
	double ResistSpell(int resist_type, int spell_id, Lua_Mob caster, Lua_Mob target, bool use_resist_override);
	double ResistSpell(int resist_type, int spell_id, Lua_Mob caster, Lua_Mob target, bool use_resist_override, int resist_override);
	double ResistSpell(int resist_type, int spell_id, Lua_Mob caster, Lua_Mob target, bool use_resist_override, int resist_override, bool tick_save);
	int GetSpecializeSkillValue(int spell_id);
	int GetNPCTypeID();
	bool IsTargeted();
	double GetX();
	double GetY();
	double GetZ();
	double GetHeading();
	double GetWaypointX();
	double GetWaypointY();
	double GetWaypointZ();
	double GetWaypointH();
	double GetWaypointPause();
	int GetWaypointID();
	void SetCurrentWP(int wp);
	double GetSize();
	void Message(int type, const char *message);
	void Message_StringID(int type, int string_id, uint32 distance);
	void Say(const char *message);
	void Say(const char *message, int language);
	void Shout(const char *message);
	void Shout(const char *message, int language);
	void Emote(const char *message);
	void InterruptSpell();
	void InterruptSpell(int spell_id);
	bool CastSpell(int spell_id, int target_id);
	bool CastSpell(int spell_id, int target_id, int slot);
	bool CastSpell(int spell_id, int target_id, int slot, int cast_time);
	bool CastSpell(int spell_id, int target_id, int slot, int cast_time, int mana_cost);
	bool CastSpell(int spell_id, int target_id, int slot, int cast_time, int mana_cost, int item_slot);
	bool CastSpell(int spell_id, int target_id, int slot, int cast_time, int mana_cost, int item_slot, int timer, int timer_duration);
	bool CastSpell(int spell_id, int target_id, int slot, int cast_time, int mana_cost, int item_slot, int timer, int timer_duration, 
		int resist_adjust);
	bool SpellFinished(int spell_id, Lua_Mob target);
	bool SpellFinished(int spell_id, Lua_Mob target, int slot);
	bool SpellFinished(int spell_id, Lua_Mob target, int slot, int mana_used);
	bool SpellFinished(int spell_id, Lua_Mob target, int slot, int mana_used, uint32 inventory_slot);
	bool SpellFinished(int spell_id, Lua_Mob target, int slot, int mana_used, uint32 inventory_slot, int resist_adjust);
	bool SpellFinished(int spell_id, Lua_Mob target, int slot, int mana_used, uint32 inventory_slot, int resist_adjust, bool proc);
	bool SpellFinished(int spell_id, Lua_Mob target, int slot, int mana_used, uint32 inventory_slot, int resist_adjust, bool proc, bool recourse);
	bool SpellOnTarget(int spell_id, Lua_Mob target);
	bool SpellOnTarget(int spell_id, Lua_Mob target, int adjust);
	Lua_Mob GetPet();
	Lua_Mob GetOwner();
	bool IsPet();
	Lua_HateList GetHateList();
	Lua_Mob GetHateTop();
	Lua_Mob GetHateRandom();
	Lua_Client GetHateRandomClient();
	Lua_Client GetHateRandomClient(uint32 max_dist);
	void AddToHateList(Lua_Mob other);
	void AddToHateList(Lua_Mob other, int hate);
	void AddToHateList(Lua_Mob other, int hate, int damage);
	void AddToHateList(Lua_Mob other, int hate, int damage, bool frenzy);
	void AddToHateList(Lua_Mob other, int hate, int damage, bool frenzy, bool buff_tic);
	void RemoveFromHateList(Lua_Mob other);
	void SetHate(Lua_Mob other);
	void SetHate(Lua_Mob other, int hate);
	void SetHate(Lua_Mob other, int hate, int damage);
	void HalveAggro(Lua_Mob other);
	void DoubleAggro(Lua_Mob other);
	uint32 GetHateAmount(Lua_Mob target);
	uint32 GetHateAmount(Lua_Mob target, bool include_bonus);
	uint32 GetDamageAmount(Lua_Mob target);
	uint32 GetDamageAmount(Lua_Mob target, bool combine_pet_dmg);
	void WipeHateList();
	bool CheckAggro(Lua_Mob other);
	void Stun(int duration);
	void UnStun();
	bool IsStunned();
	void Spin();
	void Kill();
	bool IsDualWielding();
	void SetInvul(bool value);
	bool GetInvul();
	void SetExtraHaste(int haste);
	int GetHaste();
	void Mesmerize();
	bool IsMezzed();
	bool IsEnraged();
	int GetReverseFactionCon(Lua_Mob other);
	bool IsAIControlled();
	float GetAggroRange();
	void SetAggroRange(double range);
	float GetAssistRange();
	void SetAssistRange(double range);
	void SetPetOrder(int order);
	int GetPetOrder();
	bool IsRoamer();
	bool IsRooted();
	bool IsEngaged();
	void FaceTarget(Lua_Mob target);
	void SetHeading(double in);
	double CalculateHeadingToTarget(double in_x, double in_y);
	bool CalculateNewPosition(double x, double y, double z, double speed);
	bool CalculateNewPosition(double x, double y, double z, double speed, bool check_z);
	bool CalculateNewPosition2(double x, double y, double z, double speed);
	bool CalculateNewPosition2(double x, double y, double z, double speed, bool check_z);
	float CalculateDistance(double x, double y, double z);
	void SendTo(double x, double y, double z);
	void SendToFixZ(double x, double y, double z);
	int GetResist(int type);
	bool Charmed();
	int CheckAggroAmount(int spell_id, Lua_Mob target);
	int CheckHealAggroAmount(int spell_id, Lua_Mob target);
	int CheckHealAggroAmount(int spell_id, Lua_Mob target, uint32 heal_possible);
	int GetAA(int id);
	bool DivineAura();
	void SetOOCRegen(int regen);
	const char* GetEntityVariable(const char *name);
	void SetEntityVariable(const char *name, const char *value);
	bool EntityVariableExists(const char *name);
	void Signal(uint32 id);
	bool CombatRange(Lua_Mob other);
	void DoSpecialAttackDamage(Lua_Mob other, int skill, int max_damage);
	void DoSpecialAttackDamage(Lua_Mob other, int skill, int max_damage, int min_damage);
	void DoSpecialAttackDamage(Lua_Mob other, int skill, int max_damage, int min_damage, int hate_override);
	void DoSpecialAttackDamage(Lua_Mob other, int skill, int max_damage, int min_damage, int hate_override, int animation);
	bool CheckLoS(Lua_Mob other);
	bool CheckLoSToLoc(double x, double y, double z);
	bool CheckLoSToLoc(double x, double y, double z, double mob_size);
	double FindGroundZ(double x, double y);
	double FindGroundZ(double x, double y, double z);
	void ProjectileAnimation(Lua_Mob to, int item_id);
	void ProjectileAnimation(Lua_Mob to, int item_id, bool is_arrow);
	void ProjectileAnimation(Lua_Mob to, int item_id, bool is_arrow, double speed);
	void ProjectileAnimation(Lua_Mob to, int item_id, bool is_arrow, double speed, double angle);
	void ProjectileAnimation(Lua_Mob to, int item_id, bool is_arrow, double speed, double angle, double tilt);
	void ProjectileAnimation(Lua_Mob to, int item_id, bool is_arrow, double speed, double angle, double tilt, double arc);
	void SetFlyMode(int in);
	void SetTexture(int in);
	void SetRace(int in);
	void SetGender(int in);
	void SendIllusionPacket(luabind::adl::object illusion);
	std::string GetGlobal(const char *varname);
	void SetGlobal(const char *varname, const char *newvalue, int options, const char *duration);
	void SetGlobal(const char *varname, const char *newvalue, int options, const char *duration, Lua_Mob other);
	void TarGlobal(const char *varname, const char *value, const char *duration, int npc_id, int char_id, int zone_id);
	void DelGlobal(const char *varname);
	void WearChange(int material_slot, int texture, uint32 color);
	void DoKnockback(Lua_Mob caster, uint32 pushback, uint32 pushup);
	bool IsRunning();
	void SetRunning(bool running);
	void SetBodyType(uint8 new_body, bool overwrite_orig);
	void SetAllowBeneficial(bool value);
	bool GetAllowBeneficial();
	bool IsBeneficialAllowed(Lua_Mob target);
	void SetDisableMelee(bool disable);
	bool IsMeleeDisabled();
	void SetFlurryChance(int value);
	int GetFlurryChance();
	int GetSkill(int skill_id);
	void SetSkill(int skill_id, int value);
	void CalcBonuses();
	int GetSpecialAbility(int ability);
	int GetSpecialAbilityParam(int ability, int param);
	void SetSpecialAbility(int ability, int level);
	void SetSpecialAbilityParam(int ability, int param, int value);
	void ClearSpecialAbilities();
	void ProcessSpecialAbilities(std::string str);
	void SetAppearance(int app);
	void SetAppearance(int app, bool ignore_self);
	bool IsImmuneToSpell(int spell_id, Lua_Mob caster);
	void BuffFadeBySpellID(int spell_id);
	void BuffFadeByEffect(int effect_id);
	void BuffFadeByEffect(int effect_id, int skipslot);
	void BuffFadeAll();
	void BuffFadeAll(bool skiprez);
	void BuffFadeBySlot(int slot);
	void BuffFadeBySlot(int slot, bool recalc_bonuses, bool death);
	int CanBuffStack(int spell_id, int caster_level);
	int CanBuffStack(int spell_id, int caster_level, bool fail_if_overwrite);
	void RunTo(double x, double y, double z);
	void WalkTo(double x, double y, double z);
	void NavigateTo(double x, double y, double z);
	void StopNavigation();
	int GetSnaredAmount();
	bool IsCasting();
	int GetDamageShieldAmount();

	void DeleteBucket(std::string bucket_name);
	std::string GetBucket(std::string bucket_name);
	std::string GetBucketExpires(std::string bucket_name);
	std::string GetBucketKey();
	std::string GetBucketRemaining(std::string bucket_name);
	void SetBucket(std::string bucket_name, std::string bucket_value);
	void SetBucket(std::string bucket_name, std::string bucket_value, std::string expiration);
};

#endif
#endif
